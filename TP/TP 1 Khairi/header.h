/*Saya Mochamad Khaairi NIM 2106416 mengerjakan Tugas Praktikum 1 
dalam mata kuliah Praktikum Struktur Data 
untuk keberkahanNya maka saya tidak melakukan kecurangan 
seperti yang telah dispesifikasikan. Aamiin.*/

//library yang digunakan
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//membuat tipe terstruktur untuk isi data listnya
typedef struct
{
	char judul[100];
	char produksi[100];
	double rating;
}data;

//membuat pointer sementara 
typedef struct elmt* alamatelmt;

//membuat tipe data terstruktur untuk element
typedef struct elmt
{
	data kontainer;
	alamatelmt next;
}elemen;

//membuat tipe data terstruktur untuk list
typedef struct
{
	elemen* first;
}list;

//deklarasi prosedur untuk membuat list
void createList(list *L);
//deklarasi fungsi untuk menghitung banyak element pada list
int countElement(list L);
//deklarasi prosedur untuk memasukkan data / element ke list secara addfirst
void addFirst(char nilai1[], char nilai2[], double nilai3, list *L);
//deklarasi prosedur untuk men-sorting data dari kecil ke besar
void kecilBesar(char konten[], list *L);
//deklarasi prosedur untuk men-sorting data dari besar ke kecil
void besarKecil(char konten[], list *L);
//deklarasi prosedur untuk print isi list / elementnya
void printElement(list L);