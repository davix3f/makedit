#include <iostream>
#include <fstream>
#include <string>
#include <gtkmm.h>

namespace supportive
{	
	extern Gtk::Window *main_parent;
	void set_mainwindow(Gtk::Window *mainwindow);
	
	extern Glib::RefPtr<Gtk::Builder> glade_builder;

	extern Gtk::Dialog *alertdialog;
	int question_dialog(const char* message, const char* additional_message);
}


namespace makedit_fileops
{
	int file_write_permission_checker(const char* file_name);
}


namespace makedit_logger
{
	extern int write_to_file;
	
	void init();
	void init(bool filewrite);
	
	bool log(Gtk::Object *sender, const char* message);
	bool log(const char* message);
}
