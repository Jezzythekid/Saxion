#ifndef OPDR_3_RECTANGLES_H
#define OPDR_3_RECTANGLES_H


enum{
    C_HEIGHT = 15, /// Height of the canvas
    C_WIDTH = 50 /// Width of the canvas
};

typedef enum { /// The different types of characters that can be printed.
    HORIZONTAL_EDGE = '-', /// A horizontal edge.
    VERTICAL_EDGE = '|', /// A vertical edge.
    CORNER_POINT = '+', /// A corner point.
    INTERSECTION_POINT = '+', /// An intersection point.
    INTERIOR_POINT = ' ',/// An interior point.
    CANVAS_POINT = '.'/// A regular point.
} character_type_t;

/// Represents a point in 2D space.
typedef struct {
    int x; /// The x-coordinate of the point.
    int y; /// The y-coordinate of the point.
} point_t;

/// Represents a rectangle in 2D space.
typedef struct {
    point_t lower_left; /// The lower-left corner of the rectangle.
    int width; /// The width of the rectangle.
    int height; /// The height of the rectangle.
} rect_t;


/// Function that fills a 2d character_type_t array
/// @param canvas array to fill
/// @param character character to fill the array with
void fill_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], character_type_t character);

/// Function that asks the user for an coordinate.
/// @param prompt the prompt to ask the user, make sure the user enters the coords like "(x, y)".
/// @param output the array[2] to output the coordinates ([0]: x, [1]: y).
point_t read_coord(const char * prompt);

/// Function that asks the user for an origin, width and height of a rectangle
///     and checks if the rectangle is in bounds.
/// @param rectangle pointer to to the struct to write to
/// @param width_c the width of the canvas in witch the rectangle must fit
/// @param height_c the height of the canvas in witch the rectangle must fit
rect_t read_rectangle(int width_c, int height_c);


/// Function that adds a rect in a canvas array
/// @param canvas the canvas to add the rect in
/// @param rect the rect to add
void add_rectangle_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], rect_t rect);

/// Function prints the canvas to a set width and height
/// @param canvas array to print
/// @param lineNumbers true = show line and row numbers
void print_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], bool showLineNumbers);

#endif //OPDR_3_RECTANGLES_H
