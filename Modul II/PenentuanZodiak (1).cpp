// Online C compiler to run C program online
#include<iostream>
#include<stdio.h>
#include<stdbool.h> 
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int validasibulan(char nama_bulan[20]){
    if (strcmp(nama_bulan,"januari") == 0){
    }
    else if (strcmp(nama_bulan,"februari") == 0){
    }
    else if (strcmp(nama_bulan,"maret") == 0){
    }
    else if (strcmp(nama_bulan,"april") == 0){
    }
    else if (strcmp(nama_bulan,"mei") == 0){
    }
    else if (strcmp(nama_bulan,"juni") == 0){
    }
    else if (strcmp(nama_bulan,"juli") == 0){
    }
    else if (strcmp(nama_bulan,"agustus") == 0){
    }
    else if (strcmp(nama_bulan,"september") == 0){
    }
    else if (strcmp(nama_bulan,"oktober") == 0){
    }
    else if (strcmp(nama_bulan,"november") == 0){
    }
    else if (strcmp(nama_bulan,"desember") == 0){
    }
    else{
        cout<<"\n\t Nama bulan tidak valid, ULANGI!"<<endl;
        cout<<"\n\t Masukkan Bulan : ";
		scanf("%s", nama_bulan);
        //mengubah menjadi lowercase
		char ch;
		int j = 0;
		while (nama_bulan[j]) {
	        ch = nama_bulan[j]; 
	        nama_bulan[j] = tolower(ch); 
	        j++;
	    }
        nama_bulan[20] = validasibulan(nama_bulan);
    }
    return nama_bulan[20];
}

