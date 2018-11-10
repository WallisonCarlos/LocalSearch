#ifndef UTILS_H
#define UTILS_H

typedef struct Utils {

    void copy(int* vectorOne, int* vectorTwo, unsigned int size) {

        for (unsigned int i = 0;i < size;i++) {
            vectorOne[i] = vectorTwo[i];
        }

    }

} Utils;

#endif // UTILS_H
