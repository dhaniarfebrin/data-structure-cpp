#include <iostream>
#include <stdlib.h>

#define max 3

using namespace std;

struct Queue {
    string nama_makanan[max];
    int jumlah[max];
    int head;
    int tail;
} pesanan;

void init() {
    pesanan.head = 0;
    pesanan.tail = 0;
}

bool isKosong() {
    if (pesanan.tail == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPenuh() {
    if (pesanan.tail == max) {
        return true;
    } else {
        return false;
    }
}

void tampilkanPesanan() {
    cout<<"Pesanan:"<<endl;
    if (!isKosong())
    {    
        for(int i = pesanan.head; i < pesanan.tail; i++) {
            cout<<i+1<<". "<<pesanan.nama_makanan[i]<<" - "<<pesanan.jumlah[i];
        }
    } else {
        cout<<"Pesanan Kosong bang"<<endl;
    }
}

void daftarMakanan() {
    cout<<"Daftar Makanan"<<endl;
    cout<<"1. Cimol"<<endl;
    cout<<"2. Papeda"<<endl;
    cout<<"3. Cilor"<<endl;
    cout<<"4. Sempol"<<endl;
}

void tambahPesanan() {
    system("cls");
    daftarMakanan();

    if(!isPenuh()) {
        string makanan_baru;
        int menu, jumlah_baru;

        cout<<"Input Makanan [1/2/3/4] : ";
        cin>>menu;

        switch (menu)
        {
        case 1:
            makanan_baru = "Cimol";
            break;
        case 2:
            makanan_baru = "Papeda";
            break;
        case 3:
            makanan_baru = "Cilor";
            break;
        case 4:
            makanan_baru = "Sempol";
            break;
        default:
            cout<<"ga ada menunya";
            break;
        }

        cout<<"Jumlahnya? : ";
        cin>>jumlah_baru;

        pesanan.nama_makanan[pesanan.tail] = makanan_baru;
        pesanan.jumlah[pesanan.tail] = jumlah_baru;
        pesanan.tail++;

        cout<<"Data telah ditambahkan"<<endl;
    } else {
        cout<<"Pesanan sudah penuh, selesaikan pesanan untuk melanjutkan"<<endl;
    }
}

void selesaikanPesanan() {
    if (!isKosong())
    {
        cout<<"Menyelesaikan Makanan - "<<pesanan.nama_makanan[pesanan.head]<<"......"<<endl;
        for(int i = pesanan.head; i < pesanan.tail; i++) {
            pesanan.nama_makanan[i] = pesanan.nama_makanan[i+1];
        }

        pesanan.tail--;
    } else {
        cout<<"Ga ada pesanan bang"<<endl;
    }
    
}

void tampilanMenuAntrian() {
    int menu;
    system("clear");

    cout<<"==========================="<<endl;
    cout<<"Fitur Antrian Pesan Makanan"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1. Pesan Makanan"<<endl;
    cout<<"2. Tampilkan Pesanan"<<endl;
    cout<<"3. Selesaikan Pesanan"<<endl;
    cout<<"==========================="<<endl;
    cout<<"Pilih Menu : ";
    cin>>menu;

    switch (menu)
    {
    case 1:
        tambahPesanan();
        break;
    case 2:
        tampilkanPesanan();
        break;
    case 3:
        selesaikanPesanan();
        break;
    default:
        cout<<"Menu tidak ada"<<endl;
        break;
    }
}