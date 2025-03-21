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

// Ham xoa phan tu tai vi tri bat ky trong mang
void xoaPhanTuTaiViTri(int*& arr, int& n, int viTri) {
    // Kiem tra vi tri cua mang
    if (viTri < 0 || viTri >= n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }

    // Tao mang moi co kich thuoc n - 1
    int* newArr = new int[n - 1];

    // Sao chep cac phan tu truoc vi tri can xoa
    for (int i = 0; i < viTri; i++) {
        newArr[i] = arr[i];
    }

    // Sao chep cac phan tu sau vi tri can xoa
    for (int i = viTri + 1; i < n; i++) {
        newArr[i - 1] = arr[i];
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

    // Nhap vi tri va xoa phan tu
    int viTri;
    cout << "Nhap vi tri muon xoa (0 den " << n - 1 << "): ";
    cin >> viTri;

    // Xoa phan tu tai vi tri bat ky
    xoaPhanTuTaiViTri(arr, n, viTri);

    // Xuat mang sau khi xoa phan tu
    cout << "Mang sau khi xoa phan tu tai vi tri: ";
    xuatMang(arr, n);

    // Giai phong bo nho
    giaiPhongMang(arr);

    return 0;
}
