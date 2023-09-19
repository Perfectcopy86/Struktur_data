#include "header.h"

void createList(list *L)
{
    (*L).first = NULL;
}

int countRowEl(list L)
{
    int c = 0;
    if (L.first != NULL)
    {
        Row *ptr;
        ptr = L.first;
        //
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->nextRow;
        }
    }
    return c;
}

int countColEl(Row Lr)
{
    int c = 0;
    if (Lr.toCol != NULL)
    {
        Column *ptr;
        ptr = Lr.toCol;
        //
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->nextCol;
        }
    }
    return c;
}

// add

void addFirstRow(isiKontainerRow kontainer, list *L)
{
    Row *newPtr;
    newPtr = (Row *)malloc(sizeof(Row));
    //
    newPtr->kontainerRow = kontainer;
    //
    newPtr->toCol = NULL;
    if ((*L).first == NULL)
    {
        newPtr->nextRow = NULL;
    }
    else
    {
        newPtr->nextRow = (*L).first;
    }
    //
    (*L).first = newPtr;
    newPtr = NULL;
}

void addFirstCol(isiKontainerCol kontainer, Row *Lr)
{
    Column *newPtr;
    newPtr = (Column *)malloc(sizeof(Column));
    //
    newPtr->kontainerCol = kontainer;
    //
    if ((*Lr).toCol == NULL)
    {
        newPtr->nextCol = NULL;
    }
    else
    {
        newPtr->nextCol = (*Lr).toCol;
    }
    (*Lr).toCol = newPtr;
    newPtr = NULL;
}

void addAFterRow(Row *prevRow, isiKontainerRow kontainer)
{
    Row *newPtr;
    newPtr = (Row *)malloc(sizeof(Row));
    //
    newPtr->kontainerRow = kontainer;
    //
    newPtr->toCol = NULL;
    if (prevRow->nextRow == NULL)
    {
        newPtr->nextRow = NULL;
    }
    else
    {
        newPtr->nextRow = prevRow->nextRow;
    }
    prevRow->nextRow = newPtr;
    newPtr = NULL;
}

void addAfterCol(Column *prevCol, isiKontainerCol kontainer)
{
    Column *newPtr;
    newPtr = (Column *)malloc(sizeof(Column));
    //
    newPtr->kontainerCol = kontainer;
    //
    if (prevCol->nextCol == NULL)
    {
        newPtr->nextCol = NULL;
    }
    else
    {
        newPtr->nextCol = prevCol->nextCol;
    }
    prevCol->nextCol = newPtr;
    newPtr = NULL;
}

void addLastRow(isiKontainerRow kontainer, list *L)
{
    if ((*L).first == NULL)
    {
        addFirstRow(kontainer, L);
    }
    else
    {
        Row *last = (*L).first;
        while (last->nextRow != NULL)
        {
            last = last->nextRow;
        }
        addAFterRow(last, kontainer);
    }
}

void addLastCol(isiKontainerCol kontainer, Row *Lr)
{
    if ((*Lr).toCol == NULL)
    {
        addFirstCol(kontainer, Lr);
    }
    else
    {
        Column *last = (*Lr).toCol;
        while (last->nextCol != NULL)
        {
            last = last->nextCol;
        }
        addAfterCol(last, kontainer);
    }
}

// del kolom

void delFirstCol(Row *Lr)
{
    if ((*Lr).toCol != NULL)
    {
        Column *delPtr = (*Lr).toCol;
        if (countColEl(*Lr) == 1)
        {
            (*Lr).toCol = NULL;
        }
        else
        {
            (*Lr).toCol = (*Lr).toCol->nextCol;
            delPtr->nextCol = NULL;
        }
        free(delPtr);
    }
}

void delAfterCol(Column *prevCol)
{
    Column *delPtr = prevCol->nextCol;
    if (delPtr != NULL)
    {
        if (delPtr->nextCol == NULL)
        {
            prevCol->nextCol = NULL;
        }
        else
        {
            prevCol->nextCol = delPtr->nextCol;
            delPtr->nextCol = NULL;
        }
        free(delPtr);
    }
}

void delLastCol(Row *Lr)
{
    if ((*Lr).toCol != NULL)
    {
        if (countColEl(*Lr) == 1)
        {
            delFirstCol(Lr);
        }
        else
        {
            Column *last = (*Lr).toCol;
            Column *before_last;

            while (last->nextCol != NULL)
            {
                before_last = last;
                last = last->nextCol;
            }
            delAfterCol(before_last);
        }
    }
}

void delAllCol(Row *Lr)
{
    if (countColEl(*Lr) != 0)
    {
        for (int i = countColEl(*Lr); i >= 1; i--)
        {
            delLastCol(Lr);
        }
    }
}

