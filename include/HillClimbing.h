#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <State.h>
#include <limits.h>
#include <Queen.h>


typedef struct HillClimbing {

    State search (State start) {

        State currentState = start;

        while (true) {

            int nextVal = INT_MAX;
            State nextState;
            State s = successor(currentState);

            if (s.getHeuristic() < nextVal) {

                nextState = s;
                nextVal = s.getHeuristic();

            }

            /*printf("--------------------Estado escolhido: --------------------\n");
            nextState.print();
            printf("\nWeight: %d \n", nextState.getHeuristic());
            printf("-----------------------------------------------------------s");*/

            if (nextVal >= currentState.getHeuristic()) {
                return currentState;
            }
            currentState = nextState;
        }
    }

    State successor(State state) {

        State successor = state;
        Queen* b = (Queen *) malloc(state.size * sizeof(Queen));

        for (unsigned int i = 0;i < state.size;i++) {

            utils.copy(b, state.board, state.size);

            for (unsigned int j = 0;j < state.size;j++) {

                if (!(b[i].col == j)) {

                    b[i].col = j;
                    State next(state.size, b);

                    if (next.getHeuristic() < state.getHeuristic()) {
                        successor = next;
                    }

                }

            }

        }

        return successor;
    }


} HillClimbing;


#endif // HILLCLIMBING_H
