#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct
{
    char kode[20];
    char nama[50];

} isiKontainerRow;

typedef struct
{
    char nama[100];
    char xat[50];
    int bulan;
    int tahun;
} isiKontainerCol;

typedef struct AddCol *alamateKolom;

typedef struct AddCol
{
    isiKontainerCol kontainerCol;
    alamateKolom nextCol;
} Column;

typedef struct AddRow *alamateBaris;

typedef struct AddRow
{
    isiKontainerRow kontainerRow;
    Column *toCol;
    alamateBaris nextRow;
} Row;

typedef struct
{
    Row *first;
} list;

void createList(list *L);
int countRowEl(list L);
int countColEl(Row Lr);
// add
void addFirstRow(isiKontainerRow kontainer, list *L);
void addFirstCol(isiKontainerCol kontainer, Row *Lr);
void addAFterRow(Row *prevRow, isiKontainerRow kontainer);
void addAfterCol(Column *prevCol, isiKontainerCol kontainer);
void addLastRow(isiKontainerRow kontainer, list *L);
void addLastCol(isiKontainerCol kontainer, Row *Lr);
// del kolom
void delFirstCol(Row *Lr);
void delAfterCol(Column *prevCol);
void delLastCol(Row *Lr);
void delAllCol(Row *Lr);
// del row
void delFirstRow(list *L);
void delAfterRow(Row *prevRow, list *L);
void delLastRow(list *L);
void delAllRow(list *L);
//
void printElement(list L);
//
Row *alamatElRow(list L, int tahun);
Column *alamatElCol(Row *Lr, char namaObat[]);
Row *alamatObat(list L, char namaObat[]);
//
Column *getLastCol(Row *Lr);
void tukarFirst(isiKontainerCol kolomBaru, Row *alamatBarisAsal, Row *alamatBarisTujuan, list *L);
void tukarAfter(isiKontainerCol kolomBaru, Row *alamatBarisAsal, Row *alamatBarisTujuan, list *L);
void sortRow(list *L);
int alamatElRowkode(list L, int tahun);
Row *alamatElRowkodetahun(list L, int tahun, Row *ptrnow);