// del baris
void delFirstRow(list *L)
{
    if ((*L).first != NULL)
    {
        Row *delPtr = (*L).first;

        if (delPtr->toCol != NULL)
        {
            delAllCol(delPtr);
        }
        //
        if (countRowEl(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->nextRow;
        }
        delPtr->nextRow = NULL;
        free(delPtr);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterRow(Row *prevRow, list *L)
{
    if (prevRow != NULL)
    {
        Row *delPtr = prevRow->nextRow;
        if (delPtr != NULL)
        {
            if (delPtr->toCol != NULL)
            {
                delAllCol(delPtr);
            }
            //
            if (delPtr->nextRow == NULL)
            {
                prevRow->nextRow = NULL;
            }
            else
            {
                prevRow->nextRow = delPtr->nextRow;
            }
            delPtr->nextRow = NULL;
            free(delPtr);
        }
    }
}

void delLastRow(list *L)
{
    if ((*L).first != NULL)
    {
        if (countRowEl(*L) == 1)
        {
            delFirstRow(L);
        }
        else
        {
            Row *last = (*L).first;
            Row *before_last;
            while (last->nextRow != NULL)
            {
                before_last = last;
                last = last->nextRow;
            }
            delAfterRow(before_last, L);
        }
    }
}

void delAllRow(list *L)
{
    if (countRowEl(*L) != 0)
    {
        for (int i = countRowEl(*L); i >= 1; i--)
        {
            delLastRow(L);
        }
    }
}

// print element
void printElement(list L)
{
    if (L.first != NULL)
    {
        Row *ptr = L.first;
        int i = 1;

        // while (ptr != NULL)
        // {
        //     printf("- %s %d", ptr->kontainerRow.jenis, ptr->kontainerRow.tahun);
        //     Column *eCol = ptr->toCol;
        //     while (eCol != NULL)
        //     {
        //         printf(" %s\n", eCol->kontainerCol.nama);
        //         eCol = eCol->nextCol;
        //     }
        //     printf("--------------------\n");
        //     ptr = ptr->nextRow;
        //     i += 1;
        // }
        printf("- obat keras\n");
        while (ptr != NULL)
        {
            // printf("%d", i);
            if (strcmp(ptr->kontainerRow.jenis, "keras") == 0)
            {
                printf("%d ", ptr->kontainerRow.tahun);

                Column *eCol = ptr->toCol;
                while (eCol != NULL)
                {
                    printf("%s\n", eCol->kontainerCol.nama);
                    eCol = eCol->nextCol;
                }
                i += 1;
            }
            ptr = ptr->nextRow;
        }
        ptr = L.first;
        printf("- obat ringan\n");
        while (ptr != NULL)
        {
            if (strcmp(ptr->kontainerRow.jenis, "ringan") == 0)
            {
                printf("%d ", ptr->kontainerRow.tahun);

                Column *eCol = ptr->toCol;
                while (eCol != NULL)
                {
                    printf("%s\n", eCol->kontainerCol.nama);
                    eCol = eCol->nextCol;
                }
                i += 1;
            }
            ptr = ptr->nextRow;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

Row *alamatElRow(list L, int tahun) // cari alamat baris dari tahun tertentu
{
    Row *ptrRow = L.first;
    while (ptrRow != NULL)
    {
        if (ptrRow->kontainerRow.tahun == tahun)
        {
            return ptrRow;
        }
        ptrRow = ptrRow->nextRow;
    }
    if (ptrRow == NULL)
    {
        return ptrRow;
    }
}

int alamatElRowjenis(list L, int tahun) // cari alamat baris dari tahun tertentu
{
    int cek = 0;
    Row *ptrRow = L.first;
    while (ptrRow != NULL)
    {
        if (ptrRow->kontainerRow.tahun == tahun)
        {
            if (strcmp(ptrRow->kontainerRow.jenis, "keras") == 0)
            {

                cek += 1;
            }
            else
            {
                cek += 2;
            }
        }
        ptrRow = ptrRow->nextRow;
    }

    return cek;
}

Row *alamatElRowjenistahun(list L, int tahun, Row *ptrnow) // cari alamat baris dari tahun tertentu
{
    int cek = 0;
    Row *ptrRow = L.first;
    while (ptrRow != NULL)
    {
        if (ptrRow->kontainerRow.tahun == tahun)
        {
            if (strcmp(ptrRow->kontainerRow.jenis, ptrnow->kontainerRow.jenis) != 0)
            {
                return ptrRow;
            }
        }
        ptrRow = ptrRow->nextRow;
    }

    return ptrRow;
}

Column *alamatElCol(Row *Lr, char namaObat[]) // cari alamat kolom dari nama obat tertentu
{
    Column *ptrCol = (*Lr).toCol;
    while (ptrCol != NULL)
    {
        if (strcmp(ptrCol->kontainerCol.nama, namaObat) == 0)
        {
            return ptrCol;
        }
        ptrCol = ptrCol->nextCol;
    }
}

Row *alamatObat(list L, char namaObat[]) // cari alamat kolom dari nama obat dan tahun
{

    Row *ptrRow = L.first;
    while (ptrRow != NULL)
    {
        Column *ptrCol = ptrRow->toCol;
        while (ptrCol != NULL)
        {
            if (strcmp(ptrCol->kontainerCol.nama, namaObat) == 0)
            {
                return ptrRow;
            }
            ptrCol = ptrCol->nextCol;
        }
        ptrRow = ptrRow->nextRow;
    }
}

Column *getLastCol(Row *Lr)
{ // mendapatkan alamat kolom terakhir dari suatu baris
    Column *tunjuk = (*Lr).toCol;
    Column *prev = tunjuk;
    while (tunjuk != NULL)
    {
        prev = tunjuk;
        tunjuk = tunjuk->nextCol;
    }
    return prev;
}

void tukarFirst(isiKontainerCol kolomBaru, Row *alamatBarisAsal, Row *alamatBarisTujuan, list *L)
{
    // inisialisasi pointer buat nyari baris mana yang mau dituer
    // eBaris *barissatu = getBaris(*L, labelA); // baris asal
    // eBaris *barisdua = getBaris(*L, labelB);  // baris tujuan

    // pointer buatnyari kolom awal dibaris tujuan
    // eKolom *firstKolomTokoB = barisdua->col;

    // pointer di kolom baris asal
    Column *tunjuk = alamatBarisAsal->toCol;
    Column *prev = alamatBarisAsal->toCol;
    // pointer ke kolom awal di baris tujuan
    Column *firstColTujuan = alamatBarisTujuan->toCol;

    int i = 1, ketemu = 0;
    while ((tunjuk != NULL) && (ketemu == 0))
    {
        // kondisi kalo isi kolom sama inputan sama
        if (strcmp(tunjuk->kontainerCol.nama, kolomBaru.nama) == 0 && i == 1)
        {
            // firstnya kolom di baris asal jadi tunjuk next
            // mindahin first ke nextnya
            alamatBarisAsal->toCol = tunjuk->nextCol;
            // nexttnya kolom terakhir di baris tujuan jadi tunjuk
            tunjuk->nextCol = firstColTujuan;
            alamatBarisTujuan->toCol = tunjuk;
            ketemu = 1;
        }
        else if (strcmp(tunjuk->kontainerCol.nama, kolomBaru.nama) == 0 && i != 1)
        {
            prev->nextCol = tunjuk->nextCol;
            tunjuk->nextCol = firstColTujuan;
            alamatBarisTujuan->toCol = tunjuk;
            ketemu = 1;
        }
        if (ketemu == 0)
        {
            prev = tunjuk;
            tunjuk = tunjuk->nextCol;
            i++;
        }
    }
}

void tukarAfter(isiKontainerCol kolomBaru, Row *alamatBarisAsal, Row *alamatBarisTujuan, list *L)
{
    // inisialisasi pointer buat nyari baris mana yang mau dituer
    // eBaris *barissatu = getBaris(*L, labelA); // baris asal
    // eBaris *barisdua = getBaris(*L, labelB);  // baris tujuan

    // pointer buatnyari kolom terakhir dibaris tujuan
    // eKolom *lastKolomTokoB = getLastKolom(barisdua);
    Column *lastColTujuan = getLastCol(alamatBarisTujuan);

    if (lastColTujuan == NULL)
    {
        tukarFirst(kolomBaru, alamatBarisAsal, alamatBarisTujuan, L);
    }
    else
    {
        // pointer di kolom baris asal
        Column *tunjuk = alamatBarisAsal->toCol;
        Column *prev = alamatBarisAsal->toCol;

        int i = 1, ketemu = 0;
        while ((tunjuk != NULL) && (ketemu == 0))
        {
            if (strcmp(tunjuk->kontainerCol.nama, kolomBaru.nama) == 0 && i == 1)
            {
                // firstnya kolom di baris asal jadi tunjuk next
                alamatBarisAsal->toCol = tunjuk->nextCol;
                // nexttnya kolom terakhir di baris tujuan jadi tunjuk
                lastColTujuan->nextCol = tunjuk;
                tunjuk->nextCol = NULL;
                ketemu = 1;
            }
            else if (strcmp(tunjuk->kontainerCol.nama, kolomBaru.nama) == 0 && i != 1)
            {
                prev->nextCol = tunjuk->nextCol;
                lastColTujuan->nextCol = tunjuk;
                tunjuk->nextCol = NULL;
                ketemu = 1;
            }

            if (ketemu == 0)
            {
                prev = tunjuk;
                tunjuk = tunjuk->nextCol;
                i++;
            }
        }
    }
}

void sortRow(list *L)
{
    int swap = 0;
    do
    {
        swap = 0;
        Row *prev = (*L).first;
        Row *move = (*L).first->nextRow;
        Row *temp;
        while (move != NULL)
        {

            if (prev->kontainerRow.tahun > move->kontainerRow.tahun)
            {
                if (prev == (*L).first)
                {
                    (*L).first = move;
                }
                else
                {
                    temp->nextRow = move;
                }
                prev->nextRow = move->nextRow;
                move->nextRow = prev;
                temp = move;
                move = prev->nextRow;
                swap = 1;
            }
            else
            {
                temp = prev;
                prev = prev->nextRow;
                move = prev->nextRow;
            }
        }
    } while (swap == 1);
}