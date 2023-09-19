#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nim[10];
    char nama[50];
    float nilai;
} nilaiMatKul;
typedef struct elm *alamatelmt;
typedef struct elm
{
    nilaiMatKul kontainer;
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
void add(char nim[], char nama[], float nilai, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
