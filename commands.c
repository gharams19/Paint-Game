//
// Created by Gharam Alsaedi on 12/7/17.
//

#include "commands.h"
#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"
#include "write.h"
#include "addDelete.h"
#include <string.h>
#include "saveAndload.h"



void Quit(char **canvas, int rows) {
    cleanUp(&canvas, rows);
    exit(0);
}

void Help() {

    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}



void Save(char *str, char **canvas, int rows, int cols) {
    FILE *fp;
    char *filename = " ";
    int len = strlen(str);
    filename = strndup(str + 2, len);


    fp = fopen(filename, "wb");
    for (int l = 0; l < rows; ++l) {
        for (int i = 0; i < cols; ++i) {
            fprintf(fp, "%c", canvas[l][i]);
        }
        fprintf(fp, "\n");

    }
    fclose(fp);

}


void getCommand(char *str, char **canvas, int *rows, int *cols, char ch) {

    int toRows, toCols;
    if (ch == 'q') {
        Quit(canvas, *rows);
    } else if (ch == 'h') {
        Help();
    } else if (ch == 'w') {
        int startR = str[2] - '0';
        int startC = str[4] - '0';
        int endR = str[6] - '0';
        int endC = str[8] - '0';
        write(canvas, startR, startC, endR, endC, *rows);
    } else if (ch == 'e') {
        int row = str[2] - '0';
        int col = str[4] - '0';
        Erase(canvas, *rows, row, col);
    } else if (ch == 'a') {
        char c = str[2];
        int add = str[4] - '0';

        Add(canvas, rows, cols, c, add);
    } else if (ch == 'd') {
        char c = str[2];
        int del = str[4] - '0';

        Delete(canvas, rows, cols, *rows, c, del);

    } else if (ch == 'r') {
        toRows = str[2] - '0';
        toCols = str[4] - '0';
        *rows = toRows;
        *cols = toCols;
        Resize(canvas, toRows, toCols, *rows, *cols);

    } else if (ch == 's') {

        Save(str, canvas, *rows, *cols);


    } else if (ch == 'l') {
        Load(str, &canvas,rows, cols);

    } else {
        printf("Unrecognized command. Type h for help.\n");

    }
}

