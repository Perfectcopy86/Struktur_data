/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 2(----) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    kode input;
    list L, K;
    createList(&L);
    createList(&K);
    int n;
    int i;
    int p;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", &input.gen, &input.ortu);
        addFirst(input.gen, input.ortu, &L);
        // scanf("%s %s", &input.gen, &input.ortu);
        // addFirst(input.gen, input.ortu, &K);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", &input.gen, &input.ortu);

        // scanf("%s %s", &input.gen, &input.ortu);
        addFirst(input.gen, input.ortu, &K);
    }
    scanf("%d", &p);
    tuker(&L, &K, p);

    printElemen(K);
    printElemen(L);

    return 0;
}