#include <gtk/gtk.h>

static void create_window_settings(GtkButton *button, gpointer data){
    GtkWidget *window;
    GError *error = NULL;
    GtkBuilder *builder;

    builder = gtk_builder_new();
    if(!gtk_builder_add_from_file(builder, "SettingsGUI.ui", &error)){
        g_critical("Невозможно загрузить файл: %s", error->message);
        g_error_free(error);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "settingsWindow"));

    if(!window){
        g_critical("Не могу получить объект окна!");
    }

    g_object_unref(builder);

    gtk_widget_show(window);
}