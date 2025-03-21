#include <iostream>
using namespace std;

// Ham tim gia tri lon nhat trong 1 dong cua ma tran
int timGiaTriLonNhatTrenDong(int** a, int n, int dong) {
    int max = a[dong][0];  // Giat tri dau tien trong dong duoc gan la max ban dau

    // Duyet qua cac phan tu trong dong de tim gia tri lon nhat
    for (int j = 1; j < n; j++) {
        if (a[dong][j] > max) {
            max = a[dong][j]; // Cap nhat gia tri max
        }
    }

    return max; // Tra ve gia tri lon nhat trong dong
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

    // Tim gia tri lon nhat trong dong
    int max = timGiaTriLonNhatTrenDong(a, n, dong);
    cout << "Gia tri lon nhat trong dong " << dong << " la: " << max << endl;

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
