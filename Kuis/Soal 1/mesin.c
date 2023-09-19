/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 1 Struktur data soal 1(----) dalam mata kuliah Struktur data
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

void addFirst(char jenis[], char merk[], char nama[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.nama, nama);

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

void addAfter(elemen *prev, char jenis[], char merk[], char nama[], list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.jenis, jenis);
    strcpy(baru->kontainer.merk, merk);
    strcpy(baru->kontainer.nama, nama);

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

void addLast(char jenis[], char merk[], char nama[], list *L)
{
    if ((*L).first == NULL)
    {
        // jika list adalah list kosong
        addFirst(jenis, merk, nama, L);
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
        addAfter(prev, jenis, merk, nama, L);
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

            printf("%s ", tunjuk->kontainer.jenis);
            printf("%s ", tunjuk->kontainer.merk);
            printf("%s\n", tunjuk->kontainer.nama);

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

// void tukarMenu(list *K, list *L, list *M)
// {
//     if (countElement(*L) != 0)
//     {
//         elemen *m = M->first;
//         while (m != NULL)
//         {
//             elemen *k = K->first;
//             elemen *prevK;
//             while (k != NULL)
//             {
//                 if (strcmp(k->kontainer.jenis, m->kontainer.jenis) == 0)
//                 {
//                     elemen *l = L->first;
//                     elemen *prevL;
//                     while (l != NULL && k != NULL)
//                     {
//                         if (strcmp(l->kontainer.jenis, m->kontainer.merk) == 0)
//                         {
//                             addLast(k->kontainer.jenis, k->kontainer.merk, m->kontainer.nama, L);
//                             addLast(l->kontainer.jenis, l->kontainer.merk, m->kontainer.nama, K);
//                             if (k == K->first)
//                             {
//                                 delFirst(K);
//                             }
//                             else if (k->next != NULL)
//                             {
//                                 delAfter(prevK, K);
//                             }
//                             else
//                             {
//                                 delLast(K);
//                                 break;
//                             }
//                             if (l == L->first)
//                             {
//                                 delFirst(L);
//                             }
//                             else if (l->next != NULL)
//                             {
//                                 delAfter(prevL, L);
//                             }
//                             else
//                             {
//                                 delLast(L);
//                                 break;
//                             }
//                         }
//                         if (l != NULL)
//                         {
//                             prevL = l;
//                             l = l->next;
//                         }
//                     }
//                 }
//                 else if (strcmp(k->kontainer.jenis, m->kontainer.merk) == 0)
//                 {
//                     elemen *l = L->first;
//                     elemen *prevL;
//                     while (l != NULL && k != NULL)
//                     {
//                         if (strcmp(l->kontainer.jenis, m->kontainer.nama) == 0)
//                         {
//                             addLast(k->kontainer.jenis, k->kontainer.merk, m->kontainer.nama, L);
//                             addLast(l->kontainer.jenis, l->kontainer.merk, m->kontainer.nama, K);

//                             if (k == K->first)
//                             {
//                                 delFirst(K);
//                             }
//                             else if (k->next != NULL)
//                             {
//                                 delAfter(prevK, K);
//                             }
//                             else
//                             {
//                                 delLast(K);
//                                 break;
//                             }
//                             if (l == L->first)
//                             {
//                                 delFirst(L);
//                             }
//                             else if (l->next != NULL)
//                             {
//                                 delAfter(prevL, L);
//                             }
//                             else
//                             {
//                                 delLast(L);
//                                 break;
//                             }
//                         }
//                         prevL = l;
//                         l = l->next;
//                     }
//                 }
//                 prevK = k;
//                 k = k->next;
//             }
//             m = m->next;
//         }
//     }
// }

// /* prosedur menukar elemen */
// void swap(elemen *a, elemen *b)
// {
//     // tukar elemen yg ditunjuk oleh pointer a dan b
//     barang temp = a->kontainer;
//     a->kontainer = b->kontainer;
//     b->kontainer = temp;
// }