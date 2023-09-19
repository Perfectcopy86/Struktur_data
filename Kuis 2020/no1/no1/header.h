#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct
{
    char nama[50], bahan[50];
} isiKontainer;

typedef struct
{
    int top;
    isiKontainer data[MAX];
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
void popPush(stack *Sasal, stack *Stujuan);
int cariElemen(isiKontainer pelanggan[], stack *Sasal, int m);