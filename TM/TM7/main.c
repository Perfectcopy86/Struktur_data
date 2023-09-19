#include "header.h"

int main()
{
    queue Q;
    queue Q2;
    createEmpty(&Q);
    createEmpty(&Q2);

    game input;

    scanf("%s %d", &input.nama, &input.rating);
    add(input.nama, input.rating, &Q);

    scanf("%s %d", &input.nama, &input.rating);
    add(input.nama, input.rating, &Q);

    scanf("%s %d", &input.nama, &input.rating);
    addPriority(input.nama, input.rating, 2, &Q);
    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q);

    pindahverpointer(&Q, &Q2);

    printf("Queue 1\n");
    printQueue(Q);

    printf("Queue 2\n");
    printQueue(Q2);

    scanf("%s %d", &input.nama, &input.rating);
    addPriority(input.nama, input.rating, 1, &Q);

    scanf("%s %d", &input.nama, &input.rating);
    addPriority(input.nama, input.rating, 99, &Q);

    printf("Queue 1\n");
    printQueue(Q);

    pindahverpointer(&Q, &Q2);
    pindahverpointer(&Q, &Q2);

    scanf("%s %d", &input.nama, &input.rating);
    add(input.nama, input.rating, &Q);

    printf("Queue 1\n");
    printQueue(Q);

    printf("Queue 2\n");
    printQueue(Q2);
}