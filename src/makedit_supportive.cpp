#include "makedit_namespaces.h"

namespace supportive
{
	Gtk::Window *main_parent = NULL;
	void set_mainwindow(Gtk::Window *mainwindow)
	{
		main_parent = mainwindow;
		printf("Main window set to: %p\n", main_parent);
	}

	Glib::RefPtr<Gtk::Builder> glade_builder = Gtk::Builder::create();
	
	int question_dialog(const char* message, const char* additional_message)
	{
		Gtk::MessageDialog dialog(*main_parent, message, false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL, false);

		dialog.set_title("Alert");
		dialog.set_secondary_text(additional_message);

        std::cout << "Summoned Gtk::MessageDialog [question_dialog] " << &dialog << " (parent: " << main_parent << ")" << std::endl;

		int dialog_response = dialog.run();
		switch(dialog_response)
		{
			case(Gtk::RESPONSE_OK):
			{
				printf("OK\n");
				dialog.close();
				return(Gtk::RESPONSE_OK); break;
			}
			case(Gtk::RESPONSE_CANCEL):
			{
				printf("CANCEL\n");
				dialog.close();
				return(Gtk::RESPONSE_CANCEL); break;
			}
		}
	} // question_dialog

} //namespace supportive
