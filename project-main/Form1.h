#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int mx = 150;
	int my = 55;
	int biasY = 60;
	int Logic[10][10];

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Bitmap^ bufferImage;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(-1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1630, 714);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(350, 583);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 83);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(500, 583);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 83);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(653, 583);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(94, 83);
			this->button3->TabIndex = 3;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1630, 727);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Отрисовка буферного изображения на pictureBox1
		if (bufferImage != nullptr)
		{
			e->Graphics->DrawImage(bufferImage, 0, 0);
		}
	}
#pragma endregion
		void fbdvar(int x, int y, String^ name)  // функция создания блока Вход в языке FBD
		{
			x *= mx;
			y = my * y + 16 + biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			SolidBrush^ fontBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawRectangle(pen, x + 10, y + 10, 35, 35);
			g->DrawLine(pen, x + 10 + 35, y + 10 + 35 / 2, x + 45 + 92, y + 10 + 35 / 2);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			if (name->Length > 2)
			{
				x -= ((name->Length - 2) * 4);
				y -= 26;
			}
			g->DrawString(name, drawFont, fontBrush, x + 20, y + 20);
		}
		void fbdand(int x, int y) // функция создания блока AND в языке FBD
		{
			x *= mx;
			y *= my;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			SolidBrush^ fontBrush = gcnew SolidBrush(Color::Black); // задает объект SolidBrush, который используется как цвет для текста или заполнени фигуры
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11); // данный объект создается для определения шрифта и размера текста
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawRectangle(pen, x + 10, y + 10, 105, 75); // создает прямоуголник penом, первые два параметра это точка отрисовки, а следующие два ширина и толщина соответсвенно
			g->DrawLine(pen, x + 10, y + 10 + 67 / 2, x - 26 / 2, y + 10 + 67 / 2);
			g->DrawLine(pen, x + 10, y + 35 + 67 / 2, x - 26 / 2, y + 35 + 67 / 2);
			g->DrawLine(pen, x + 10 + 105, y + 10 + 67 / 2, x + 115 + 45 / 2, y + 10 + 67 / 2);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			g->DrawString("OR", drawFont, fontBrush, x + 43, y + 15);  // создает текст, в котором сначала передается текст, потом объект Font, далее solidbrush, далее задается точка положения
			g->DrawString(Convert::ToString("IN1"), drawFont, fontBrush, x + 18, y + 35);
			g->DrawString(Convert::ToString("IN2"), drawFont, fontBrush, x + 18, y + 60);
			g->DrawString(Convert::ToString("OUT"), drawFont, fontBrush, x + 75, y + 35);
		}

		void fbdjumps(int x, int y, int z) // функция создания вертикальной черты в языке FBD, для соединения элементов, параметр z задает высоту прыжка
		{
			x *= mx;
			y *= my;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawLine(pen, x - 26 / 2, y + 35 + 67 / 2, x - 26 / 2, y + 20 + 67 / 2 + 45 + 55 * (z - 1));
		}

		void fbdend(int x, int y, String^ name) // функция создания блока Выход языке FBD, параметр b отвечает за номер переменной Q
		{
			if (name[0] == 'I' && (name[1] >= '1' || name[1] <= '9')) // условие для того, чтобы физические входы не были выходами
			{
				MessageBox::Show("Физические входы не могут являться выходами");
				Close();
			}
			x *= mx;
			y = my * y + 16 + biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			SolidBrush^ fontBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawRectangle(pen, x + 75, y + 10, 35, 35);
			g->DrawLine(pen, x - 34, y + 10 + 35 / 2, x + 45 + 30, y + 10 + 35 / 2);
			if (name->Length > 2) // условие выноса текста переменной наверх, чтобы влезло внутрь блока
			{
				x -= ((name->Length - 2) * 4);
				y -= 26;
			}
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			g->DrawString(name, drawFont, fontBrush, x + 80, y + 20);

		}

		void lightInput(int x, int y, bool value)
		{
			Graphics^ g = Graphics::FromImage(bufferImage);
			Color color = Color::FromArgb(255, System::Drawing::Color::Green);
			if (!value)
			{
				color = Color::White;
			}
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			g->FillRectangle(fontBrush, 11, 27 + my * y + biasY, 33, 33);

		}

		void fbdINO(int x, int y, bool z) // функция, которая в зависимости от того, что подходит к IN1, подсвечивает его зеленым или белым
		{
			y *= my;
			y += biasY;
			x *= mx;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Color color; // создает объект цвет
			if (z) // переменная передающая состояние фхода
			{
				color = Color::Green; // если приходит 1, то цвет становится зеленым
			}
			else
			{
				color = Color::White; // если приходит 0, то цвет становится белым
			}
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			g->FillRectangle(fontBrush, 12 + x, 32 + y, 40, 22);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			g->DrawString(Convert::ToString("IN1"), drawFont, fontBrushs, x + 18, y + 35); // сначала обновляем надписиь входа, чтобы не было мигания
		}

		void fbdINT(int x, int y, bool z) // функция, которая в зависимости от того, что подходит к IN2, подсвечивает его зеленым или белым
		{
			y *= my;
			x *= mx;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Color color;
			if (z)
			{
				color = Color::Green;
			}
			else
			{
				color = Color::White;
			}
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			g->FillRectangle(fontBrush, 12 + x, 56 + y, 40, 23);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			g->DrawString(Convert::ToString("IN2"), drawFont, fontBrushs, x + 18, y + 60);

		}

		void fbdOUT(int x, int y, bool z) // функция, которая подсвечивает выход блока FBD зеленым или белым
		{
			y *= my;
			y += biasY;
			x *= mx;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Color color;
			if (z)
			{
				color = Color::Green;
			}
			else
			{
				color = Color::White;
			}
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			g->FillRectangle(fontBrush, 75 + x, 32 + y, 38, 23);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			g->DrawString(Convert::ToString("OUT"), drawFont, fontBrushs, x + 75, y + 35);
		}

		void logicAnd(int x, int y)
		{
			fbdINO(x, y, Logic[x - 1][y]);
			fbdINT(x, y, Logic[x - 1][y + 1]);
			Logic[x][y] = Logic[x - 1][y] || Logic[x - 1][y + 1];
			fbdOUT(x, y, Logic[x][y]);
			pictureBox1->Invalidate(); // функция обновления картинки
		}

		void fbdEND(int x, int y, bool z, String^ b) // функция, которая подсвечивает выход программы зеленым или белым
		{
			Logic[x][y] = z;
			y *= my;
			x *= mx;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Graphics^ d = Graphics::FromImage(bufferImage);
			Color color;
			if (z)
			{
				color = Color::Green;
			}
			else
			{
				color = Color::White;
			}
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			g->FillRectangle(fontBrush, 76 + x, 27 + y, 33, 33);
			if (b->Length > 2)
			{
				x -= ((b->Length - 2) * 4);
				y -= 26;
			}
			d->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Включить сглаживание текста
			d->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Включить сглаживание линий и форм
			d->DrawString(b, drawFont, fontBrushs, x + 80, y + 35);
		}

		void cycle()
		{
			logicAnd(1, 0);
			fbdEND(2, 0, Logic[2 - 1][0], "END");
		}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		timer1->Start();
		fbdvar(0, 0, "button1");
		fbdvar(0, 1, "button2");
		fbdjumps(1,0,1);
		fbdand(1,0);
		fbdend(2, 0, "END");
		pictureBox1->Invalidate(); // функция обновления картинки
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	bufferImage = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height); // задание границ отрисовки
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (!Logic[0][0])
	{
		Logic[0][0] = 1;
	}
	else
	{
		Logic[0][0] = 0;
	}
	lightInput(0, 0, Logic[0][0]);
	pictureBox1->Invalidate();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (!Logic[0][1])
	{
		Logic[0][1] = 1;
	}
	else
	{
		Logic[0][1] = 0;
	}
	lightInput(0, 1, Logic[0][1]);
	pictureBox1->Invalidate();
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	cycle();
	pictureBox1->Invalidate();
}
};
}
