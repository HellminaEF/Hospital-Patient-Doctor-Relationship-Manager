#include "child.h"

//Hellmina Enjelina Fitri

Pasien* cariPasien(ListPasien& list, int id) {
    Pasien* current = list.head;
    while (current) {
        if (current->id == id) return current;
        current = current->next;
    }
    return nullptr;
}

void hapusPasien(ListPasien& list, int id) {
    if (!list.head) return;

    if (list.head->id == id) {
        Pasien* current = list.head;
        list.head = list.head->next;
        if (list.head) list.head->prev = nullptr;
        else list.tail = nullptr;
        delete current;
        return;
    }

    Pasien* current = list.head;
    while (current && current->id != id) current = current->next;

    if (current) {
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == list.tail) list.tail = current->prev;
        delete current;
    }
}

// Izza Az Zahra

void insertPasien(ListPasien& list, int id, const string& nama, int umur, int tingkatKeparahan) {
     if (cariPasien(list, id)!= nullptr) {
        cout<<"ID yang anda masukkan sudah terdaftar. Silahkan masukan ID baru"<<endl;
        return;
     }
     Pasien* newPasien = new Pasien{id, nama, umur, tingkatKeparahan};

     if (list.head == nullptr) {
         list.head = newPasien;
         list.tail = newPasien;
     } else {
         newPasien->next = list.head;
         list.head->prev = newPasien;
         list.head = newPasien;
     }
}

void showPasien(ListPasien& list) {
     Pasien* current = list.head;

     while(current!=nullptr){
        cout<<"ID: "<<current->id;
        cout<<", Nama: "<<current->nama;
        cout<<", Umur: "<<current->umur;
        cout<<", tingkatKeparahan: "<<current->tingkatKeparahan<<endl;
        current = current->next;
     }
}
