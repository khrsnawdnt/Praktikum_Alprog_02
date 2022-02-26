#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SegitigaSembarang();
void BelahKetupat();
void JajarGenjang();
void Trapesium();
void Lingkaran();

int main(){
	int pilihan;
	printf ("\t\t Program Bangun Datar\n");
	printf ("\t\t ________________________\n\n");
	printf ("\t\t 1. Segitiga Sembarang \n");
	printf ("\t\t 2. Belah Ketupat\n");
	printf ("\t\t 3. Jajar Genjang\n");
	printf ("\t\t 4. Trapesium\n");
	printf ("\t\t 5. Lingkaran\n");
	printf ("\t\t Pilih bangun datar untuk dihitung : ");
	scanf ("%d", &pilihan);
	
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

}

void SegitigaSembarang(){
	int s1, s2, s3, kll;
	float sp, luas;
	
	system("cls");
	printf ("\t\t Menghitung Luas dan Keliling Segitiga Sembarang\n\n");
	printf ("\t\t Masukkan Panjang Sisi 1 : ");
	scanf ("%d", &s1);
	printf ("\t\t Masukkan Panjang Sisi 2 : ");
	scanf ("%d", &s2);
	printf ("\t\t Masukkan Panjang Sisi 3 : ");
	scanf ("%d", &s3);
	
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
	printf ("\t\t Menghitung Luas dan Keliling Belah Ketupat\n\n");
	printf ("\t\t Masukkan Panjang Diagonal 1 : ");
	scanf ("%d", &d1);
	printf ("\t\t Masukkan Panjang Diagonal 2 : ");
	scanf ("%d", &d2);
	printf ("\t\t Masukkan Panjang Sisi Miring : ");
	scanf ("%d", &s_miring);
	
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
	printf ("\t\t Menghitung Luas dan Keliling Jajar Genjang\n\n");
	printf ("\t\t Masukkan Panjang Sisi Miring : ");
	scanf ("%d", &s_miring);
	printf ("\t\t Masukkan Panjang Alas : ");
	scanf ("%d", &alas);
	printf ("\t\t Masukkan Tinggi : ");
	scanf ("%d", &tinggi);
	
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
	printf ("\t\t Menghitung Luas dan Keliling Trapesium\n\n");
	printf ("\t\t Masukkan Panjang Sisi Atas : ");
	scanf ("%d", &s_atas);
	printf ("\t\t Masukkan Panjang Sisi Bawah : ");
	scanf ("%d", &s_bawah);
	printf ("\t\t Masukkan Panjang Sisi Miring 1 : ");
	scanf ("%d", &s_miring1);
	printf ("\t\t Masukkan Panjang Sisi Miring 2 : ");
	scanf ("%d", &s_miring2);
	printf ("\t\t Masukkan Tinggi : ");
	scanf ("%d", &tinggi);
	
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
	printf ("\t\t Masukkan Panjang Jari-Jari : ");
	scanf ("%d", &r);
	
	kll = 2 * phi * r;
	luas = phi * r * r;
	
	printf ("\n\n");
	printf ("\t\t Jadi, Kelilingnya adalah : %.2f\n", kll);
	printf ("\t\t Jadi, Luasnya adalah : %.2f\n", luas);
}
