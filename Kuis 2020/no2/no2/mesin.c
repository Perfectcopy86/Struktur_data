#include "header.h"

void createQueue(queue *Q)
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

void push(isiKontainer kontainer, queue *Q)
{
    elemen *newptr;
    newptr = (elemen *)malloc(sizeof(elemen));
    newptr->kontainer = kontainer;
    newptr->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = newptr;
    }
    else
    {
        (*Q).last->next = newptr;
    }
    (*Q).last = newptr;
    newptr = NULL;
}

void pop(queue *Q)
{
    if ((*Q).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *delptr = (*Q).first;
        if (countElement(*Q) == 1)
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else
        {
            (*Q).first = (*Q).first->next;
            delptr->next = NULL;
        }

        free(delptr);
    }
}

void popPush(queue *Q1, queue *Q2)
{
    if ((*Q1).first != NULL)
    {
        /* jika queue bukan queue kosong */
        elemen *moveptr = (*Q1).first;
        if (countElement(*Q1) == 1) // kalau data di queue1 cmn 1
        {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else // kalau data di queue1 > 1
        {
            (*Q1).first = (*Q1).first->next;
            moveptr->next = NULL;
        }

        if ((*Q2).first == NULL) // queue2 nya kosong
        {
            (*Q2).first = moveptr;
        }
        else // queue2 ada isinya
        {
            (*Q2).last->next = moveptr;
        }
        (*Q2).last = moveptr;
        moveptr = NULL;
    }
}

void printQueue(queue Q)
{
    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL)
        {
            printf("%s %d %s %d\n", bantu->kontainer.nama, bantu->kontainer.prioritas, bantu->kontainer.daerah, bantu->kontainer.nominal);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

void addPriority(isiKontainer kontainer, queue *Q)
{
    elemen *newptr;
    newptr = (elemen *)malloc(sizeof(elemen));
    newptr->kontainer = kontainer;
    newptr->next = NULL;
    if ((*Q).first == NULL)
    {
        (*Q).first = newptr;
        (*Q).last = newptr;
    }
    else
    {
        if (kontainer.prioritas == 1) // kalau elemen prioriti di tambahkan di depan
        {
            newptr->next = (*Q).first;
            (*Q).first = newptr;
        }
        else if (kontainer.prioritas > countElement(*Q)) // kalau elemen prioriti di tambahkan di terakhir
        {
            (*Q).last->next = newptr;
            (*Q).last = newptr;
        }
        else // kalau elemen prioriti di tengah
        {
            elemen *bantu = (*Q).first;
            int i = 1;
            while (bantu != NULL)
            {
                if (i == (kontainer.prioritas - 1))
                {
                    newptr->next = bantu->next;
                    bantu->next = newptr;
                }
                bantu = bantu->next;
                i++;
            }
        }
    }
    newptr = NULL;
}