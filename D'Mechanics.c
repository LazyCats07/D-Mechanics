#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//mainMenu
void mainMenu();

//Dealer
void menuDealer();
void menuLoginDealer();
void menuOpsiDealer();
void menuDataCustomer();
void menghapusDTCustomer();
void menu_MenambahDataBarang();
void menu_MenghapusDataBarang();
void browseDealer();


//customer
void menuRLCustomer();
void menuLoginCustomer();
void menuRegistrasiCustomer();
void menuRegistrasi();
void menuCustomer();
void searchBarang();
void prosesPembayaran();
void browseCustomer();
void mesin();
void ban();
void velg();
void aksesoris();
void jok();


//Struct
struct pembeli{
	char id[100],pwd[100],nama[100], alamat[1000], tlp[50];	
}pmb;

struct brg{
	char ktgr[50], brg[50], harga[100], jenis[40];
//	int harga;
}data;

//Variabel
int a1, b1, c1, d1, e1, n, status, salah, i=1, j;
char username[500], password[500], ID[100], passwoerd[100], hapus[50];


int main(){
	printf("========================");
	printf("\n===== D'Auto Parts =====\n");
	printf("========================\n");
	printf("     Menu Utama\n");
	printf("     ----------\n");
	printf("1. Dealer\n");
	printf("2. Customer\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &a1);
	
	switch(a1){
	case 1:
		system("cls");
		menuDealer();
		break; 
	case 2:
		system("cls");
		menuRLCustomer();
		break; 
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-2 #\n");
		system("pause");
		system("cls");
		main();
		break;
	}	
	
}
////////////////////Customer
void menuRLCustomer(){
	printf("------------------\n");
	printf("==== Customer ====\n");
	printf("------------------\n");
	printf("1. Login\n");
	printf("2. Registrasi\n");
	printf("3. Kembali\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &d1);
	
	switch(d1){
	case 1:
		system("cls");
		menuLoginCustomer();
		break; 
	case 2:
		system("cls");
		menuRegistrasiCustomer();
		break; 
	case 3:
		system("cls");
		main();
		break; 
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-3 #\n");
		system("pause");
		system("cls");
		menuRLCustomer();
		break;
	}
}

void menuRegistrasiCustomer(){
	int i=1;
	FILE *f_registrasi;
	getchar();
	f_registrasi = fopen("f_registrasi.dat", "ab");
	printf("==== ========== ====\n");
	printf("==== Registrasi ====\n");
	printf("==== ========== ====\n");
	printf("Nama        : ");
	gets(pmb.nama);
	printf("Alamat      : ");
	gets(pmb.alamat);
	printf("No. Telepon : ");
	gets(pmb.tlp);
	printf("ID          : ");
	gets(pmb.id);
	printf("Password    : ");
	gets(pmb.pwd);
	fflush(stdin);
	fwrite(&pmb,sizeof(pmb),1,f_registrasi);

	fclose(f_registrasi);
	printf("Registrasi Berhasil\n");
	system("pause");
	system("cls");	
	menuRLCustomer();
}

void menuLoginCustomer(){
	int i=0;
	getchar();
	while(status<3){	
	FILE *f_registrasi;
	f_registrasi = fopen("f_registrasi.dat", "rb");
	printf("==== LOGIN COSTUMER ====\n");
	printf("ID : ");
	gets(ID);
	printf("Password : ");
	gets(password);
	while(fread(&pmb,sizeof(pmb),1,f_registrasi)==1 ){
		if( strcmp(ID, pmb.id)==0 && strcmp(password, pmb.pwd)==0){
			status=0;
			salah=0;
			printf("Akses diterima. Selamat Datang %s\n", pmb.nama);
			system("pause");
			system("cls");
			menuCustomer();
			break;
			}		
		}fclose(f_registrasi);
		
		if (strcmp(ID, pmb.id)!=0 && strcmp(password, pmb.pwd)!=0){
			printf("Username/Password Salah\n");
			salah++;
			system("pause");
			system("cls");
			if(salah==3){
				status=0;
				salah=0;
				printf(">>Mohon Maaf Batas Login Telah Habis<<\n");
				system("pause");
				system("cls");
				main();
				}
			menuLoginCustomer();
		}status++;
	}
}

void menuCustomer(){
	printf("------------------\n");
	printf("==== Customer ====\n");
	printf("------------------\n");
	printf("1. List Barang\n");
	printf("2. Cari barang sesuai Kategori\n");
	printf("3. Checkout atau Pemesanan\n");
	printf("4. Log Out\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &e1);
	
	switch(e1){
	case 1:
		system("cls");
		browseCustomer();
		break; 
	case 2:
		system("cls");
		searchBarang();
		break; 
	case 3:
		system("cls");
		prosesPembayaran();
		break; 
	case 4:
		system("cls");
		main();
		break; 
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-4 #\n");
		system("pause");
		system("cls");
		menuCustomer();
		break;
	}
}

void browseCustomer(){
	FILE *f_dm;
	
	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		
		printf("Nama Barang\t: %s\n",data.brg);
		printf("Kategori\t: %s\n",data.ktgr);
		printf("Jenis\t\t: %s\n",data.jenis);
		printf("Harga\t\t: %s\n",data.harga);
		printf("\n");
	}
	fclose(f_dm);
	system("pause");
	system("cls");
	menuCustomer();
}

void searchBarang(){
	puts("===== CARI BARANG =====");
	printf("Daftar Kategori\n");
	printf("0. Batal\n");
	printf("1. Mesin\n");
	printf("2. Ban\n");
	printf("3. Velg\n");
	printf("4. Aksesoris\n");
	printf("5. Jok\n");
	printf("6. Kembali\n");
	printf("Masukkan pilihan anda : ");
	scanf("%d",&j);
	switch (j) { 
		case 0:
			system("cls");
			menuCustomer();
		break;
		case 1:
			mesin();
			printf("\n");
			system("pause");
			system("cls");
			searchBarang();
		break; 
		case 2:
			ban();
			printf("\n");
			system("pause");
			system("cls");
			searchBarang();
		break; 
		case 3:
			velg();
			printf("\n");
			system("pause");
			system("cls");
			searchBarang();
		break; 
		case 4:
			aksesoris();
			printf("\n");
			system("pause");
			system("cls");
			searchBarang();
		break; 
		case 5:
			jok();
			printf("\n");
			system("pause");
			system("cls");
			searchBarang();
		break; 
		case 6:
			system("cls");
			menuCustomer();
		default : printf("Tidak ada daftar kategori yang anda inputkan");break;
	} 
}
void mesin(){
	FILE *f_dm;


	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		if(strcmp("mesin",data.ktgr)==0){
     		printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
			printf("   Kategori\t\t: %s\n",data.ktgr);
			printf("   Jenis\t\t: %s\n", data.jenis);
			printf("   Harga\t\t: Rp. %s\n", data.harga);
			printf("\n");
		}
	}
	fclose(f_dm);
}

void ban(){
	FILE *f_dm;


	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		if(strcmp("ban",data.ktgr)==0){
     		printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
			printf("   Kategori\t\t: %s\n",data.ktgr);
			printf("   Jenis\t\t: %s\n", data.jenis);
			printf("   Harga\t\t: Rp. %s\n", data.harga);
			printf("\n");
		}
	}
	fclose(f_dm);
}

