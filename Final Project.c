#include <stdio.h>
#include <stdlib.h>

/*Made by : Kelompok Lobak
members : Emir Zaid, Kemas Rafly, Mikail Rahmansur, Qinthara Andini */ 


typedef struct pasien {			//disini kita menginisiasikan struct bernama pasien
	char nama[50];				//terdapat 2 variabel dalam struct ini yaitu nama dan kondisi
	int kondisi;
}pasien;

int exitCondition(void){		//disini terdapat sebuah exit condition yang berarti program ini telat selesai digunakan
	system("cls");
		printf("\n~~~~~~~~~~ Terimakasih telah menggunakan program ini, and as always take care ~~~~~~~~~~\n\n");
		printf("This program was made by : Emir Zaid, Kemas Rafly, Mikail Rahmansur, Qinthara Andini\n\n");
		printf("press any key to continue...");
	getch();
	system("cls");		//baris 14, 17 dan 18 ada agar program ini terlihat rapih dengan menghilangkan segala macam informasi yang terlihat yang ada diatasnya
}

int failCondition(void){		//fail condition yang berarti jika terdapat sebuah angka yang tidak sesuai pilihan maka function ini akan muncul
	system("cls");
		printf("xxxxxXXXXX Maaf pilihan anda salah, harap pilih ulang XXXXXxxxxx\n\n");
		printf("press any key to continue...");
	getch();
	system("cls");			//sama seperti sebelumnya pada barus 23, 26 dan 27 akan menghapus segala informasi dari sebelumnya agar tampilan terlihat rapih
}

int helpCondition(void){		//help condition membantu user cara/manual dalam menggunakan program ini
	system("cls");
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n\n");
		printf("Disini Kami akan menunjukkan cara kerja program kami.. \n\n");
		printf("Disini kami membuat program yang dapat mendata semua pasien yang datang dan/atau ada di dalam rumah sakit\n\n");
		printf("Pertama terdapat 5 pilihan main menu yaitu Input, Edit, Cek, Help, dan EXIT\n\n");
		printf("Pada pilihan pertama yaitu input user akan diminta untuk memasukkan nama dan kondisi sebuah pasien yang datang ke rumah sakit\n\n");
		printf("Input yang dimasukkan maksimal 1000 input");
		printf("Selanjutnya pilihan kedua user dapat merubah kondisi pasien yang ada didalam rumah sakit\n\n");
		printf("Selanjutnya pilihan ketiga user dapat melihat semua data pasien yang telah diinputkan dan juga yang telah diedit\n\n");
		printf("Selanjutnya pilihan keempat user mendapatkan panduan mengenai program ini\n\n");
		printf("Terakhir pilihan kelima user dapat keluar dari program ini.\n\n");
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=\n");
		printf("\npress any key to continue...");
	getch();
	system("cls");				//sama seperti sebelumnya pada barus 31, 42 dan  akan menghapus segala informasi dari sebelumnya agar tampilan terlihat rapih
}		

