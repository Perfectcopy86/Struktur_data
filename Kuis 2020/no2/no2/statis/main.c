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
        pushPriority(data, &Q);
    }
    int m;
    scanf("%d", &m);
    printf("Bantuan Tersalurkan:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s %d %s %d\n", Q.data[Q.first].nama, Q.data[Q.first].prioritas, Q.data[Q.first].daerah, Q.data[Q.first].nominal);
        pop(&Q);
    }
    printf("\nAntrian berisi:\n");
    printQueue(Q);
    return 0;
}
