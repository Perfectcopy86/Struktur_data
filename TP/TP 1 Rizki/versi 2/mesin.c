/*Saya Muhammad Rizki NIM 2107922 mengerjakan soal
Kompetisi TP1 Alpro2 C2 2021 dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin*/
#include "header.h" //memnggil file header

void createList(list *L)
{                      // buat list
    (*L).first = NULL; // pointer first diisi null
}

int countElement(list L)
{ // hitung isi list
    int count = 0;
    if (L.first != NULL)
    {                   // jika list tidak kosong
        element *flag;  // pointer penunjuk elemen
        flag = L.first; // diisi dengan first
        while (flag != NULL)
        {                      // loop selama flag tidak null
            count++;           // tambah count
            flag = flag->next; // pointer maju ke next
        }
    }
    return count; // nilai kembalian
}

void addFirst(char judul[], char production[], float rating, list *L)
{                                             // tambah diawal
    element *new;                             // pointer elemen baru
    new = (element *)malloc(sizeof(element)); // siapkan elemen baru
    strcpy(new->container.judul, judul);      // isi elemen
    strcpy(new->container.production, production);
    new->container.rating = rating;
    if ((*L).first == NULL)
    {                     // jika pointer first null
        new->next = NULL; // maka pointer next element new null
    }
    else
    {
        new->next = (*L).first; // pointer next elemen baru menunjuk ke elemen milik pointer first
    }
    (*L).first = new; // pointer first diinisialisasi oleh elemen baru
    new = NULL;       // mengosongkan pointer baru
}

void addAfter(element *prev, char judul[], char production[], float rating, list *L)
{                                             // menambah element seteleah element lainya
    element *new;                             // membaut element baru
    new = (element *)malloc(sizeof(element)); //
    strcpy(new->container.judul, judul);      // salin elemen
    strcpy(new->container.production, production);
    new->container.rating = rating;
    if (prev->next == NULL)
    { // jika elemen baru akan ditambah setelah elemen terakhir
        new->next = NULL;
    }
    else
    { // jika elemen baru ditambah di tengah2
        new->next = prev->next;
    }
    prev->next = new; // pointer next elemen prev menunjuk ke elemen baru
    new = NULL;       // new dinullkan
}

void addLast(char judul[], char production[], float rating, list *L)
{ // tambah elemen di akhir list
    if ((*L).first == NULL)
    { // jika list kosong jalankan prosedur addFirst()
        addFirst(judul, production, rating, L);
    }
    else
    { // jika list tidak kosong cari elemen terakhir
        element *prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, judul, production, rating, L); // tambah dengan add after
    }
}

void delFirst(list *L)
{ // hapus elemen pertama list
    if ((*L).first != NULL)
    {                              // jika ada elemen yg dihapus/list tidak kosong
        element *del = (*L).first; // pointer del menunjuk ke elemen pertama
        if (countElement(*L) == 1)
        { // jika elemen hanya 1
            (*L).first = NULL;
        }
        else
        {                                  // jika elemen > 1
            (*L).first = (*L).first->next; // pindahkan pointer first ke elemen kedua
            del->next = NULL;              // null kan pointer del next
        }
        free(del); // bebaskan del
    }
}

void delAfter(element *prev, list *L)
{                              // hapus elemen setelah elemen lain
    element *del = prev->next; // pointer del menunjuk elemen setelah elemen yg ditunjuk pointer prev next
    if (del != NULL)
    {                           // jika yg ditunjuk ada elemennya
        prev->next = del->next; // pointer prev next menunjuk elemen yg ditunjuk pointer del next
        del->next = NULL;       // pointer del dibuat null
        free(del);              // elemen del dibebaskan
    }
}

void delLast(list *L)
{ // hapus elemen terakhir
    if ((*L).first != NULL)
    { // jika list ada isinya
        if (countElement(*L) == 1)
        { // jika elemen hanya 1
            delFirst(L);
        }
        else
        {
            element *last = (*L).first, *prev;
            while (last->next != NULL)
            { // mencari prev elemen terakhir
                prev = last;
                last = last->next;
            } // dihapus dgn prosedur delAfter()
            delAfter(prev, L);
        }
    }
}

