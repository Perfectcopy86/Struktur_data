#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{

    char nama[50];
    int harga;
} makanan;
typedef struct elmt *alamatelmt;
typedef struct elmt
{
    makanan kontainer;
    alamatelmt next;
} elemen;
typedef struct
{
    elemen *top;
} stack;

void createEmpty(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void printStack(stack S);
void pindah_pop(stack *S, stack *S2);
