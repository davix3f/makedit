#include "makedit_namespace.h"

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


namespace makedit_logger
{
	int write_to_file = 0;
	
	void init()
	{
		std::cout << "No argument provided. Setting write_to_file (" << &write_to_file << ") to FALSE" << std::endl;
		write_to_file = 1;
	}
	
	void init(bool filewrite)
	{
		if (filewrite==true)
		{
			write_to_file = 2;
			std::cout << "Setting write_to_file (" << &write_to_file << ") to TRUE" << std::endl;
		}
		else
		{
			write_to_file = 1;
			std::cout << "Setting write_to_file (" << &write_to_file << ") to FALSE" << std::endl;
		}
	}

	bool log(Gtk::Object *sender, const char* message)
	{
		if (write_to_file==0)
		{
			std::cout << "Log value write_to_file (" << &write_to_file << ") is NULL. Log operations can't be performed" << std::endl;
			return false;
		}
		std::cout << message << " [Sender: " << sender << "]" << std::endl;
		return true;
	}
	
	bool log(const char* message)
	{
		if (write_to_file==0)
		{
			std::cout << "Log value write_to_file (" << &write_to_file << ") is NULL. Log operations can't be performed" << std::endl;
			return false;
		}
		std::cout << message << std::endl;
		return true;
	}
}
