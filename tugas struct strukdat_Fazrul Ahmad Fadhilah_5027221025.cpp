#include <iostream>
#include <string>

// Struktur data untuk menyimpan informasi
struct Data {
    int id;
    std::string nama;
    int usia;
};

int main() {
    const int MAX_DATA = 10;
    Data arrayData[MAX_DATA];
    int jumlahData = 0;
    bool dataDitemukan = false;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tampilkan Data\n";
        std::cout << "2. Tambah Data Baru\n";
        std::cout << "3. Hapus Data\n";
        std::cout << "4. Ubah Data\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilih menu (1-5): ";

        int pilihan;
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "\nData:\n";
                for (int i = 0; i < jumlahData; ++i) {
                    std::cout << "ID: " << arrayData[i].id << "\n";
                    std::cout << "Nama: " << arrayData[i].nama << "\n";
                    std::cout << "Usia: " << arrayData[i].usia << "\n";
                    std::cout << "-------------------\n";
                }
                break;
            
            case 2:
                if (jumlahData < MAX_DATA) {
                    Data newData;
                    std::cout << "\nMasukkan ID: ";
                    std::cin >> newData.id;
                    std::cout << "Masukkan Nama: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, newData.nama);
                    std::cout << "Masukkan Usia: ";
                    std::cin >> newData.usia;

                    arrayData[jumlahData++] = newData;
                    std::cout << "Data berhasil ditambahkan.\n";
                } else {
                    std::cout << "Batas maksimum data telah tercapai.\n";
                }
                break;
            
            case 3:
                int idHapus;
                std::cout << "\nMasukkan ID data yang ingin dihapus: ";
                std::cin >> idHapus;;
                for (int i = 0; i < jumlahData; ++i) {
                    if (arrayData[i].id == idHapus) {
                        for (int j = i; j < jumlahData - 1; ++j) {
                            arrayData[j] = arrayData[j + 1];
                        }
                        jumlahData--;
                        dataDitemukan = true;
                        std::cout << "Data berhasil dihapus.\n";
                        break;
                    }
                }
                if (!dataDitemukan) {
                    std::cout << "Data dengan ID tersebut tidak ditemukan.\n";
                }
                break;
            
            case 4:
                int idUbah;
                std::cout << "\nMasukkan ID data yang ingin diubah: ";
                std::cin >> idUbah;
                dataDitemukan = false;
                for (int i = 0; i < jumlahData; ++i) {
                    if (arrayData[i].id == idUbah) {
                        std::cout << "Masukkan data yang baru:\n";
                        std::cout << "Nama: ";
                        std::cin.ignore();
                        std::getline(std::cin, arrayData[i].nama);
                        std::cout << "Usia: ";
                        std::cin >> arrayData[i].usia;
                        dataDitemukan = true;
                        std::cout << "Data berhasil diubah.\n";
                        break;
                    }
                }
                if (!dataDitemukan) {
                    std::cout << "Data dengan ID tersebut tidak ditemukan.\n";
                }
                break;
            
            case 5:
                std::cout << "Program selesai.\n";
                return 0;
            
            default:
                std::cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
        }
    }

    return 0;
}
