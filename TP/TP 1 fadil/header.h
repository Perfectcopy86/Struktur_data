// Tugas Praktikum
// (KBT22) Kisah Baru Techi

/* 
Saya Muhammad Fadhillah Nursyawal NIM 2107135 mengerjakan Evaluasi TP1
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
    char judul[100], produk[100];
    float rating;
}nilaiMatkul;

typedef struct elmt* alamatelmt;
typedef struct elmt{
    nilaiMatkul kontainer;
    alamatelmt next;
}elemen;

typedef struct{
    elemen* first;
}list;

void createList(list *L);

void addLast(char judul[], char produk[], float rating, list *L);

void printElement(list L);

void swapPoint(elemen* temp, elemen* prev, elemen* prev2, list *L);

void shortingJudul(char jenis[], list *L);
void shortingRating(char jenis[], list *L);
