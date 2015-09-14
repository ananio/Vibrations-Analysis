#pragma once

#include "windows.h"
#include <stdio.h>
#include <math.h>
#include <err/gsl_errno.h>
#include <fft/gsl_fft_complex.h>
#include <fft/gsl_fft_real.h>
#include <fft/gsl_fft.h>
#include <fft/gsl_fft_halfcomplex.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

long m = 599;
double  x1[599]={0},y1a[2*599]={0},x2[599]={0},y2a[2*599]={0},x3[599]={0},y3a[2*599]={0};
int i = 0;
double dt = 0.00021;
double peak1=0, peak2=0;
bool flagxfft=TRUE, flagyfft=TRUE, flagzfft=TRUE, flagregfft=TRUE, flagxreg=TRUE, flagyreg=FALSE, flagzreg=FALSE;


namespace Proyecto_Diseño {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	public: System::Windows::Forms::RadioButton^  radioButton1;
	private: 



	private: System::Windows::Forms::GroupBox^  groupBox2;



	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox6;


	private: componentXtra::XYGraph^  xyGraph1;
	private: componentXtra::XYGraph^  xyGraph2;
	private: componentXtra::XYGraph^  xyGraph3;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Button^  button3;



	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::GroupBox^  groupBox8;
	private: System::Windows::Forms::Button^  button4;
	public: System::Windows::Forms::RadioButton^  radioButton3;
	private: 

	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::GroupBox^  groupBox9;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;

	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox10;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::Label^  label6;



	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->xyGraph1 = (gcnew componentXtra::XYGraph());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->xyGraph2 = (gcnew componentXtra::XYGraph());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->xyGraph3 = (gcnew componentXtra::XYGraph());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(17, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(354, 58);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ADX";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(138, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Frecuencia de oscilación";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(152, 32);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox1->TabIndex = 4;
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox1_MaskInputRejected);
			// 
			// radioButton3
			// 
			this->radioButton3->AllowDrop = true;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(55, 33);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(44, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Text = L"FFT";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AllowDrop = true;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(55, 14);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(60, 18);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Tiempo";
			this->radioButton1->UseCompatibleTextRendering = true;
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(268, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Leer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(172, 29);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {80, 0, 0, 0});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(81, 20);
			this->numericUpDown2->TabIndex = 11;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown2_ValueChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->groupBox10);
			this->groupBox2->Controls->Add(this->radioButton11);
			this->groupBox2->Controls->Add(this->radioButton10);
			this->groupBox2->Controls->Add(this->radioButton9);
			this->groupBox2->Controls->Add(this->button6);
			this->groupBox2->Location = System::Drawing::Point(14, 361);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(353, 66);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Registo de datos";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &Form1::groupBox2_Enter);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->radioButton8);
			this->groupBox10->Controls->Add(this->radioButton2);
			this->groupBox10->Location = System::Drawing::Point(3, 16);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(71, 48);
			this->groupBox10->TabIndex = 16;
			this->groupBox10->TabStop = false;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Checked = true;
			this->radioButton8->Location = System::Drawing::Point(3, 3);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(44, 17);
			this->radioButton8->TabIndex = 7;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"FFT";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton8_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(3, 21);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(60, 17);
			this->radioButton2->TabIndex = 13;
			this->radioButton2->Text = L"Tiempo";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(104, 43);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(30, 17);
			this->radioButton11->TabIndex = 15;
			this->radioButton11->Text = L"z";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton11_CheckedChanged);
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(104, 25);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(30, 17);
			this->radioButton10->TabIndex = 14;
			this->radioButton10->Text = L"y";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton10_CheckedChanged);
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Checked = true;
			this->radioButton9->Location = System::Drawing::Point(104, 9);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(30, 17);
			this->radioButton9->TabIndex = 13;
			this->radioButton9->TabStop = true;
			this->radioButton9->Text = L"x";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton9_CheckedChanged);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(270, 19);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 12;
			this->button6->Text = L"Guardar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->xyGraph1);
			this->groupBox4->Location = System::Drawing::Point(380, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(286, 159);
			this->groupBox4->TabIndex = 5;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Datos en x";
			// 
			// xyGraph1
			// 
			this->xyGraph1->BackColor = System::Drawing::Color::White;
			this->xyGraph1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->xyGraph1->Location = System::Drawing::Point(6, 19);
			this->xyGraph1->Name = L"xyGraph1";
			this->xyGraph1->Size = System::Drawing::Size(274, 134);
			this->xyGraph1->TabIndex = 0;
			this->xyGraph1->XtraAutoScale = true;
			this->xyGraph1->XtraClassicLabels = true;
			this->xyGraph1->XtraFrame = false;
			this->xyGraph1->XtraLabelX = L"Frecuencia";
			this->xyGraph1->XtraLabelY = L"Potencia";
			this->xyGraph1->XtraLogX = false;
			this->xyGraph1->XtraLogY = false;
			this->xyGraph1->XtraMinLeftMargin = 0;
			this->xyGraph1->XtraSelectPoint = false;
			this->xyGraph1->XtraShowGrid = false;
			this->xyGraph1->XtraShowLegend = false;
			this->xyGraph1->XtraTitle = L"Vibraciones en x";
			this->xyGraph1->XtraUpdateCursor = true;
			this->xyGraph1->XtraXdigits = 0;
			this->xyGraph1->XtraXmax = 0;
			this->xyGraph1->XtraXmin = 0;
			this->xyGraph1->XtraXstep = 0;
			this->xyGraph1->XtraYdigits = 0;
			this->xyGraph1->XtraYmax = 0;
			this->xyGraph1->XtraYmin = 0;
			this->xyGraph1->XtraYstep = 0;
			this->xyGraph1->Load += gcnew System::EventHandler(this, &Form1::xyGraph1_Load);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->xyGraph2);
			this->groupBox5->Location = System::Drawing::Point(380, 177);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(286, 159);
			this->groupBox5->TabIndex = 6;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Datos en y";
			// 
			// xyGraph2
			// 
			this->xyGraph2->BackColor = System::Drawing::Color::White;
			this->xyGraph2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->xyGraph2->Location = System::Drawing::Point(6, 17);
			this->xyGraph2->Name = L"xyGraph2";
			this->xyGraph2->Size = System::Drawing::Size(274, 132);
			this->xyGraph2->TabIndex = 0;
			this->xyGraph2->XtraAutoScale = true;
			this->xyGraph2->XtraClassicLabels = true;
			this->xyGraph2->XtraFrame = false;
			this->xyGraph2->XtraLabelX = L"Frecuencia";
			this->xyGraph2->XtraLabelY = L"Potencia";
			this->xyGraph2->XtraLogX = false;
			this->xyGraph2->XtraLogY = false;
			this->xyGraph2->XtraMinLeftMargin = 0;
			this->xyGraph2->XtraSelectPoint = false;
			this->xyGraph2->XtraShowGrid = false;
			this->xyGraph2->XtraShowLegend = false;
			this->xyGraph2->XtraTitle = L"Vibraciones en y";
			this->xyGraph2->XtraUpdateCursor = true;
			this->xyGraph2->XtraXdigits = 0;
			this->xyGraph2->XtraXmax = 0;
			this->xyGraph2->XtraXmin = 0;
			this->xyGraph2->XtraXstep = 0;
			this->xyGraph2->XtraYdigits = 0;
			this->xyGraph2->XtraYmax = 0;
			this->xyGraph2->XtraYmin = 0;
			this->xyGraph2->XtraYstep = 0;
			this->xyGraph2->Load += gcnew System::EventHandler(this, &Form1::xyGraph2_Load);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->xyGraph3);
			this->groupBox6->Location = System::Drawing::Point(380, 342);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(286, 159);
			this->groupBox6->TabIndex = 7;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Datos en z";
			// 
			// xyGraph3
			// 
			this->xyGraph3->BackColor = System::Drawing::Color::White;
			this->xyGraph3->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->xyGraph3->Location = System::Drawing::Point(6, 19);
			this->xyGraph3->Name = L"xyGraph3";
			this->xyGraph3->Size = System::Drawing::Size(274, 134);
			this->xyGraph3->TabIndex = 0;
			this->xyGraph3->XtraAutoScale = true;
			this->xyGraph3->XtraClassicLabels = true;
			this->xyGraph3->XtraFrame = false;
			this->xyGraph3->XtraLabelX = L"Frecuencia";
			this->xyGraph3->XtraLabelY = L"Potencia";
			this->xyGraph3->XtraLogX = false;
			this->xyGraph3->XtraLogY = false;
			this->xyGraph3->XtraMinLeftMargin = 0;
			this->xyGraph3->XtraSelectPoint = false;
			this->xyGraph3->XtraShowGrid = false;
			this->xyGraph3->XtraShowLegend = false;
			this->xyGraph3->XtraTitle = L"Vibraciones en z";
			this->xyGraph3->XtraUpdateCursor = true;
			this->xyGraph3->XtraXdigits = 0;
			this->xyGraph3->XtraXmax = 0;
			this->xyGraph3->XtraXmin = 0;
			this->xyGraph3->XtraXstep = 0;
			this->xyGraph3->XtraYdigits = 0;
			this->xyGraph3->XtraYmax = 0;
			this->xyGraph3->XtraYmin = 0;
			this->xyGraph3->XtraYstep = 0;
			this->xyGraph3->Load += gcnew System::EventHandler(this, &Form1::xyGraph3_Load);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->label3);
			this->groupBox7->Controls->Add(this->radioButton5);
			this->groupBox7->Controls->Add(this->radioButton4);
			this->groupBox7->Controls->Add(this->button3);
			this->groupBox7->Controls->Add(this->maskedTextBox3);
			this->groupBox7->Location = System::Drawing::Point(18, 95);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(353, 60);
			this->groupBox7->TabIndex = 8;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"ADY";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(137, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Frecuencia de oscilación";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click_1);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Checked = true;
			this->radioButton5->Location = System::Drawing::Point(54, 12);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(60, 17);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Tiempo";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(54, 33);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(44, 17);
			this->radioButton4->TabIndex = 4;
			this->radioButton4->Text = L"FFT";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton4_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(267, 27);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Leer";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(151, 32);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox3->TabIndex = 3;
			this->maskedTextBox3->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox3_MaskInputRejected);
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM14";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(10) {L"Com7", L"Com8", L"Com9", L"Com10", 
				L"Com11", L"Com12", L"Com13", L"Com14", L"Com15", L"Com16"});
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ItemHeight = 13;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"Com10", L"Com11", L"Com12", L"Com13", L"Com14", 
				L"Com15", L"Com16", L"Com7", L"Com8", L"Com9"});
			this->comboBox1->Location = System::Drawing::Point(12, 477);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->Sorted = true;
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 461);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Puerto Com virtual de lectura";
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->label6);
			this->groupBox8->Controls->Add(this->maskedTextBox2);
			this->groupBox8->Controls->Add(this->label5);
			this->groupBox8->Controls->Add(this->button4);
			this->groupBox8->Controls->Add(this->numericUpDown2);
			this->groupBox8->Location = System::Drawing::Point(13, 287);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(353, 60);
			this->groupBox8->TabIndex = 12;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Frecuencia de oscilación";
			this->groupBox8->Enter += gcnew System::EventHandler(this, &Form1::groupBox8_Enter);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(56, 16);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(82, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Frecuencia (Hz)";
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(59, 29);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox2->TabIndex = 13;
			this->maskedTextBox2->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox2_MaskInputRejected_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(169, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"0-80 de 250Hz";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(271, 23);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Frecuencia";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->label4);
			this->groupBox9->Controls->Add(this->maskedTextBox4);
			this->groupBox9->Controls->Add(this->radioButton6);
			this->groupBox9->Controls->Add(this->radioButton7);
			this->groupBox9->Controls->Add(this->button5);
			this->groupBox9->Location = System::Drawing::Point(16, 161);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(354, 58);
			this->groupBox9->TabIndex = 4;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"ADZ";
			this->groupBox9->Enter += gcnew System::EventHandler(this, &Form1::groupBox9_Enter);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(141, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Frecuencia de oscilación";
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(153, 32);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(100, 20);
			this->maskedTextBox4->TabIndex = 4;
			this->maskedTextBox4->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox4_MaskInputRejected);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(56, 32);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(44, 17);
			this->radioButton6->TabIndex = 3;
			this->radioButton6->Text = L"FFT";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Checked = true;
			this->radioButton7->Location = System::Drawing::Point(56, 12);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(60, 17);
			this->radioButton7->TabIndex = 2;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Tiempo";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton7_CheckedChanged);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(269, 19);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Leer";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 4000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 4000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 4000;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form1::timer3_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(454, 524);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(546, 524);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 14;
			this->button7->Text = L"Stop";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(678, 570);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Oscilador de espejo óptico";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void xyGraph4_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void xyGraph2_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		
	serialPort1->Open();
	i = 0;
	serialPort1->Write("L");
	Sleep(20);
	

	while(i<599){

		serialPort1->Write("L");
		x1[i] = (float)5*serialPort1->ReadByte()/255; 
		i++;
	}
	
	serialPort1->Write("L");
	serialPort1->Close();

	if(flagyfft){

	xyGraph2->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph2->ClearGraphs();
	for(int i=0; i<599; i++)
	xyGraph2->AddValue(0, (float)i*dt, (float)x1[i]);
	xyGraph2->DrawAll();
	}
	else{

  int i; double data[2*599];
  const int n = 599;

  for (i = 0; i < m; i++)
  {
     REAL(data,i) = x1[i]; IMAG(data,i) = 0.0;
  }

       gsl_fft_complex_wavetable * wavetable;
       gsl_fft_complex_workspace * workspace;

	   wavetable = gsl_fft_complex_wavetable_alloc (n);
       workspace = gsl_fft_complex_workspace_alloc (n);

	  gsl_fft_complex_forward (data, 1, n, 
                                wavetable, workspace);

      gsl_fft_complex_wavetable_free (wavetable);
      gsl_fft_complex_workspace_free (workspace);

  for (i = 1; i <= 599; i++)
  {
    y1a[i] = sqrt(REAL(data,i)*REAL(data,i) + IMAG(data,i)*IMAG(data,i));
  }

	xyGraph2->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph2->ClearGraphs();
	for(i=0; i<300; i++)
	xyGraph2->AddValue(0, (float)i*8.0645, (float)y1a[i]);
	xyGraph2->DrawAll();

	for(i = 0;i<300;i++){
		
		if(y1a[i]>peak1){
		peak1 = y1a[i];
		peak2 = 8.0645*i;
		}

	}

	maskedTextBox3->Text = Convert::ToString((float)peak2);
	peak1 = 0;
	peak2 = 0;
	}
		 }

public: System::Void maskedTextBox3_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {


		
		}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			if (comboBox1->Text == "Com7" ){
				serialPort1->PortName = "COM7";
			}
			if (comboBox1->Text == "Com8" ){
				serialPort1->PortName = "COM8";
			}
			if (comboBox1->Text == "Com9" ){
				serialPort1->PortName = "COM9";
			}
			if (comboBox1->Text == "Com10" ){
				serialPort1->PortName = "COM10";
			}
			if (comboBox1->Text== "Com11" ){
				serialPort1->PortName = "COM11";
			}
			if (comboBox1->Text == "Com12" ){
				serialPort1->PortName = "COM12";
			}
			if (comboBox1->Text == "Com13" ){
				serialPort1->PortName = "COM13";
			}
			if (comboBox1->Text == "Com14" ){
				serialPort1->PortName = "COM14";
			}
			if (comboBox1->Text == "Com15" ){
				serialPort1->PortName = "COM15";
			}
			if (comboBox1->Text == "Com16" ){
				serialPort1->PortName = "COM16";
			}

		 }
