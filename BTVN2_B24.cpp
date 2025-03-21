#include <iostream>
using namespace std;

// Ham tim gia tri nho nhat trong 1 cot cua ma tran
int timGiaTriNhoNhatTrenCot(int** a, int m, int cot) {
    int min = a[0][cot];  // Giat tri dau tien trong cot duoc gan la min ban dau

    // Duyet qua cac phan tu trong cot de tim gia tri nho nhat
    for (int i = 1; i < m; i++) {
        if (a[i][cot] < min) {
            min = a[i][cot]; // Cap nhat gia tri min
        }
    }

    return min; // Tra ve gia tri nho nhat trong cot
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

    // Tim gia tri nho nhat trong cot
    int min = timGiaTriNhoNhatTrenCot(a, m, cot);
    cout << "Gia tri nho nhat trong cot " << cot << " la: " << min << endl;

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
