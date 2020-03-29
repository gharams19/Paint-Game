//
// Created by Gharam Alsaedi on 12/12/17.
//

#ifndef PAINT_FINAL_ADDDELETE_H
#define PAINT_FINAL_ADDDELETE_H

void Add(char **canvas, int *rows, int *cols, char ch, int del);

void Delete(char **canvas, int *rows, int *cols, int rows1, char ch, int del);

void Erase(char **canvas, int rows, int row, int col);

#endif //PAINT_FINAL_ADDDELETE_H
