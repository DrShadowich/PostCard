#pragma once
#include <wx/wx.h>

// Время сделать отдельное окно открытки!


class ThirdFrame : public wxFrame
{
public:


	wxBitmap congrat_img{};


	wxPanel* panel_of_frame = new wxPanel(this);
	wxStaticBitmap* congratulation{};
	wxButton* playback_button{};


	wxBoxSizer* sizer;


	void set_congrat_img(const wxString& pathofimage);
	

	ThirdFrame(const wxString& title);


};
