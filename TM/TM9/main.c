#include "header.h"

int main()
{
    tree T;
    data input;
    scanf("%s %d", input.nama, &input.nilai);
    makeTree(input.nama, input.nilai, &T);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root->child);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root->child);

    printf("Step 1:\n");
    printf("================\n");
    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    delChild(T.root->child->child->sibling, T.root->child);

    printTreePreOrder(T.root, T.root);
    printf("\n");
    printTreePostOrder(T.root, T.root);
    printf("\n");

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root->child->sibling);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root->child->sibling);

    scanf("%s %d", input.nama, &input.nilai);
    addChild(input.nama, input.nilai, T.root->child->sibling->sibling);

    printTreePreOrder(T.root, T.root);
    printf("\n");
    printf("Step 2:\n");
    printf("================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak Sama\n");
    }
    printf("Step 3:\n");
    printf("================\n");

    char cari[20];
    scanf("%s", &cari);
    simpul *find1 = findSimpul(cari, T.root->child->child);
    if (find1 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }
    simpul *find2 = findSimpul(cari, T.root->child->sibling);
    if (find2 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }
    simpul *find3 = findSimpul(cari, T.root);
    if (find3 != NULL)
    {
        printf("%s ditemukan\n", cari);
    }
    else
    {
        printf("%s tidak ditemukan\n", cari);
    }
    return 0;
}