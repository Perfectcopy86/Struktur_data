#include "header.h"
void createList(list *L)
{
    (*L).first = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        // list tidak kosong
        int hitung;
        // inisialisasi
        hitung = L.first;
        while (hitung != -1)
        {
            // proses
            hasil = hasil + 1;
            // iterasi
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}

int emptyElement(list L)
{
    int hasil = -1;

    if (countElement(L) < 10)
    {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 10))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char nama[], char level[], char asal[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.asal, asal);

        if ((*L).first == -1)
        {
            // jika list kosong
            (*L).data[baru].next = -1;
        }
        else
        {
            // jika list tidak kosong
            (*L).data[baru].next = (*L).first;
        }

        (*L).first = baru;
    }
    else
    {
        // proses jika array penuh
        printf("sudah tidak dapat ditambahkan\n");
    }
}

void addAfter(int prev, char nama[], char level[], char asal[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.level, level);
        strcpy((*L).data[baru].kontainer.asal, asal);

        if ((*L).data[prev].next == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            (*L).data[baru].next = (*L).data[prev].next;
        }
        (*L).data[prev].next = baru;
    }
    else
    {
        // proses jika array penuh
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char nama[], char level[], char asal[], list *L)
{
    if ((*L).first == -1)
    {
        // proses jika list masih kosong
        addFirst(nama, level, asal, L);
    }
    else
    {
        // proses jika telah berisi elemen
        if (countElement(*L) < 10)
        {
            // proses jika array belum pnuh
            // proses mencari elemen terakhir
            // inisialisasi
            int prev = (*L).first;

            while ((*L).data[prev].next != -1)
            {
                // iterasi
                prev = (*L).data[prev].next;
            }
            addAfter(prev, nama, level, asal, L);
        }
        else
        {
            // proses jika array penuh
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        // elemen awal sebelumnya dikosongkan
        (*L).data[hapus].next = -2;
    }
    else
    {
        // proses jika list kosong
        printf("list kosong\n");
    }
}

void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;
    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        // pengosongan elemen
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;

            while ((*L).data[hapus].next != -1)
            {
                // iterasi
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            delAfter(prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void printElement(list L)
{
    if (L.first != -1)
    {
        // inisialisasi
        int tunjuk = L.first;
        int i = 1;
        while (tunjuk != -1)
        {
            // proses

            printf("- %s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.level, L.data[tunjuk].kontainer.asal);

            tunjuk = L.data[tunjuk].next;
            i = i + 1;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
    {
        // proses menghapus elemen list
        delLast(L);
    }
}