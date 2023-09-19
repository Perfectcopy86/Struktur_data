#include "header.h"

int main()
{
    int i, n;
    word input;
    list L;

    createList(&L);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", &input.kata);
        addFirst(input.kata, &L);
    }

    printElemen(L);

    return 0;
}