void velg(){
	FILE *f_dm;


	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		if(strcmp("velg",data.ktgr)==0){
     		printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
			printf("   Kategori\t\t: %s\n",data.ktgr);
			printf("   Jenis\t\t: %s\n", data.jenis);
			printf("   Harga\t\t: Rp. %s\n", data.harga);
			printf("\n");
		}
	}
	fclose(f_dm);
}

void aksesoris(){
	FILE *f_dm;


	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		if(strcmp("aksesoris",data.ktgr)==0){
     		printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
			printf("   Kategori\t\t: %s\n",data.ktgr);
			printf("   Jenis\t\t: %s\n", data.jenis);
			printf("   Harga\t\t: Rp. %s\n", data.harga);
			printf("\n");
		}
	}
	fclose(f_dm);
}

void jok(){
	FILE *f_dm;


	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		if(strcmp("jok",data.ktgr)==0){
     		printf("%i. Nama barang\t\t: %s\n",i++,data.brg);
			printf("   Kategori\t\t: %s\n",data.ktgr);
			printf("   Jenis\t\t: %s\n", data.jenis);
			printf("   Harga\t\t: Rp. %s\n", data.harga);
			printf("\n");
		}
	}
	fclose(f_dm);
}

void prosesPembayaran(){
	FILE *f_dm;
	FILE *f_temp;
	
	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		
		printf("Nama Barang\t: %s\n",data.brg);
		printf("Kategori\t: %s\n",data.ktgr);
		printf("Jenis\t\t: %s\n",data.jenis);
		printf("Harga\t\t: %s\n",data.harga);
		printf("\n");
	}
	fclose(f_dm);
	getchar();
	
	f_dm = fopen("Data Barang.dat", "rb");
	f_temp = fopen("temp.dat", "wb");
	
	printf("(Jika tidak membeli, bisa tekan (=ENTER=)\n");
	printf("Masukkan Nama Barang yang akan dibeli : "); gets(hapus);
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		if(strcmp(data.brg,hapus)!=0){
		fwrite(&data,sizeof(data), 1, f_temp);
		printf("\n");
		printf("\t===== Proses pembelian anda telah berhasil =====\n");
		printf("\t==== Silahkan lakukan transaksi COD ====\n");
		printf("\t=== Di alamat : Jl. Airlangga No.100 Jombang ===\n");
		printf("\n");
		system("pause");
		system("cls");
		fflush(stdin);
		}
	}
	
	fclose(f_dm);
	fclose(f_temp);
	
	remove("Data Barang.dat");
	rename("temp.dat", "Data Barang.dat");
	system("cls");
	
	puts("====== Data Barang ======");
	f_dm = fopen("Data Barang.dat", "rb");
	
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		printf("Nama barang\t\t: %s\n", data.brg);
		printf("   Kategori\t\t: %s\n", data.ktgr);
		printf("   Jenis\t\t: %s\n", data.jenis);
		printf("   Harga\t\t: Rp. %s\n", data.harga);
		printf("\n");
	}
	
	fclose(f_dm);
	
	system("pause");
	system("cls");
	menuCustomer();
}


