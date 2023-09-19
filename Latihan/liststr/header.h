#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char kata[50];
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
void addFirst(char kata[], list *L);
void printElemen(list L);