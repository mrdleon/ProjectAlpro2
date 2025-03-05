#include <iostream>
#include <chrono>
#include <windows.h>
#include <string>
using namespace std;

struct user {
    string username;
    string password;
};


user loginAdmin[5];

int savedPassword = 0;

struct Obat {
    string namaObat;
    string penyakit;
    int harga;
    int stock;
};

Obat daftarObat[] = {
    {"Paracetamol", "Demam", 10000,500},
    {"Amoxicillin", "Infeksi", 10000, 300},
    {"Cefadroxil", "Infeksi", 10000, 400},
    {"Ibuprofen", "Demam", 10000, 100},
    {"Antasida", "Asam Lambung", 10000,200}
};

int jumlahObat = sizeof(daftarObat) / sizeof(daftarObat[0]);

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void loading() {
    auto start = chrono::steady_clock::now();  // Waktu mulai
    int duration = 5;  // Durasi dalam detik
    int elapsedTime = 0;
    string dots = "";  // Untuk menambahkan titik secara bertahap
    bool isLoading = true;

    setColor(6);
    cout << "Login process";
    setColor(7);

    while (isLoading) {
        auto now = chrono::steady_clock::now();
        elapsedTime = chrono::duration_cast<chrono::seconds>(now - start).count();

        // Setiap detik, tambahkan satu titik
        if (elapsedTime < duration) {
            if (elapsedTime % 1 == 0 && dots.size() < elapsedTime) {
                dots += ".";  // Menambahkan satu titik
                cout << dots << flush;  // Menampilkan titik yang bertambah
            }
        } else {
            isLoading = false;  // Waktu sudah habis, berhenti
        }
    }

    setColor(2);
    cout << "\nSuccess to Login!" << endl;
    setColor(7);
    system("pause");
    system("cls");
}

void searchingobat() {
    string cariPenyakit;
    cout << "Enter the name of the disease ";
    cin.ignore(); 
    getline(cin, cariPenyakit);

    bool ditemukan = false;    
    for (int i = 0; i < jumlahObat; i++) {
        if (daftarObat[i].penyakit == cariPenyakit) {
            cout << "- " << daftarObat[i].namaObat << " Rp." << daftarObat[i].harga << endl;
            ditemukan = true; }
    }
    if (!ditemukan) {
        cout << "sorry, disease's name doesn't found" << endl;
    }
}

void medicinestock(){
    string cariobat;

    cout << "Enter Drug's Name: ";
    cin.ignore(); 
    getline(cin, cariobat);

    bool ditemukan = false;

    
    for (int i = 0; i < jumlahObat; i++) {
        if (daftarObat[i].namaObat == cariobat) {
            cout << "- " << daftarObat[i].namaObat << " Stock: " << daftarObat[i].stock << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "sorry, stock for that drug doesn't found" << endl;
    }
}

void cariobat(){
    int choice;
    do {
        cout << "\n+===========================+" << endl;
        cout << "|           Menu            |" << endl;
        cout << "+===========================+" << endl;
        cout << "1. All Stock drug" << endl;
        cout << "2. Search stock's drug " << endl;
        cout << "3. Exit "<<endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for(int i=0; i<jumlahObat; i++){
                    cout<<i+1<<". "<<daftarObat[i].namaObat<< " stock: "<<daftarObat[i].stock<<endl;
                }
                break;
            case 2:
                medicinestock();
                break;
            case 3:
                system("exit");
            default:
                cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
    } while (choice != 2); 

    
}

void mainMenu() {
    int selectMenu;

    do {
        cout << "======== VETERAN PHARMACY =========" << endl
             << "1. Medicine stock" << endl
             << "2. Add medicine" << endl
             << "3. Search medicine" << endl
             << "4. Check stock from suppliers" << endl
             << "5. Add patient" << endl
             << "6. Display patient" << endl
             << "7. Search patient" << endl
             << "8. Remove patient" << endl
             << "9. Purchase history" << endl
             << "10. Exit" << endl
             << "Select menu: ";
        cin >> selectMenu;
        switch(selectMenu) {
            case 1:
                system("cls");
                cariobat();
                break;
            case 2: 
                break;
            case 3:
                system("cls");
                searchingobat();
                system("pause");
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                return;
            default:
                cout << "Invalid choice!" << endl;
                system("pause");
                system("cls");
                break;
        }
    }while (true);
}

void signUp() {
    string user, pw;
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pw;

    for (int i = 0; i < savedPassword; i++) {
        if (loginAdmin[i].username == user) {
            cout << "Username already used! Try again." << endl;
            return;
        }
    }

    loginAdmin[savedPassword].username = user;
    loginAdmin[savedPassword].password = pw;
    savedPassword++;
    loading();
    mainMenu();
}

void signIn(int attempts) {
    if (attempts == 0) {
        cout << "To many tries! Try again later." << endl;
        return;
    }

    string user, pw;
    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter yout password: ";
    cin >> pw;

    for (int i = 0; i < savedPassword; i++) {
        if (user == loginAdmin[i].username && pw == loginAdmin[i].password) {
            loading();
            mainMenu();
        }
        else {
            cout << "Incorrect username or password. Try again!" << endl;
            signIn(attempts - 1);
        }
    }
}

void login() {
    int loginOpt;

    do {
        cout << "===== Login Page =====" << endl
             << "1. Sign Up" << endl
             << "2. Sign In" << endl
             << "Choose your login option: ";
        cin >> loginOpt;
        switch(loginOpt) {
            case 1: 
                signUp();
                break;
            case 2:
                signIn(5);
                break;
            default:
                cout << "Invalid choices!" << endl;
                system("pause");
                break;
        }
    }while (true);
}

int main() {
    login();
}