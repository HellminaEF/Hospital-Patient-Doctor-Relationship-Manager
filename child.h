#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

// Struktur untuk node Pasien
struct Pasien {
    int id;
    string nama;
    int umur;
    int tingkatKeparahan;
    Pasien* prev;
    Pasien* next;
};

// Struktur untuk list Pasien
struct ListPasien {
    Pasien* head;
    Pasien* tail;
    ListPasien() : head(nullptr), tail(nullptr) {}
};

//Fungsi untuk list Pasien
// Izza Az Zahra
void insertPasien(ListPasien& list, int id, const string& nama, int umur, int tingkatKeparahan);
void showPasien(ListPasien& list);

// Hellmina Enjelina Fitri
Pasien* cariPasien(ListPasien& list, int id);// Mencari pasien berdasarkan ID
void hapusPasien(ListPasien& list, int id);// Menghapus pasien berdasarkan ID

#endif // CHILD_H_INCLUDED
