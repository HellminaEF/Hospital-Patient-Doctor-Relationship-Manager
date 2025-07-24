#include "parent.h"

//Hellmina Enjelina Fitri

Dokter* cariDokter(ListDokter& list, int id) {
    Dokter* current = list.head;
    while (current) {
        if (current->id == id) return current;
        current = current->next;
    }
    return nullptr;
}

void hapusDokter(ListDokter& list, int id) {
    if (!list.head) return;

    if (list.head->id == id) {
        Dokter* current = list.head;
        list.head = list.head->next;
        delete current;
        return;
    }

    Dokter* prev = list.head;
    Dokter* current = list.head->next;
    while (current && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current) {
        prev->next = current->next;
        delete current;
    }
}

//Izza Az Zahra

void insertDokter(ListDokter& list, int id, const string& nama, const string& spesialis) {
     if (cariDokter(list, id)!= nullptr) {
        cout<<"Maaf ID yang anda masukkan sudah terdaftar. Silahkan masukkan ID baru"<<endl;
        return;
     }
     Dokter* newDokter = new Dokter{id, nama, spesialis};
     newDokter-> next = list.head;
     list.head = newDokter;
     cout<<"Data Dokter berhasil didaftarkan"<<endl;
}

void showDokter(ListDokter& list) {
    Dokter* current = list.head;

    while (current != nullptr) {
        cout << "ID: " << current->id << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "Spesialis: " << current->spesialis << endl;
        current = current->next;
    }
}
