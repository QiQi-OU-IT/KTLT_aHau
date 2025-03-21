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

// Ham them phan tu vao vi tri bat ky trong mang
void themPhanTuVaoViTri(int*& arr, int& n, int x, int viTri) {
    // Kiem tra vi tri co hop le hay khong
    if (viTri < 0 || viTri > n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    // Tao mang moi co kich thuoc lon hon
    int* newArr = new int[n + 1];

    // Sao chep cac phan tu cua mang cu vao mang moi
    for (int i = 0; i < viTri; i++) {
        newArr[i] = arr[i];
    }

    // Gan phan tu moi vao vi tri chinh xac
    newArr[viTri] = x;

    // Sao chep cac phan tu con lai cua mang cu vao mang moi
    for (int i = viTri; i < n; i++) {
        newArr[i + 1] = arr[i];
    }

    // Giai phong bo nho mang cu
    delete[] arr;

    // Cap nhat con tro arr tro den mang moi
    arr = newArr;
    n++;  // Tang kich thuoc mang len 1
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

    // Xuat mang truoc khi them phan tu
    cout << "Mang truoc khi them phan tu: ";
    xuatMang(arr, n);

    // Nhap vi tri va phan tu muon them
    int x, viTri;
    cout << "Nhap phan tu muon them: ";
    cin >> x;
    cout << "Nhap vi tri muon them phan tu (0 den " << n << "): ";
    cin >> viTri;

    // Them phan tu vao vi tri bat ky trong mang
    themPhanTuVaoViTri(arr, n, x, viTri);

    // Xuat mang sau khi them phan tu
    cout << "Mang sau khi them phan tu: ";
    xuatMang(arr, n);

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
