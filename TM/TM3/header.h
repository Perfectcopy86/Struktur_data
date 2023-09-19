#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[100];
    char tanggal[100];
    int jumlah;
} infoHewan;

typedef struct
{
    infoHewan kontainer;
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
void addFirst(char nama[], char tanggal[], int jumlah, list *L);
void addAfter(int before, char nama[], char tanggal[], int jumlah, list *L);
void addLast(char nama[], char tanggal[], int jumlah, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printElemen(list L);
void delAll(list *L);
void printreverse(list L);
