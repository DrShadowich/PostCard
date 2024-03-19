#pragma once
#include <wx/wx.h>
#include "SecondFrame.h"
#include "App.h"

class CustomPanel : public wxPanel {
private:
	
	
	wxDECLARE_EVENT_TABLE();


public:
	
	
	wxBitmap panel_image{};

	
	CustomPanel(wxWindow* parent, const wxString& imagePath) : wxPanel(parent) {
		

		if (wxFileExists(imagePath)) {
			
			
			panel_image = wxBitmap(imagePath, wxBITMAP_TYPE_PNG);


			SetBackgroundStyle(wxBG_STYLE_CUSTOM);
		
		
		}


	}


	void OnPaint(wxPaintEvent& event) {
		
		
		wxPaintDC dc(this);


		dc.DrawBitmap(panel_image, 0, 0, false);
		
		
		event.Skip();
	
	
	}


};


class MainFrame : public wxFrame
{


private:
	
	
	int size_of_window_x{ 200 };
	int size_of_window_y{ 300 };


	void OnButtonClicked(wxCommandEvent& click_event);
	wxDECLARE_EVENT_TABLE();


public:


	wxButton* start_button{};
	wxButton* update_frame{};
	wxButton* setting_button{};


	wxPanel* panel_of_frame{};
	wxBoxSizer* sizer{};
	

	int get_size_y() const {
		return size_of_window_y;
	}


	int get_size_x() const {
		return size_of_window_x;
	}


	MainFrame(const wxString& title);


};