private: System::Void maskedTextBox2_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	serialPort1->Open();
	i = 0;
	serialPort1->Write("S");
	Sleep(20);
	

	while(i<599){
		
		serialPort1->Write("S");
		x2[i] = (float)5*serialPort1->ReadByte()/255; 
		i++;
	}

	serialPort1->Write("S");
	serialPort1->Close();

	if(flagxfft){

	xyGraph1->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph1->ClearGraphs();
	for(int i=0; i<599; i++)
	xyGraph1->AddValue(0, (float)i*dt, (float)x2[i]);
	xyGraph1->DrawAll();
	}
	else{

  int i; double data[2*599];
  const int n = 599;

  for (i = 0; i < m; i++)
  {
     REAL(data,i) = x2[i]; IMAG(data,i) = 0.0;
  }

       gsl_fft_complex_wavetable * wavetable;
       gsl_fft_complex_workspace * workspace;

	   wavetable = gsl_fft_complex_wavetable_alloc (n);
       workspace = gsl_fft_complex_workspace_alloc (n);

	  gsl_fft_complex_forward (data, 1, n, 
                                wavetable, workspace);

      gsl_fft_complex_wavetable_free (wavetable);
      gsl_fft_complex_workspace_free (workspace);

  for (i = 1; i <= 599; i++)
  {
    y1a[i] = sqrt(REAL(data,i)*REAL(data,i) + IMAG(data,i)*IMAG(data,i));
  }

	xyGraph1->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph1->ClearGraphs();
	for(i=0; i<300; i++)
	xyGraph1->AddValue(0, (float)i*8.0645, (float)y1a[i]);
	xyGraph1->DrawAll();

	for(i = 0;i<300;i++){
		
		if(y1a[i]>peak1){
		peak1 = y1a[i];
		peak2 = 8.0645*i;
		}

	}

	maskedTextBox1->Text = Convert::ToString((float)peak2);
	peak1 = 0;
	peak2 = 0;
	}
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		  }

