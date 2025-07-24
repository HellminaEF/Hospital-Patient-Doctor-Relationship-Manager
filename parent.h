#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

// Struktur untuk node Dokter
struct Dokter {
    int id;
    string nama;
    string spesialis;
    Dokter* next;
};

// Struktur untuk list Dokter
struct ListDokter {
    Dokter* head;
    ListDokter() : head (nullptr) {}
};

// Fungsi untuk list Dokter
// Izza Az Zahra
void insertDokter(ListDokter& list, int id, const string& nama, const string& spesialis);
void showDokter(ListDokter& list);

// Hellmina Enjelina Fitri
Dokter* cariDokter(ListDokter& list, int id);// Cari dokter berdasarkan ID
void hapusDokter(ListDokter& list, int id); // Hapus dokter berdasarkan ID

#endif // PARENT_H_INCLUDED
