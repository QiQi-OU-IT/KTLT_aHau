#include <iostream>
#include <iomanip>
using namespace std;

// Cap phat bo nho dong cho ma tran
void capPhatMaTran(int**& a, int m, int n) {
	a = new int* [m]; // So hang
	for (int i = 0; i < m; i++) {
		a[i] = new int[n]; //Moi hang co n cot
	}
}

//Ham nhap ma tran
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

// Ham dem so Duong trong ma tran
int demSoDuong(int** a, int m, int n) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] > 0) {
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

	// Goi ham dem so luong
	int soLuongSoDuong = demSoDuong(a, m, n);
	cout << "\nSo luong so duong trong ma tran: " << soLuongSoDuong << endl;

	// Giai phong bo nho
	giaiPhongMaTran(a, m);

	return 0;
}