#include <iostream>
using namespace std;

// Ham sap xep cac phan tu trong 1 dong theo thu tu giam dan
void sapXepDongGiamDan(int** a, int n, int dong) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[dong][j] < a[dong][j + 1]) { // So sanh va hoan doi neu phan tu sau nho hon phan tu truoc
                int temp = a[dong][j];
                a[dong][j] = a[dong][j + 1];
                a[dong][j + 1] = temp;
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

    int dong;
    cout << "Nhap dong muon sap xep (tu 0 den " << m - 1 << "): ";
    cin >> dong;

    // Sap xep cac phan tu trong dong theo thu tu giam dan
    sapXepDongGiamDan(a, n, dong);

    cout << "Ma tran sau khi sap xep dong " << dong << " theo thu tu giam dan: " << endl;
    xuatMaTran(a, m, n); // Xuat ma tran sau khi sap xep

    giaiPhongMaTran(a, m); // Giai phong bo nho
    return 0;
}
