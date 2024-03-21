#pragma once
#include "Mesh.h"

class Mesh;

namespace Lighting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangePixelToolWindow
	/// </summary>
	public ref class ChangePixelToolWindow : public System::Windows::Forms::Form
	{
	public:
		ChangePixelToolWindow(Mesh* meshInstance)
		{
			myMesh = meshInstance;
			InitializeComponent();
			
			// Y TrackBar
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarY->Location = System::Drawing::Point(10, 20);
			this->trackBarY->Size = System::Drawing::Size(264, 45);
			this->trackBarY->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarY->Minimum = 0;      // Set the minimum value
			this->trackBarY->Maximum = 200;    // Set the maximum value
			this->trackBarY->Value = 100;

			// U TrackBar
			this->trackBarU = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarU->Location = System::Drawing::Point(10, 70);
			this->trackBarU->Size = System::Drawing::Size(264, 45);
			this->trackBarU->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarU->Minimum = 0;      // Set the minimum value
			this->trackBarU->Maximum = 200;    // Set the maximum value
			this->trackBarU->Value = 100;

			// V TrackBar
			this->trackBarV = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarV->Location = System::Drawing::Point(10, 120);
			this->trackBarV->Size = System::Drawing::Size(264, 45);
			this->trackBarV->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBarV->Minimum = 0;      // Set the minimum value
			this->trackBarV->Maximum = 200;    // Set the maximum value
			this->trackBarV->Value = 100;

			// Invert Colors CheckBox
			this->checkBoxInvertColors = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxInvertColors->Location = System::Drawing::Point(10, 170);
			this->checkBoxInvertColors->Size = System::Drawing::Size(100, 24);
			this->checkBoxInvertColors->Text = L"Invert Colors";

			// Y TrackBar Label
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelY->Location = System::Drawing::Point(280, 20); // Adjust position as needed
			this->labelY->Size = System::Drawing::Size(40, 20); // Adjust size as needed
			this->labelY->Text = L"100%"; // Default value

			// U TrackBar Label
			this->labelU = (gcnew System::Windows::Forms::Label());
			this->labelU->Location = System::Drawing::Point(280, 70); // Adjust position as needed
			this->labelU->Size = System::Drawing::Size(40, 20); // Adjust size as needed
			this->labelU->Text = L"100%"; // Default value

			// V TrackBar Label
			this->labelV = (gcnew System::Windows::Forms::Label());
			this->labelV->Location = System::Drawing::Point(280, 120); // Adjust position as needed
			this->labelV->Size = System::Drawing::Size(40, 20); // Adjust size as needed
			this->labelV->Text = L"100%"; // Default value


			// Add controls to the form
			this->Controls->Add(this->trackBarY);
			this->Controls->Add(this->trackBarU);
			this->Controls->Add(this->trackBarV);
			this->Controls->Add(this->checkBoxInvertColors);

			// Add labels to the form
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->labelU);
			this->Controls->Add(this->labelV);

			// Add event handlers for TrackBars' ValueChanged events to update labels
			this->trackBarY->ValueChanged += gcnew System::EventHandler(this, &ChangePixelToolWindow::trackBarY_ValueChanged);
			this->trackBarU->ValueChanged += gcnew System::EventHandler(this, &ChangePixelToolWindow::trackBarU_ValueChanged);
			this->trackBarV->ValueChanged += gcnew System::EventHandler(this, &ChangePixelToolWindow::trackBarV_ValueChanged);

			// ChangePixelToolWindow
	// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"ChangePixelToolWindow";
			this->Text = L"Tool Box";
			this->Load += gcnew System::EventHandler(this, &ChangePixelToolWindow::ChangePixelToolWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChangePixelToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		Mesh* myMesh;

		// TrackBar and CheckBox declarations (add to the class definition)
		 System::Windows::Forms::TrackBar^ trackBarY;
		 System::Windows::Forms::TrackBar^ trackBarU;
		 System::Windows::Forms::TrackBar^ trackBarV;
		 System::Windows::Forms::CheckBox^ checkBoxInvertColors;

		 // Label declarations (add to the class definition)
		System::Windows::Forms::Label^ labelY;
		System::Windows::Forms::Label^ labelU;
		System::Windows::Forms::Label^ labelV;

		System::Void UpdateMeshColor() {
			// Convert trackbar values to YUV components
			float yValue = static_cast<float>(this->trackBarY->Value) / 100.0f;
			float uValue = static_cast<float>(this->trackBarU->Value) / 100.0f;
			float vValue = static_cast<float>(this->trackBarV->Value) / 100.0f;

			//function to set shader uniforms
			myMesh->SetShaderYuvUniforms(yValue, uValue, vValue);
		}

		//calling the update-mesh-color method upon any value changed 
		System::Void trackBarY_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			this->labelY->Text = this->trackBarY->Value.ToString() + "%";
			UpdateMeshColor();
		}

		System::Void trackBarU_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			this->labelU->Text = this->trackBarU->Value.ToString() + "%";
			UpdateMeshColor();
		}

		System::Void trackBarV_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			this->labelV->Text = this->trackBarV->Value.ToString() + "%";
			UpdateMeshColor();

}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// ChangePixelToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"ChangePixelToolWindow";
			this->Text = L"ChangePixelToolWindow";
			this->Load += gcnew System::EventHandler(this, &ChangePixelToolWindow::ChangePixelToolWindow_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ChangePixelToolWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
