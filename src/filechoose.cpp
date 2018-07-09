#include "filechoose.h"

auto tempbuild = Gtk::Builder::create();

void filechoose_dialog(Gtk::Window *parent, Gtk::TextView *textview)
{
    std::cout << "Summoned Gtk::FileChooserDialog from parent main window " << parent << std::endl;
    tempbuild->add_from_file("interface.glade");
    printf("Opening file\n");
    Gtk::FileChooserDialog *filechoose;
    tempbuild->get_widget("filechooser", filechoose);
    filechoose->set_transient_for(*parent);
    filechoose->set_title("Select file");
    auto openbutton = filechoose->add_button("Open", Gtk::RESPONSE_OK);
    auto closebutton = filechoose->add_button("Close", Gtk::RESPONSE_CLOSE);
    int response = filechoose->run();
    switch(response)
    {
        case(Gtk::RESPONSE_OK):
        {
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
                parent->set_title("makedit ~ " + filechoose->get_filename());
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
