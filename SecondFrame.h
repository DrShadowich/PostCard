#pragma once
#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/sound.h>




class SecondFrame : public wxFrame
{


private:


	void OnOpenFile(wxCommandEvent& file_event);
	void OnButtonClicked(wxCommandEvent& click_event);
	wxDECLARE_EVENT_TABLE();


public:


	wxBoxSizer* frame_box_sizer;


	wxStaticText* setting_text_background;
	wxStaticText* setting_text_cursor;
	wxStaticText* setting_text_icon;
	wxStaticText* setting_text_congrat;
	wxStaticText* setting_text_playback;


	wxBitmap modify_icon_img;
	wxBitmap modify_background_img;
	wxBitmap modify_congrat_img;
	wxBitmap modify_cursor_img;


//  wxSound


	wxButton* setting_modify_img{};
	wxButton* setting_modify_playback{};
	wxButton* setting_modify_ico{};
	wxButton* setting_modify_background{};
	wxButton* setting_modify_cursor{};
	wxButton* play_playback{};


	wxStaticBitmap* setting_congrat{};
	wxStaticBitmap* setting_icon{};
	wxStaticBitmap* setting_cursor{};
	wxStaticBitmap* setting_background{};
	wxStaticBitmap* playback_image{};


	wxPanel* panel_of_frame{};


	void CopyFileW(const wxString& to, const wxString& from) {


		wxCopyFile(to, from);
	
	
	}


	SecondFrame(const wxString& title);


};

