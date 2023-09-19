/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP3 Struktur data (PKL22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    // deklarasi stack
    stack S;  // stack semua jenis musik
    stack S2; // stack untuk rock
    stack S3; // stack untuk pop
    // membuat stack kosong
    createEmpty(&S);
    createEmpty(&S2);
    createEmpty(&S3);
    musik input;

    int n = 0;       // variabel untuk jumlah masukan
    scanf("%d", &n); // inputan
    for (int i = 0; i < n; i++)
    {

        scanf("%d %s %s", &input.tahun, &input.judul, &input.nama); // inputan

        push(input.tahun, input.judul, input.nama, &S); // melakukan push ke stack semua jenis musik
    }

    Pindah_Stack(&S, &S2, &S3); // panggil fungsi pindah stack sesuai syarat
    // keluaran sesuai syarat
    printf("Playlist Musik Rock:\n");
    printf("===================\n");
    printStackRock(S2);
    printf("\n");
    printf("Playlist Musik Pop:\n");
    printf("===================\n");
    printStackPop(S3);
    return 0;
}