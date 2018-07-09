#include <iostream>
#include <gtkmm.h>
#include <string>
#include <vector>
#include "button_functions.h"

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.makedit.base");

    Gtk::Window *window;

    typedef void (*buttonFunction)();

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    builder->add_from_file("interface.glade");
    set_builder(builder);
    builder->get_widget("mainwindow", window);

    set_mainwindow(window);

    Gtk::Button *openfile_button, *save_button, *saveas_button, *newfile_button, *make_button, *execmd_button;
    Gtk::Button* buttonPointers[]={openfile_button, save_button, saveas_button, newfile_button, make_button, execmd_button};
    std::vector<std::string> buttonNames={"openfile_button", "save_button", "saveas_button", "newfile_button", "make_button", "execmd_button"};
    buttonFunction buttonFunctions[]={openfile_click, save_click, saveas_click, newfile_click, make_click, execmd};

    for(uint x=0; x<buttonNames.size(); x++)
    {
        builder->get_widget(buttonNames[x], buttonPointers[x]);
        buttonPointers[x]->signal_clicked().connect(sigc::ptr_fun(buttonFunctions[x]));
        std::cout << x <<" Assigned \'" << buttonNames[x]  << "\' to function " << &buttonFunctions[x] << std::endl;
    }

    Gtk::TextView *txtview;
    builder->get_widget("textview", txtview);
    set_textview(txtview);
    txtview->set_vexpand(true);

    window->set_default_size(900,800);

    return app->run(*window);

}
