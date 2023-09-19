/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Soal 1 Struktur data (pbaks22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    int kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(int c, tree *T);
void addRight(int c, simpul *root);
void addLeft(int c, simpul *root);
void printTreePostOrder(simpul *root, simpul *cek);
void addkirikanan(int angka, simpul *root);
