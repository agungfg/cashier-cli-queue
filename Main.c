#include "Body.c"

int main(){
    long long int totalOnGoingHarga=0;//Inisialisasi Total Harga Berjalan = 0
	Queue BarangPelanggan;//Inisialisasi Antrian Barang Belanjaan Pelanggan
	Queue DatabaseBarang;//Inisialisasi Antrian Database Barang
	Queue DatabaseMember;//Inisialisasi Antrian Database Member
	createEmpty(&BarangPelanggan);//Membuat Antrian Barang Belanjaan Pelanggan
	createEmpty(&DatabaseBarang);//Membuat Antrian Database Barang
	createEmpty(&DatabaseMember);//Membuat Antrian Database Member
    databaseBarang(&DatabaseBarang);//Memanggil Isi Database Barang
    databaseMember(&DatabaseMember);//Memanggil Isi Database Member
	intro();//Loading Program
    menu(DatabaseBarang,DatabaseMember,BarangPelanggan,totalOnGoingHarga);//Masuk Ke Menu Utama
    return 0;
}
