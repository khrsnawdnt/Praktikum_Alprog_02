// I Putu Riko Putra Arnawa
// Modul 1 Soal Praktikum Nomor 3

#include <stdio.h>
#define PHI 3.14

float volume_tabung(float r, float t){
	float volume;
	volume = PHI*r*r*t;
	return volume;
}

float lp_tabung(float r, float t){
	float luas_permukaan;
	luas_permukaan = 2*PHI*r*(r+t);
	return luas_permukaan;
}

float volume_bola(float r){
	float volume;
	volume = (4*PHI*r*r*r)/3;
	return volume;
}

float lp_bola(float r){
	float luas_permukaan;
	luas_permukaan = 4*PHI*r*r;
	return luas_permukaan;
}

float volume_limas(float L, float t){
	float volume;
	volume = (1*L*t)/3;
	return volume;
}

float lp_limas(float L, float t){
	float luas_permukaan;
	luas_permukaan = L+(4*t);
	return luas_permukaan;
}
	
float volume_prisma(float luas_alas, float t){
	float volume;
	volume = luas_alas*t;
	return volume;
}
	
float lp_prisma(float luas_alas, float t, float kll){
	float luas_permukaan;
	luas_permukaan = (2*luas_alas)+(kll*t);
	return luas_permukaan;
}
	
float volume_kerucut(float r, float t){
	float volume;
	volume = (1*PHI*r*r*t)/3;
	return volume;
}
	
float lp_kerucut(float r, float s){
	float luas_permukaan;
	luas_permukaan = PHI*r*(s+r);
	return luas_permukaan;
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
        printf("\n\tMasukan Angka yang benar \t: ");
        fflush(stdin);
        cek_validasi();
    }
	else{
        return bilangan;
    }
}

int main(){
	
	float volume, luas_permukaan, r, t, L, kll, luas_alas, s;
	int pilih;
	char ulang;
	
	do{
		system("color F4");
		system("cls");
		printf("\n\t===========================================================\n");
		printf("\t|Program Menghitung Volume dan Luas Permukaan Bangun Ruang|\n");
		printf("\t===========================================================\n\n");
		printf("\tList Bangun Datar : \n");
		printf("\t1. Tabung \n");
		printf("\t2. Bola \n");
		printf("\t3. Limas Segiempat \n");
		printf("\t4. Prisma Segitiga \n");
		printf("\t5. Kerucut \n");
		printf("\t6. Keluar \n");
		koreksi(&pilih, "\tMasukkan Pilihan Anda : ");
		
		if (pilih==1){
			printf("\n\tAnda memilih Tabung!\n");
			printf("\tMasukkan jari-jari alas tabung \t: ");
			r = cek_validasi();
			printf("\tMasukkan tinggi tabung \t\t: ");
			t = cek_validasi();
			volume = volume_tabung(r, t);
			luas_permukaan = lp_tabung(r, t);
			printf("\n\tVolume dari Tabung adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Tabung adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
		else if (pilih==2){
			printf("\n\tAnda memilih Bola!\n");
			printf("\tMasukkan jari-jari bola \t: ");
			r = cek_validasi();
			volume = volume_bola(r);
			luas_permukaan = lp_bola(r);
			printf("\n\tVolume dari Bola adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Bola adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
		else if (pilih==3){
			printf("\n\tAnda memilih Limas Segiempat!\n");
			printf("\tMasukkan luas alas \t: ");
			L = cek_validasi();
			printf("\tMasukkan tinggi \t: ");
			t = cek_validasi();
			volume = volume_limas(L, t);
			luas_permukaan = lp_limas(L, t);
			printf("\n\tVolume dari Limas Segiempat adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Limas Segiempat adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
		else if (pilih==4){
			printf("\n\tAnda memilih Prisma Segitiga!\n");
			printf("\tMasukkan luas alas \t: ");
			luas_alas = cek_validasi();
			printf("\tMasukkan tinggi \t: ");
			t = cek_validasi();
			printf("\tMasukkan keliling alas \t: ");
			kll = cek_validasi();
			volume = volume_prisma(luas_alas, t);
			luas_permukaan = lp_prisma(luas_alas, t, kll);
			printf("\n\tVolume dari Prisma Segitiga adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Prisma Segitiga adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
		else if (pilih==5){
			printf("\n\tAnda memilih Kerucut!\n");
			printf("\tMasukkan jari-jari alas \t: ");
			r = cek_validasi();
			printf("\tMasukkan tinggi kerucut \t: ");
			t = cek_validasi();
			printf("\tMasukkan garis pelukis kerucut \t: ");
			s = cek_validasi();
			volume = volume_kerucut(r, t);
			luas_permukaan = lp_kerucut(r, s);
			printf("\n\tVolume dari Kerucut adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Kerucut adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
		else if (pilih==6){
			return printf("\n\tTerima kasih sudah menggunakan program kami!");
		}else{
			printf("\n\tPilihan tidak tersedia!\n");
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
	}while (ulang=='Y'||ulang=='y');
	
	do{
		return printf("\n\tTerima kasih sudah menggunakan program kami!");
	}while (ulang=='N'||ulang=='n');
}
