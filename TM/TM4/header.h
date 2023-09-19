#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char nim[50];
    char goldar[10];
} Data;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    Data kontainer;
    alamatelmt prev;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nim[], char nama[], char goldar[], list *L);
void addAfter(elemen *before, char nim[], char nama[], char goldar[], list *L);
void addBefore(elemen *before, char nim[], char nama[], char goldar[], list *L);
void addLast(char nim[], char nama[], char goldar[], list *L);
void delFirst(list *L);
void delAfter(elemen *before, list *L);
void delLast(list *L);
void delAll(list *L);
void printElemen(list L);
void tuker(list *L);
void printreverse(list L);