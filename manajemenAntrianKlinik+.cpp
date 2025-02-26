#include <iostream>
using namespace std;

struct patient {
    string name, complaints;
    int queueNumber, age;
};

struct klinik {
    string klinikName, address;
};

patient pasien[50];

int inputPatient = 0;

void addPatient() {
    if (inputPatient < 50) {
        cout << "Masukan nama: ";
        cin.ignore();
        getline(cin, pasien[inputPatient].name);

        cout << "Umur: ";
        cin >> pasien[inputPatient].age;

        cout << "Keluhan: ";
        cin.ignore();
        getline(cin, pasien[inputPatient].complaints);

        pasien[inputPatient].queueNumber = inputPatient + 1;

        cout << "Pasien ke- " << pasien[inputPatient].queueNumber << " berhasil ditambahkan." << endl;
        inputPatient++;
    }
    else {
        cout << "Kuota pendaftaran untuk saat ini sudah penuh." << endl;
    }
}

void displayPatient() {
    if (inputPatient == 0) {
        cout << "Belum ada pasien yang ditambahkan" << endl;
    }
    
    cout << "============ DATA PASIEN ===============" << endl;
    for (int i = 0; i < inputPatient; i++) {
        cout << "Antrian ke- " << i + 1 << endl;
        cout << "Nama: " << pasien[i].name << endl;
        cout << "Umur: " << pasien[i].age << endl;
        cout << "Keluhan: " << pasien[i].complaints << endl;
    }
}

void removePatientRecursive(int index) {
    if (index >= inputPatient - 1) {
        inputPatient--;
        return;
    }

    pasien[index] = pasien[index + 1];

    removePatientRecursive(index + 1);
}

void removePatient() {
    if (inputPatient == 0) {
        cout << "Belum ada pasien yang ditambahkan." << endl;
        system("pause");
        return;
    }

    string target;
    cout << "Masukan nama pasien yang ingin dihapus: " << endl;
    cin.ignore();
    getline(cin, target);

    bool found = false;
    for (int i = 0; i < inputPatient; i++) {
        if (pasien[i].name == target) {
            found = true;
            cout << "Pasien " << pasien[i].name << " telah dihapus dari antrean." << endl;
            removePatientRecursive(i);
            break;
        }
    }

    if (!found) {
        cout << "Pasien tidak ditemukan." << endl;
    }
}

int main() {
    int option;

    do {
        system("cls");
        cout << "================ CLINIC QUEUE MANAGEMENT SYSTEM ================" << endl
             << "1. Add Patient" << endl
             << "2. Display Patient" << endl
             << "3. Search Patient" << endl
             << "4. Remove Patient" << endl
             << "5. Sort Queue" << endl
             << "6. Exit" << endl
             << "Choose Option: ";
        cin >> option;

        switch (option) {
            case 1:
                addPatient();
                system("pause");
                system("cls");
                break;
            case 2: 
                displayPatient();
                system("pause");
                system("cls");
                break;
            case 3: 
                break;
            case 4:
                removePatient();
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "Exting...." << endl;
                system("pause");
                return 0;
            default: 
                cout << "Invalid choice" << endl;
                system("pause");
                system("cls");
        }
    }while (true);
}