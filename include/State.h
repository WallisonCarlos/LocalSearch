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
        for (unsigned int i = 0;i < size;i++) {
            for (unsigned int j = i+1;j < size;j++) {
                if (board[i].row == board[j].row || board[i].col == board[j].col) {
                    printf("(%d, %d) ", board[i].row, board[i].col);
                }
                int offset = j - i;

                if (board[i].col == board[j].col - offset || board[i].col == board[j].col + offset) {
                    printf("(%d, %d) ", board[i].row, board[i].col);
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

                    int offset = j - i;

                    if (board[i].col == board[j].col - offset || board[i].col == board[j].col + offset) {
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
                if (board[i].col == j) {
                    printf("[Q]");
                } else {
                    printf("[ ]");
                }
            }

            printf("\n");
        }

    }

} State;



#endif // STATE_H
