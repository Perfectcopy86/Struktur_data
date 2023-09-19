/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan kuis 2 Struktur data soal 1() dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char kurir[50];
    char wilayah[50];
    int berat;
} paket;

typedef struct
{
    int top;
    paket data[100];
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(char nama[], char kurir[], char wilayah[], int berat, stack *S);
void pop(stack *S);
void printStack(stack S);
void popPush(stack *Sasal, stack *Stujuan);
