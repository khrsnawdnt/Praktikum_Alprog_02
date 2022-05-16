// I Putu Riko Putra Arnawa
// Modul 2 Soal Praktikum nomor 6

#include <stdio.h>

int rumus_angsuran (int pinjaman, int lama){
	int angsuran;
	angsuran = pinjaman/lama;
	return angsuran;
}

void judul(){
		printf("\n\t==================================================================");
		printf("\n\t|-----------------Program Angsuran Bunga Menurun-----------------|");
		printf("\n\t==================================================================\n");
}

void koreksi(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(valid(var))
			break;
		printf("\n\tHanya menerima input berupa angka!!\n");
	}
}

int valid(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %f", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

int cek_validasi();
int cek_validasi(){
	int bilangan;
    char huruf;
    scanf("%d%c", &bilangan,&huruf);
    if(huruf != '\n' || bilangan<0){
        printf("\n\tHanya menerima input berupa angka!");
        printf("\n\tMasukkan Angka yang benar \t: ");
        fflush(stdin);
        cek_validasi();
    }
	else{
        return bilangan;
    }
}

int main(){
	int pokok, bulan, angsuran, bunga;
	int pinjaman, lama, pilih;
	int total_bunga, total_angsuran, bulan_total;
	char ulang;
	
	int bunga_total[100];
	int total[100];
	
	do{
		system("color F4");
		system("cls");
		judul();
		printf("\n\t1. Hitung Angsuran");
		printf("\n\t2. Keluar");
		koreksi(&pilih, "\n\tMasukkan Pilihan Anda : ");
		
		if (pilih==1){
			printf("\n\tAnda Akan Menghitung Angsuran!\n");
			printf("\tPokok Pinjaman \t\t: Rp.");
			pinjaman = cek_validasi();
			printf("\tBesar Bunga (%%) \t: ");
			bunga = cek_validasi();
			printf("\tLama Pinjaman (bulan) \t: ");
			lama = cek_validasi();
			angsuran = rumus_angsuran(pinjaman, lama);
			
			printf("\n\t===============================================================");
			printf("\n\t|| Bulan |    Bunga   |  Angsuran Pokok  |  Angsuran Perbulan ||");
			printf("\n\t===============================================================\n");
			for(bulan=1; bulan<=lama; bulan++){
	        	bunga_total[bulan]=(pinjaman-((bulan-1)*angsuran))*(bunga*0.01)/12;
	        	
	        	total[bulan]=bunga_total[bulan]+angsuran;
				total_bunga = total_bunga+bunga_total[bulan];
				total_angsuran = total_angsuran+total[bulan];
				printf("\t||%-7d|Rp.%-9d|Rp.%-15d|Rp.%-17d||\n", bulan, bunga_total[bulan], angsuran, total[bulan] );
				printf("\t----------------------------------------------------------------\n");
	    	}
	    	printf("\n\tTotal Bunga \t: Rp.%d", total_bunga);
	    	printf("\n\tTotal Angsuran \t: Rp.%d", total_angsuran);
	    	printf("\n\n\tApakah Anda Ingin Mengulang Lagi? (Y/N) ");
	    	scanf("%s", &ulang);
		}
		else if (pilih==2){
			return printf("\n\tTerima Kasih Sudah Menggunakan Program Kami!");
		}else{
			printf("\n\tPilihan tidak tersedia!\n");
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
	}while (ulang=='Y'||ulang=='y');
	
	do{
		return printf("\n\tTerima Kasih Sudah Menggunakan Program Kami!");
	}while (ulang=='N'||ulang=='n');
}
