/*
 * edit from 《Linux C/C++視窗程式設計－使用GTK+與Qt》
 * 
 * makefile as follow : 
 * ### makefile###
 * P=gtkDemo
 * CFLAGS= -g -ggdb -Wall -O3
 * GTKFLAGS=-export-dynamic `pkg-config --cflags --libs gtk+-3.0`
 * $(P): $(OBJECTS)
 * ###end of makefile###
 */

#include <gtk/gtk.h>
static void activate(GtkApplication *app,
    gpointer user_data) {
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK");
    gtk_widget_show_all(window);
}
int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    app = gtk_application_new("org.gtk.example",
        G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate",
        G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return (status);
}
