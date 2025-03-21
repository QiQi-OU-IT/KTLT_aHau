#include <iostream>
#include <cstdlib>  // De su dung rand() va srand()
#include <ctime>    // De su dung time()
#include <cmath>   

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

// Ham kiem tra so chinh phuong
bool laSoChinhPhuong(int x) {
    int canBacHai = static_cast<int>(sqrt(x));  // Tinh can bac hai
    return (canBacHai * canBacHai == x);  // Ktra can bac hai phai so nguyen khong?
}

// Ham tinh tong cac phan tu la so chinh phuong trong mang
int tinhTongSoChinhPhuong(int* arr, int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(arr[i])) {  // if arr[i] chinh phuong?
            tong += arr[i];  // Cong arr[i]
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

    // Tinh tong cac phan tu la so chinh phuong trong mang
    int tong = tinhTongSoChinhPhuong(arr, n);

    // Xuat tong
    cout << "Tong cac phan tu la so chinh phuong trong mang la: " << tong << endl;

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
