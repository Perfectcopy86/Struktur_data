/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UAS Soal 1 Struktur data (pbaks22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"
#include "math.h"
int main()
{
    tree T;
    int angka;
    int hasil;
    scanf("%d", &angka);
    makeTree(angka, &T);

    hasil = sqrt(angka);
    if (hasil % 2 != 0)
    {
        // addRight(hasil, T.root);
        addkirikanan(hasil, T.root);
        // angka = hasil;
    }
    else
    {
        // addLeft(hasil, T.root);
        addkirikanan(hasil, T.root);
        // angka = hasil;
    }
    angka = hasil;
    printTreePostOrder(T.root, T.root);
    printf("\n");
    // }

    return 0;
}