#include <stdio.h>
#include <stdlib.h>
#include "commands.h"
#include "canvas.h"

typedef struct canvas {
    int rows;
    int cols;

} canvas;

int main(int argc, char *argv[]) {
    struct canvas c;

    if (argc == 3) {
        c.rows = *argv[1] - '0';
        c.cols = *argv[2] - '0';
    } else {
        c.rows = 10;
        c.cols = 10;
    }


    char **canvas = CreateCanvas(argc, argv);
    char ch = ' ';
    char str[50];
    bool ifAfter = false;
    printf("\nEnter 'h' to list commands\n");
    while (ch != 'q') {


        int i = 0;

        printf("\nEnter your command: ");
        while (ch != '\n') {

            ch = getchar();
            str[i] = ch;
            i++;
        }
        str[i] = '\0';

        ch = str[0];
        getCommand(str, canvas, &c.rows, &c.cols, ch);
        if(ch == 'a'){
            ifAfter = true;
        }
        print_canvas(c.rows, c.cols, canvas,ifAfter);
    }
    getCommand(str, canvas, &c.rows, &c.cols, ch);

    cleanUp(&canvas,c.rows);


    return 0;
}