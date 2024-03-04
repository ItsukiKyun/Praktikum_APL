#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void login()
{
    string username, password;
    int percobaan = 0;

    while (percobaan < 3)
    {
        cout << "Masukkan username anda: ";
        getline(cin, username);
        cout << "Masukkan password anda: ";
        getline(cin, password);

        if (username == "ahmad zuhair nur aiman" && password == "2309106025")
        {
            cout << "Anda berhasil login" << endl;
            return;
        }
        else
        {
            cout << "Username atau password anda salah, silahkan coba lagi" << endl;
            percobaan++;
        }
    }

    if (percobaan == 3)
    {
        cout << "Terlalu banyak mencoba, program dihentikan" << endl;
        exit(0);
    }
}

int main()
{
    login();

    while (true)
    {
        cout << "\nMenu Konversi Mata Uang:" << endl;
        cout << "1. Rupiah ke Dollar, Euro, Yen" << endl;
        cout << "2. Dollar ke Rupiah, Euro, Yen" << endl;
        cout << "3. Euro ke Rupiah, Dollar, Yen" << endl;
        cout << "4. Yen ke Rupiah, Dollar, Euro" << endl;
        cout << "5. Hentikan program" << endl;

        int pilihan;
        cout << "Masukkan pilihan anda (1-5): ";
        cin >> pilihan;

        if (pilihan == 5) {
            cout << "Program berhenti...";
            break;
        }

        double nilai_uang;
        if (pilihan == 1) {
            cout << "Masukkan jumlah uang dalam Rupiah: ";
            cin >> nilai_uang;
            cout << " Rupiah --> Dollar : " << fixed << setprecision(2) << nilai_uang * 0.000064 << endl;
            cout << " Rupiah --> Euro : " << fixed << setprecision(2) << nilai_uang * 0.000059 << endl;
            cout << " Rupiah --> Yen : " << fixed << setprecision(2) << nilai_uang * 0.0096 << endl;
        } else if (pilihan == 2) {
            cout << "Masukkan jumlah uang dalam Dollar: ";
            cin >> nilai_uang;
            cout << " Dollar --> Rupiah : " << fixed << setprecision(2) << nilai_uang * 15071.95 << endl;
            cout << " Dollar --> Euro : " << fixed << setprecision(2) << nilai_uang * 0.92 << endl;
            cout << " Dollar --> Yen : " << fixed << setprecision(2) << nilai_uang * 150.10 << endl;
        } else if (pilihan == 3) {
            cout << "Masukkan jumlah uang dalam Euro: ";
            cin >> nilai_uang;
            cout << " Euro --> Rupiah : " << fixed << setprecision(2) << nilai_uang * 17043.68 << endl;
            cout << " Euro --> Dollar : " << fixed << setprecision(2) << nilai_uang * 1.09 << endl;
            cout << " Euro --> Yen : " << fixed << setprecision(2) << nilai_uang * 162.93 << endl;
        } else if (pilihan == 4) {
            cout << "Masukkan jumlah uang dalam Yen: ";
            cin >> nilai_uang;
            cout << " Yen --> Rupiah : " << fixed << setprecision(2) << nilai_uang * 104.61 << endl;
            cout << " Yen --> Dollar : " << fixed << setprecision(2) << nilai_uang * 0.0067 << endl;
            cout << " Yen --> Euro : " << fixed << setprecision(2) << nilai_uang * 0.0061 << endl;
        } else {
            cout << "Pilihan tidak valid." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    return 0;
}