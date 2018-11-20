#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <State.h>
#include <limits.h>
#include <queue>

typedef struct HillClimbing {

    int durationRandomRestart;
    int maxIterations = INT_MAX;

    State search (State start) {

        State currentState = start;
        int nextVal = INT_MAX;

        while (true) {

            State nextState;
            State s = successor(currentState);

            if (s.getHeuristic() < nextVal) {

                nextState = s;
                nextVal = s.getHeuristic();

            }

            if (nextVal >= currentState.getHeuristic()) {
                return currentState;
            }
            currentState = nextState;
        }
    }

    State random(State start) {

        State current = start;
        State best = start;
        int iterations = 0;

        while (true) {

            State next = successor(current);

            if (next.getHeuristic() < current.getHeuristic()) {

                current = next;
                best = current;

            } else {

                current = generateRandomState(current.size);

                if (current.getHeuristic() < best.getHeuristic()) {
                    best = current;
                }

            }

            if (best.getHeuristic() == 0 || iterations == maxIterations) {
                break;
            }

        }

        return best;
    }

    State searchRandomRestart(State start) {

        State best = start;

        int nextVal = INT_MAX;

        while (true) {

            int timeStart = time(NULL);

            while (true) {

                State r = successor(start);

                if (r.getHeuristic() < start.getHeuristic()) {
                    start = r;
                }

                if (start.getHeuristic() ==  0 || (timeStart + durationRandomRestart) >= time(NULL)) {
                    break;
                }
            }

            if (start.getHeuristic() < best.getHeuristic()) {
                best = start;
            }

            start = generateRandomState(start.size);

            if (start.getHeuristic() == 0 || (timeStart + durationRandomRestart) >= time(NULL)) {
                break;
            }
        }
        return best;
    }

   State generateRandomState (unsigned int size) {

        State state(size);
        srand((unsigned int) time(NULL));

        for (unsigned int i = 0;i < size;i++) {
            state.board[i] = rand() % size;
        }

        return state;
    }

    State successor(State state) {

        State successor = state;
        int b[state.size];

        for (unsigned int i = 0;i < state.size;i++) {

            utils.copy(b, state.board, state.size);

            for (unsigned int j = 0;j < state.size;j++) {

                if (!(b[i] == j)) {

                    b[i] = j;
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
