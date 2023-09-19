#include "header.h"

int main()
{
    queue Q;
    createQueue(&Q);
    isiKontainer data;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %s %d", data.nama, &data.prioritas, data.daerah, &data.nominal);
        addPriority(data, &Q);
    }
    int m;
    scanf("%d", &m);
    printf("Bantuan Tersalurkan:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s %d %s %d\n", Q.first->kontainer.nama, Q.first->kontainer.prioritas, Q.first->kontainer.daerah, Q.first->kontainer.nominal);
        pop(&Q);
    }
    printf("\nAntrian Berisi:\n");
    printQueue(Q);

    return 0;
}