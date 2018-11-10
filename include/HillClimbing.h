#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <State.h>
#include <limits.h>
#include <vector>

typedef struct HillClimbing {

    State search (State start) {

        State currentState = start;
        int i = 0;
        while (true) {
            //printf("------------------------%d Cycle States -------------------------\n", i);
            std::vector<State> successors = currentState.successors();
            int nextVal = INT_MAX;

            State nextState;

            for (unsigned int i = 0;i < successors.size();i++) {
                State s = successors[i];
                if (s.getHeuristic() < nextVal) {
                    nextState = s;
                    nextVal = s.getHeuristic();
                }
            }

            /*printf("--------------------Estado escolhido: --------------------\n");
            nextState.print();
            printf("\nWeight: %d \n", nextState.getHeuristic());
            printf("-----------------------------------------------------------s");*/

            if (nextVal >= currentState.getHeuristic()) {
                return currentState;
            }

            currentState = nextState;
            i++;
            if (i == 5) {
                getchar();
            }
        }
    }

} HillClimbing;


#endif // HILLCLIMBING_H
