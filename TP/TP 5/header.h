/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP5 Struktur data (TCI222) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct jlr *alamatjalur;
typedef struct smp
{
    char kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul;

typedef struct jlr
{
    int kontainer_jalur;
    alamatjalur next_jalur;
    simpul *tujuan;
} jalur;

typedef struct
{
    simpul *first;
} graph;

void createEmpty(graph *G);                                                             // membuat graph
void addSimpul(char c, graph *G);                                                       // nambah simpul
void addJalur(simpul *awal, simpul *tujuan, int beban);                                 // nambah jalur
simpul *findSimpul(char c, graph G);                                                    // cari simpul
void printGraph(graph G);                                                               // print graph
void search(char cawal, char ctujuan, simpul *awal, int beban, char path[], int index); // mencari jalan
void keep_route_awal(char c);                                                           // print char source