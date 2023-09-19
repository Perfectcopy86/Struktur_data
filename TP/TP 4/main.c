/*Saya Rasyid Andriansyah NIM 2101963 mengerjakan evaluasi TP4 Struktur data (BPRA2) dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main()
{
    tree T;
    char query[100];  // variabel untuk query
    char nama[100];   // variabel untuk nama
    char parent[100]; // variabel untuk parent

    int hitung = 1;                     // variabel untung hitung output
    while (strcmp(query, "DONE;") != 0) // selama masukan bukan "DONE;" maka akan terus minnta inputan
    {
        scanf("%s", &query); // masukan query

        if (strcmp(query, "MAKETREE") == 0) // jika query sama dengan "MAKETREE"
        {
            int i = 0;
            while (nama[i - 1] != ';') // Selama bukan ";" akan terus jalan
            {
                scanf(" %c", &nama[i]); // inputan nama
                i++;
            }
            nama[i - 1] = '\0';
            makeTree(nama, &T); // membuat tree
        }
        else if (strcmp(query, "CHILD") == 0) // jika query sama dengan "CHILD"
        {
            simpul *root2;      // simpul tampungan untuk cari parent
            scanf("%s", &nama); // inputan nama
            int i = 0;
            while (parent[i - 1] != ';')
            {
                scanf(" %c", &parent[i]); // inputan parent
                i++;
            }
            parent[i - 1] = '\0';
            root2 = findSimpul(parent, T.root); // mencari parent dengan fungsi findSimpul
            addChild(nama, root2);              // menambah anak
        }
        else if (strcmp(query, "DELLCHILD") == 0) // jika query sama dengan "DELLCHILD"
        {
            simpul *root2;
            scanf("%s", &nama); // inputan nama
            int i = 0;
            while (parent[i - 1] != ';')
            {
                scanf(" %c", &parent[i]); // inputan parent
                i++;
            }
            parent[i - 1] = '\0';
            root2 = findSimpul(parent, T.root);           // mencari parent dengan fungsi findSimpul
            simpul *hapusroot = findSimpul(nama, T.root); // simpul untuk hapus
            delChild(hapusroot, root2);                   // hapus anak
        }
        else if (strcmp(query, "PREORDER;") == 0) // jika Query sama dengan "PREORDER;"
        {
            level(0, hitung++);           // keluaran untuk output(angka)
            printTreePreOrder(T.root, 0); // Keluaran anak
        }
        else if (strcmp(query, "DONE;") == 0)
        {
            printf("=========\n"); // keluaran jika query == "DONE"
        }
    }
    return 0;
}