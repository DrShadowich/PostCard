#include "ThirdFrame.h"
#include <wx/sound.h>


void ThirdFrame::set_congrat_img(const wxString& pathofimage)
{


	wxSound("core\\tada.wav").Play();


	if (wxFileExists(pathofimage)) {
		
		
		congrat_img = wxBitmap(pathofimage, wxBITMAP_TYPE_PNG);
	
	
	}
	else {
		
		
		congrat_img = wxBitmap("core\\error.png", wxBITMAP_TYPE_PNG);


	}


}


ThirdFrame::ThirdFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{


	set_congrat_img("modify\\congratulation.png");


	if (!ThirdFrame::IsShown()) {


		wxSound("core\\tada.wav").Play();


	}


	if (wxFileExists("modify\\icon.ico")) {
		

		SetIcon(wxIcon("modify\\icon.ico", wxBITMAP_TYPE_ICO));


	}


	else {


		SetIcon(wxIcon("core\\error.ico", wxBITMAP_TYPE_ICO));
	
	
	}

	
	congratulation = new wxStaticBitmap(panel_of_frame, wxID_ANY, congrat_img, wxPoint(0, 0), wxSize(congrat_img.GetWidth(), congrat_img.GetHeight()));


	if (wxFileExists("modify\\playback_audio.wav")) {


		playback_button = new wxButton(panel_of_frame, wxID_ANY, "Пожелание", wxPoint(0, congrat_img.GetHeight()), wxSize(congrat_img.GetWidth(), 25));


		playback_button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& button_event) {


			wxSound("modify\\playback_audio.wav").Play();


			button_event.Skip();


			});


	}


	sizer = new wxBoxSizer(wxVERTICAL);


	sizer->Add(panel_of_frame, wxEXPAND | wxALL, 0);


	this->SetSizer(sizer);
	sizer->Fit(this);


	ThirdFrame::SetSizeHints(ThirdFrame::GetSize(), ThirdFrame::GetSize());


}
