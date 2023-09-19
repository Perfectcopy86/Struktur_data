#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    int rating;
} game;
typedef struct elm *alamatelmt;
typedef struct elm
{
    game kontainer;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void add(char nama[], int rating, queue *Q);
void addPriority(char nama[], int rating, int priority, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void pindah(queue *Q1, queue *Q2);
void pindahverpointer(queue *Q1, queue *Q2);
