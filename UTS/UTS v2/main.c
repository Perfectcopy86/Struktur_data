#include "header.h"

int main()
{
    list llist;
    isiKontainerRow dataObat;
    isiKontainerCol namaObat;
    createList(&llist);
    //
    int n;
    scanf("%d", &n);
    Row *tanda = llist.first;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s", dataObat.jenis, &dataObat.tahun, namaObat.nama);
        addLastRow(dataObat, &llist);
        if (i == 0)
            tanda = llist.first;
        else
            tanda = tanda->nextRow;
        addLastCol(namaObat, tanda);
    }

    isiKontainerRow tahunBaru;
    isiKontainerCol tukarObat;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s %d", tukarObat.nama, &tahunBaru.tahun);
        Row *cekTahun = alamatElRow(llist, tahunBaru.tahun);  // cek tahunnya ada atau ngga
        Row *ptrRow = alamatObat(llist, tukarObat.nama);      // baris asal
        Column *ptrCol = alamatElCol(ptrRow, tukarObat.nama); // kolom asal
        char temp[20];
        // printf("> %d\n", alamatElRowjenis(llist, tahunBaru.tahun));
        strcpy(temp, ptrRow->kontainerRow.jenis);
        if (cekTahun == NULL)
        { // kalau tahunnya gaada, masukin elemen baris baru
            // ini buat nyari nama obat yang sama
            // kalau misal nama obatnya sama, bikin baris baru dan masukin jenis yang berbeda
            if (strcmp(ptrRow->kontainerRow.jenis, "ringan") == 0)
            {
                strcpy(tahunBaru.jenis, "keras");
                addLastRow(tahunBaru, &llist);
                Row *ptrNewRow = alamatElRow(llist, tahunBaru.tahun); // baris tujuan
                Column *ptrNewCol = ptrNewRow->toCol;                 // kolom tujuan
                tukarAfter(tukarObat, ptrRow, ptrNewRow, &llist);
            }
            else
            {
                strcpy(tahunBaru.jenis, "ringan");
                addLastRow(tahunBaru, &llist);
                Row *ptrNewRow = alamatElRow(llist, tahunBaru.tahun); // baris tujuan
                Column *ptrNewCol = ptrNewRow->toCol;                 // kolom tujuan
                tukarAfter(tukarObat, ptrRow, ptrNewRow, &llist);
            }
        }

        else if (cekTahun != NULL && alamatElRowjenis(llist, tahunBaru.tahun) == 1)
        {

            strcpy(tahunBaru.jenis, "ringan");
            addLastRow(tahunBaru, &llist);
            Row *ptrNewRow = alamatElRow(llist, tahunBaru.tahun); // baris tujuan
            Column *ptrNewCol = ptrNewRow->toCol;                 // kolom tujuan
            tukarAfter(tukarObat, ptrRow, ptrNewRow, &llist);
        }
        else if (cekTahun != NULL && alamatElRowjenis(llist, tahunBaru.tahun) == 2)
        {
            strcpy(tahunBaru.jenis, "keras");
            addLastRow(tahunBaru, &llist);
            Row *ptrNewRow = alamatElRow(llist, tahunBaru.tahun); // baris tujuan
            Column *ptrNewCol = ptrNewRow->toCol;                 // kolom tujuan
            tukarAfter(tukarObat, ptrRow, ptrNewRow, &llist);
        }
        else if (cekTahun != NULL && alamatElRowjenis(llist, tahunBaru.tahun) == 3)
        {
            Row *ptrNewRow = alamatElRowjenistahun(llist, tahunBaru.tahun, ptrRow);

            // dipindahin ke tahun yang jenisnya ringan
            tukarAfter(tukarObat, ptrRow, ptrNewRow, &llist);
        }
    }

    Row *cekBaris = llist.first;
    Row *prev = cekBaris;
    int i = 0, sign = 0;
    while (cekBaris != NULL)
    {
        sign = 0;
        if (cekBaris->toCol == NULL)
        {
            sign = 1;
            if (i == 0)
            {
                delFirstRow(&llist);
            }
            else
            {
                cekBaris = cekBaris->nextRow;
                delAfterRow(prev, &llist);
            }
        }
        // printElement(llist);
        if (sign == 0)
        {
            prev = cekBaris;
            cekBaris = cekBaris->nextRow;
        }
        i++;
    }
    sortRow(&llist);
    printElement(llist);

    return 0;
}