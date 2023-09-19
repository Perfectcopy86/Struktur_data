#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatKul;
typedef struct
{
    int first;
    int last;
    nilaiMatKul data[100];
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
void add(char nim[], char nama[], float nilai, queue *Q);
void del(queue *Q);
void del2(queue *Q1, queue *Q2);
void printQueue(queue Q, char Queue[]);
void printQueue(queue Q);