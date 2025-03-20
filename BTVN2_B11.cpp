#include <iostream>
using namespace std;

// Ham nhap kich thuoc cua mang
int nhapKichThuocMang() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    return n;
}

// Ham nhap cac phan tu cua mang
void nhapCacPhanTu(int* arr, int n) {
    cout << "Nhap cac phan tu trong mang: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}

// Ham kiem tra va in ra cac so am trong mang
void kiemTraSoAm(int* arr, int n) {
    bool timSoAm = false;  // Bien kiem tra so co am hay khong

    // Duyet qua tat ca cac phan tu trong mang
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (!timSoAm) {
                cout << "Cac so am trong mang la: " << endl;
                timSoAm = true;
            }
            // In ra vi tri va gia tri cua so am tim duoc
            cout << "Vi tri " << i << ": " << arr[i] << endl;
        }
    }

    // Cout neu khong tim thay so am
    if (!timSoAm) {
        cout << "Khong co so am trong mang!" << endl;
    }
}

// Ham gia phong bo nho
void giaiPhongBoNho(int* arr) {
    delete[] arr;
}

int main() {
    int n = nhapKichThuocMang();

    int* arr = new int[n];  // Cap phat bo nho cho mang

    nhapCacPhanTu(arr, n);  

    kiemTraSoAm(arr, n);    

    giaiPhongBoNho(arr);     

    return 0;
}
