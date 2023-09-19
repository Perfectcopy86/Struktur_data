/*Saya Muhammad Rizki NIM 2107922 mengerjakan soal 
Kompetisi TP1 Alpro2 C2 2021 dalam mata kuliah Struktur data
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin*/
#include <stdio.h>  //library input output
#include <malloc.h> //library alokasi memori
#include <string.h> //library string

typedef struct {    //struct data
    char judul[50];
    char production[50];
    float rating;
}Data;      //nama

// typedef struct pointer_element* address_element;//pointer

typedef struct pointer_element {//element
    Data container;
    struct pointer_element* next;
}element;

typedef struct {//list
    element* first;
}list;

void createList(list *L); // inisialisasi list 
int countElement(list L); // hitung isi list
void addFirst(char judul[], char production[], float rating, list *L); // menambah 1 awal list
void addAfter(element* prev, char judul[], char production[], float rating, list *L); // menambah 1 setelah elemen tertentu
void addLast(char judul[], char production[], float rating, list *L); // menambah 1 di akhir list
void delFirst(list *L); // menghapus 1 di awal list
void delAfter(element *prev, list *L); // menghapus 1 setelah elemen tertentu
void delLast(list *L); // menghapus 1 di akhir list
void delAll(list *L); // menghapus seluruh isi list
void printElement(list L); // mencetak seluruh elemen list

int stop_strip(char arr[]); //fungsi cek inputan
void selection_sort(list *L, int option);//selection sort pada list
void pindah_pointer(list *L, element *before, element *key, element *temp);//pindah pointer
