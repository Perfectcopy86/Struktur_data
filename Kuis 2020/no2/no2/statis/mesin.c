#include "header.h"

void createQueue(queue *Q)
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
    if (Q.last == MAX - 1)
    {
        hasil = 1;
    }
    return hasil;
}

void push(isiKontainer kontainer, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = kontainer;
    }
    else
    {
        /* jika queue tidak kosong */
        if (isFull(*Q) != 1)
        {
            (*Q).last = (*Q).last + 1;
            (*Q).data[(*Q).last] = kontainer;
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

void pop(queue *Q)
{
    if ((*Q).last == 0) // jika elemen hanya 1
    {
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else // jika elemen ada > 1
    {
        /*menggeser elemen ke depan*/
        int i;
        for (i = ((*Q).first + 1); i <= (*Q).last; i++)
        {
            (*Q).data[i - 1] = (*Q).data[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

void printQueue(queue Q)
{
    if (Q.first != -1)
    {
        int i;
        for (i = Q.first; i <= Q.last; i++)
        {
            printf("%s %d %s %d\n", Q.data[i].nama, Q.data[i].prioritas, Q.data[i].daerah, Q.data[i].nominal);
        }
    }
    else
    {
        /* proses jika queue kosong */
        printf("queue kosong\n");
    }
}

void pushPriority(isiKontainer kontainer, queue *Q)
{
    if (isEmpty(*Q) == 1)
    {
        /* jika queue kosong */
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).data[0] = kontainer;
    }
    else
    {
        if (isFull(*Q) != 1)
        {
            // (*Q).last = (*Q).last + 1;
            // (*Q).data[(*Q).last] = kontainer;
            if (kontainer.prioritas == 1) // jadi elemen pertama
            {
                // geser semua elemen ke kanan
                for (int i = (*Q).last; i >= (*Q).first; i--)
                {
                    (*Q).data[i + 1] = (*Q).data[i];
                }
                // copy data masukan
                (*Q).data[(*Q).first] = kontainer;
                (*Q).last = (*Q).last + 1;
            }
            else if (kontainer.prioritas > (*Q).last) // jika elemen di simpan di terakhir
            {
                (*Q).last = (*Q).last + 1;
                (*Q).data[(*Q).last] = kontainer;
            }
            else
            {
                int bantu = (*Q).last;
                for (int i = (*Q).last; i >= kontainer.prioritas - 1; i--)
                {
                    (*Q).data[i + 1] = (*Q).data[i];
                }
                (*Q).data[kontainer.prioritas - 1] = kontainer;
                (*Q).last = (*Q).last + 1;
            }
        }
    }
}