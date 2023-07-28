# Lexical-analyzer
This is the first phase of compiler.
It's a GUI desktop application use to scan C++ code and convert it to tokens with a little errors detection.

- Inputs:
    <br>Stream of characters (multiple lines of code written in C++ language syntax).
  
- Output:
    <br>Stream of tokens in form: (token value, token type). 
  	<br>Example:	int x = 5;
    <table>
	    <tr>
		    <th>Token Value</th>
				<th>Token Type</th>
	    </tr>
			<tr>
				<td>int</td>
				<td>Keyword</td>
			</tr>
			<tr>
				<td>x</td>
				<td>Identifier</td>
			</tr>
			<tr>
				<td>=</td>
				<td>Operator</td>
			</tr>
			<tr>
				<td>5</td>
				<td>Constant</td>
			</tr>
			<tr>
				<td>;</td>
				<td>Punctuation</td>
			</tr>
    </table>
