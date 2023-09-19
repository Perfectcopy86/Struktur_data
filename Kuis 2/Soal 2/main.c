/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Struktur data soal 2(qufree22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    queue Q;         // membuat variabel queue
    createEmpty(&Q); // create empty queue
    data input;      // masukan
    int n;
    scanf("%d", &n); // masukan jumlah elemen queue
    for (int i = 0; i < n; i++)
    {
        // masukan
        scanf("%s%s%d", &input.nama, &input.kategori, &input.prioritas);
        // menambahkan masukan elemen ke queue
        addPriority(input.nama, input.kategori, input.prioritas, &Q);
    }
    int m;           // variabel untuk pekerjaan sudah selesai
    scanf("%d", &m); // masukan
    printf("pekerjaan yang telah selesai:\n");

    for (int i = 0; i < m; i++)
    {
        printf("%s %s %d\n", Q.first->kontainer.nama, Q.first->kontainer.kategori, Q.first->kontainer.prioritas);
        del(&Q); // dibuang karena sudah tidak dibutuhkan
    }
    printf("\n");
    printf("pekerjaan yang masih menanti:\n");
    printQueue(Q); // print sisa queue

    return 0;
}
