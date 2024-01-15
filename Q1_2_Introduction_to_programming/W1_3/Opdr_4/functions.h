#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef const char * string;

/// Reads an integer from the user.
/// @param prompt The prompt to display to the user.
/// @return The integer entered by the user.
int read_int(string prompt);

/// Reads a float from the user.
/// @param prompt The prompt to display to the user.
/// @return The float entered by the user.
float read_float(string prompt);

/// Reads a character from the user.
/// @param prompt The prompt to display to the user.
/// @return The character entered by the user.
char read_char(string prompt);

/// Generates a random integer between min and max (inclusive).
/// @param min The minimum value of the random number.
/// @param max The maximum value of the random number.
int random_int(int min, int max);

#endif //FUNCTIONS_H
