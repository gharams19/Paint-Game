//
// Created by Gharam Alsaedi on 12/7/17.
//

#ifndef PAINT_FINAL_COMMANDS_H
#define PAINT_FINAL_COMMANDS_H

#include <stdbool.h>

bool InvalidCommand(char c);

void getCommand(char *str, char **canvas, int *rows, int *cols, char ch);

void Resize(char **canvas, int newRows, int newCols, int rows, int cols);

void Quit(char **canvas, int rows);

void Help();

void Write(char *str, char **canvas);

void Save(char *str, char **canvas, int rows, int cols);

#endif //PAINT_FINAL_COMMANDS_H
