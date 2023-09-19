#include "header.h"

int main()
{

    Data input;
    list L;
    createList(&L);
    printf("Data Golongan Darah\n");
    printf("===================\n");
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addLast(input.nama, input.nim, input.goldar, &L);
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addFirst(input.nama, input.nim, input.goldar, &L);
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addBefore(L.first->next, input.nama, input.nim, input.goldar, &L);
    printElemen(L);
    printf("===================\n");

    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addAfter(L.first->next, input.nama, input.nim, input.goldar, &L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addAfter(L.first, input.nama, input.nim, input.goldar, &L);
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addBefore(L.tail, input.nama, input.nim, input.goldar, &L);
    delFirst(&L);
    printElemen(L);
    printf("===================\n");

    delLast(&L);
    delAfter(L.first, &L);
    scanf("%s %s %s", &input.nama, &input.nim, &input.goldar);
    addLast(input.nama, input.nim, input.goldar, &L);
    printreverse(L);
    printf("===================\n");

    delAll(&L);
    printElemen(L);

    return 0;
}