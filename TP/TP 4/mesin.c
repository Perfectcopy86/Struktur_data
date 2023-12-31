/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Struktur data (BPRA2) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

// Prosedur Membuat Tree
void makeTree(char nama[], tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->nama, nama);
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char nama[], simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->nama, nama);
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum memiliki simpul
            anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki anak yang belum
                memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan
                dikaitkan dengan simpul baru sebagai simpul
                anak terakhir yang baru, simpul anak terakhir
                adalah yang memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul anak terakhir,
                penunjuk last akan berjalan ke simpul anak berikutnya */
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

void delAll(simpul *root)
{
    if ((root) != NULL)
    {
        /* jika simpul root tidak kosong */
        if ((root)->child != NULL)
        {
            if ((root)->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll((root)->child);
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = (root)->child;
                while (bantu->sibling != (root)->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
                delAll(bantu);
            }
            free((root)->child);
            (root)->child = NULL;
        }
        free(root);
        root = NULL;
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
                /*jika hanya mempunyai satu anak*/
                if ((root->child == del))
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
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
                /* memproses simpul anak terakhir karena
                belum terproses dalam pengulangan */
                if ((ketemu == 0) && (hapus == del))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last == hapus))
                        {
                            /* jika hanya ada dua simpul anak dan
                            yang dihapus adalah simpul anak kedua */
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan simpul anak
                            pertama dan simpul root memiliki simpul
                            anak lebih dari dua simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
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
        if ((strcmp(root->nama, cari) == 0))
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
                    /*jika memiliki satu simpul anak*/
                    if ((strcmp(bantu->nama, cari) == 0))
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
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if ((strcmp(bantu->nama, cari) == 0))
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
                    /*memproses simpul anak terakhir karena belum
                    terproses dalam pengulangan*/
                    if (ketemu == 0)
                    {
                        if ((strcmp(bantu->nama, cari) == 0))
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

void level(int n, int hitung)
{
    if (n == 0)
    {
        printf("Output %d:\n=========\n", hitung);
    }
}

void printTreePreOrder(simpul *root, int n)
{

    if (root != NULL)
    {
        // mencetak -> sesuai level
        for (int i = 0; i < n; i++)
        {
            printf("->");
        }
        printf("%s\n", root->nama);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /* jika memiliki satu simpul anak */
                printTreePreOrder(bantu, ++n);
                n--;
            }
            else
            {
                /* jika memiliki banyak simpul anak */
                /* mencetak simpul anak */
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, ++n);
                    n--;
                    bantu = bantu->sibling;
                }
                /* memproses simpul anak terakhir karena belum
                terproses dalam pengulangan */
                printTreePreOrder(bantu, ++n);
                n--;
            }
        }
    }
    else
    {
        printf("Kosong\n");
    }
}
