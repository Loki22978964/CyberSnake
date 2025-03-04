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

			Brush^ fruitBrush = gcnew SolidBrush(Color::Red);
			g->FillRectangle(fruitBrush, fruitPosition.X, fruitPosition.Y, blockSize, blockSize);

			Brush^ snakeBrush = gcnew SolidBrush(Color::Green);
			g->FillRectangle(snakeBrush, snakePosition.X, snakePosition.Y, blockSize, blockSize);
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		Point snakePosition;
		Point fruitPosition;
		const int blockSize = 20;
		Timer^ timer;
		int moveX = 0, moveY = 0;

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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 400);

			this->Text = L"SyberSnake";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);



			snakePosition = Point(100, 100);
			srand(time(NULL));
			PlaceFruit();

			timer = gcnew Timer();
			timer->Interval = 200; //game speed
			timer->Tick += gcnew EventHandler(this, &MyForm::OnTimerTick);
			timer->Start();


			this->Paint += gcnew PaintEventHandler(this, &MyForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &MyForm::OnKeyDown);


		}
#pragma endregion
		void PlaceFruit() {
			int maxX = this->ClientSize.Width / blockSize;
			int maxY = this->ClientSize.Height / blockSize;

			fruitPosition = Point((rand() % maxX) * blockSize, (rand() % maxY) * blockSize);
		}

		void OnTimerTick(Object^ obj, EventArgs^ e) {
			snakePosition.X += moveX * blockSize;
			snakePosition.Y += moveY * blockSize;

			this->Invalidate();
		}

		void OnKeyDown(Object^ obj, KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Up:
				moveX = 0;
				moveY = -1;
				break;
			case Keys::Down:
				moveX = 0;
				moveY = 1;
				break;
			case Keys::Left:
				moveX = -1;
				moveY = 0;
				break;
			case Keys::Right:
				moveX = 1;
				moveY = 0;
				break;
			case Keys::W:
				moveX = 0;
				moveY = -1;
				break;
			case Keys::S:
				moveX = 0;
				moveY = 1;
				break;
			case Keys::A:
				moveX = -1;
				moveY = 0;
				break;
			case Keys::D:
				moveX = 1;
				moveY = 0;
				break;
			}
		}

	};
}
