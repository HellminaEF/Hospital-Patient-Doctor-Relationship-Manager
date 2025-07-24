#include <iostream>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

ListDokter listDokter;  // List untuk dokter
ListPasien listPasien;  // List untuk pasien
ListRelasi listRelasi;  // List untuk relasi

void menu(){
    cout << "\n====Menu Rumah Sakit====\n";
    cout << "1. Masukan data Dokter\n";
    cout << "2. Masukan data Pasien\n";
    cout << "3. Tambah Relasi\n";
    cout << "4. Tampilkan semua Dokter\n";
    cout << "5. Tampilkan semua Pasien\n";
    cout << "6. Tampilkan semua Relasi\n";
    cout << "7. Tampilkan Pasien dari Dokter tertentu\n";
    cout << "8. Tampilkan Dokter dari Pasien tertentu\n";
    cout << "9. Hapus Dokter\n";
    cout << "10. Hapus Pasien\n";
    cout << "11. Hapus Relasi\n";
    cout << "12. Hitung Pasien dari Dokter Tertentu\n";
    cout << "13. Hitung Dokter dari Pasien Tertentu\n";
    cout << "14. Hitung Pasien tanpa Dokter\n";
    cout << "15. Hitung Dokter tanpa Pasien\n";
    cout << "16. Edit Relasi\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main(){

    int pilihan;
    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: { // Tambah Dokter
            int id;
            string nama, spesialis;
            cout<<"ID Dokter: ";
            cin>>id;
            cout<<"Nama Dokter: ";
            cin.ignore();
            getline(cin,nama);
            cout<<"Spesialis: ";
            getline(cin,spesialis);

            insertDokter(listDokter, id, nama, spesialis);
            break;
        }
        case 2: { // Tambah Pasien
            int id, umur, tingkatKeparahan;
            string nama;
            cout<<"ID Pasien: ";
            cin>>id;
            cout<<"Nama Pasien: ";
            cin.ignore();
            cin>>nama;
            cout<<"Umur Pasien: ";
            cin>>umur;
            cout<<"Tingkat Keparahan: ";
            cin>>tingkatKeparahan;

            insertPasien(listPasien, id, nama, umur, tingkatKeparahan);
            cout<<"Data Pasien berhasil didaftarkan"<<endl;
            break;
        }
        case 3: {// Tambah Relasi Dokter-Pasien
            int idDokter, idPasien;
            string tanggalPemeriksaan;
            cout<<"Masukan ID Dokter: ";
            cin>>idDokter;
            Dokter* dokter=cariDokter(listDokter, idDokter);
            if(!dokter) {
            cout<<"Data dokter tidak ditemukan"<<endl;
            break;
            }
            cout<<"Masukkn ID Pasien: ";
            cin>>idPasien;
            Pasien* pasien=cariPasien(listPasien, idPasien);
            if(!pasien) {
            cout<<"Data pasien tidak ditemukan"<<endl;
            break;
            }
            cout<<"Masukkan tanggal pemeriksaan: ";
            cin.ignore();
            getline(cin,tanggalPemeriksaan);

            tambahRelasi(listRelasi, dokter, pasien, tanggalPemeriksaan);
            break;
        }
        case 4: {// Tampilkan Semua Dokter
            showDokter(listDokter);
            break;
        }
        case 5: {// Tampilkan Semua Pasien
            showPasien(listPasien);
            break;
        }
        case 6: {// Tampilkan Semua Relasi
            showRelasi(listRelasi);
            break;
        }
        case 7: {//Tampilkan Pasien dari Dokter Tertentu
            int idDokter;
            cout<<"Masukkan ID Dokter: ";
            cin>>idDokter;
            Dokter* dokter = cariDokter(listDokter, idDokter);
            if(dokter) {
                showPasienDariDokter(listRelasi, idDokter);
            } else {
                cout<<"Dokter tidak ditemukan"<<endl;
            }
            break;
        }
        case 8: {// Tampilkan Dokter dari Pasien Tertentu
            int idPasien;
            cout<<"Masukkan ID Pasien: ";
            cin>>idPasien;
            Pasien* pasien = cariPasien(listPasien, idPasien);
            if(pasien){
                showDokterDariPasien(listRelasi, pasien);
            } else {
                cout<<"Pasien tidak ditemukan"<<endl;
            }
            break;
        }
        case 9: { // Hapus Dokter
            int idDokter;
            cout << "Masukkan ID Dokter yang akan dihapus: ";
            cin >> idDokter;
            Dokter* dokter = cariDokter(listDokter, idDokter);
            if (dokter) {
                hapusDokter(listDokter, idDokter);
                cout << "Dokter berhasil dihapus.\n";
            } else {
                cout << "Dokter tidak ditemukan.\n";
            }
            break;
        }
        case 10: { // Hapus Pasien
            int idPasien;
            cout << "Masukkan ID Pasien yang akan dihapus: ";
            cin >> idPasien;
            Pasien* pasien = cariPasien(listPasien, idPasien);
            if (pasien) {
                hapusPasien(listPasien, idPasien);
                cout << "Pasien berhasil dihapus.\n";
            } else {
                cout << "Pasien tidak ditemukan.\n";
            }
            break;
        }
        case 11: { // Hapus Relasi
            int idDokter, idPasien;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            Dokter* dokter = cariDokter(listDokter, idDokter);
            Pasien* pasien = cariPasien(listPasien, idPasien);
            if (dokter && pasien) {
                hapusRelasi(listRelasi, dokter, pasien);
                cout << "Relasi berhasil dihapus.\n";
            } else {
                cout << "Dokter atau Pasien tidak ditemukan.\n";
            }
            break;
        }
        case 12: { // Hitung Pasien dari Dokter Tertentu
            int idDokter;
            cout << "Masukkan ID Dokter: ";
            cin >> idDokter;
            Dokter* dokter = cariDokter(listDokter, idDokter);
            if (dokter) {
                int jumlah = hitungPasienPerDokter(listRelasi, dokter);
                cout << "Jumlah pasien dari Dokter " << dokter->nama << ": " << jumlah << endl;
            } else {
                cout << "Dokter tidak ditemukan.\n";
            }
            break;
        }
        case 13: { // Hitung Dokter dari Pasien Tertentu
            int idPasien;
            cout << "Masukkan ID Pasien: ";
            cin >> idPasien;
            Pasien* pasien = cariPasien(listPasien, idPasien);
            if (pasien) {
                int jumlah = hitungDokterPerPasien(listRelasi, pasien);
                cout << "Jumlah dokter untuk Pasien " << pasien->nama << ": " << jumlah << endl;
            } else {
                cout << "Pasien tidak ditemukan.\n";
            }
            break;
        }
        case 14: { // Hitung Pasien tanpa Dokter
            int jumlah = hitungPasienTanpaDokter(listPasien, listRelasi);
            cout << "Jumlah pasien tanpa dokter: " << jumlah << endl;
            break;
        }
        case 15: { // Hitung Dokter tanpa Pasien
            int jumlah = hitungDokterTanpaPasien(listDokter, listRelasi);
            cout << "Jumlah dokter tanpa pasien: " << jumlah << endl;
            break;
        }
        case 16: { // Edit Relasi
            int pilihanEdit;
            cout << "\n=== Edit Relasi ===\n";
            cout << "1. Ganti Dokter dari Pasien Tertentu\n";
            cout << "2. Ganti Pasien dari Dokter Tertentu\n";
            cout << "0. Kembali\n";
            cout << "Pilih: ";
            cin >> pilihanEdit;

            if (pilihanEdit == 1) { // Ganti Dokter dari Pasien Tertentu
                int idDokterLama, idDokterBaru, idPasien;
                cout << "Masukkan ID Dokter Lama: ";
                cin >> idDokterLama;
                cout << "Masukkan ID Dokter Baru: ";
                cin >> idDokterBaru;
                cout << "Masukkan ID Pasien: ";
                cin >> idPasien;

                Dokter* dokterLama = cariDokter(listDokter, idDokterLama);
                Dokter* dokterBaru = cariDokter(listDokter, idDokterBaru);
                Pasien* pasien = cariPasien(listPasien, idPasien);

                if (dokterLama && dokterBaru && pasien) {
                    editRelasi(listRelasi, dokterLama, pasien, dokterBaru, nullptr);
                } else {
                    cout << "Dokter atau Pasien tidak ditemukan.\n";
                }
            } else if (pilihanEdit == 2) { // Ganti Pasien dari Dokter Tertentu
                int idDokter, idPasienLama, idPasienBaru;
                cout << "Masukkan ID Dokter: ";
                cin >> idDokter;
                cout << "Masukkan ID Pasien Lama: ";
                cin >> idPasienLama;
                cout << "Masukkan ID Pasien Baru: ";
                cin >> idPasienBaru;

                Dokter* dokter = cariDokter(listDokter, idDokter);
                Pasien* pasienLama = cariPasien(listPasien, idPasienLama);
                Pasien* pasienBaru = cariPasien(listPasien, idPasienBaru);

                if (dokter && pasienLama && pasienBaru) {
                    editRelasi(listRelasi, dokter, pasienLama, nullptr, pasienBaru);
                } else {
                    cout << "Dokter atau Pasien tidak ditemukan.\n";
                }
            } else if (pilihanEdit == 0){
                cout << "Kembali ke Menu Rumah Sakit.\n";
                break;
            }else {
                cout << "Pilihan tidak valid.\n";
            }
            break;
        }
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
