#include <iostream>
#include <State.h>
#include <HillClimbing.h>

using namespace std;

State generateRandomState (unsigned int size) {
    State state(size);
    for (unsigned int i = 0;i < size;i++) {
        state.board[i] = rand() % size;
    }
    return state;
}


int main() {
    int n = 32;
    State start = generateRandomState(n);
    HillClimbing hillClimbing;
    printf("\n---------Start State---------\n");
    start.print();
    start.inAttack();
    //printf("---------Successors State---------\n");
    State goal = hillClimbing.search(start);
    printf("\n---------Goal State---------\n");
    goal.print();
    goal.inAttack();
    printf("\nWeight: %d\n", goal.getHeuristic());
    return 0;
}

