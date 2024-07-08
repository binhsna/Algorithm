#include "ThuVienCuaTui.h"

int main() {
	int n;
	int a[100];
	do {
		cout << "\nNhap so phan tu n = ";
		cin >> n;
	} while (n <= 0);

	InputArray(a, n);
	ShowArray(a, n);

	//int x;
	//cout << "\nNhap so nguyen can them x = ";
	//cin >> x;

	int place;
	cout << "\nNhap vi tri can delete : ";
	cin >> place;

	DeleteNumber(a, n, place);

	ShowArray(a, n);

	system("pause");
	return 0;
}