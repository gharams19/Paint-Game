//
// Created by Gharam Alsaedi on 12/8/17.
//

#ifndef PAINT_FINAL_CANVAS_H
#define PAINT_FINAL_CANVAS_H

#include <stdbool.h>

void print_canvas(int rows, int cols, char **canvas, bool ifAfter);

char **CreateCanvas(int argc, char **argv);

bool valid_input(int n1, int n2);

void cleanUp(char ***canvas, int rows);

#endif //PAINT_FINAL_CANVAS_H
