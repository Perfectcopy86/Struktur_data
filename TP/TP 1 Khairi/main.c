/*Saya Mochamad Khaairi NIM 2106416 mengerjakan Tugas Praktikum 1 
dalam mata kuliah Praktikum Struktur Data 
untuk keberkahanNya maka saya tidak melakukan kecurangan 
seperti yang telah dispesifikasikan. Aamiin.*/

//menggunakan header / library yang sebelumnya telah dibuat
#include "header.h"

int main()
{
	//membuat list
	list L;
	createList(&L);
	//membuat tempat sementara untuk data yang akan dimasukkan ke list
	char a[100];
	char b[100];
	double c;
	//tempat untuk data mau di-sorting berdasarkan apa (judul atau rating) dan secara apa (asc atau desc)
	char konten[50];
	char urutan[50];

	//masukkan
	do
	{
		//masukkan untuk judul film
		scanf("%s", a);
		//jika judul film bukan "-" (pembatas) maka masukkan produksi film dan rating filmnya
		if(strcmp(a, "-") != 0)
		{
			scanf("%s", b);
			scanf("%lf", &c);
			//panggil prosedur untuk memasukkan data tadi ke list secara addfirst
			addFirst(a, b, c, &L);
		}
	//perulangan selama masukkan pada judul film bukan "-" yaitu pembatas
	}while(strcmp(a, "-") != 0);
	//masukkan untuk di-sorting berdasar apa dan secara apa
	scanf("%s", konten);
	scanf("%s", urutan);

	//jika di-sorting dari kecil ke besar
	if(strcmp(urutan, "asc") == 0)
	{
		kecilBesar(konten, &L);
	}
	//jika di-sorting dari besar ke kecil
	else if(strcmp(urutan, "desc") == 0)
	{
		besarKecil(konten, &L);
	}

	//print isi list
	printElement(L);
	return 0;
}