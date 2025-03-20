#include <iostream>
using namespace std;

// Ham kiem tra so hoan thien
bool kiemTraSoHoanThien(int x) {
    if (x <= 1) return false; // Cac so nho hon hoac bang 1 khong phai la so hoan thien
    int tongUoc = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            tongUoc += i; // Cong cac uoc so cua x (tru chinh no)
        }
    }
    return tongUoc == x; // Kiem tra neu tong cac uoc so bang x
}

// Ham nhap kich thuoc mang
int nhapKichThuocMang() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    return n;
}

// Ham nhap cac phan tu cua mang
void nhapCacPhanTu(int* arr, int n) {
    cout << "Nhap cac phan tu trong mang: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

// Ham kiem tra va in ra cac so hoan thien trong mang
void kiemTraSoHoanThienTrongMang(int* arr, int n) {
    bool timSoHoanThien = false;  // Bien kiem tra co so hoan thien khong

    // Duyet qua tat ca phan tu trong mang
    for (int i = 0; i < n; i++) {
        if (kiemTraSoHoanThien(arr[i])) {
            if (!timSoHoanThien) {
                cout << "Cac so hoan thien trong mang la: " << endl;
                timSoHoanThien = true;
            }
            // In ra vi tri va gia tri cua so hoan thien
            cout << "Vi tri " << i << ": " << arr[i] << endl;
        }
    }

    // In thong bao neu khong tim thay so hoan thien
    if (!timSoHoanThien) {
        cout << "Khong co so hoan thien trong mang!" << endl;
    }
}

// Ham giai phong bo nho
void giaiPhongBoNho(int* arr) {
    delete[] arr;
}

int main() {
    int n = nhapKichThuocMang(); // Nhap kich thuoc mang

    int* arr = new int[n];  // Cap phat bo nho cho mang

    nhapCacPhanTu(arr, n);  // Nhap cac phan tu cho mang

    kiemTraSoHoanThienTrongMang(arr, n);    // Kiem tra va in ra cac so hoan thien

    giaiPhongBoNho(arr);     // Giai phong bo nho

    return 0;
}
