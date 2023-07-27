#pragma once

namespace lexicalScanner {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			this->input_box->Text = File::ReadAllText("input.txt");
			this->errors_list_box->Text = File::ReadAllText("error.txt");
			this->tokens_list_box->Text = File::ReadAllText("output.txt");
			//this->Show();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ errors_label;
	private: System::Windows::Forms::RichTextBox^ errors_list_box;
	protected:

	private: System::Windows::Forms::Label^ tokens_label;
	private: System::Windows::Forms::RichTextBox^ tokens_list_box;
	private: System::Windows::Forms::RichTextBox^ input_box;
	private: System::Windows::Forms::Label^ input_label;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->errors_label = (gcnew System::Windows::Forms::Label());
			this->errors_list_box = (gcnew System::Windows::Forms::RichTextBox());
			this->tokens_label = (gcnew System::Windows::Forms::Label());
			this->tokens_list_box = (gcnew System::Windows::Forms::RichTextBox());
			this->input_box = (gcnew System::Windows::Forms::RichTextBox());
			this->input_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// errors_label
			// 
			this->errors_label->AutoSize = true;
			this->errors_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)
				| System::Drawing::FontStyle::Strikeout)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->errors_label->Location = System::Drawing::Point(659, 341);
			this->errors_label->Name = L"errors_label";
			this->errors_label->Size = System::Drawing::Size(178, 38);
			this->errors_label->TabIndex = 0;
			this->errors_label->Text = L"Errors List";
			this->errors_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// errors_list_box
			// 
			this->errors_list_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->errors_list_box->Location = System::Drawing::Point(537, 382);
			this->errors_list_box->Name = L"errors_list_box";
			this->errors_list_box->Size = System::Drawing::Size(435, 390);
			this->errors_list_box->TabIndex = 1;
			this->errors_list_box->Text = L"";
			// 
			// tokens_label
			// 
			this->tokens_label->AutoSize = true;
			this->tokens_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tokens_label->Location = System::Drawing::Point(135, 341);
			this->tokens_label->Name = L"tokens_label";
			this->tokens_label->Size = System::Drawing::Size(196, 38);
			this->tokens_label->TabIndex = 2;
			this->tokens_label->Text = L"Tokens List";
			// 
			// tokens_list_box
			// 
			this->tokens_list_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->tokens_list_box->Location = System::Drawing::Point(33, 382);
			this->tokens_list_box->Name = L"tokens_list_box";
			this->tokens_list_box->Size = System::Drawing::Size(435, 390);
			this->tokens_list_box->TabIndex = 3;
			this->tokens_list_box->Text = L"";
			// 
			// input_box
			// 
			this->input_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_box->Location = System::Drawing::Point(190, 66);
			this->input_box->Name = L"input_box";
			this->input_box->Size = System::Drawing::Size(617, 257);
			this->input_box->TabIndex = 4;
			this->input_box->Text = L"";
			// 
			// input_label
			// 
			this->input_label->AutoSize = true;
			this->input_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_label->Location = System::Drawing::Point(355, 9);
			this->input_label->Name = L"input_label";
			this->input_label->Size = System::Drawing::Size(307, 54);
			this->input_label->TabIndex = 5;
			this->input_label->Text = L"Source Code";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(390, 799);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 40);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Design and developed by \r\n     Howiidaa _ Mayar";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1009, 863);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->input_label);
			this->Controls->Add(this->input_box);
			this->Controls->Add(this->tokens_list_box);
			this->Controls->Add(this->tokens_label);
			this->Controls->Add(this->errors_list_box);
			this->Controls->Add(this->errors_label);
			this->Name = L"MyForm";
			this->Text = L"Scanner";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
