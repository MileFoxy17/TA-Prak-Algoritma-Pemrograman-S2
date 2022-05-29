//Header Untuk Fungsi Dasar Input Output
#include <iostream>

//Mengaktifkan Fungsi Seperti Numeric Limit
#include <limits>

//Header Untuk Dapat Membuat File Eksternal
#include <fstream>

using namespace std;

//Variabel String Dengan Array
string IsiPesan[100], hidang[100], porsi[100], no[100];
const int maks = 100;
int jumlah = 0, pil;

bool kosong()
{
    return jumlah == 0;
}

bool penuh()
{
    return jumlah >= maks;
}

int Sisa()
{
    return maks - jumlah;
}

int Count()
{
    return jumlah;
}

int BesarMaks()
{
    return maks;
}

//Fungsi VOID untuk memanggil menu pesan
void Pesan()
{

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (penuh())
    {
        cout << "\n\t\t\t\t+====================+"
             << "\n\t\t\t\t|Pesanan Sudah Penuh!|"
             << "\n\t\t\t\t+====================+" << endl;
        return;
    }

    cout << endl;

    cout << "\n\t\t\t\t\t\t+===================+"
         << "\n\t\t\t\t\t\t|   Menu Hidangan   |"
         << "\n\t\t\t\t\t\t+===================+"
         << "\n\t\t\t\t\t\t|1. La Vue syeam    |"
         << "\n\t\t\t\t\t\t|2. Crispy Lasagna  |" 
         << "\n\t\t\t\t\t\t|3. Orq Temp'h      |" 
         << "\n\t\t\t\t\t\t|4. Sweet Corn      |" 
         << "\n\t\t\t\t\t\t|5. A Char A Seum   |" 
         << "\n\t\t\t\t\t\t|6. Lemonade Ghetti |" 
         << "\n\t\t\t\t\t\t|7. Crab Soup       |" 
         << "\n\t\t\t\t\t\t|8. Zheng Kwaol     |"   
         << "\n\t\t\t\t\t\t|9. Thun Der Vouce  |" 
         << "\n\t\t\t\t\t\t|10. Chocolate pour |" 
         << "\n\t\t\t\t\t\t|11. Americano      |" 
         << "\n\t\t\t\t\t\t|12. Kwah De soup   |" 
         << "\n\t\t\t\t\t\t|13. Lemon Juice    |" 
         << "\n\t\t\t\t\t\t+===================+" << endl << endl;

    for (int a = 1; a < 2; a++)
    {   
        cout << "\n\t\t\t\t\t+====================================+"
             << "\n\t\t\t\t\t|        Contoh Cara Memesan         |"
             << "\n\t\t\t\t\t|   (Menu) (Porsi), (Menu) (Porsi)   |"
             << "\n\t\t\t\t\t|     Zheng Kwaol 2, Americano 2     |"
             << "\n\t\t\t\t\t+====================================+" << endl;

        cout << "\n\t\t\t\t\tMasukan Pesanan : ";
        getline(cin, hidang[a]);
        system ("cls");
        cout << endl;
    }

    for (int c = 1; c < 2; c++)
    {
        jumlah += 1;
        IsiPesan[jumlah] = hidang[c];
        cout << "\n+======================+"
             << "\n|Pesanan Sudah Diterima|[" << hidang[c] << "]"
             << "\n+======================+" << endl;
    }
}

void Selesai()
{
    if (kosong())
    {
        cout << "\n\t\t\t\t\t\t  +=================+"
             << "\n\t\t\t\t\t\t  |Belum Ada Pesanan|"
             << "\n\t\t\t\t\t\t  +=================+" << endl;
        return;
    }

    cout << endl;
    cout << "\n\t[Pesanan " << IsiPesan[1] << " Selesai]" << endl;

    for (auto i = 1; i <= jumlah; i++)
    {
        IsiPesan[i] = IsiPesan[i + 1];
    }

    jumlah -= 1;
}

void Hapus()
{
    jumlah = 0;
    cout << "\n\t\t\t\t\t     +============================+"
         << "\n\t\t\t\t\t     |Antrian pesanan sudah kosong|"
         << "\n\t\t\t\t\t     +============================+" << endl;
}

