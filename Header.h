#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <string.h>
#define true 1
#define false 0

typedef struct tElmtKasir *address;
typedef struct tElmtKasir {
    char* namaBarang;//Asumsi Nama Barang Tidak Ada Yang Sama
	char* kodeBarang;//Asumsi Kode Barang 8 Digit Tidak Ada Yang Sama
	char* kodeMember;//Asumsi Kode Member 8 Karakter Tidak Ada Yang Sama
	long long int hargaBarangSatuan;//Asumsi Harga Barang Satuan Dalam Rupiah
	long long int hargaTotalBarangSatuanPelanggan;//Asumsi Harga Total Barang Satuan = Banyak Barang * Harga Barang Satuan
	int banyakBarang;//Asumsi Banyak Barang Tidak Boleh Negatif
	address next;
} Elmt;

typedef struct {
	address head;
	address tail;
} Queue;

// HEADER PROSEDUR DAN FUNGSI

void createEmpty(Queue *Q);//Prosedur Membuat Antrian Kosong
address alokasiBarangPelanggan(char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX, long long int hargaTotalBarangSatuanPelangganX, int banyakBarangX);//Prosedur Untuk Memesan Database Barang Belanjaan Pelanggan di Memori
address alokasiDatabaseBarang(char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX);//Prosedur Untuk Memesan Database Barang di Memori
address alokasiDatabaseMember(char* kodeMemberX);//Prosedur Untuk Memesan Database Member di Memori
void dealokasi(address p);//Prosedur Untuk Menghapus Antrian dari Memori
boolean isEmpty(Queue Q);//Prosedur Mencek Head Antrian Kosong Atau Tidak
void addAddress(Queue *Q, address p);//Prosedur Antrian Ke Memori
void addBarangPelanggan(Queue *Q, char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX, long long int hargaTotalBarangSatuanPelangganX, int banyakBarangX);//Prosedur Menambahkan Database Barang Belanjaan Pelanggan Ke Memori
void addDatabaseBarang(Queue *Q, char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX);//Prosedur Menambahkan Database Barang Ke Memori
void addDatabaseMember(Queue *Q,char* kodeMemberX);//Prosedur Menambahkan Database Member Ke Memori
void intro();//Prosedur Loading Program
void menu(Queue Database, Queue DatabaseMember, Queue BarangPelanggan, long long int totalOnGoingHarga);//Prosedur Untuk Memilih Menu Utama
boolean cariKodeBarang(Queue Database,char kodeBarangX[10]);//Prosedur Untuk Mencari Barang di Database
void cetakStruk(Queue *BarangPelanggan, Queue DatabaseMember);//Prosedur Untuk Mencetak Struk Belanjaan Sekaligus Menghapus Antrian Daftar Barang Belanjaan
void cariBarang(Queue Database,char kodeBarangX[10],char namaBarangX[50],long long int *hargaBarangSatuanX);//Prosedur Untuk Mendefinisikan Nama Barang dan Harga Barang Satuan
boolean cariMember(Queue DatabaseMember,char kodeMemberX[10]);//Prosedur Untuk Mencari Member di Database
void mulaiProgram(Queue Database, Queue BarangPelanggan, Queue DatabaseMember, long long int totalOnGoingHarga);//Prosedur Untuk Memulai Program
void databaseBarang(Queue *Database);//Prosedur Yang Berisi Database Barang
void databaseMember(Queue *Member);//Prosedur Yang Berisi Database Member
void cetakDatabaseBarang(Queue Database);//Prosedur Mencetak Database Barang
void cetakDatabaseMember(Queue Member);//Prosedur Mencetak Database Member
void credit();//Prosedur Menampilkan Pembuat Program
