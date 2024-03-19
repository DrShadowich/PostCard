#include "SecondFrame.h"
#include <wx/wx.h>
#include <wx/sound.h>


enum IDs {
	
	
	FIRST = 1, SECOND, THIRD, FOURTH, FIFTH, SIXTH, SEVENTH, EIGHTH


};


wxBEGIN_EVENT_TABLE(SecondFrame, wxFrame)
EVT_BUTTON(FIRST, SecondFrame::OnButtonClicked)
EVT_BUTTON(SECOND, SecondFrame::OnButtonClicked)
EVT_BUTTON(THIRD, SecondFrame::OnButtonClicked)
EVT_BUTTON(FOURTH, SecondFrame::OnButtonClicked)
EVT_BUTTON(FIFTH, SecondFrame::OnButtonClicked)
EVT_BUTTON(SIXTH, SecondFrame::OnButtonClicked)
EVT_BUTTON(SEVENTH, SecondFrame::OnButtonClicked)
EVT_BUTTON(EIGHTH, SecondFrame::OnButtonClicked)
wxEND_EVENT_TABLE()


SecondFrame::SecondFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize) {


	SetIcon(wxIcon("core\\settings.ico", wxBITMAP_TYPE_ICO));


	if (wxFileExists("modify\\icon.ico")) {


		modify_icon_img = wxBitmap("modify\\icon.ico", wxBITMAP_TYPE_ICO);


	}
	else {


		modify_icon_img = wxBitmap("core\\error.ico", wxBITMAP_TYPE_ICO);


	}


	if (wxFileExists("modify\\cursor.png")) {


		modify_cursor_img = wxBitmap("modify\\cursor.png", wxBITMAP_TYPE_PNG);


	}


	else {


		modify_cursor_img = wxBitmap("core\\error.ico", wxBITMAP_TYPE_ICO);


	}

	
	if (wxFileExists("core\\playback_sound.wav")) {


		wxSound modify_playback("core\\playback_sound.wav");


	}
	

	if (wxFileExists("modify\\background.png")) {


		modify_background_img = wxBitmap("modify\\background.png", wxBITMAP_TYPE_PNG);


	}
	else {


		modify_background_img = wxBitmap("core\\error.png", wxBITMAP_TYPE_PNG);


	}


	if (wxFileExists("modify\\congratulation.png")) {


		if (wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG).GetWidth() < 512 ||
			wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG).GetHeight() < 512) {


			wxMessageBox("Ширина или высота изображения-сюрприза должна быть равна или больше 512 пикселей");
			CopyFileW("core\\error.png", "modify\\congratulation.png");


		}


		modify_congrat_img = wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG);


	}
	else {


		modify_congrat_img = wxBitmap("core\\error.png", wxBITMAP_TYPE_PNG);


	}


	panel_of_frame = new wxPanel(this);

	// id FIRST
	setting_text_background = new wxStaticText(panel_of_frame, wxID_ANY, "Задний фон", wxPoint((modify_icon_img.GetWidth() / 2 - 20) - 24, 5), wxSize(75, 15), wxALIGN_CENTER);
	setting_background = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_background_img, wxPoint(modify_icon_img.GetWidth() / 2 - 40, 25),
		wxSize(64, 64));
	setting_modify_background = new wxButton(panel_of_frame, FIRST, "Set background", wxPoint(modify_icon_img.GetWidth() / 2 - 56, 100), wxSize(95, 25));


	setting_text_cursor = new wxStaticText(panel_of_frame, wxID_ANY, "Курсор", 
		wxPoint((modify_icon_img.GetWidth() / 2 - 20) - 4, 162), wxSize(75, 15));
	setting_cursor = new wxStaticBitmap(panel_of_frame, wxID_ANY,
		modify_cursor_img, wxPoint(modify_icon_img.GetWidth() / 2 - 20, 181), wxSize(32, 32));
	setting_modify_cursor = new wxButton(panel_of_frame, FOURTH, "Set Cursor", wxPoint(modify_icon_img.GetWidth() / 2 - 40, 218), wxSize(75, 25));


	// id SECOND
	setting_text_icon = new wxStaticText(panel_of_frame, wxID_ANY, "Иконка", 
		wxPoint(modify_icon_img.GetWidth() / 2 - 20, modify_icon_img.GetHeight() * 1.60 - 30), wxSize(50, 15));
	setting_icon = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_icon_img, wxPoint(5, modify_icon_img.GetHeight() * 1.60), wxSize(modify_icon_img.GetWidth(), modify_icon_img.GetHeight()));
	setting_modify_ico = new wxButton(panel_of_frame, SECOND, "Set Icon", wxPoint(modify_icon_img.GetWidth() / 2 - 20, modify_icon_img.GetHeight() * 3 - 100), wxSize(55, 25));
	
	// id THIRD
	setting_text_congrat = new wxStaticText(panel_of_frame, wxID_ANY, "Поздравление", wxPoint(((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4)) * 1.5) - 150, 5), wxSize(100, 15));
	setting_congrat = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_congrat_img, 
		wxPoint((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4) + 5) - 150, 50),
		wxSize(modify_congrat_img.GetWidth(), modify_congrat_img.GetHeight()));
	setting_modify_img = new wxButton(panel_of_frame, THIRD, "Set Congrat", 
		wxPoint(((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4)) * 1.5) - 150, modify_congrat_img.GetHeight() + 55), wxSize(75, 25));

	// id FIFTH & SIXTH
	setting_text_playback = new wxStaticText(panel_of_frame, wxID_ANY, "Аудио-файл",
		wxPoint(modify_icon_img.GetWidth() / 2 - 36, 266), wxSize(75, 15));
	playback_image = new wxStaticBitmap(panel_of_frame, wxID_ANY, wxBitmap("core\\playback.png", wxBITMAP_TYPE_PNG), 
		wxPoint(modify_icon_img.GetWidth() / 2 - 20, 286), wxSize(32, 32));
	play_playback = new wxButton(panel_of_frame, SIXTH, "Произвести", wxPoint(modify_icon_img.GetWidth() / 2 - 40, 323), wxSize(75, 25));
	setting_modify_playback = new wxButton(panel_of_frame, FIFTH, "Set Sound", wxPoint(modify_icon_img.GetWidth() / 2 - 40, 350), wxSize(75, 25));


	frame_box_sizer = new wxBoxSizer(wxVERTICAL);
	frame_box_sizer->Add(panel_of_frame, 0, wxEXPAND | wxALL, 5);
	frame_box_sizer->AddStretchSpacer();
	this->SetSizer(frame_box_sizer);
	frame_box_sizer->Fit(this);

	// id SEVENTH & EIGHTH
	wxButton* update_images_button = new wxButton(panel_of_frame, SEVENTH, "Update", wxPoint(5, 5), wxSize(75, 25));
	wxButton* close_button = new wxButton(panel_of_frame, EIGHTH, "Close", wxPoint(5, 35), wxSize(75, 25));


	SecondFrame::SetSizeHints(SecondFrame::GetSize(), SecondFrame::GetSize());


}


