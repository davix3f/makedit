#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>

namespace supportive
// Utils namespace
// implemented in makedit_supportive.cpp
{	
	// Main window mem address
	extern Gtk::Window *main_parent;
	void set_mainwindow(Gtk::Window *mainwindow);
	
	// glade_builder object
	extern Glib::RefPtr<Gtk::Builder> glade_builder;

	// Gtk::Dialog object
	extern Gtk::Dialog *alertdialog;
	// Standard Gtk::Dialog for simple questions use
	int question_dialog(const char* message, const char* additional_message);
}


namespace makedit_fileops
// Operations-onf-file namespace
// implemented in makedit_fileops.cpp
{
	int file_write_permission_checker(const char* file_name);
}


namespace makedit_logger
// Logger namespace
// implemented in makedit_logger.cpp
{
	extern int write_to_file;
	
	void init();
	void init(bool filewrite);
	
	bool log(Gtk::Object *sender, const char* message);
	bool log(const char* message);
}
