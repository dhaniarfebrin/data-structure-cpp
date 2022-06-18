#include <iostream>
#include <stdlib.h>

using namespace std;

// break the code separately to multiple files
#include "queue.h"
#include "functions.h"

int main() {
	int menu;
	string exit;
	bool isExit = false;
	
	do {
		system("clear");
		cout<<"==============="<<endl;
		cout<<"   Aplikasi    "<<endl;
		cout<<"==============="<<endl;
		cout<<"1. Input data mahasiswa"<<endl;
		cout<<"2. Hitung IPK"<<endl;
		cout<<"3. Urutkan Mahasiswa berdasarkan NIM"<<endl;
		cout<<"4. Tampilkan daftar mahasiswa"<<endl;
		cout<<"5. Cari Mahasiswa"<<endl;
		cout<<"6. Pesan Makanan (queue)"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Pilih salah satu menu diatas [1/2/3/4/5/6/7]: ";
		cin>>menu;
	
		switch (menu) {
			case 1:
				InputMahasiswa();
				break;
			case 2:
				InputNilaiMatkul();
				break;
			case 3:
				urutkanNIM();
				break;
			case 4:
				tampilkanMahasiswa();
				break;
			case 5:
				cariMhs();
				break;
			case 6:
				tampilanMenuAntrian();
				break;
			case 7:
				goto keluar;
			default:
				cout<<"Menu tidak ada"<<endl;
				break;
		}
		
		cout<<endl;
		cout<<"Ingin keluar ? [y/n] :  ";
		cin>>exit;

		isExit = exit == "y" ? true : false;
			
	} while (!isExit);
	
	keluar:

	return 0;
}