void SecondFrame::OnOpenFile(wxCommandEvent& file_event) {


	if (file_event.GetId() != SECOND && file_event.GetId() != FIFTH) {


		wxFileDialog OpenPNGFile(nullptr, "Выберите картинку в формате .png", "", "", "PNG FILES (*.png*)|*.png*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);


		if (OpenPNGFile.ShowModal() == wxID_CANCEL) {


			return;
		
		
		}


		wxString selected_file = OpenPNGFile.GetPath();
		wxString to_file;


		if (file_event.GetId() == FIRST) {


			to_file = "modify\\background.png";


		}


		if (file_event.GetId() == THIRD) {


			to_file = "modify\\congratulation.png";


		}


		if (file_event.GetId() == FOURTH) {


			to_file = "modify\\cursor.png";


		}


		CopyFileW(selected_file, to_file);


	}


	if (file_event.GetId() == FIFTH) {


		wxFileDialog OpenWAVFile(nullptr, "Выберите иконку в формате .wav", "", "", "wav файлы (*.wav*)|*.wav*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);


		if (OpenWAVFile.ShowModal() == wxID_CANCEL) {
			
			
			return;
		
		
		}


		wxString selected_file = OpenWAVFile.GetPath();
		wxString to_file = "modify\\playback_audio.wav";


		CopyFileW(selected_file, to_file);


	}


	if(file_event.GetId() == SECOND) {
	

		wxFileDialog OpenICOFile(nullptr, "Выберите иконку в формате .ico", "", "", "ico файлы (*.ico*)|*.ico*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
		

		if (OpenICOFile.ShowModal() == wxID_CANCEL) {
			
			
			return;
		
		
		}

		
		wxString selected_file = OpenICOFile.GetPath();
		wxString to_file = "modify\\icon.ico";


		CopyFileW(selected_file, to_file);


	}

}


void SecondFrame::OnButtonClicked(wxCommandEvent& click_event) {
	
	
	if (click_event.GetId() == FIRST) {


		setting_modify_background->Bind(wxEVT_BUTTON, &SecondFrame::OnOpenFile, this);


	}

	
	else if (click_event.GetId() == SECOND) {


		setting_modify_ico->Bind(wxEVT_BUTTON, &SecondFrame::OnOpenFile, this);


	}


	else if (click_event.GetId() == THIRD) {


		setting_modify_img->Bind(wxEVT_BUTTON, &SecondFrame::OnOpenFile, this);


	}


	else if (click_event.GetId() == FOURTH) {


		setting_modify_cursor->Bind(wxEVT_BUTTON, &SecondFrame::OnOpenFile, this);


	}


	else if (click_event.GetId() == FIFTH) {


		setting_modify_playback->Bind(wxEVT_BUTTON, &SecondFrame::OnOpenFile, this);


	}


	else if (click_event.GetId() == SIXTH) {


		wxSound sound("modify\\playback_audio.wav");
		sound.Play();
	
	
	}


	else if (click_event.GetId() == SEVENTH) {



		setting_text_background->Destroy();
		setting_background->Destroy();
		setting_modify_background->Destroy();


		if (wxFileExists("modify\\cursor.png")) {


			setting_text_cursor->Destroy();
			setting_cursor->Destroy();
			setting_modify_cursor->Destroy();


		}


		setting_text_icon->Destroy();
		setting_icon->Destroy();
		setting_modify_ico->Destroy();


		setting_text_congrat->Destroy();
		setting_congrat->Destroy();
		setting_modify_img->Destroy();


		if (wxFileExists("modify\\playback_audio.wav")) {
				
				
				setting_text_playback->Destroy();
				playback_image->Destroy();
				play_playback->Destroy();
				setting_modify_playback->Destroy();
			
		
		}
		

		if (wxFileExists("modify\\icon.ico")) {


			modify_icon_img = wxBitmap("modify\\icon.ico", wxBITMAP_TYPE_ICO);


		}


		else {


			modify_icon_img = wxBitmap("core\\error.ico", wxBITMAP_TYPE_ICO);


		}


		if (wxFileExists("modify\\cursor.png")) {


			modify_cursor_img = wxBitmap("modify\\cursor.png", wxBITMAP_TYPE_PNG);

		}


		if (wxFileExists("core\\playback_sound.wav")) {


			wxSound modify_playback("core\\playback_sound.wav");


		}


		if (wxFileExists("modify\\background.png")) {


			modify_background_img = wxBitmap("modify\\background.png", wxBITMAP_TYPE_PNG);


		}


		else {


			modify_background_img = wxBitmap("core\\error.png", wxBITMAP_TYPE_PNG);


		}


		if (wxFileExists("modify\\congratulation.png")) {


			if (wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG).GetWidth() < 512 || 
				wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG).GetHeight() < 512) {


				wxMessageBox("Ширина или высота изображения-сюрприза должна быть равна или больше 512 пикселей");
				CopyFileW("core\\error.png", "modify\\congratulation.png");


			}


				modify_congrat_img = wxBitmap("modify\\congratulation.png", wxBITMAP_TYPE_PNG);
			
			
		}


		else {


			modify_congrat_img = wxBitmap("core\\error.png", wxBITMAP_TYPE_PNG);


		}


		setting_text_background = new wxStaticText(panel_of_frame, wxID_ANY, "Задний фон", wxPoint((modify_icon_img.GetWidth() / 2 - 20) - 24, 5), wxSize(75, 15), wxALIGN_CENTER);
		setting_background = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_background_img, wxPoint(modify_icon_img.GetWidth() / 2 - 40, 25),
			wxSize(64, 64));
		setting_modify_background = new wxButton(panel_of_frame, FIRST, "Set background", wxPoint(modify_icon_img.GetWidth() / 2 - 56, 100), wxSize(95, 25));


		setting_text_cursor = new wxStaticText(panel_of_frame, wxID_ANY, "Курсор",
			wxPoint((modify_icon_img.GetWidth() / 2 - 20) - 4, 162), wxSize(75, 15));
		setting_cursor = new wxStaticBitmap(panel_of_frame, wxID_ANY,
			modify_cursor_img, wxPoint(modify_icon_img.GetWidth() / 2 - 20, 181), wxSize(32, 32));
		setting_modify_cursor = new wxButton(panel_of_frame, FOURTH, "Set Cursor", 
			wxPoint(modify_icon_img.GetWidth() / 2 - 40, 181 + modify_cursor_img.GetHeight() + 5), wxSize(75, 25));


		setting_text_icon = new wxStaticText(panel_of_frame, wxID_ANY, "Иконка",
			wxPoint(modify_icon_img.GetWidth() / 2 - 20, modify_icon_img.GetHeight() * 1.60 - 30), wxSize(50, 15));
		setting_icon = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_icon_img, wxPoint(5, modify_icon_img.GetHeight() * 1.60), wxSize(modify_icon_img.GetWidth(), modify_icon_img.GetHeight()));
		setting_modify_ico = new wxButton(panel_of_frame, SECOND, "Set Icon", wxPoint(modify_icon_img.GetWidth() / 2 - 20, modify_icon_img.GetHeight() * 3 - 100), wxSize(55, 25));


		setting_text_congrat = new wxStaticText(panel_of_frame, wxID_ANY, "Поздравление", wxPoint(((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4)) * 1.5) - 150, 5), wxSize(100, 15));
		setting_congrat = new wxStaticBitmap(panel_of_frame, wxID_ANY, modify_congrat_img,
			wxPoint((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4) + 5) - 150, 50),
			wxSize(modify_congrat_img.GetWidth(), modify_congrat_img.GetHeight()));
		setting_modify_img = new wxButton(panel_of_frame, THIRD, "Set Congrat",
			wxPoint(((modify_congrat_img.GetWidth() - (modify_icon_img.GetWidth() / 4)) * 1.5) - 150, modify_congrat_img.GetHeight() + 55), wxSize(75, 25));


		setting_text_playback = new wxStaticText(panel_of_frame, wxID_ANY, "Аудио-файл",
			wxPoint(modify_icon_img.GetWidth() / 2 - 36, 266), wxSize(75, 15));
		playback_image = new wxStaticBitmap(panel_of_frame, wxID_ANY, wxBitmap("core\\playback.png", wxBITMAP_TYPE_PNG),
			wxPoint(modify_icon_img.GetWidth() / 2 - 20, 286), wxSize(32, 32));
		play_playback = new wxButton(panel_of_frame, SIXTH, "Произвести", wxPoint(modify_icon_img.GetWidth() / 2 - 40, 323), wxSize(75, 25));
		setting_modify_playback = new wxButton(panel_of_frame, FIFTH, "Set Sound", wxPoint(modify_icon_img.GetWidth() / 2 - 40, 350), wxSize(75, 25));



	}


	else if (click_event.GetId() == EIGHTH) {
	

		SecondFrame::Close(true);


	}


}