int main() {
	pasien *ptr; 				// menghubungkan struct ke pasien
    int i, selection, selectionPasien, sentinel, jumlahPasien = 0, exitStatus = 0;	//terdapat beberapa variabel
    int parselection1 = 0;		//parameter selection 1 ini maksudnya adalah jika tidak ada input data pasien maka akan memunculkan sebuah fail condition

    printf("=~=~=~=~=~= Selamat datang di Pusat Informasi Pasien Covid-19 (PIPC) =~=~=~=~=~=\n\n");		//awal dan/atau judul program

	do{	
	sentinel = 0;				//sentinel disini berguna untuk melakukan loop if yang ada pada line 63
	printf("Silahkan memasukkan nomor sesuai dengan menu yang ingin dipilih ");
	printf("\n\nInput Data	(1)\nEdit Data	(2)\nCek Data	(3)\nHelp		(4)\nExit		(5)\n\nMasukkan sesuai nomor: ");
    scanf(" %d",&selection);	//user akan diminta untuk memilih angka yang sesuai

	if(selection == 5){			//jika user memilih angka 5 pada selection
		exitCondition();		//maka akan di passing ke function exitCondition
		exitStatus = 1;
		free(ptr);
	}
	
	if(selection == 1){			//jika user memilih angka 1 pada selection yaitu input data
		system("cls");
		while(sentinel != -1){	//sentinel ini akan mengecek selama angkanya bukan -1 maka if loop ini akan selalu lanjut
        	if(jumlahPasien == 0){
				ptr = (pasien*)calloc(1000, sizeof(struct pasien));		//disini akan terjadi sebuah proses pengalokasian memori
				if (ptr == NULL){
					printf("Error, Memory not allocated.\n");			//jika memori tidak bisa dialokasikan maka akan muncul message ini
					exit(0);
			}
		}	
			if(jumlahPasien == 1000){
				printf("Maaf total input sudah 1000/1000 (FULL) anda tidak bisa memasukkan input lagi");
				continue;
			}
			else{
				jumlahPasien++;												//seiring bertambahnya input pasien maka variabel ini juga akan bertambah
				printf("=~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~=\n");
				printf("Pasien ke %d/1000\n", ++i);
        
        		printf("Masukkan nama : ");									//disini user akan diminta untuk memasukkan nama
        		scanf(" %[^\n]s",&(ptr+i)->nama);							//dan dimasukkan ke struck bagian nama
        
        		printf("Kondisi Pasien:\n\nSehat			(1)\nPositif Covid-19	(2)\nMeninggal		(3)\n\nMasukkan sesuai nomor:");
        		scanf("%d",&(ptr+i)->kondisi);								//disini user akan diminta untuk memberikan kondisi pasien yang tadi telah diinput					
																		//dan juga akan dimasukkan ke struct bagian kondisi
				printf("Tekan -1 jika ingin exit, jika tidak tekan 1: ");	//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        		scanf("%d",&sentinel);										//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
        		printf("\n");
			}
		}
		parselection1 = 1;								//parameter selection akan berubah menjadi 1 jika input data pasien telah dilakukan user		
		printf("press any key to continue...");
		getch();						//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");					//bisa kita anggap seperti mengubah halaman baru															
	}

	else if(selection == 2){			//bagian ini akan jalan di user memilih angka 2 pada selection yaitu edit data
		system("cls");
		if(parselection1 == 1){			//disini bisa kita lihat bahwa jika parameter selection bernilai 1 maka akan menjalankan if bagian ini
			printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~");
			printf("\nKondisi Pasien:\n\nSehat			(1)\nPositif Covid-19	(2)\nMeninggal		(3)\n\n");
			for (i = 0; i < jumlahPasien; ++i ){
	    	printf("\n(%d)	%s", i+1, (ptr+i+1)->nama);		//disini program akan menunjukkan semua pasien yang telah diinputkan oleh user sebelumnya
	    	printf("	%d\n\n", (ptr+i+1)->kondisi);
		}
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
    	while (sentinel != -1) {			//disini disaat variabel sentinel tidak bernilai -1 maka akan melanjutkan loop ini, jika iya maka akan keluar loop
		printf("Silahkan memasukkan nomor pasien yang anda ingin edit kondisi: ");
		scanf("%d",&selectionPasien);						//disini user diminta untuk memasukkan angka sesuai dengan urutan pasien untuk diedit kondisinya
		
		printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
		printf("\n\nNama Pasien: %s\n",&(ptr+selectionPasien)->nama);	
		printf("Kondisi Pasien:\n\nSehat			(1)\nPositif Covid-19	(2)\nMeninggal		(3)\n\nMasukkan sesuai nomor: ");
        scanf("%d",&(ptr+selectionPasien)->kondisi);		//kondisi pasien yang dipilih akan diubah sesuai pilihan terbaru dari user					
	
		printf("\n\nTekan -1 jika ingin exit, jika tidak tekan 1: ");	//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        scanf("%d",&sentinel);											//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
		}
	}
		else{					//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
			system("cls");
				printf("Maaf belum ada data yang diinputkan\n\nHarap menginputkan data terlebih dahulu\n");
			}				//terdapat pesan yang menandakan bahwa belum ada input data pasien dari user	
		printf("\npress any key to continue...");		
		getch();				//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");
	}
	
	else if(selection == 3){	//bagian ini akan jalan di user memilih angka 3 pada selection yaitu cek data
		system("cls");
		if(parselection1 == 1){			//disini bisa kita lihat bahwa jika parameter selection bernilai 1 maka akan menjalankan if bagian ini
			while (sentinel != -1) {	//disini disaat variabel sentinel tidak bernilai -1 maka akan melanjutkan loop ini, jika iya maka akan keluar loop
			for (i = 0; i < jumlahPasien; i++ ){		//for loop disini akan menunjukkan semua data pasien yang telah diinputkan serta yang sudah diedit 
				switch((ptr+i+1)->kondisi){				//dengan menggunakan switch case dapat menampilkan 3 macam kondisi pasien
					case 1:
						printf("(Sehat)			%s\n", (ptr+i+1)->nama);
						break;
					case 2:
						printf("(Positif COVID-19)	%s\n", (ptr+i+1)->nama);
						break;
					case 3:
						printf("(Meninggal)		%s\n", (ptr+i+1)->nama);
						break;
					default:
						printf("Invalid input. \n");
        				printf("Masukkan Input yang benar!\n");
        				continue;
				}	
			}
			printf("\nTekan -1 jika ingin exit, jika tidak tekan 1: ");		//disini user akan diminta memilih untuk exit dari loop ini atau tidak
        	scanf("%d",&sentinel);											//serta akan dimasukkan ke variabel sentinel yang nanti di atas akan dicek lagi
			}	
		}	
		else{						//disini terdapat kondisi else dari parameter selection tadi jika tidak bernilai 1
			system("cls");
				printf("Maaf belum ada data yang diinputkan\n\nHarap menginputkan data terlebih dahulu\n");
			}				//terdapat pesan yang menandakan bahwa belum ada input data pasien dari user
			printf("\npress any key to continue...");	
		getch();						//sama seperti sebelumnya ini dilakukkan agar program terlihat rapih dengan menghapus informasi yang terlihat sebelumnya
		system("cls");	
	}
		
	else if(selection == 4){			//bagian ini akan jalan di user memilih angka 4 pada selection yaitu help 
			helpCondition();			//akan di passing ke function helpCondition
	}
		
	else if(exitStatus != 1 ){ 			//bagian ini akan berjalan jika user memilih angka selain 1-5 yang telah disediakan pada awal dan kondisi belum exit 
		failCondition();				//akan di passing ke function failCondition
		}
	}
while(exitStatus != 1);				//while loop ini akan berjalan selama nilai exit tidak bernilai 1
return 0;
} 
