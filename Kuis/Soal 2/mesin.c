/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 2(----) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createList(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 10; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        // list tidak kosong
        int bantu;

        // inisialisasi
        bantu = L.first;

        while (bantu != -1)
        {
            // proses
            hasil = hasil + 1;

            // iterasi
            bantu = L.data[bantu].next;
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

void addFirst(char gen[], char ortu[], list *L)
{
    if (countElement(*L) < 10)
    {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.gen, gen);
        strcpy((*L).data[baru].kontainer.ortu, ortu);

        if ((*L).first == -1)
        {
            // jika List Kosong.
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
        else
        {
            // jika list tidak kosong
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }
        (*L).first = baru;
    }
    else
    {
        // proses jika array penuh
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char gen[], char ortu[], list *L)
{
    if (before != -1)
    {
        if (countElement(*L) < 10)
        {
            int baru = emptyElement(*L);
            strcpy((*L).data[baru].kontainer.gen, gen);
            strcpy((*L).data[baru].kontainer.ortu, ortu);

            if ((*L).data[before].next != -1)
            {
                // jika baru bukan menjadi elemen terakhir
                (*L).data[baru].prev = before;
                (*L).data[baru].next = (*L).data[before].next;
                (*L).data[before].next = baru;
                (*L).data[(*L).data[baru].next].prev = baru;
            }
            else
            {
                // jika baru menjadi elemen terakhir
                (*L).data[baru].prev = before;
                (*L).data[before].next = baru;
                (*L).data[baru].next = -1;
                (*L).tail = baru;
            }
        }
        else
        {
            // proses jika array penuh
            printf("sudah tidak dapat ditambah\n");
        }
    }
}

void addLast(char gen[], char ortu[], list *L)
{
    if ((*L).first == -1)
    {
        // jika list masih kosong
        addFirst(gen, ortu, L);
    }
    else
    {
        // proses jika list telah berisi elemen
        addAfter((*L).tail, gen, ortu, L);
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
            (*L).tail = -1;
        }
        else
        {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = 1;
        }

        // elemen awal sebelumnya dikosongkan
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        // proses jika List Kosong.
        printf("List Kosong.\n");
    }
}

void delAfter(int before, list *L)
{
    int hapus = (*L).data[before].next;
    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).tail = before;
            (*L).data[before].next = -1;
        }
        else
        {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }

        // pengosongan elemen
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            // proses jika list hanya berisi satu elemen
            delFirst(L);
        }
        else
        {
            // elemen sebelum elemen terakhir menjadi elemen terakhir
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        // proses jika List Kosong.
        printf("List Kosong.\n");
    }
}

void printElemen(list L)
{
    if (L.first != -1)
    {
        // inisialisasi
        int bantu = L.first;

        while (bantu != -1)
        {
            // proses
            printf("%s %s\n", L.data[bantu].kontainer.gen, L.data[bantu].kontainer.ortu);

            // iterasi
            bantu = L.data[bantu].next;
        }
    }
    else
    {
        // jika List Kosong.
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

void printreverse(list L)
{
    if (L.first != -1)
    {
        // inisialisasi
        int bantu = L.tail;

        while (bantu != -1)
        {
            // proses
            printf("%s %s\n", L.data[bantu].kontainer.gen, L.data[bantu].kontainer.ortu);

            // iterasi
            bantu = L.data[bantu].prev;
        }
    }
    else
    {
        // jika List Kosong.
        printf("List Kosong.\n");
    }
}

void tuker(list *L, list *K, int p)
{
    int i;
    int j;

    int depan = (*L).first;
    int belakang = (*L).tail;
    char gen[50];
    char ortu[50];

    for (i = 0; i < countElement(*L) / 2; i++)
    {
        strcpy(gen, (*L).data[depan].kontainer.gen);
        strcpy((*L).data[depan].kontainer.gen, (*L).data[belakang].kontainer.gen);
        strcpy((*L).data[belakang].kontainer.gen, gen);

        strcpy(ortu, (*L).data[depan].kontainer.ortu);
        strcpy((*L).data[depan].kontainer.ortu, (*L).data[belakang].kontainer.ortu);
        strcpy((*L).data[belakang].kontainer.ortu, ortu);

        //     strcpy(ortu, (*L).data[depan].kontainer.ortu);
        //     strcpy((*L).data[depan].kontainer.ortu, (*L).data[belakang].kontainer.ortu);
        //     strcpy((*L).data[belakang].kontainer.ortu, ortu);
        depan = (*L).data[depan].next;
        belakang = (*L).data[belakang].prev;

        //     strcpy(gen, (*K).data[depan].kontainer.gen);
        //     strcpy((*K).data[depan].kontainer.gen, (*K).data[belakang].kontainer.gen);
        //     strcpy((*K).data[belakang].kontainer.gen, gen);

        //     strcpy(ortu, (*K).data[depan].kontainer.ortu);
        //     strcpy((*K).data[depan].kontainer.ortu, (*K).data[belakang].kontainer.ortu);
        //     strcpy((*K).data[belakang].kontainer.ortu, ortu);
        //     depan = (*K).data[depan].next;
        //     belakang = (*K).data[belakang].prev;
    }

    int depan2 = (*K).first;
    int belakang2 = (*K).tail;

    for (i = 0; i < countElement(*K) / 2; i++)
    {
        strcpy(gen, (*K).data[depan2].kontainer.gen);
        strcpy((*K).data[depan2].kontainer.gen, (*K).data[belakang2].kontainer.gen);
        strcpy((*K).data[belakang2].kontainer.gen, gen);

        strcpy(ortu, (*K).data[depan2].kontainer.ortu);
        strcpy((*K).data[depan2].kontainer.ortu, (*K).data[belakang2].kontainer.ortu);
        strcpy((*K).data[belakang2].kontainer.ortu, ortu);
        depan2 = (*K).data[depan2].next;
        belakang2 = (*K).data[belakang2].prev;
    }
}
