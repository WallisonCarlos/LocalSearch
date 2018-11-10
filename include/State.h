#ifndef STATE_H
#define STATE_H

#include <vector>
#include <Utils.h>
Utils utils;

typedef struct State{

    int *board;
    unsigned int size;
    int heuristic = -1;
    State () {
        board = (int *) malloc(4*sizeof(int));
        size = 4;
    }

    State (unsigned int n) {
        this->size = n;
        this->board = (int*) malloc(n*(sizeof(int)));
    }

    State (int n, int *b) {
        this->size = n;
        this->board = (int *) malloc(size*sizeof(int));
        utils.copy(board, b, size);
    }

    void inAttack () {
        for (unsigned int i = 0;i < size;i++) {
            for (unsigned int j = i+1;j < size;j++) {
                if (board[i] == board[j]) {
                    printf("(%d, %d) ", i, board[i]);
                }
                int offset = j - i;

                if (board[i] == board[j] - offset || board[i] == board[j] + offset) {
                    printf("(%d, %d) ", i, board[i]);
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
                    if (board[i] == board[j]) {
                        h += 1;
                    }
                    int offset = j - i;

                    if (board[i] == board[j] - offset || board[i] == board[j] + offset) {
                        h += 1;
                    }
                }
            }
            return heuristic = h;
        }
    }

    std::vector<State> successors() {

        std::vector<State> successors;
        int b[size];

        for (unsigned int i = 0;i < size;i++) {

            utils.copy(b, board, size);

            for (unsigned int j = 0;j < size;j++) {

                if (!(b[i] == j)) {
                    b[i] = j;
                    successors.push_back(State(size, b));
                    //successors.back().print();
                    //printf("Weight: %d\n", successors.back().getHeuristic());
                    //successors.back().inAttack();
                    //printf("\n");
                }

            }

        }

        return successors;
    }

    void print() {

        for (unsigned int i = 0;i < size;i++) {

            for (unsigned int j = 0;j < size;j++) {
                if (board[i] == j) {
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
