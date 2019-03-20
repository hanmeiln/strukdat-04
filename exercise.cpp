/*
Nama Program : Exercise
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 20 Maret 2019
Deskripsi    : List pegawai
**************************************************************/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct ElemtList{
    char nama[30];
    char bidang[40];
    int gaji;
    ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void insertLast(List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast(List& First, pointer& pHapus);
void traversal(List First);

main(){
    pointer p;
    List Pegawai;
    int pil;
    createList(Pegawai);
    while(1){
        system("cls");
        cout<<"----------------PILIHAN----------------"<<endl;
        cout<<"1. Masukkan data di awal (Insert First)"<<endl;
        cout<<"2. Masukkan data di akhir (Insert Last)"<<endl;
        cout<<"3. Hapus data pertama (Delete First)"<<endl;
        cout<<"4. Hapus data terakhir (Delete Last)"<<endl;
        cout<<"5. Cetak data"<<endl;
        cout<<"6. Keluar "<<endl;
        cout<<"Masukkan Pilihan : ";
        cin>>pil;
        switch(pil){
            case 1:
            createElmt(p);
            insertFirst(Pegawai,p);
            cout<<"Data berhasil dibuat";
            getch();
            break;

            case 2:
            createElmt(p);
            insertLast(Pegawai,p);
            cout<<"Data berhasil dibuat";
            getch();
            break;

            case 3:
            deleteFirst(Pegawai,p);
            cout<<"Data berhasil dihapus";
            getch();
            break;

            case 4:
            deleteLast(Pegawai,p);
            cout<<"Data berhasil dihapus";
            getch();
            break;

            case 5:
            traversal(Pegawai);
            getch();
            break;

            case 6:
            return 0;
            break;
        }
    }
}

void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Nama : ";
	cin.ignore();
	cin.getline(pBaru->nama,30);
	cout<<"Bidang : ";
	cin.ignore();
	cin.getline(pBaru->bidang,40);
	cout<<"Gaji : ";
	cin>>pBaru->gaji;
	pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void deleteFirst(List& First, pointer& pHapus){
	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}else{
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}

void deleteLast(List& First, pointer& pHapus){
	pointer last,precLast;
	if(First==NULL){
		cout<<"List Kosong";
	}else if(First->next==NULL){
		pHapus=First;
		First=NULL;
	}else{
		last=First;
		precLast=NULL;
		while(last->next!=NULL){
			precLast=last;
			last=last->next;
		}
		pHapus=last;
		precLast->next=NULL;
	}
}

void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		do{
            cout<<"---------------------------------"<<endl;
            cout<<"Data Pegawai ke-"<<i<<endl;
            cout<<"Nama : "<<pBantu->nama<<endl;
            cout<<"Bidang : "<<pBantu->bidang<<endl;
            cout<<"Gaji : "<<pBantu->gaji<<endl;
			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}
