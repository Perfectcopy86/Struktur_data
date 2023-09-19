#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[100], daerah[100];
    int nominal, prioritas;
} isiKontainer;

typedef struct elm *alamatelmt;
typedef struct elm
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createQueue(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void push(isiKontainer kontainer, queue *Q);
void pop(queue *Q);
void popPush(queue *Q1, queue *Q2);
void printQueue(queue Q);
void addPriority(isiKontainer kontainer, queue *Q);

// tc
/*
7
nani 6 bandung 350000
rohaedi 10 cicalengka 400000
darmaji 1 cilacap 250000
siti 2 garut 500000
yolanda 11 garut 500000
anik 13 garut 600000
yayat 5 tasikmalaya 500000
2
*/