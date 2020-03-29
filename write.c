//
// Created by Gharam Alsaedi on 12/8/17.
#include "write.h"
#include <stdbool.h>
#include <stdio.h>

void write(char **canvas, int row1, int col1, int row2, int col2, int numR) {

    if (validate_input(row1, col1, row2, col2)) {
        printf("Improper draw command.\n");
    }//check if one line
    if (check_if_one_line(row1, col1, row2, col2)) {
        if (canvas[numR - 1 - row1][col1] == '*' || canvas[numR - 1 - row1][col1] == '-') {
            canvas[numR - 1 - row1][col1] = '-';
        } else {
            canvas[numR - 1 - row1][col1] = '+';
        }
    }//write right diagonal
    else if (check_if_right(row1, col1, row2, col2)) {
        int startR = row1;
        int startC = col1;
        if (row1 < row2) {
            while (startR <= row2 && startC <= col2) {
                if (canvas[numR - 1 - startR][startC] == '*' || canvas[numR - 1 - startR][startC] == '/') {
                    canvas[numR - 1 - startR][startC] = '/';
                } else {
                    canvas[numR - 1 - startR][startC] = '+';
                }
                startR++;
                startC++;
            }
        } else {
            while (startR >= row2 && startC >= col2) {
                if (canvas[numR - 1 - startR][startC] == '*' || canvas[numR - 1 - startR][startC] == '/') {
                    canvas[numR - 1 - startR][startC] = '/';
                } else {
                    canvas[numR - 1 - startR][startC] = '+';
                }
                startR--;
                startC--;
            }
        }
    }//write left diagonal
    else if (check_if_left(row1, col1, row2, col2)) {
        int startR = row1;
        int startC = col1;
        if (row1 > row2) {
            while (startR >= row2 && startC <= col2) {
                if (canvas[numR - 1 - startR][startC] == '*' || canvas[numR - 1 - startR][startC] == '\\') {
                    canvas[numR - 1 - startR][startC] = '\\';
                } else {
                    canvas[numR - 1 - startR][startC] = '+';
                }
                startR--;
                startC++;
            }
        } else {
            while (startR <= row2 && startC >= col2) {
                if (canvas[numR - 1 - startR][startC] == '*' || canvas[numR - 1 - startR][startC] == '\\') {
                    canvas[numR - 1 - startR][startC] = '\\';
                } else {
                    canvas[numR - 1 - startR][startC] = '+';
                }
                startR++;
                startC--;
            }
        }
    }//write horizontal line
    else if (check_if_horizontal(row1, row2)) {
        int startC = col1;
        if (col1 < col2) {
            while (startC <= col2) {
                if (canvas[numR - 1 - row1][startC] == '*' || canvas[numR - 1 - row1][startC] == '-') {
                    canvas[numR - 1 - row1][startC] = '-';
                } else {
                    canvas[numR - 1 - row1][startC] = '+';
                }
                startC++;
            }
        } else {
            while (startC >= col2) {
                if (canvas[numR - 1 - row1][startC] == '*' || canvas[numR - 1 - row1][startC] == '-') {
                    canvas[numR - 1 - row1][startC] = '-';
                } else {
                    canvas[numR - 1 - row1][startC] = '+';
                }
                startC--;
            }
        }
    }//write verticle
    else if (check_if_verticle(col1, col2)) {
        int startR = row1;
        if (row1 < row2) {
            while (startR <= row2) {
                if (canvas[numR - 1 - startR][col1] == '*' || canvas[numR - 1 - startR][col1] == '|') {
                    canvas[numR - 1 - startR][col1] = '|';
                } else {
                    canvas[numR - 1 - startR][col1] = '+';
                }
                startR++;
            }
        } else {
            while (startR >= row2) {
                if (canvas[numR - 1 - startR][col1] == '*' || canvas[numR - 1 - startR][col1] == '|') {
                    canvas[numR - 1 - startR][col1] = '|';
                } else {
                    canvas[numR - 1 - startR][col1] = '+';
                }
                startR--;
            }
        }
    }
}

bool check_if_one_line(int start_row, int start_column, int end_row, int end_column) {
    if ((start_row == end_row) && (start_column == end_column)) {
        return true;
    }
    return false;
}

bool check_if_right(int start_row, int start_column, int end_row, int end_column) {
    if ((start_row - end_row) - (start_column - end_column) == 0) {
        return true;
    }
    return false;
}

bool check_if_left(int start_row, int start_column, int end_row, int end_column) {
    if ((start_row - end_row) + (start_column - end_column) == 0) {
        return true;
    }
    return false;
}

bool check_if_verticle(int start_column, int end_column) {
    if (start_column == end_column) {
        return true;
    }
    return false;
}

bool check_if_horizontal(int start_row, int end_row) {
    if (start_row == end_row) {
        return true;
    }
    return false;
}

bool validate_input(int start_row, int start_column, int end_row, int end_column) {
    if (!check_if_one_line(start_row, start_column, end_row, end_column)) {
        if (!check_if_right(start_row, start_column, end_row, end_column)) {
            if (!check_if_left(start_row, start_column, end_row, end_column)) {
                if (!check_if_horizontal(start_row, end_row)) {
                    if (!check_if_verticle(start_column, end_column)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}