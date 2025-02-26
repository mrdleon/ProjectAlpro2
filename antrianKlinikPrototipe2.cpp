#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi pasien
struct Pasien {
    string nama;
    int nomorAntrian;
    string keluhan;
};

// Node untuk linked list (queue)
struct Node {
    Pasien data;
    Node* next;
};

// Queue berbasis linked list
struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    bool isEmpty();
    void enqueue(Pasien p);
    Pasien dequeue();
    void displayRecursive(Node* node);
    void display();
    Node* getFront();
};

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::enqueue(Pasien p) {
    Node* newNode = new Node{p, nullptr};
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Pasien Queue::dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!" << endl;
        exit(1);
    }
    Node* temp = front;
    Pasien p = front->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    return p;
}

void Queue::displayRecursive(Node* node) {
    if (node == nullptr) return;
    cout << "Nomor Antrian: " << node->data.nomorAntrian
         << ", Nama: " << node->data.nama
         << ", Keluhan: " << node->data.keluhan << endl;
    displayRecursive(node->next);
}

void Queue::display() {
    displayRecursive(front);
}

Node* Queue::getFront() {
    return front;
}

// Deklarasi fungsi
Pasien* search(Queue& q, const string& nama, int nomor = -1);
void insertionSort(Pasien arr[], int n);
void tambahPasien(Queue &antrian, Pasien daftarPasien[], int &jumlahPasien);
void layaniPasien(Queue &antrian);
void cariPasien(Queue &antrian);
void urutkanAntrian(Pasien daftarPasien[], int jumlahPasien);

int main() {
    Queue antrian;
    Pasien daftarPasien[100];
    int jumlahPasien = 0;

    int pilihan;
    do {
        system("cls");
        cout << "\nSistem Manajemen Antrian Klinik" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Layani Pasien" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Cari Pasien" << endl;
        cout << "5. Urutkan Antrian" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer

        switch (pilihan) {
            case 1:
                system("cls");
                tambahPasien(antrian, daftarPasien, jumlahPasien);
                system("pause");
                break;
            case 2:
                system("cls");
                layaniPasien(antrian);
                system("pause");
                break;
            case 3:
                system("cls");
                antrian.display();
                system("pause");
                break;
            case 4:
                system("cls");
                cariPasien(antrian);
                system("pause");
                break;
            case 5:
                system("cls");
                urutkanAntrian(daftarPasien, jumlahPasien);
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}

// Linear Search berdasarkan nama atau nomor antrian
Pasien* search(Queue& q, const string& nama, int nomor) {
    Node* current = q.getFront();
    while (current != nullptr) {
        if (current->data.nama == nama || current->data.nomorAntrian == nomor) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

// Insertion Sort berdasarkan nomor antrian
void insertionSort(Pasien arr[], int n) {
    for (int i = 1; i < n; i++) {
        Pasien key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].nomorAntrian > key.nomorAntrian) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void tambahPasien(Queue &antrian, Pasien daftarPasien[], int &jumlahPasien) {
    Pasien p;
    cout << "Masukkan Nama: ";
    getline(cin, p.nama); // Menggunakan getline untuk nama panjang
    cout << "Masukkan Nomor Antrian: ";
    cin >> p.nomorAntrian;
    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan Keluhan: ";
    getline(cin, p.keluhan);

    antrian.enqueue(p);
    daftarPasien[jumlahPasien++] = p;
}

void layaniPasien(Queue &antrian) {
    if (!antrian.isEmpty()) {
        Pasien dilayani = antrian.dequeue();
        cout << "Pasien dengan nama " << dilayani.nama << " telah dilayani." << endl;
    } else {
        cout << "Antrian kosong!" << endl;
    }
}

void cariPasien(Queue &antrian) {
    string nama;
    cout << "Masukkan Nama atau Nomor Antrian: ";
    getline(cin, nama);

    Pasien* ditemukan = search(antrian, nama);
    if (ditemukan) {
        cout << "Pasien ditemukan: " << ditemukan->nama << ", Keluhan: " << ditemukan->keluhan << endl;
    } else {
        cout << "Pasien tidak ditemukan." << endl;
    }
}

void urutkanAntrian(Pasien daftarPasien[], int jumlahPasien) {
    insertionSort(daftarPasien, jumlahPasien);
    cout << "Antrian setelah diurutkan:" << endl;
    for (int i = 0; i < jumlahPasien; i++) {
        cout << "Nomor Antrian: " << daftarPasien[i].nomorAntrian
             << ", Nama: " << daftarPasien[i].nama
             << ", Keluhan: " << daftarPasien[i].keluhan << endl;
    }
}
