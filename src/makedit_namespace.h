#include <iostream>
#include <gtkmm.h>

namespace supportive
{	
	extern Gtk::Window *main_parent;
	void set_mainwindow(Gtk::Window *mainwindow);
	
	extern Glib::RefPtr<Gtk::Builder> glade_builder;

	extern Gtk::Dialog *alertdialog;
	int question_dialog(const char* message, const char* additional_message);
}
