#include <stdio.h>

int invalid(){
	fflush(stdin);
	system("cls");

	int pilihan;
	int cekerror=0;
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|         Program Matriks         |\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	printf("\t\t\t\t\tInput anda tidak valid\n");
	printf("\t\t\t\t\tKembali ke menu utama?\n");
	printf("\t\t\t\t\t[1] Ya\n");
	printf("\t\t\t\t\t[0] Tutup Program\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\tJawaban: ");
	masukkanAngka(&pilihan,&cekerror,0,1);
	if(cekerror==1){
		return invalid();
	}
	
	if(pilihan==0){
		return tutupProgram();
	}
	else if(pilihan==1){
		return main();
	}
	
}

int masukkanAngka(int* pilihan, int* cekerror, int skalaBawah,int skalaAtas){
	
	char sementara[255];
	char tampungNewline;
	
	while(1){
		fgets(sementara,sizeof(sementara),stdin);
		if(sscanf(sementara,"%d %s",pilihan,&tampungNewline)==1){
			if(*pilihan<skalaBawah||*pilihan>skalaAtas){
				fflush(stdin);
				*cekerror=1;
				return;
			}	
			return;
		}	
		else{
			fflush(stdin);
			*cekerror=1;
			return;
		}
	}
}

int masukkanMatriks(int* cekerror, int baris, int kolom, int matriks[baris][kolom]){
	int counterBaris;
	int counterKolom;
	int jawaban;

	for(counterBaris=1;counterBaris<=baris;counterBaris++){
		for(counterKolom=1;counterKolom<=kolom;counterKolom++){
			printf("\t\t\t\t\tMasukkan Nilai Untuk Baris[%d] Kolom[%d]: ",counterBaris,counterKolom);
			
			//masukkan angka ke variabel jawaban
			masukkanAngka(&jawaban,cekerror,-999,999);
			if(*cekerror==1){
				return;
			}	
			matriks[counterBaris-1][counterKolom-1]=jawaban;
		}
	}
	
	return;
}

int ulangProgram(int* ulang){
	int cekerror=0;
	
	printf("\t\t\t\t\tIngin mengulang program?\n");
	printf("\t\t\t\t\t[1] Ya\n");
	printf("\t\t\t\t\t[0] Kembali\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\tJawaban: ");
	
	//masukkan pilihan ke variabel jawaban
	masukkanAngka(ulang,&cekerror,0,1);
	if(cekerror==1){
		return invalid();
	}
	
	return;
	
}

int tutupProgram(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|         Program Matriks         |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	printf("\t\t\t\t\t        - Selamat tinggal -");
	Sleep(1000);
	return 0;
}

