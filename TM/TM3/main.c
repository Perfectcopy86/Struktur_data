#include "header.h"

int main()
{
    infoHewan input;
    list L;
    createList(&L);
    printf("Data Kebun Binatang\n");
    printf("===================\n");

    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addFirst(input.nama, input.tanggal, input.jumlah, &L);
    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addLast(input.nama, input.tanggal, input.jumlah, &L);
    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addAfter(L.first, input.nama, input.tanggal, input.jumlah, &L);
    printElemen(L);
    printf("===================\n");

    delAfter(L.data[L.first].next, &L);
    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addAfter(L.first, input.nama, input.tanggal, input.jumlah, &L);
    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addAfter(L.data[L.tail].prev, input.nama, input.tanggal, input.jumlah, &L);
    delFirst(&L);
    printElemen(L);
    printf("===================\n");

    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addFirst(input.nama, input.tanggal, input.jumlah, &L);
    scanf("%s %s %d", &input.nama, &input.tanggal, &input.jumlah);
    addAfter(L.data[L.first].next, input.nama, input.tanggal, input.jumlah, &L);
    delLast(&L);
    printreverse(L);
    printf("===================\n");

    delAll(&L);
    printElemen(L);

    return 0;
}