#include <stdio.h>
#include "list.h"

struct list *readNumbers(struct list *first);
void printNumbers(struct list *first);
struct list *popNums(struct list *first);
struct node *numBin(struct list *p);
void printBins(struct list *first);

int main() {
    struct list *first = 0;
    first = readNumbers(first);
    first = popNums(first);
    printBins(first);

    return 0;
}

struct list *popNums(struct list *first) {
    for (struct list *p = first; p; p = p->next) 
        p->bin = numBin(p);
    
    return first;
}

struct node *numBin(struct list *p) {
    struct node *bin = 0;
    int x = p->val;
    int base = p->base;

    bin = newNode(x % base + 48);
    x /= base;

    while (x / base) {
        addNode(bin, newNode(x % base + 48));
        x /= base;
    }

    addNode(bin, newNode(x % base + 48));
    return bin;
}

void printBins(struct list *first) {
    for (struct list *p = first; p; p = p->next) {
        printf("%d in base %d\n", p->val, p->base);
        for (struct node *q = p->bin; q; q = q->next)
            printf("%c ",q->val);
        printf("\n");
    }
}

struct list *readNumbers(struct list *first) {
    int n, val, base;

    printf("n = "); scanf("%d", &n);

    printf("0:\nval = "); scanf("%d", &val);
    printf("base = "); scanf("%d", &base);
    first = newListNode(val, base);

    for (int i = 1; i < n; i++) {
        printf("%d:\nval = ", i); scanf("%d", &val);
        printf("base = "); scanf("%d", &base);
        addList(first, newListNode(val, base));
    }

    return first;
}

void printNumbers(struct list *first) {
    for (struct list *p = first; p; p = p->next)
        printf("val = %d - base = %d\n", p->val, p->base);

    printf("\n");
}
