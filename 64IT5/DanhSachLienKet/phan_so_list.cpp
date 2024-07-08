#include<iostream>
using namespace std;

// Nhập danh sách liên kết đơn các phân số
// khai báo cấu trúc 1 cái phân
struct phanso
{
	int tuso;
	int mauso;
};
typedef struct phanso PHANSO;


// nhập phân số
void Nhap_Phan_So(PHANSO& ps)
{
	cout << "\nNhap tu so: ";
	cin >> ps.tuso;
	cout << "\nNhap mau so: ";
	cin >> ps.mauso;
}

// hàm xuất phân số
void Xuat_Phan_So(PHANSO ps)
{
	cout << ps.tuso << "/" << ps.mauso;
}

// khai báo cấu trúc 1 cái node
struct node
{
	PHANSO data; // thành phần dữ liệu của 1 cái node
	node* pNext; // con trỏ dùng để giữ địa chỉ của cái node mà nó muốn liên kết đến
};
typedef struct node NODE;

// hàm khởi tạo 1 cái node 
NODE* KhoiTaoNode(PHANSO ps)
{
	NODE* p = new NODE; // Khởi tạo vùng nhớ cho cái node chuẩn bị thêm vào danh sách
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = ps; // truyền giá trị ps vào cho cái data của cái node p
	p->pNext = NULL; // chưa liên kết đến thằng nào hết
	return p;
}

// hàm thêm 1 cái node p vào đầu danh sách
void ThemDau(NODE*& pHead, NODE* p)
{
	// nếu danh sách rỗng
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		p->pNext = pHead; // cho node p cầnh thêm kết nối đến thằng đầu danh sách
		pHead = p; // cập nhật lại node đầu chính là node vừa thêm vào
	}
}

// hàm thêm 1 cái node p cuối danh sách
void ThemCuoi(NODE*& pHead, NODE* p)
{
	// nếu danh sách rỗng
	if (pHead == NULL)
	{
		pHead = p;
	}
	else
	{
		for (NODE* k = pHead; ; k = k->pNext)
		{
			// nếu cái thằng đang xét mà cái pNext bên trong nó đang liên kết đến NULL ==> k chính là node cuối danh sách
			if (k->pNext == NULL)
			{
				k->pNext = p;
				break;
			}
		}
	}
}

// hàm xuất danh sách các phân số
void Xuat_Danh_Phan_So(NODE* pHead)
{
	for (NODE* k = pHead; k != NULL; k = k->pNext)
	{
		Xuat_Phan_So(k->data);
		cout << endl;
	}
}

// hàm xóa node đầu danh sách
void XoaDau(NODE*& pHead)
{
	// danh sách đang rỗng
	if (pHead == NULL)
	{
		return;
	}
	NODE* p = pHead; // node p là node thế mạng giữ thằng đầu danh sách thông qua việc trỏ đến thằng pHead
	pHead = pHead->pNext;
	delete p; // xóa đi thằng p cũng chính là xóa đi thằng đầu danh sách
}

// hàm xóa node cuối danh sách
void XoaCuoi(NODE*& pHead)
{
	// danh sách đang rỗng
	if (pHead == NULL)
	{
		return;
	}
	// nếu danh sách tồn tại 1 cá node
	if (pHead->pNext == NULL)

	{
		NODE* p = pHead; // node p là node thế mạng giữ thằng đầu danh sách thông qua việc trỏ đến thằng pHead
		pHead = NULL;
		delete p; // xóa đi thằng p cũng chính là xóa đi thằng đầu danh sách
		return;
	}
	// đi kiếm cái NODE cuối
	for (NODE* k = pHead; ; k = k->pNext)
	{
		if (k->pNext->pNext == NULL)
		{
			delete k->pNext;
			k->pNext = NULL;
			break;
		}
	}
}


// hàm thêm 1 NODE k vào sau NODE q trong dannh sách - NODE q phải tồn tại thì mới thêm
void Them_Node_k_Sau_Node_q_Trong_Danh_Sach(NODE*& pHead, PHANSO x, NODE* q)
{

	// duyệt danh sách để kiểm tra xem có tồn tại node q hay không
	for (NODE* l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso)
		{
			NODE* k = KhoiTaoNode(x);
			// BƯỚC 1: lấy node k liên kết đến node nằm sau node l
			k->pNext = l->pNext; // l->pNext chính là thằng nằm sau node l
			// BƯỚC 2: lấy thằng l kết nối với node k cần thêm vào sau node l
			l->pNext = k;
		}
	}
}

// hàm xóa 1 NODE k sau NODE q trong dannh sách - NODE q phải tồn tại thì mới xóa sau
void Xoa_Node_Sau_Node_q_Trong_Danh_Sach(NODE*& pHead, NODE* q)
{

	// duyệt danh sách để kiểm tra xem có tồn tại node q hay không
	for (NODE* l = pHead; l != NULL; l = l->pNext)
	{
		if (l->data.tuso == q->data.tuso && l->data.mauso == q->data.mauso && l->pNext != NULL)
		{
			NODE* tam = l->pNext; // Bước 1: nhờ thằng tam giữ dùm địa chỉ của thằng nằm sau node l
			l->pNext = l->pNext->pNext; // Bước 2: cho node l liên kết đến node nằm sau node cần xóa
			delete tam; // Bước 3: xóa đi thằng tam <=> xóa đi thằng nằm sau node l
		}
	}
}

// thiết kế menu thao tác trên danh sách liên kết đơn
void Menu(NODE*& pHead)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY DANH SACH PHAN SO ========\n";
		cout << "\n1. Nhap phan so";
		cout << "\n2. Xuat danh sach phan so";
		cout << "\n3. Xoa dau danh sach";
		cout << "\n4. Xoa cuoi danh sach";
		cout << "\n5. Them NODE k sau NODE q trong danh sach";
		cout << "\n6. Xoa 1 cai NODE sau NODE q trong danh sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			PHANSO ps;
			cout << "\n\n\t\t NHAP PHAN SO\n";
			Nhap_Phan_So(ps);

			NODE* p = KhoiTaoNode(ps);
			//ThemDau(pHead, p);
			ThemCuoi(pHead, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH PHAN SO\n";
			Xuat_Danh_Phan_So(pHead);
			system("pause");
		}
		else if (luachon == 3)
		{
			XoaDau(pHead);
		}
		else if (luachon == 4)
		{
			XoaCuoi(pHead);
		}
		else if (luachon == 5)
		{
			PHANSO x;
			cout << "\nNhap gia tri phan so cho NODE K can them: ";
			Nhap_Phan_So(x);
			PHANSO y;
			cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
			Nhap_Phan_So(y);
			NODE* q = KhoiTaoNode(y);
			Them_Node_k_Sau_Node_q_Trong_Danh_Sach(pHead, x, q);
		}
		else if (luachon == 6)
		{
			PHANSO y;
			cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
			Nhap_Phan_So(y);

			NODE* q = KhoiTaoNode(y);
			Xoa_Node_Sau_Node_q_Trong_Danh_Sach(pHead, q);
		}

		else
		{
			break;
		}
	}
}

int main()
{
	NODE* pHead = NULL;
	Menu(pHead);
	system("pause");
	return 0;
}
