#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

const int MAX_PEMAIN = 100;

struct Tim {
    struct Pemain {
        string nama;
        string posisi;
        int NoPunggung;
    };

    Pemain DataPemain[MAX_PEMAIN];
    int jumlahPemain;

    void TambahPemain() {
        if (jumlahPemain >= MAX_PEMAIN) {
            cout << "Jumlah pemain sudah mencapai batas maksimum." << endl;
            return;
        }
        Pemain PemainBaru;
        cout << "Masukkan nama pemain: ";
        getline(cin, PemainBaru.nama);

        if (PemainBaru.nama.empty()) {
            cout << "Nama pemain tidak boleh kosong." << endl;
            return;
        }

        for (int i = 0; i < jumlahPemain; ++i) {
            if (DataPemain[i].nama == PemainBaru.nama) {
                cout << "Nama pemain sudah digunakan. Silakan masukkan nama pemain lain." << endl;
                return;
            }
        }

        cout << "Masukkan posisi pemain (pivot, kiper, anchor, flank): ";
        getline(cin, PemainBaru.posisi);

        if (PemainBaru.posisi != "pivot" && PemainBaru.posisi != "kiper" && PemainBaru.posisi != "anchor" && PemainBaru.posisi != "flank") {
            cout << "Posisi pemain tidak valid." << endl;
            return;
        }

        string NomorPunggung;
        cout << "Masukkan nomor pemain: ";
        getline(cin, NomorPunggung);

        stringstream ss(NomorPunggung);
        int nomorPunggung;
        if (!(ss >> nomorPunggung) || nomorPunggung <= 0) {
            cout << "Nomor punggung tidak valid." << endl;
            return;
        }
        PemainBaru.NoPunggung = nomorPunggung;

        for (int i = 0; i < jumlahPemain; ++i) {
            if (DataPemain[i].NoPunggung == PemainBaru.NoPunggung) {
                cout << "Nomor punggung tidak valid." << endl;
                return;
            }
        }

        DataPemain[jumlahPemain++] = PemainBaru;
        cout << "Pemain berhasil ditambahkan." << endl;
    }

    void LihatPemain() {
        if (jumlahPemain == 0) {
        cout << "Tidak ada data pemain." << endl;
        return;
    }
        cout << "Daftar Pemain Futsal: " << endl;
        cout << endl;
        for (int i = 0; i < jumlahPemain; ++i) {
            cout << "Nama Pemain: " << DataPemain[i].nama << endl;
            cout << "Posisi Pemain: " << DataPemain[i].posisi << endl;
            cout << "Nomor Punggung Pemain: " << DataPemain[i].NoPunggung << endl;
            cout << endl;
        }
    }

