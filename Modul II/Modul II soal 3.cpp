#include<stdio.h>
#include<math.h>
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
int bil,biner=0,bobot=0;
	printf("Masukkan Bilangan Desimal : ");
	scanf("%d",&bil);

	while(bil>0){
	biner=biner+ bil%2*(int)pow(10,bobot);
	bil= bil/2;
	bobot++;
	}

	printf("Hasil Biner Adalah : %d\n",biner);
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

