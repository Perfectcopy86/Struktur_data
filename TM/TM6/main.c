#include "header.h"

int main()
{
    makanan input;
    stack S1;
    stack S2;

    createEmpty(&S1);
    createEmpty(&S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    pop(&S1);
    pindah_pop(&S2, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    pop(&S2);
    pindah_pop(&S1, &S2);

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    return 0;
}