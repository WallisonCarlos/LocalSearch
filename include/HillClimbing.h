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
        //Percorrer lista de Rainhas
        for (unsigned int i = 0;i < state.size;i++) {

            utils.copy(b, state.board, state.size);
            Queen backup = b[i];
            Queen aux = b[i];
            int minCol, maxCol, minRow, maxRow, minPri, maxPri, minSec, maxSec;
            minCol = minRow = minPri = minSec = INT_MIN;
            maxCol = maxRow = maxPri = maxSec = INT_MAX;
            //Movimentar a Rainha na linha e na coluna
            for (unsigned int j = 1;j < state.size;j++) {


                //Verifica se movimento da direita da coluna é válido e cria estado sucesso
                if (aux.col + j < maxCol && aux.col + j < state.size) {
                    aux.col = aux.col + j;
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }
                    } else {
                        maxCol = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;

                //Verifica se movimento da esquerda da coluna é válido e cria estado sucesso
                if (aux.col - j > minCol && aux.col - j >= 0) {

                    aux.col = aux.col - j;
                    //Verifica se movimento da esquerda da coluna é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }

                    } else {
                        minCol = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;
                //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                if (aux.row + j < maxRow && aux.row < state.size) {

                    aux.row = aux.row + j;
                    //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }
                    } else {
                        maxRow = aux.row;
                    }
                }

                b[i] = backup;
                aux = backup;
                //Verifica se movimento para cima da linha é válido e cria estado sucesso
                if (aux.row - j > minRow && aux.row >= 0) {

                    aux.row = aux.row - j;
                    //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }
                    } else {
                        minRow = aux.row;
                    }
                }

                b[i] = backup;
                aux = backup;
                //Verifica se movimento para cima da diagonal principal é válido e cria estado sucesso
                if ((aux.row - j > minPri && aux.col - j> minPri) && (aux.row - j >= 0 && aux.col - j >= 0)) {

                    aux.row = aux.row - j;
                    aux.col = aux.col - j;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }

                    } else {
                        minPri = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;
                //Verifica se movimento para baixo da digagonal principal é válido e cria estado sucesso
                if ((aux.row + j < maxPri && aux.col + j < maxPri) && (aux.row + j < state.size && aux.col + j < state.size)) {

                    aux.row = aux.row + j;
                    aux.col = aux.col + j;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }

                    } else {
                        maxPri = aux.col;
                    }
                }

                b[i] = backup;
                aux =  backup;
                //Verifica se movimento para cima da digagonal secundária é válido e cria estado sucesso
                if ((aux.col + j < maxSec) && aux.row - j >= 0 && aux.col + j < state.size) {

                    aux.row = aux.row - j;
                    aux.col = aux.col + j;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }

                    } else  {
                        maxSec = aux.col;
                    }
                }

                b[i] = backup;
                aux =  backup;
                //Verifica se movimento para baixo da digagonal secundária é válido e cria estado sucesso
                if ((aux.col - j < minSec) && aux.row + j < state.size && aux.col - j >= 0) {

                    aux.row = aux.row + j;
                    aux.col = aux.col - j;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);

                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                        }

                    } else  {
                        minSec = aux.col;
                    }

                }

            }

        }

        return successor;
    }


} HillClimbing;


#endif // HILLCLIMBING_H
