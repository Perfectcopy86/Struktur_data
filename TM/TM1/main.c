#include "header.h"

int main()
{
    int i;
    game input;

    list L;
    createList(&L);
    scanf("%s %s %s", &input.nama, &input.level, &input.asal);
    addFirst(input.nama, input.level, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.level, &input.asal);
    addFirst(input.nama, input.level, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.level, &input.asal);
    addAfter(L.first, input.nama, input.level, input.asal, &L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    scanf("%s %s %s", &input.nama, &input.level, &input.asal);
    addAfter(L.data[L.first].next, input.nama, input.level, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.level, &input.asal);
    addLast(input.nama, input.level, input.asal, &L);
    printElement(L);
    printf("--------------------\n");

    delAfter(L.data[L.first].next, &L);
    delFirst(&L);
    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    delLast(&L);
    printElement(L);
    printf("--------------------\n");

    return 0;
}