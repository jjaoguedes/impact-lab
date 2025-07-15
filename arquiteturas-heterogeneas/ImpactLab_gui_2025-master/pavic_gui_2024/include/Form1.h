#pragma once

namespace SepiaFilterApp {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::PictureBox^ pbox_input;
    private: System::Windows::Forms::PictureBox^ pbox_output;
    private: System::Windows::Forms::Button^ bt_filter_Sepia_MultiThread;

    private:
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->pbox_input = (gcnew System::Windows::Forms::PictureBox());
            this->pbox_output = (gcnew System::Windows::Forms::PictureBox());
            this->bt_filter_Sepia_MultiThread = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // 
            // pbox_input
            // 
            this->pbox_input->Location = System::Drawing::Point(12, 12);
            this->pbox_input->Size = System::Drawing::Size(300, 200);
            this->pbox_input->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;

            // 
            // pbox_output
            // 
            this->pbox_output->Location = System::Drawing::Point(12, 230);
            this->pbox_output->Size = System::Drawing::Size(300, 200);
            this->pbox_output->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;

            // 
            // bt_filter_Sepia_MultiThread
            // 
            this->bt_filter_Sepia_MultiThread->Location = System::Drawing::Point(12, 450);
            this->bt_filter_Sepia_MultiThread->Size = System::Drawing::Size(100, 30);
            this->bt_filter_Sepia_MultiThread->Text = L"Apply Sepia";
            this->bt_filter_Sepia_MultiThread->Click += gcnew System::EventHandler(this, &Form1::bt_filter_Sepia_MultiThread_Click);

            // 
            // Form1
            // 
            this->ClientSize = System::Drawing::Size(800, 500);
            this->Controls->Add(this->pbox_input);
            this->Controls->Add(this->pbox_output);
            this->Controls->Add(this->bt_filter_Sepia_MultiThread);
            this->ResumeLayout(false);
        }

    public:
        // Event handler for the Sepia button click
        System::Void bt_filter_Sepia_MultiThread_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
