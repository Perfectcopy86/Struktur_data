/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    tree T;
    data tParent, tChild;
    int maxLen[50] = {0}; // inisialisasi seluruh nilai array ke nol
    int n = 0, m = 0;
    char str[250];
    simpul *nodeRoot;

    // meminta masukan jumlah daerah/simpul
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // meminta masukan query daerah parent, daerah child, jumlah nilai
        // dipisahkan oleh karakter #
        scanf("%s", str);
        // memecah string masukan berdasarkan karakter pemisah
        explode(str, tParent.nama, tChild.nama, &tChild.nilai, '#');

        if (strcmp(tParent.nama, "null") == 0)
        {
            // jika parent nya null, maka itu root teratas
            // untuk membuat tree
            makeTree(tChild, &T);
        }
        else
        {
            // jika parent nya bukan null, cari parent nya
            nodeRoot = findSimpul(tParent.nama, T.root);
            // tambahkan simpul anaknya
            addChild(tChild, nodeRoot);
        }
    }
    return 0;
}