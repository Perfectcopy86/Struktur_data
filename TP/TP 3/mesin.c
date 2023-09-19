/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP3 Struktur data (PKL22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

void createEmpty(stack *S)
{
    (*S).top = NULL;
}

int isEmpty(stack S)
{
    int hasil = 0;
    if (S.top == NULL)
    {
        hasil = 1;
    }
    return hasil;
}

int countElement(stack S)
{

    int hasil = 0;

    if (S.top != NULL)
    {
        /* stack tidak kosong */

        elemen *bantu;

        /* inisialisasi */
        bantu = S.top;

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

void push(int tahun, char judul[], char nama[], stack *S)
{
    elemen *baru;
    baru = (elemen *)malloc(sizeof(elemen));
    baru->kontainer.tahun = tahun;
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.nama, nama);

    if ((*S).top == NULL)
    {
        // jika stack kosong
        baru->next = NULL;
    }
    else
    {
        // jika stack tidak kosong
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    if ((*S).top != NULL)
    {
        /*jika stack bukan list kosong*/
        elemen *hapus = (*S).top;
        if (countElement(*S) == 1)
        {
            (*S).top = NULL;
        }
        else
        {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);
    }
    else
    {
        printf("- Stack Kosong");
    }
}

void printStackRock(stack S)
{

    if (S.top != NULL)
    {

        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {

            printf("%d. %s\n", i, bantu->kontainer.judul); // keluaran
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("BUKAN ANAK ROCK!\n");
    }
}

void printStackPop(stack S)
{

    if (S.top != NULL)
    {

        elemen *bantu = S.top;

        int i = 1;

        while (bantu != NULL)
        {

            printf("%d. %s\n", i, bantu->kontainer.judul); // keluaran
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
    else
    {
        /* proses jika stack kosong */
        printf("BUKAN ANAK POP!\n");
    }
}

void Pindah_Stack(stack *S1, stack *S2, stack *S3)
{
    if (isEmpty(*S1) == 0)
    {
        // jika stack tidak kosong
        elemen *tunjuk = (*S1).top;
        while (tunjuk != NULL)
        {
            // proses memindahkan stack
            // menghitung ascii judul
            int count = 0; // variabel untuk hitung jumlah huruf
            for (int i = 0; i < strlen(tunjuk->kontainer.judul); i++)
            {
                // menyimpan jumlah ASCII
                count = count + tunjuk->kontainer.judul[i];
            }
            // jika total ascii genap, isi pindah ke stack rock
            if (count % 2 == 0)
            {
                // melakukan push ke stack rock
                push(tunjuk->kontainer.tahun, tunjuk->kontainer.judul, tunjuk->kontainer.nama, S2);
            }
            // jika total ascii ganjil, isi pindah ke stack pop
            else
            {
                // melakukan push ke stack pop
                push(tunjuk->kontainer.tahun, tunjuk->kontainer.judul, tunjuk->kontainer.nama, S3);
            }
            tunjuk = tunjuk->next;
        }
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}