#include "header.h"

void createEmpty(queue *Q)
{
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q)
{
    int hasil = 0;
    if (Q.first == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q)
{
    int hasil = 0;
    if (Q.last == 9)
    {
        hasil = 1;
    }
    return hasil;
}

void add(char nim[], char nama[], float nilai, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    }

    else
    {
        /* jika queue tidak kosong */
        if (isFull(*Q) != 1)
        {
            (*Q).last = (*Q).last + 1;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

// void addPriority(char nim[], char nama[], int priority, queue *Q)
// {
//     if (isEmpty(*Q) == 1)
//     {
//         (*Q).first = 0;
//         (*Q).last = 0;
//         strcpy((*Q).data[0].nim, nim);
//         strcpy((*Q).data[0].nama, nama);
//         (*Q).data[0].priority = priority;
//     }
//     else
//     {
//         if (isFull(*Q) != 1)
//         {
//             if (priority > countElement(*Q))
//             {
//                 add(nim, nama, Q);
//             }
//             else
//             {
//                 (*Q).last++;
//                 if (priority > 0)
//                 {
//                     for (int i = (*Q).last - 1; i >= priority - 1; i--)
//                     {
//                         strcpy((*Q).data[i + 1].nim, (*Q).data[i].nim);
//                         strcpy((*Q).data[i + 1].nama, (*Q).data[i].nama);
//                     }
//                     strcpy((*Q).data[priority - 1].nim, nim);
//                     strcpy((*Q).data[priority - 1].nama, nama);
//                     (*Q).data[priority - 1].priority = priority;
//                 }
//             }
//         }
//         else
//         {
//             printf("queue penuh\n");
//         }
//     }
// }

void del2(queue *Q1, queue *Q2)
{
    add((*Q1).data[(*Q1).first].nim, (*Q1).data[(*Q1).first].nama, (*Q1).data[(*Q1).first].nilai, Q2);
    if ((*Q1).last == 0)
    {
        (*Q1).first = -1;
        (*Q1).last = -1;
    }
    else
    {
        int i = 0;
        for (i = ((*Q1).first + 1); i <= (*Q1).last; i++)
        {
            strcpy((*Q1).data[i - 1].nim, (*Q1).data[i].nim);
            strcpy((*Q1).data[i - 1].nama, (*Q1).data[i].nama);
        }
        (*Q1).last--;
    }
}

void del(queue *Q)
{
    if ((*Q).last == 0)
    {
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else
    {
        /*menggeser elemen ke depan*/
        int i;
        for (i = ((*Q).first + 1); i <= (*Q).last; i++)
        {
            strcpy((*Q).data[i - 1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i - 1].nama, (*Q).data[i].nama);
            (*Q).data[i - 1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last = (*Q).last - 1;
    }
}

void printQueue(queue Q)
{
    if (Q.first != -1)
    {
        printf("------isi queue------\n");
        int i;
        for (i = Q.last; i >= Q.first; i--)
        {
            printf("====================\n");
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", Q.data[i].nim);
            printf("nama : %s\n", Q.data[i].nama);
            printf("nilai : %f\n", Q.data[i].nilai);
        }
        printf("---------------------\n");
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}