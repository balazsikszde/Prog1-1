/*
    g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }

int main()
{
	constexpr int xmax = 600;
    constexpr int ymax = 600;

    constexpr int origo_x = xmax/2;
    constexpr int origo_y = ymax/2;

    Point origo(xmax/2, ymax/2);

	Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

	Axis x_axis(Axis::x, Point(100, origo_y), 400, 20, "1 == 20 pixels");
	Axis y_axis(Axis::y, Point(origo_x, 500), 400, 20, "1 == 20 pixels");

	x_axis.set_color(Color::red);
	y_axis.set_color(Color::red);

	win.attach(y_axis);
	win.attach(x_axis);

	Function f_one (one, origo,)

	win.wait_for_button();
}