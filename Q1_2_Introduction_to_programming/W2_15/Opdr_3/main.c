#include "functions.h"
#include "rectangles.h"

// Week 15, Opdr. 3
// Write a program that asks the user to input three rectangles, and then prints these rectangles
// to the console, in a 2D coordinate system. The coordinate system has its origin (0, 0) in the top left
// corner, and the x-axis points to the right, and the y-axis points down. The width and height
// of the coordinate system are 50 wide by 15 high

int main() {

    // define variables
    character_type_t canvas[C_HEIGHT][C_WIDTH];
    rect_t rectangles[3];

    // fill the canvas with regular points
    fill_canvas(canvas, CANVAS_POINT);

    // ask the user 3 to enter 3 rectangles
    rectangles[0] = read_rectangle(C_WIDTH, C_HEIGHT);
    rectangles[1] = read_rectangle(C_WIDTH, C_HEIGHT);
    rectangles[2] = read_rectangle(C_WIDTH, C_HEIGHT);

    // add the rectangles to the canvas array
    add_rectangle_canvas(canvas, rectangles[0]);
    add_rectangle_canvas(canvas, rectangles[1]);
    add_rectangle_canvas(canvas, rectangles[2]);

    // print the canvas array
    print_canvas(canvas, true);

    // pause the terminal
    read_string("\n\nPress enter to exit...");

    return 0;
}