private: System::Void xyGraph1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void xyGraph3_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	serialPort1->Open();
	Sleep(20);
	serialPort1->Write("P");
	Sleep(40);
	char a = NULL;
	
	a = (char)(a + (char)(((unsigned int)numericUpDown2->Value)+2));
	serialPort1->Write(Convert::ToString(Convert::ToChar(a)));
	serialPort1->Close();

	maskedTextBox2->Text = Convert::ToString((float)(1/((4/48000000.)*16*((unsigned int)numericUpDown2->Value+3)))/1000);

		 }

private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		flagxfft = TRUE;
		 }
private: System::Void groupBox9_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	serialPort1->Open();
	i = 0;
	serialPort1->Write("Q");
	Sleep(20);
	

	while(i<599){

		serialPort1->Write("Q");
		x3[i] = (float)5*serialPort1->ReadByte()/255; 
		i++;
	}

	serialPort1->Write("Q");
	serialPort1->Close();

	if(flagzfft){

	xyGraph3->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph3->ClearGraphs();
	for(int i=0; i<599; i++)
	xyGraph3->AddValue(0, (float)i*dt, (float)x3[i]);
	xyGraph3->DrawAll();
	}
	else{

  int i; double data[2*599];
  const int n = 599;

  for (i = 0; i < m; i++)
  {
     REAL(data,i) = x3[i]; IMAG(data,i) = 0.0;
  }

       gsl_fft_complex_wavetable * wavetable;
       gsl_fft_complex_workspace * workspace;

	   wavetable = gsl_fft_complex_wavetable_alloc (n);
       workspace = gsl_fft_complex_workspace_alloc (n);

	  gsl_fft_complex_forward (data, 1, n, 
                                wavetable, workspace);

      gsl_fft_complex_wavetable_free (wavetable);
      gsl_fft_complex_workspace_free (workspace);

  for (i = 1; i <= 599; i++)
  {
    y3a[i] = sqrt(REAL(data,i)*REAL(data,i) + IMAG(data,i)*IMAG(data,i));
  }

	xyGraph3->AddGraph("XtraTitle", DashStyle::Solid, Color::Red, 1, false);
	xyGraph3->ClearGraphs();
	for(i=0; i<300; i++)
	xyGraph3->AddValue(0, (float)i*8.0645, (float)y3a[i]);
	xyGraph3->DrawAll();

	for(i = 0;i<300;i++){
		
		if(y1a[i]>peak1){
		peak1 = y3a[i];
		peak2 = 8.0645*i;
		}

	}
	maskedTextBox4->Text = Convert::ToString((float)peak2);
	peak1 = 0;
	peak2 = 0;
	}

		 }
