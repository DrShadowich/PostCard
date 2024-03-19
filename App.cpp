#include "MainFrame.h"
#include "SecondFrame.h"
#include "App.h"


wxIMPLEMENT_APP(App);


bool App::OnInit() {


	MainFrame* mainFrame = new MainFrame("Ñþðïðèç");


	mainFrame->SetClientSize(mainFrame->get_size_x(), mainFrame->get_size_y());
	mainFrame->Center();
	

	mainFrame->Show(true);


	return true;


}