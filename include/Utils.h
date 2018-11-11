#ifndef UTILS_H
#define UTILS_H

#include <Queen.h>

typedef struct Utils {

    void copy(Queen* vectorOne, Queen* vectorTwo, unsigned int size) {

        for (unsigned int i = 0;i < size;i++) {
            vectorOne[i] = vectorTwo[i];
        }

    }

    bool valid(Queen queen, Queen *board, unsigned int size) {

        for (unsigned int i = 0;i < size;i++) {


            if ((queen.row == board[i].row && board[i].col == queen.col)) {
                return false;
            }

        }

        return true;
    }

    bool validCol(Queen queen, Queen *board, unsigned int size) {

        for (unsigned int i = 0;i < size;i++) {


            if (board[i].col == queen.col) {
                return false;
            }

        }

        return true;
    }



} Utils;

#endif // UTILS_H
