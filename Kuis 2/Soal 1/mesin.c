/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Struktur data soal 1() dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = -1;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(stack S)
{
    int hasil = 0;
    if (S.top == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void push(char nama[], char kurir[], char wilayah[], int berat, stack *S)
{

    if (isFull(*S) == 1)
    {
        /*jika stack penuh*/
        printf("stack penuh\n");
    }
    else
    {
        if (isEmpty(*S) == 1)
        {
            /* jika stack kosong */
            (*S).top = 0;
            strcpy((*S).data[0].nama, nama);
            strcpy((*S).data[0].kurir, kurir);
            strcpy((*S).data[0].wilayah, wilayah);
            (*S).data[0].berat = berat;
        }
        else
        {
            /* jika stack tidak kosong */
            (*S).top = (*S).top + 1;
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].kurir, kurir);
            strcpy((*S).data[(*S).top].wilayah, wilayah);
            (*S).data[(*S).top].berat = berat;
        }
    }
}

void pop(stack *S)
{

    if ((*S).top == 0)
    {
        /*jika stack berisi satu elemen*/
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            /*jika stack tidak kosong*/
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S)
{
    if (S.top != -1)
    {

        int i;
        for (i = S.top; i >= 0; i--)
        {

            printf("%s %s %s %d\n", S.data[i].nama, S.data[i].kurir, S.data[i].wilayah, S.data[i].berat);
        }
        printf("\n");
    }
    else
    {
        /* proses jika stack kosong */
        printf("stack kosong\n");
    }
}

void popPush(stack *S1, stack *S2)
{
    if (isEmpty((*S1)) == 0) // jika stack asal tidak kosong
    {
        if ((*S1).top == 0) // jika elemen hanya 1
        {
            push((*S1).data[0].nama, (*S1).data[0].kurir, (*S1).data[0].wilayah, (*S1).data[0].berat, S2); // push ke stack tujuan
            (*S1).top = -1;                                                                                // topnya di NULL in
        }
        else // jika elemen dalam stack > 1
        {
            push((*S1).data[(*S1).top].nama, (*S1).data[(*S1).top].kurir, (*S1).data[(*S1).top].wilayah, (*S1).data[(*S1).top].berat, S2); // push ke stack tujuan
            (*S1).top = (*S1).top - 1;                                                                                                     // decrement
        }
    }
}