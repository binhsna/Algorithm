#include <iostream> // khai báo thư viện có sẵn
#include <math.h> // #include <cmath>
using namespace std;

// Định nghĩa hàm kiểm tra số nguyên tố
// Trả về true nếu n là số nguyên tố
bool Kiem_Tra_So_Nguyen_To(int n) {
	if (n < 2) {
		return false;
	}
	else {
		if (n == 2) {
			return true;
		}
		else
		{
			if (n % 2 == 0) {
				return false;
			}
			else {
				for (int i = 2; i < n; i++) {
					if (n % i == 0) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
// Khia báo hàm kiểm tra số hoàn thiện
bool Kiem_Tra_So_Hoan_Thien(int n) {
	// Số hoàn thiện là các số có tổng các ước số của nó ( trừ nó ra ) bằng chính nó
	int sum = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		return true;
	}
	return false;
}

// Khai báo hàm giải phương trình bậc 2
void Giai_Phuong_Trinh_Bac_2(float a, float b, float c) {
	// ax^2 + bx +c = 0
	cout << a << "x^2 + " << b << "x + " << c << " = 0 " << endl;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "\nPhuong trinh vo so nghiem !\n";
			}
			else {
				cout << "\nPhuong trinh vo nghiem !\n";
			}
		}
		else {
			cout << "\nPhuong trinh co nghiem duy nhat! x = " << -c / b << endl;
		}
	}
	else {
		float delta = (b * b) - (4 * a * c);
		if (delta == 0) {
			cout << "\nPhuong trinh co nghiem kep : " << -b / (2 * a);
		}
		else if (delta < 0) {
			cout << "\nPhuong trinh vo nghiem !\n";
		}
		else {
			cout << "\nPhuong trinh co 2 nghiem phan biet : ";
			cout << "\nx1 = " << (-b + sqrt(delta)) / (2 * a);
			cout << "\nx2 = " << (-b - sqrt(delta)) / (2 * a);
		}
	}
	cout << endl;
}

// Mảng 1 chiều số nguyên:
void InputArray(int a[], int& n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << "A[" << i << "] = ";
		cin >> a[i];
	}
	
}
void ShowArray(int a[], int& n) {
	for (size_t i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
  // Hàm thêm 1 số nguyên vào vị trí k bất kỳ
void InsertNumber(int a[], int& n, int x, int place) {
	for (int i = n + 1; i > place; i--)
	{
		a[i] = a[i - 1];

	}
	 a[place] = x;
	 n++;
}
// Hàm xóa 1 số nguyên tại vị trí bất kỳ
void DeleteNumber(int a[], int& n, int place) {
	for (int i = place ; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}