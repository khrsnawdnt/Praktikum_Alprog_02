#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float input();
int hapus();
int validasiNim();
int cekNim();
int cekNimEdit();
int prosesReadDataTmp();
int main();
void Exit();
void reset();
void setDefaultDataTmp();
void prosesInsertData();
void prosesShowData();
void prosesUpdateData();
void prosesDeletedata();
void insertData();
void showData();
void updateData();
void deleteData();
void searchData();

struct Mahasiswa{
    int nim;
	char nama[50];
};

int clear(){
	while(getchar() != '\n');
	return 1;
}

float input(int desimal, int min, int batas_akhir){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int minus = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }
		else if(masukan[i]>='0' && masukan[i]<='9' || masukan[i] == '.' || (masukan[0] == '-' && min == 1)){
            if((masukan[i] == '.') && (desimal == 1)){
                titik = titik + 1;
                if(titik > 1 || masukan[i+1] == '\0'){
                    salah = 1;
                    masukan[i] = '\0';
                }
                status = 1;
            }
			else if((masukan[i] == '.') && (desimal == 0)){
                salah = 1;
                masukan[i] = '\0';
            }
            
            if(masukan[0] == '-' && min == 1){
                minus = 1;
            }
			else if(masukan[0] == '-' && min == 0){
                salah = 1;
                masukan[i] = '\0';
            }

            if(masukan[i]>='0' && masukan[i]<='9'){
                if(status == 1){
                    isi_belakang = (isi_belakang * 10) + (masukan[i] - 48);
                    belakang = belakang + 1;
                }
				else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }
            i++;
        }
		else{
            salah = 1;
            masukan[i] = '\0';
        }
    }
    if(titik == 1){
        hasil = (float)isi_depan + (isi_belakang / (pow(10, belakang)));
    }else{
        hasil = isi_depan;
    }

    
    if(minus == 1 && min == 1){
        hasil = hasil - (hasil * 2);
    }else if(minus == 1 && min == 0){
        salah = 1;
        masukan[i] = '\0';
    }

    if(salah == 1){
        printf("    Masukkan salah! Masukkan angka yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf("    Masukkan tidak boleh 0 ! Masukkan nilai yang benar : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf("    Masukkan tidak boleh lebih dari %d ! Masukkan nilai yang benar : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{
        return hasil;
    }
}

void Exit(){
	system("cls");
	printf("\n+-----------------------------------------------------------------------------+");
	printf("\n|                              TERIMAKASIH  !                                 |");
    printf("\n+-----------------------------------------------------------------------------+");
    exit(0);
}

void reset(int ulang){
    char huruf_ulang[1];
    
    printf("\n 	[M] Menu			[Q Quit]");
	printf("\n    Masukkan Pilihan : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "M") != 0) && (strcmp(huruf_ulang, "Q") != 0)){
        printf("    Input Invalid! Masukan Dengan Benar : \n");
        reset(ulang);
    }
	else if((strcmp(huruf_ulang, "M") == 0)){
        system("cls");
        main();
    }
	else{
        Exit();
    }
}

int hapus(){
    char huruf_hapus[1];
    int hasil = 0;
    
    printf("    [Y] Yes				[N] No \n");
    printf("    Masukkan Pilihan : ");
    scanf("%s", &huruf_hapus);
    fflush(stdin);

    if((strcmp(huruf_hapus, "Y") != 0) && (strcmp(huruf_hapus, "N") != 0)){
        printf("    Input Invalid ! Masukkan Dengan Benar : \n");
        hapus();
    }
	else if((strcmp(huruf_hapus, "Y") == 0)){
		hasil = 1;
    }
	else{
		hasil = 0;
    }

    return hasil;
}

void setDefaultDataTmp(struct Mahasiswa data_tmp[]){
    int i;
    for(i = 0; i < 100; i++){
        data_tmp[i].nim = 0;
    }
}

int validasiNim(){
    char masukan[100];
    int i = 0;
    int salah = 0;
    int hasil = 0;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[i] >= '0' && masukan[i] <= '9'){
            hasil = (hasil * 10) + (masukan[i] - 48);
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        printf("        Format NIM Salah! Masukkan Format Yang Benar : ");
        return validasiNim();
    }
	else if(i != 10){
        printf("        Format NIM Salah! Masukkan Format Yang Benar : ");
        return validasiNim();
    }
	else{
        return hasil;
    }
}

