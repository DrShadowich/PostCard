#include "MainFrame.h"
#include "SecondFrame.h"
#include "ThirdFrame.h"
#include <wx/sound.h>


ThirdFrame* thirdFrame;
MainFrame* mainFrame;


enum IDs {


	FIRST = 1, SECOND, THIRD, FOURTH


};


wxBEGIN_EVENT_TABLE(CustomPanel, wxPanel)
EVT_PAINT(CustomPanel::OnPaint)
wxEND_EVENT_TABLE()


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_BUTTON(FIRST, MainFrame::OnButtonClicked)
EVT_BUTTON(THIRD, MainFrame::OnButtonClicked)
EVT_BUTTON(FOURTH, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	

	if (wxFileExists("modify\\icon.ico")) {
		
		
		SetIcon(wxIcon("modify\\icon.ico", wxBITMAP_TYPE_ICO));
	
	
	}


	else {


		SetIcon(wxIcon("core\\error.ico", wxBITMAP_TYPE_ICO));
	
	
	}
	

	wxInitAllImageHandlers();


	panel_of_frame = new CustomPanel(this, "modify\\background.png");
	panel_of_frame->SetBackgroundColour(wxColour(0, 0, 0, 0));
	start_button = new wxButton(panel_of_frame, FIRST, "Нажмите кнопку\nдля сюрприза", wxPoint(get_size_x() / 4, get_size_y() / 4), wxSize(get_size_x() / 1.9, get_size_y() / 4));
	setting_button = new wxButton(panel_of_frame, THIRD, "Настроить собственную открытку", wxPoint(0, get_size_y() - 25), wxSize(get_size_x(), 20));


	start_button->Bind(wxEVT_ENTER_WINDOW, [this] (wxMouseEvent& mouse_event) {
		

		if (wxFileExists("modify\\cursor.png")) {


			this->SetCursor(wxImage("modify\\cursor.png", wxBITMAP_TYPE_PNG));
			mouse_event.Skip();


		}

		
		else {


			this->SetCursor(wxCURSOR_HAND);
			mouse_event.Skip();


		}


		});


	start_button->Bind(wxEVT_LEAVE_WINDOW, [this] (wxMouseEvent& mouse_event) {
		
		
		this->SetCursor(wxNullCursor);
		mouse_event.Skip();
		
		
		});


	MainFrame::SetClientSize(MainFrame::get_size_x(), MainFrame::get_size_y() + 20);
	MainFrame::SetSizeHints(MainFrame::GetSize(), MainFrame::GetSize());


	CreateStatusBar();
	wxLogStatus("By Berendsen Martin");
	
	
}


void MainFrame::OnButtonClicked(wxCommandEvent& event)
{


	if (event.GetId() == FOURTH) {


		thirdFrame = new ThirdFrame("debug");


		if (thirdFrame->IsShown()) {


			thirdFrame->Destroy();


		}


		MainFrame::Destroy();


		mainFrame = new MainFrame("Сюрприз");
		mainFrame->SetClientSize(get_size_x(), get_size_y());
		mainFrame->Center();


		mainFrame->Show();


		CreateStatusBar();
		wxLogStatus("By Berendsen Martin");


	}


	if (event.GetId() == THIRD) {


		SecondFrame* secondFrame = new SecondFrame("Настройки");
		secondFrame->Show(true);


		update_frame = new wxButton(panel_of_frame, FOURTH, "Обновить окно", wxPoint(0, get_size_y() - 45), wxSize(get_size_x(), 20));


		event.Skip();
	}


	if (event.GetId() == FIRST) {


		thirdFrame = new ThirdFrame("Сюрприз");


		thirdFrame->Show(true);


		event.Skip();
	
	
	}


}


