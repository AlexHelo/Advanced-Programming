#include <stdio.h>
#include <stdlib.h>

 struct tVector {
    void **items;
    int capacity;
    int total;
} ;


int main() {
    printf("Hello, World!\n");
    return 0;
}


struct tVector vector(){
    struct tVector v;

    struct v *capacity = 0;
    struct v *total = 0;
    struct v *items = malloc(sizeof(void *) * v.capacity);

    return v;
}

struct tVector vectorSize(size_t n){
    struct tVector v;

    struct v *capacity = n;
    struct v *total = 0;
    struct v *items = malloc(sizeof(void *) * v.capacity);

    return v;
}

