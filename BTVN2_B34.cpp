#include <iostream>
using namespace std;

// Ham tinh hieu hai ma tran vuong
void tinhHieuMaTran(int** a, int** b, int** c, int n) {
    // Duyet qua tung phan tu cua hai ma tran a va b
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j]; // Tinh hieu ma tran
        }
    }
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
    int** b = new int* [n];
    int** c = new int* [n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n]; // Ma tran ket qua
    }

    // Nhap ma tran a
    cout << "Nhap ma tran a:" << endl;
    nhapMaTran(a, n);

    // Nhap ma tran b
    cout << "Nhap ma tran b:" << endl;
    nhapMaTran(b, n);

    // Tinh hieu hai ma tran
    tinhHieuMaTran(a, b, c, n);

    // Xuat ma tran a
    cout << "Ma tran a:" << endl;
    xuatMaTran(a, n);

    // Xuat ma tran b
    cout << "Ma tran b:" << endl;
    xuatMaTran(b, n);

    // Xuat ma tran ket qua (hieu)
    cout << "Hieu hai ma tran a va b la:" << endl;
    xuatMaTran(c, n);

    // Giai phong bo nho
    giaiPhongMaTran(a, n);
    giaiPhongMaTran(b, n);
    giaiPhongMaTran(c, n);

    return 0;
}
