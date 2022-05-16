#include <stdio.h>
#include <string.h>
#include <ctype.h>

int invalid(){
	fflush(stdin);
	system("cls");

	int pilihan;
	int cekerror=0;
	
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Program Palindrom        |\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	printf("\t\t\t\t\tInput anda tidak benar\n");
	printf("\t\t\t\t\tIngin mengulang program?\n");
	printf("\t\t\t\t\t[1] Ya\n");
	printf("\t\t\t\t\t[0] Tidak\n");
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

int tutupProgram(){
	
	system("cls");
	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Program Palindrom        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	printf("\t\t\t\t\t        - Selamat tinggal -");
	Sleep(1000);
	return 0;
}

int ulangProgram(){
	
	int pilihan;
	int cekerror;
	
	printf("\n");
	printf("\t\t\t\t\t-----------------------------------\n");
	printf("\t\t\t\t\tProgram telah selesai\n");
	printf("\t\t\t\t\tIngin mengulang program?\n");
	printf("\t\t\t\t\t[1] Ya\n");
	printf("\t\t\t\t\t[0] Tidak\n");
	printf("\t\t\t\t\t-----------------------------------\n");	
	printf("\t\t\t\t\tJawaban: ");
	fflush(stdin);
	masukkanAngka(&pilihan,&cekerror,0,1);	
	if(cekerror==1){
		return invalid();
	}

	if(pilihan==1){
		return main();
	}
	else if(pilihan==0){
		return tutupProgram();
	}
	
}

void masukkan_palindrom(int* besar,char palindrom_awal[],int* status_angka){
	
	scanf(" %[^\n]s",palindrom_awal);
	
	//hitung panjang kata
	*besar = strlen(palindrom_awal);
	
	char sementara;
	int counter_tolower=0;
	int counter_cekAngka=0;
	
	//menjadikan semua huruf kecil
	while(palindrom_awal[counter_tolower]){
	sementara = palindrom_awal[counter_tolower];
	palindrom_awal[counter_tolower] = tolower(sementara);
	counter_tolower++;
	}
	
	//cek jika isi angka
	while(palindrom_awal[counter_cekAngka]){
	sementara = palindrom_awal[counter_cekAngka];
	if(isdigit(sementara)==1){
		*status_angka=1;
		break;
	}
	counter_cekAngka++;
	}
	
	
}

void balikkan_palindrom(int besar, char palindrom_awal[besar], char palindrom_akhir[besar], int* status){

	int counter_depan;
	int counter_belakang;
	char palindrom_sementara[besar];
	strcpy(palindrom_sementara, palindrom_awal);
	
	counter_belakang = besar - 1;
	
	strcpy(palindrom_akhir,strrev(palindrom_sementara));
	
	if(strcmp(palindrom_awal,palindrom_akhir)==!1){
		*status = 1;
	}else{
		*status = 0;
	}

}

void file_palindrom(int besar, char palindrom_awal[besar], int status){

	FILE *file = fopen("kamusKata.txt","a+");
	
	char palindrom_sorted[besar];
	int counter_tolower=0;
	char sementara;
	
	int counter_awal;
	int counter_lanjut;
	
	char huruf_file[0];
	int jumlah_huruf;
		
	int counter_input=0;
	int status_input;

	strcpy(palindrom_sorted,palindrom_awal);
	
	//urutkan palindrom sesuai huruf
	for (counter_awal=0 ; counter_awal<besar-1 ; counter_awal++) {
		for (counter_lanjut=counter_awal+1 ; counter_lanjut<besar ; counter_lanjut++) {
			if (palindrom_sorted[counter_awal] > palindrom_sorted[counter_lanjut]) {
					sementara = palindrom_sorted[counter_awal];
					palindrom_sorted[counter_awal] = palindrom_sorted[counter_lanjut];
					palindrom_sorted[counter_lanjut] = sementara;
			}
		}
	}

	
	fprintf(file,"%s(%d)\t\t : ",palindrom_awal,besar);
	
	while(counter_input<besar){
		
		jumlah_huruf = 0;
		status_input = 0;
		huruf_file[0] = palindrom_sorted[counter_input];
		fprintf(file,"%s=",huruf_file);
		jumlah_huruf++;
		
		while(1){
			if(palindrom_sorted[counter_input]==palindrom_sorted[counter_input+1]){
				jumlah_huruf++;
				counter_input++;
				status_input = 1;
			}	
			else{
				counter_input++;
				break;
			}
		}

		fprintf(file,"%d ",jumlah_huruf);
	}
		
		if(status==1){
			fputs(": Palindrom",file);
		}
		else if(status==0){
			fputs(": Bukan Palindrom",file);
		}
		
		fputs("\n",file);
		fclose(file);
}

int main(){
	fflush(stdin);
	system("cls");
	
	//deklarasi awal
	char palindrom_awal[255];
	int besar_palindrom;
	int status;
	int status_angka;
	int ulang;

	printf("\n\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|        Program Palindrom        |\n");	
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
	
	//input kata
	printf("\t\t\t\t\tMasukkan kata        : ");
	masukkan_palindrom(&besar_palindrom,palindrom_awal,&status_angka);
	if(status_angka==1){
		return invalid();
	}
	
	//deklarasi kembali
	char palindrom_akhir[besar_palindrom];

	balikkan_palindrom(besar_palindrom,palindrom_awal,palindrom_akhir,&status);	
	file_palindrom(besar_palindrom, palindrom_awal,status);

	printf("\n");
	printf("\t\t\t\t\t-----------------------------------\n");	

	printf("\t\t\t\t\t- Jumlah huruf       : %d\n", besar_palindrom);
	printf("\t\t\t\t\t- Sebelum di-balik   : %s\n", palindrom_awal);
	printf("\t\t\t\t\t- Setelah di-balik   : %s\n", palindrom_akhir);
	printf("\n");
	if(status==1){
		printf("\t\t\t\t\t( V )  Ya, merupakan Palindrom\n");
	}
	else if(status==0){
		printf("\t\t\t\t\t( X )  Tidak, bukan Palindrom\n");
	}
	printf("\t\t\t\t\t       Data dimasukkan ke kamusKata");
		
	return ulangProgram();
}