    void UpdatePemain() {
        string namaPemain;
        cout << "Masukkan nama pemain yang ingin diupdate: ";
        getline(cin, namaPemain);

        bool pemainDitemukan = false;
        for (int i = 0; i < jumlahPemain; ++i) {
            if (DataPemain[i].nama == namaPemain) {
                string NomorPunggung;
                cout << "Masukkan nomor punggung baru: ";
                getline(cin, NomorPunggung);

                stringstream ss(NomorPunggung);
                int nomorPunggung;
                if (!(ss >> nomorPunggung) || nomorPunggung <= 0) {
                    cout << "Nomor punggung tidak valid. Silahkan masukkan angka ." << endl;
                    return;
                }

                for (int j = 0; j < jumlahPemain; ++j) {
                    if (DataPemain[j].NoPunggung == nomorPunggung && i != j) {
                        cout << "Nomor punggung sudah digunakan oleh pemain lain. Silakan coba lagi." << endl;
                        return;
                    }
                }

                DataPemain[i].NoPunggung = nomorPunggung;

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

    void HapusPemain(Pemain* pemain) { 
        bool pemainDitemukan = false;
        for (int i = 0; i < jumlahPemain; ++i) {
            if (&DataPemain[i] == pemain) {
                pemainDitemukan = true;
                for (int j = i; j < jumlahPemain - 1; ++j) {
                    DataPemain[j] = DataPemain[j + 1];
                }
                jumlahPemain--;
                cout << "Pemain " << (*pemain).nama << " berhasil dihapus." << endl; // mengakses nama pemain dengan menggunakan operator dereference
                break;
            }
        }

        if (!pemainDitemukan) {
            cout << "Pemain tidak ditemukan." << endl;
        }
    }

    int Part(Pemain* arr, int low, int high) {
        string pivot = arr[high].nama;
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j].nama<= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void QuickSort(Pemain* arr, int low, int high) {
        if (low < high) {
            int A = Part(arr, low, high);
            QuickSort(arr, low, A - 1);
            QuickSort(arr, A + 1, high);
        }
    }

    void SortNamaAscending() {
        QuickSort(DataPemain, 0, jumlahPemain - 1);
    }

    void BubbleSort(Pemain* arr, int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j].NoPunggung > arr[j + 1].NoPunggung) {
                    Pemain temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void SortNoPunggungAscending() {
        BubbleSort(DataPemain, jumlahPemain);
         cout << "Pemain diurutkan berdasarkan nomor punggung secara ascending." << endl;
    }

    void MergeSort(Pemain* arr, int kiri, int tengah, int kanan) {
        int a = tengah - kiri + 1;
        int b = kanan - tengah;

        Pemain L[a], R[b];

        for (int i = 0; i < a; i++)
            L[i] = arr[kiri + i];
        for (int j = 0; j < b; j++)
            R[j] = arr[tengah + 1 + j];

        int i = 0, j = 0, k = kiri;
        while (i < a && j < b) {
            if (L[i].NoPunggung >= R[j].NoPunggung) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < a) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < b) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void SortNoPunggungDescending2(Pemain* arr, int kiri, int kanan) {
        if (kiri < kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            SortNoPunggungDescending2(arr, kiri, tengah);
            SortNoPunggungDescending2(arr, tengah + 1, kanan);
            MergeSort(arr, kiri, tengah, kanan);
            cout << "Pemain diurutkan berdasarkan nomor punggung secara descending." << endl;
        }
    }

    void SortNoPunggungDescending(Pemain* arr, int kiri, int kanan) {
        if (kiri < kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            SortNoPunggungDescending(arr, kiri, tengah);
            SortNoPunggungDescending(arr, tengah + 1, kanan);
            MergeSort(arr, kiri, tengah, kanan);
        }
    }

    int BinarySearch(Tim::Pemain* arr, int kiri, int kanan, string namaDicari) {
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        // Jika nama pemain pada posisi tengah adalah yang dicari, kembalikan indeksnya
        if (arr[tengah]. nama== namaDicari)
            return tengah;
        // Jika nama pemain pada posisi tengah lebih kecil dari yang dicari, cari di sebelah kanan
        if (arr[tengah].nama.compare(namaDicari) < 0 )
            kiri = tengah + 1;
        // Jika nama pemain pada posisi tengah lebih besar dari yang dicari, cari di sebelah kiri
        else
            kanan = tengah - 1;
        }
        return -1;
    }

    int InterpolationSearch(Tim::Pemain* arr, int noPunggung, int n) {
    int low = 0, high = n - 1;
    while (low <= high && noPunggung <= arr[low].NoPunggung && noPunggung >= arr[high].NoPunggung) {
        if (low == high) {
            if (arr[low].NoPunggung == noPunggung)
                return low;
            return -1;
        }
        int pos = low + static_cast<double>(high - low) / (arr[low].NoPunggung - arr[high].NoPunggung) * (noPunggung - arr[high].NoPunggung);
        if (pos < low || pos > high) {
            return -1;
        }
        if (arr[pos].NoPunggung == noPunggung)
            return pos;

        if (arr[pos].NoPunggung < noPunggung)
            high = pos - 1;
        else
            low = pos + 1;
        }
        return -1;
    }

};

int main() {
    string username, password;
    int percobaan = 0;
    Tim tim;
    tim.jumlahPemain = 0;

    while (percobaan < 3) {
        cout << "Masukkan username anda: ";
        getline(cin, username);
        cout << "Masukkan password anda: ";
        getline(cin, password);

        if (username == "Aiman" && password == "2309106025") {
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
    
    int pilihan;
    while (true) {
        cout << "\nMenu CRUD Pemain:" << endl;
        cout << "1. Tambah Data Pemain " << endl;
        cout << "2. Tampilkan Data Pemain " << endl;
        cout << "3. Update Data Pemain " << endl;
        cout << "4. Hapus Data Pemain " << endl;
        cout << "5. Sorting Data Pemain " << endl;
        cout << "6. Cari Pemain " << endl;
        cout << "7. Hentikan Program " << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tim.TambahPemain();
        } else if (pilihan == 2) {
            tim.LihatPemain();
        } else if (pilihan == 3) {
            tim.UpdatePemain();
        } else if (pilihan == 4) {
            string namaPemain;
            cout << "Masukkan nama pemain yang ingin dihapus: ";
            getline(cin, namaPemain);
            for (int i = 0; i < tim.jumlahPemain; ++i) {
                if (tim.DataPemain[i].nama == namaPemain) { 
                    tim.HapusPemain(&tim.DataPemain[i]);
                    break;
                }
            }
        } else if (pilihan == 5) {
                tim.SortNoPunggungAscending(); // Memanggil fungsi sorting no punggung secara ascending menggunakan bubble sort
                tim.LihatPemain(); // Menampilkan daftar pemain setelah diurutkan
        } else if (pilihan == 6) {
        cout << "Pilihan pencarian: " << endl;
        // jika ingin searching pemain dengan nama maka harus melakukan tampilkan data terlebih dahulu
        cout << "1. Berdasarkan Nama Pemain" << endl; // mencari data pemain dengan nama pemain tersebut dengan binary search
        // jika ingin searching pemain dengan no punggung maka harus melakukan sorting pemain secara descending terlebih dahulu
        cout << "2. Berdasarkan No Punggung Pemain" << endl; // mencari data pemain yg memiliki no punggung tersebut dengan interpolation search
        cout << "Masukkan pilihan: ";
        int pilihanPencarian;
        cin >> pilihanPencarian;
        cin.ignore();
        if (pilihanPencarian == 1) {
           string namaDicari;
                tim.SortNamaAscending(); // Memastikan data sudah disorting berdasarkan nama secara ascending menggunakan quick sort
                cout << "Masukkan nama pemain yang ingin dicari: ";
                getline(cin, namaDicari);
                int indeks = tim.BinarySearch(tim.DataPemain, 0, tim.jumlahPemain - 1, namaDicari);
                if (indeks != -1) {
                    cout << "Pemain ditemukan:" << endl;
                    cout << endl;
                    cout << "Nama Pemain: " << tim.DataPemain[indeks].nama << endl;
                    cout << "Posisi Pemain: " << tim.DataPemain[indeks].posisi << endl;
                    cout << "Nomor Punggung Pemain: " << tim.DataPemain[indeks].NoPunggung << endl;
                } else {
                    cout << "Pemain dengan nama " << namaDicari << " tidak ditemukan." << endl;
                    // Menampilkan data pemain yang sudah disorting berdasarkan nama secara ascending
                    cout << "Daftar Nama Pemain:" << endl;
                    for (int i = 0; i < tim.jumlahPemain; ++i) {
                        cout << "Nama Pemain: " << tim.DataPemain[i].nama << endl;
                        cout << "Posisi Pemain: " << tim.DataPemain[i].posisi << endl;
                        cout << "Nomor Punggung Pemain: " << tim.DataPemain[i].NoPunggung << endl;
                        cout << endl;
                    }
                }
            } else if (pilihanPencarian == 2) {
                int noPunggungDicari;
                tim.SortNoPunggungDescending(tim.DataPemain, 0, tim.jumlahPemain - 1); // Memastikan data sudah disorting berdasarkan nomor punggung secara descending menggunakan merge sort
                cout << "Masukkan nomor punggung pemain yang ingin dicari: ";
                cin >> noPunggungDicari;
                int indeks = tim.InterpolationSearch(tim.DataPemain, noPunggungDicari, tim.jumlahPemain);
                if (indeks != -1) {
                    cout << "Pemain ditemukan:" << endl;
                    cout << endl;
                    cout << "Nama Pemain: " << tim.DataPemain[indeks].nama << endl;
                    cout << "Posisi Pemain: " << tim.DataPemain[indeks].posisi << endl;
                    cout << "Nomor Punggung Pemain: " << tim.DataPemain[indeks].NoPunggung << endl;
                } else {
                    cout << "Pemain dengan nomor punggung " << noPunggungDicari << " tidak ditemukan." << endl;
                }
            }
        } else if (pilihan == 7) {
                    cout << "Program selesai " << endl;
                    break;
                } else {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            }
    }
    return 0;
};