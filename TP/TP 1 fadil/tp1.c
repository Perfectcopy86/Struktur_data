// Tugas Praktikum
// (KBT22) Kisah Baru Techi

/* 
Saya Muhammad Fadhillah Nursyawal NIM 2107135 mengerjakan Evaluasi TP1
dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int main(){

    list L; // deklarasi variabel list
    createList(&L); // membuat list

    // deklarasi variabel inputan
    char a[100], b[100]; 
    float c;

    // inputan dimasukan dengan batas masukan berupa "-"
    while(strcmp(a, "-") != 0){

        a[0]=b[0]='\0'; // direset agar tidak ngaco

        scanf("%s %s %f", &a, &b, &c); // input

        //kondisi jika inputan pertama bukan "-"
        if(strcmp(a, "-") != 0){
            addLast(a, b, c, &L); // maka inputan dimasukan kedalam list dengan addlast
        }
    }
    scanf("%s", &a); // inputan untuk asc/desc

    // kondisi jika yang dishorting judulnya atau ratingnya
    if(strcmp(b, "judul") == 0){ 
        shortingJudul(a, &L); // masuk ke fungsi
    }
    else{
        shortingRating(a, &L);
    }

    printElement(L); // output
    
return 0;
}

/*
input

AnakKakiGunung CitraSinema 5.0
WeOwnThisCity HBO 3.5
Dark Netflix 4.3
TheHauntingOfHillHouse Netflix 3.9
TheWheelOfTime Amazon 4.6
-
judul
asc

*/