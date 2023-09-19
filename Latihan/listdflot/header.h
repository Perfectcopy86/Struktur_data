#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    float angka;
} word;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    word kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(float angka, list *L);
void printElemen(list L);