#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[200];
    int nilai;
    int jmlh_komponen;
    char arr_komponen[200][200];
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

void makeTree(data c, tree *T);
void addChild(data c, simpul *root);
void delAll(simpul **root);
// void delChild(data c, simpul *root);
void delChild(simpul *del, simpul *root);
simpul *findSimpul(char cari[], simpul *root);
void printTreePreOrder(simpul *root, int depth[], int n);
void printTreePostOrder(simpul *root, int n);
void maxLenName(simpul *root, int n, int len[]);
int totalDigit(int num);
// void delete (simpul *root, int depth[], int n, int harga_hapus);
void delete2(simpul *root, int depth[], int n, int harga_hapus);