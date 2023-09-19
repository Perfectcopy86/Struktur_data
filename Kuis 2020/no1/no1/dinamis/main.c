#include "header.h"

int main()
{
    isiKontainer data; // membuat tampungan data masukan
    int n;
    scanf("%d", &n);
    stack s[n], temp[n]; // deklarasi stack
    for (int i = 0; i < n; i++)
    {
        createStack(&s[i]); // membuat stack kosong
        createStack(&temp[i]);
        int start, end;
        scanf("%d", &start);
        if (start == 1)
        {
            scanf("%s", data.nama);
            if (strcmp(data.nama, "0") != 0)
            {
                while (strcmp(data.nama, "0") != 0)
                {
                    scanf("%s", data.bahan);
                    push(data, &s[i]);
                    scanf("%s", data.nama);
                }
            }
        }
    }
    int m;
    scanf("%d", &m);
    isiKontainer pelanggan[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", pelanggan[i].nama);
    }

    for (int i = 0; i < n; i++) // perulangan stack
    {
        elemen *batas = cariElemen(pelanggan, &s[i], m); // cari batas elemen pelanggan di dalam stack
        if (batas != NULL)                               // cek pointer batas
        {
            while (s[i].top != batas)
            { // sampe ketemu pointer batas
                int sign = 0;
                for (int j = 0; j < m; j++) // cek pelanggan yg bahannya dikeluaran
                {
                    if (strcmp(s[i].top->kontainer.nama, pelanggan[j].nama) == 0 && sign == 0) // cek nama pelanggan yg dikeluarin
                    {
                        // printf("pop\n");
                        sign = 1;
                        pop(&s[i]);
                        // s[i].top = s[i].top->next;
                    }
                }
                if (sign == 0) // kalau nama pelanggannya bukan yg di cari, masukin ke batas stack
                {
                    // printf("poppush\n");
                    popPush(&s[i], &temp[i]);
                    // printf("%s\n", s[i].top->kontainer.nama);
                }
            }
            if (s[i].top == batas) // cek nama pelanggan yg dikeluarin
            {
                pop(&s[i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("Stack %d:\n", i + 1);
        printStack(s[i]);
        printf("\n");
    }

    for (int i = n - 1; i >= 0; i--)
    {
        printf("batas stack %d:\n", i + 1);
        printStack(temp[i]);
    }

    return 0;
}

/*
3
1
panji linen
diah linen
tya linen
0
1
diah jean
dera jean
tina jean
nata jean
dara jean
0
1
dera katun
dina katun
panji katun
nata katun
dara katun
0
2
panji
dera
*/

/*
2
1
diana jean
rudi jean
tiara jean
santuy jean
lapi jean
0
1
dimana katun
harus katun
kucari katun
santuy katun
tapi katun
nggak katun
0
3
tiara
kucari
tapi
*/