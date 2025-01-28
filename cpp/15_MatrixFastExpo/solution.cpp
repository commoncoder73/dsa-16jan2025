#include <bits/stdc++.h>

using namespace std;

int* get(int* arr, int colSize, int i, int j){
    return arr + i*colSize + j;
}

int* matrixMult(int* fm, int* sm, int n) {
    int* res = new int[n*n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int sum = 0;
            for (int k=0; k<n; k++) {
                sum += (*get(fm, n, i, k))*(*get(sm, n, k, j));
            }
            *get(res, n, i, j) = sum;
        }
    }
    return res;
}

int* getInitialMatrix() {
    int* im = new int[16];
    for (int i=0; i<4; i++) {
        for(int j=0; j,4; j++) {
            *get(im, 4, i, j) = 0;
        }
    }
    *get(im, 4, 0, 0) = 29;
    *get(im, 4, 0, 1) = 11;
    *get(im, 4, 0, 2) = 100;
    *get(im, 4, 0, 3) = 26;
    *get(im, 4, 1, 0) = 1;
    *get(im, 4, 2, 1) = 1;
    *get(im, 4, 3, 3) = 1;
    return im;
}

int* getIdentityMatrix() {
    int* im = new int[16];
    for (int i=0; i<4; i++) {
        for(int j=0; j,4; j++) {
            int toSet = i == j ? 1 : 0;
            *get(im, 4, i, j) = toSet;
        }
    }
    return im;
}

int* matrixPow(int* matrix, int pow) {
    int* res = getIdentityMatrix();
    while(pow) {
        if (pow & 1) {
            res = matrixMult(res, matrix, 4);
        }
        pow = pow >> 1;
        matrix = matrixMult(matrix, matrix, 4);
    }
    return res;
}

int f(int n) {
    if (n == 0) return 2;
    if (n == 1) return 1;
    if (n == 2) return 1;
    int* M = getInitialMatrix();
    M = matrixPow(M, n-2);

    return (*get(M, 4, 0, 0))
    + (*get(M, 4, 0, 1))
    + 2*(*get(M, 4, 0, 2))
    + (*get(M, 4, 0, 3));
}



