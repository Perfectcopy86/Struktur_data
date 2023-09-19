/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan Tugas Masa Depan (TMD) dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

/* Prosedur Membuat Tree */
void makeTree(data d, tree *T)
{
    // membuat node, meminta alokasi memori seukuran simpul
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    // mengisi data
    node->daerah = d;
    // membuat pointer anak dan saudara
    node->sibling = NULL;
    node->child = NULL;
    // memasang node ke root
    (*T).root = node;
}

/* Prosedur Menambah Child */
void addChild(data d, simpul *root)
{
    if (root != NULL)
    {
        // jika simpul root tidak kosong,
        // berarti dapat ditambahkan simpul anak
        simpul *baru;
        // membuat node, meminta alokasi memori seukuran simpul
        baru = (simpul *)malloc(sizeof(simpul));
        // mengisikan data
        baru->daerah = d;
        baru->child = NULL;
        if (root->child == NULL)
        {
            // jika simpul root belum memiliki simpul
            // anak maka simpul baru menjadi anak pertama
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                // jika root baru memiliki satu anak
                baru->sibling = root->child;
                root->child->sibling = baru;
                if (baru->daerah.nilai > root->child->daerah.nilai)
                {
                    // jika simpul baru memiliki jumlah nilai > simpul anak pertama
                    // maka simpul baru akan menjadi anak pertama
                    root->child = baru;
                }
            }
            else
            {
                // jika root sudah memiliki anak lebih dari satu
                simpul *bantu = root->child;
                int stop = 0; // penanda child baru sudah menemukan tempat yg pas
                if (baru->daerah.nilai > bantu->daerah.nilai)
                {
                    // jika jumlah nilai simpul baru > jumlah nilai anak pertama
                    // maka simpul baru akan menjadi anak perta,a
                    baru->sibling = root->child;
                    simpul *last = root->child;
                    // mencari anak terakhir pada root
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    // anak terakhir dihubungkan ke anak pertama yang baru
                    last->sibling = baru;
                    root->child = baru;
                    stop = 2; // tandai
                }
                else
                {
                    // jika jumlah nilai simpul baru <= jumlah nilai anak pertama
                    // dilakukan penelusuran thd seluruh anak pada root
                    while (bantu->sibling != root->child && stop == 0)
                    {
                        // selama saudara simpul saat ini bukan anak terakhir
                        // dan simpul baru belum menemukan tempat
                        if (bantu->sibling->daerah.nilai < baru->daerah.nilai)
                        {
                            // jika nilai saudara simpul saat ini < nilai simpul baru
                            // maka simpul baru ditempatkan tepat setelah simpul saat ini
                            baru->sibling = bantu->sibling;
                            bantu->sibling = baru;
                            stop = 1; // tandai
                        }
                        // iterasi penelusuran simpul
                        bantu = bantu->sibling;
                    }
                    // mengecek simpul anak terakhir jika penanda stop masih nol
                    // (jika simpul baru belum menemukan tempat yg pas)
                    if (stop == 0)
                    {
                        if (baru->daerah.nilai <= bantu->daerah.nilai)
                        {
                            // jika nilai simpul baru <= nilai simpul terakhir
                            // maka simpul baru akan menjadi simpul terakhir
                            baru->sibling = root->child;
                            bantu->sibling = baru;
                        }
                    }
                }
            }
        }
    }
}

// void delAll(simpul *root)
// {
//     if (root != NULL)
//     {
//         /* jika simpul root tidak kosong */
//         if (root->child != NULL)
//         {
//             if (root->child->sibling == NULL)
//             {
//                 /* jika hanya memiliki satu simpul anak */
//                 delAll(root->child);
//                 free(root);
//             }

//             else
//             {
//                 simpul *bantu;
//                 simpul *proses;
//                 bantu = root->child;
//                 while (bantu->sibling != root->child)
//                 {
//                     proses = bantu;
//                     bantu = bantu->sibling;
//                     delAll(proses);
//                 }
//             }
//             free(root);
//         }
//         else
//         {
//             free(root);
//         }
//     }
// }

