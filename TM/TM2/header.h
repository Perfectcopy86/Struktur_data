#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char kelamin[2];
    char asal[50];
} tokoh;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    tokoh kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);
int countElement(list L);
void addFirst(char nama[], char kelamin[], char asal[], list *L);
void addAfter(elemen *prev, char nama[], char kelamin[], char asal[], list *L);
void addLast(char nama[], char kelamin[], char asal[], list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void delAll(list *L);
void printElemen(list L);
