/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"


struct Lines_window : Window {

	Lines_window(Point xy,int w, int h, const string& title);

private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	Menu color_menu;
	Menu style_menu;
	Button style_button;
	Button menu_button;

	void next();
	void quit();

	void red_pressed() { changec(Color::red); hide_menu(); }
	void blue_pressed() { changec(Color::blue); hide_menu();}
	void black_pressed() { changec(Color::black); hide_menu();}

	void solid_pressed() { changes(Line_style::solid); hide_smenu();}
	void dash_pressed() { changes(Line_style::dash); hide_smenu();}
	void dot_pressed() { changes(Line_style::dot); hide_smenu();}

	void menu_pressed() { menu_button.hide(); color_menu.show();}
	void hide_menu() { color_menu.hide(); menu_button.show();}
	void hide_smenu() { style_menu.hide(); style_button.show(); }

	void style_pressed() { style_button.hide(); style_menu.show(); }

	void changec(Color c) { lines.set_color(c); }
	void changes(Line_style s) { lines.set_style(s); }

	static void cb_next(Address,Address);
	static void cb_quit(Address,Address);

	static void cb_menu(Address,Address);
	static void cb_smenu(Address,Address);

	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);

	static void cb_solid(Address,Address);
	static void cb_dash(Address,Address);
	static void cb_dot(Address,Address);

};

Lines_window::Lines_window(Point xy,int w, int h, const string& title)
	:Window(xy,w,h,title),

	color_menu(Point(x_max()-70,40),70,20,Menu::vertical,"color"),
	menu_button(Point(x_max()-80,30),80,20,"color menu", cb_menu),
	style_menu(Point(x_max()-70,110),70,20,Menu::vertical,"style"),
	style_button(Point(x_max()-80,120),80,20,"style menu", cb_smenu),

	next_button(Point(x_max()-150,0),70,20,"Next point",cb_next),
	quit_button(Point(x_max()-70,0),70,20,"Quit",cb_quit),
	
	next_x(Point(x_max()-310,0),50,20,"next x:"),
	next_y(Point(x_max()-210,0),50,20,"next y:"),
	xy_out(Point(100,0),100,20,"current (x,y):")
	{
		attach(next_button);
		attach(quit_button);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		xy_out.put("no point");
		color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
		color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
		color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
		style_menu.attach(new Button(Point(0,0),0,0,"solid",cb_solid));
		style_menu.attach(new Button(Point(0,0),0,0,"dash",cb_dash));
		style_menu.attach(new Button(Point(0,0),0,0,"dot",cb_dot));
		attach(color_menu);
		attach(style_menu);
		color_menu.hide();
		style_menu.hide();
		attach(menu_button);
		attach(style_button);
		attach(lines);
	};

void Lines_window::cb_quit(Address,Address pw)
{
	reference_to<Lines_window>(pw).quit();
}
void Lines_window::quit()
{
	hide();
}

void Lines_window::cb_next(Address,Address pw)
{
	reference_to<Lines_window>(pw).next();
}
void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point(x,y));

	stringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Lines_window::cb_black(Address,Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}
void Lines_window::cb_blue(Address,Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_red(Address,Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_solid(Address,Address pw)
{
	reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dash(Address,Address pw)
{
	reference_to<Lines_window>(pw).dash_pressed();
}
void Lines_window::cb_dot(Address,Address pw)
{
	reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_menu(Address,Address pw)
{
	reference_to<Lines_window>(pw).menu_pressed();
}
void Lines_window::cb_smenu(Address,Address pw)
{
	reference_to<Lines_window>(pw).style_pressed();
}

int main()
try {
	Lines_window win(Point(100,100),600,400,"lines");
	return gui_main();
}
catch(exception& e){
	cerr << "exception:" << e.what() << endl; 
	return 1;
}
catch(...){
	cerr << "Some exception:\n"; 
	return 2;
}
