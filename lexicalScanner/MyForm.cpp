#include "MyForm.h"
#include "Header.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lexical x("input.txt");
	x.scan();
	
	lexicalScanner::MyForm form;
	
	Application::Run(%form);
	
}


