#include "stdio.h"
#include "stdbool.h"
#include "functions.h"
#include "rectangles.h"

void fill_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], character_type_t character) {

    // iterate through each line and row, setting each point the correct character
    for (int x = 0; x < C_HEIGHT; x++) {
        for (int y = 0; y < C_WIDTH; y++) {
            canvas[x][y] = character;
        }
    }
}

point_t read_coord(const char * prompt) {

    const char * buff;
    point_t coord;

    buff = read_string(prompt);

    // check if user entered the input in the (x, y) format, if not, ask the user again.
    while (sscanf(buff, "(%d, %d)", &coord.x, &coord.y) != 2) {

        printf("Invalid coordinate, please use the format '(x, y)'\n");
        buff = read_string(prompt);
    }

    return coord;
}

rect_t read_rectangle(int width_c, int height_c) {

    point_t coord;
    int width;
    int height;

    coord = read_coord("Please enter the lower left coordinate of a rectangle in the form '(x, y)': ");

    // check if coordinates are in bounds (if the value is not less than 0 and out of the canvas size - 1)
    //  the offset at height-/width_c is necessary otherwise a rectangle can not be made (height/width would be zero)
    while (coord.x <= 0 || coord.x > (width_c - 1) || coord.y <= 0 || coord.y > (height_c - 1)) {

        if (coord.x <= 0 || coord.x > width_c) printf("Invalid 'x' coordinate, please keep x between 1 - %d", width_c - 1);
        else printf("Invalid 'y' coordinate, please keep y between 0 - %d", height_c - 1);

        coord = read_coord("\nPlease enter the lower left coordinate of a rectangle in the form '(x, y)': ");

    }

    // calculate the maximum width the rectangle can have
    int max_height = coord.y;
    int max_width = width_c - coord.x;

    width = read_int("Please enter the width of the rectangle: ");

    // check if width is in bounds, if not ask again
    while (width > max_width || width <= 0) {

        if (width > max_width) printf("That's to wide. the maximum width is %d", max_width);
        else printf("The width can not be 0 or negative");

        width = read_int("\nPlease enter the width of the rectangle: ");

    }

    height = read_int("Please enter the height of the rectangle: ");

    // check if height is in bounds, if not ask again
    while (height > max_height || height <= 0) {

        if (height > max_height) printf("That's to high. the maximum height is %d", max_height);
        else printf("The height can not be 0 or negative");

        height = read_int("\nPlease enter the height of the rectangle: ");

    }

    // return value
    rect_t temp = {coord, width, height};
    return temp;

}

void add_rectangle_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], rect_t rect) {

    // calculate four corner points
    point_t lowLeft = {rect.lower_left.x, rect.lower_left.y};
    point_t lowRight = {rect.lower_left.x + rect.width, rect.lower_left.y};
    point_t topLeft = {rect.lower_left.x, rect.lower_left.y - rect.height};
    point_t topRight = {rect.lower_left.x + rect.width, rect.lower_left.y - rect.height};

    // iterate through each line and row, setting the correct value based on the previous data
    for (int y = 0; y < C_HEIGHT; y++) {

        for (int x = 0; x < C_WIDTH; x++) {

            // corner rectangle
            if (topLeft.x == x && topLeft.y == y) canvas[y][x] = CORNER_POINT;
            if (topRight.x == x && topRight.y == y) canvas[y][x] = CORNER_POINT;
            if (lowLeft.x == x && lowLeft.y == y) canvas[y][x] = CORNER_POINT;
            if (lowRight.x == x && lowRight.y == y) canvas[y][x] = CORNER_POINT;

            // horizontal (if the point is not a canvas-/interior_point, then the lines must intersect)
            if ((x > topLeft.x && x < topRight.x) && (y == topLeft.y || y == lowLeft.y)) {
                if (canvas[y][x] == CANVAS_POINT || canvas[y][x] == INTERIOR_POINT) canvas[y][x] = HORIZONTAL_EDGE;
                else canvas[y][x] = INTERSECTION_POINT;
            }

            // vertical (if the point is not a canvas-/interior_point, then the lines must intersect)
            if ((y > topLeft.y && y < lowLeft.y) && (x == topLeft.x || x == topRight.x)){
                if (canvas[y][x] == CANVAS_POINT || canvas[y][x] == INTERIOR_POINT) canvas[y][x] = VERTICAL_EDGE;
                else canvas[y][x] = INTERSECTION_POINT;
            }

            // inside
            if (x > topLeft.x && x < topRight.x && y > topLeft.y && y < lowLeft.y && canvas[y][x] == CANVAS_POINT) {
                canvas[y][x] = INTERIOR_POINT;
            }

        }
    }

}

void print_canvas(character_type_t canvas[C_HEIGHT][C_WIDTH], bool showLineNumbers) {

    // iterate through each line and row, printing the correct character and putting an '\n' at the end of each row.
    for (int y = 0; y < C_HEIGHT; y++) {
        if (showLineNumbers) printf("%2d: ", y);
        for (int x = 0; x < C_WIDTH; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }

}