int validasiNama(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' ' || masukan[i] == '.' || masukan[i] == ','){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

int cekNim(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if(data.nim == data_tmp[i].nim){
            ditemukan = 1;
            break;
        }
		else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int cekNimEdit(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if((data.nim == data_tmp[i].nim) && (data_tmp[i].nim != data_tmp[nomorEdit].nim)){
            ditemukan = 1;
            break;
        }
		else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int prosesReadDataTmp(struct Mahasiswa data_tmp[]){
    int jumlah = 0;

    FILE *read_tmp = fopen("DataMahasiswa.txt","r");
    if(!read_tmp){
        jumlah = 1;
    }
	else{
	    while(!feof(read_tmp)){
	   	    fscanf(read_tmp,"%d#%[^\n]\n", &data_tmp[jumlah].nim, &data_tmp[jumlah].nama);
            jumlah++;
	    }
    }
	fclose(read_tmp);

    return jumlah;
}

void prosesInsertData(struct Mahasiswa data){
    FILE *insert = fopen("DataMahasiswa.txt", "a");
	fprintf(insert,"%d#%s\n", data.nim, data.nama);
	fclose(insert);
}

void prosesShowData(struct Mahasiswa data_tmp[], int jumlah){
    int i;
    if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("      Tidak Ada Data\n");
    }
	else{
        for(i = 0; i < jumlah; i++){
            printf("    %d. %d - %s\n", i+1, data_tmp[i].nim, data_tmp[i].nama);
        }
    }
}

void prosesUpdateData(struct Mahasiswa data_edit, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i, j;
    
    data_tmp[nomorEdit].nim = data_edit.nim;
    
    for(i = 0; i < 50; i++){
        data_tmp[nomorEdit].nama[i] = data_edit.nama[i];
    }

    FILE *update = fopen("DataMahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        fprintf(update, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
    }
    fclose(update);
}

void prosesDeleteData(struct Mahasiswa data_tmp[], int jumlah, int nomorHapus){
    int i;
    FILE *del = fopen("DataMahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        if(i == nomorHapus){
            continue;
        }
		else{
            fprintf(del, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
        }
    }
    fclose(del);
}

void insertData(){
    int statusNim;
    int statusNama;
    int jumlah;
    struct Mahasiswa data;
    struct Mahasiswa data_tmp[100];
    
    setDefaultDataTmp(data_tmp);
    jumlah = prosesReadDataTmp(data_tmp);
    
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                      <<   INSERT DATA MAHASISWA  >>                         |");
    printf("\n+-----------------------------------------------------------------------------+\n");
	printf("  Tambah Data \n\n");
	printf("     Masukan NIM  : ");
    data.nim = validasiNim();

    statusNim = cekNim(data, data_tmp, jumlah);
    while(statusNim == 1){
        printf("     NIM Sudah Ada ! Masukan NIM Yang Baru : ");
        data.nim = validasiNim();
        statusNim = cekNim(data, data_tmp, jumlah);
    }

	printf("     Masukan Nama : ");
    scanf("%[^\n]", &data.nama);
    fflush(stdin);

    statusNama = validasiNama(data.nama);
    while(statusNama == 0){
        printf("     Format Nama Salah ! Masukan Format Yang Benar : ");
        scanf("%[^\n]", &data.nama);
        fflush(stdin);
        statusNama = validasiNama(data.nama);
    }

    prosesInsertData(data);

    printf("\n===============================================================================\n\n");
    printf("  Data Berhasil Ditambahkan !\n\n");
    printf("     NIM  : %d\n", data.nim);
    printf("     Nama : %s\n", data.nama);
	printf("\n===============================================================================\n");
    reset(1);
}

void showData(){
	int jumlah;
    struct Mahasiswa data_tmp[100];
    
    setDefaultDataTmp(data_tmp);

    jumlah = prosesReadDataTmp(data_tmp);
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                       <<    DATA MAHASISWA   >>                             |");
    printf("\n+-----------------------------------------------------------------------------+\n\n");
    printf("  Daftar Data Mahasiswa :\n");
    printf("\n");

    prosesShowData(data_tmp, jumlah);

    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("\n");
        printf("  Jumlah Data : %d", jumlah);
    }
	printf("\n===============================================================================\n");
    reset(2);
}

void updateData(){
    int statusNim, statusNama;
    int nomorEdit = 0;
    int jumlah;
    struct Mahasiswa data_edit;
    struct Mahasiswa data_tmp[100];
    
    setDefaultDataTmp(data_tmp);
    jumlah = prosesReadDataTmp(data_tmp);
    
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                      <<   UPDATE DATA MAHASISWA  >>                         |");
    printf("\n+-----------------------------------------------------------------------------+\n\n");
    printf("  Daftar Data Mahasiswa :\n");
    printf("\n");

    prosesShowData(data_tmp, jumlah);

    printf("\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
    	printf("===============================================================================\n\n");
        printf("    Data Ingin Di Update ? (1 - %d) : ", jumlah);
        nomorEdit = input(0, 0, jumlah);
        nomorEdit = nomorEdit - 1;

        printf("\n===============================================================================\n\n");
        printf("    Input Update Data\n");
	    printf("      Masukan NIM  : ");
        data_edit.nim = validasiNim();

        statusNim = cekNimEdit(data_edit, data_tmp, jumlah, nomorEdit);
        while(statusNim == 1){
            printf("      NIM sudah ada ! Masukan NIM yang berbeda : ");
            data_edit.nim = validasiNim();
            statusNim = cekNimEdit(data_edit, data_tmp, jumlah, nomorEdit);
        }

	    printf("      Masukan Nama : ");
        scanf("%[^\n]", &data_edit.nama);
        fflush(stdin);

        statusNama = validasiNama(data_edit.nama);
        while(statusNama == 0){
            printf("      Format Nama salah ! Masukan Nama Dengan Benar : ");
            scanf("%[^\n]", &data_edit.nama);
            fflush(stdin);
            statusNama = validasiNama(data_edit.nama);
        }

        printf("\n");

        prosesUpdateData(data_edit, data_tmp, jumlah, nomorEdit);

	    printf("    Data berhasil Di Update !\n");
    }
	else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("   Masukan Data Terlebih Dahulu !\n");
    }
	printf("\n===============================================================================\n\n");
    reset(3);
}

