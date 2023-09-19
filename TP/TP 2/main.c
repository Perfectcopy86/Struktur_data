/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP2 Struktur data (LID22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    data input;
    list L;
    createList(&L); // buat kerangka list
    do
    {
        scanf("%s", &input.nama); // inputan
        if (strcmp(input.nama, "--stop--") != 0)
        {
            // jika masukan bukan "--stop--""
            scanf("%d", &input.tanggal); // masukkan masukan selanjutnya
            addFirst(input.nama, input.tanggal, &L);
        }
        // diulang sampai masukan bukan "--stop--""
    } while (strcmp(input.nama, "--stop--") != 0);

    sort(&L); // sorting secara ascending

    printf("==== Inventory Dapur ====\n");
    printf("List semua bahan:\n");
    printreverse(L); // print secara reverse
    printf("\n");
    printf("List bahan kadaluarsa:\n");
    hapus(&L); // menghapus data yang ada di bahan kadaluarsa
    printf("\n");
    printf("List bahan sisa:\n");
    sortname(&L); // sort berdasarkan nama
    printElemen(L);
    printf("=========================\n");

    return 0;
}