/////////////////// Dealer
void menuDealer(){
	printf("----------------\n");
	printf("==== Dealer ====\n");
	printf("----------------\n");
	printf("1. Login\n");
	printf("2. Kembali\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &b1);
	
	switch(b1){
	case 1:
		system("cls");
		menuLoginDealer();
		break; 
	case 2:
		system("cls");
		main();
		break; 
	
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-2 #\n");
		system("pause");
		system("cls");
		menuDealer;
		break;
	}	
}

void menuLoginDealer(){
	FILE *registrasi;
	getchar();
	registrasi = fopen("registrasi.dat", "ab");
	printf("=== LOGIN DEALER ===\n");
	printf("Username : ");
	gets(username);
	printf("Password : ");
	gets(password);
	
		if(strcmp(username,"Dealer")==0 && strcmp(password,"123")==0){
			for (int i=0;i<1;i++){
				status=0;
				salah=0;
				printf("Akses diterima. \n");
				system("pause");
				system("cls");
				menuOpsiDealer();
				break;
				}
			}else{
				printf("Username/Password Salah\n");
				salah++;
				system("pause");
				system("cls");
				if(salah==3){
					status=0;
					salah=0;
					printf(">>Mohon Maaf Batas Login Telah Habis<<\n");
					system("pause");
					system("cls");
					main();
				}
				menuLoginDealer();
			}
			status++;
}

void menuOpsiDealer(){
	
	printf("----------------\n");
	printf("==== Dealer ====\n");
	printf("----------------\n");
	printf("1. Melihat dan menghapus data Customer\n");
	printf("2. Menambah Data Barang\n");
	printf("3. Menghapus Data Barang\n");
	printf("4. Data Barang\n");
	printf("5. Log Out\n");
	printf("Masukkan nomor Pilihan :\n");
	scanf("%d", &c1);
	
	switch(c1){
	case 1:
		system("cls");
		menuDataCustomer();
		break; 
	case 2:
		system("cls");
		menu_MenambahDataBarang();
		break; 
	case 3:
		system("cls");
		menu_MenghapusDataBarang();
		break; 	
	case 4:
		system("cls");
		browseDealer();
		break; 
	case 5:
		system("cls");
		main();
		break; 
		
	default : 
	printf("\n# Tidak ada di pilihan #\n");
	printf("# Pilih Angka 1-3 #\n");
		system("pause");
		system("cls");
		menuOpsiDealer();
		break;
	}	
}


void menuDataCustomer(){
	FILE *f_registrasi;
	FILE *f_temp;
	
	puts("====== Data Customer ======");
	
	f_registrasi = fopen("f_registrasi.dat", "rb");
	
	i = 1;
	while(fread(&pmb,sizeof(pmb), 1,f_registrasi) == 1){
		printf("%d. ID\t    : %s\n", i, pmb.id);
        printf("   Password : %s\n", pmb.pwd);
        printf("   Nama     : %s\n", pmb.nama);
        printf("   Alamat   : %s\n", pmb.alamat);
        printf("   No. Telp : %s\n", pmb.tlp);
        printf("---------------------------------------\n");
        i++;
	}
	
	fclose(f_registrasi);
	
	//delete, cls
	getchar();
	f_registrasi = fopen("f_registrasi.dat", "rb");
	f_temp = fopen("temp.dat", "wb");
	
	printf("Masukkan ID yang akan dihapus : "); gets(hapus);
	
	while(fread(&pmb,sizeof(pmb), 1,f_registrasi) == 1){
		if(strcmp(pmb.id,hapus)!=0){
		fwrite(&pmb,sizeof(pmb), 1, f_temp);
		}
	}
	
	fclose(f_registrasi);
	fclose(f_temp);
	remove("f_registrasi.dat");
	rename("temp.dat", "f_registrasi.dat");
	system("cls");
	
	//header, display
	
	printf("====== Data Customer ======\n");
	f_registrasi = fopen("f_registrasi.dat", "rb");
	
	i = 1;
	while(fread(&pmb,sizeof(pmb), 1, f_registrasi) == 1){
		printf("%d. ID\t    : %s\n", i, pmb.id);
        printf("   Password : %s\n", pmb.pwd);
        printf("   Nama     : %s\n", pmb.nama);
        printf("   Alamat   : %s\n", pmb.alamat);
        printf("   No. Telp : %s\n", pmb.tlp);
        printf("---------------------------------------\n");
        i++;
	}
	
	fclose(f_registrasi);
system("pause");
system("cls");
menuOpsiDealer();
}

void menu_MenambahDataBarang(){
	FILE *f_dm;

	int i, n;
	
	puts("====== Data Barang ======");
	f_dm = fopen("Data Barang.dat", "ab");
	
	printf("Banyak barang yang akan diinput : "); scanf("%d", &n); getchar();
	for(i=1;i<=n;i++){
		printf("%d. Nama barang\t\t: ", i); gets(data.brg);
		printf("   Kategori\t\t: "); gets(data.ktgr);
		printf("   Jenis\t\t: "); gets(data.jenis);
		printf("   Harga\t\t: Rp. "); gets(data.harga);
		printf("\n");
//		fflush(stdin);
		
		fwrite(&data,sizeof(data), 1, f_dm);
	}
	fclose(f_dm);
	system("cls");
	
	//Header, display, pause
	
	puts("====== Data Barang ======");
	
	f_dm = fopen("Data Barang.dat", "rb");
	
	i = 1;
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		printf("%d. Nama barang\t\t: %s\n", i, data.brg);
		printf("   Kategori\t\t: %s\n", data.ktgr);
		printf("   Jenis\t\t: %s\n", data.jenis);
		printf("   Harga\t\t: Rp. %s\n", data.harga);
		printf("\n");
		i++;
	}
	
	fclose(f_dm);
	system("pause");
	
system("cls");
menuOpsiDealer();
}

