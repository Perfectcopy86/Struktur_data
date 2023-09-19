/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 1(----) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    barang input;
    list L, K, M, menuSwap;
    createList(&L), createList(&K), createList(&M);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", &input.jenis, &input.merk, &input.nama);
        // addLast(input.jenis, input.merk, input.nama, &L);
        if (strcmp(input.jenis, "action_figure") == 0)
        {
            addFirst(input.jenis, input.merk, input.nama, &L);
        }
        else if (strcmp(input.jenis, "sepatu") == 0)
        {
            addFirst(input.jenis, input.merk, input.nama, &K);
        }
        else if (strcmp(input.jenis, "sepeda") == 0)
        {
            addFirst(input.jenis, input.merk, input.nama, &M);
        }
    }
    // tukarMenu(&L, &K, &menuSwap);

    printElemen(L);

    printElemen(K);
    printElemen(M);

    return 0;
}