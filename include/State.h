#ifndef STATE_H
#define STATE_H

#include <queue>
#include <Utils.h>
#include <Queen.h>

Utils utils;

typedef struct State{

    Queen *board;
    unsigned int size;
    int heuristic = -1;

    State () {
        board = (Queen *) malloc(4*sizeof(Queen));
        size = 4;
    }

    State (unsigned int n) {
        this->size = n;
        this->board = (Queen*) malloc(n*(sizeof(Queen)));
    }

    State (int n, Queen *b) {
        this->size = n;
        this->board = (Queen *) malloc(size*sizeof(Queen));
        utils.copy(board, b, size);
    }

    void inAttack () {
        printf("\nIn Attack:\n");
        for (unsigned int i = 0;i < size;i++) {

            for (unsigned int j = i+1;j < size;j++) {

                if (board[i].row == board[j].row || board[i].col == board[j].col) {
                    printf("(%d, %d) ", board[j].row, board[j].col);
                }

                if (board[i].diagPri == board[j].diagPri || board[i].diagSec == board[j].diagSec) {
                    printf("(%d, %d) ", board[j].row, board[j].col);
                }

            }

        }
    }

    int getHeuristic() {
        if (heuristic != -1) {
            return heuristic;
        } else {
            int h = 0;
            for (unsigned int i = 0;i < size;i++) {

                for (unsigned int j = i+1;j < size;j++) {

                    if (board[i].row == board[j].row || board[i].col == board[j].col) {
                        h += 1;
                    }

                    if (board[i].diagPri == board[j].diagPri || board[i].diagSec == board[j].diagSec) {
                        h += 1;
                    }

                }

            }

            return heuristic = h;
        }
    }

    void print() {

        for (unsigned int i = 0;i < size;i++) {

            for (unsigned int j = 0;j < size;j++) {
                bool isQueen = false;
                for (unsigned int k = 0;k < size;k++) {
                    if (board[k].row == i && board[k].col == j) {
                        isQueen = true;
                        break;
                    }
                }
                if (isQueen) {
                    printf("[Q]");
                } else {
                    printf("[ ]");
                }
            }

            printf("\n");
        }
        printf("Heuristic: %d\n", getHeuristic());
    }

} State;



#endif // STATE_H
