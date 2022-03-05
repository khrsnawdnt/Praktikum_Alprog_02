#include<stdio.h>
#include<stdlib.h>
void satu (); 
void dua ();

main () {

int pil,pilih;

	
	printf("\n\n");
	printf("|===================== SELAMAT DATANG ===================|\n");
	printf("|               PROGRAM KONVERSI BILANGAN                |\n");
	printf("|========================================================|\n");
	
	printf ("\n");
	printf("1. Desimal ke Biner \n");
	printf("2. Biner Ke Desimal \n");
	lagi :
		
	printf ("\n");
	printf("Masukan pilihan : ");
	scanf("%d", &pil);

	 if (pil == 1)
		satu ();
	 else if (pil == 2)
		dua ();
	printf("Ingin Melakukan Konversi  [y/t] ?? ");
	pilih = getchar ();
	scanf("%c", &pilih);
	 if (pilih== 'Y' || pilih== 'y') goto lagi;
	 else if (pilih== 'T' || pilih== 't') exit (0);

}


void satu ()
{
int bil, desi, hasil, basis = 1, biner = 0;
   
    printf("Masukan Bilangan Desimal = ");
    scanf("%d", &bil);
    desi = bil;
   	 while (bil>0){
        hasil= bil%2;
        biner = biner + hasil*basis;
        bil=bil/2;
        basis= basis*10;
   	 }
    printf("Hasil Biner adalah = %d\n", biner);
	
}



void dua ()
{
int biner,desi,bobot, digit;
bobot=1;
desi=0;
	printf("Masukkan Bilangan Biner: ");
	scanf("%d",&biner);
	while (biner!=0){
		digit= biner %10;
		desi=desi+(digit*bobot);
		bobot=bobot*2;
		biner=biner/10;
	}
	printf("Hasil Desimal Adalah: %d\n",desi);
}
