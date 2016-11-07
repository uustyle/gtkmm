#include <gtk/gtk.h>

int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *hpaned;
    GtkWidget *button;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    vpaned = gtk_vpaned_new ();
    gtk_container_add (GTK_CONTAINER (window), vpaned);
    gtk_widget_show (vpaned);

    hpaned = gtk_hpaned_new ();
    gtk_paned_add1 (GTK_PANED (vpaned), hpaned);
    gtk_widget_show (hpaned);

    button = gtk_button_new_with_label ("Hello World");
    gtk_paned_add1 (GTK_PANED (hpaned), button);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("Hello World2");
    gtk_paned_add2 (GTK_PANED (hpaned), button);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("Hello World2");
    gtk_paned_add2 (GTK_PANED (vpaned), button);
    gtk_widget_show (button);



    gtk_widget_show (window);
    
    gtk_main ();
    
    return 0;
}
