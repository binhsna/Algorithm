#include<iostream>
using namespace std;

/*
Ð?i 1 s? nguyên sang co s? 2 8 16

*/

// khai báo 1 cái node
struct node
{
	int data;
	struct node* pNext;
};
typedef struct node NODE;
// khai báo c?u trúc c?a 1 cái stack
struct stack
{
	NODE* pTop; // con tr? qu?n lí d?u stack
};
typedef struct stack STACK;

// hàm kh?i t?o stack
void KhoiTaoStack(STACK& s)
{
	s.pTop = NULL;
}

// hàm kh?i t?o 1 cái node
NODE* KhoiTaoNode(int x)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // dua d? li?u c?a bi?n x vào trong cái data c?a node p
	p->pNext = NULL;
	return p;
}

/* ================= KI?M TRA STACK R?NG =================*/
bool IsEmpty(STACK s)
{
	// n?u stack r?ng
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}

/* ================= THÊM PH?N T? VÀO Ð?U STACK =================*/
bool Push(STACK& s, NODE* p)
{
	// node p dang r?ng
	if (p == NULL)
	{
		return false;
	}

	// n?u danh sách r?ng
	if (IsEmpty(s) == true)
	{
		s.pTop = p;// node p cung chính là node pTop <=>chính là node d?u stack
	}
	else
	{
		p->pNext = s.pTop; // B1: cho con tr? c?a node p tr? d?n node pTop
		s.pTop = p;// c?p nh?t l?i node d?u chính là node p
	}
	return true;// thêm thành công
}

/* ================= L?Y PH?N T? Ð?U DANH SÁCH VÀ H?Y NÓ ÐI ================= */
bool Pop(STACK& s, int& x) // x chính là giá tr? c?n l?y ra
{
	// n?u danh sách r?ng
	if (IsEmpty(s) == true)
	{
		return false; // l?y th?t b?i <=> danh sách dang r?ng
	}
	else
	{
		NODE* p = s.pTop; // gán node d?u danh sách vào node p <=> node p chính là node mà tí n?a ta s? xóa nó
		s.pTop = s.pTop->pNext; // c?p nh?t l?i node d?u 
		x = p->data; // l?y giá tr? c?a node d?u ra gán vào bi?n x
		delete p;
	}
	return true; // l?y ph?n t? thành công
}

/* ================= XEM THÔNG TIN C?A NODE Ð?U DANH SÁCH ================= */
bool Top(STACK s, int& x) // x chính là giá tr? c?n xem
{
	// n?u danh sách r?ng

	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data;
	return true;
}

// HÀM Ð?I CO S? 10 SANG CO S? 2 8 16
void Chuyen_So_So(STACK& s, int cosocandoi, int hethapphan)
{
	while(hethapphan != 0)
	{
		int x = hethapphan % cosocandoi;
		NODE* p = KhoiTaoNode(x); // thêm x vào node p
		Push(s, p); // thêm node p vào stack
		hethapphan /= cosocandoi;
	}
}

// xu?t danh sách stack
void XuatStack(STACK& s)
{
	for (NODE* k = s.pTop; k != NULL; k = k->pNext)
	{
		if (k->data < 10) {
			cout << k->data;
		}
		else if(k->data == 10)
		{
			cout << "A";
		}
		else if (k->data == 11)
		{
			cout << "B";
		}
		else if (k->data == 12)
		{
			cout << "C";
		}
		else if (k->data == 13)
		{
			cout << "D";
		}
		else if (k->data == 14)
		{
			cout << "E";
		}
		else if (k->data == 15)
		{
			cout << "F";
		}

	}
}
// Hàm giải phóng bộ nhớ:
void CleanMemory(STACK& s)
{
	node* k = NULL;
	while (s.pTop != NULL)
	{
		k = s.pTop;
		s.pTop= s.pTop->pNext;
		delete k;
	}
}
// Hàm Menu
void Menu(STACK& s)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t==================== MENU ====================\n";
		cout << "\n\t\t\t1. Nhap thao tac chuyen ? ";
		cout << "\n\t\t\t0. Ket thuc !!! ";
		cout << "\n\n\t\t\t==================== END =====================\n";

		cout << "\nLua chon cua ban la: ";
		cin >> choose;

		if (choose < 0 || choose > 1)
		{
			cout << "\nBan vui long nhap lai !!!";
			system("pause");
		}
		else if (choose == 1) {
			int a;
			cout << "\nMoi ban nhap so thap phan: ";
			cin >> a;
			int cosocandoi;
			cout << "\nNhap co so can chuyen (2, 8, 16): ";
			cin >> cosocandoi;
			Chuyen_So_So(s, cosocandoi, a);

			cout << "\nKet qua la: \n";
			XuatStack(s);
			CleanMemory(s);
			cout << endl;

			system("pause");
		}
		else
		{
			//CleanMemory(s);
			break;
		}
	}
}


int main()
{
	STACK s;

	KhoiTaoStack(s);


	Menu(s);

	system("pause");
	return 0;
}