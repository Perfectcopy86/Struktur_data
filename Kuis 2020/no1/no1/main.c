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
        int start;
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
    // solve
    for (int i = 0; i < n; i++) // perulangan stack
    {
        int batas = cariElemen(pelanggan, &s[i], m); // ngecek doang ada elemen yg dicari atau ngga
        if (batas != -1)                             // cek ada pelanggan yg keluar
        {
            for (int j = s[i].top; j >= batas; j--) // perulangan elemen dalam stack
            {
                int sign = 0;               // tanda element tsb adalah elemen yg di cari atau bukan
                for (int k = 0; k < m; k++) // perulangan untuk pelanggan
                {
                    if (strcmp(s[i].data[j].nama, pelanggan[k].nama) == 0 && sign == 0) // jika elemen di stack merupakan elemen yg dicari maka akan di pop
                    {
                        sign = 1;
                        pop(&s[i]);
                    }
                }
                if (sign == 0) // jika elemen tersebut tidak ada di daftar yg di cari maka di push ke batas stack
                {
                    popPush(&s[i], &temp[i]);
                }
            }
        }
    }

    // output
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