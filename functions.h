#include <iostream>
#include <stdlib.h>

using namespace std;


// array of struct
struct
{
	/* data */
	string nama;
	string nim;
}Mahasiswa[99];

int jumlah_mhs;

void cariMhs() {
	system("clear");
	string nama_yang_dicari;
	bool ketemu = false;
	int posisi;

	cout<<"Cari Mahasiswa"<<endl;
	cout<<"Nama Mahasiswa yang Dicari : ";
	cin>>nama_yang_dicari;

	for(int i = 0; i < jumlah_mhs; i++) {
		if(Mahasiswa[i].nama == nama_yang_dicari) {
			ketemu = true;
			posisi = i;
			break;
		}
	}

	if(ketemu) {
		cout<<"Nama ditemukan, '"<<nama_yang_dicari<<"' ditemukan di posisi "<< posisi <<" indeks array"<<endl;
	} else {
		cout<<"Nama tidak ditemukan"<<endl;
	}
}

void InputMahasiswa() {

	cout<<"Masukkan jumlah mahasiswa : ";
	cin>>jumlah_mhs;

	// Mahasiswa.nama = new string[jumlah_mhs]; // memory allocation
	// Mahasiswa.nim = new string[jumlah_mhs]; // memory allocation

	for (int i = 0; i < jumlah_mhs; i++ ) {
		cout<<endl;

		cout<<"Input data mahasiswa - "<<i+1<<" : "<<endl;
		cout<<"Nama\t : ";
		cin>>Mahasiswa[i].nama;
		cout<<"NIM\t : ";
		cin>>Mahasiswa[i].nim;
	}
	
}

void HitungIpk(int* jumlah_matkul, int nilai_matkul[99]) {
	float ipk , jumlah_nilai;
	
	for (int i = 0; i < (*jumlah_matkul); i++) {
		jumlah_nilai += nilai_matkul[i]; 
	}

    ipk = jumlah_nilai / (*jumlah_matkul);
	
	cout<<"IPK\t : "<< ipk  <<endl;
}

void InputNilaiMatkul() {
	
	int jumlah_matkul;
	
	system("clear");
	cout<<"========================"<<endl;
	cout<<" Input nilai matkul mhs"<<endl;
    cout<<"========================"<<endl;
	cout<<"Jumlah matkul : ";
	cin>>jumlah_matkul;
	int nilai_matkul[jumlah_matkul];
	char tmp[jumlah_matkul];
	
	for (int i = 0; i < jumlah_matkul; i++) {
		cout<<"Nilai matkul ke - "<< i + 1 << " [A/B/C/D/E] : ";
		cin>>tmp[i];
		
		if (tmp[i] == 'A') {
			nilai_matkul[i] = 4;
		} else if (tmp[i] == 'B') {
			nilai_matkul[i] = 3;
		} else if (tmp[i] == 'C') {
			nilai_matkul[i] = 2;
		} else if (tmp[i] == 'D') {
			nilai_matkul[i] = 1;
		} else if (tmp[i] == 'E') {
			nilai_matkul[i] = 0;
		}
	}

	system("clear");	

	HitungIpk(&jumlah_matkul, nilai_matkul);
}

void bubbleSort() {
	int i, j, second = 0;
	string temp;

	for(i = 0; i < (jumlah_mhs-1); i++) {
		for (j = 0; j < (jumlah_mhs-1); j++){
			second = j+1;
			if (Mahasiswa[j].nim > Mahasiswa[second].nim){
				// pertukaran nama
				temp = Mahasiswa[j].nama;
				Mahasiswa[j].nama = Mahasiswa[second].nama;
				Mahasiswa[second].nama = temp;

				// pertukaran nim
				temp = Mahasiswa[j].nim;
				Mahasiswa[j].nim = Mahasiswa[second].nim;
				Mahasiswa[second].nim = temp;
			}
			
		}
	}
	cout<<"Berhasil diurutkan dengan Bubble Ascending"<<endl;
}

void selectionSort() {
	int i, maks, j;
	string temp;

	for(i = 0; i < jumlah_mhs; i++) {
		maks = i;
		for(j = i+1; j < jumlah_mhs; j++) {
			if(Mahasiswa[maks].nim > Mahasiswa[j].nim){
				// mencari indeks dengan value terendah
				maks = j;
			}
		}
		if (Mahasiswa[i].nim != Mahasiswa[maks].nim) {
			// pertukaran nama
			temp = Mahasiswa[i].nama;
			Mahasiswa[i].nama = Mahasiswa[maks].nama;
			Mahasiswa[maks].nama = temp;

			// pertukaran nim
			temp = Mahasiswa[i].nim;
			Mahasiswa[i].nim = Mahasiswa[maks].nim;
			Mahasiswa[maks].nim = temp;
		}
	}
	cout<<"Berhasil diurutkan dengan Selection Ascending"<<endl;
}

void insertionSort() {
	int i, j, second;
	string temp, temp2;

	for (i = 0; i < jumlah_mhs; i++) {
		temp = Mahasiswa[i].nim;
		temp2 = Mahasiswa[i].nama;
		j = i-1; 

		while (Mahasiswa[j].nim > temp && j >= 0)
		{
			Mahasiswa[j+1].nim = Mahasiswa[j].nim;
			Mahasiswa[j+1].nama = Mahasiswa[j].nama;
			j--;
		}
		second = j+1;
		Mahasiswa[second].nim = temp;
		Mahasiswa[second].nama = temp2;
	}
	cout<<"Berhasil diurutkan dengan Insertion Ascending"<<endl;
}

void urutkanNIM() {
	// selection sorting
	int sort;

	sortMenu:
	system("clear");
	cin.ignore();
	cout<<"==========="<<endl;
	cout<<"Mengurutkan"<<endl;
	cout<<"==========="<<endl;
	cout<<"1. Bubble sort"<<endl;
	cout<<"2. Selection sort"<<endl;
	cout<<"3. Insertion sort"<<endl;
	cout<<"pilih salah satu [1-3] : "; cin>>sort;

	switch(sort) {
		case 1:
			bubbleSort();
			break;
		case 2:
			selectionSort();
			break;
		case 3:
			insertionSort();
			break;
		default:
			cout<<"menu yang anda inputkan tidak ada";
			system("pause");
			goto sortMenu;
	}
}

void tampilkanMahasiswa() {
	system("clear");

	cout<<"================"<<endl;
	cout<<"Daftar Mahasiswa"<<endl;
	cout<<"================"<<endl;
	cout<<"|  NIM  |  Nama  |"<<endl;

	for(int i = 0; i < jumlah_mhs; i++ ) {
		cout<<"| "<<Mahasiswa[i].nim<<" | "<<Mahasiswa[i].nama<<" | "<<endl;
	}
}