void Cetak()
{
    if (kosong())
    {
        cout << "\n\t\t\t\t\t\t  +=================+"
             << "\n\t\t\t\t\t\t  |Belum Ada Pesanan|"
             << "\n\t\t\t\t\t\t  +=================+" << endl;
        return;
    }

    for (auto i = jumlah; i > 0; i--)
    {
        cout << "\n\t +===============+" << endl;
        cout << "\t |Pesanan No [" << i << "] |" << " [" << IsiPesan[i] << "]";
        cout << "\n\t +===============+";
        cout << "\n\t |   Diproses    |";
        cout << "\n\t +===============+";
    }
}

void CetakStruk()
{
    if (kosong())
    {
        cout << "\n\t\t\t\t\t\t  +=================+"
             << "\n\t\t\t\t\t\t  |Belum Ada Pesanan|"
             << "\n\t\t\t\t\t\t  +=================+" << endl;
        return;
    }

    //Membuat file external
    ofstream file_out; 
    file_out.open ("Pesanan.txt"); 

    if(!file_out) 
    { 
     std::cout <<"'OUTPUT FILE' TIDAK BISA DIBUKA, ERROR, PROGRAM DIHENTIKAN"; 
     exit (-1); 
    } 
    else 
    
    //Menulis output pada file external
    for (auto i = jumlah; i > 0; i--)
    {
        file_out << "+======================+" << endl;
        file_out << "Pesanan No [" << i << "]" << endl;
        file_out << "[" << IsiPesan[i] << "]" << endl;
        file_out << endl;
    }

}

int main()
{
    auto menu = 0;
    auto isLoop = true;

    //Melakukan Perulangan untuk memunculkan menu utama secara terus menerus
    while (isLoop)
    {
        cout << "\n\t\t\t\t\t+=====================================+"
             << "\n\t\t\t\t\t|        Menu Sistem Pemesanan        |"
             << "\n\t\t\t\t\t+=====================================+"
             << "\n\t\t\t\t\t|   1. Cek Jumlah Pesanan             |"
             << "\n\t\t\t\t\t|   2. Masukkan Pesanan               |"
             << "\n\t\t\t\t\t|   3. Selesaikan Pesanan             |"
             << "\n\t\t\t\t\t|   4. Lihat Daftar Pesanan           |"
             << "\n\t\t\t\t\t|   5. Cetak Daftar pesanan           |"
             << "\n\t\t\t\t\t|   6. Hapus Seluruh Daftar Pesanan   |"
             << "\n\t\t\t\t\t|   7. Keluar                         |"
             << "\n\t\t\t\t\t+=====================================+" << endl;
        cout << "\n\t\t\t\t\tMasukan pilihan: ";
        cin >> menu;

        //System cls untuk menghapus menu yang sudah tidak relevan di command prompt
        system ("cls");

        //Switch case untuk memilih menu
        switch (menu)
        {
            case 1:
            if (kosong())
            {
                cout << endl;
                cout << "\n\t\t\t\t     +===========================================+"
                     << "\n\t\t\t\t     |             Tidak ada pesanan             |"
                     << "\n\t\t\t\t     |\t    Masih bisa menerima " << Sisa() << " pesanan      |"
                     << "\n\t\t\t\t     +===========================================+" << endl;
                break;
            }
            else if (penuh())
            {
                cout << "\n\t\t\t\t+====================+"
                     << "\n\t\t\t\t|Pesanan Sudah Penuh!|"
                     << "\n\t\t\t\t+====================+" << endl;
                break;
            }
            else
            {
                cout << endl;
                cout << "\t[Terisi " << Count() << " Pesanan]" << endl;
                cout << "\t[Masih bisa menerima " << Sisa() << " pesanan]" << endl;
                cout << endl;
                break;
            }

            case 2:
            Pesan();
            cout << endl;
            break;

            case 3:
            Selesai();
            cout << endl;
            break;

            case 4:
            Cetak();
            cout << endl;
            break;

            case 5:
            CetakStruk();
            cout << endl;
            break;

            case 6:
            Hapus();
            cout << endl;
            break;

            case 7:
            cout << "\n\t\t\t\t\t    +==========================+"
                 << "\n\t\t\t\t\t    |Terimakasih, Sampai Jumpa!|"
                 << "\n\t\t\t\t\t    +==========================+" << endl << endl;
            isLoop = false;
            break;

            default:
            cout << "\n\t\t\t\t\t\t  +==================+"
                 << "\n\t\t\t\t\t\t  |Tidak Ada Pilihan!|"
                 << "\n\t\t\t\t\t\t  +==================+" << endl;
            break;
        }
    }
}