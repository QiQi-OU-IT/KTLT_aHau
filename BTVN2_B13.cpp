#include <iostream>
#include <cmath>  
using namespace std;

// Ham kiem tra so chinh phuong
bool kiemTraSoChinhPhuong(int x) {
    if (x < 0) return false; // So am khong phai la so chinh phuong
    int sqrtX = static_cast<int>(sqrt(x)); // Tinh can bac hai va ep kieu ve int
    return sqrtX * sqrtX == x; // Kiem tra xem can bac hai cua x co binh phuong lai bang chinh no hay khong
}

// Ham nhap kich thuoc mang
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

// Ham kiem tra va in ra cac so chinh phuong trong mang
void kiemTraSoChinhPhuongTrongMang(int* arr, int n) {
    bool timSoChinhPhuong = false;  // Bien kiem tra co so chinh phuong khong

    // Duyet qua tat ca phan tu trong mang
    for (int i = 0; i < n; i++) {
        if (kiemTraSoChinhPhuong(arr[i])) {
            if (!timSoChinhPhuong) {
                cout << "Cac so chinh phuong trong mang la: " << endl;
                timSoChinhPhuong = true;
            }
            // In ra vi tri va gia tri cua so chinh phuong
            cout << "Vi tri " << i << ": " << arr[i] << endl;
        }
    }

    // In thong bao neu khong tim thay so chinh phuong
    if (!timSoChinhPhuong) {
        cout << "Khong co so chinh phuong trong mang!" << endl;
    }
}

// Ham giai phong bo nho
void giaiPhongBoNho(int* arr) {
    delete[] arr;
}

int main() {
    int n = nhapKichThuocMang(); // Nhap kich thuoc mang

    int* arr = new int[n];  // Cap phat bo nho cho mang

    nhapCacPhanTu(arr, n);  // Nhap cac phan tu cho mang

    kiemTraSoChinhPhuongTrongMang(arr, n);    // Kiem tra va in ra cac so chinh phuong

    giaiPhongBoNho(arr);     // Giai phong bo nho

    return 0;
}