// void delChild(simpul *delete, simpul *root)
// {
//     if (root != NULL)
//     {
//         simpul *hapus = root->child;
//         if (hapus != NULL)
//         {
//             if (hapus->sibling == NULL)
//             {
//                 /*jika hanya mempunyai satu anak*/
//                 if (root->child == delete)
//                 {
//                     delAll(root->child);
//                     root->child = NULL;
//                 }
//                 else
//                 {
//                     printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
//                 }
//             }
//             else
//             {
//                 /*jika memiliki lebih dari satu simpul
//                 anak*/
//                 simpul *prev = NULL;
//                 /*mencari simpul yang akan dihapus*/
//                 int ketemu = 0;
//                 while ((hapus->sibling != root->child) && (ketemu == 0))
//                 {
//                     if (hapus == delete)
//                     {
//                         ketemu = 1;
//                     }
//                     else
//                     {
//                         prev = hapus;
//                         hapus = hapus->sibling;
//                     }
//                 }
//                 /*memproses simpul anak terakhir karena
// belum terproses dalam pengulangan*/
//                 if ((ketemu == 0) && (hapus == delete))
//                 {
//                     ketemu = 1;
//                 }
//                 if (ketemu == 1)
//                 {
//                     simpul *last = root->child;
//                     /* mencari simpul anak terakhir untuk
//                     membantu proses atau pemeriksaan jika yang
//                     dihapus nantinya anak terakhir */
//                     while (last->sibling != root->child)
//                     {
//                         last = last->sibling;
//                     }
//                     if (prev == NULL)
//                     {
//                         /*jika simpul yang dihapus
//                         anak pertama*/
//                         if ((hapus->sibling == last) && (last->sibling == root->child))
//                         {
//                             /*jika hanya ada dua anak*/
//                             root->child = last;
//                             last->sibling = NULL;
//                         }
//                         else
//                         {
//                             /* jika memiliki simpul anak
//                             lebih dari dua simpul */
//                             root->child = hapus->sibling;
//                             last->sibling = root->child;
//                         }
//                     }
//                     else
//                     {
//                         if ((prev == root->child) && (last->sibling == root->child))
//                         {
//                             /* jika hanya ada dua simpul
//                             anak dan yang dihapus adalah simpul
//                             anak kedua */

//                             root->child->sibling = NULL;
//                         }
//                         else
//                         {
//                             /* jika yang dihapus bukan
//                             simpul anak pertama dan simpul root
//                             memiliki simpul anak lebih dari dua
//                             simpul */
//                             prev->sibling = hapus->sibling;
//                             hapus->sibling = NULL;
//                         }
//                     }
//                     delAll(hapus);
//                 }
//                 else
//                 {
//                     printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
//                 }
//             }
//         }
//     }
// }

// simpul *findSimpul(char cari[], simpul *root)
// {
//     simpul *hasil = NULL;
//     if (root != NULL)
//     {
//         if ((strcmp(root->kontainer.nama, cari) == 0))
//         {
//             hasil = root;
//         }
//         else
//         {
//             simpul *bantu = root->child;
//             if (bantu != NULL)
//             {
//                 if (bantu->sibling == NULL)
//                 {
//                     /*jika memiliki satu simpul anak*/
//                     if ((strcmp(bantu->kontainer.nama, cari) == 0))
//                     {
//                         hasil = bantu;
//                     }
//                     else
//                     {
//                         hasil = findSimpul(cari, bantu);
//                     }
//                 }
//                 else
//                 {
//                     /*jika memiliki banyak simpul anak*/
//                     int ketemu = 0;
//                     while ((bantu->sibling != root->child) && (ketemu == 0))
//                     {
//                         if ((strcmp(bantu->kontainer.nama, cari) == 0))
//                         {
//                             hasil = bantu;
//                             ketemu = 1;
//                         }
//                         else
//                         {
//                             hasil = findSimpul(cari, bantu);
//                             bantu = bantu->sibling;
//                             if (hasil != 0)
//                             {
//                                 ketemu = 1;
//                             }
//                         }
//                     }
//                     /*memproses simpul anak terakhir karena belum
//                     terproses dalam pengulangan*/
//                     if (ketemu == 0)
//                     {
//                         if ((strcmp(bantu->kontainer.nama, cari) == 0))
//                         {
//                             hasil = bantu;
//                         }
//                         else
//                         {
//                             hasil = findSimpul(cari, bantu);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return hasil;
// }

