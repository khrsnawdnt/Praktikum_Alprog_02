//Deklarasi Library
#include <stdio.h>
#include <string.h>

void header(){
	//Header Program
	printf("\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\t\t\t\t\t|   Program Penentu Nilai Akhir   |\n");
	printf("\t\t\t\t\t*---------------------------------*\n");
	printf("\n");
}

void masukkanJikaAngka(int* pilihan,int* cekerror,int skala,char* teks){	
	char sementara[255];
	char tampungNewline;
	while(1){
		printf(teks);
		fgets(sementara,sizeof(sementara),stdin);
		if(sscanf(sementara,"%d %s",pilihan,&tampungNewline)==1){
			if(*pilihan<0||*pilihan>skala){
				printf("\t\t\t\t\tSALAH! - Input harus 0 sampai %d!\n\n",skala);
				*cekerror=1;
				break;
			}	
			*cekerror=0;
			system("cls");
			header();
			break;
		}	
		else{
		printf("\t\t\t\t\tSALAH! - Input harus berupa angka!\n\n");
		fflush(stdin);
		}
	}
}

int ulangProgram(){
	char sementara[255];
	char tampungNewline;
	int ulangi;
	int hasil;
	
	printf("\n");
	printf("\t\t\t\t\t[1]= Ya\n");
	printf("\t\t\t\t\t[0]= Tidak\n");
	printf("\t\t\t\t\tIngin mengulang program? : ");
	
	fgets(sementara,sizeof(sementara),stdin);
	
	if(sscanf(sementara,"%d %s",&ulangi,&tampungNewline)==1){
		if(ulangi==1){
			system("cls");
			fflush(stdin);
			return main();		
		}
		else if(ulangi==0){
			system("cls");
			fflush(stdin);
			header();
			return tutupProgram();
		}
	}
	system("cls");
	fflush(stdin);
	return tidakValid();			
}

int tidakValid(){
	header();
	printf("\t\t\t\t\tSALAH! - Input tidak valid\n");
	return ulangProgram();	
}

int hitungNilaiAkhir(int Kehadiran,int Nilai3Tugas,int NilaiQuiz,int NilaiUTS,int NilaiUAS){
	//hitung semua max 100
	return Kehadiran+Nilai3Tugas+NilaiQuiz+NilaiUTS+NilaiUAS;
}

void hitungPredikatNilai(int nilaiAkhir,char* predikatNilai){
	if(nilaiAkhir>=0 && nilaiAkhir<45){
		strcpy(predikatNilai,"E");
	}
	else if(nilaiAkhir>=45 && nilaiAkhir<50){
		strcpy(predikatNilai,"D");
	}
	else if(nilaiAkhir>=50 && nilaiAkhir<55){
		strcpy(predikatNilai,"D+");
	}
	else if(nilaiAkhir>=55 && nilaiAkhir<60){
		strcpy(predikatNilai,"C");
	}
	else if(nilaiAkhir>=60 && nilaiAkhir<65){
		strcpy(predikatNilai,"C+");
	}
	else if(nilaiAkhir>=65 && nilaiAkhir<75){
		strcpy(predikatNilai,"B");
	}
	else if(nilaiAkhir>=75 && nilaiAkhir<80){
		strcpy(predikatNilai,"B+");
	}
	else if(nilaiAkhir>=80 && nilaiAkhir<=100){
		strcpy(predikatNilai,"A");
	}
}

int tutupProgram(){
	//Tutup Program
	printf("\t\t\t\t\t         Selamat Tinggal          \n");
	Sleep(1000);
	return 1;
}

int main(){
	int cekerror=0;
	char predikatNilai[2];
	
	//Deklarasi Variabel
	int kehadiran;
	int nilaiTugas1;
	int nilaiTugas2;
	int nilaiTugas3;
	int nilai3Tugas;
	int nilaiQuiz;
	int nilaiUTS;
	int nilaiUAS;
	int nilaiAkhir;	
	
	header();
	
	//Input Kehadiran
	do{
		masukkanJikaAngka(&kehadiran,&cekerror,15,"\t\t\t\t\tMasukkan Kehadiran (Max15): ");
	}while(cekerror==1);

	//Proses Kehadiran MAX 5%
	kehadiran = kehadiran * 100/15 * 5/100;
	
	//Input Nilai Tugas 1
	do{
		masukkanJikaAngka(&nilaiTugas1,&cekerror,100,"\t\t\t\t\tMasukkan Nilai Tugas 1    : ");
	}while(cekerror==1);

	//Input Nilai Tugas 2
	do{
		masukkanJikaAngka(&nilaiTugas2,&cekerror,100,"\t\t\t\t\tMasukkan Nilai Tugas 2    : ");
	}while(cekerror==1);
	
	//Input Nilai Tugas 3
	do{
		masukkanJikaAngka(&nilaiTugas3,&cekerror,100,"\t\t\t\t\tMasukkan Nilai Tugas 3    : ");
	}while(cekerror==1);
	
	//Proses Ke3 Nilai Tugas MAX 20%
	nilai3Tugas = (nilaiTugas1+nilaiTugas2+nilaiTugas3)/3 * 20/100;
	
	//Input Nilai Quiz
	do{
		masukkanJikaAngka(&nilaiQuiz,&cekerror,100,"\t\t\t\t\tMasukkan Nilai Quiz       : ");
	}while(cekerror==1);
	
	//Proses Nilai Quiz MAX 15%
	nilaiQuiz = nilaiQuiz * 15/100;
	
	//Input Nilai UTS
	do{
		masukkanJikaAngka(&nilaiUTS,&cekerror,100,"\t\t\t\t\tMasukkan Nilai UTS        : ");
	}while(cekerror==1);
	
	//Proses Nilai UTS MAX 30%
	nilaiUTS = nilaiUTS * 30/100;
	
	//Input Nilai UAS
	do{
		masukkanJikaAngka(&nilaiUAS,&cekerror,100,"\t\t\t\t\tMasukkan Nilai UAS        : ");
	}while(cekerror==1);
	
	//Proses Nilai UAS MAX 30%
	nilaiUAS = nilaiUAS * 30/100;
	
	//Proses Nilai Akhir dan Predikat
	nilaiAkhir		 = hitungNilaiAkhir(kehadiran,nilai3Tugas,nilaiQuiz,nilaiUTS,nilaiUAS);
	hitungPredikatNilai(nilaiAkhir,predikatNilai);
	
	printf("\t\t\t\t\t----------------------------------\n");
	printf("\t\t\t\t\tNilai Akhir      : %d\n",nilaiAkhir);
	printf("\t\t\t\t\tPredikat Nilai   : %s\n",predikatNilai);
	printf("\t\t\t\t\t----------------------------------\n");
	return ulangProgram();	
}
