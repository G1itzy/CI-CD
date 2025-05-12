#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define ppn 0.10 // PPN = 10%
const int diskon = 20000;

int main() {
    char nama[50], menu[20], back;
    int jumlah, makanan, makan, total, bayar, kurang, bonus, pajak, kembalian,
        harga[5] = {13000, 10000, 15000, 4000, 25000}, i = 0;
    bool saldo;
    
    do {
        system("CLS");
        cout << "===========================KPC============================" << endl;
        cout << "=======================DEPE CHICKEN=======================" << endl;

        cout << endl;
        cout << "Masukkan Nama Anda : ";
        cin.getline(nama, 50);
        cin.getline(nama, 50); // Dibuat dua kali untuk membersihkan buffer
        cout << "Pilihan menu yang tersedia --- " << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "|   [1] Chicken Muffin                                                  |" << endl;
        cout << "|       [A]Paket Hemat              = Rp 13.000                         |" << endl;
        cout << "|       [B]Paket Combo              = Rp 19.000                         |" << endl;
        cout << "|       [C]A La Carte                = Rp 22.000                         |" << endl;                                        
        cout << "|   [2] Chesse Burger                                                  |" << endl;
        cout << "|       [A]Paket Hemat              = Rp 10.000                         |" << endl;
        cout << "|       [B]A La Carte                = Rp 14.000                         |" << endl;                
        cout << "|   [3] Chicken Burger              = Rp 15.000                         |" << endl;
        cout << "|   [4] Hotcakes                                                      |" << endl;
        cout << "|       [A]Paket Hemat              = Rp 4.000                          |" << endl;
        cout << "|       [B]A La Carte                = Rp 8.000                          |" << endl;                
        cout << "|   [5] Paket Special               = Rp 25.000                         |" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        
        cout << "   (Masukkan Menu Makanan Berdasarkan Nomor) " << endl;
        cout << "   Silahkan Pilih Makanan Anda : ";
        cin >> makanan;
        
        switch(makanan) {
            case 1:
                strcpy(menu, "Chicken Muffin");
                i = 0;
                break;                    
            case 2:
                strcpy(menu, "Chesse Burger");
                i = 1;
                break;
            case 3:
                strcpy(menu, "Chicken Burger");
                i = 2;
                break;
            case 4:
                strcpy(menu, "Hotcakes");
                i = 3;
                break;
            case 5:
                strcpy(menu, "Paket Special");
                i = 4;
                break;
            default:
                cout << "Pilihan Menu Yang Anda Pilih Tidak Tersedia..." << endl;
                goto ulang;
        }
        
        cout << " Anda Memilih Paket " << menu << endl;
        cout << endl;
        cout << "Jumlah Makanan yang dibeli : ";
        cin >> jumlah;
        
        makan = jumlah * harga[i];
        pajak = makan * ppn;
        total = pajak + makan;
        cout << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << " |                                          DEPE CHICKEN                               |" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "\tPemesan atas nama       : " << nama << endl;
        cout << "\tMenu Makanan             : " << menu << endl;
        cout << "\tJumlah Makanan           : " << jumlah << " porsi" << endl;
        cout << "\tHarga Makanan            : " << harga[i] << " * " << jumlah << endl;
        cout << "\tPajak Restaurant         : " << pajak << endl;
        cout << "\tTotal Pembayaran         : Rp " << total << endl;
        
        if(jumlah >= 4) {
            bonus = total - diskon;
            total = bonus;
            cout << endl;
            cout << " # Anda mendapatkan diskon potongan Harga : Rp " << diskon << " #" << endl;
            cout << "Total Pembayaran Anda Setelah Diskon : Rp " << total << endl;
        }
        
        cout << "--------------------------------------------------" << endl;
        cout << "Silahkan Bayar : Rp. ";
        cin >> bayar;
        cout << endl;
        
        while (bayar < total) {
            cout << "Saldo Anda kurang, Silahkan bayar lagi : Rp. ";
            cin >> kurang;
            bayar += kurang;
        }
        
        kembalian = bayar - total;
        cout << "Uang yang anda bayar \t\t\t Rp. " << bayar << endl;
        cout << "Uang kembalian\t\t\t\t Rp. " << kembalian << endl;
        cout << "-----------------------------------------------------" << endl;
        
        ulang:
            cout << " [Y = ya / T = tidak]" << endl;
            cout << " Apakah anda ingin memesan lagi ? [Y/T] = ";
            cin >> back;
            cin.ignore(); // Membersihkan newline character dari buffer
    } while (back == 'Y' || back == 'y');
    
    cout << endl;
    cout << " Terima kasih telah memesan makanan di Depe Chicken" << endl;
    cout << "Selamat menikmati" << endl;
    
    return 0;
}