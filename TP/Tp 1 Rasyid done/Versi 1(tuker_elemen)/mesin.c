/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Struktur data (KBT22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
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

void addFirst(char judul[], char produksi[], float rating, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.produksi, produksi);
    baru->kontainer.rating = rating;

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

void addAfter(elemen *prev, char judul[], char produksi[], float rating, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.produksi, produksi);
    baru->kontainer.rating = rating;

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

void addLast(char judul[], char produksi[], float rating, list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(judul, produksi, rating, L);
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
        addAfter(prev, judul, produksi, rating, L);
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

            printf("%s - ", tunjuk->kontainer.judul);
            printf("%s\n", tunjuk->kontainer.produksi);

            // iterasi
            tunjuk = tunjuk->next;
            i = i + 1;
        }
    }
    else
    {
        // proses jika list kosong
        printf("List Kosong.\n");
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

void selectascjudul(list *L)
{
    elemen *i;
    elemen *j;
    elemen *min;
    film temp;
    // metode selection ascending
    for (i = L->first; i->next != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(i->kontainer.judul, j->kontainer.judul) > 0)
            {
                min = j;
            }
        }
        temp = min->kontainer;
        min->kontainer = i->kontainer;
        i->kontainer = temp;
    }
}

void selectascrating(list *L)
{
    elemen *i;
    elemen *j;
    elemen *min;
    film temp;
    // metode selection ascending
    for (i = L->first; i->next != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->kontainer.rating > j->kontainer.rating)
            {
                min = j;
            }
        }
        temp = min->kontainer;
        min->kontainer = i->kontainer;
        i->kontainer = temp;
    }
}

void selectdscjudul(list *L)
{
    elemen *i;
    elemen *j;
    elemen *min;
    film temp;
    // metode selection descending
    for (i = L->first; i->next != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (strcmp(i->kontainer.judul, j->kontainer.judul) < 0)
            {
                min = j;
            }
        }
        temp = min->kontainer;
        min->kontainer = i->kontainer;
        i->kontainer = temp;
    }
}

void selectdscrating(list *L)
{
    elemen *i;
    elemen *j;
    elemen *min;
    film temp;
    // metode selection ascending
    for (i = L->first; i->next != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->kontainer.rating < j->kontainer.rating)
            {
                min = j;
            }
        }
        temp = min->kontainer;
        min->kontainer = i->kontainer;
        i->kontainer = temp;
    }
}