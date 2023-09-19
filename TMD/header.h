/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nama[50];
    int nilai;
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data daerah;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(data d, tree *T);                                                 // membuat tree
void addChild(data d, simpul *root);                                            // menambah anak
simpul *findSimpul(char cari[], simpul *root);                                  // mencari node
void printTreePreOrder(simpul *root, int n, int len[]);                         // mencetak tree
void explode(char str[], char first[], char second[], int *num, char splitter); // memecah string
int hitungKorban(simpul *root);                                                 // menghitung jumlah korban
void maxLenName(simpul *root, int n, int len[]);                                // mencari nama daerah terpanjang
int totalDigit(int num);                                                        // menghitung jumlah digit