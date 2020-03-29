//
// Created by Gharam Alsaedi on 12/8/17.
//

#include "canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void print_canvas(int rows, int cols, char **canvas, bool ifAfter) {


        printf("\n");
        // print board
        for (int row = 0; row < rows; ++row) {
            printf("%d ", rows-row - 1);  // row header
            for (int col = 0; col < cols; ++col) {
                printf("%c ", canvas[row][col]);
            }
            printf("\n");
        }
        printf("  ");
        for(int col = 0; col < cols; ++col){
            printf("%d ", col);
        }

    }






bool valid_input(int n1, int n2) {
    if (n1 >= 1 || n2 >= 1) {
        return true;
    }
    return false;
}


char **CreateCanvas(int argc, char **argv) {
    char **canvas;
    if (argc == 3) {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[2]);
        if (valid_input(n1, n2)) {
            canvas = (char **) malloc(n1 * sizeof(char *));
            for (int i = 0; i < n1; i++) {
                canvas[i] = (char *) malloc(n2 * sizeof(char));
                for (int j = 0; j < n2; j++) {
                    canvas[i][j] = '*';
                }
            }
            print_canvas(n1, n2, canvas, false);
        }
    } else {
        canvas = (char **) malloc(10 * sizeof(char *));
        for (int i = 0; i < 10; i++) {
            canvas[i] = (char *) malloc(10 * sizeof(char));
            for (int j = 0; j < 10; j++) {
                canvas[i][j] = '*';
            }
        }
        print_canvas(10, 10, canvas, false);
    }
    return canvas;
}


void cleanUp(char ***canvas, int rows) {
    for (int row = 0; row < rows; ++row) {
        free((*canvas)[row]);
    }
    free(*canvas);
    *canvas = NULL;
}


