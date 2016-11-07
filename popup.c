#include <gtk/gtk.h>

static void cb_button(GtkButton *button,
	gpointer user_data){
	GtkWidget *dialog;
	GtkWidget *parent;
	GtkWidget *label;
	gint response;

	parent=GTK_WIDGET(user_data);

	dialog=gtk_dialog_new_with_buttons("SaveÃConfermation",
		GTK_WINDOW(parent),
		GTK_DIALOG_MODAL|
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_STOCK_NO,GTK_RESPONSE_NO,
		GTK_STOCK_YES,GTK_RESPONSE_YES,
		NULL);
	label=gtk_label_new("Confirm Are yo Ãsur Ãyou wan Ãto save.");
	gtk_container_add(GTK_CONTAINER(GTK_DIALOG(dialog)->vbox),label);
	gtk_widget_show_all(dialog);

	response=gtk_dialog_run(GTK_DIALOG(dialog));
	if(response==GTK_RESPONSE_YES){
		g_print("YesÃbuttonÃwasÃpressed.\n");
	}else if(response==GTK_RESPONSE_NO){
		g_print("NoÃbuttonÃwasÃpressed.\n");
	}else{
		g_print("AnotherÃresponseÃwasÃrecieved.\n");
	}
	gtk_widget_destroy(dialog);
}

int main(int argc,
	char **argv){
	GtkWidget *window;
	GtkWidget *hbox;
	GtkWidget *label;
	GtkWidget *entry;
	GtkWidget *button;

	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"GtkDialogÃSample");
	gtk_container_set_border_width(GTK_CONTAINER(window),5);
	g_signal_connect(G_OBJECT(window),"destroy",
	G_CALLBACK(gtk_main_quit),NULL);

	hbox=gtk_hbox_new(FALSE,5);
	gtk_container_add(GTK_CONTAINER(window),hbox);

	button=gtk_button_new_from_stock(GTK_STOCK_SAVE);
	g_signal_connect(G_OBJECT(button),"clicked",
	G_CALLBACK(cb_button),(gpointer)window);
	gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);

	button=gtk_button_new_from_stock(GTK_STOCK_QUIT);
	g_signal_connect(G_OBJECT(button),"clicked",
	G_CALLBACK(gtk_main_quit),NULL);
	gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