int validasitanggal(char nama_bulan[20], int tanggal) {
	if (strcmp(nama_bulan,"januari") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"februari") == 0){
	    if ((tanggal > 29) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"maret") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"april") == 0){
	    if ((tanggal > 30) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"mei") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"juni") == 0){
	    if ((tanggal > 30) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"juli") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"agustus") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"september") == 0){
	    if ((tanggal > 30) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"oktober") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"november") == 0){
	    if ((tanggal > 30) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	else if (strcmp(nama_bulan,"desember") == 0){
	    if ((tanggal > 31) || (tanggal < 1)){
	        cout<<"\t Tanggal tidak valid, ULANGI!\n"<<endl;
	        cout<<"\t Masukkan Tanggal : ";
		    scanf("%d", &tanggal);
		    tanggal = validasitanggal(nama_bulan, tanggal);
		}
	}
	
	return tanggal;
}

//validasikeluar
int validasipil() {
    int pil;
	char hasil;
	
    if (scanf("%i%c", &pil, &hasil) != 2 || hasil != '\n') {
    	fflush(stdin);
		cout<<"\n\t Pilihan yang anda masukan tidak valid!\n\t Masukan ulang: ";
        return validasipil();
        printf("\n\t -----------------------------------------------\n");
	} else if (pil < 0 || pil >2) {
		cout<<"\n\tPilihan yang anda masukan tidak valid!\n\tPilih antara 1 atau 2: ";
		return validasipil();
        printf("\n\t -----------------------------------------------\n");	
	} else {
        return pil;
    }
}



void printHeader(){
    cout<<"\t----------------------------------------\n";
    cout<<"\t|       Aplikasi Penentu Zodiak         |\n";
    cout<<"\t----------------------------------------\n";
}

int main (){
	while(true){
		printHeader();
		//mendefinisikan variabel input
		char nama_bulan[20];
		char zodiak[50];
		int tanggal,pil;
		char temp;
		
		//input ke variabel nama_bulan
		cout<<"\t Masukkan Bulan : ";
		scanf("%[^\n]", nama_bulan);
		//mengubah menjadi lowercase
		char ch;
		int j = 0;
		while (nama_bulan[j]) {
	        ch = nama_bulan[j]; 
	        nama_bulan[j] = tolower(ch); 
	        j++;
	    }
		nama_bulan[20] = validasibulan(nama_bulan);
		
	    
		//input ke variael tanggal
		cout<<"\t Masukkan Tanggal : ";
		scanf("%d", &tanggal);
		tanggal = validasitanggal(nama_bulan, tanggal);
		
		//logika menentukan zodiak
		if (strcmp(nama_bulan,"desember") == 0){
	         
	        if ((tanggal >=1) && (tanggal < 22)){
	        	strcpy(zodiak, "Sagitarius");
			}
	        else if((tanggal >= 22)&&(tanggal <= 31)){
	        	strcpy(zodiak, "Capricorn");
			}
			
	    } else if (strcmp(nama_bulan,"januari") == 0){
	         
	        if((tanggal>=1)&&(tanggal < 20)){
	        	strcpy(zodiak, "Capricorn");
			}
	        else if((tanggal>=20)&&(tanggal<=31)) {
	        	strcpy(zodiak, "Aquarius");
			}
	    } else if (strcmp(nama_bulan,"februari") == 0){
	         
	        if((tanggal >= 1)&&(tanggal < 19)){
	        	strcpy(zodiak, "Aquarius");
			}
	        else if((tanggal >= 19)&&(tanggal < 29)) {
	        	strcpy(zodiak, "Pisces");
			}
	    } else if (strcmp(nama_bulan,"maret") == 0){
	         
	        if((tanggal >= 1)&&(tanggal < 21)){
	        	strcpy(zodiak, "Pisces");
			}
	        else if((tanggal >= 21)&&(tanggal < 31)) {
	        	strcpy(zodiak, "Aries");
			}
	    } else if (strcmp(nama_bulan,"april") == 0){
	         
	        if((tanggal >= 1)&&(tanggal < 20)){
	        	strcpy(zodiak, "Aries");
			}
	        else if((tanggal >= 21)&&(tanggal <= 30)) {
	        	strcpy(zodiak, "Taurus");
			}
	    } else if (strcmp(nama_bulan,"mei") == 0){
	         
	        if((tanggal >=1)&&(tanggal < 21)){
	        	strcpy(zodiak, "Taurus");
			}
	        else if((tanggal >= 21)&&(tanggal <= 31)) {
	        	strcpy(zodiak, "Gemini");
			}
	    } else if (strcmp(nama_bulan,"juni") == 0){
	         
	        if((tanggal >= 1)&&(tanggal < 21)){
	        	strcpy(zodiak, "Gemini");
			}
	        else if((tanggal >= 21)&&(tanggal <= 30)) {
	        	strcpy(zodiak, "Cancer");
			}
	    } else if (strcmp(nama_bulan,"juli") == 0){
	         
	        if ((tanggal >= 1)&&(tanggal < 23)){
	        	strcpy(zodiak, "Cancer");
			}
	        else if((tanggal >= 23)&&(tanggal <= 31)) {
	        	strcpy(zodiak, "Leo");
			}
	    } else if (strcmp(nama_bulan,"agustus") == 0){
	         
	        if ((tanggal >=1)&&(tanggal < 23)){
	        	strcpy(zodiak, "Leo");
			}
	        else if ((tanggal >= 23)&&(tanggal <= 31)) {
	        	strcpy(zodiak, "Virgo");
			}
	    } else if (strcmp(nama_bulan,"september") == 0){
	         
	        if ((tanggal >= 1)&&(tanggal < 23)){
	        	strcpy(zodiak, "Virgo");
			}
	        else if ((tanggal >= 23)&&(tanggal <= 30)) {
	        	strcpy(zodiak, "Libra");
			}
	    }  else if (strcmp(nama_bulan,"oktober") == 0){
	         
	        if ((tanggal >= 1)&&(tanggal < 23)){
	        	strcpy(zodiak, "Libra");
			}
	        else if((tanggal >= 23)&&(tanggal <= 31)) {
	        	strcpy(zodiak, "Scorpio");
			}
	    }  else if (strcmp(nama_bulan,"november") == 0){
	         
	        if ((tanggal >= 1)&&(tanggal < 22)){
	        	strcpy(zodiak, "Scorpio");
			}
	        else if ((tanggal >= 22)&&(tanggal <= 30)) {
	        	strcpy(zodiak, "Sagitarius");
			}
	    }
	    
	         
		
		//menampilkan hasil zodiak
		cout<<"\t----------------------------------------\n";
	    cout<<"\t*     Zodiak Anda adalah "<<zodiak<<endl;
	    cout<<"\t----------------------------------------\n";
		cout<<"\tApakah anda ingin keluar/mengulangi Program";
		cout<<"\n\t1. Keluar dari program";
		cout<<"\n\t2. ulang program";
	    cout<<"\n\tInput pilihan : "; 
	    pil = validasipil();
	    if (pil==1){
	        break;
	    }else{
	        system("cls || clear");
	    }
	    
	    
	}
	cout<<"\n\t------------PROGRAM SELESAI-------------\n";
	cout<<"\n\t-------------TERIMA KASIH---------------\n";
	return 0;
}
