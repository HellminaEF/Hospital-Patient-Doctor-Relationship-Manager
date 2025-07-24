#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include <iostream>
#include <string>
#include "parent.h"
#include "child.h"

using namespace std;

// Struktur untuk node Relasi
struct Relasi {
    Dokter* dokter; //Pointer ke dokter
    Pasien* pasien; //Pointer ke pasien
    string tanggalPemeriksaan;
    Relasi* next;
};

// Struktur untuk list Relasi
struct ListRelasi {
    Relasi* head;
};

//Fungsi untuk list Relasi
// Izza Az Zahra
void showRelasi(ListRelasi& list);
void showPasienDariDokter(ListRelasi& list, int DokterId);
void showDokterDariPasien(ListRelasi& list, Pasien* pasien);

// Hellmina Enjelina Fitri
void initlistRelasi(ListRelasi& list); // Inisialisasi list relasi
void tambahRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien, string tanggal); // Menambah relasi
Relasi* cariRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien); // Mencari relasi
void hapusRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien); // Menghapus relasi
int hitungPasienPerDokter(const ListRelasi& list, Dokter* dokter);  // Hitung jumlah pasien per dokter
int hitungDokterPerPasien(const ListRelasi& list, Pasien* pasien);  // Hitung jumlah dokter per pasien
int hitungPasienTanpaDokter(const ListPasien& list, const ListRelasi& relasiList); // Hitung pasien tanpa dokter
int hitungDokterTanpaPasien(const ListDokter& list, const ListRelasi& relasiList); // Hitung dokter tanpa pasien
void editRelasi(ListRelasi& list, Dokter* dokterLama, Pasien* pasienLama, Dokter* dokterBaru, Pasien* pasienBaru); // Edit relasi


#endif // RELASI_H_INCLUDED
