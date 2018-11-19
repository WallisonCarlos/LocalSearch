#include <iostream>
#include <State.h>
#include <HillClimbing.h>
#include <SimulatedAnnealing.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

State generateRandomState (unsigned int size) {
    State state(size);
    srand((unsigned int) time(NULL));
    for (unsigned int i = 0;i < size;i++) {
        state.board[i] = rand() % size;
    }
    return state;
}


int main() {
    int n = 8, algorithm = 1;
    State start = generateRandomState(n);
    HillClimbing hillClimbing;
    hillClimbing.durationRandomRestart = 10000;
    SimulatedAnnealing simulatedAnnealing;
    printf("\n---------Start State---------\n");
    start.print();
    start.inAttack();
    State goal;

    if (algorithm) {
        goal = hillClimbing.searchRandomRestart(start);
    } else {
        goal = simulatedAnnealing.search(start);
    }

    printf("\n---------Goal State---------\n");
    goal.print();
    goal.inAttack();
    printf("\nWeight: %d\n", goal.getHeuristic());
    return 0;
}

