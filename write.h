//
// Created by Gharam Alsaedi on 12/8/17.
//
#ifndef UNTITLED10_WRITE_H
#define UNTITLED10_WRITE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void write(char **canvas, int row1, int col1, int row2, int col2, int numR);

bool check_if_one_line(int start_row, int start_column, int end_row, int end_column);

bool check_if_right(int start_row, int start_column, int end_row, int end_column);

bool check_if_left(int start_row, int start_column, int end_row, int end_column);

bool check_if_verticle(int start_column, int end_column);

bool check_if_horizontal(int start_row, int end_row);

bool validate_input(int start_row, int start_column, int end_row, int end_column);


#endif //UNTITLED10_WRITE_H
