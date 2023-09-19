/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Struktur data soal 1() dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    stack(S);
    stack S2[30];
    stack S3;
    createEmpty(&S3);
    createEmpty(&S);
    paket input;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s %s %s %d", &input.nama, &input.kurir, &input.wilayah, &input.berat);
        push(input.nama, input.kurir, input.wilayah, input.berat, &S);
    }

    int jumstack;
    scanf("%d", &jumstack);
    char cek[jumstack][50];
    char cek2[10][100];
    for (i = 0; i < jumstack; i++)
    {
        createEmpty(&S2[i]);

        scanf("%s", &cek[i]);
    }

    // for (i = 0; i < jumstack; i++)
    // {
    //     printf("%s\n", cek[i]);
    //     printStack(S2[i]);
    // }

    for (i = 0; i < n; i++)
    {
        if (strcmp(S.data[i].kurir, cek[i]) == 0)
        {
            for (i = 0; i < jumstack; i++)
            {
                popPush(&S, &S2[i]);
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (strcmp(S.data[i].kurir, cek[i]) == 0)
        {
            for (i = jumstack; i >= 0; i++)
            {
                popPush(&S, &S2[i]);
            }
        }
    }

    for (i = 0; i < jumstack; i++)
    {
        printf("stack %s:\n", cek[i]);
        printStack(S2[i]);
    }

    // printStack(S);

    // for (i = 0; i < n; i++)
    // {
    //     if (strcmp((S.data[i].kurir), cek[i]) == 0)
    //     {
    //         popPush(&S, &S2[i]);
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printStack(S2[i]);
    // }

    return 0;
}