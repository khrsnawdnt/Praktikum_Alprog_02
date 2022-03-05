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
		printf("\tMasukkan pilihan anda \t: ");
		scanf("%d", &pilih);
		
		if (pilih==1){
			printf("\n\tAnda memilih Tabung!\n");
			printf("\tMasukkan jari-jari alas tabung \t: ");
			scanf("%f", &r);
			printf("\tMasukkan tinggi tabung \t\t: ");
			scanf("%f", &t);
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
			scanf("%f", &r);
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
			scanf("%f", &L);
			printf("\tMasukkan tinggi \t: ");
			scanf("%f", &t);
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
			scanf("%f", &luas_alas);
			printf("\tMasukkan tinggi \t: ");
			scanf("%f", &t);
			printf("\tMasukkan keliling alas \t: ");
			scanf("%f", &kll);
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
			scanf("%f", &r);
			printf("\tMasukkan tinggi kerucut \t: ");
			scanf("%f", &t);
			printf("\tMasukkan garis pelukis kerucut \t: ");
			scanf("%f", &s);
			volume = volume_kerucut(r, t);
			luas_permukaan = lp_kerucut(r, s);
			printf("\n\tVolume dari Kerucut adalah %.2f", volume);
			printf("\n\tLuas permukaan dari Kerucut adalah %.2f", luas_permukaan);
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}else{
			printf("\n\tPilihan tidak tersedia!\n");
			printf("\n\tIngin memilih lagi? (Y/N) ");
			scanf("%s", &ulang);
		}
	}while (ulang=='Y'||ulang=='y');	
}
