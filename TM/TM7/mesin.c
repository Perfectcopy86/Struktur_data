#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q)
{
    int hasil = 0;
    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;

        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;

            /* iterasi */
            bantu = bantu->next;
        }
    }

    return hasil;
}

void add(char nama[], int rating, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.rating = rating;
    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void addPriority(char nama[], int rating, int priority, queue *Q)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.rating = rating;
    baru->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
        (*Q).last = baru;
    }
    else
    {
        if (priority == 1)
        {
            baru->next = (*Q).first;
            (*Q).first = baru;
        }
        else if (priority > countElement(*Q))
        {
            add(nama, rating, Q);
        }
        else
        {
            elemen *bantu = (*Q).first;
            int i = 1;
            while (bantu != NULL)
            {
                if (i == priority - 1)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    baru = NULL;
}

void del(queue *Q)
{
    if ((*Q).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *hapus = (*Q).first;
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else
        {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void pindah(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL)
    {
        elemen *hapus = (*Q1).first;
        add(hapus->kontainer.nama, hapus->kontainer.rating, Q2);
        if (countElement(*Q1) == 1)
        {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else
        {
            (*Q1).first = (*Q1).first->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void pindahverpointer(queue *Q1, queue *Q2)
{

    if (Q1->first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *hapus = Q1->first;
        if (countElement(*Q1) == 1)
        {
            Q1->first = NULL;
            Q1->last = NULL;
        }
        else
        {
            Q1->first = Q1->first->next;
            hapus->next = NULL;
        }

        if ((*Q2).first == NULL)
        {
            (*Q2).first = hapus;
        }
        else
        {
            (*Q2).last->next = hapus;
        }
        (*Q2).last = hapus;
        hapus = NULL;
    }
}

void printQueue(queue Q)
{
    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;

        while (bantu != NULL)
        {
            printf("%s ", bantu->kontainer.nama);

            printf("%d\n", bantu->kontainer.rating);

            /* iterasi */
            bantu = bantu->next;
        }
        printf("******************\n");
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}