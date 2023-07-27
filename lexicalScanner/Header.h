#pragma once

#include <string>
#include <string.h>
#include <fstream>
#include <ctype.h>

using namespace std;

/*
	memset(pointer to first element of string , value , size of string) 
	value = 0 --> for clear string
*/
class Lexical {
public:
	string s;
	char pattern[18];
	int line, j;

	string keywords[9] = { "int", "double", "float", "char", "false", "true", "if", "else", "for" };
	string operators[11] = { "=", "+", "-", "*", "/", "%", ">", "<", "++", "--","==" };
	string punctuations[5] = { "{", "}", "(", ")", ";" };

	Lexical(string in) {
		s = in;
		line = 1;
		j = 0;
	}

	void scan()
	{
		ifstream fin(s);

		fstream out_token("output.txt");
		out_token.trunc;

		fstream out_error("error.txt");
		out_error.trunc;

		do {  

			char c = fin.get();

			if (isalpha(c)) {
				if (j != 0) {
					if (isalpha(pattern[0])) {

						if (isKeyword(pattern) == 1) {
							// error: keyword followed by char without space between them. ex: intx
							pattern[j] = '\0';
							out_token << pattern << "\tis keyword." << endl;
							out_error << "Error in line " << line << " :\t" << pattern << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
						else
							pattern[j++] = c;
					}
					else if (isOperator(pattern)) {
						// token: operator followed by char
						pattern[j] = '\0';
						out_token << pattern << "\tis operator." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}
					else if (isPunctuation(pattern)) {
						pattern[j] = '\0';
						if (pattern[0] == '{' || pattern[0] == '(') {
							out_token << pattern << "\tis punctuation." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
						else {
							out_error << "Error in line " << line << " :\t" << pattern << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
					}
				}
				else
					pattern[j++] = c; 
			}

			else if (isdigit(c)) {
				if (j != 0) {
					if (isalpha(pattern[0])) {
						if (isKeyword(pattern) == 1) {
							// error: keyword followed by digit without space between them. ex: double5
							out_token << pattern << "\tis keyword." << endl;
							out_error << "Error in line " << line << " :\t" << pattern << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
						else
							pattern[j++] = c;
					}
					else if (isdigit(pattern[0])) {
						pattern[j++] = c;
					}
					else if (isOperator(pattern)) {
						// token: operator followed by digit
						pattern[j] = '\0';
						out_token << pattern << "\tis operator." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}
					else if (pattern == "(") {
						out_token << pattern << "\tis punctuation." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}
					else {
						out_error << "Error in line " << line << " :\t" << pattern << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}
				}
				else
					pattern[j++] = c;
			}

			else if ((c == ' ' || c == '\t')) {
				if (j != 0) {
					pattern[j] = '\0';

					if (isdigit(pattern[0])) {
						out_token << pattern << "\tis constant." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
					else if (isalpha(pattern[0])) {
						if (isKeyword(pattern) == 1) {
							
							out_token << pattern << "\tis keyword." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
						else {
							out_token << pattern << "\tis identifier." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
					}
					else if (isOperator(pattern)) {
						out_token << pattern << "\tis operator." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
					else if (isPunctuation(pattern)) {
						out_token << pattern << "\tis punctuation." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
					else {
						// error: invalid lexeme  <or>  unfinished lexeme
						out_error << "Error in line " << line << " :\t" << pattern << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
				}
			}

			else if (c == '\n') {
				if (j != 0) {
					pattern[j] = '\0';

					if (isdigit(pattern[0])) {
						out_token << pattern << "\tis constant." << endl;
						out_error << "Error in line " << line << " :\t" << ";" << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
					else if (isalpha(pattern[0])) {
						if (isKeyword(pattern) == 1) {
							out_token << pattern << "\tis keyword." << endl;
							out_error << "Error in line " << line << " :\t" << ";" << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
						else {
							out_token << pattern << "\tis identifier." << endl;
							out_error << "Error in line " << line << " :\t" << ";" << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
					}
					else if (isOperator(pattern)) {
						out_token << pattern << "\tis operator." << endl;
						out_error << "Error in line " << line << " :\t" << ";" << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
					else if (isPunctuation(pattern)) {
						if (pattern[0] == '{' || pattern[0] == '(') {
							out_token << pattern << "\tis punctuation." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
						else {
							out_error << "Error in line " << line << " :\t" << ";" << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
						}
					}
					else {
						// error: invalid lexeme  <or>  unfinished lexeme
						out_error << "Error in line " << line << " :\t" << pattern << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
					}
				}

				line++;
			}

			else if (isOperator(""s + c)) {
				if (j != 0) {

					if (isdigit(pattern[0])) {
						out_token << pattern << "\tis constant." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j] = c;
					}

					else if (isalpha(pattern[0])) {
						pattern[j] = '\0';

						if (isKeyword(pattern) == 1) {
							out_token << pattern << "\tis keyword." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j] = c;
						}
						else {
							out_token << pattern << "\tis identifier." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
					}

					else if (pattern == "++" || pattern == "--" || pattern == "==") {
						// error: completed operator followed by operator. ex: +-  <or>  =-  <or>  <+  <or>  +++
						out_error << "Error in line " << line << " :\t" << pattern << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}

					else if (isPunctuation(pattern)) {
						if (pattern == ")") {
							pattern[j] = '\0';
							out_token << pattern << "\tis punctuation." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
						else {

							pattern[j] = '\0';
							out_error << "Error in line " << line << " :\t" << pattern << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
					}

					else
						pattern[j++] = c;
				}
				else
					pattern[j++] = c;
			}

			else if (isPunctuation(""s + c)) {
				if (j != 0) {
					pattern[j] = '\0';

					if (isdigit(pattern[0])) {
						out_token << pattern << "\tis constant." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}

					else if (isalpha(pattern[0])) {
						if ((pattern == "false" || pattern == "true") && ""s + c == ";") {
							out_token << pattern << "\tis keyword." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}

						else if ((pattern == "if" || pattern == "for") && ""s + c == "(") {
							out_token << pattern << "\tis keyword." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}

						else if (pattern == "else" && ""s + c == "{") {
							out_token << pattern << "\tis keyword." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}

						else if (isKeyword(pattern) == 0 && ""s + c == ";") {   
							out_token << pattern << "\tis identifier." << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}

						else if (isKeyword(pattern) == 1) {
							// error: keyword followed by punctuation. ex: int{  <or>  double}  <or>  float(  <or>  char)
							out_token << pattern << "\tis keyword." << endl;
							out_error << "Error in line " << line << " :\t" << pattern << endl;
							memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
							j = 0;
							pattern[j++] = c;
						}
					}

					else if ((strcmp(pattern, "++") == 0) || (strcmp(pattern, "--") == 0)) {
						out_token << pattern << "\tis operator." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}

					else if (isPunctuation(pattern)) {
						out_token << pattern << "\tis punctuatuion." << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}

					else {
						// error: 
						out_error << "Error in line " << line << " :\t" << pattern << endl;
						memset(&pattern[0], 0, sizeof(pattern)); // clear content of pattern
						j = 0;
						pattern[j++] = c;
					}
				}
				else
					pattern[j++] = c;
			}
		} while (!fin.eof());

		if (isalpha(pattern[0])) {
			if (isKeyword(pattern) == 1) out_token << pattern << "\tis keyword." << endl;
			else out_token << pattern << "\tis identifier." << endl;
		}
		else if (isdigit(pattern[0])) out_token << pattern << "\tis constant." << endl;
		else if (isOperator(pattern)) out_token << pattern << "\tis operator." << endl;
		else if (isPunctuation(pattern)) out_token << pattern << "\tis punctuation." << endl;
	}

	int isKeyword(string p) {
		for (int i = 0; i < 9; i++) {
			if (p == keywords[i])
				return 1;
		}
		return 0;
	}

	int isOperator(string p) {
		for (int i = 0; i < 11; i++) {
			if (p == operators[i])
				return 1;
		}
		return 0;
	}

	bool isPunctuation(string p) {
		for (int i = 0; i < 5; i++) {
			if (p == punctuations[i])
				return 1;
		}
		return 0;
	}
};