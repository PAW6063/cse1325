#include "mainwin.h"



int main(int argc, char** argv) {
	
	auto app = Gtk::Application::create( argc, argv, "ENTER THE NAME HERE"); //FINISH THIS!!!
	Mainwin win;
	
	return app->run(win);
}
