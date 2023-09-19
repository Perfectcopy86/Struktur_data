#include "header.h"

void makeTree(data c, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer.nama, c.nama);
    node->kontainer.jmlh_komponen = c.jmlh_komponen;
    for (int i = 0; i < c.jmlh_komponen; i++)
    {
        strcpy(node->kontainer.arr_komponen[i], c.arr_komponen[i]);
        // printf("%s\n",node->kontainer.arr_komponen[i]);
    }
    node->kontainer.nilai = c.nilai;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data c, simpul *root)
{
    if (root != NULL)
    {
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->kontainer.nama, c.nama);
        baru->kontainer.jmlh_komponen = c.jmlh_komponen;
        baru->kontainer.nilai = c.nilai;
        for (int i = 0; i < c.jmlh_komponen; i++)
        {
            strcpy(baru->kontainer.arr_komponen[i], c.arr_komponen[i]);
            // printf("%s\n",baru->kontainer.arr_komponen[i]);
        }
        baru->child = NULL;

        if (root->child == NULL)
        {
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul **root)
{
    if ((*root) != NULL)
    {
        if ((*root)->child != NULL)
        {
            if ((*root)->child->sibling == NULL)
            {
                delAll(&(*root)->child);
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = (*root)->child;
                while (bantu->sibling != (*root)->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(&proses);
                }
                delAll(&bantu);
            }
            free((*root)->child);
            (*root)->child = NULL;
        }
        free(*root);
        *root = NULL;
    }
}

void delChild(simpul *del, simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                if ((root->child == del))
                {
                    delAll(&root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                simpul *prev = NULL;
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (hapus == del)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && (hapus == del))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child))
                        {
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(&hapus);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul *findSimpul(char cari[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if ((strcmp(root->kontainer.nama, cari) == 0))
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    if ((strcmp(bantu->kontainer.nama, cari) == 0))
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(cari, bantu);
                    }
                }
                else
                {
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if ((strcmp(bantu->kontainer.nama, cari) == 0))
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(cari, bantu);
                            bantu = bantu->sibling;
                            if (hasil != 0)
                            {
                                ketemu = 1;
                            }
                        }
                    }
                    if (ketemu == 0)
                    {
                        if ((strcmp(bantu->kontainer.nama, cari) == 0))
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(cari, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printTreePreOrder(simpul *root, int depth[], int n)
{
    if (root != NULL)
    {
        printf("\n");
        if (n > 0)
        {
            // spasi di cetak jika bukan mencetak root paling atas
            // atau jika level kedalaman tree > 0
            for (int i = 0; i < depth[n - 1]; i++)
            {
                // cetak spasi sebanyak nilai pada array panjang string
                printf(" ");
            }
        }
        printf("|%s %d\n", root->kontainer.nama, root->kontainer.nilai);
        for (int i = 0; i < root->kontainer.jmlh_komponen; i++)
        {
            if (n > 0)
            {
                // spasi di cetak jika bukan mencetak root paling atas
                // atau jika level kedalaman tree > 0
                for (int i = 0; i < depth[n - 1]; i++)
                {
                    // cetak spasi sebanyak nilai pada array panjang string
                    printf(" ");
                }
            }
            printf("- %s\n", root->kontainer.arr_komponen[i]);
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                n++;
                printTreePreOrder(bantu, depth, n);
                n--;
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    n++;
                    printTreePreOrder(bantu, depth, n);
                    n--;
                    bantu = bantu->sibling;
                }
                n++;
                printTreePreOrder(bantu, depth, n);
                n--;
            }
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

void delete2(simpul *root, int depth[], int n, int harga_hapus)
{
    if (root != NULL)
    {
        if (root->kontainer.nilai >= harga_hapus)
        {
            printf("\n");
            if (n > 0)
            {
                // spasi di cetak jika bukan mencetak root paling atas
                // atau jika level kedalaman tree > 0
                for (int i = 0; i < depth[n - 1]; i++)
                {
                    // cetak spasi sebanyak nilai pada array panjang string
                    printf(" ");
                }
            }
            printf("|%s %d\n", root->kontainer.nama, root->kontainer.nilai);
            for (int i = 0; i < root->kontainer.jmlh_komponen; i++)
            {
                if (n > 0)
                {
                    // spasi di cetak jika bukan mencetak root paling atas
                    // atau jika level kedalaman tree > 0
                    for (int i = 0; i < depth[n - 1]; i++)
                    {
                        // cetak spasi sebanyak nilai pada array panjang string
                        printf(" ");
                    }
                }
                printf("- %s\n", root->kontainer.arr_komponen[i]);
            }
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    n++;
                    delete2(bantu, depth, n, harga_hapus);
                    n--;
                }
                else
                {
                    while (bantu->sibling != root->child)
                    {
                        n++;
                        delete2(bantu, depth, n, harga_hapus);
                        n--;
                        bantu = bantu->sibling;
                    }
                    n++;
                    delete2(bantu, depth, n, harga_hapus);
                    n--;
                }
            }
        }
        else
        {
            delAll(&root);
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

void delete (simpul *root, int depth[], int n, int harga_hapus)
{
    if (root != NULL)
    {
        if (root->kontainer.nilai >= n)
        {

            printf("\n");
            if (n > 0)
            {
                // spasi di cetak jika bukan mencetak root paling atas
                // atau jika level kedalaman tree > 0
                for (int i = 0; i < depth[n - 1]; i++)
                {
                    // cetak spasi sebanyak nilai pada array panjang string
                    printf(" ");
                }
            }
            printf("|%s %d\n", root->kontainer.nama, root->kontainer.nilai);
            for (int i = 0; i < root->kontainer.jmlh_komponen; i++)
            {
                if (n > 0)
                {
                    // spasi di cetak jika bukan mencetak root paling atas
                    // atau jika level kedalaman tree > 0
                    for (int i = 0; i < depth[n - 1]; i++)
                    {
                        // cetak spasi sebanyak nilai pada array panjang string
                        printf(" ");
                    }
                }
                // printf("- %s\n", root->kontainer.arr_komponen[i]);
            }
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                n++;
                delete (bantu, depth, n, harga_hapus);
                n--;
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    n++;
                    delete (bantu, depth, n, harga_hapus);
                    n--;
                    bantu = bantu->sibling;
                }
                n++;
                delete (bantu, depth, n, harga_hapus);
                n--;
            }
        }
    }
}

void printTreePostOrder(simpul *root, int n)
{
    if (root != NULL)
    {
        if (root->kontainer.nilai >= n)
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {

                    printTreePostOrder(bantu, n);
                }
                else
                {
                    while (bantu->sibling != root->child)
                    {
                        printTreePostOrder(bantu, n);
                        bantu = bantu->sibling;
                    }
                    printTreePostOrder(bantu, n);
                }
            }
            if (n > root->kontainer.nilai)
            {
                printf("[hapus] ");
            }
            printf("%s %d\n", root->kontainer.nama, root->kontainer.nilai);
        }
        else
        {
            delAll(&root);
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

void maxLenName(simpul *root, int level, int len[])
{
    if (root != NULL)
    {
        // jika root tidak kosong
        // simpan panjang nama kontainer saat ini ditambah jumlah digit nilai
        int curLen = strlen(root->kontainer.nama) + totalDigit(root->kontainer.nilai) + 4;
        for (int i = 0; i < root->kontainer.jmlh_komponen; i++)
        {
            if (strlen(root->kontainer.arr_komponen[i]) > curLen)
            {
                curLen = strlen(root->kontainer.arr_komponen[i]) + 4;
            }
        }
        if (len[level] < curLen)
        {
            // jika panjang yg tersimpan di len[level] < panjang saat ini
            // simpan panjang saat ini ke array len[level]
            len[level] = curLen;
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            // jika root memiliki simpul anak
            if (bantu->sibling == NULL)
            {
                // jika memiliki satu simpul anak
                // telusuri simpul anak
                maxLenName(bantu, ++level, len);
                --level;
            }
            else
            {
                // jika memiliki banyak simpul anak
                // telusuri semua simpul anak
                while (bantu->sibling != root->child)
                {
                    // selama saudara simpul saat ini bukan simpul terakhir
                    // telusuri simpul anak (simpul di bawahnya)
                    maxLenName(bantu, ++level, len);
                    --level;
                    bantu = bantu->sibling; // iterasi
                }
                // memproses simpul anak terakhir
                maxLenName(bantu, ++level, len);
                --level;
            }
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

int totalDigit(int num)
{
    int digit = 0;
    while (num != 0)
    {
        // selama nilai num belum nol
        num /= 10;
        digit++;
    }
    // mengembalikan nilai var digit
    return digit;
}