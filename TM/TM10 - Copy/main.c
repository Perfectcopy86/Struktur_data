#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);
    int i = 1;
    do
    {
        addSimpul(i, &G);
        i++;
    } while (i != 9);

    // while (i < 9)
    // {
    //     addSimpul(i, &G);
    //     i++;
    // }
    // addSimpul(1, &G);
    // addSimpul(2, &G);
    // addSimpul(3, &G);
    // addSimpul(4, &G);
    // addSimpul(5, &G);
    // addSimpul(6, &G);
    // addSimpul(7, &G);
    // addSimpul(8, &G);

    // memasukan jalur ke simpul simpul
    simpul *begin = findSimpul(3, G);
    simpul *end = findSimpul(8, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(1, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(4, G);
    end = findSimpul(2, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(5, G);
    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(6, G);
    end = findSimpul(3, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(7, G);
    end = findSimpul(4, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    begin = findSimpul(8, G);
    end = findSimpul(1, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }
    end = findSimpul(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end, 0);
    }

    printGraph(G);
    printf("==============\n");

    int hapus;
    scanf("%d", &hapus);

    begin = findSimpul(hapus, G);
    if (begin != NULL)
    {
        delSimpul(hapus, &G);
    }
    printGraph(G);
    return 0;
}
