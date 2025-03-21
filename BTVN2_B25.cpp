#include <iostream>
using namespace std;

// Ham kiem tra so nguyen to
bool kiemTraSoNguyenTo(int x) {
    if (x <= 1) return false; // So nho hon hoac bang 1 khong phai la so nguyen to
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false; // Neu chia het cho i, thi x khong phai so nguyen to
    }
    return true; // X la so nguyen to
}

// Ham tim gia tri nguyen to xuat hien dau tien tren 1 dong cua ma tran
int timGiaTriNguyenToDauTienTrenDong(int** a, int n, int dong) {
    for (int j = 0; j < n; j++) {
        if (kiemTraSoNguyenTo(a[dong][j])) {  // Kiem tra neu phan tu la so nguyen to
            return a[dong][j]; // Tra ve gia tri nguyen to dau tien
        }
    }
    return -1; // Tra ve -1 neu khong tim thay so nguyen to nao
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

    // Tim gia tri nguyen to dau tien tren dong
    int result = timGiaTriNguyenToDauTienTrenDong(a, n, dong);
    if (result == -1) {
        cout << "Khong tim thay so nguyen to trong dong " << dong << endl;
    }
    else {
        cout << "Gia tri nguyen to dau tien tren dong " << dong << " la: " << result << endl;
    }

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
