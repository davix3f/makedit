#include <iostream>
#include <gtkmm.h>

void set_mainwindow(Gtk::Window *mainwindow);
void set_textview(Gtk::TextView *textview);
void set_builder(Glib::RefPtr<Gtk::Builder> mainbuilder);

void openfile_click();
void save_click();
void saveas_click();
void newfile_click();
void make_click();
void execmd();
