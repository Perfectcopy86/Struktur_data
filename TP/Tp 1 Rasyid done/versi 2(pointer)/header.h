/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Struktur data (KBT22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char judul[50];    // variabel untuk judul
    char produksi[50]; // variabel untuk produksi
    float rating;      // variabel untuk rating
} film;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    film kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char judul[], char produksi[], float rating, list *L);
void addAfter(elemen *prev, char judul[], char produksi[], float rating, list *L);
void addLast(char judul[], char produksi[], float rating, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElemen(list L);
void selectascjudul(list *L);  // sorting asc judul
void selectascrating(list *L); // sorting asc rating
void selectdscjudul(list *L);  // sorting dsc judul
void selectdscrating(list *L); // sorting dsc raring
