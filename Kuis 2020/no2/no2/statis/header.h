#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char nama[100], daerah[100];
    int nominal, prioritas;
} isiKontainer;

typedef struct
{
    int first;
    int last;
    isiKontainer data[MAX];
} queue;

void createQueue(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void push(isiKontainer kontainer, queue *Q);
void pop(queue *Q);
void printQueue(queue Q);
void pushPriority(isiKontainer kontainer, queue *Q);