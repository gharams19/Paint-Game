//
// Created by Gharam Alsaedi on 12/12/17.
//

#include "addDelete.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void Delete(char **canvas, int *rows, int *cols, int rows1, char ch, int del) { //isn't finished


    if (ch == 'c') {
        *cols = *cols - 1;


        char temp;
        for (int i = 0; i < *rows; i++) {
            char *tmp = realloc(canvas[i], sizeof *canvas[i] * (*cols));
            if (tmp) {
                canvas[i] = tmp;
            }
        }
        for (int i = 0; i < *rows; i++) {
            for (int j = del; j < *cols; j++) {
                temp = canvas[i][j];

                canvas[i][j] = canvas[i][j + 1];
                canvas[i][j + 1] = temp;

            }
        }

    } else {
        char temp;

        *rows = *rows - 1;
        for (size_t i = 1; i <= 1; i++)
            free(canvas[rows1 - i]);

        canvas = realloc(canvas, rows1 * sizeof(char *));


        del = rows1 - 1 - del;
        for (int i = del; i < *rows; i++) {
            for (int j = 0; j < *cols; j++) {

                temp = canvas[i][j];

                canvas[i][j] = canvas[i + 1][j];
                canvas[i + 1][j] = temp;
            }
        }


    }


}

void Add(char **canvas, int *rows, int *cols, char ch, int add) { //i think this is good


    char temp1, temp2;


    if (ch == 'c') {
        *cols = *cols + 1;

        for (int i = 0; i < *rows; i++) {
            char *tmp = realloc(canvas[i], sizeof *canvas[i] * (*cols));
            if (tmp) {
                canvas[i] = tmp;
            }
        }
        for (int i = 0; i < *rows; i++) {
            for (int j = *cols - 1; j > add; j--) {
                temp1 = canvas[i][j];

                canvas[i][j] = canvas[i][j - 1];
                canvas[i][j - 1] = temp1;
            }
        }
        for (int k = 0; k < *rows; ++k) {
            canvas[k][add] = '*';
        }

    } else if (ch == 'r') {
        int rows1 = *rows;
        *rows = *rows + 1;

        canvas = (char **) realloc(canvas, (*rows) * sizeof(char *));

        for (int i = 0; i < 1; ++i) {
            canvas[i] = (char *) malloc((*cols) * sizeof(char));
        }


        add = rows1 - add;

        for (int i = rows1 - 1; i > add; i--) {
            for (int j = 0; j < *cols; j++) {

                temp2 = canvas[i][j];
                canvas[i][j] = canvas[i - 1][j];
                canvas[i - 1][j] = temp2;

            }
        }
        for (int k = 0; k < *cols; ++k) {
            canvas[add][k] = '*';

        }
    }

}


void Erase(char **canvas, int rows, int row, int col) { //good


    if (row == 0) {
        canvas[rows - 1][col] = '*';

    } else {
        canvas[rows - 1 - row][col] = '*';
    }
}
bool valid_resize(int newRows, int newCols) {
    if (newRows >= 1 && newCols >= 1) {
        return true;
    }
    return false;
}
void Resize(char **canvas, int newRows, int newCols, int rows, int cols) { // not finshed

    if (valid_resize(newRows, newCols)) {
        if (newRows < rows) {
            for (int i = 0; i < rows - newRows; i++) {
                Delete(canvas, &rows, &cols, rows, 'r', rows - 1 - i);
            }
        } else if (rows < newRows) {
            for (int i = 0; i < newRows - rows; i++) {
                Add(canvas, &rows, &cols, 'r', newRows);
            }
        }

        if (newCols < cols) {
            for (int i = 0; i < cols - newCols; i++) {
                Delete(canvas, &rows, &cols, rows, 'c', cols - 1 - i);
            }
        } else if (cols < newCols) {
            for (int i = 0; i < newCols - cols; i++) {
                Add(canvas, &rows, &cols, 'c', newCols);
            }
        }
    } else {
        printf("Improper resize command.\n");
    }
}



