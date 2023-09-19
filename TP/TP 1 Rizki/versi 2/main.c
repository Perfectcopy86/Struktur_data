/*Saya Muhammad Rizki NIM 2107922 mengerjakan soal 
Kompetisi TP1 Alpro2 C2 2021 dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin*/
#include "header.h"//memanggil file header

int main(){//fungsi utama
    // ===>>deklarasi variable<<===
    list L; //variabel list
    char judul[50], production[50];//penampung record list bentuk string
    float rating;   //penampung record list bentuk float
    int stop=0;     //variabel looping inputan
    char sort_menu[20], order[10];//variabel menu sorting

    createList(&L); //buat kerangka list L
    while(stop==0){ //loop selama stop bernilai 0
        scanf("%s", judul);//minta inputan judul dulu
        if(stop_strip(judul)==1){//cek dengan fungsi stop strip
            stop=1; //jika terdapat '-' maka stop menjadi 1
        }
        else{//jika tidak
            scanf("%s%f", production, &rating);//lanjut minta sisa inputannya
            addFirst(judul, production, rating, &L); //masukan ke list dengan add first
        }
    };
    scanf("%s%s", sort_menu, order);//minta inputan menu sorting

    if(strcmp(sort_menu, "judul")==0){//menu sorting berdasarkan judul
        if(strcmp(order, "asc")==0){    //ascending
            selection_sort(&L, 1);
        }
        else if(strcmp(order, "desc")==0){  //descending
            selection_sort(&L, 2);
        }
    }
    else if(strcmp(sort_menu, "rating")==0){//menu sorting berdasarkan rating
        if(strcmp(order, "asc")==0){    //ascending
            selection_sort(&L, 3);
        }
        else if(strcmp(order, "desc")==0){  //descending
            selection_sort(&L, 4);
        }
    }
    printElement(L);//tampilkan list
    return 0;//tutup program
}