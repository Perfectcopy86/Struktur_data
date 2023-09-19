/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Struktur data (BPRA2) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char nama[100]; // data
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

// Prosedur dan Fungsi
void makeTree(char nama[], tree *T);           // buat tree
void addChild(char nama[], simpul *root);      // tammbah anak
void delAll(simpul *root);                     // hapus keseluruhan tree
void delChild(simpul *del, simpul *root);      // hapus anak
simpul *findSimpul(char cari[], simpul *root); // cari node
void level(int n, int hitung);                 // print output
void printTreePreOrder(simpul *root, int n);   // print node
