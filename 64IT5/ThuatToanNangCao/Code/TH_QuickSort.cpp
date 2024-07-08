#include <iostream>
using namespace std;

// Ham hoan doi vi tri
void DoiCho(int &x, int &y)
{
	int tg = x;
	x = y;
	y = tg;
}
// Ham phan hoach
int PH(int a[], int head, int tail)
{
	int p = a[tail]; // Khai b�o ph�n tu m�c
	int L = head; // Khai b�o bi�n b�n tr�i
	int R = tail - 1; // Khai b�o bi�n b�n phai
	
	while(1){
		while(L <= R && a[L] < p) L++; // Tang L++ cho d�n khi a[L] >= p
		while(R >= L && a[R] > p) R--; // Giam R-- cho d�n khi a[R] <= p
		if(L >= R) break;
		DoiCho(a[L],a[R]);
		L++; // Vi L hi�n tai da x�t, n�n c�n tang
		R--; // Vi R hi�n tai da x�t, n�n c�n giam
	}
	DoiCho(a[L],a[tail]);
	return L; // Tra v� chi s� se dung de chia doi mang
}
// Ham sap xep nhanh QuickSort
void QS(int a[], int head, int tail)
{
	if (head < tail)
	{
		/* k l� chi so phan tu da dung dung vi tri khi phan hoach
		chia mang lam 2 doan */
		int k = PH(a,head,tail);
		//cout<<k<<" ";
		// Goi de quy sap xep 2 mang con tr�i v� phai
		QS(a,head,k-1);
		QS(a,k+1,tail);
	}
}

// Ham hien thi mang
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 7, 4, 8, 3, 5};
	int n = sizeof(a) / sizeof(a[0]);
	QS(a, 0, n - 1);
	cout << "\nMang sau khi duoc sap xep: \n";
	XuatMang(a, n);
	return 0;
}


