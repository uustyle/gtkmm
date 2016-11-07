#include <gtkmm.h>

class HelloWorld : public Gtk::Window
{
    Gtk::Label m_label;

public:
    HelloWorld();
    virtual ~HelloWorld(){}
};

HelloWorld::HelloWorld()
{
    m_label.set_text( "Hello World" );
    add( m_label );
    show_all_children();
    resize( 100, 100 );
}

int main( int argc, char *argv[] )
{
    Gtk::Main kit( argc, argv );
    HelloWorld hw;
    Gtk::Main::run( hw );

    return 0;
}

