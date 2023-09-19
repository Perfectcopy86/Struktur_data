/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 2(----) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char gen[50];
    char ortu[50];

} kode;

typedef struct
{
    kode kontainer;
    int prev;
    int next;
} elemen;

typedef struct
{
    int first;
    int tail;
    elemen data[10];
} list;

void createList(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(char gen[], char tanggal[], list *L);
void addAfter(int before, char gen[], char tanggal[], list *L);
void addLast(char gen[], char tanggal[], list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElemen(list L);
void delAll(list *L);
void printreverse(list L);
void tuker(list *L, list *K, int p);
