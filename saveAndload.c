//
// Created by Gharam Alsaedi on 12/14/17.
//

#include "saveAndload.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void Find_rows_and_columns(char*str,int *rows, int*cols) {
    FILE *fopen(), *fp;
    char c;
    char *filename;
    int row = 1, col = 1, temp = 0;

    int len = strlen(str);
    filename = strndup(str + 2, len);



    fp = fopen(filename, "r");
    do {
        c = getc(fp);

        if ((temp != 2) && (c == ' '))
            col++;
        if (c == '\n') {
            temp = 2;
            row++;
        }
    }while(!feof(fp));

    *rows = row;
    *cols = col;
}
void Load(char *str, char ***canvas, int* rows, int* cols) {
    FILE *fp;
    char *filename;
    int len = strlen(str);
    filename = strndup(str + 2, len);

    fp = fopen(filename, "r");
    char c;
    int rows1=0, cols1=0;

    Find_rows_and_columns(str,&rows1,&cols1);

    *rows = rows1;
    *cols = cols1;

    char** newCanvas;

    newCanvas = (char**)malloc(*rows * sizeof(char*));

    for (int m = 0; m <*rows ; ++m) {
        newCanvas[m] = (char*)malloc(*cols * sizeof(char));
    }




    for (int j = 0; j < *rows; ++j) {

        for (int i = 0; i < *cols; ++i) {
            fscanf(fp, "%c ", &newCanvas[j][i]);
        }
    }

    *canvas = newCanvas;


    fclose(fp);
}