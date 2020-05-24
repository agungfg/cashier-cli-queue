#include "Header.h"
#include "Database.c"

void createEmpty(Queue *Q){
    (*Q).head=NULL;
    (*Q).tail=NULL;
}
address alokasiBarangPelanggan(char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX, long long int hargaTotalBarangSatuanPelangganX, int banyakBarangX){
    address p=(address)malloc(sizeof(Elmt));
    if(p!=NULL){
        (*p).kodeBarang=kodeBarangX;
        (*p).namaBarang=namaBarangX;
        (*p).hargaBarangSatuan=hargaBarangSatuanX;
        (*p).hargaTotalBarangSatuanPelanggan=hargaTotalBarangSatuanPelangganX;
        (*p).banyakBarang=banyakBarangX;
        (*p).next=NULL;
    }
    return p;
}
address alokasiDatabaseBarang(char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX){
    address p=(address)malloc(sizeof(Elmt));
    if(p!=NULL){
        (*p).kodeBarang=kodeBarangX;
        (*p).namaBarang=namaBarangX;
        (*p).hargaBarangSatuan=hargaBarangSatuanX;
        (*p).next=NULL;
    }
    return p;
}
address alokasiDatabaseMember(char* kodeMemberX){
    address p=(address)malloc(sizeof(Elmt));
    if(p!=NULL){
        (*p).kodeMember=kodeMemberX;
        (*p).next=NULL;
    }
    return p;
}
void dealokasi(address p){
    free(p);
}
boolean isEmpty(Queue Q){
    if(Q.head==NULL){
        return true;
    }else{
        return false;
    }
}
void addAddress(Queue *Q, address p){
    if(isEmpty(*Q)){
        (*Q).head=p;
        (*Q).tail=p;
    }else{
        (*Q).tail->next=p;
        (*Q).tail=p;
    }
}
void addBarangPelanggan(Queue *Q, char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX, long long int hargaTotalBarangSatuanPelangganX, int banyakBarangX){
    address q=alokasiBarangPelanggan(kodeBarangX,namaBarangX,hargaBarangSatuanX,hargaTotalBarangSatuanPelangganX,banyakBarangX);
    addAddress(Q,q);
}
void addDatabaseBarang(Queue *Q, char* kodeBarangX, char* namaBarangX, long long int hargaBarangSatuanX){
    address q=alokasiDatabaseBarang(kodeBarangX,namaBarangX,hargaBarangSatuanX);
    addAddress(Q,q);
}
void addDatabaseMember(Queue *Q,char* kodeMemberX){
    address q=alokasiDatabaseMember(kodeMemberX);
    addAddress(Q,q);
}
void intro(){
    char* loading;
    int i;
    loading="LOADING";
    for(i=0;i<=strlen(loading);i++){
        Sleep(1000);
        printf("%c",loading[i]);
    }
}
void menu(Queue Database, Queue DatabaseMember, Queue BarangPelanggan, long long int totalOnGoingHarga){
    int pilihan;
	do{
        system("cls");
        printf("||=========================================||\n");
        printf("||      Program Kasir Menggunakan Queue    ||\n");
        printf("||=========================================||\n");
        printf("||      1. Mulai Program                   ||\n");
        printf("||      2. Database Barang                 ||\n");
        printf("||      3. Database Member                 ||\n");
        printf("||      4. Credit                          ||\n");
        printf("||      5. Exit                            ||\n");
        printf("||=========================================||\n");
        printf("Masukan Pilihan : ");
        scanf("%d",&pilihan);
        getchar();
        switch(pilihan){
            case 1:mulaiProgram(Database,BarangPelanggan,DatabaseMember,totalOnGoingHarga);break;
            case 2:cetakDatabaseBarang(Database);break;
            case 3:cetakDatabaseMember(DatabaseMember);break;
            case 4:credit();break;
            case 5:exit(0);break;
            default:printf("Pilihan Yang Anda Masukkan Salah");break;
        }
	}while(pilihan <1 || pilihan>5);
	menu(Database,DatabaseMember,BarangPelanggan,totalOnGoingHarga);
}
boolean cariKodeBarang(Queue Database,char kodeBarangX[10]){
    while(!isEmpty(Database)){
		if(strcmp((Database).head->kodeBarang,kodeBarangX)==0){
            return true;
		}
		(Database).head=(Database).head->next;
	}
	return false;
}
void cetakStruk(Queue *BarangPelanggan, Queue DatabaseMember){
    system("cls");
    address q;
    char kodeMember[10][10];
    long long int hargaTotalSemuaBelanjaan=0;
    long long int uangPelanggan=0;
    if(isEmpty(*BarangPelanggan)){
        printf("Barang Pelanggan Belum Ditambahkan");
    }

    while(!isEmpty(*BarangPelanggan)){
        printf("Kode Barang         : %s\n",(*BarangPelanggan).head->kodeBarang);
        printf("Nama Barang         : %s\n",(*BarangPelanggan).head->namaBarang);
        printf("Banyak Barang       : %i\n",(*BarangPelanggan).head->banyakBarang);
        printf("Harga Satuan        : Rp. %lli\n",(*BarangPelanggan).head->hargaBarangSatuan);
        printf("Harga Total Barang  : Rp. %lli\n\n",(*BarangPelanggan).head->hargaTotalBarangSatuanPelanggan);
        hargaTotalSemuaBelanjaan+=(*BarangPelanggan).head->hargaTotalBarangSatuanPelanggan;
        q=(*BarangPelanggan).head;
        (*BarangPelanggan).head=(*BarangPelanggan).head->next;
        dealokasi(q);
	}
	printf("||================================================||\n");
	printf("   HARGA TOTAL SEMUA BELANJAAN  : Rp. %lli          \n",hargaTotalSemuaBelanjaan);
	printf("||================================================||\n");

    do{
        printf("\nMember\n");
        printf(" -  Jika Bukan Member\n");
        printf("Masukan Kode Member : ");
        gets(kodeMember[1]);
        if(strcmp(kodeMember[1],"-")==0){
            break;
        }
        if(cariMember(DatabaseMember,kodeMember[1])==0){
            printf("Member Tidak Terdaftar\n");
            getch();
    }
    }while(cariMember(DatabaseMember,kodeMember[1])==0);
    if(cariMember(DatabaseMember,kodeMember[1])==1){
        printf("Member Terdaftar Diskon 5 Persen\n");
        printf("||================================================||\n");
        printf("   DISKON                       : Rp. %lli          \n",(hargaTotalSemuaBelanjaan*5)/100);
        hargaTotalSemuaBelanjaan=hargaTotalSemuaBelanjaan-((hargaTotalSemuaBelanjaan*5)/100);
        printf("   HARGA TOTAL SEMUA BELANJAAN  : Rp. %lli          \n",hargaTotalSemuaBelanjaan);
        printf("||================================================||\n");
    }

	do{
        printf("Masukan Uang Customer  : Rp. ");
        scanf("%i",&uangPelanggan);
        if((uangPelanggan-hargaTotalSemuaBelanjaan)<0){
            printf("Uang Customer Kurang\n");
            getch();
        }
	}while((uangPelanggan-hargaTotalSemuaBelanjaan)<0);
	uangPelanggan=uangPelanggan-hargaTotalSemuaBelanjaan;
    printf("Kembalian               : Rp. %lli",uangPelanggan);
	getch();getch();
}
void cariBarang(Queue Database,char kodeBarangX[10],char namaBarangX[50],long long int *hargaBarangSatuanX){
    while(!isEmpty(Database)){
		if(strcmp((Database).head->kodeBarang,kodeBarangX)==0){
            strcpy(namaBarangX,(Database).head->namaBarang);
            *hargaBarangSatuanX=(Database).head->hargaBarangSatuan;
		}
		(Database).head=(Database).head->next;
	}
}
boolean cariMember(Queue DatabaseMember,char kodeMemberX[10]){
    while(!isEmpty(DatabaseMember)){
		if(strcmp((DatabaseMember).head->kodeMember,kodeMemberX)==0){
            return true;
		}
		(DatabaseMember).head=(DatabaseMember).head->next;
	}
	return false;
}

