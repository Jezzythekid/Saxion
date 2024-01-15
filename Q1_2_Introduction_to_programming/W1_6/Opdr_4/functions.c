#include <stdio.h>  // for printf()
#include <stdlib.h>  // for rand()
#include <stdbool.h>  // for bool
#include <time.h>  // for time(), localtime()

#include "functions.h"

static void seed_prng(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        for (int i = 0; i < 50; i++) rand();
        seeded = true;
    }
}

int read_int(string prompt) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Try again: ");
        while (getchar() != '\n');  // clear input buffer
    }
    while (getchar() != '\n');  // clear input buffer
    return input;
}

float read_float(string prompt) {
    float input;
    printf("%s", prompt);
    while (scanf("%f", &input) != 1) {
        printf("Invalid input. Try again: ");
        while (getchar() != '\n');  // clear input buffer
    }
    while (getchar() != '\n');  // clear input buffer
    return input;
}

char read_char(string prompt) {
    char input;
    printf("%s", prompt);
    while (scanf(" %c", &input) != 1) {
        printf("Invalid input. Try again: ");
        while (getchar() != '\n');  // clear input buffer
    }
    while (getchar() != '\n');  // clear input buffer
    return input;
}

int random_int(int min, int max) {
    seed_prng();
    return rand() / (RAND_MAX / (max - min + 1) + 1) + min;
}

float random_float(float min, float max) {
    seed_prng();
    return rand() * (max - min) / RAND_MAX + min;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

bool get_current_date(int date_parts[static 3]) {
    time_t t = time(NULL);
    if (t == -1) return false;
    struct tm *tm = localtime(&t);
    if (tm == NULL) return false;
    date_parts[0] = tm->tm_year + 1900;
    date_parts[1] = tm->tm_mon + 1;
    date_parts[2] = tm->tm_mday;
    return true;
}

bool get_current_time(int time_parts[static 3]) {
    time_t t = time(NULL);
    if (t == -1) return false;
    struct tm *tm = localtime(&t);
    if (tm == NULL) return false;
    time_parts[0] = tm->tm_hour;
    time_parts[1] = tm->tm_min;
    time_parts[2] = tm->tm_sec;
    return true;
}