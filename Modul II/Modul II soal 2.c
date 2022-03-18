//Deklarasi Library
#include <stdio.h>
#include <string.h>

int hitungKehadiran(int kehadiran){
	//max 5%
	return kehadiran * 100/15 * 5/100;
}

int hitungNilai3Tugas(int tugas1, int tugas2, int tugas3){
	//max 20%
	return (tugas1+tugas2+tugas3)/3 * 20/100;
}

int hitungNilaiQuiz(int nilaiQuiz){
	//max 15%
	return nilaiQuiz * 15/100;
}

int hitungNilaiUTS(int nilaiUTS){
	//max 30%
	return nilaiUTS * 30/100;
}

int hitungNilaiUAS(int nilaiUAS){
	//max 30%
	return nilaiUAS * 30/100;
}

int hitungNilaiAkhir(int akhirKehadiran,int akhirNilai3Tugas,int akhirNilaiQuiz,int akhirNilaiUTS,int akhirNilaiUAS){
	//hitung semua max 100
	return akhirKehadiran+akhirNilai3Tugas+akhirNilaiQuiz+akhirNilaiUTS+akhirNilaiUAS;
}

void hitungPredikatNilai(int nilaiAkhir,char* predikatNilai){
	if(nilaiAkhir>=0 && nilaiAkhir<45){
		strcpy(predikatNilai,"E+");
	}
}

int main(){
	//Deklarasi Variabel Inputan User
	int kehadiran;
	int nilaiTugas1;
	int nilaiTugas2;
	int nilaiTugas3;
	int nilaiQuiz;
	int nilaiUTS;
	int nilaiUAS;
	
	//Deklarasi Variabel Telah Terhitung
	int akhirKehadiran;
	int akhirNilai3Tugas;
	int akhirNilaiQuiz;
	int akhirNilaiUTS;
	int akhirNilaiUAS;
	int nilaiAkhir;
	char predikatNilai[1];
	
	//Header Program
	printf("Program Penentu Nilai Akhir (NA)\n");
	printf("--------------------------------\n");
	
	//Input Kehadiran
	printf("Kehadiran (Max15): ");
	scanf("%d",&kehadiran);
	
	//Input Nilai Tugas 1
	printf("Nilai Tugas 1    : ");
	scanf("%d",&nilaiTugas1);
	
	//Input Nilai Tugas 2
	printf("Nilai Tugas 2    : ");
	scanf("%d",&nilaiTugas2);
	
	//Input Nilai Tugas 3
	printf("Nilai Tugas 3    : ");
	scanf("%d",&nilaiTugas3);
	
	//Input Nilai Quiz
	printf("Nilai Quiz       : ");
	scanf("%d",&nilaiQuiz);
	
	//Input Nilai UTS
	printf("Nilai UTS        : ");
	scanf("%d",&nilaiUTS);
	
	//Input Nilai UAS
	printf("Nilai UAS        : ");
	scanf("%d",&nilaiUAS);
	
	//Proses Nilai
	akhirKehadiran   = hitungKehadiran(kehadiran);
	akhirNilai3Tugas = hitungNilai3Tugas(nilaiTugas1,nilaiTugas2,nilaiTugas3);
	akhirNilaiQuiz   = hitungNilaiQuiz(nilaiQuiz); 
	akhirNilaiUTS    = hitungNilaiUTS(nilaiUTS);
	akhirNilaiUAS    = hitungNilaiUAS(nilaiUAS);
	nilaiAkhir		 = hitungNilaiAkhir(akhirKehadiran,akhirNilai3Tugas,akhirNilaiQuiz,akhirNilaiUTS,akhirNilaiUAS);
	hitungPredikatNilai(nilaiAkhir,&predikatNilai[0]);
	
	printf("--------------------------------\n");
	printf("Nilai Akhir      : %d\n",nilaiAkhir);
	printf("Predikat Nilai   : %s\n",predikatNilai);
	
	Sleep(1000);
	
	//Akhir Program
	return 0;
}
