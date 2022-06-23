#include <iostream>
#include <stdlib.h>

using namespace std;

#include "Common.h"
#include "linkedList.h"

int main() {
    int menu;
    system("clear");

    cout<<"Pilih versi dari aplikasi"<<endl;
    cout<<"1. Versi Biasa"<<endl;
    cout<<"2. Versi Linked List"<<endl;
    cout<<"Pilih salah satu menu diatas [1/2] : ";
    cin>>menu;

    switch (menu)
    {
    case 1:
        common();
        break;
    case 2:
        linkedList();
        break;
    default:
        cout<<"menu tidak ada"<<endl;
        break;
    }

    return 0;
}