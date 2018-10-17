#include "openfile.h"

// Temporary builder.
// Automatically destroyed after function end
auto tempbuild = Gtk::Builder::create();

void openfile_action(Gtk::Window *parent, Gtk::TextView *textview, Gtk::HeaderBar *bottom_bar)
{
	Gtk::Label *file_openmode_label;
	supportive::glade_builder->get_widget("file_openmode", file_openmode_label);
	// = RW if the user has rw permission
	// = READ-ONLY if the user has read-only access

	tempbuild->add_from_file("interface.glade");

	Gtk::FileChooserDialog *filechoose;
	tempbuild->get_widget("openfile_dialog", filechoose);
	// Assign FileChooserDialog from glade file

	std::cout << "Summoned Gtk::FileChooserDialog (parent main window: " << parent << ")" << std::endl;

	filechoose->set_transient_for(*parent);
	// ^ Assign main window as Dialog parent
	filechoose->set_title("Select file"); // set title

	auto openbutton = filechoose->add_button("Open", Gtk::RESPONSE_OK);
	auto closebutton = filechoose->add_button("Close", Gtk::RESPONSE_CLOSE);
	// Add buttons 'Open' and 'Close', with OK and CLOSE responses

	int response = filechoose->run(); // Run FileChooserDialog
	switch(response)
	// Response elaboration
	{
		case(Gtk::RESPONSE_OK): // A file is selected and confirmed
		{
			if(makedit_fileops::file_write_permission_checker(filechoose->get_filename().c_str()))
			{ file_openmode_label->set_markup("<b>READ-WRITE</b>"); }
			// If file_write_permission_checker returns true
			// file_openmode_label is set to "READ-WRITE"
			// If not, it's set to "READ ONLY"
			else { file_openmode_label->set_markup("<b>READ ONLY</b>"); }

			std::cout << &filechoose << " -- File selected: " << filechoose->get_filename() << std::endl;

			std::string file_content, line;
			std::ifstream selected_file;
			selected_file.open(filechoose->get_filename());

			if(selected_file.is_open())
			{
				while(std::getline(selected_file, line))
				{
					// Every line from selected file
					// is copied to file_content string
					file_content+=line+"\n";
				}
				textview->get_buffer()->set_text(file_content);
				// TextView widget is populated with file_content
				bottom_bar->set_title("File: " + filechoose->get_filename());
			}
			else { std::cout << "Error occured while opening file" << std::endl; }
			filechoose->close(); // Close FileChooserDialog
			break;
		}
		case(Gtk::RESPONSE_CLOSE): // 'Close' button is pressed
		{
			std::cout << &filechoose << " -- No file selected" << std::endl;
			filechoose->close();
			break;
		}
	}
}
