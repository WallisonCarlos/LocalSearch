#ifndef HILLCLIMBING_H
#define HILLCLIMBING_H

#include <State.h>
#include <limits.h>
#include <Queen.h>


typedef struct HillClimbing {

    State search (State start) {

        State currentState = start;
        int i = 0;
        int plato = 0;
        while (true) {
            printf("\n\n------------------Laço %d----------------\n", i);
            int nextVal = INT_MAX;
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
            i++;
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

                int newCol = aux.col + j;
                //Verifica se movimento da direita da coluna é válido e cria estado sucesso
                if ((newCol < maxCol) && (newCol < state.size)) {

                    aux.col = newCol;

                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Col-Right-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }
                    } else {
                        maxCol = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;
                newCol = aux.col - j;
                //Verifica se movimento da esquerda da coluna é válido e cria estado sucesso
                if ((newCol > minCol) && (newCol > -1)) {
                    aux.col = newCol;
                    //Verifica se movimento da esquerda da coluna é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Col-Left-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }
                    } else {
                        minCol = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;
                int newRow = aux.row + j;
                //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                if ((newRow < maxRow) && (newRow < state.size)) {

                    aux.row = newRow;
                    //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Line-Down-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }
                    } else {
                        maxRow = aux.row;
                    }
                }

                b[i] = backup;
                aux = backup;
                newRow = aux.row - j;
                //printf("\nAux top: %d e j: %d newRow: %d minRow: %d\n ", aux.row, j, newRow, minRow);
                //Verifica se movimento para cima da linha é válido e cria estado sucesso
                if ((newRow > minRow) && (newRow > -1)) {
                    //printf("\nAux top: %d e j: %d minRow: %d\n ", aux.row, j, minRow);
                    aux.row = newRow;
                    //Verifica se movimento para baixo da linha é válido e cria estado sucesso
                    if (utils.valid(aux, state.board, state.size)) {
                        printf("Aqui\n");
                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Line-Top-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }
                    } else {
                        printf("Não, aqui\n");
                        minRow = aux.row;
                    }
                }

                b[i] = backup;
                aux = backup;
                int newColPri = aux.col - j;
                int newRowPri = aux.row - j;
                //Verifica se movimento para cima da diagonal principal é válido e cria estado sucesso
                if ((newRowPri > minPri && newColPri > minPri) && (newRowPri> -1 && newColPri > -1)) {

                    aux.row = newRowPri;
                    aux.col = newColPri;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Diag-Pri-Top-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }

                    } else {
                        minPri = aux.col;
                    }
                }

                b[i] = backup;
                aux = backup;
                newColPri = aux.col + j;
                newRowPri = aux.row + j;
                //Verifica se movimento para baixo da digagonal principal é válido e cria estado sucesso
                if ((newRowPri < maxPri && newColPri < maxPri) && (newRowPri < state.size && newColPri < state.size)) {

                    aux.row = newRowPri;
                    aux.col = newColPri;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Diag-pri-Down-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }

                    } else {
                        maxPri = aux.col;
                    }
                }

                b[i] = backup;
                aux =  backup;
                int newRowSec = aux.row - j;
                int newColSec = aux.col + j;
                //Verifica se movimento para cima da digagonal secundária é válido e cria estado sucesso
                if ((newColSec < maxSec) && newRowSec > -1 && newColSec < state.size) {

                    aux.row = newRowSec;
                    aux.col = newColSec;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Diag-Sec-Top-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
                        }

                    } else  {
                        maxSec = aux.col;
                    }
                }

                b[i] = backup;
                aux =  backup;
                newRowSec = aux.row + j;
                newColSec = aux.col - j;
                //Verifica se movimento para baixo da digagonal secundária é válido e cria estado sucesso
                if ((newColSec > minSec) && (newRowSec < state.size && newColSec > -1)) {

                    aux.row = newRowSec;
                    aux.col = newColSec;
                    //Valida posição e cria novo estado
                    if (utils.valid(aux, state.board, state.size)) {

                        b[i] = aux;
                        State next(state.size, b);
                        printf("\n------------Diag-Sec-Down-------------\n");
                        printf("Sucessor atual: \n");
                        successor.print();
                        printf("Next: \n");
                        next.print();
                        if (next.getHeuristic() < state.getHeuristic()) {
                            successor = next;
                            printf("Next\n");
                        } else {
                            printf("Atual\n");
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
