/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP2 Struktur data (LID22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50]; // variabel untuk nama bahan
    int tanggal;   // variabel untuk tanggal kadaluarsa
} data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    data kontainer;
    alamatelmt prev;
    alamatelmt next;

} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], int tanggal, list *L);
void addLast(char nama[], int tanggal, list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void printElemen(list L);
void printreverse(list L); // prosedur print secara reverse
void sort(list *L);        // prosedur sorting asc tanggal kadaluarsa
void hapus(list *L);       // prosedur hapus data yang ada di bahan kadaluarsa
void sortname(list *L);    // prosedur sorting asc nama bahan