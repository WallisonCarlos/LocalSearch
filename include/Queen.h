#ifndef QUEEN_H
#define QUEEN_H


typedef struct Queen {

    int row = 0;
    int col = 0;
    int diagPri = 0;
    int diagSec = 0;

    Queen (int r, int c) {
        row = r;
        col = c;
        diagPri = row - col;
        diagSec = row + col;
    }

} Queen;

#endif // QUEEN_H
