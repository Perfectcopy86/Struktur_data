/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP1 Struktur data (KBT22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    film input;
    list L;
    char sortby[10]; // variabel untuk milih sorting asc atau desc
    char jenis[10];  // variabel untuk milih sorting judul atau rating
    createList(&L);  // buat kerangka list
    do
    {
        scanf("%s", input.judul); // inputan
        if (strcmp(input.judul, "-") != 0)
        {
            // jika masukan bukan "-""
            scanf("%s %f", &input.produksi, &input.rating); // masukkan masukan selanjutnya
            addFirst(input.judul, input.produksi, input.rating, &L);
        }
        // diulang sampai masukan bukan -
    } while (strcmp(input.judul, "-") != 0);
    scanf("%s", &jenis);             // sorting by judul atau rating
    scanf("%s", &sortby);            // sorting by asc atau desc
    if (strcmp(jenis, "judul") == 0) // jika judul masuk kesini
    {
        if (strcmp(sortby, "asc") == 0)
        {
            selectascjudul(&L);         
        }
        else if (strcmp(sortby, "desc") == 0)
        {
            selectdscjudul(&L);
        }
    }
    else if (strcmp(jenis, "rating") == 0) // jika rating masuk kesini
    {
        if (strcmp(sortby, "asc") == 0)
        {
            selectascrating(&L);
        }
        else if (strcmp(sortby, "desc") == 0)
        {
            selectdscrating(&L);
        }
    }
    printElemen(L); // mencetak daftar barang setelah di urutkan
    return 0;
}