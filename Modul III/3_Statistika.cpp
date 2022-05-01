#include <stdio.h>
#include <stdlib.h>
void Menu_mean (); 
void Menu_median ();
void Menu_modus();
void Menu ();
void Exit();


// VALIDASI untuk menu utama
int validasi(){
    int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n'|| bilangan<0){
        printf("--- Masukkan Bilangan 1-4! ---\n");
        printf("\nMasukKan Ulang: ");
        fflush(stdin);
        validasi();
    }
	else{
        return bilangan;
    }
}

// CEK VALIDASI  untuk menu 1 2 3 
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



// rumus untuk mean
float mean(int *data, int jumlah_data){
	int i;
	float sum=0;
	for(i=1 ; i<=jumlah_data ; i++){
		sum = sum + data[i];
	}
	float avg = sum/(float)jumlah_data;
	return (avg);
}




float median(float *data, int jumlah_data){
	float hasil;
	if(jumlah_data%2==0){
		hasil = (data[(jumlah_data/2)] + data[(jumlah_data/2)+1]) /2;
	}else{
		hasil = data[(jumlah_data/2)+1];
	}
	return hasil;
}





void modus(int n, int *data){
	int z=0, x=0, k=1, i, j; 
	int total[n];
	float mod[n];
	float temp;


//menghitung berapa kali muncul tiap angka 
	for(i=0;i<n;i++){
		total[i]=0;
		for(j=0;j<n;j++){
			if(data[i]==data[j]){
				total[i]++;
			}
		}
	}
	
	//menentukan nilai yang paling sering muncul 
	for(i=0;i<n;i++){
		if(total[i]>k){
			k=total[i];
		}
	}
	
	//jika modus lebih dari satu 
	for(i=0;i<n;i++){
		if(x==0){
			mod[x]=0;
		}else{
			mod[x]=mod[x-1];
		}
		if(total[i]==k){
			if(data[i]!=mod[x]){
				mod[x]=data[i]; 
				x++;
			}
		}
	}
	
	//Jika Semua angka muncul sama banyak 
	for(i=0;i<n;i++){
		if(total[i]==k){
		z++;
		}
	}
	if(z==n){ 
		x=0;
	}
	
	if (x==0){
		printf("\nTidak ada modus dari data tersebut!\n");
	}else{
		printf("\nHasil Dari Modus Adalah: "); 
		for(i=0;i<x;i++){
			printf(" %.0f", mod[i]);
			
			if(i<x-1){
				printf(",");
			}
		}
		printf("\n");
	}
}




// menu untuk Mean

void Menu_mean(){
	int masukan;
	int data[100];
	int i;
	float hasil_mean;
	int pilih;
	
	system("cls");
	printf("           >>|MENGHITUNG MEAN|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = cek_valid();	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = cek_valid();
    }
    
    hasil_mean = mean(data,masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Mean\t: %.2f" ,hasil_mean);
 	
 	do{
 	printf("\n\n");	
	printf("1. Ulangi\n");
	printf("2. Menu Utama\n");
	printf("3. Keluar\n");
	printf("Pilihan Selanjutnya	: ");
	pilih=cek_valid();
	switch (pilih){
		case 1:
			Menu_mean();
			break;
		case 2:
			Menu();
			break;
		case 3:
			Exit();
		default:
			printf("EROR! \n\n");
	
	}
}
		while(pilih !=0);

}
	
	
// Menu Untuk Median
void Menu_median(){
	int masukan;
	float data[100];
	int i;
	float hasil_median;
	int pilih;
	
	system("cls");
	printf("           >>|MENGHITUNG MEDIAN|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan=cek_valid();	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = cek_valid();
    }
    
    hasil_median = median(data,masukan);
    printf("\n-----------------------------------\n");
 	printf("Nilai Median\t: %.2f" ,hasil_median);
	
	do{
 	printf("\n\n");	
	printf("1. Ulangi\n");
	printf("2. Menu Utama\n");
	printf("3. Keluar\n");
	printf("Pilihan Selanjutnya	: ");
	pilih=cek_valid();
	switch (pilih){
		case 1:
			Menu_median();
			break;
		case 2:
			Menu();
			break;
		case 3:
			Exit();
		default:
			printf("EROR! \n\n");
	
	}
}
		while(pilih !=0);

}
	

// Menu untuk Modus
void Menu_modus(){
	int masukan;
	int data[100];
	int i;
	int pilih;
	
	system("cls");
	printf("           >>|MENGHITUNG MODUS|<<             \n");
	printf("=========================================\n\n\n");
    fflush (stdin);
	printf("Masukkan jumlah data : ");
	masukan = cek_valid();	
	
	for(i=1; i<= masukan; i++){
		printf("Masukkan Data Ke-%d : ", i);
		data[i] = cek_valid();
    }
    
    printf("\n-----------------------------------\n");
 	modus(masukan, data);
	
	do{
 	printf("\n\n");	
	printf("1. Ulangi\n");
	printf("2. Menu Utama\n");
	printf("3. Keluar\n");
	printf("Pilihan Selanjutnya	: ");
	pilih=cek_valid();
	switch (pilih){
		case 1:
			Menu_modus();
			break;
		case 2:
			Menu();
			break;
		case 3:
			Exit();
		default:
			printf("EROR! \n\n");
	
	}
}
		while(pilih !=0);

}
	

	
	
	


// Menu Keluar

void Exit(){
	printf("Terimakasih Sudah Menggunakan Program Ini");
	exit(0);
}


// Menu Utama

void Menu(){
	int pilih;
	system("cls");
	printf("===================================================\n");
	printf("|                PROGRAM STATISTIKA               |\n");
	printf("===================================================\n\n\n");

	printf("    +----------------------------------------+\n");
	printf("    |                  MENU                  |\n");
	printf("    +----------------------------------------+\n");
	printf("    |         1. Menghitung Mean             |\n");
	printf("    |         2. Menghitung Median           |\n");
	printf("    |         3. Menghitung Modus            |\n");
	printf("    |         4. Tutup Program               |\n");
	printf("    +----------------------------------------+\n\n\n");
	
	do{
	
	printf("MasukKan Pilihan Menu:");
	pilih=validasi();
	
	switch(pilih){
		case 1:
			Menu_mean();
			break;
		case 2:
			Menu_median();
			break;
		case 3:
			Menu_modus();
			break;
		case 4:
			Exit();
			break;
		default:
			printf("EROR! \n\n");
		}
	
		
	} while(pilih !=0);
}

int main(){
	Menu();
return 0;
}
