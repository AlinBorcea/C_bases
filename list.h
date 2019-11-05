#include <stdio.h>
#include <stdlib.h>

struct node {
    char val;
    struct node *next;
};

struct list {
    int val;
    int base;
    struct node *bin;
    struct list *next;
};

struct node *newNode(char val) {
    struct node *p = 0;
    p = (struct node*) malloc(sizeof(struct node));
    p->val = val;
    p->next = 0;
    return p;
}

struct list *newListNode(int val, int base) {
    struct list *p = 0;
    p = (struct list*) malloc(sizeof(struct list));
    p->val = val;
    p->base = base;
    p->bin = 0;
    p->next = 0;
    return p;
}

struct node *lastNode(struct node *first) {
    while (first->next)
        first = first->next;

    return first;
}

struct list *lastList(struct list *first) {
    while (first->next)
        first = first->next;

    return first;
}

void addNode(struct node *first, struct node *p) {
    lastNode(first)->next = p;
}

void addList(struct list *first, struct list *p) {
    lastList(first)->next = p;
}
