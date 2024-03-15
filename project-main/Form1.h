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
		// Îòðèñîâêà áóôåðíîãî èçîáðàæåíèÿ íà pictureBox1
		if (bufferImage != nullptr)
		{
			e->Graphics->DrawImage(bufferImage, 0, 0);
		}
	}
#pragma endregion
		void fbdvar(int x, int y, String^ name)  // ôóíêöèÿ ñîçäàíèÿ áëîêà Âõîä â ÿçûêå FBD
		{
			x *= mx;
			y = my * y + 16 + biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			SolidBrush^ fontBrush = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawRectangle(pen, x + 10, y + 10, 35, 35);
			g->DrawLine(pen, x + 10 + 35, y + 10 + 35 / 2, x + 45 + 92, y + 10 + 35 / 2);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
			if (name->Length > 2)
			{
				x -= ((name->Length - 2) * 4);
				y -= 26;
			}
			g->DrawString(name, drawFont, fontBrush, x + 20, y + 20);
		}
		void fbdand(int x, int y) // ôóíêöèÿ ñîçäàíèÿ áëîêà AND â ÿçûêå FBD
		{
			x *= mx;
			y *= my;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			SolidBrush^ fontBrush = gcnew SolidBrush(Color::Black); // çàäàåò îáúåêò SolidBrush, êîòîðûé èñïîëüçóåòñÿ êàê öâåò äëÿ òåêñòà èëè çàïîëíåíè ôèãóðû
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11); // äàííûé îáúåêò ñîçäàåòñÿ äëÿ îïðåäåëåíèÿ øðèôòà è ðàçìåðà òåêñòà
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawRectangle(pen, x + 10, y + 10, 105, 75); // ñîçäàåò ïðÿìîóãîëíèê penîì, ïåðâûå äâà ïàðàìåòðà ýòî òî÷êà îòðèñîâêè, à ñëåäóþùèå äâà øèðèíà è òîëùèíà ñîîòâåòñâåííî
			g->DrawLine(pen, x + 10, y + 10 + 67 / 2, x - 26 / 2, y + 10 + 67 / 2);
			g->DrawLine(pen, x + 10, y + 35 + 67 / 2, x - 26 / 2, y + 35 + 67 / 2);
			g->DrawLine(pen, x + 10 + 105, y + 10 + 67 / 2, x + 115 + 45 / 2, y + 10 + 67 / 2);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
			g->DrawString("OR", drawFont, fontBrush, x + 43, y + 15);  // ñîçäàåò òåêñò, â êîòîðîì ñíà÷àëà ïåðåäàåòñÿ òåêñò, ïîòîì îáúåêò Font, äàëåå solidbrush, äàëåå çàäàåòñÿ òî÷êà ïîëîæåíèÿ
			g->DrawString(Convert::ToString("IN1"), drawFont, fontBrush, x + 18, y + 35);
			g->DrawString(Convert::ToString("IN2"), drawFont, fontBrush, x + 18, y + 60);
			g->DrawString(Convert::ToString("OUT"), drawFont, fontBrush, x + 75, y + 35);
		}

		void fbdjumps(int x, int y, int z) // ôóíêöèÿ ñîçäàíèÿ âåðòèêàëüíîé ÷åðòû â ÿçûêå FBD, äëÿ ñîåäèíåíèÿ ýëåìåíòîâ, ïàðàìåòð z çàäàåò âûñîòó ïðûæêà
		{
			x *= mx;
			y *= my;
			y += biasY;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Pen^ pen = gcnew Pen(Color::Black, 2);
			g->DrawLine(pen, x - 26 / 2, y + 35 + 67 / 2, x - 26 / 2, y + 20 + 67 / 2 + 45 + 55 * (z - 1));
		}

		void fbdend(int x, int y, String^ name) // ôóíêöèÿ ñîçäàíèÿ áëîêà Âûõîä ÿçûêå FBD, ïàðàìåòð b îòâå÷àåò çà íîìåð ïåðåìåííîé Q
		{
			if (name[0] == 'I' && (name[1] >= '1' || name[1] <= '9')) // óñëîâèå äëÿ òîãî, ÷òîáû ôèçè÷åñêèå âõîäû íå áûëè âûõîäàìè
			{
				MessageBox::Show("Ôèçè÷åñêèå âõîäû íå ìîãóò ÿâëÿòüñÿ âûõîäàìè");
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
			if (name->Length > 2) // óñëîâèå âûíîñà òåêñòà ïåðåìåííîé íàâåðõ, ÷òîáû âëåçëî âíóòðü áëîêà
			{
				x -= ((name->Length - 2) * 4);
				y -= 26;
			}
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
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

	void fbdsteps(int x, int y, int z) // функция создания горизонтальной черты в языке FBD, для заполнения пустот между элементами, параметр z задает количество свободных клеток
	{
		int a, b;
		x *= mx;
		y *= my;
		y += biasY;
		Graphics^ g = Graphics::FromImage(bufferImage);
		Pen^ pen = gcnew Pen(Color::Black, 2);
		if (z > 0)
		{
			g->DrawLine(pen, x - 18 , y + 26 + 35 / 2, x + 45 + 92 + 150 * (z - 1), y + 26 + 35 / 2);
			while (z > 0)
			{
			a = x / mx + z - 1;
			b = (y - biasY) / my;
			Logic[x/mx + z - 1][(y - biasY)/ my] = true;
			z--;
			}
		}
	}

		void fbdINO(int x, int y, bool z) // ôóíêöèÿ, êîòîðàÿ â çàâèñèìîñòè îò òîãî, ÷òî ïîäõîäèò ê IN1, ïîäñâå÷èâàåò åãî çåëåíûì èëè áåëûì
		{
			y *= my;
			y += biasY;
			x *= mx;
			Graphics^ g = Graphics::FromImage(bufferImage);
			Color color; // ñîçäàåò îáúåêò öâåò
			if (z) // ïåðåìåííàÿ ïåðåäàþùàÿ ñîñòîÿíèå ôõîäà
			{
				color = Color::Green; // åñëè ïðèõîäèò 1, òî öâåò ñòàíîâèòñÿ çåëåíûì
			}
			else
			{
				color = Color::White; // åñëè ïðèõîäèò 0, òî öâåò ñòàíîâèòñÿ áåëûì
			}
			SolidBrush^ fontBrush = gcnew SolidBrush(color);
			SolidBrush^ fontBrushs = gcnew SolidBrush(Color::Black);
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
			g->FillRectangle(fontBrush, 12 + x, 32 + y, 40, 22);
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
			g->DrawString(Convert::ToString("IN1"), drawFont, fontBrushs, x + 18, y + 35); // ñíà÷àëà îáíîâëÿåì íàäïèñèü âõîäà, ÷òîáû íå áûëî ìèãàíèÿ
		}

		void fbdINT(int x, int y, bool z) // ôóíêöèÿ, êîòîðàÿ â çàâèñèìîñòè îò òîãî, ÷òî ïîäõîäèò ê IN2, ïîäñâå÷èâàåò åãî çåëåíûì èëè áåëûì
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
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
			g->DrawString(Convert::ToString("IN2"), drawFont, fontBrushs, x + 18, y + 60);

		}

		void fbdOUT(int x, int y, bool z) // ôóíêöèÿ, êîòîðàÿ ïîäñâå÷èâàåò âûõîä áëîêà FBD çåëåíûì èëè áåëûì
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
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
			g->DrawString(Convert::ToString("OUT"), drawFont, fontBrushs, x + 75, y + 35);
		}

		void logicAnd(int x, int y)
		{
			fbdINO(x, y, Logic[x - 1][y]);
			fbdINT(x, y, Logic[x - 1][y + 1]);
			Logic[x][y] = Logic[x - 1][y] || Logic[x - 1][y + 1];
			fbdOUT(x, y, Logic[x][y]);
			pictureBox1->Invalidate(); // ôóíêöèÿ îáíîâëåíèÿ êàðòèíêè
		}

		void fbdEND(int x, int y, bool z, String^ b) // ôóíêöèÿ, êîòîðàÿ ïîäñâå÷èâàåò âûõîä ïðîãðàììû çåëåíûì èëè áåëûì
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
			d->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå òåêñòà
			d->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias; // Âêëþ÷èòü ñãëàæèâàíèå ëèíèé è ôîðì
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
		pictureBox1->Invalidate(); // ôóíêöèÿ îáíîâëåíèÿ êàðòèíêè
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	bufferImage = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height); // çàäàíèå ãðàíèö îòðèñîâêè
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
