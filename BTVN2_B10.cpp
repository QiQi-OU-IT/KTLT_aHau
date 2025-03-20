#include <iostream>
using namespace std;

void kiemTraSoDuong(int* arr, int n) {
    bool timSoDuong = false;  // Bien de kiem tra so do co duong hay khong?

    // Duyet qua tat ca phan tu tong mang
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {  
            if (!timSoDuong) {
                cout << "Cac so duong trong mang la: " << endl;
                timSoDuong = true;
            }
            // In ra vi tri so duong
            cout << "Vi tri " << i << ": " << arr[i] << endl;
        }
    }

    // Neu khong tim thay so duong
    if (!timSoDuong) {
        cout << "Khong co so duong trong mang!" << endl;
    }
}

int main() {
    int n;

    // Nhap kich thuoc cua mang
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int* arr = new int[n];  // Cap phat bo nho cho mang

    // nhap cac phan tu cho mang
    cout << "Nhap cac phan tu trong mang: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    // Kiem tra va in ra cac so duonng
    kiemTraSoDuong(arr, n);

    delete[] arr;  // giang phong bo nho
    return 0;
}
