#include "button_functions.h"

Gtk::Window *parent_main_window = nullptr;
Gtk::TextView *textview_ptr = nullptr;
Gtk::Entry *make_option_input = nullptr;
Gtk::HeaderBar *info_bar = nullptr;


void set_mainwindow(Gtk::Window *mainwindow)
{
    std::cout << "Main window set to: " << mainwindow << std::endl;
    parent_main_window = mainwindow;
    std::cout << "parent_main_window value is now: " << mainwindow << std::endl;
}

void set_widgets()
{
    supportive::glade_builder->get_widget("textview",textview_ptr);
    std::cout << "Textview set to: " << textview_ptr << std::endl;

	supportive::glade_builder->get_widget("info_headerbar", info_bar);
    std::cout << "Info bottom bar set to: " << info_bar << std::endl;
    
    supportive::glade_builder->get_widget("make_option_input", make_option_input);
    std::cout << "Make option entry set to: " << make_option_input << std::endl;
}



void openfile_click()
{
    openfile_action(parent_main_window, textview_ptr, info_bar);
}

void save_click()
{
    printf("File saved\n");
}

void saveas_click()
{
    printf("Saved as\n");
}

void newfile_click()
{
    printf("New file opened\n");
}

void make_click()
{
    printf("Make executed\n");
}

void execmd()
{
    printf("Executing bash command\n");
}
