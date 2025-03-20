#include <iostream>
using namespace std;

// Ham kiem tra 1 cot trong ma tran co giam dan khong
bool kiemTraCotGiamDan(int** a, int m, int n, int cot) {
    // Duyet qua cot va kiem tra xem phan tu sau co nho hon phan tu truoc hay khong
    for (int i = 1; i < m; i++) {
        if (a[i][cot] >= a[i - 1][cot]) {
            return false; // Neu phan tu sau khong nho hon phan tu truoc, tra ve false
        }
    }
    return true; // Cot giam dan
}

// Ham nhap kich thuoc ma tran
void nhapKichThuocMaTran(int& m, int& n) {
    cout << "Nhap so hang (m): ";
    cin >> m;
    cout << "Nhap so cot (n): ";
    cin >> n;
}

// Ham nhap ma tran
void nhapMaTran(int**& a, int m, int n) {
    cout << "Nhap cac phan tu cua ma tran: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Ham xuat ma tran
void xuatMaTran(int** a, int m, int n) {
    cout << "Ma tran cua ban la: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Ham giai phong bo nho
void giaiPhongMaTran(int**& a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i]; // Giai phong tung hang
    }
    delete[] a; // Giai phong mang con tro
    a = nullptr;
}

int main() {
    int m, n;
    nhapKichThuocMaTran(m, n); // Nhap kich thuoc ma tran

    // Cap phat bo nho cho ma tran
    int** a = new int* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }

    nhapMaTran(a, m, n); // Nhap ma tran
    xuatMaTran(a, m, n); // Xuat ma tran

    int cot;
    cout << "Nhap cot muon kiem tra (tu 0 den " << n - 1 << "): ";
    cin >> cot;

    // Kiem tra cot co giam dan khong
    if (kiemTraCotGiamDan(a, m, n, cot)) {
        cout << "Cot " << cot << " co giam dan!" << endl;
    }
    else {
        cout << "Cot " << cot << " khong giam dan!" << endl;
    }

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
