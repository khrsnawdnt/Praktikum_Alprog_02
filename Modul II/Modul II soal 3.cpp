#include <stdio.h>
#include <stdlib.h>
void Satu (); 
void Dua ();
void Menu();
void Exit();

// VALIDASI

int validasi(){
    int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n'|| bilangan<0){
        printf("--- Masukkan Bilangan 1-3! ---\n");
        printf("\nMasukKan Ulang: ");
        fflush(stdin);
        validasi();
    }
	else{
        return bilangan;
    }
}

// CEK VALIDASI 

int cek_valid();
int cek_valid(){
    int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n' || bilangan<0){
        printf("\tERROR!");
        printf("\n\tMasukan Ulang: ");
        fflush(stdin);
        cek_valid();
    }
	else{
        return bilangan;
    }
}


// Konversi Desimal Ke Biner

void Satu(){
	int bil, desi, pilih ,sisa, basis = 1, biner = 0;
	system ("cls");
	printf("==================================\n");
	printf("|	Desimal Ke Biner	|\n");
	printf("==================================\n\n");
	printf("Masukkan Bilangan Desimal	: ");
	bil=cek_valid();
	while (bil>0){
        sisa= bil%2;
        biner = biner + sisa*basis;
        bil=bil/2;
        basis= basis*10;
   	 }
	printf("Hasil Biner 	: %.d\n", biner);
	printf("---------------------------------  \n\n\n");
	
	do{
	printf("1. Ulangi Konversi\n");
	printf("2. Menu Utama\n");
	printf("3. Keluar\n");
	printf("Pilihan Selanjutnya	: ");
	pilih=cek_valid();
	switch (pilih){
		case 1:
			Satu();
			break;
		case 2:
			Menu();
			break;
		case 3:
			Exit();	
		}

	} while(pilih !=0);
}

// Konversi Biner Ke Desimal

void Dua (){
	int biner,angka,pilih, desi,bobot, digit;
	bobot=1;
	desi=0;
	system ("cls");
	printf("==================================\n");
	printf("|	Biner Ke Desimal	|\n");
	printf("==================================\n\n");
	printf("Masukkan Bilangan Biner	: ");
	biner=cek_valid();
	while (biner!=0 ){
		digit= biner %10;
		desi=desi+(digit*bobot);
		bobot=bobot*2;
		biner=biner/10;
	}	
	printf("Hasil Desimal : %d\n",desi);
	printf("---------------------------------  \n\n\n");
	
	do{
	printf("1. Ulangi Konversi\n");
	printf("2. Menu Utama\n");
	printf("3. Keluar\n");
	printf("Pilihan Selanjutnya	: ");
	pilih=cek_valid();
	switch (pilih){
		case 1:
			Dua();
			break;
		case 2:
			Menu();
			break;
		case 3:
			Exit();
		}
	}while(pilih !=0);
}

// Menu Keluar

void Exit(){
	printf("Terimakasih Sudah Melakukan Konversi");
	exit(0);
}

// Menu Utama

void Menu(){
	int pilih;
	system ("cls");
	printf("=======================================\n");
	printf("|	KONVERSI BILANGAN			|\n");
	printf("=======================================\n");
	printf(" 1. Desimal Ke Biner\n");
	printf(" 2. Biner Ke Desimal\n");
	printf(" 3. Exit\n");
	
	do{
	
	printf("MasukKan Pilihan Menu	:");
	pilih=validasi();
	
	switch(pilih){
		case 1:
			Satu();
			break;
		case 2:
			Dua();
			break;
		case 3:
			Exit();
			break;	
		}
	} while(pilih !=0);
}

int main(){
	Menu();
return 0;
}
