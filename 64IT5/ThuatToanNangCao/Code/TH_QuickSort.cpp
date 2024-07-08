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
	int p = a[tail]; // Khai báo phân tu môc
	int L = head; // Khai báo biên bên trái
	int R = tail - 1; // Khai báo biên bên phai
	
	while(1){
		while(L <= R && a[L] < p) L++; // Tang L++ cho dên khi a[L] >= p
		while(R >= L && a[R] > p) R--; // Giam R-- cho dên khi a[R] <= p
		if(L >= R) break;
		DoiCho(a[L],a[R]);
		L++; // Vi L hiên tai da xét, nên cân tang
		R--; // Vi R hiên tai da xét, nên cân giam
	}
	DoiCho(a[L],a[tail]);
	return L; // Tra vê chi sô se dung de chia doi mang
}
// Ham sap xep nhanh QuickSort
void QS(int a[], int head, int tail)
{
	if (head < tail)
	{
		/* k là chi so phan tu da dung dung vi tri khi phan hoach
		chia mang lam 2 doan */
		int k = PH(a,head,tail);
		//cout<<k<<" ";
		// Goi de quy sap xep 2 mang con trái và phai
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


