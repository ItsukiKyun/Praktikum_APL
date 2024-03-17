#include <iostream>
#include <string>

using namespace std;

struct Pemain {
    string nama;
    string posisi;
    int NoPunggung;
};

const int MAX_PEMAIN = 100;

void TambahPemain(Pemain DataPemain[], int& jumlahPemain) {
Pemain PemainBaru;
    cout << "Masukkan nama pemain: ";
    getline(cin, PemainBaru.nama);
    cout << "Masukkan posisi pemain (pivot, kiper, anchor, flank): ";
    getline(cin, PemainBaru.posisi);
    cout << "Masukkan nomor pemain: ";
    cin >> PemainBaru.NoPunggung;
    cin.ignore();

    for (int i = 0; i < jumlahPemain; ++i) {
        if (DataPemain[i].NoPunggung == PemainBaru.NoPunggung) {
            cout << "Nomor punggung tidak valid." << endl;
            return;
        }
    }

    if (PemainBaru.posisi != "pivot" && PemainBaru.posisi != "kiper" && PemainBaru.posisi != "anchor" && PemainBaru.posisi != "flank") {
        cout << "Posisi pemain tidak valid." << endl;
        return;
    }

    DataPemain[jumlahPemain++] = PemainBaru;
    cout << "Pemain berhasil ditambahkan." << endl;
}

void LihatPemain(const Pemain DataPemain[], int jumlahPemain) {
cout << "Daftar Pemain Futsal: " << endl;
    for (int i = 0; i < jumlahPemain; ++i) {
        cout << "Nama: " << DataPemain[i].nama << ", Posisi: " << DataPemain[i].posisi << ", Nomor Punggung: " << DataPemain[i].NoPunggung << endl;
    }
}

void UpdatePemain(Pemain DataPemain[], int jumlahPemain) {
   string namaPemain;
    cout << "Masukkan nama pemain yang ingin diupdate: ";
    getline(cin, namaPemain);

    bool pemainDitemukan = false;
    for (int i = 0; i < jumlahPemain; ++i) {
        if (DataPemain[i].nama == namaPemain) {
            int nomorPunggungBaru;
            cout << "Masukkan nomor punggung baru: ";
            cin >> nomorPunggungBaru;
            cin.ignore();

            for (int j = 0; j < jumlahPemain; ++j) {
                if (DataPemain[j].NoPunggung == nomorPunggungBaru && i != j) {
                    cout << "Nomor punggung sudah digunakan oleh pemain lain. Silakan coba lagi." << endl;
                    return;
                }
            }

            DataPemain[i].NoPunggung = nomorPunggungBaru;   

            cout << "Masukkan posisi pemain baru (pivot, kiper, anchor, flank): ";
            getline(cin, DataPemain[i].posisi);

            if (DataPemain[i].posisi != "pivot" && DataPemain[i].posisi != "kiper" && DataPemain[i].posisi != "anchor" && DataPemain[i].posisi != "flank") {
                cout << "Posisi pemain tidak valid." << endl;
                return;
            }

            cout << "Data pemain berhasil diupdate." << endl;
            pemainDitemukan = true;
            break;
        }
    }

    if (!pemainDitemukan) {
        cout << "Pemain dengan nama " << namaPemain << " tidak ditemukan." << endl;
    }
}

void HapusPemain(Pemain DataPemain[], int& jumlahPemain, string namaPemain, int index = 0) {
    if (index >= jumlahPemain) {
        cout << "Pemain dengan nama " << namaPemain << " tidak ditemukan." << endl;
        return;
    }

    if (DataPemain[index].nama == namaPemain) {
        for (int i = index; i < jumlahPemain - 1; ++i) {
            DataPemain[i] = DataPemain[i + 1];
        }
        jumlahPemain--;
        cout << "Pemain " << namaPemain << " berhasil dihapus." << endl;
    } else {
        HapusPemain(DataPemain, jumlahPemain, namaPemain, index + 1);
    }
}

int main() {
    string username, password;
    int percobaan = 0;
    Pemain DataPemain[MAX_PEMAIN];
    int jumlahPemain = 0;

    while (percobaan < 3) {
        cout << "Masukkan username anda: ";
        getline(cin, username);
        cout << "Masukkan password anda: ";
        getline(cin, password);

        if (username == "ahmad zuhair nur aiman" && password == "2309106025") {
            cout << "Anda berhasil login" << endl;
            break;
        } else {
            cout << "username atau password anda salah, silahkan coba lagi" << endl;
            percobaan++;
        }
    }

    if (percobaan == 3) {
        cout << "Terlalu banyak mencoba, program dihentikan" << endl;
        return 0;
    }

    int choice;
    while (true) {
        cout << "\nMenu CRUD Pemain:" << endl;
        cout << "1. Tambah Pemain " << endl;
        cout << "2. Tampilkan Pemain " << endl;
        cout << "3. Update Pemain " << endl;
        cout << "4. Hapus Pemain " << endl;
        cout << "5. Hentikan Program " << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            TambahPemain(DataPemain, jumlahPemain);
        } else if (choice == 2) {
            LihatPemain(DataPemain, jumlahPemain);
        } else if (choice == 3) {
            UpdatePemain(DataPemain, jumlahPemain);
        } else if (choice == 4) {
            string namaPemain;
            cout << "Masukkan nama pemain yang ingin dihapus: ";
            getline(cin, namaPemain);
            HapusPemain(DataPemain, jumlahPemain, namaPemain);
        } else if (choice == 5) {
            cout << " Program selesai. Gacorr Ngabb " << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');  
        }
    }
    return 0;
}
