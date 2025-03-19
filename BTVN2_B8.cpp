#include <iostream>
#include <iomanip>
#include <cmath>  
#include <unordered_set>  // Thu vien de theo doi cac gia tri tuyet doi da xuat hien trong ma tran
using namespace std;

/*So tri: La so trong ma tran ma gia tri tuyet doi cua no bang gia tri tuyet doi cua
                                                                                    so khac trong ma tran
*/

// Cap phat bo nho dong cho ma tran
void capPhatMaTran(int**& a, int m, int n) {
    a = new int* [m]; // So hang
    for (int i = 0; i < m; i++) {
        a[i] = new int[n]; // Moi hang co n cot
    }
}

// Ham kiem tra so tri
bool kiemTraSoTri(int** a, int m, int n, int i, int j, unordered_set<int>& foundValues) {
    int absValue = abs(a[i][j]); // Lay gia tri tuyet doi cua mot so

    // Kiem tra xem so do da xuat hien trong ma tran hay chua?
    if (foundValues.find(absValue) != foundValues.end()) {
        return true; // Neu co -> tra ve true
    }

    // Them gia tri tuyet doi cua so no vao 'set' de theo doi
    foundValues.insert(absValue);
    return false; // Tra ve false ne khong tim thay so tri
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

// Ham dem so luong so tri trong ma tran
int demSoTri(int** a, int m, int n) {
    unordered_set<int> foundValues; // su dung unordered_set de theo doi cac gia tri tuyet doi
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (kiemTraSoTri(a, m, n, i, j, foundValues)) {
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

    // Goi ham dem so luong so tri
    int soLuongSoTri = demSoTri(a, m, n);
    cout << "\nSo luong so tri trong ma tran: " << soLuongSoTri << endl;

    // Giai phong bo nho
    giaiPhongMaTran(a, m);

    return 0;
}
