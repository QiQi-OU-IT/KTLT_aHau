#include <iostream>
#include <iomanip>
#include <cmath>  
using namespace std;

/*So cuc dai: La so lon hon tat ca cac so khac xung quanh no*/

// Cap phat bo nho dong cho ma tran
void capPhatMaTran(int**& a, int m, int n) {
    a = new int* [m]; // So hang
    for (int i = 0; i < m; i++) {
        a[i] = new int[n]; // Moi hang co n cot
    }
}

// Ham kiem tra so cuc dai
bool kiemTraSoCucDai(int** a, int m, int n, int i, int j) {
    int current = a[i][j];

    // Kiem tra cac phan tu xung quanh no
    int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 }; // Huong doc va huong cheo
    int dy[] = { 0, 0, -1, 1, -1, -1, 1, 1 }; // Huong ngang va huong cheo

    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        // Kiem tra vi tri cua no co nam trong ma tran khong
        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            if (a[ni][nj] >= current) {
                return false; // Neu co so nao >= chinh no -> khong phai so cuc dai
            }
        }
    }
    return true;
}

// Ham nhap ma tran
void nhapMaTran(int** a, int m, int n) {
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
            cout << setw(5) << a[i][j]; // Moi cot cach nhau 5 ky tu
        }
        cout << endl;
    }
}

// Ham dem so luong so cuc dai trong ma tran
int demSoCucDai(int** a, int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (kiemTraSoCucDai(a, m, n, i, j)) {
                count++;
            }
        }
    }
    return count;
}

// Ham giai phong bo nho 
void giaiPhongMaTran(int**& a, int m) {
    for (int i = 0; i < m; i++) {
        delete[] a[i]; //giai phong tung hang
    }
    delete[] a; // Gia phong mang con tro hang
    a = nullptr;
}

int main() {
    int** a;
    int m, n;

    //Nhap so ha va so cot cua ma tran
    cout << "Nhap so hang (m): " << endl;
    cin >> m;
    cout << "Nhap so cot (n): " << endl;
    cin >> n;

    // Cap phat bo nho
    capPhatMaTran(a, m, n);

    // Goi ham nhap ma tran
    nhapMaTran(a, m, n);

    // Goi ham xuat ma tran
    xuatMaTran(a, m, n);

    // Goi ham dem so luong so cuc dai
    int soLuongSoCucDai = demSoCucDai(a, m, n);
    cout << "\nSo luong so cuc dai trong ma tran: " << soLuongSoCucDai << endl;

    // Giai phong bo nho
    giaiPhongMaTran(a, m);

    return 0;
}
