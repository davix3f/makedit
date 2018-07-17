#include "openfile.h"

auto tempbuild = Gtk::Builder::create();

void openfile_action(Gtk::Window *parent, Gtk::TextView *textview, Gtk::HeaderBar *bottom_bar)
{
	Gtk::Label *file_openmode_label;

	supportive::glade_builder->get_widget("file_openmode", file_openmode_label);
	tempbuild->add_from_file("interface.glade");
	Gtk::FileChooserDialog *filechoose;
	tempbuild->get_widget("openfile_dialog", filechoose);
	std::cout << "Summoned Gtk::FileChooserDialog (parent main window: " << parent << ")" << std::endl;
	filechoose->set_transient_for(*parent);
	filechoose->set_title("Select file");
	auto openbutton = filechoose->add_button("Open", Gtk::RESPONSE_OK);
	auto closebutton = filechoose->add_button("Close", Gtk::RESPONSE_CLOSE);
	int response = filechoose->run();
	switch(response)
	{
		case(Gtk::RESPONSE_OK):
		{
			if(makedit_fileops::file_write_permission_checker(filechoose->get_filename().c_str()))
			{ file_openmode_label->set_text("READ-WRITE"); }
			else { file_openmode_label->set_text("READ ONLY"); }
			
			std::cout << &filechoose << " -- File selected: " << filechoose->get_filename() << std::endl;
			std::string file_content, line;
			std::ifstream selected_file;
			selected_file.open(filechoose->get_filename());

			if(selected_file.is_open())
			{
				while(std::getline(selected_file, line))
				{
					file_content+=line+"\n";
				}
				textview->get_buffer()->set_text(file_content);
				bottom_bar->set_title("File: " + filechoose->get_filename());
			}
			else { std::cout << "Error occured while opening file" << std::endl; }
			filechoose->close();
			break;
		}
		case(Gtk::RESPONSE_CLOSE):
		{
			std::cout << &filechoose << " -- No file selected" << std::endl;
			filechoose->close();
			break;
		}
	}
}
