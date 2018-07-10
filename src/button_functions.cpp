#include "button_functions.h"
#include "openfile.h"

Glib::RefPtr<Gtk::Builder> main_builder;

Gtk::Window *parent_main_window = nullptr;
Gtk::TextView *textview_ptr = nullptr;
Gtk::Entry *make_option_input = nullptr;


void set_builder(Glib::RefPtr<Gtk::Builder> mainbuilder)
{
    main_builder = main_builder;
    std::cout << "Main builder set to: " << &main_builder << std::endl;
}

void set_mainwindow(Gtk::Window *mainwindow)
{
    std::cout << "Main window set to: " << mainwindow << std::endl;
    parent_main_window = mainwindow;
    std::cout << "parent_main_window value is now: " << mainwindow << std::endl;
}

void set_textview(Gtk::TextView *textview)
{
    textview_ptr = textview;
    std::cout << "Textview set to: " << textview_ptr << std::endl;
}

void openfile_click()
{
    openfile_action(parent_main_window, textview_ptr);
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
