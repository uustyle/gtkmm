#include <gtk/gtk.h>
#define BUFSIZE 256

static void destroy(GtkWidget *widget, gpointer data)
{
  gtk_main_quit();
}

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *scrolledWindow;
  GtkWidget *textView;
  
  gtk_init(&argc, &argv);
  
  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  textView= gtk_text_view_new();
  scrolledWindow= gtk_scrolled_window_new (NULL, NULL);

  {
    char buffer[BUFSIZE];
    size_t length;
    FILE *in= fopen("test.txt", "r");
    GtkTextBuffer *textBuffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
    
	while ((length= fread (buffer, 1, BUFSIZE, in)) > 0) {
      gtk_text_buffer_insert_at_cursor(textBuffer, buffer, length);
    }
    fclose(in);
  }

  gtk_container_add (GTK_CONTAINER(scrolledWindow), textView);
  gtk_container_add (GTK_CONTAINER(window), scrolledWindow);
  gtk_widget_show_all(window);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  gtk_main();

  return 0;
}
