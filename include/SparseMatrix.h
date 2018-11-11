#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

typedef struct SpaceMatrix {

    int row = 0;
    int col = 0;
    bool value = false;
    SpaceMatrix nextRow = 0;
    SpaceMatrix nextCol = 0;

    SpaceMatrix(int r, int c, bool v, SpaceMatrix nr, SpaceMatrix nc) {
        row = r;
        col = c;
        value = v;
        nextRow = nr;
        nextCol = nc;
    }

} SpaceMatrix;

#endif // SPARSEMATRIX_H
