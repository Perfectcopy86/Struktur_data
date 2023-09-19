/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP2 Struktur data (LID22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
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

void addFirst(char nama[], int tanggal, list *L)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.tanggal = tanggal;

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
            hapus->next = NULL;
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
            if (bantu->kontainer.tanggal > 9)
            {

                printf("%d %s\n", bantu->kontainer.tanggal, bantu->kontainer.nama);
            }
            else
            {
                printf("0%d %s\n", bantu->kontainer.tanggal, bantu->kontainer.nama);
            }
            // iterasi
            bantu = bantu->next;
        }
    }
    else
    {
        // proses jika list kosong
        printf("-\n");
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
            if (bantu->kontainer.tanggal > 9)
            {

                printf("%d %s\n", bantu->kontainer.tanggal, bantu->kontainer.nama);
            }
            else
            {
                printf("0%d %s\n", bantu->kontainer.tanggal, bantu->kontainer.nama);
            }

            // iterasi
            bantu = bantu->prev;
        }
    }
    else
    {
        // jika List Kosong.
        printf("-\n");
    }
}

void sort(list *L)
{
    elemen *current, *nextone; // membuat pointer baru
    int i, j;
    if (countElement(*L) == 2) // jika hanya terdapat dua elemen dalam list
    {
        // proses menukar pointernya
        if ((*L).first->kontainer.tanggal > (*L).tail->kontainer.tanggal) // jika elemen awal lebih besar dari elemen akhir
        {

            (*L).tail->next = (*L).first;
            (*L).first->next = NULL;
            (*L).first->prev = (*L).tail;
            (*L).tail->prev = NULL;
            (*L).first = (*L).tail;
            (*L).tail = (*L).first->next;
        }
    }
    else
    {

        for (i = 0; i < countElement(*L); i++) // jika terdapat lebih dari dua elemen
        {
            current = (*L).first; // L.first ditandai dengan current
            for (j = 0; j < countElement(*L) - 1 - i; j++)
            {
                // jika elemen yang ditunjuk besar dari elemen setelahnya
                if (current->kontainer.tanggal > current->next->kontainer.tanggal)
                {
                    nextone = current->next;   // nextone ditandai dengan next nya si current
                    if (current == (*L).first) // jika current berada di L.first maka prosesnya seperti yang dibawah
                    {

                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = NULL;
                        current->prev = nextone;
                        current->next->prev = current;
                        (*L).first = nextone;
                        current = nextone;
                    }
                    else if (nextone->next != NULL) // menukar pointer ketika nextone->next tidak null
                    {
                        current->prev->next = nextone;
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        current->next->prev = current;
                        current = nextone;
                    }
                    else if (nextone == (*L).tail) // menukar pointer ketika nextone berada di tail
                    {
                        current->prev->next = nextone;
                        nextone->next = nextone->prev;
                        current->next = NULL;
                        current->prev = current->prev->next;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        (*L).tail = current;
                    }
                }

                current = current->next;
            }
        }
    }
}

void sortname(list *L)
{
    elemen *current, *nextone; // membuat pointer baru
    int i, j;
    if (countElement(*L) == 2) // jika hanya terdapat dua elemen dalam list
    {
        // proses menukar pointernya
        if (strcmp((*L).first->kontainer.nama, (*L).tail->kontainer.nama) > 0)
        {

            (*L).tail->next = (*L).first;
            (*L).first->next = NULL;
            (*L).first->prev = (*L).tail;
            (*L).tail->prev = NULL;
            (*L).first = (*L).tail;
            (*L).tail = (*L).first->next;
        }
    }
    else
    {

        for (i = 0; i < countElement(*L); i++)
        {
            current = (*L).first;
            for (j = 0; j < countElement(*L) - 1 - i; j++)
            {
                // jika elemen yang ditunjuk urutan abjad nya lebih akhir dari elemen setelahnya
                if (strcmp(current->kontainer.nama, current->next->kontainer.nama) > 0)
                {
                    nextone = current->next;   // nextone ditandai dengan next nya si current
                    if (current == (*L).first) // jika current berada di L.first maka prosesnya seperti yang dibawah
                    {
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = NULL;
                        current->prev = nextone;
                        current->next->prev = current;
                        (*L).first = nextone;
                        current = nextone;
                    }
                    else if (nextone->next != NULL) // menukar pointer ketika nextone->next tidak null
                    {
                        current->prev->next = nextone;
                        current->next = nextone->next;
                        nextone->next = current;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        current->next->prev = current;
                        current = nextone;
                    }
                    else if (nextone == (*L).tail) // menukar pointer ketika nextone berada di tail
                    {
                        current->prev->next = nextone;
                        nextone->next = nextone->prev;
                        current->next = NULL;
                        current->prev = current->prev->next;
                        nextone->prev = current->prev;
                        current->prev = nextone;
                        (*L).tail = current;
                    }
                }

                current = current->next;
            }
        }
    }
}

void hapus(list *L)
{
    elemen *current, *nextone;
    current = (*L).tail;          // tail dimasukan kedalam current agar pengecekan dimulai dari belakang
    int batas = countElement(*L); // countelement dimasukkan ke batas karena jika countelemen dimasukkan ke for akan berubah lantaran adanya proses penghapusan

    for (int i = 0; i < batas; i++)
    {

        if (current->kontainer.tanggal < 9) // jika tanggal kurang dari sembilan maka akan masuk ke list kadaluarsa
        {

            printf("0%d %s\n", current->kontainer.tanggal, current->kontainer.nama); // keluaran
            if (current != (*L).first)                                               // jika current bukan di L.first pointer akan mundur lalu melakukan del after
            {

                current = current->prev;
                delAfter(current, L);
            }
            else if (current == (*L).first) // jika current berada di L.first maka akan melakukan del first
            {
                delFirst(L);
            }
        }
        else
        {
            current = current->prev; // jika tanggal > 9 , maka pointer akan melewati data tersebut
        }
    }
    if (countElement(*L) == batas) // jika list kadaluarsa kosong
    {
        printf("-\n");
    }
}
