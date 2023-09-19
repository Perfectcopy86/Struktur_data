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
    // address_element next;
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

int stop_strip(char arr[]);
void selection_sort_mintomax_title(list *L);
void selection_sort_mintomax_title_v2(list *L);
void selection_sort_maxtomin_title(list *L);
void selection_sort_maxtomin_title_v2(list *L);
void selection_sort_mintomax_rate(list *L);
void selection_sort_mintomax_rate_v2(list *L);
void selection_sort_maxtomin_rate(list *L);
void selection_sort_maxtomin_rate_v2(list *L);
void swapNode(element *x, element *y);
// void show_sort(list *L);