#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *textview;
GtkWidget *textview2;

static guint timer_id ;


static void cb_button(){
    GtkWidget *dialog;
    GtkWidget *parent;
    GtkWidget *label;
    GtkWidget *entry;
    gint response;

    parent=window;

    dialog=gtk_dialog_new_with_buttons("Search Box",
        GTK_WINDOW(parent),
        GTK_DIALOG_MODAL|
        GTK_DIALOG_DESTROY_WITH_PARENT,
        GTK_STOCK_NO,GTK_RESPONSE_NO,
        GTK_STOCK_YES,GTK_RESPONSE_YES,
        NULL);
    label=gtk_label_new("search");
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox),label);

    entry =gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox),entry);



    gtk_widget_show_all(dialog);

    response=gtk_dialog_run(GTK_DIALOG(dialog));
    if(response==GTK_RESPONSE_YES){
        g_print("Yes.\n");
    }else if(response==GTK_RESPONSE_NO){
        g_print("No.\n");
    }else{
        g_print("Another.\n");
    }
    gtk_widget_destroy(dialog);
}






static void callback (GtkWidget *widget, GdkEventKey* pKey, gpointer data)
{
    const gchar *c;
    GtkTextBuffer *buffer;
    int ret;

    g_print ("%s\n", "callback");

    if (pKey->type == GDK_KEY_PRESS){
g_print ("key_press:keyval=%02X", pKey->keyval);

        //sprintf(buff,"%d:%d:%d",pnow->tm_hour,pnow->tm_min,pnow->tm_sec);

g_printerr("%s\n",
               gdk_keyval_name (pKey->keyval));

        g_print("%i\n", pKey->keyval);


ret = strcmp(gdk_keyval_name (pKey->keyval),"Return");
        g_print("ret = %d\n", ret);


if (pKey->state & GDK_CONTROL_MASK){
        g_print (" Ctrl");
cb_button();

}

/*
if(ret == 0){

    g_print("%s\n", "0desu");

    GtkTextBuffer *buffer;
    buffer=gtk_text_view_get_buffer(textview);

    if (strcmp(buffer,"color") == 0){

    }

}
*/



/*
        switch (pKey->keyval)
    	{
    		case GDK_Enter :
    			gtk_main_quit ();
    		break;
    	}
*/

    }

}



static void set_text(GtkTextView *textview, const gchar *text){
    GtkTextBuffer *buffer;
    gchar *utf8_text;

    utf8_text=g_locale_to_utf8(text,-1,NULL,NULL,NULL);
    buffer=gtk_text_view_get_buffer(textview);
    gtk_text_buffer_set_text(buffer,(utf8_text) ? utf8_text : text,-1);
    if(utf8_text) g_free(utf8_text);
}

static void set_text2(GtkWidget *widget,gpointer data){
    GtkTextBuffer *buffer;
    gchar *utf8_text;
    gchar *text = "text";
GtkTextIter iter;


    g_print("%s\n","set_text2");

    utf8_text=g_locale_to_utf8(text,-1,NULL,NULL,NULL);
    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
gtk_text_buffer_insert(buffer, &iter, "Plain text\n", -1);
//    gtk_text_buffer_set_text(buffer,(utf8_text) ? utf8_text : text,-1);
    if(utf8_text) g_free(utf8_text);
}

static void set_text4(gpointer data){
    GtkTextBuffer *buffer;
    gchar *utf8_text;
    gchar *text = "text2";

    time_t now = time(NULL);
    struct tm *pnow = localtime(&now);

/*
    char buff[128]="";
    sprintf(buff,"%d:%d:%d",pnow->tm_hour,pnow->tm_min,pnow->tm_sec);
*/

    g_print("%s\n","set_text3");

/*
    utf8_text=g_locale_to_utf8(buff,-1,NULL,NULL,NULL);
    buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    gtk_text_buffer_set_text(buffer,(utf8_text) ? utf8_text : text,-1);
    if(utf8_text) g_free(utf8_text);
*/
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
    GtkWidget *vbox,*hbox,*hbox2;
    GtkWidget *scrolledwindow;
    GtkWidget *button;

    gtk_init(&argc,&argv);
    window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"GtkTextViewÃSample");
    gtk_widget_set_size_request(window,300,200);
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


    scrolledwindow=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(scrolledwindow),
    		GTK_SHADOW_ETCHED_OUT);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledwindow),
    		GTK_POLICY_AUTOMATIC,
    		GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(vbox),scrolledwindow,TRUE,TRUE,0);

    textview2=gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolledwindow),textview2);
    set_text(GTK_TEXT_VIEW(textview2),
    "このプログラムはGtkTextViewウィジェットのサンプル\n"
    "プログラムです。");

g_signal_connect(G_OBJECT(textview2), "key_press_event",
             G_CALLBACK(callback), NULL);

/*
    hbox=gtk_hbox_new(FALSE,5);

    textview2=gtk_text_view_new();
    set_text(GTK_TEXT_VIEW(textview2),
    "このプログラムはGtkTextViewウィジェットのサンプル\n"
    "プログラムです。");

    gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,0);
    gtk_box_pack_end(GTK_BOX(hbox),textview2,FALSE,FALSE,0);

*/


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


    button=gtk_button_new_with_label("TEST");
/*
    g_signal_connect(G_OBJECT(button),"clicked",
    		G_CALLBACK(
    set_text(GTK_TEXT_VIEW(textview),
    "プログラムです。")),(gpointer)textview);
*/
    g_signal_connect(G_OBJECT(button),"clicked",
    		G_CALLBACK(set_text2),NULL);

    gtk_box_pack_end(GTK_BOX(hbox),button,FALSE,FALSE,0);

    //timer_id = g_timeout_add(1000,(GSourceFunc)set_text3,NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