void belanjaanOnGoing(Queue BarangPelanggan){
    while(!isEmpty(BarangPelanggan)){
        printf("Kode Barang         : %s\n",(BarangPelanggan).head->kodeBarang);
        printf("Nama Barang         : %s\n",(BarangPelanggan).head->namaBarang);
        printf("Banyak Barang       : %i\n",(BarangPelanggan).head->banyakBarang);
        printf("Harga Satuan        : Rp. %lli\n",(BarangPelanggan).head->hargaBarangSatuan);
        printf("Harga Total Barang  : Rp. %lli\n\n",(BarangPelanggan).head->hargaTotalBarangSatuanPelanggan);
        (BarangPelanggan).head=(BarangPelanggan).head->next;
	}
}

void mulaiProgram(Queue Database, Queue BarangPelanggan, Queue DatabaseMember, long long int totalOnGoingHarga){
    char kodeBarang[10][10];
    char namaBarang[100];
    int proses;
    long long int hargaBarangSatuan;
    int banyakBarang;
    long long int hargaTotalBarangSatuanPelanggan;
    do{
        system("cls");
        if((BarangPelanggan).head!=NULL){
            printf("        Daftar Belanjaan\n");
            belanjaanOnGoing(BarangPelanggan);
        }
        printf("Total Harga                 : Rp. %i\n",totalOnGoingHarga);
        printf("Ketik 'OK' Untuk Cetak Struk\n");
        printf("Masukan Kode Barang 8 Digit : ");
        gets(kodeBarang[1]);
        if(strcmp(kodeBarang[1],"OK")==0 && (BarangPelanggan).head==NULL){
            system("cls");
            printf("Barang Belanjaan Pelanggan Kosong");
            getch();
            menu(Database,DatabaseMember,BarangPelanggan,totalOnGoingHarga);
        }else if(strcmp(kodeBarang[1],"OK")==0){
            cetakStruk(&BarangPelanggan,DatabaseMember);
            menu(Database,DatabaseMember,BarangPelanggan,totalOnGoingHarga);
        }
    }while(cariKodeBarang(Database,kodeBarang[1])==0);

    do{
        system("cls");
        printf("Masukan Banyak Barang     :");
        scanf("%i",&banyakBarang);
        if(banyakBarang<=0){
            printf("Banyak Barang Tidak Valid");
            getch();
        }
    }while(banyakBarang<=0);

    cariBarang(Database,kodeBarang[1],&namaBarang,&hargaBarangSatuan);
    hargaTotalBarangSatuanPelanggan=hargaBarangSatuan*banyakBarang;

    printf("\nKode Barang     : %s\n",kodeBarang[1]);
    printf("Nama Barang     : %s\n",namaBarang);
    printf("Banyak Barang   : Rp. %i\n",banyakBarang);
    printf("Harga Satuan    : Rp. %lli\n",hargaBarangSatuan);
    printf("Harga Total     : Rp. %lli\n",hargaTotalBarangSatuanPelanggan);

    do{
        printf("\n1.Ya\n2.Tidak\nProses? ");
        scanf("%i",&proses);
        if(proses<1 || proses>2){
            printf("Inputan Tidak Valid");
            getch();
        }
    }while(proses<1 || proses>2);

    if(proses==1){
        addBarangPelanggan(&BarangPelanggan,kodeBarang[1],namaBarang,hargaBarangSatuan,hargaTotalBarangSatuanPelanggan,banyakBarang);
        totalOnGoingHarga+=hargaTotalBarangSatuanPelanggan;
        mulaiProgram(Database,BarangPelanggan,DatabaseMember,totalOnGoingHarga);
    }else if(proses==2){
        mulaiProgram(Database,BarangPelanggan,DatabaseMember,totalOnGoingHarga);
    }
}
void cetakDatabaseBarang(Queue Database){
    system("cls");
    int no=1;
    printf("                Database Barang\n");
    printf("    No  Kode Barang     Harga Barang        Nama Barang\n");
    while(!isEmpty(Database)){
        printf("%6i    %6s        Rp. %6lli      %6s\n",no,(Database).head->kodeBarang,(Database).head->hargaBarangSatuan,(Database).head->namaBarang);
        no+=1;
        (Database).head=(Database).head->next;
	}
    getch();
}
void cetakDatabaseMember(Queue Member){
    system("cls");
    int no=1;
    printf("    Database Member\n");
    printf("    No  Kode Member\n");
    while(!isEmpty(Member)){
        printf("%6i    %6s\n",no,(Member).head->kodeMember);
        no+=1;
        (Member).head=(Member).head->next;
	}
    getch();
}
void credit(){
    system("cls");
    printf("||===============================================||\n");
    printf("||        Program Kasir Menggunakan Queue        ||\n");
    printf("||===============================================||\n");
    printf("||       NIM            Nama             Kelas   ||\n");
    printf("||===============================================||\n");
    printf("||    1302150019 Agung Fajar Gumilar   CS-39-01  ||\n");
    printf("||    1302150043 M. Ardi Rizmaldi      CS-39-01  ||\n");
    printf("||    1302154151 M. Alvin Yuda Pratama CS-39-01  ||\n");
    printf("||    1302154157 Uggi Stivani Savitri  CS-39-01  ||\n");
    printf("||===============================================||\n");
    getch();
}
