#include "header.h"

void createStack(stack *S) // prosedur untuk membuat stack
{
    (*S).top = NULL; // inisialisasi pointer top dengan NULL
}

int isEmpty(stack S) // fungsi untuk cek apakah stack kosong
{
    int hasil = 0;
    if (S.top == NULL) // jika pointer top menunjuk NULL
    {
        hasil = 1; // tanda stack tsb kosong
    }
    return hasil;
}

int countElement(stack S) // fungsi untuk menghitung jumlah elemen dalam stack
{
    int hasil = 0;
    if (S.top != NULL) // jika stack tidak kosong
    {
        elemen *ptr; // deklarasi pointer
        ptr = S.top; // inisialisasi
        //
        while (ptr != NULL)
        { // menghitung hingga ditemukan NULL
            hasil++;
            ptr = ptr->next;
        }
    }
    return hasil;
}

void push(isiKontainer kontainer, stack *S) // prosedur untuk menambahkan elemen baru ke stack
{
    elemen *newPtr;                            // deklarasi pointer
    newPtr = (elemen *)malloc(sizeof(elemen)); // inisialisasi
    //
    newPtr->kontainer = kontainer; // copy data
    //
    if ((*S).top == NULL) // jika stack kosong
    {
        newPtr->next = NULL;
    }
    else // jika stack tidak kosong
    {
        newPtr->next = (*S).top;
    }
    (*S).top = newPtr;
    newPtr = NULL;
}

void pop(stack *S) // prosedur untuk mengeluarkan elemen dari stack
{
    if ((*S).top != NULL)
    {                              // jika stack tidak kosong
        elemen *hapus = (*S).top;  // inisialisasi
        if (countElement(*S) == 1) // jika elemen dalam stack hanya 1
        {
            (*S).top = NULL;
        }
        else // jika elemen dalam stack > 1
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("stack kosong\n");
    }
}

void printStack(stack S) // prosedur untuk menampilkan elemen dalam stack
{
    if (S.top != NULL) // jika stack tidak kosong
    {
        int i = 1;
        elemen *ptr = S.top; // inisialisasi
        while (ptr != NULL)  // selama elemen yang ditunjuk pointer bukan NULL
        {
            printf("%s %s\n", ptr->kontainer.nama, ptr->kontainer.bahan);
            // iterasi
            ptr = ptr->next;
            i++;
        }
    }
    else
    {
        printf("stack kosong\n");
    }
}

void popPush(stack *Sasal, stack *Stujuan)
{
    if ((*Sasal).top != NULL) // jika stack asal tidak kosong
    {
        elemen *hapus = (*Sasal).top;  // inisialisasi
        if (countElement(*Sasal) == 1) // jika elemen dalam stack hanya 1
        {
            (*Sasal).top = NULL;
        }
        else // jika elemen dalam stack > 1
        {
            (*Sasal).top = (*Sasal).top->next;
        }
        if ((*Stujuan).top == NULL) // jika stack tujuan kosong
        {
            hapus->next = NULL;
        }
        else // jika stack tidak kosong
        {
            hapus->next = (*Stujuan).top;
        }
        (*Stujuan).top = hapus;
        hapus = NULL;
    }
}

elemen *cariElemen(isiKontainer pelanggan[], stack *Sasal, int m)
{
    elemen *ptr = (*Sasal).top; // pointer penelusuran
    elemen *batas;              // pointer tanda batas
    while (ptr != NULL)         // cek sampe elemen terakhir
    {
        for (int i = 0; i < m; i++)
        {
            if (strcmp(ptr->kontainer.nama, pelanggan[i].nama) == 0)
            {
                batas = ptr;
            }
        }
        ptr = ptr->next;
    }
    return batas;
}