// void printTreePreOrder(simpul *root, simpul *root2)
// {
//     if (root != NULL)
//     {
//         if (root == root2)
//         {
//             printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
//         }
//         else
//         {
//             printf("-%s %d", root->kontainer.nama, root->kontainer.nilai);
//         }
//         simpul *bantu = root->child;
//         if (bantu != NULL)
//         {
//             if (bantu->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 printTreePreOrder(bantu, root2);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 /*mencetak simpul anak*/
//                 while (bantu->sibling != root->child)
//                 {
//                     printTreePreOrder(bantu, root2);
//                     bantu = bantu->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena belum
//                 terproses dalam pengulangan*/
//                 printTreePreOrder(bantu, root2);
//             }
//         }
//     }
//     else
//     {
//         printf("Kosong\n");
//     }
// }

// void printTreePostOrder(simpul *root, simpul *root2)
// {
//     if (root != NULL)
//     {
//         simpul *bantu = root->child;
//         if (bantu != NULL)
//         {
//             if (bantu->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 printTreePostOrder(bantu, root2);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 /*mencetak simpul anak*/
//                 while (bantu->sibling != root->child)
//                 {
//                     printTreePostOrder(bantu, root2);
//                     bantu = bantu->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena
//                 belum terproses dalam pengulangan*/
//                 printTreePostOrder(bantu, root2);
//             }
//         }
//         printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
//         if (root != root2)
//         {
//             printf("-");
//         }
//     }
//     else
//     {
//         printf("Kosong\n");
//     }
// }

// void copyTree(simpul *root1, simpul **root2)
// {
//     if (root1 != NULL)
//     {
//         (*root2) = (simpul *)malloc(sizeof(simpul));
//         (*root2)->kontainer = root1->kontainer;
//         (*root2)->sibling = NULL;
//         (*root2)->child = NULL;
//         if (root1->child != NULL)
//         {
//             if (root1->child->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 copyTree(root1->child, &(*root2)->child);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 simpul *bantu1 = root1->child;
//                 simpul *bantu2 = (*root2)->child;
//                 while (bantu1->sibling != root1->child)
//                 {
//                     copyTree(bantu1, &bantu2);
//                     bantu1 = bantu1->sibling;
//                     bantu2 = bantu2->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena
//                 belum terproses dalam pengulangan*/
//                 copyTree(bantu1, &bantu2);
//             }
//         }
//     }
// }

// int isEqual(simpul *root1, simpul *root2)
// {
//     int hasil = 1;
//     if ((root1 != NULL) && (root2 != NULL))
//     {
//         if ((root1->kontainer.nilai != root2->kontainer.nilai) || (strcmp(root1->kontainer.nama, root2->kontainer.nama) != 0))
//         {
//             hasil = 0;
//         }
//         else
//         {
//             if ((root1->child != NULL) && (root2->child != NULL))
//             {
//                 if (root1->child->sibling == NULL)
//                 {
//                     /*jika memiliki satu simpul anak*/
//                     hasil = isEqual(root1->child, root2->child);
//                 }
//                 else
//                 {
//                     /*jika memiliki banyak simpul anak*/
//                     simpul *bantu1 = root1->child;
//                     simpul *bantu2 = root2->child;
//                     while (bantu1->sibling != root1->child)
//                     {
//                         if ((bantu1 != NULL) && (bantu2 != NULL))
//                         {
//                             hasil = isEqual(bantu1, bantu2);
//                             bantu1 = bantu1->sibling;
//                             bantu2 = bantu2->sibling;
//                         }
//                         else
//                         {
//                             hasil = 0;
//                             break;
//                         }
//                     }
//                     /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                     hasil = isEqual(bantu1, bantu2);
//                 }
//             }
//         }
//     }
//     else
//     {
//         if ((root1 != NULL) || (root2 != NULL))
//         {
//             hasil = 0;
//         }
//     }
//     return hasil;
// }

