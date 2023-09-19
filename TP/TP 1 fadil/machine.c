// Tugas Praktikum
// (KBT22) Kisah Baru Techi

/* 
Saya Muhammad Fadhillah Nursyawal NIM 2107135 mengerjakan Evaluasi TP1
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

// fungsi membuat list
void createList(list *L){
    (*L).first = NULL; // list di null kan
}

// fungsi untuk menambahkan data list dengan cara addfirst
void addFirst(char judul[], char produk[], float rating, list *L){
    
    // deklarasi variabel elemen baru
    elemen* baru;
    baru = (elemen*) malloc (sizeof(elemen));

    // masukan datanya
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.produk, produk);
    baru->kontainer.rating = rating;

    // kondisi jika elemen ada atau tidak
    if((*L).first == NULL){
        // jika first null
        baru->next = NULL;
    }
    else{
        // jika first ada kontainer
        baru->next = (*L).first;
    }

    (*L).first = baru;
    baru = NULL; // pointer baru di NULL kan
}

// fungsi untuk menambahkan data list dengan cara addafter
void addAfter(elemen* prev, char judul[], char produk[], float rating){

    // deklarasi variabel elemen baru
    elemen* baru;
    baru = (elemen*) malloc (sizeof(elemen));

    // masukan datanya
    strcpy(baru->kontainer.judul, judul);
    strcpy(baru->kontainer.produk, produk);
    baru->kontainer.rating = rating;

    // kondisi jika pointer next nya null atau tidak
    if(prev->next == NULL){
        // menambahkan di akhir
        baru->next = NULL;
    }
    else{
        // menambahkan di tengah
        baru->next = prev->next;
    }

    prev->next = baru;
    baru = NULL;

}

// fungsi untuk menambahkan data list dengan cara addlast
void addLast(char judul[], char produk[], float rating, list *L){

    // kondisi jika eleme kosong atau tidak
    if((*L).first == NULL){
        // proses jika list masih kosong
        addFirst(judul, produk, rating, L);
    }
    else{
        // proses jika list telah berisi element
        elemen* prev = (*L).first;

        // membuat pointer pada di akhir elemen list
        while(prev->next != NULL){
            /*iterasi*/
            prev = prev->next;
        }
        addAfter(prev, judul, produk, rating);
    }
}

// fungsi untuk output
void printElement(list L){

    // kondisi jika list ada elemennya atau tidak
    if(L.first != NULL){
        // membuat pointer
        elemen* tunjuk = L.first;

        // print setiap elemen
        while(tunjuk != NULL){
            printf("%s - %s\n", tunjuk->kontainer.judul, tunjuk->kontainer.produk);
            tunjuk = tunjuk->next; // iterasi
        }
    }
}

// fungsi untuk menukar pointer
// pointer ditukar dengan pointer disebelahnya
void swapPoint(elemen* temp, elemen* prev, elemen* prev2, list *L){

    // kondisi jika pointer berada di elemen pertama/tengah/akhir
    if((*L).first == prev){
        // if nested jika elemen hanya 2 buah atau tidak
        if(prev2->next == NULL){
            prev->next = NULL; // jika dalam list hanya ada 2 elemen, maka pointer pertama NULL
        }
        else{
            prev->next = prev2->next; // jika tidak next dari elemen pertama menuju elemen nextnya dari pointer depannya
        }
        prev2->next = prev; // prev kedua nextnya menuju prev pertama
        (*L).first = prev2; // l first menunjuk perv2
    }
    else if(prev2->next != NULL){

        // kurang lebih sama kaya sebelumnya
        prev->next = prev2->next;
        prev2->next = prev;
        temp->next = prev2;
    }
    else{
        // ini juga sama aja
        prev->next = NULL;
        prev2->next = prev;
        temp->next = prev2;
    }

}

// fungsi untuk shorting judul
void shortingJudul(char jenis[], list *L){  

    // deklarasi variabel elemen (pointer)
    elemen* prev = L->first;
    elemen* temp = (*L).first;

    // kondisi jika judul akan dishorting asc/desc
    if(strcmp(jenis, "asc") == 0){ 
        // menggunakan looping
        while(prev->next != NULL){
            // kondisi jika elemen pertama lebih besar daripada kedua
            if(strcmp(prev->kontainer.judul, prev->next->kontainer.judul) > 0){
                // maka pointer akan ditukar
                swapPoint(temp, prev, prev->next, L);
                prev = L->first; // dan pointer akan direset lagi
            }
            else{
                // jika tidak pointer akan diiterasi
                temp = prev;
                prev = prev->next;
            }
        }
    }   
    else{
        // sama seperti yang diatas cuman desc
        while(prev->next != NULL){
            if(strcmp(prev->kontainer.judul, prev->next->kontainer.judul) < 0){
                swapPoint(temp, prev, prev->next, L);
                prev = L->first;
            }
            else{
                temp = prev;
                prev = prev->next;
            }
        }
    }

}

// fungsi untuk shorting ratingnya
void shortingRating(char jenis[], list *L){

    elemen* prev = L->first;
    elemen* temp = (*L).first;

    // konsepnya kurang lebih sama dengan yang diatas
    if(strcmp(jenis, "asc") == 0){
        while(prev->next != NULL){
            if(prev->kontainer.rating > prev->next->kontainer.rating){
                swapPoint(temp, prev, prev->next, L);
                prev = L->first;
            }
            else{
                temp = prev;
                prev = prev->next;
            }
        }
    }   
    else{
        while(prev->next != NULL){
            if(prev->kontainer.rating < prev->next->kontainer.rating){
                swapPoint(temp, prev, prev->next, L);
                prev = L->first;
            }
            else{
                temp = prev;
                prev = prev->next;
            }
        }
    }

}