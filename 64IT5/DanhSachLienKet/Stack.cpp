#include <iostream>
using namespace std;
/*
	Nhập danh sách 1 stack chứa các số nguyên, sau đó xuất ra màn hình số nguyên đó	
*/

// Khai báo 1 cái node
class node
{
public:
	int data;
	node* next; // con trỏ liên kết giữa các node vs nhau
};
// Khai báo cấu trúc 1 stack
class stack
{
public:
	node* pTop; // Dùng con trỏ đầu để quản lý stack
};
// Hàm khởi tạo stack
void CreateStack(stack& s)
{
	s.pTop = NULL;
}
// Hàm khởi tạo node
node* CreateNode(int x)
{
	node* p = new node();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;

}
// Hàm kiểm tra stack rỗng ?
bool IsEmpty(stack s)
{
	if (s.pTop == NULL) 
	{
		return true;
	}
	return false;
}
// Hàm push thêm 1 phần tử vào đầu stack
bool Push(stack& s, node* p)
{
	if (p == NULL)
	{
		return false;
	}
	// Nếu danh sách đang rỗng
	if (!IsEmpty(s))	// <-> IsEmpty(s) == true
	{
		s.pTop = p; // node p là node đầu stack
	}
	else // danh sách đã có danh sách
	{
		p->next = s.pTop;
		s.pTop = p; // Cập nhật lại node đầu
	}
	return true;
}
// lấy phần tử đầu stack và hủy nó đi
bool Pop(stack& s, int x) // x chính là giá trị cần lấy trong node
{
	// Nếu danh sách rỗng
	if (!IsEmpty(s))
	{
		return false;
	}
	else 
	{
		node* p = s.pTop; 
		x = p->data;
		s.pTop = s.pTop->next;
		delete p;
	}
	return true;
}
// Hàm xem thông tin phần tử đầu stack:
bool Top(stack& s, int& x) 
{
	if (!IsEmpty(s))
	{
		return false;
	}
	x = s.pTop->data; // Lấy giá trị của phần tử đầu stack ra để xem
	return true;
}
// Hàm xuất danh sách stack
void ShowStack(stack s)
{
	while (IsEmpty(s)) // <-> IsEmpty(s) == false
	{
		int x;
		Pop(s, x);
		cout << x << " ";
	}
}
// Hàm nhập danh sách các số nguyên trong stack
void NhapStack(stack& s)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t ============ Menu ============\n";
		cout << "\n\t\t\t1. Them phan tu vao stack";
		cout << "\n\t\t\t2. Xuat danh sach ra man hinh";
		cout << "\n\t\t\t0. Thoat";
		cout << "\n\t\t\t ============= End =============\n";

		cout << "\nNhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 2)
		{
			cout << "Vui long nhap lai lua chon !";
			system("pause");
		}
		else if (choose == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			node* p = CreateNode(x);
			Push(s, p);
		}
		else if (choose == 2)
		{
			ShowStack(s);
			system("pause");
		}
		else
		{
			break;
		}
	}
}
int main()
{
	stack s;
	CreateStack(s);

	NhapStack(s);

	system("pause");
	return 0;
}