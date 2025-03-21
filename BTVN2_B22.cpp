#include <iostream>
using namespace std;

// Ham kiem tra so hoan thien
bool kiemTraSoHoanThien(int x) {
    if (x <= 1) return false; // So nho hon hoac bang 1 khong phai la so hoan thien
    int tongUoc = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            tongUoc += i; // Cuong cac uoc cua x (tru chinh no)
        }
    }
    return tongUoc == x; 
}

// Ham tinh tong cac so hoan thien trong 1 dong cua ma tran
int tinhTongSoHoanThienTrenDong(int** a, int n, int dong) {
    int tong = 0;

    // Duyet qua tat ca cac phan tu trong dong
    for (int j = 0; j < n; j++) {
        if (kiemTraSoHoanThien(a[dong][j])) {  // Kiem tra neu phan tu la so hoan thien
            tong += a[dong][j]; // Cong phan tu vao tong
        }
    }

    return tong; // Tra ve tong cac so hoan thien tren dong
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

    int dong;
    cout << "Nhap dong muon kiem tra (tu 0 den " << m - 1 << "): ";
    cin >> dong;

    // Tinh tong cac so hoan thien trong dong
    int tong = tinhTongSoHoanThienTrenDong(a, n, dong);
    cout << "Tong cac so hoan thien trong dong " << dong << " la: " << tong << endl;

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
