/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan UTS Struktur data (lolzat22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char kode[20];
    char name[50];
} perusahaan;

typedef struct
{
    char kode2[20];
    char zat[50];
    int bulan;
    int tahun;

} obat;

// typedef struct
// {
//     char zat2[50];
//     int bulan2;
//     int tahun2;
// } organisasi;

typedef struct eklm *alamatekolom;
typedef struct eklm
{
    obat kontainer_kol;
    alamatekolom next_kol;
} eKolom;

typedef struct ebr *alamatebaris;
typedef struct ebr
{
    perusahaan kontainer;
    eKolom *col;
    alamatebaris next;
} eBaris;

typedef struct
{
    eBaris *first;
} list;

void createList(list *L);
int countElementB(list L);
int countElementK(eBaris L);
void addFirstB(char kode[], char name[], list *L);
void addFirstK(char Kode2[], char zat[], int bulan, int tahun, eBaris *L);
void addAfterB(eBaris *prev, char kode[], char name[]);
void addAfterK(eKolom *prev, char kode2[], char zat[], int bulan, int tahun);
void addLastB(char kode[], char name[], list *L);
void addLastK(char kode2[], char zat[], int bulan, int tahun, eBaris *L);
void delFirstK(eBaris *L);
void delAfterK(eKolom *prev);
void delLastK(eBaris *L);
void delAllK(eBaris *L);
void delFirstB(list *L);
void delAfterB(eBaris *prev);
void delLastB(list *L);
void delAllB(list *L);
void printElement(list L);
void addFirstK2(char zat[], int bulan, int tahun, eBaris *L);
void addLastK2(char zat[], int bulan, int tahun, eBaris *L);
void addAfterK2(eKolom *prev, char zat[], int bulan, int tahun);
