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

// Ham xoa phan tu o cuoi mang
void xoaPhanTuCuoiMang(int*& arr, int& n) {
    // Kiem tra cac phan tu trong mang
    if (n <= 0) {
        cout << "Mang rong, khong the xoa phan tu!" << endl;
        return;
    }

    // Tao mang moi co kich thuoc n - 1
    int* newArr = new int[n - 1];

    // Sao chep cac phan tu tu vi tri 0 den n-2 vao mang moi
    for (int i = 0; i < n - 1; i++) {
        newArr[i] = arr[i];
    }

    // Giai phong bo nho mang cu
    delete[] arr;

    // Cap nhat con tro arr tro den mang moi
    arr = newArr;
    n--;  // Giam kich thuoc cua mang
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

    // Xuat mang truoc khi xoa phan tu
    cout << "Mang truoc khi xoa phan tu: ";
    xuatMang(arr, n);

    // Xoa phan tu o cuoi mang
    xoaPhanTuCuoiMang(arr, n);

    // Xuat mang sau khi xoa phan tu
    cout << "Mang sau khi xoa phan tu o cuoi: ";
    xuatMang(arr, n);

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