void delAll(list *L)
{ // hapus semua elemen
    if (countElement(*L) != 0)
    {          // jika list tidak kosong
        int i; // iterasi
        for (i = countElement(*L); i >= 1; i--)
        { // for loop
            // hapus elemen dari belakang
            delLast(L); // hapus setiap elemen dengan dellast
        }
    }
}

void printElement(list L)
{ // cetak list
    if (L.first != NULL)
    {                            // jika list ada isinya
        element *flag = L.first; // untuk menunjuk tiap elemen
        while (flag != NULL)
        {                                                                           // selama flag tidak null
            printf("%s - %s\n", flag->container.judul, flag->container.production); // tampilkan elemen
            flag = flag->next;                                                      // pointer maju
        }
    }
    else
    { // jika list kosong
        printf("list kosong\n");
    }
}

int stop_strip(char arr[])
{              // cek masukan
    int i = 0; // variabel iterasi
    while (i < strlen(arr))
    { // loop sepanjang string
        if (arr[i] == '-')
        {             // jika terdapat karakter '-'
            return 1; // nilai kembalian 1
        }
        i++; // increment i
    }
    return 0; // jika tidak, nilai kembalian 0
}
//---------------------------------------------------------------
void selection_sort(list *L, int option)
{                                 // selection sort pada list
    element *key, *temp, *before; // elemet untuk penunjuk
    int tukar;                    // variabel penanda loop
    do
    {                     // loop
        tukar = 0;        // tukar diisi 0
        key = (*L).first; // key diisi first element
        temp = key->next; // temp isi elemen setelah key
        if (option == 1)
        { // sort berdasarkan title ascending
            while (temp != NULL)
            { // selama temp tidak null
                if (strcmp(key->container.judul, temp->container.judul) > 0)
                {                                         // kondisi sort
                    pindah_pointer(L, before, key, temp); // saling tukar pointer next nya dengan prosedur
                    before = temp;                        // before diisi nilai temp
                    tukar = 1;                            // tandai terjadi penukaran
                }
                else
                {                    // jika tidak
                    before = key;    // key sekarang jadi before
                    key = key->next; // key lanjut maju ke depan
                }
                temp = key->next; // temp maju di depan key
            }
        }
        else if (option == 2)
        { // sorting berdasarkan judul descending
            while (temp != NULL)
            { // prosesnya sama seperti yang diatas
                if (strcmp(key->container.judul, temp->container.judul) < 0)
                { // cuma beda di sini, kondisinya
                    pindah_pointer(L, before, key, temp);
                    before = temp;
                    tukar = 1;
                }
                else
                {
                    before = key;
                    key = key->next;
                }
                temp = key->next;
            }
        }
        else if (option == 3)
        { // sorting berdasarkan raring ascending
            while (temp != NULL)
            { // sama kayak yang diatas, cuma beda kondisi if
                if (key->container.rating > temp->container.rating)
                {
                    pindah_pointer(L, before, key, temp);
                    before = temp;
                    tukar = 1;
                }
                else
                {
                    before = key;
                    key = key->next;
                }
                temp = key->next;
            }
        }
        else if (option == 4)
        { // sorting berdasarkan raring descending
            while (temp != NULL)
            { // sama kayak yang diatas, cuma beda kondisi if
                if (key->container.rating < temp->container.rating)
                {
                    pindah_pointer(L, before, key, temp);
                    before = temp;
                    tukar = 1;
                }
                else
                {
                    before = key;
                    key = key->next;
                }
                temp = key->next;
            }
        }
    } while (tukar == 1); // looping trus selama masih ada proses penukaran
}

void pindah_pointer(list *L, element *before, element *key, element *temp)
{ // tukar pointer
    if (key == (*L).first)
    {                        // jika  key masih di first
        (*L).first = temp;   // first tunjuk ke temp
        before = (*L).first; // before tunjuk ke first
    }
    else
    {                        // jika tidak
        before->next = temp; // before next tunjuk ke temp
    }
    key->next = temp->next; // key next tunjuk ke temp next
    temp->next = key;       // temp next tunjuk ke key
}
