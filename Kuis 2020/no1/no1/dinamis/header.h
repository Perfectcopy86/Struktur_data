#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50], bahan[50];
} isiKontainer;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
void popPush(stack *Sasal, stack *Stujuan);
elemen *cariElemen(isiKontainer pelanggan[], stack *Sasal, int m);