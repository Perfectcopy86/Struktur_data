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

void addFirst(float angka, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    baru->kontainer.angka = angka;

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
            printf("%.2f\n", tunjuk->kontainer.angka);
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
