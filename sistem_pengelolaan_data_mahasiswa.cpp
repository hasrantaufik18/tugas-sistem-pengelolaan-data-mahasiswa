#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    float ipk;
};

vector<Mahasiswa> dataMahasiswa;

void tambahMahasiswa() {
    Mahasiswa m;
    cout << "Masukkan NIM     : ";
    getline(cin, m.nim);
    cout << "Masukkan Nama    : ";
    getline(cin, m.nama);
    cout << "Masukkan Jurusan : ";
    getline(cin, m.jurusan);
    cout << "Masukkan IPK     : ";
    cin >> m.ipk;
    cin.ignore();

    dataMahasiswa.push_back(m);
    cout << "Data mahasiswa berhasil ditambahkan.\n";
}

void tampilkanSemuaMahasiswa() {
    if (dataMahasiswa.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }

    cout << "\nDaftar Mahasiswa:\n";
    cout << left << setw(15) << "NIM" << setw(20) << "Nama" 
         << setw(20) << "Jurusan" << setw(5) << "IPK" << "\n";
    cout << "-------------------------------------------------------------\n";

    for (size_t i = 0; i < dataMahasiswa.size(); ++i) {
        Mahasiswa m = dataMahasiswa[i];
        cout << left << setw(15) << m.nim 
             << setw(20) << m.nama 
             << setw(20) << m.jurusan 
             << setw(5) << m.ipk << "\n";
    }
}

void cariMahasiswa() {
    int pilihan;
    cout << "Cari berdasarkan (1. NIM / 2. Nama): ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        string nim;
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        bool ditemukan = false;
        for (size_t i = 0; i < dataMahasiswa.size(); ++i) {
            if (dataMahasiswa[i].nim == nim) {
                cout << "Ditemukan:\n";
                cout << "NIM     : " << dataMahasiswa[i].nim << "\n";
                cout << "Nama    : " << dataMahasiswa[i].nama << "\n";
                cout << "Jurusan : " << dataMahasiswa[i].jurusan << "\n";
                cout << "IPK     : " << dataMahasiswa[i].ipk << "\n";
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan)
            cout << "Data tidak ditemukan.\n";
    } else if (pilihan == 2) {
        string nama;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        bool ditemukan = false;
        for (size_t i = 0; i < dataMahasiswa.size(); ++i) {
            if (dataMahasiswa[i].nama == nama) {
                cout << "Ditemukan:\n";
                cout << "NIM     : " << dataMahasiswa[i].nim << "\n";
                cout << "Nama    : " << dataMahasiswa[i].nama << "\n";
                cout << "Jurusan : " << dataMahasiswa[i].jurusan << "\n";
                cout << "IPK     : " << dataMahasiswa[i].ipk << "\n";
                ditemukan = true;
            }
        }
        if (!ditemukan)
            cout << "Data tidak ditemukan.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

void hapusMahasiswa() {
    string nim;
    cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, nim);
    bool ditemukan = false;

    for (size_t i = 0; i < dataMahasiswa.size(); ++i) {
        if (dataMahasiswa[i].nim == nim) {
            dataMahasiswa.erase(dataMahasiswa.begin() + i);
            cout << "Data mahasiswa berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "Data mahasiswa tidak ditemukan.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Sistem Pengelolaan Data Mahasiswa ===\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Cari Data Mahasiswa\n";
        cout << "3. Hapus Data Mahasiswa\n";
        cout << "4. Tampilkan Semua Data Mahasiswa\n";
        cout << "5. Exit\n";
        cout << "Pilih menu (1-5): ";

        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak sesuai. Silakan masukkan angka 1-5.\n";
            continue;
        }

        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                cariMahasiswa();
                break;
            case 3:
                hapusMahasiswa();
                break;
            case 4:
                tampilkanSemuaMahasiswa();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Input tidak sesuai. Silakan pilih menu 1-5.\n";
        }
    } while (pilihan != 5);

    return 0;
}