int penjumlahanMatriks(){
	int cekerror=0;
	int ulang=0;
	
	system("cls");
	
	//deklarasi variabel
	int baris;
	int kolom;
	int counterBaris;
	int counterKolom;
	int jawaban;
	
	//header + pemasukan baris & kolom matriks
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|       Penjumlahan Matriks       |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	
	//masukkan angka ke variabel baris
	printf("\t\t\t\t\tBaris Matriks: ");
	masukkanAngka(&baris,&cekerror,1,255);
	if(cekerror==1){
		return invalid();
	}
	
	//masukkan angka ke variabel kolom
	printf("\t\t\t\t\tKolom Matriks: ");
	masukkanAngka(&kolom,&cekerror,1,255);
	if(cekerror==1){
		return invalid();
	}
	
	//deklarasi variabel sesuai input
	int matriksAwal[baris][kolom];
	int matriksSelanjutnya[baris][kolom];
	int matriksHasil[baris][kolom];

	printf("\n");
	
	//Menginputkan nilai ke dalam matriks awal
	printf("\t\t\t\t\tMatriks Awal:\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	masukkanMatriks(&cekerror,baris,kolom,matriksAwal);
	if(cekerror==1){
		return invalid();
	}	
	
	printf("\n");
	
	//Menginputkan nilai ke dalam matriks Selanjutnya
	printf("\t\t\t\t\tMatriks Selanjutnya:\n");
	printf("\t\t\t\t\t----------------------\n");
	masukkanMatriks(&cekerror,baris,kolom,matriksSelanjutnya);
	if(cekerror==1){
		return invalid();
	}	
	
	//Clear screen untuk menampilkan hasil
	system("cls");
	
	//print header
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|       Penjumlahan Matriks       |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	
	//print Matriks Awal
	printf("\n");
	printf("\t\t\t\t\t Nilai Matriks Awal:");
	counterBaris=1;
	while(counterBaris<=baris){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=kolom){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksAwal[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}

	printf("\n");
	
	//print matriks selanjutnya
	printf("\n");
	printf("\t\t\t\t\t Nilai Matriks Selanjutnya:");
	counterBaris=1;
	while(counterBaris<=baris){
		printf("\n");		
		counterKolom=1;
		while(counterKolom<=kolom){			
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksSelanjutnya[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}
	
	
	
	//Proses penjualan matriks
	for(counterBaris=0;counterBaris<baris;counterBaris++){
		for(counterKolom=0;counterKolom<kolom;counterKolom++){
			jawaban = matriksAwal[counterBaris][counterKolom] + matriksSelanjutnya[counterBaris][counterKolom];
			matriksHasil[counterBaris][counterKolom] = jawaban;
		}
	}
	
	printf("\n");
	
	//Print hasil penjumlahan matriks
	printf("\n");
	printf("\t\t\t\t\t Hasil Penjumlahan Matriks:");
	counterBaris=1;
	while(counterBaris<=baris){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=kolom){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksHasil[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}	
	
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\tProgram telah selesai\n");
	ulangProgram(&ulang);
	if(ulang==1){
		return penjumlahanMatriks();
	}
	else if(ulang==0){
		return main();
	}
	
}

int perkalianMatriks(){
	int cekerror=0;
	int ulang=0;
	int jawaban=0;
	int baris1;
	int kolom1;
	int baris2;
	int kolom2;	
	int counterBaris;
	int counterKolom;
	int counterJumlah;
	
	system("cls");
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Perkalian Matriks        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");

	
	printf("\t\t\t\t\tBaris Matriks Awal: ");
	masukkanAngka(&baris1,&cekerror,1,999);
	if(cekerror==1){
		return invalid();
	}	
	
	printf("\t\t\t\t\tKolom Matriks Awal: ");
	masukkanAngka(&kolom1,&cekerror,1,999);
	if(cekerror==1){
		return invalid();
	}	
	
	
	printf("\t\t\t\t\tBaris Matriks Selanjutnya: ");
	masukkanAngka(&baris2,&cekerror,1,999);
	if(cekerror==1){
		return invalid();
	}	
	
	printf("\t\t\t\t\tKolom Matriks Selanjutnya: ");
	masukkanAngka(&kolom2,&cekerror,1,999);
	if(cekerror==1){
		return invalid();
	}		
	
	printf("\n");
	
	//Jika matriks tidak dapat dikalikan
	if(kolom1 != baris2){
		printf("\t\t\t\t\tMatriks tidak memenuhi persyaratan\n");
		ulangProgram(&ulang);
		if(ulang==1){
			return perkalianMatriks();
		}
		else if(ulang==0){
			return main();
		}
		
	}
	
	//Deklarasi matriks jika dapat dikalikan
	int matriksAwal[baris1][kolom1];
	int matriksSelanjutnya[baris2][kolom2];
	int matriksHasil[baris1][kolom2];
	
	//Menginputkan nilai ke dalam matriks awal
	printf("\t\t\t\t\tMatriks Awal:\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	masukkanMatriks(&cekerror,baris1,kolom1,matriksAwal);
	if(cekerror==1){
		return invalid();
	}	
	
	printf("\n");

	//Menginputkan nilai ke dalam matriks selanjutnya
	printf("\t\t\t\t\tMatriks Selanjutnya:\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	masukkanMatriks(&cekerror,baris2,kolom2,matriksSelanjutnya);
	if(cekerror==1){
		return invalid();
	}		
	
	//Perhitungan hasil perkalian matriks
	for(counterBaris=0 ; counterBaris < baris1 ; counterBaris++){
		for(counterKolom=0 ; counterKolom < kolom2 ; counterKolom++){
			for(counterJumlah=0 ; counterJumlah < baris2 ; counterJumlah++){
				jawaban = jawaban + (matriksAwal[counterBaris][counterJumlah] * matriksSelanjutnya[counterJumlah][counterKolom]);
			}
			matriksHasil[counterBaris][counterKolom] = jawaban;
			jawaban=0;
		}
	}
	
	system("cls");
	
	//print header
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Perkalian Matriks        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	
	//print Matriks Awal
	printf("\n");
	printf("\t\t\t\t\t Nilai Matriks Awal:");
	counterBaris=1;
	while(counterBaris<=baris1){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=kolom1){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksAwal[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom1){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}	
	
	printf("\n");
		
	//print matriks selanjutnya
	printf("\n");
	printf("\t\t\t\t\t Nilai Matriks Selanjutnya:");
	counterBaris=1;
	while(counterBaris<=baris2){
		printf("\n");		
		counterKolom=1;
		while(counterKolom<=kolom2){			
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksSelanjutnya[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom2){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}

	printf("\n");
	
	//Print hasil perkalian matriks
	printf("\n");
	printf("\t\t\t\t\t Hasil Perkalian Matriks:");
	counterBaris=1;
	while(counterBaris<=baris1){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=kolom2){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksHasil[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom2){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}	
	
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\tProgram telah selesai\n");
	ulangProgram(&ulang);
	if(ulang==1){
		return perkalianMatriks();
	}
	else if(ulang==0){
		return main();
	}
	
}

int transposeMatriks(){
	int cekerror=0;
	int ulang=0;
	int jawaban;
	int baris;
	int kolom;
	int counterBaris;
	int counterKolom;
		
	system("cls");
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Transpose Matriks        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	
	//masukkan angka ke variabel baris
	printf("\t\t\t\t\tBaris Matriks: ");
	masukkanAngka(&baris,&cekerror,1,255);
	if(cekerror==1){
		return invalid();
	}
	
	//masukkan angka ke variabel kolom
	printf("\t\t\t\t\tKolom Matriks: ");
	masukkanAngka(&kolom,&cekerror,1,255);
	if(cekerror==1){
		return invalid();
	}
	
	
	//deklarasi sesuai input
	int matriksAwal[baris][kolom];
	int matriksHasil[kolom][baris];
	
	printf("\n");
	
	//Menginputkan nilai ke dalam matriks awal
	printf("\t\t\t\t\tMatriks Awal:\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	masukkanMatriks(&cekerror,baris,kolom,matriksAwal);
	if(cekerror==1){
		return invalid();
	}	
	
	//Proses Transpose Matriks
	for(counterBaris=0 ; counterBaris<kolom ; counterBaris++){
		for(counterKolom=0 ; counterKolom<baris ; counterKolom++){
			matriksHasil[counterBaris][counterKolom] = matriksAwal[counterKolom][counterBaris];
		}
	}
	
	system("cls");
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Transpose Matriks        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	
	//print Matriks Awal
	printf("\n");
	printf("\t\t\t\t\t Nilai Matriks Awal:");
	counterBaris=1;
	while(counterBaris<=baris){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=kolom){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksAwal[counterBaris-1][counterKolom-1]);
			if(counterKolom==kolom){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}

	printf("\n");
	
	//Print hasil transpose matriks
	printf("\n");
	printf("\t\t\t\t\t Hasil Transpose Matriks:");
	counterBaris=1;
	while(counterBaris<=kolom){
		printf("\n");	
		counterKolom=1;
		while(counterKolom<=baris){
			if(counterKolom==1){
				printf("\t\t\t\t\t [\t");
			}
			printf("%d\t",matriksHasil[counterBaris-1][counterKolom-1]);
			if(counterKolom==baris){
				printf("]");
			}
			counterKolom++;
		}
		counterBaris++;
	}	
	
	printf("\n");
	printf("\n");
	printf("\t\t\t\t\tProgram telah selesai\n");
	ulangProgram(&ulang);
	if(ulang==1){
		return transposeMatriks();
	}
	else if(ulang==0){
		return main();
	}		
		
}


int main(){
	fflush(stdin);
	system("cls");
	int pilihan;
	int cekerror=0;
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|         Program Matriks         |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	printf("\t\t\t\t\t[1] Penjumlahan Matriks\n");
	printf("\t\t\t\t\t[2] Perkalian Matriks\n");
	printf("\t\t\t\t\t[3] Transpose Matriks\n");
	printf("\t\t\t\t\t[4] Tutup Program\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\tJawaban: ");
	
	//Masukkan Angka ke Variabel Pilihan	
	masukkanAngka(&pilihan,&cekerror,1,4);
	if(cekerror==1){
		return invalid();
	}
	
	if(pilihan==1){
		return penjumlahanMatriks();
	}
	else if(pilihan==2){
		return perkalianMatriks();
		
	}
	else if(pilihan==3){
		return transposeMatriks();
	}	
	else if(pilihan==4){
		return tutupProgram();
	}
	
}
