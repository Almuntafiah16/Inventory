#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char option;
    int pilih , maks_inv , maks_item , tambah , hapus , acak;
    vector<string> item {"Parang . stat : 7" , "Panci . stat : 6","VSS . stat : 10"};
    vector<string> inve;
    vector<string>::iterator penunjuk ; // bisa diisi di sini juga
//    tes.push_back("Item 1"); // tambahkan item 1
//    tes.push_back("Item 2"); // tambahkan item 2
//    tes[1] = "item5";
    vector<string>::iterator penunjuk2;
    srand(static_cast<unsigned>(time(0)));

    maks_item=item.size();
    cout<< "Maksimal Item : " << maks_item << endl;
    cout << "Masukkan Maks Inventory : "; cin>> maks_inv;

    do{
    cout << "Inventory System :" << endl;
    cout << "1. Tampilkan Inventory" << endl;
    cout << "2. Tambah Item" << endl;
    cout << "3. Hapus Item" << endl;
    cout << "Masukkan Pilihan Anda : "; cin >> pilih;


    switch(pilih){
    case 1:
        // Menampilkan Inventory

        if(inve.empty())//memberitahukan jika inventory masih kosong
        {
            cout << "\nMaaf Inventory anda masih kosong" << endl;

        }
        else// jika ada isi maka proses
        {
            cout<<endl;
           for(penunjuk = inve.begin() ; penunjuk != inve.end(); ++penunjuk)
            {
                cout << *penunjuk << endl;
            }
        }
        break;
    case 2: // tambah Item
        // jika inventory penuh
        if(inve.size()>= maks_inv)
        {
            cout << "\ninventory Penuh" << endl;
        }
        else // jika masih ada inventory
        {
            acak=rand()%maks_item;
            inve.push_back(item[acak]);
            cout << "\nItem yang ditambahkan yaitu : " << item[acak] << endl;
            // menampilkan inventory
            cout << "\nAnda Mendapatkan Item : " << item[acak]<< endl;

        }
        break;
    case 3:
        // pilihan untuk menghapus item
        cout << "\nHapus item ke -  " ; cin >> hapus;
        if(hapus-1>=inve.size())
        {
            cout << "Item yang dipilih Tidak ada " << endl;
        }
        else {
            hapus= hapus-1;
            inve.erase(inve.begin()+hapus);
        }
        break;
    default: // selain tidak ada di menu maka pilihan dianggap salah
        cout << "\nMaaf Pilihan Anda Salah" << endl;
        break;
    }
    cout << "\nApakah Anda ingin Melanjutkan (y/n) ? ";cin >> option;
    }while(option == 'y');


    return 0;
}
