/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

void makeTree(data c, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->kontainer.nama, c.nama);
    node->kontainer.jumlah_komposisi = c.jumlah_komposisi;
    for (int i = 0; i < c.jumlah_komposisi; i++)
    {
        strcpy(node->kontainer.arr_komposisi[i], c.arr_komposisi[i]);
    }
    node->kontainer.harga = c.harga;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data c, simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
        */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        strcpy(baru->kontainer.nama, c.nama);
        baru->kontainer.jumlah_komposisi = c.jumlah_komposisi;
        baru->kontainer.harga = c.harga;
        for (int i = 0; i < c.jumlah_komposisi; i++)
        {
            strcpy(baru->kontainer.arr_komposisi[i], c.arr_komposisi[i]);
        }
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                /* mencari simpul anak terakhir
                karena akan dikaitkan dengan simpul
                baru sebagai simpul anak terakhir yang
                baru, simpul anak terakhir adalah yang
                memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul
                anak terakhir, penunjuk last akan
                berjalan ke simpul anak berikutnya */
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
        /* jika simpul root tidak kosong */
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
                /*jika hanya mempunyai satu anak*/
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
                /*jika memiliki lebih dari satu simpul
                anak*/
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
                /*memproses simpul anak terakhir karena
belum terproses dalam pengulangan*/
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
                        /*jika simpul yang dihapus
                        anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak
                            lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child))
                        {
                            /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua
                            simpul */
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
                    /*jika memiliki satu simpul anak*/
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
                    /*jika memiliki banyak simpul anak*/
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
                    /*memproses simpul anak terakhir karena belum
                    terproses dalam pengulangan*/
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

void printTreePreOrder(simpul *root, int depth[], int n, int *tanda)
{
    if (root != NULL)
    {
        // kondisi untuk baris pertama tidak ada enter
        if (tanda == 0)
        {
            tanda = tanda;
        }
        else // baris selanjutnya memakai enter
        {
            printf("\n");
        }

        // printf("%d", tanda);
        tanda += 1; // tambah agar hanya baris pertama yang tidak memakai enter
        if (n > 0)
        {
            for (int i = 0; i < depth[n - 1]; i++)
            {
                printf(" "); // print spasi
            }
        }
        // print data mie
        printf("|%s - %d\n", root->kontainer.nama, root->kontainer.harga);
        for (int i = 0; i < root->kontainer.jumlah_komposisi; i++)
        {
            if (n > 0)
            {
                for (int i = 0; i < depth[n - 1]; i++)
                {
                    printf(" ");
                }
            }
            // print data komposisi mie
            printf(" - %s\n", root->kontainer.arr_komposisi[i]);
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                n++;
                printTreePreOrder(bantu, depth, n, tanda);
                n--;
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    n++;
                    printTreePreOrder(bantu, depth, n, tanda);
                    n--;
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum
                terproses dalam pengulangan*/
                n++;
                printTreePreOrder(bantu, depth, n, tanda);
                n--;
            }
        }
    }
    else
    {
        printf("GA ADA\n");
    }
}

// sama seperti prosedur print pre order namun yang beda hanya kondisi dimana harga
// barang harus melebihi harga yang dihapus
void delete (simpul *root, int depth[], int n, int hapus)
{
    if (root != NULL)
    {
        // jika harga melebihi harga yang dihapus
        if (root->kontainer.harga >= hapus)
        {
            printf("\n");
            if (n > 0)
            {
                for (int i = 0; i < depth[n - 1]; i++)
                {
                    printf(" ");
                }
            }
            // print data mie
            printf("|%s - %d\n", root->kontainer.nama, root->kontainer.harga);
            for (int i = 0; i < root->kontainer.jumlah_komposisi; i++)
            {
                if (n > 0)
                {
                    for (int i = 0; i < depth[n - 1]; i++)
                    {
                        printf(" ");
                    }
                }
                // print data komposisi mie
                printf(" - %s\n", root->kontainer.arr_komposisi[i]);
            }
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    n++;
                    delete (bantu, depth, n, hapus);
                    n--;
                }
                else
                {
                    while (bantu->sibling != root->child)
                    {
                        n++;
                        delete (bantu, depth, n, hapus);
                        n--;
                        bantu = bantu->sibling;
                    }
                    n++;
                    delete (bantu, depth, n, hapus);
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
        printf("GA ADA\n");
    }
}

void terpanjang(simpul *root, int depth, int len[])
{
    if (root != NULL)
    {
        // jika root tidak kosong
        // mencari string terpanjang
        int current = strlen(root->kontainer.nama) + totalDigit(root->kontainer.harga) + 4;
        for (int i = 0; i < root->kontainer.jumlah_komposisi; i++)
        {
            if (strlen(root->kontainer.arr_komposisi[i]) > current)
            {
                current = strlen(root->kontainer.arr_komposisi[i]) + 4;
            }
        }
        if (len[depth] < current)
        {
            len[depth] = current;
        }
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                terpanjang(bantu, ++depth, len);
                --depth;
            }
            else
            {
                while (bantu->sibling != root->child)
                {
                    terpanjang(bantu, ++depth, len);
                    --depth;
                    bantu = bantu->sibling;
                }
                terpanjang(bantu, ++depth, len);
                --depth;
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
        // selama harga num belum nol
        num /= 10;
        digit++;
    }
    // mengembalikan harga variabel digit
    return digit;
}

void pisah(char str[], char kata1[], char kata2[], int *num, int *num2, char delimiter)
{
    // parameter delimiter untuk menandai karakter pemisah string dari 1 string dipecah menjadi 2 string dan 2 integer
    int tanda = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    char temp[200];  // tampungan untuk di ubah ke integer
    char temp2[200]; // tampungan untuk di ubah ke integer
    for (int i = 0; i < strlen(str); i++)
    {
        // diulang sepanjang string
        if (str[i] == delimiter)
        {
            // jika bertemu karakter pemisah, tandai dan
            // lanjutkan iterasi tanpa mengeksekusi kode berikutnya
            tanda++;
            continue;
        }
        if (tanda == 0)
        {
            // jika tanda 0, isi ke string pertama
            kata1[r] = str[i];
            r++;
        }
        if (tanda == 1)
        {
            // jika tanda 1, isi ke string kedua
            kata2[s] = str[i];
            s++;
        }
        if (tanda == 2)
        {
            // jika tanda 2, isi ke string temp
            // untuk diubah ke integer nantinya
            temp[t] = str[i];
            t++;
        }
        if (tanda == 3)
        {
            // jika tanda 2, isi ke string temp
            // untuk diubah ke integer nantinya
            temp2[u] = str[i];
            u++;
        }
    }
    // menutup semua string
    kata1[r] = '\0';
    kata2[s] = '\0';
    temp[t] = '\0';
    temp2[u] = '\0';
    *num = 0;
    *num2 = 0;

    // mengubah string ke integer
    int digit = strlen(temp) - 1;
    for (int i = 0; i < strlen(temp); i++)
    {
        // ubah harga ascii , lalu kalikan dengan 10 pangkat jumlah digit
        *num += ((temp[i] - 48) * (pow(10, digit)));
        digit--;
    }

    int digit2 = strlen(temp2) - 1;
    for (int i = 0; i < strlen(temp2); i++)
    {
        // ubah harga ascii , lalu kalikan dengan 10 pangkat jumlah digit
        *num2 += ((temp2[i] - 48) * (pow(10, digit2)));
        digit2--;
    }
}