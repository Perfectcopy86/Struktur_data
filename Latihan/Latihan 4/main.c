#include "header.h"

int main()
{
    list L;
    createList(&L);
    printElemen(L);
    printf("=======================\n");

    // addFirst("1", "orang_1", "A", &L);
    // addAfter(L.first, "2", "orang_2", "A", &L);
    // addLast("3", "orang_3", "A", &L);
    // printElemen(L);
    // printf("======================\n");

    addFirst("1", "orang_1", "A", &L);
    addAfter(L.first, "2", "orang_2", "A", &L);
    addLast("3", "orang_3", "A", &L);
    // addLast("4", "orang_4", "A", &L);
    tuker(&L);
    printElemen(L);
    printf("======================\n");

    delLast(&L);
    delLast(&L);
    delAfter(L.first, &L);
    delFirst(&L);
    printElemen(L);
    printf("======================\n");

    return 0;
}