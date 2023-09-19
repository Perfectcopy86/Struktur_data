/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UTS Struktur data (lolzat22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    list L;
    perusahaan perinput;
    obat obinput;

    obat temp;
    createList(&L);

    int n;
    int n2;
    scanf("%d", &n);
    eBaris *tanda = L.first;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", &perinput.kode, &perinput.name);
        addLastB(perinput.kode, perinput.name, &L);
        scanf("%d", &n2);

        if (i == 0)
            tanda = L.first;
        else
            tanda = tanda->next;

        for (int j = 0; j < n2; j++)
        {

            scanf("%s %s %d %d", &obinput.kode2, &obinput.zat, &obinput.bulan, &obinput.tahun);
            addLastK(obinput.kode2, obinput.zat, obinput.bulan, obinput.tahun, tanda);
        }
    }

    addLastB("org", "OrganisasiPengawas", &L);

    int m;
    scanf("%d", &m);
    for (int k = 0; k < m; k++)
    {
        scanf("%s %d %d", &temp.zat, &temp.bulan, &temp.tahun);
        addLastK2(temp.zat, temp.bulan, temp.tahun, tanda);
    }

    printElement(L);

    return 0;
}