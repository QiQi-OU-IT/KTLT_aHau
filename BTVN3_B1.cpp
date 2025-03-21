#include <iostream>
#include <cstdlib>  // De su dung rand() va srand()
#include <ctime>    // De su dung time()

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
    xuatMang(arr, n);

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
