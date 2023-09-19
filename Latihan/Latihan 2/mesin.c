#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        // list tidak kosong

        elemen *tunjuk;

        // inisialisasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            // proses
            hasil = hasil + 1;

            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    return hasil;
}

void addFirst(char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *prev, char nim[], char nama[], char nilai[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void addLast(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(nim, nama, nilai, L);
    }
    else
    {
        // jika list tidak kosong
        // mencari elemen terakhir list
        elemen *prev = (*L).first;
        while (prev->next != NULL)
        {
            // iterasi
            prev = prev->next;
        }
        addAfter(prev, nim, nama, nilai, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list bukan list kosong
        elemen *hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delAfter(elemen *prev, list *L)
{
    elemen *hapus = prev->next;
    if (hapus != NULL)
    {
        if (hapus->next == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika list tidak kosong
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            // mencari elemen terakhir list
            elemen *last = (*L).first;
            elemen *prev;
            while (last->next != NULL)
            {
                // iterasi
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void printElemen(list L)
{
    if (L.first != NULL)
    {
        // jika list tidak kosong
        // inisialisasi
        elemen *tunjuk = L.first;
        int i = 1;
        while (tunjuk != NULL)
        {
            // proses
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", tunjuk->kontainer.nim);
            printf("nama : %s\n", tunjuk->kontainer.nama);
            printf("nilai : %s\n", tunjuk->kontainer.nilai);
            printf("------------\n");
            // iterasi
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    }
    else
    {
        // proses jika list kosong
        printf("list kosong\n");
    }
}

void delAll(list *L)
{
    if (countElement(*L) != 0)
    {
        int i;

        for (i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}