private: System::Void groupBox8_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagxfft = FALSE;
		 }
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagyfft=TRUE;
		 }
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagyfft=FALSE;
		 }
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagzfft=TRUE;
		 }
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagzfft=FALSE;
		 }
private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagregfft=TRUE;
		 }
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagregfft=FALSE;
		 }
private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagxreg=TRUE;
			 flagyreg=FALSE;
			 flagzreg=FALSE;
		 }
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagxreg=FALSE;
			 flagyreg=TRUE;
			 flagzreg=FALSE;
		 }
private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 flagxreg=FALSE;
			 flagyreg=FALSE;
			 flagzreg=TRUE;
		 }
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void label3_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void maskedTextBox4_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(!flagregfft){
				 if(flagxreg){
		FILE *x = fopen("x.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(x,"%s\n",Convert::ToString(x1[i]));
		}
		fclose(x);
				 }
				 if(flagyreg){
		FILE *y = fopen("y.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(y,"%s\n",Convert::ToString(x2[i]));
		}
		fclose(y);
				 }
				 if(flagzreg){
		FILE *z = fopen("z.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(z,"%s\n",Convert::ToString(x3[i]));
		}
		fclose(z);
				 }
			 }
			 else{
				 if(flagxreg){
		FILE *fftx = fopen("fft_x.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(fftx,"%s\n",Convert::ToString(y1a[i]));
		}
		fclose(fftx);
				 }
				 if(flagyreg){
		FILE *ffty = fopen("fft_y.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(ffty,"%s\n",Convert::ToString(y2a[i]));
		}
		fclose(ffty);
				 }
				 if(flagzreg){
		FILE *fftz = fopen("fft_z.txt","w");
		for(i = 0;i<599 ;i++){
			fprintf(fftz,"%s\n",Convert::ToString(y3a[i]));
		}
		fclose(fftz);
				 }
			 }
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled=false;
			 timer2->Enabled=true;
			 timer3->Enabled=false;
			 button1->PerformClick();
			 
		 }
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled=false;
			 timer2->Enabled=false;
			 timer3->Enabled=true;
			 button3->PerformClick();
		 }
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled=true;
			 timer2->Enabled=false;
			 timer3->Enabled=false;
			 button5->PerformClick();
		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled = true;
			 timer2->Enabled=false;
			 timer3->Enabled=false;
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Enabled=false;
			 timer2->Enabled=false;
			 timer3->Enabled=false;
		 }
private: System::Void maskedTextBox2_MaskInputRejected_1(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
};
}


