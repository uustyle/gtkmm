#include <gtk/gtk.h>
#define BUFSIZE 256

static void set_text(GtkWidget *textView, const gchar *text){

    GtkTextBuffer *textBuffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
    gtk_text_buffer_set_text(textBuffer, text, -1);

}



/* Create the list of "messages" */
static GtkWidget *create_list( void )
{

    GtkWidget *scrolled_window;
    GtkWidget *textView;
   
    /* Create a new scrolled window, with scrollbars only if needed */
    textView= gtk_text_view_new();
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
				    GTK_POLICY_AUTOMATIC, 
				    GTK_POLICY_AUTOMATIC);

    set_text(textView,"aaaa");

    gtk_container_add (GTK_CONTAINER (scrolled_window), textView);

    return scrolled_window;
}




int main( int   argc,
          char *argv[] )
{
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *hpaned;
    GtkWidget *button;
    GtkWidget *list;
    
    gtk_init (&argc, &argv);
    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Paned Windows");
    g_signal_connect (window, "destroy",
	              G_CALLBACK (gtk_main_quit), NULL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_widget_set_size_request (GTK_WIDGET (window), 450, 400);


    vpaned = gtk_vpaned_new ();
    gtk_container_add (GTK_CONTAINER (window), vpaned);
    gtk_widget_show (vpaned);

    hpaned = gtk_hpaned_new ();
    gtk_paned_add1 (GTK_PANED (vpaned), hpaned);
    gtk_widget_show (hpaned);

    list = create_list ();
    gtk_paned_add1 (GTK_PANED (hpaned), list);
    gtk_widget_show (list);

    button = gtk_button_new_with_label ("Hello World2");
    gtk_paned_add2 (GTK_PANED (hpaned), button);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("Hello World2");
    gtk_paned_add2 (GTK_PANED (vpaned), button);
    gtk_widget_show (button);



    gtk_widget_show (window);
gtk_widget_show_all(window);
    
    gtk_main ();
    
    return 0;
}
