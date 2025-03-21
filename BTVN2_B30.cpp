#include <iostream>
using namespace std;

// Ham tinh tong cac phan tu tren duong cheo chinh cua ma tran vuong
int tinhTongDuongCheoChinh(int** a, int n) {
    int tong = 0;

    // Duyet qua cac phan tu tren duong cheo chinh
    for (int i = 0; i < n; i++) {
        tong += a[i][i]; // Cong cac phan tu tren duong cheo chinh
    }

    return tong; // Tra ve tong cac phan tu tren duong cheo chinh
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

    // Tinh tong cac phan tu tren duong cheo chinh
    int tong = tinhTongDuongCheoChinh(a, n);
    cout << "Tong cac phan tu tren duong cheo chinh la: " << tong << endl;

    giaiPhongMaTran(a, n); // Giai phong bo nho
    return 0;
}
