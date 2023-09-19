#include "header.h"

void createStack(stack *S) // prosedur untuk membuat stack kosong
{
    (*S).top = -1; // inisialisasi pointer top dengan -1/NULL
}

int isEmpty(stack S) // prosedur untuk cek apakah stack kosong
{
    int hasil = 0;
    if (S.top == -1) // jika pointer top menunjuk -1/NULL
    {
        hasil = 1; // tanda stack tsb kosong
    }
    return hasil;
}

int isFull(stack S) // prosedur untuk cek apakah stack penuh
{
    int hasil = 0;
    if (S.top == MAX - 1) // jika pointer top menunjuk pada 9
    {
        hasil = 1; // tanda stack tsb penuh
    }
    return hasil;
}

void push(isiKontainer kontainer, stack *S) // prosedur untuk menambahkan elemen ke dalam stack
{
    if (isFull(*S) == 1) // stack penuh jadi tidak bisa ditambahkan lagi
    {
        printf("stack penuh\n");
    }
    else // jika stack belum penuh
    {
        if (isEmpty(*S) == 1) // jika stack kosong
        {
            (*S).top = 0;
            (*S).data[0] = kontainer;
        }
        else // jika stack tidak kosong
        {
            (*S).top = (*S).top + 1;
            (*S).data[(*S).top] = kontainer;
        }
    }
}

void pop(stack *S) // prosedur untuk mengambil elemen dari stack
{
    if ((*S).top == 0) // jika stack berisi 1 elemen
    {
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1) // jika stack berisi > 1 elemen
        {
            (*S).top = (*S).top - 1;
        }
    }
}

void printStack(stack S) // prosedur untuk menampilkan isi stack
{
    if (S.top != -1) // jika stack tidak kosong
    {
        for (int i = S.top; i >= 0; i--) // menampilkan dari elemen paling baru masuk
        {
            printf("%s %s\n", S.data[i].nama, S.data[i].bahan);
        }
    }
    else
    {
        printf("stack kosong\n");
    }
}

void popPush(stack *Sasal, stack *Stujuan)
{
    if (isEmpty((*Sasal)) == 0) // jika stack asal tidak kosong
    {
        if ((*Sasal).top == 0) // jika elemen hanya 1
        {
            push((*Sasal).data[0], Stujuan); // push ke stack tujuan
            (*Sasal).top = -1;               // topnya di NULL in
        }
        else // jika elemen dalam stack > 1
        {
            push((*Sasal).data[(*Sasal).top], Stujuan); // push ke stack tujuan
            (*Sasal).top = (*Sasal).top - 1;            // decrement
        }
    }
}

int cariElemen(isiKontainer pelanggan[], stack *Sasal, int m)
{
    int batas = 0, sign = 0;
    for (int i = (*Sasal).top; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (strcmp((*Sasal).data[i].nama, pelanggan[j].nama) == 0)
            {
                batas = i;
                sign = 1;
            }
        }
    }
    if (sign == 0) // artinya gaada yg dikeluarin
    {
        batas = -1;
    }

    return batas;
}