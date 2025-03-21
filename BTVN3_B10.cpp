#include <iostream>
#include <cstdlib>  // De su dung rand() va srand()
#include <ctime>    // De su dung time>

using namespace std;

// Ham tao mang 1 chieu ngau nhien
void taoMangNgauNhien(int*& arr, int n) {
    // Cap phat bo nho cho mang
    arr = new int[n];

    // Sinh ngau nhien gia tri tu 1 den 100
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
}

// Ham xuat mang
void xuatMang(int* arr, int n) {
    cout << "Mang ngau nhien la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int x) {
    if (x <= 1) {
        return false;  // x ? SNT | x > 1
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;  // x chia het cho i => khong phai SNT
        }
    }

    return true;  // reuturn x neu la SNT
}

// Ham tinh tong cac phan tu la so nguyen to trong mang
int tinhTongSoNguyenTo(int* arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {  // Ktra cac ptu la SNT
            tong += arr[i];  // Cong cac phan tu la SNT
        }
    }
    return tong;
}

// Ham giai phong bo nho
void giaiPhongMang(int*& arr) {
    delete[] arr;  // Giai phong bo nho cho mang
    arr = nullptr;  // Dat con tro ve NULL
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Khoi tao seed cho rand()

    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    int* arr = nullptr;  // Con tro mang

    // Tao mang ngau nhien
    taoMangNgauNhien(arr, n);

    // Xuat mang
    cout << "Mang ngau nhien: ";
    xuatMang(arr, n);

    // Tinh tong cac phan tu la so nguyen to trong mang
    int tong = tinhTongSoNguyenTo(arr, n);

    // Xuat tong
    cout << "Tong cac phan tu la so nguyen to trong mang la: " << tong << endl;

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