void deleteData(){
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = prosesReadDataTmp(data_tmp);
    int nomorHapus = 0;
    int yakinHapus = 0;
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                      <<   DELETE DATA MAHASISWA >>                          |");
    printf("\n+-----------------------------------------------------------------------------+\n\n");
    printf("  Daftar Data Mahasiswa :\n");
    printf("\n");

    prosesShowData(data_tmp, jumlah);

    printf("\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
    	printf("\n===============================================================================\n");
        printf("  Data Yang Ingin Dihapus ? (1 - %d) : ", jumlah);
        nomorHapus = input(0, 0, jumlah);
        nomorHapus = nomorHapus - 1;
        yakinHapus = hapus();
        printf("\n");
        if(yakinHapus == 1){
            prosesDeleteData(data_tmp, jumlah, nomorHapus);
            printf("     Data Telah Di Hapus !\n");
        }
		else{
            printf("    \nData Tidak Di Hapus\n");
        }
    }
	else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("   Masukan Data Terlebih Dahulu\n");
    }
	printf("\n===============================================================================\n");
    reset(4);
}

void searchData(){
    int salah = 0, jumlah = 0;
    int searchNim;
    struct Mahasiswa data;
	
	printf("+-----------------------------------------------------------------------------+");
	printf("\n|                       <<  SEARCH DATA MAHASISWA  >>                         |");
    printf("\n+-----------------------------------------------------------------------------+\n\n");

    printf("  Masukkan NIM : ");
    searchNim = validasiNim();
    fflush(stdin);
    FILE *in=fopen("dataMahasiswa.txt","r");

    while(!feof(in)){
        fflush(stdin);
        fscanf(in,"%d#%[^\n]\n", &data.nim, &data.nama);
        if(data.nim == searchNim){
        	printf("\n===============================================================================\n");
        	printf("\n  Data Ditemukan !\n");
            printf("\n    Nama	: %s",data.nama);
			printf("\n    NIM		: %d",data.nim);
            printf("\n\n===============================================================================\n");
            jumlah +=1;
        }
		else{
            salah +=1;
            jumlah +=1;
        }
    }
    if(salah == jumlah){
        printf("\n    Data Tidak Ada !\n");
       
    }
    fclose(in);
    reset(5);
}

int main(){
    system("cls");
    int pilihan;
	printf("+-----------------------------------------------------------------------------+");                     
	printf("\n|                            PROGRAM DATA MAHASISWA                           |");
    printf("\n+-----------------------------------------------------------------------------+");
    printf("\n|   Pilih Menu Program :                                                      |");
    printf("\n|                                                                             |");
	printf("\n|        1. Insert Data Mahasiswa                                             |");
	printf("\n|        2. Show Data Mahasiswa                                               |");
	printf("\n|        3. Update Data Mahasiswa                                             |");
	printf("\n|        4. Delete Data Mahasiswa                                             |");
	printf("\n|        5. Search Data Mahasiswa                                             |");
	printf("\n|        6. Keluar                                                            |");
	printf("\n+-----------------------------------------------------------------------------+");
    printf("\nMasukkan Pilihan: ");
    pilihan = input(0,0,6);

    if(pilihan == 1){
        system("cls");
        insertData();
    }
	else if(pilihan == 2){
        system("cls");
        showData();
    }
	else if(pilihan == 3){
        system("cls");
        updateData();
    }
	else if(pilihan == 4){
        system("cls");
        deleteData();
    }
    else if(pilihan == 5){
        system("cls");
        searchData();
    }
	else if(pilihan == 6){
        Exit ();
    }

    return 0;
}
