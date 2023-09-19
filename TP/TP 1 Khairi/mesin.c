/*Saya Mochamad Khaairi NIM 2106416 mengerjakan Tugas Praktikum 1 
dalam mata kuliah Praktikum Struktur Data 
untuk keberkahanNya maka saya tidak melakukan kecurangan 
seperti yang telah dispesifikasikan. Aamiin.*/

//menggunakan header / library yang sebelumnya telah dibuat
#include "header.h"

//inisialisasi prosedur untuk membuat list
void createList(list *L)
{
	//pointer first di null kan yang menandakan list masih kosong
	(*L).first = NULL;
}

//inisialisasi fungsi untuk menghitung banyak element pada list
int countElement(list L)
{
	//tempat untuk menampung banyaknya element
	int hasil = 0;
	//jika first bukan null (artinya ada elementnya) kalau kosong buat apa dihitung :/
	if(L.first != NULL)
	{
		//buat pointer pembantu dan simpan / tunjuk pointer ke first
		elemen* tunjuk;
		tunjuk = L.first;

		//perulangan selama yang ditunjuk oleh pointer pembantu bukan null
		while(tunjuk != NULL)
		{
			//hasil bertambah 1 dan tunjuk pindah ke depan posisinya tadi / ke next nya
			hasil = hasil + 1;
			tunjuk = tunjuk->next;
		}
	}
	//kembalikan nilai hasil
	return hasil;
}

//inisialisasi prosedur untuk memasukkan data / element ke list secara addfirst
void addFirst(char nilai1[], char nilai2[], double nilai3, list *L)
{
	//buat element baru (pointer baru) dan masukkan data pada parameter ke dalam element tersebut
	elemen* baru;
	baru = (elemen*) malloc (sizeof(elemen)); //alokasi tempat di memori yang besarnya sama seperti elemen
	strcpy(baru->kontainer.judul, nilai1);
	strcpy(baru->kontainer.produksi, nilai2);
	baru->kontainer.rating = nilai3;

	//jika list kosong
	if((*L).first == NULL)
	{
		//next dari baru dibuat null karena dia element terakhir dan satu satunya
		baru->next = NULL;
	}
	//jika bukan list kosong (ada isinya)
	else
	{
		//next dari baru menunjuk ke element pertama (first)
		baru->next = (*L).first;
	}

	//pointer first menunjuk element baru karena element baru menjadi element pertama
	(*L).first = baru;
	//karena sudah tidak digunakan maka pointer baru di-null-kan agar tidak ada tangan tangan zombie :D
	baru = NULL;
}

