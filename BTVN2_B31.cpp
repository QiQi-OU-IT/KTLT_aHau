#include <iostream>
using namespace std;

// Ham tinh tong cac phan tu tren duong cheo phu cua ma tran vuong
int tinhTongDuongCheoPhu(int** a, int n) {
    int tong = 0;

    // Duyet qua cac phan tu tren duong cheo phu
    for (int i = 0; i < n; i++) {
        tong += a[i][n - i - 1]; // Cong cac phan tu (i, n-i-1). Trong do i la hangm n-i-1 la cot
    }

    return tong; // Tra ve tong cac phan tu tren duong cheo phu
}

// Ham nhap kich thuoc ma tran vuong
void nhapKichThuocMaTran(int& n) {
    cout << "Nhap kich thuoc ma tran vuong (n): ";
    cin >> n;
}

// Ham nhap ma tran
void nhapMaTran(int**& a, int n) {
    cout << "Nhap cac phan tu cua ma tran: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Ham xuat ma tran
void xuatMaTran(int** a, int n) {
    cout << "Ma tran cua ban la: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Ham giai phong bo nho
void giaiPhongMaTran(int**& a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i]; // Giai phong tung hang
    }
    delete[] a; // Giai phong mang con tro
    a = nullptr;
}

int main() {
    int n;
    nhapKichThuocMaTran(n); // Nhap kich thuoc ma tran vuong

    // Cap phat bo nho cho ma tran
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    nhapMaTran(a, n); // Nhap ma tran
    xuatMaTran(a, n); // Xuat ma tran

    // Tinh tong cac phan tu tren duong cheo phu
    int tong = tinhTongDuongCheoPhu(a, n);
    cout << "Tong cac phan tu tren duong cheo phu la: " << tong << endl;

    giaiPhongMaTran(a, n); // Giai phong bo nho
    return 0;
}
