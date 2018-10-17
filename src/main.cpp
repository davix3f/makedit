#include <iostream>
#include <gtkmm.h>
#include <gtksourceview/gtksource.h>
#include <string>
#include <vector>
#include "button_functions.h"
#include "makedit_namespaces.h"

int main(int argc, char *argv[])
{
	// Start the logger
	makedit_logger::init();

	// Init app
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.makedit.base");

	// Main Window pointer declaration
	Gtk::Window *window;

	// Define *buttonFunction type pointer
	typedef void (*buttonFunction)();

	// Import 'interface.glade'
	supportive::glade_builder->add_from_file("interface.glade");

	// Gets 'mainwindow' glade widget and
	// assigns it to *window pointer [Line 18]
	supportive::glade_builder->get_widget("mainwindow", window);
	// Sets *window as the main window
	supportive::set_mainwindow(window);


	// Declaring all buttons and stores them in an array
	Gtk::Button *openfile_button, *save_button, *saveas_button, *newfile_button, *make_button, *execmd_button;
	Gtk::Button* buttonPointers[]={openfile_button, save_button, saveas_button, newfile_button, make_button, execmd_button};

	std::vector<std::string> buttonNames={"openfile_button", "save_button", "saveas_button", "newfile_button", "make_button", "execmd_button"};
	buttonFunction buttonFunctions[]={openfile_click, save_click, saveas_click, newfile_click, make_click, execmd};

	for(uint x=0; x<buttonNames.size(); x++)
	{
		// Assigns each button from buttonPointers to its glade file instance
		supportive::glade_builder->get_widget(buttonNames[x], buttonPointers[x]);
		buttonPointers[x]->signal_clicked().connect(sigc::ptr_fun(buttonFunctions[x]));
		std::cout <<"Assigned \'" << buttonNames[x]  << "\' to " << &buttonFunctions[x] << std::endl;
	}

	// Declare main TextView
	Gtk::TextView *txtview;
	supportive::glade_builder->get_widget("textview", txtview);
	txtview->set_vexpand(true);

	// Assigns txtview to 'textview' glade file widget
	set_widgets();

	// Set window size
	window->set_default_size(900,800);

	// Run app
	return app->run(*window);

}
