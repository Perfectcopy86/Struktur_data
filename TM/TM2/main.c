#include "header.h"

int main()
{
    int i;
    tokoh input;

    list L;
    createList(&L);
    printf("--------------------\n");
    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addFirst(input.nama, input.kelamin, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addLast(input.nama, input.kelamin, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addAfter(L.first->next, input.nama, input.kelamin, input.asal, &L);

    printElemen(L);

    delAfter(L.first->next, &L);
    delFirst(&L);
    delLast(&L);
    printElemen(L);

    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addFirst(input.nama, input.kelamin, input.asal, &L);
    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addFirst(input.nama, input.kelamin, input.asal, &L);
    delLast(&L);

    printElemen(L);

    delAll(&L);
    printElemen(L);

    scanf("%s %s %s", &input.nama, &input.kelamin, &input.asal);
    addLast(input.nama, input.kelamin, input.asal, &L);
    printElemen(L);

    return 0;
}