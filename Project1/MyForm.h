#pragma once

#include <time.h>
#include <stdlib.h>

namespace SyberSnake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			//
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

		virtual void OnPaint(System::Object^ obj, PaintEventArgs^ e) override {
			Graphics^ g = e->Graphics;

			Brush^ snakeBrush = gcnew SolidBrush(Color::Green);
			g->FillRectangle(snakeBrush, snakePosition.X, snakePosition.Y, blockSize, blockSize);
			 

			Brush^ fruitBrush = gcnew SolidBrush(Color::Red);
			g->FillRectangle(fruitBrush, fruitPosition.X, fruitPosition.Y, blockSize, blockSize);
			
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Point snakePosition;
		Point fruitPosition;
		const int blockSize = 20;
			
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 400);
			
			this->Text = L"SyberSnake";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);



			snakePosition = Point(this->ClientSize.Width / 2, this->ClientSize.Height / 2 );
			srand(time(NULL));
			PlaceFruit();

			this->Paint += gcnew PaintEventHandler(this ,  &MyForm::OnPaint) ;

		}
#pragma endregion
		void PlaceFruit() {
			int maxX = this->ClientSize.Width / blockSize;
			int maxY = this->ClientSize.Height / blockSize;

			fruitPosition = Point(rand() % maxX * blockSize, rand() % maxY * blockSize);
		}


	};
}
