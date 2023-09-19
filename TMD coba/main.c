/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    tree T;
    data input;
    char string[200];      // variabel menampung semua string
    char word1[200];       // variabel kata ke 1
    char word2[200];       // variabel kata ke 1
    int number3, number4;  // variabel angka ke 1 dan ke 2
    simpul *cari;          // simpul cari
    int maxLen[200] = {0}; // variabel untuk max len/ panjang kata

    int n;           // variabel untuk banyaknya inputan
    scanf("%d", &n); // masukan
    int inputan = 0; // inisialisasi
    do
    {
        scanf("%s", &string); // masukan string
        // membagi string masukan berdasarkan delimiter yaitu '#'
        pisah(string, word1, word2, &number3, &number4, '#');
        // copy kata dan angka
        strcpy(input.nama, word1);
        input.harga = number3;
        input.jumlah_komposisi = number4;
        // masukan string komposisi sesuai dengan banyaknya masukan
        for (int r = 0; r < number4; r++)
        {
            scanf("%s", &input.arr_komposisi[r]);
        }
        // kondisi jika null maka buat tree
        if (strcmp(word2, "null") == 0)
        {
            makeTree(input, &T);
        }
        // kondisi nambah anak
        else
        {
            cari = findSimpul(word2, T.root);
            addChild(input, cari);
        }
        inputan++;
    } while (inputan < n); // selama inputan belum mencapai n maka akan lanjut terus

    terpanjang(T.root, 0, maxLen); // panggil fungsi terpanjang
    int i = 1;
    do
    {
        maxLen[i] += maxLen[i - 1];
        i++;
    } while (maxLen[i + 1] != 0);
    maxLen[i] = 0;

    int hapus;           // variabel untuk hapus barang sesuai harga yg sesuai
    scanf("%d", &hapus); // masukan

    printTreePreOrder(T.root, maxLen, 0, 0); // panggil fungsi print

    delete (T.root, maxLen, 0, hapus); // panggil print yg sudah di delete

    return 0;
}