//inisialisasi prosedur untuk men-sorting data dari kecil ke besar
void kecilBesar(char konten[], list *L)
{
	//swap untuk menandakan apakah sudah rapi atau tidak
	//tanda untuk menandakan pengecekan pertama atau bukan
	int swap, tanda, i;
	//deklarasi pointer depan
	elemen* depan;
	do
	{
		//tanda dibuat nol yang masih pada pengecekan pertama
		tanda = 0;
		//deklarasi para pointer pembantu
		//kenapa tidak diluar do while karena sifat bubble sort yang berulang maka kalau masuk cycle kedua dia tidak akan balik ke awal dan menyebabkan error
		//pointer prev dan tunjuk awalnya berada di first dan pointer depan ada di depan kedua pointer tersebut
		elemen* prev = (*L).first;
		elemen* tunjuk = (*L).first;
		elemen* depan = tunjuk->next;
		// swap dibuat nol yang artinya sudah rapi
		swap = 0;
		//perulangan sebanyak element dikurang 1
		for(i = 0; i < countElement(*L) - 1; i++)
		{
			//jika diurut berdasarkan judul filmnya
			if(strcmp(konten, "judul") == 0)
			{
				
				//jika data pada pointer tunjuk lebih besar asciinya dibanding data pada pointer depan maka perlu ditukar
				if(strcmp(tunjuk->kontainer.judul, depan->kontainer.judul) > 0)
				{
					//kondisi jika pada pengecekan pertama
					//kenapa perlu adanya penanda untuk pengecekan pertama, karena pertukaran pada pengecekan pertama (dua element pertama) berbeda cara tukarnya
					if(tanda == 0)
					{
						//proses pertukaran tempat dengan mengatur pointer nextnya
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						(*L).first = depan;
						//setelah ditukar maka posisi pointer pembantu akan berubah maka harus diubah lagi posisinya
						//posisi pointer 'prev->tunjuk->depan' harus dipertahankan agar bisa melakukan pertukaran tanpa error
						tunjuk = depan;
						prev = depan;
						depan = tunjuk->next;

					}
					//jika bukan pengecekan pertama
					else
					{
						//beda pengecekan pertama sama bukan ada pada proses mengatur pointer nextnya
						prev->next = depan;
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						//sama seperti kasus pengecekan awal maka pointer pembantu harus diubah lagi posisinya
						tunjuk = depan;
						depan = tunjuk->next;
					}

					//swap dibuat jadi satu yang artinya masih belum rapi
					swap = 1;
				}

				//iterasi pointer pembantu
				//kondisi pada pengecekan awal
				if(tanda == 0)
				{
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				//kondisi bukan pengecekan pertama
				else
				{
					//bedanya hanya pada pointer prev yang sekarang ikut maju
					prev = prev->next;
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				//tanda dibuat satu yang artinya sudah melakukan pengecekan pertama
				tanda = 1;
			}
			//jika diurutkan berdasarkan rating filmnya
			else if(strcmp(konten, "rating") == 0)
			{
				if(tunjuk->kontainer.rating > depan->kontainer.rating)
				{
					if(tanda == 0)
					{
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						(*L).first = depan;
						tunjuk = depan;
						prev = depan;
						depan = tunjuk->next;

					}
					else
					{
						prev->next = depan;
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						tunjuk = depan;
						depan = tunjuk->next;
					}

					swap = 1;
				}

				if(tanda == 0)
				{
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				else
				{
					prev = prev->next;
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				tanda = 1;
			}
		}
	//perulangan terus berlangsung selama swap masih satu artinya belum rapi
	}while(swap == 1);
	//karena pointer atau posisi elementnya diubah ubah maka null pada akhir list hilang sehingga perlu dibuat lagi untuk print data nantinya
	depan = NULL;
}

//inisialisasi prosedur untuk men-sorting data dari besar ke kecil
//sebenarnya sama saja seperti soring dari kecil ke besar hanya beda pada tanda pembanding
void besarKecil(char konten[], list *L)
{
	int swap, tanda, i;
	elemen* depan;
	do
	{
		tanda = 0;
		elemen* prev = (*L).first;
		elemen* tunjuk = (*L).first;
		elemen* depan = tunjuk->next;
		swap = 0;
		for(i = 0; i < countElement(*L) - 1; i++)
		{
			if(strcmp(konten, "judul") == 0)
			{
				//                                 perbedaaan tanda banding (menjadi lebih kecil dari)
				//                                                         v
				if(strcmp(tunjuk->kontainer.judul, depan->kontainer.judul) < 0)
				{
					if(tanda == 0)
					{
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						(*L).first = depan;
						tunjuk = depan;
						prev = depan;
						depan = tunjuk->next;

					}
					else
					{
						prev->next = depan;
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						tunjuk = depan;
						depan = tunjuk->next;
					}

					swap = 1;
				}

				if(tanda == 0)
				{
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				else
				{
					prev = prev->next;
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				tanda = 1;
			}
			else if(strcmp(konten, "rating") == 0)
			{
				// perbedaaan tanda banding (menjadi lebih kecil dari)
				//                          v
				if(tunjuk->kontainer.rating < depan->kontainer.rating)
				{
					if(tanda == 0)
					{
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						(*L).first = depan;
						tunjuk = depan;
						prev = depan;
						depan = tunjuk->next;

					}
					else
					{
						prev->next = depan;
						tunjuk->next = depan->next;
						depan->next = tunjuk;
						tunjuk = depan;
						depan = tunjuk->next;
					}

					swap = 1;
				}

				if(tanda == 0)
				{
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				else
				{
					prev = prev->next;
					tunjuk = tunjuk->next;
					depan = depan->next;
				}
				tanda = 1;
			}
		}
	}while(swap == 1);
	depan = NULL;
}

//inisialisasi prosedur untuk print isi list / elementnya
void printElement(list L)
{
	//deklarasi pointer tunjuk dan simpan di element pertama
	elemen* tunjuk = L.first;

	//jika element tidak kosong, kalau kosong mau print apa :/
	if(tunjuk != NULL)
	{
		//perulangan selama pointer tunjuk tidak bertemu null yang artinya akhir dari list
		while(tunjuk != NULL)
		{
			//print data pada list
			printf("%s - %s\n", tunjuk->kontainer.judul, tunjuk->kontainer.produksi);
			tunjuk = tunjuk->next;
		}
	}
	//print pesan jika list kosong
	else
	{
		printf("list kosong\n");
	}
}