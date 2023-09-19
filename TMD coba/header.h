/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nama[200];               // variabel untuk nama mie
    int harga;                    // variabel untuk harga
    int jumlah_komposisi;         // variabel untuk jumlah /banyaknya komposisi
    char arr_komposisi[200][200]; // variabel untuk nama komposisi
} data;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    data kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(data c, tree *T);                                                          // prosedur buat tree
void addChild(data c, simpul *root);                                                     // prosedur tambah anak
void delAll(simpul **root);                                                              // prosedur hapus semua
void delChild(simpul *del, simpul *root);                                                // prosedur hapus anak
simpul *findSimpul(char cari[], simpul *root);                                           // fungsi mencari node/simpul
void printTreePreOrder(simpul *root, int depth[], int n, int *tanda);                    // print pre order
void terpanjang(simpul *root, int depth, int len[]);                                     // cari kata terpanjang
int totalDigit(int num);                                                                 // total digit
void delete (simpul *root, int depth[], int n, int hapus);                               // prosedur hapus sesuai harga atau syarat
void pisah(char str[], char kata1[], char kata2[], int *num, int *num2, char delimiter); // prosedur memisah string dengan delimyer '#'