/* Prosedur Mencari Node */
simpul *findSimpul(char cari[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        // jika tree tidak kosong
        if ((strcmp(root->daerah.nama, cari) == 0))
        {
            // jika simpul yg dicari adalah root
            hasil = root;
        }
        else
        {
            // jika simpul yg dicari bukan root (anak2nya)
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                // jika root memiliki anak
                if (bantu->sibling == NULL)
                {
                    // jika memiliki satu simpul anak
                    if ((strcmp(bantu->daerah.nama, cari) == 0))
                    {
                        // jika anaknya adalah simpul yg dicari
                        hasil = bantu;
                    }
                    else
                    {
                        // jika anaknya bukan simpul yg dicari
                        // rekursif, telusuri level root di bawahnya
                        hasil = findSimpul(cari, bantu);
                    }
                }
                else
                {
                    // jika memiliki banyak simpul anak
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        // selama saudara simpul saat ini bukan simpul terakhir
                        // dan simpul yg dicari belum ketemu
                        if ((strcmp(bantu->daerah.nama, cari) == 0))
                        {
                            // jika ketemu di saudaranya
                            hasil = bantu;
                            ketemu = 1; // tandai
                        }
                        else
                        {
                            // jika tidak ketemu, rekursif
                            // telusuri ke level root di bawahnya
                            hasil = findSimpul(cari, bantu);
                            if (hasil != 0)
                            {
                                // jika ditemukan dalam rekursif
                                ketemu = 1; // tandai
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    // memproses simpul anak terakhir
                    if (ketemu == 0)
                    {
                        // jika simpul yg dicari belum ketemu
                        if ((strcmp(bantu->daerah.nama, cari) == 0))
                        {
                            // jika ketemu di anak terakhir
                            hasil = bantu;
                        }
                        else
                        {
                            // jika belum ketemu di anak terakhir
                            // telurusi level di bawah anak terakhir
                            hasil = findSimpul(cari, bantu);
                        }
                    }
                }
            }
        }
    }
    // kembalikan alamat simpul hasil pencarian
    return hasil;
}

/* Prosedur Mencetak Node */
void printTreePreOrder(simpul *root, int n, int len[])
{
    // parameter n menandakan level kedalaman tree
    // parameter len menandakan jumlah spasi yg harus dicetak
    if (root != NULL)
    {
        // mencetak spasi sesuai level tree dan panjang nama daerah terpanjang
        printf("\n");
        if (n > 0)
        {
            // spasi di cetak jika bukan mencetak root paling atas
            // atau jika level kedalaman tree > 0
            for (int i = 0; i < len[n - 1]; i++)
            {
                // cetak spasi sebanyak nilai pada array panjang string
                printf(" ");
            }
        }
        // mencetak nama daerah dan jumlah nilai (simpul tree)
        printf("|%s - %d\n", root->daerah.nama, root->daerah.nilai);

        // persiapan mencetak simpul berikutnya (anak dari root)
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            // jika root memiliki simpul anak
            if (bantu->sibling == NULL)
            {
                // jika root memiliki satu simpul anak
                printTreePreOrder(bantu, ++n, len);
                --n;
            }
            else
            {
                // jika root memiliki banyak simpul anak
                while (bantu->sibling != root->child)
                {
                    // simpul anak ditelurusi satu per satu sampai anak terakhir
                    // dengan memanggil rekursif untuk penelusuran level di bawahnya
                    printTreePreOrder(bantu, ++n, len);
                    --n;
                    // iterasi pengecekan simpul selanjutnya
                    bantu = bantu->sibling;
                }
                // memproses simpul anak terakhir
                printTreePreOrder(bantu, ++n, len);
                --n;
            }
        }
    }
    else
    {
        printf("Kosong\n");
    }
}

