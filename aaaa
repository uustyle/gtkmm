#include <gtk/gtk.h>

static void set_text(GtkTextView *textview, const gchar *text){
    GtkTextBuffer *buffer;
    gchar *utf8_text;

    utf8_text=g_locale_to_utf8(text,-1,NULL,NULL,NULL);
    buffer=gtk_text_view_get_buffer(textview);
    gtk_text_buffer_set_text(buffer,(utf8_text) ? utf8_text : text,-1);
    if(utf8_text) g_free(utf8_text);
}

static void print_text(GtkWidget *widget,gpointer data){
    GtkTextBuffer *buffer;
    GtkTextIter start,end;
    gchar *utf8_text;

    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(data));
    gtk_text_buffer_get_start_iter(buffer,&start);
    gtk_text_buffer_get_end_iter(buffer,&end);
    utf8_text=gtk_text_buffer_get_text(buffer,&start,&end,TRUE);
    g_print("%s\n",utf8_text);
    g_free(utf8_text);
}

int main(int argc,char **argv){
    GtkWidget *window;
    GtkWidget *vbox,*hbox;
    GtkWidget *scrolledwindow;
    GtkWidget *textview;
    GtkWidget *button;

    gtk_init(&argc,&argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"GtkTextViewÃSample");
    gtk_widget_set_size_request(window,300,100);
    gtk_container_set_border_width(GTK_CONTAINER(window),5);
    g_signal_connect(G_OBJECT(window),"destroy",
    		G_CALLBACK(gtk_main_quit),NULL);

    vbox=gtk_vbox_new(FALSE,5);
    gtk_container_add(GTK_CONTAINER(window),vbox);

    scrolledwindow=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow),
    		GTK_SHADOW_ETCHED_OUT);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow),
    		GTK_POLICY_AUTOMATIC,
    		GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox),scrolledwindow,TRUE,TRUE,0);

    textview=gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolledwindow),textview);
    set_text(GTK_TEXT_VIEW(textview),
    "このプログラムはGtkTextViewウィジェットのサンプル\n"
    "プログラムです。");

    hbox=gtk_hbox_new(FALSE,5);
    gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,0);

    button=gtk_button_new_from_stock(GTK_STOCK_QUIT);
    g_signal_connect(G_OBJECT(button),"clicked",
    		G_CALLBACK(gtk_main_quit),NULL);
    gtk_box_pack_end(GTK_BOX(hbox),button,FALSE,FALSE,0);

    button=gtk_button_new_from_stock(GTK_STOCK_APPLY);
    g_signal_connect(G_OBJECT(button),"clicked",
    		G_CALLBACK(print_text),(gpointer)textview);
    gtk_box_pack_end(GTK_BOX(hbox),button,FALSE,FALSE,0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
