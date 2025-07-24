#include "relasi.h"

//Izza Az Zahra
void showRelasi(ListRelasi& list) {
    Relasi* current = list.head;

    while (current != nullptr) {
        cout << "Dokter: " <<current->dokter->nama <<", ID: "<<current->dokter->id<<endl;
        cout << "Pasien: " <<current->pasien->nama <<", ID: "<<current->pasien->id<<endl;
        cout << "Tanggal: " <<current->tanggalPemeriksaan<< endl;
        cout << "---------------------\n";
        current = current->next;
    }
}

void showPasienDariDokter(ListRelasi& list, int DokterId) {
     Relasi* current = list.head;
     bool found = false;

     while (current != nullptr) {
        if(current->dokter->id == DokterId) {
           cout<<"Pasien: "<<current->pasien->nama << ", ID: " <<current->pasien->id << endl;
           cout<<"Dokter: "<<current->dokter->nama << ", ID: " <<current->dokter->id << endl;
           cout<<"Tanggal: "<<current->tanggalPemeriksaan << endl;
           cout << "---------------------\n";
           found = true;
        }
           current = current->next;
}
    if(!found){
        cout<<"Tidak ada pasien yang berelasi dengan dokter ID "<<DokterId << endl;
    }
}

void showDokterDariPasien(ListRelasi& list, Pasien* pasien) {
    Relasi* current = list.head;
    bool found = false;

    while (current != nullptr) {
        if (current->pasien->id == pasien->id) {
        cout<<"Dokter: "<<current->dokter->nama <<", ID: " << current->dokter->id << endl;
        cout<<"Pasien: "<<current->pasien->nama <<", ID: " << current->pasien->id << endl;
        cout<<"Tanggal: "<<current->tanggalPemeriksaan << endl;
        cout << "---------------------\n";
        found = true;
    }
    current = current->next;
}
    if(!found) {
        cout<<"Tidak ada relasi antara pasien dengan ID " <<pasien->id << endl;
    }
}

//Hellmina Enjelina Fitri

// Inisialisasi list relasi
void initlistRelasi(ListRelasi& list) {
    list.head = nullptr;
}

// Menambahkan relasi
void tambahRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien, string tanggal) {
    Relasi* newRelasi = new Relasi{dokter, pasien, tanggal, nullptr};
    if (!list.head) {
        list.head = newRelasi;
    } else {
        Relasi* temp = list.head;
        while (temp->next) temp = temp->next;
        temp->next = newRelasi;
    }
}

// Mencari relasi
Relasi* cariRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien) {
    Relasi* temp = list.head;
    while (temp) {
        if (temp->dokter == dokter && temp->pasien == pasien) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Menghapus relasi
void hapusRelasi(ListRelasi& list, Dokter* dokter, Pasien* pasien) {
    Relasi* prev = nullptr;
    Relasi* current = list.head;
    while (current) {
        if (current->dokter == dokter && current->pasien == pasien) {
            if (!prev) list.head = current->next;
            else prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Hitung jumlah pasien per dokter
int hitungPasienPerDokter(const ListRelasi& list, Dokter* dokter) {
    int count = 0;
    Relasi* temp = list.head;
    while (temp) {
        if (temp->dokter == dokter) count++;
        temp = temp->next;
    }
    return count;
}

// Hitung jumlah dokter per pasien
int hitungDokterPerPasien(const ListRelasi& list, Pasien* pasien) {
    int count = 0;
    Relasi* temp = list.head;
    while (temp) {
        if (temp->pasien == pasien) count++;
        temp = temp->next;
    }
    return count;
}

// Hitung pasien tanpa dokter
int hitungPasienTanpaDokter(const ListPasien& list, const ListRelasi& relasiList) {
    int count = 0;
    Pasien* temp = list.head;
    while (temp) {
        if (hitungDokterPerPasien(relasiList, temp) == 0) count++;
        temp = temp->next;
    }
    return count;
}

// Hitung dokter tanpa pasien
int hitungDokterTanpaPasien(const ListDokter& list, const ListRelasi& relasiList) {
    int count = 0;
    Dokter* temp = list.head;
    while (temp) {
        if (hitungPasienPerDokter(relasiList, temp) == 0) count++;
        temp = temp->next;
    }
    return count;
}

// Edit relasi untuk mengganti pasien dari dokter tertentu atau dokter dari pasien tertentu
void editRelasi(ListRelasi& list, Dokter* dokterLama, Pasien* pasienLama, Dokter* dokterBaru, Pasien* pasienBaru) {
    // Cari relasi yang akan diubah
    Relasi* relasi = cariRelasi(list, dokterLama, pasienLama);

    if (relasi) {
        // Jika ada perubahan dokter
        if (dokterBaru) {
            relasi->dokter = dokterBaru;
            cout << "Relasi diperbarui: Dokter untuk Pasien " << pasienLama->nama
                 << " diubah menjadi " << dokterBaru->nama << ".\n";
        }
        // Jika ada perubahan pasien
        if (pasienBaru) {
            relasi->pasien = pasienBaru;
            cout << "Relasi diperbarui: Pasien dari Dokter " << dokterLama->nama
                 << " diubah menjadi " << pasienBaru->nama << ".\n";
        }
    } else {
        cout << "Relasi tidak ditemukan.\n";
    }
}
