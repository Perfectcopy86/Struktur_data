/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 1(lthobi22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char jenis[50];
    char merk[50];
    char nama[50];
} barang;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    barang kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char jenis[], char merk[], char nama[], list *L);
void addAfter(elemen *prev, char jenis[], char merk[], char nama[], list *L);
void addLast(char jenis[], char merk[], char nama[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElemen(list L);
// void tukarMenu(list *K, list *L, list *M);
