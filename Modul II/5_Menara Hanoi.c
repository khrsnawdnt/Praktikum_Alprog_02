#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char tower[3] = {'A', 'B', 'C'};
void header();
void hanoiRekursif(int cakram, int x, int y, int z);
void hanoiIteratif(int total_langkah);
void inputUlang();
void validMenu();
void validInput();
void validUlangi();
void clean();


int main(){
	int jml_cakram, menu, total_langkah;

	system("cls");
	fflush(stdin);	 		
	header();	 
	printf("\n\n\t\t\t Silahkan Pilih : \n");
	printf("\t\t\t [1] Menara Hanoi Iteratif \n");
	printf("\t\t\t [2] Menara Hanoi Rekursif \n");
	printf("\t\t\t [0] Exit \n");
	validMenu(&menu, "\n\t\t\t >>> Silahkan Masukkan Pilihan Anda : ");
		 	
	if (menu == 0){
		system("cls");
		printf ("\n\n\t\t\t\t Terimakasih!");
		return 0;
	}

	validInput(&jml_cakram, "\n\t\t\t Masukan Jumlah Cakram : ");
	system("cls");
	total_langkah = (int)pow(2, jml_cakram);
		
	if (menu == 1){
		header();
		printf("\n\t\t\t Menara Hanoi Iteratif \n\n");
		hanoiIteratif(total_langkah);
	}	
	
	else if (menu == 2){
		header();
		printf("\n\t\t\t Menara Hanoi Rekursif \n\n");
		hanoiRekursif(jml_cakram, 0, 1, 2);
	}
	printf("\n\t\t\t Jumlah Minimal Langkah yang diperlukan adalah : %d ", total_langkah-1);
	inputUlang();
	return 0;
}


void header(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t                   Praktikum Modul 2                   \n");
	printf("\t\t\t\t            Kelompok 2 - Program Menara Hanoi          \n");
	printf("\t\t\t\t ++--------------------------------------------------++\n");
}


void hanoiRekursif(int cakram, int x, int y, int z){
	if (cakram > 0){
		hanoiRekursif(cakram - 1, x, z, y);
		printf("\t\t\t Pindahkan piringan dari Tower %c ke Tower %c \n", tower[x], tower[z]);
		hanoiRekursif(cakram - 1, y, x, z);
	}
}


void hanoiIteratif(int total_langkah){
	int i;
 	for( i = 1; i < total_langkah; i++){
 		printf("\t\t\t Pindahkan piringan dari Tower %c ke Tower %c \n", tower[(i -(i & -i)) % 3], tower[(i + (i & -i)) % 3]);
 	}
}


void clean(){
 /*untuk mengosongkan karakter yang tersimpan di dalam buffer sampai ketemu karakter newline (‘\n’).*/
 	while (getchar() != '\n');
}


void inputUlang(){
	int pilih;
	int n;
 
	printf("\n\n\t\t\t================================================\n");
	printf("\n\t\t\t Ingin Ulangi Program?");
	printf("\n\t\t\t [1] Ya \n");
	printf("\t\t\t [2] Tidak, Exit Program\n");
	validUlangi(&pilih, "\n\t\t\t Masukan Pilihan : ");
	
	if(pilih == 1){
		system("cls");	
		main();
	}
	else if(pilih == 2){
		system("cls");
		printf ("\n\n\t\t\t\t Terimakasih!");
		exit(0);
	}
}


/* Validasi Input Angta */

int validInt(int *var){
	char buff[1024];
	char cek;
		
		fflush(stdin);
		if(fgets(buff, sizeof(buff), stdin) != NULL){
			if(sscanf(buff, "%d %c", var, &cek) == 1) {
				return 1;
			}
		}
		return 0;
}

// Validasi Jika Input Bukan Berupa Angka
void validAngka(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validInt(var))
			break;
	printf("\t\t\t HANYA MENERIMA INPUT ANGKA!. Masukkan ulang angka \n");
	}	
}

// Validasi Input pada Menu Utama
void validMenu(int *var, char *prompt){
	while(1){
		validAngka(var, prompt);
		if(*var >=0 && *var <=2)
			break;
	printf("\t\t\t INPUT TIDAK VALID! Pilih antara 0, 1 atau 2.\n");
	}
}

// Validasi pada Input Jumlah cakram
void validInput(int *var, char *prompt){
	while(1){
		validAngka(var, prompt);
		if(*var >0 && *var <=50)
			break;
	printf("\t\t\t INPUT TIDAK VALID! Masukan angka diatas 0 dan tidak lebih dari 50! \n");
	}
}

// Validasi pada Input Ulangi Program
void validUlangi(int *var, char *prompt){
	while(1){
		validAngka(var, prompt);
		if(*var == 1 || *var == 2)
			break;
	printf("\t\t\t INPUT TIDAK VALID! Pilih antara 1 atau 2.\n");
	}
}

