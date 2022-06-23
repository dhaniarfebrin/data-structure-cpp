#include <iostream>
#include <stdlib.h>

using namespace std;

struct Mhss
{
    string nama;
    int nim;
    Mhss *next;
};

Mhss *headMhs = NULL;
Mhss *currentMhs = NULL;

bool isEmpty();
void insertMahasiswa(string nama, int nim);
void printMahasiswa();
void hapusDariBelakang();
void hapusDariDepan();
void kosongkanMahasiswa();

int linkedList() {
    int pilihanMenu, nim;
    string nama;
    char isKeluar;

    do
    {
        system("clear");
        cout<<"<<<< Pilihan Menu >>>>"<<endl;
        cout<<"1. Tambah Mahasiswa"<<endl;
        cout<<"2. Tampilkan Mahasiswa"<<endl;
        cout<<"3. Hapus Mahasiswa dari Belakang"<<endl;
        cout<<"4. Hapus Mahasiswa dari Depan"<<endl;
        cout<<"5. Kosongkan daftar Mahasiswa"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Masukkan pilihan anda : "; cin>>pilihanMenu;
        cout<<endl;

        switch (pilihanMenu)
        {
        case 1:
            cin.ignore();
            cout<<"<< INPUT MAHASISWA >>"<<endl;
            cout<<"Input nama : "; getline(cin, nama);
            cout<<"Input nim : "; cin>>nim;

            insertMahasiswa(nama, nim);
            break;
        case 2:
            printMahasiswa();
            break;
        case 3:
            hapusDariBelakang();
            break;
        case 4:
            hapusDariDepan();
            break;
        case 5:
            kosongkanMahasiswa();
            break;
        case 6:
            goto keluar_linkedList;
        default:
            cout<<"Pilihan menu tidak ada"<<endl;
            break;
        }
        cout<<"Keluar? [y/n] : "; cin>>isKeluar;
    } while (isKeluar == 'n' || isKeluar == 'N');

    keluar_linkedList:
    return 0;
}

bool isEmpty() {
    return (headMhs == NULL);
}

void insertMahasiswa(string nama, int nim) {
    Mhss *newMhs = NULL;
    newMhs = new Mhss;

    newMhs->nama = nama;
    newMhs->nim = nim;

    if(isEmpty()) {
        headMhs = newMhs;
    } else {
        currentMhs->next = newMhs;
    }

    currentMhs = newMhs;
    currentMhs->next = NULL;

    cout<<"Mahasiswa berhasil ditambahkan"<<endl;
}

void printMahasiswa() {
    Mhss *awalMhs = headMhs;
    int i = 1;

    if (!isEmpty()){
        cout<<"Daftar Mahasiswa"<<endl;
        cout<<"NO |   Nama   |  NIM  "<<endl;
        while (awalMhs != NULL)
        {
            cout<<i<<"  | "<<awalMhs->nama<<" | "<<awalMhs->nim<<endl;
            awalMhs = awalMhs->next;
            i++;
        }
    } else {
        cout<<"Data masih kosong"<<endl;
    }
    cout<<endl;
}

void hapusDariBelakang() {
    if (!isEmpty())
    {
        if (headMhs == currentMhs) {
            headMhs = NULL;
            currentMhs = NULL;
        } else {
            Mhss *bantu = headMhs;
            Mhss *hapusMhs = currentMhs;

            while (bantu->next != currentMhs)
            {
                bantu = bantu->next;
            }
            
            currentMhs = bantu;
            currentMhs->next = NULL;
            delete hapusMhs;
            
            cout<<"Berhasil dihapus"<<endl<<endl;
        }
    } else {
        cout<<"Data mahasiswa kosong!!"<<endl<<endl;
    }
}

void hapusDariDepan() {
    if (!isEmpty())
    {    
        Mhss *hapusMhs = headMhs;

        headMhs = headMhs->next;

        delete hapusMhs;
        cout<<"Berhasil dihapus"<<endl;
    } else {
        cout<<"Data mahasiswa kosong!!"<<endl<<endl;
    }
}

void kosongkanMahasiswa() {
    if(!isEmpty()) {
        Mhss *bantu, *hapusMhs;
        bantu = headMhs;

        while (bantu->next != currentMhs)
        {
            hapusMhs = bantu;
            bantu = bantu->next;
            delete hapusMhs;
        }
        
        headMhs = NULL;
        currentMhs = NULL;
        cout<<"Berhasil dihapus semuanya!!"<<endl;
    } else {
        cout<<"Data mahasiswa kosong!!"<<endl<<endl;
    }
}