#include "header.h"

int main()
{
    tree T;
    data dataStr;
    char temp[200];
    char kata1[200];
    char kata2[200];
    char kata3[20];
    char kata4[20];
    char komponen[200];
    int angka3, angka4;
    simpul *find;
    int n;
    int j;
    int idx1, idx2, batas = 0;
    int maxLen[50] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &temp);
        idx1 = 0;
        while (temp[idx1] != '#')
        {
            kata1[idx1] = temp[idx1];
            idx1++;
        }
        kata1[idx1] = '\0';
        idx1++;
        idx2 = 0;
        while (temp[idx1] != '#')
        {
            kata2[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata2[idx2] = '\0';

        idx1++;
        idx2 = 0;
        while (temp[idx1] != '#')
        {
            kata3[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata3[idx2] = '\0';
        angka3 = 0;
        for (int k = 0; kata3[k] != '\0'; ++k)
        {
            angka3 = angka3 * 10 + kata3[k] - '0';
        }

        idx1++;
        idx2 = 0;
        while (temp[idx1] != '\0')
        {
            kata4[idx2] = temp[idx1];
            idx2++;
            idx1++;
        }
        kata4[idx2] = '\0';
        angka4 = 0;
        for (int k = 0; kata4[k] != '\0'; ++k)
        {
            angka4 = angka4 * 10 + kata4[k] - '0';
        }
        strcpy(dataStr.nama, kata1);
        dataStr.nilai = angka3;
        dataStr.jmlh_komponen = angka4;
        for (int l = 0; l < angka4; l++)
        {
            scanf("%s", &dataStr.arr_komponen[l]);
        }
        // printf("%s - %s - %d -%d\n", kata1, kata2, angka3, angka4);
        if (strcmp(kata2, "null") == 0)
        {
            makeTree(dataStr, &T);
        }
        else
        {
            find = findSimpul(kata2, T.root);
            addChild(dataStr, find);
        }
    }

    maxLenName(T.root, 0, maxLen);
    int i = 1;
    while (maxLen[i + 1] != 0)
    {
        maxLen[i] += maxLen[i - 1];
        i++;
    }
    maxLen[i] = 0;

    int harga_hapus;
    scanf("%d", &harga_hapus);

    printf("isi lengkap:\n");
    printTreePreOrder(T.root, maxLen, 0);

    delete2(T.root, maxLen, 0, harga_hapus);

    // printTreePreOrder(T.root, maxLen, 0);

    return 0;
}