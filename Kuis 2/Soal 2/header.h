/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Struktur data soal 2(qufree22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char kategori[50];
    int prioritas;
} data;
typedef struct elm *alamatelmt;
typedef struct elm
{
    data kontainer;
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
void add(char nama[], char kategori[], int prioritas, queue *Q);
void addPriority(char nama[], char kategori[], int prioritas, queue *Q);
void del(queue *Q);
void printQueue(queue Q);
void pindah(queue *Q1, queue *Q2);
void pindahverpointer(queue *Q1, queue *Q2);
