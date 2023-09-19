/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Soal 1 Struktur data (pbaks22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"
#include "math.h"

void makeTree(int c, tree *T)
{
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(int c, simpul *root)
{
    if (root->right == NULL)
    {
        /*jika sub pohon kanan kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        root->right = baru;
    }
    else
    {
        printf("sub pohon kanan telah terisi \n");
    }
}

void addLeft(int c, simpul *root)
{
    if (root->left == NULL)
    {
        /*jika sub pohon kiri kosong*/
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->right = NULL;
        baru->left = NULL;
        root->left = baru;
    }
    else
    {
        printf("sub pohon kiri telah terisi \n");
    }
}

void printTreePostOrder(simpul *root, simpul *cek)
{

    if (root != NULL)
    {
        printTreePostOrder(root->left, cek);
        printTreePostOrder(root->right, cek);
        printf("%d", root->kontainer);
        if (root != cek)
        {
            printf(" ");
        }
    }
}

void addkirikanan(int angka, simpul *root)
{
    int hasil = angka;
    while (hasil != 1)
    {
        hasil = sqrt(root->kontainer);
        if (angka % 2 != 0)
        {
            addLeft(hasil, root);
            root = root->left;
        }
        else
        {
            addRight(hasil, root);
            root = root->right;
        }
        hasil = root->kontainer;
    }
}
