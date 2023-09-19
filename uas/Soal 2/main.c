/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Soal 2 Struktur data (grtjm22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP5 Struktur data (TCI222) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    graph G;
    createEmpty(&G); // buat graph
    char start;      // char source
    char finish;     // char destination
    int i = 0;
    int buat_jalur = 0;       // variabel untuk masukan jalur sebanyak n
    int beban;                // variabel cost
    scanf("%d", &buat_jalur); // masukan banyak jalur

    do
    {
        scanf(" %c %c %d", &start, &finish, &beban); // masukan source, destination, cost
        simpul *begin;
        simpul *end;

        begin = findSimpul(start, G);
        end = findSimpul(finish, G);
        if (begin == NULL) // jika belum ada maka add simpul sesuai inputan source
        {
            addSimpul(start, &G); // add simpul
            begin = findSimpul(start, G);
        }

        if (end == NULL) // jika belum ada maka add simpul sesuai inputan destination
        {
            addSimpul(finish, &G); // add simpul
            end = findSimpul(finish, G);
        }

        // menambah jalur
        if ((begin != NULL) && (end != NULL))
        {
            addJalur(begin, end, beban);
        }

        i++;                   // iterasi
    } while (i != buat_jalur); // selama i tidak sama dengan inputan buat jalur

    char awal;   // variabel awal node
    char tujuan; // variabel tujuan node
    char path[150];
    int panjang[100];                // variabel tampungan
    scanf(" %c %c", &awal, &tujuan); // masukan
    simpul *mulai = findSimpul(awal, G);

    search(awal, tujuan, mulai, 0, path, 0, panjang); // mencari jalur dan print jalur serta cost

    return 0;
}