#include <stdio.h>
#include <stdlib.h>

int enkripsi();
int dekripsi();
void header();
void inputUlang();
void validMenu();
void validInput();
void validUlangi();

int main(){
	int pilih;
	
	fflush(stdin);
	header();
	printf("\n\t\t\t Silahkan Pilih Operasi : \n");
	printf("\t\t\t [1] Enkripsi \n");
	printf("\t\t\t [2] Dekripsi \n");
	printf("\t\t\t [0] Exit \n");
	validMenu(&pilih, "\n\t\t\t >>> Silahkan Masukkan Pilihan Anda : ");
	switch(pilih){
		case 1:
			header();
			enkripsi();
		break;
		case 2:
			header();
			dekripsi();
		break;
		case 0:
			system("cls");
			printf("\t\t\t Terimakasih \n");
			exit(0);
		break;
	}
	inputUlang();
	return(0);
}

int enkripsi(){
	char s[100];
	int i, geser;
	
		printf("\n\t\t\t Silahkan Masukan Pesan yang ingin di-ENKRIPSI : ");
		gets(s);
		validInput(&geser, "\n\t\t\t Masukan jumlah Pergeseran : ");
		
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'A' && s[i] <= 'Z') {
 			s[i] = s[i] + 32;
		}
 	
		if(s[i] >= 'a' && s[i] <= 'z'){	
			s[i] = s[i] + geser;
			if(s[i] > 'z'){
				s[i] = s[i] - 26;
			}
			s[i] = s[i] -32;
		}
	}	
	printf("\n\t\t\t Hasil Enkripsi Pesan : %s", s);
	return 0;
}


int dekripsi(){
	char s[100];
	int i, geser;
	
		printf("\n\t\t\t Silahkan Masukan Pesan yang ingin di-DEKRIPSI: ");
		gets(s);
		validInput(&geser, "\n\t\t\t Masukan Jumlah Pergeseran : ");
		
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 32;
 		}
 
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] - geser;
			if(s[i] < 'A'){
				s[i] = s[i] + 26;
			}
			s[i] = s[i] +32;
		}	
	}
	printf("\n\t\t\t Hasil Dekripsi Pesan : %s", s);
	return 0;
}


void header(){
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t                   Praktikum Modul 3                   \n");
	printf("\t\t\t\t        Kelompok 2 - Program Enkripsi & Dekripsi       \n");
	printf("\t\t\t\t ++--------------------------------------------------++\n");
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

// Validasi pada Input Jumlah pergeseran
void validInput(int *var, char *prompt){
	while(1){
		validAngka(var, prompt);
		if(*var >0)
			break;
	printf("\t\t\t INPUT TIDAK VALID! Masukkan diatas 0 (nol) \n");
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




