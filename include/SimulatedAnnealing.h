#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include <State.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define RANDOM_ZERO_UNTIL_ONE ((float)(random())/(float)(RAND_MAX))

typedef struct SimulatedAnnealing {

    State search (State start) {

        State solution = start;

        float temperature = 1000.0f;

        while (temperature > 0.00001f) {


            State neighbor = randomNeighbor(solution);
            printf("\n----------------------Compare----------------------------\n");
            printf("-----------Solution-------------\n");
            solution.print();
            printf("\nWeight: %d", solution.getHeuristic());
            printf("\n-----------Neighbor-------------\n");
            neighbor.print();
            printf("\nWeight: %d", neighbor.getHeuristic());
            int dE = neighbor.getHeuristic() - solution.getHeuristic();
            if (dE <= 0) {

                solution = neighbor;

                if (solution.getHeuristic() == 0) {
                    break;
                }

            } else {
                printf("\n---------------------Calcs---------------------\n");
                float probability = powf(M_E, (float)(-dE/temperature));
                std::cout << probability << std::endl;
                printf("Probability: %f\n", probability);
                if (probability > 0.9f) {
                    printf("trocou");
                    solution = neighbor;
                }
            }

            temperature *= 0.9f;
        }

        return solution;
    }

    State randomNeighbor (State state) {

        State neighbor;

        //srand((unsigned int) time(NULL));

        int changes = rand() % state.size;

        if (changes == 0) {
            changes++;
        }

        int *board = (int *) malloc(state.size * sizeof(int));

        utils.copy(board, state.board, state.size);

        for (unsigned int i = 0;i < changes;i++) {

            int row = rand() % state.size;
            int col = rand() % state.size;
            board[row] = col;

        }

        neighbor.board = board;
        neighbor.size = state.size;

        return neighbor;

    }

} SimulatedAnnealing;

#endif // SIMULATEDANNEALING_H
