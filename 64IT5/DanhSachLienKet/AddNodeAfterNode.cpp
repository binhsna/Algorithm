#include <iostream>
using namespace std;
// Thêm node p vào sau node q
class node {
public:
	int data;
	node* next;
};
class list {
public:
	node* head;
	node* tail;
};
void KhoiTaoDSLK(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
node* KhoiTaoNode(int x) {
	node* p = new node;
	if (!p) {
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
// Hàm thêm node p vào đầu danh sách:
void InsertFirst(list& l, node* p) {
	if (! l.head) {
		l.head = l.tail = p;
	}
	else 
	{
		p->next = l.head;
		l.head = p;
	}
}
// Hàm thêm node p vào cuối danh sách:
void InsertLast(list& l, node* p) {
	if (!l.head) {
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
// Xuất danh sách liên kết đơn
void ShowList(list& l) {
	for (node* k = l.head; k != NULL; k = k->next) {
		cout << k->data << " ";
	}
	cout << endl;
}
// Thêm node p vào sau node q(nằm trong single linked list)
void AddNodeAfterOtherNode(list& l, node* p) {
	int x;
	cout << "\nMhap gia tri node q: ";
	cin >> x;
	node* q = KhoiTaoNode(x);

	// Nếu single linked list chỉ có 1 phân tử thì:
	if (q->data == l.head->data && l.head->next == NULL) {
		InsertLast(l, p);
	}
	else
	{
		// Duyệt từ đầu danh sách đến cuối danh sách
		for (node* k = l.head; k != NULL; k = k->next) {
			// Nếu node q tồn tại thì....
			if (q->data == k->data) {
				node* h = KhoiTaoNode(p->data); // Khởi tạo node h để thêm vào sau node q
				node* g = k->next; // Cho node g trỏ đến node nằm sau node q
				h->next = g; // Bước 1. Tạo mối liên kết từ node h đến node g -> cũng chính là tạo mối liên kết node h đến node nằm sau node q
				k->next = h; // Bước 2. Tạo mối liên kết từ node q đến node h -> cũng chính là node k đến node h
			}
		}
	}
}

// Menu
void Menu(list& l) {
	int choose;
	while (true) {
		system("cls");
		cout << "\n\t\t\t==================== MENU ====================\n";
		cout << "\t\t\t1. Them node vao danh sach\n";
		cout << "\t\t\t2. Xuat danh sach lien ket don\n";
		cout << "\t\t\t3. Them node p after node q trong danh sach\n";
		cout << "\t\t\t0. Thoat ";
		cout << "\n\t\t\t==================== END =====================\n";
		
		cout << "Nhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 3) {
			cout << "\nLua chon cua ban khong hop le >> Vui long nhap lai !";
			system("pause");
		}
		else if (choose == 1) {
			int x;
			cout << "\nNhap gia tri so nguyen x = ";
			cin >> x;
			node* p = KhoiTaoNode(x);
			InsertLast(l, p);
		}
		else if (choose == 2) {
			ShowList(l);
			system("pause");
		}
		else if (choose == 3)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao sau node q: ";
			cin >> x;
			node* p = KhoiTaoNode(x);
			AddNodeAfterOtherNode(l, p);
		} 
		else
		{
			break; // Thoát khỏi vòng lặp hiện tại
		}
	}
}
int main() {
	list l;
	KhoiTaoDSLK(l);
	
	Menu(l);

	system("pause");
	return 0;
}