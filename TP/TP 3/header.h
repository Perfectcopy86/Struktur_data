/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP3 Struktur data (PKL22) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    int tahun;      // variabel tahun
    char judul[50]; // variabel judul lagu
    char nama[50];  // variabel band atau penyanyi
} musik;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    musik kontainer;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(int tahun, char judul[], char nama[], stack *S);
void pop(stack *S);
void printStackRock(stack S);                       // print stack rock
void printStackPop(stack S);                        // print stack pop
void Pindah_Stack(stack *S1, stack *S2, stack *S3); // fungsi pindah stack
