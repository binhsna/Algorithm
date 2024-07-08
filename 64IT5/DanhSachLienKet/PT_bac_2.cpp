

#include "ThuVienCuaTui.h"

int main()
{
	/*int n;
	cout << "\nNhap n : ";
	cin >> n;

	bool KT = Kiem_Tra_So_Nguyen_To(n);
	if (KT == true) {
		cout << n << " la so nguyen to !";
	}
	else {
		cout << n << " khong phai la so nguyen to !";
	}*/
	int n, a[100];
	cout << "n = ";
	cin >> n;
	InputArray(a, n);
	ShowArray(a, n);

	InsertNumber(a, n, 12, 3);
	ShowArray(a, n);

	DeleteNumber(a, n, 2);
	ShowArray(a, n);

	system("pause");

	return 0;
}