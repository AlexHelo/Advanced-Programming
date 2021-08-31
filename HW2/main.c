#include <stdio.h>
#include <stdlib.h>

#define N 10;
typedef struct  {
    void **items;
    int capacity;
    int total;
} tVector;


int main() {
    printf("Hello, World!\n");
    return 0;
}


tVector vector() {

    tVector v;

    v.capacity = N;
    v.total = 0;
    v.items = malloc(v.capacity * sizeof(void *));

    return v;
}

tVector vectorSize(size_t n){
    tVector v;

    v.capacity = n;
    v.total = 0;
    v.items = malloc(v.capacity * sizeof(void *));

    return v;
}