void menu_MenghapusDataBarang(){
	FILE *f_dm;
	FILE *f_temp;
	
	puts("====== Data Barang ======");
	
	f_dm = fopen("Data Barang.dat", "rb");
	
	i = 1;
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		printf("%d. Nama barang\t\t: %s\n", i, data.brg);
		printf("   Kategori\t\t: %s\n", data.ktgr);
		printf("   Jenis\t\t: %s\n", data.jenis);
		printf("   Harga\t\t: Rp. %s\n", data.harga);
		printf("\n");
		i++;
	}
	
	fclose(f_dm);
	
	//delete, cls
	getchar();
	f_dm = fopen("Data Barang.dat", "rb");
	f_temp = fopen("temp.dat", "wb");
	
	printf("Masukkan kategori yang akan dihapus : "); gets(hapus);
	
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		if(strcmp(data.ktgr,hapus)!=0){
		fwrite(&data,sizeof(data), 1, f_temp);
		}
	}
	
	fclose(f_dm);
	fclose(f_temp);
	
	remove("Data Barang.dat");
	rename("temp.dat", "Data Barang.dat");
	system("cls");
	
	//header, display
	
	puts("====== Data Barang ======");
	f_dm = fopen("Data Barang.dat", "rb");
	
	i = 1;
	while(fread(&data,sizeof(data), 1, f_dm) == 1){
		printf("%d. Nama barang\t\t: %s\n", i, data.brg);
		printf("   Kategori\t\t: %s\n", data.ktgr);
		printf("   Jenis\t\t: %s\n", data.jenis);
		printf("   Harga\t\t: Rp. %s\n", data.harga);
		printf("\n");
		i++;
	}
	
	fclose(f_dm);
system("pause");
system("cls");
menuOpsiDealer();
}

void browseDealer(){
	FILE *f_dm;
	
	f_dm = fopen("Data Barang.dat", "rb");
	while(fread(&data,sizeof(data),1,f_dm)==1){
		
		printf("Nama Barang\t: %s\n",data.brg);
		printf("Kategori\t: %s\n",data.ktgr);
		printf("Jenis\t\t: %s\n",data.jenis);
		printf("Harga\t\t: %s\n",data.harga);
		printf("\n");
	}
	fclose(f_dm);
	system("pause");
	system("cls");
	menuOpsiDealer();
}
