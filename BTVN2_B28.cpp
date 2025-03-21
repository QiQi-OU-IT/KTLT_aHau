#include <iostream>
using namespace std;

// Ham sap xep cac phan tu trong 1 cot theo thu tu tang dan
void sapXepCotTangDan(int** a, int m, int cot) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j][cot] > a[j + 1][cot]) { // So sanh va hoan doi neu phan tu sau nho hon phan tu truoc
                int temp = a[j][cot];
                a[j][cot] = a[j + 1][cot];
                a[j + 1][cot] = temp;
            }
        }
    }
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
    cout << "Nhap cot muon sap xep (tu 0 den " << n - 1 << "): ";
    cin >> cot;

    // Sap xep cac phan tu trong cot theo thu tu tang dan
    sapXepCotTangDan(a, m, cot);

    cout << "Ma tran sau khi sap xep cot " << cot << " theo thu tu tang dan: " << endl;
    xuatMaTran(a, m, n); // Xuat ma tran sau khi sap xep

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
