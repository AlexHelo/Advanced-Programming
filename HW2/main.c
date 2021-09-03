#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10;

struct Node {
    struct Node * next;
    void * content;
};


struct Node * vector() {
    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
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

    for(int i = 0; i < n; i++) {
        struct Node * newNode  = (struct  Node *) malloc(sizeof (struct Node));
        newNode->next = NULL;
        newNode->content = malloc(sizeof (content));
        newNode->content = content;
        temp->next = newNode;
        temp = newNode;
    }

    return node;
}


void insert(struct Node * node, int pos, void * content) {
    struct Node * temp = node;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    struct Node * aux = temp->next;
    struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
    newNode->content = malloc(sizeof(void *));
    newNode->content = content;
    newNode->next = aux;
    temp->next = newNode;
}

struct Node * insertN(struct Node * node, int pos, size_t n, void * content) {

    struct Node * temp = node;
    if(pos == 0) {
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node *));
        newNode->content = malloc(sizeof (void *));
        newNode->content = content;
        node = newNode;
        struct Node * aux = node;
        for(int i = 0; i < n-1; i++) {
            struct Node * newNode1 = (struct Node *) malloc(sizeof (struct Node *));
            newNode1->content = malloc(sizeof (void *));
            newNode1->content = content;
            aux->next = newNode1;
            aux = aux->next;
        }
        aux->next = temp;
        return newNode;
    }

    struct Node * previous;
    for(int i = 0; i < pos; i++) {
        previous = temp;
        temp = temp->next;
    }

    for(int j = 0; j < n; j++) {
        struct Node * newNode = (struct Node *) malloc(sizeof (struct Node *));
        newNode->content = malloc(sizeof (void *));
        newNode->content = content;
        previous->next = newNode;
        previous = previous->next;
    }

    previous->next = temp;
    return node;
}

void pushBack(struct Node * node, void * content) {
    struct Node * temp = node;
    while(temp->next) {
        temp = temp->next;
    }
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->content = malloc(sizeof(void *));
    newNode->content = content;
    temp->next = newNode;
}

void popBack(struct Node * node) {
    struct Node * temp = node;
    struct Node * previous;

    while(temp->next){
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    free(previous->next);
    free(temp);
}

void printNodes(struct Node * node) {

    while(node) {
        printf("\n");
        printf(node->content);
        node = node->next;
    }

}

void freeNodes(struct Node * node) {
    while(node) {
        struct Node * temp = node;
        node = node->next;
        free(temp);

    }
}

bool empty(struct Node * node) {
    return !node;
}

int countNodes(struct Node * node) {
    struct Node * temp = node;
    int count = 0;
    while (temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    int integer = 5;
    char * string = "hola";
    char * other = "aqui";
    size_t n = 2;
    struct Node * test = vector();
    if (empty(test)){
        printf("Empty list");
    }
    printf("%d\n", countNodes(test));
    pushBack(test, string);
    printf("%d\n", countNodes(test));
    test = insertN(test, 0, 3, other);
    printf("%d\n", countNodes(test));

    printNodes(test);

    freeNodes(test);

    return 0;
}




