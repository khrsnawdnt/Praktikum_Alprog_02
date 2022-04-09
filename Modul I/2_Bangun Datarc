#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void SegitigaSembarang();
void BelahKetupat();
void JajarGenjang();
void Trapesium();
void Lingkaran();
void correct(int *var, char *prompt);

char ulang;

int main(){
	do{
	
		int pilihan;
		system ("cls");
		printf ("\t\t Program Bangun Datar\n");
		printf ("\t\t ________________________\n\n");
		printf ("\t\t 1. Segitiga Sembarang \n");
		printf ("\t\t 2. Belah Ketupat\n");
		printf ("\t\t 3. Jajar Genjang\n");
		printf ("\t\t 4. Trapesium\n");
		printf ("\t\t 5. Lingkaran\n");
		printf ("\t\t ________________________\n");
		printf ("\t\t 0. Exit Program\n\n");
		correct(&pilihan,"\t\t Pilih bangun datar untuk dihitung : ");
		
		if (pilihan==1){
			SegitigaSembarang();
		}
		else if (pilihan==2){
			BelahKetupat();
		}
		else if (pilihan==3){
			JajarGenjang();
		}
		else if (pilihan==4){
			Trapesium();
		}
		else if (pilihan==5){
			Lingkaran();
		}
		else if (pilihan==0){
			system ("cls");
			printf ("\n\n\n\t\t\t\t\t Enter 1x untuk keluar\n\n\n");
			exit(0);
		}
		else{
			system ("cls");
			printf ("\n\t\t ANGKA TIDAK VALID, Masukkan ulang! (1-5)");
		}
		printf ("\n\t\t >> Coba input lagi? (y/t) : "); scanf ("%s", &ulang);
	}
	while (ulang=='Y' || ulang=='y');
		printf ("\n \t \t Terimakasih, tekan enter untuk keluar. \n");
		
		return 0;
}

void SegitigaSembarang(){
	int s1, s2, s3, kll;
	float sp, luas;
	
	system("cls");
	printf ("\t\t Menghitung Luas dan Keliling Segitiga Sembarang\n\n");
	printf ("\n\t\t Masukkan Panjang Sisi 1 : "); s1=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi 2 : "); s2=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi 3 : "); s3=validasi();

	
	kll = s1 + s2 + s3;
	sp = (s1 + s2 + s3) / 2;
	luas = sqrt (sp * (sp - s1) * (sp - s2) * (sp - s3));
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %d\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}

void BelahKetupat(){
	int s_miring, d1, d2, kll;
	float luas;
	
	system("cls");
	printf ("\n\t\t Menghitung Luas dan Keliling Belah Ketupat\n\n");
	printf ("\n\t\t Masukkan Panjang Diagonal 1 : "); d1=validasi();
	printf ("\n\t\t Masukkan Panjang Diagonal 2 : "); d2=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi Miring : "); s_miring=validasi();

	
	kll = 4*s_miring;
	luas = (d1*d2)/2;
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %d\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}

void JajarGenjang(){
	int s_miring, alas, tinggi, kll;
	float luas;
	
	system("cls");
	printf ("\n\t\t Menghitung Luas dan Keliling Jajar Genjang\n\n");
	printf ("\n\t\t Masukkan Panjang Sisi Miring : "); s_miring=validasi();
	printf ("\n\t\t Masukkan Panjang Alas : "); alas=validasi();
	printf ("\n\t\t Masukkan Tinggi : "); tinggi=validasi();

	kll = 2*(alas+tinggi);
	luas = alas * tinggi;
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %d\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}

void Trapesium(){
	int s_atas, s_bawah, s_miring1, s_miring2, tinggi, kll;
	float luas;
	
	system("cls");
	printf ("\n\t\t Menghitung Luas dan Keliling Trapesium\n\n");
	printf ("\n\t\t Masukkan Panjang Sisi Atas : "); s_atas=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi Bawah : "); s_bawah=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi Miring 1 : "); s_miring1=validasi();
	printf ("\n\t\t Masukkan Panjang Sisi Miring 2 : "); s_miring2=validasi();
	printf ("\n\t\t Masukkan Tinggi : "); tinggi=validasi();

	
	kll = s_atas + s_bawah + s_miring1 + s_miring2;
	luas = (s_atas + s_bawah) * tinggi /2;
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %d\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}

void Lingkaran(){
	int r;
	float phi=3.14, luas, kll;
	
	system("cls");
	printf ("\t\t Menghitung Luas dan Keliling Lingkaran\n\n");
	printf ("\n\t\t Masukkan Panjang Jari-Jari : "); r=validasi();
	
	kll = 2 * phi * r;
	luas = phi * r * r;
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %.2f\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}

int check(int *var){
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

//Validasi Inputan Angka
void correct(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(check(var))
			break;
		printf("\t\t Hanya Menerima Input ANGKA!\n");
		printf("\n");
	}
}

int validasi(){
	int angka;
    char karakter;
    scanf("%d%c", &angka, &karakter);
    if(karakter != '\n' || angka<0){
        printf("\t\t\t Hanya Menerima Input ANGKA!\n\n");
        printf("\n\t\t Masukkan ulang Angka : ");
        fflush(stdin);
        validasi();
    }
	else{
        return angka;
    }
}