/* Fungsi Menghitung Jumlah nilai Setiap Daerah (Simpul) */
int hitungnilai(simpul *root)
{
    if (root != NULL)
    {
        // jika root tidak kosong
        int jumlah = 0;
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            // jika root memiliki anak
            if (bantu->sibling == NULL)
            {
                // jika memiliki satu simpul anak
                jumlah += hitungnilai(bantu);
            }
            else
            {
                // jika memiliki banyak simpul anak
                // simpul anak ditelusuri satu per satu
                while (bantu->sibling != root->child)
                {
                    // selama saudara simpul saat ini bukan simpul terakhir
                    // telusuri level di bawahnya untuk mendapatkan jumlah
                    // nilai dari simpul di bawahnya
                    jumlah += hitungnilai(bantu);
                    bantu = bantu->sibling; // lanjut ke saudara berikutnya
                }
                // memproses simpul anak terakhir untuk dicari jumlah nilainya
                jumlah += hitungnilai(bantu);
            }
            // mengisikan nilai root saat ini dengan total jumlah
            // yg hasil penjumlahan nilai simpul di bawahnya
            root->daerah.nilai = jumlah;
        }
        // mengembalikan nilai jumlah nilai pada root
        return root->daerah.nilai;
    }
    else
    {
        printf("Kosong\n");
    }
}

/* Prosedur Memecah String */
void explode(char str[], char first[], char second[], int *num, char splitter)
{
    // parameter splitter untuk menandai karakter pemisah string
    // dari 1 string dipecah menjadi 2 string dan 1 integer
    int tag = 0, f = 0, s = 0, v = 0;
    char temp[50];
    for (int i = 0; i < strlen(str); i++)
    {
        // diulang sepanjang string
        if (str[i] == splitter)
        {
            // jika bertemu karakter pemisah, tandai dan
            // lanjutkan iterasi tanpa mengeksekusi kode berikutnya
            tag++;
            continue;
        }
        if (tag == 0)
        {
            // jika tag 0, isi ke string pertama
            first[f] = str[i];
            f++;
        }
        if (tag == 1)
        {
            // jika tag 1, isi ke string kedua
            second[s] = str[i];
            s++;
        }
        if (tag == 2)
        {
            // jika tag 2, isi ke string temp
            // untuk diubah ke integer nantinya
            temp[v] = str[i];
            v++;
        }
    }
    // menutup semua string
    first[f] = '\0';
    second[s] = '\0';
    temp[v] = '\0';
    *num = 0;
    // mengubah string ke integer
    int digit = strlen(temp) - 1;
    for (int i = 0; i < strlen(temp); i++)
    {
        // selama panjang string, ubah nilai ascii
        // kalikan dengan 10 pangkat jumlah digit
        // tambahkan setiap hasil perkalian
        *num += ((temp[i] - 48) * (pow(10, digit)));
        digit--;
    }
}

/* Prosedur Mencari Nama Daerah Terpanjang Setiap Level */
void maxLenName(simpul *root, int level, int len[])
{
    if (root != NULL)
    {
        // jika root tidak kosong
        // simpan panjang nama daerah saat ini ditambah jumlah digit nilai
        int curLen = strlen(root->daerah.nama) + totalDigit(root->daerah.nilai) + 4;
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

/* Fungsi Menghitung Total Digit */
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