#ifndef SIMULATEDANNEALING_H
#define SIMULATEDANNEALING_H

#include <State.h>
#include <math.h>


typedef struct SimulatedAnnealing {

    State search (State start) {

        State solution = start;

        float temperature = 1.0f;

        while (temperature > 0.1f) {

            State neighbor = randomNeighbor(solution);

            if (neighbor.getHeuristic() < solution.getHeuristic()) {

                solution = neighbor;

                if (solution.getHeuristic() == 0) {
                    break;
                }

            } else {

                int probability = pow(M_E, (-neighbor.getHeuristic/temperature));

                if (probability > 0.7f) {
                    solution = neighbor;
                }
            }

            temperature *= 0.009f;
        }

        return solution;
    }

    State randomNeighbor (State state) {

        State neighbor;
        int changes = random() % state.size;
        int *board = (int *) malloc(size * sizeof(int));

        utils.copy(board, state.board, state.size);

        for (unsigned int i = 0;i <changes;i++) {

            int row = random() % state.size;
            int col = random() % state.size;

            board[row] = col;

        }

        neighbor.board = board;
        neighbor.size = state.size;

        return neighbor;

    }

} SimulatedAnnealing;

#endif // SIMULATEDANNEALING_H
