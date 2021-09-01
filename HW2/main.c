#include <stdio.h>
#include <stdlib.h>

#define N 10;

struct Node {
    struct Node * next;
    void * content;
};


struct Node * vector() {
    struct Node * node;
    node->next = (struct Node *) malloc(sizeof (struct Node));
    node->content = malloc(sizeof(void *));
    return node;
}


struct Node * vectorSize(size_t n) {
    struct Node * node;
    struct Node * temp = node;
    for(int i = 0; i < n; i++){
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
        newNode->content = malloc(sizeof (void *));
        temp->next = newNode;
        temp = newNode;
    }

    return node;
}

struct Node * vectorCopy(size_t n, void * content) {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->content = malloc(sizeof(void *));
    node->content = content;
    struct Node * temp = &node;

    for(int i = 0; i < n; i++){
        struct Node * newNode  = (struct  Node *) malloc(sizeof (struct Node));
        newNode->next = NULL;
        newNode->content = malloc(sizeof (content));
        newNode->content = content;
        temp->next = newNode;
        temp = newNode;
    }

    return node;
}

void printNodes(struct Node * node) {

    while(node) {
        printf(node->content,"\n");
        node = node->next;
    }

}

int main() {
    int integer = 5;
    size_t n = 2;
    struct Node * test = vectorCopy(n, (void *) integer);
    printNodes(test);

    return 0;
}




