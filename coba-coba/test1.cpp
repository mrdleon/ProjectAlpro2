#include <iostream>
using namespace std;

// Fungsi Binary Search secara rekursif
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika elemen ditemukan di tengah
        if (arr[mid] == target) {
            return mid;
        }

        // Jika elemen berada di sebelah kiri
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Jika elemen berada di sebelah kanan
        return binarySearch(arr, mid + 1, right, target);
    }

    // Elemen tidak ditemukan
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1) {
        cout << "Elemen ditemukan di indeks: " << result << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}
