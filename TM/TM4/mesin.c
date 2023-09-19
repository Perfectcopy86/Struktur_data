#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L)
{
    int hasil = 0;

    if (L.first != NULL)
    {
        // list tidak kosong

        elemen *bantu;

        // inisialisasi
        bantu = L.first;

        while (bantu != NULL)
        {
            // proses
            hasil = hasil + 1;

            // iterasi
            bantu = bantu->next;
        }
    }
    return hasil;
}

void addFirst(char nama[], char nim[], char goldar[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.goldar, goldar);

    if ((*L).first == NULL)
    {
        baru->prev = NULL;
        baru->next = NULL;
        (*L).tail = baru;
    }
    else
    {
        baru->next = (*L).first;
        baru->prev = NULL;
        (*L).first->prev = baru;
    }
    (*L).first = baru;
    baru = NULL;
}

void addAfter(elemen *before, char nama[], char nim[], char goldar[], list *L)
{
    if (before != NULL)
    {
        elemen *baru;
        baru = (elemen *)malloc(sizeof(elemen));
        strcpy(baru->kontainer.nama, nama);
        strcpy(baru->kontainer.nim, nim);
        strcpy(baru->kontainer.goldar, goldar);

        if (before->next == NULL)
        {
            baru->next = NULL;
            (*L).tail = baru;
        }
        else
        {
            baru->next = before->next;
            baru->next->prev = baru;
        }
        baru->prev = before;
        before->next = baru;
        baru = NULL;
    }
}

void addBefore(elemen *before, char nama[], char nim[], char goldar[], list *L)
{
    addAfter(before->prev, nama, nim, goldar, L);
}

void addLast(char nama[], char nim[], char goldar[], list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(nama, nim, goldar, L);
    }
    else
    {
        // jika list tidak kosong
        addAfter((*L).tail, nama, nim, goldar, L);
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
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            hapus->next = NULL; // dikomen kalo masalah
        }
        free(hapus);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *hapus = before->next;
        if (hapus != NULL)
        {
            if (hapus->next == NULL)
            {
                L->tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = hapus->next;
                hapus->next->prev = before;
                hapus->next = NULL;
            }
            hapus->prev = NULL;
            free(hapus);
        }
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
            // jika banyak elemen
            delAfter((*L).tail->prev, L);
        }
    }
}

void printElemen(list L)
{
    if (L.first != NULL)
    {
        // jika list tidak kosong
        // inisialisasi
        elemen *bantu = L.first;

        while (bantu != NULL)
        {
            // proses

            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.nim, bantu->kontainer.goldar);

            // iterasi
            bantu = bantu->next;
        }
    }
    else
    {
        // proses jika list kosong
        printf("List Kosong\n");
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

void tuker(list *L)
{
    elemen *depan = (*L).first;
    elemen *belakang = (*L).tail;
    char nama[20];
    char nim[50];
    char goldar[5];
    int i;

    for (i = 0; i < countElement(*L) / 2; i++)
    {

        strcpy(nama, depan->kontainer.nama);
        strcpy(depan->kontainer.nama, belakang->kontainer.nama);
        strcpy(belakang->kontainer.nama, nama);
        depan = depan->next;
        belakang = belakang->prev;
    }
}

void printreverse(list L)
{
    if (L.first != NULL)
    {
        // inisialisasi
        elemen *bantu = L.tail;

        while (bantu != NULL)
        {
            // proses
            printf("%s %s %s\n", bantu->kontainer.nama, bantu->kontainer.nim, bantu->kontainer.goldar);

            // iterasi
            bantu = bantu->prev;
        }
    }
    else
    {
        // jika List Kosong.
        printf("List Kosong\n");
    }
}