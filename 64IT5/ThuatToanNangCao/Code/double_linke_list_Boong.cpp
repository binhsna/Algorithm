#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node* prev;
};
class list
{
public:
	node* head;
	node* tail;
};
node* CreateNode(int x)
{
	node* p = new node;
	if (p == NULL) exit(1);
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
void CreateList(list& l)
{
	l.head = NULL;
	l.tail = NULL;
}
void InsertAtHead(list& l, int x)
{
	node* p = CreateNode(x);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		return;
	}
	l.head->prev = p;
	p->next = l.head;
	l.head = p;
}
void InsertAtTail(list& l, int x)
{
	node* p = CreateNode(x);
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		return;
	}
	l.tail->next = p;
	p->prev = l.tail;
	l.tail = p;
}
// Hàm search
node* search(list& l, int k) {
	node* p = l.head;
	while (p != NULL) {
		if (p->data == k) {
			return p;
		}
		p = p->next;
	}
	cout << "\nKhong co phan tu " << k << " trong list !" << endl;
	return NULL;
}
// Hàm chèn node x vào sau node k (trong list có 1 hay nhiều node k)
void addsAfter(list& l, int x, int k) {
	search(l, k);
	for (node* g = l.head; g != NULL; g = g->next) {
		if (g != l.tail && g->data == k) {
			node* q = CreateNode(x);
			node* r = g->next;
			g->next = q; q->prev = g;
			q->next = r; r->prev = q;
		}
		if (g == l.tail && g->data == k) {
			InsertAtTail(l, x);
		}
	}
}
// Hàm chèn node x vào trước node k (trong list có 1 hay nhiều node k)
void addsBefore(list& l, int x, int k) {
	search(l, k);
	for (node* g = l.tail; g != NULL; g = g->prev)
	{
		if (g != l.head && g->data == k) {
			node* q = CreateNode(x);
			node* r = g->prev;
			g->prev = q; q->next = g;
			q->prev = r; r->next = q;
		}
		if (g == l.head && g->data == k) {
			InsertAtHead(l, x);
		}
	}
}
// Hàm chèn vào vi trí bất kỳ trong list:
void addNode_k(list& l, int x, int place, int n) {
	if (l.head == NULL || place == 1) {
		InsertAtHead(l, x);
	}
	else if (place == n + 1) {
		InsertAtTail(l, x);
	}
	else {
		node* temp = l.head;
		n = 0;
		while (temp != NULL) {
			n++;
			if (place == n) {
				node* q = CreateNode(x);
				node* r = temp->prev;
				temp->prev = q; q->next = temp;
				q->prev = r; r->next = q;
			}
			temp = temp->next;

		}
	}
}
void DeleteAtHead(list& l, int n) {
	if (l.head == NULL) {
		cout << "\nList is Empty !" << endl;
		return;
	}
	//l.head = l.head->next;
	//l.head->prev = NULL;
	if (n == 1) {
		node* q = l.head;
		delete q;
	}
	else {
		node* p = l.head; // node p là node sẽ xóa
		l.head = l.head->next; // cập nhật lại l.head là phần tử kế tiếp
		l.head->prev = NULL;
		delete p;
	}
}
void DeleteAtTail(list& l, int n) {
	if (l.head == NULL) {
		return;
	}
	//l.tail = l.tail->prev;
	//l.tail->next = NULL;
	if (n == 1) {
		node* q = l.head;
		delete q;
	}
	else {
		node* p = l.tail;
		l.tail = l.tail->prev;
		l.tail->next = NULL;
		delete p;
	}
}
// Hàm xóa 1 node sau 1 node:
void DeleteNodeAfterNode(list& l, int x, int n) {
	search(l, x);
	if (l.tail->prev->data == x) {
		DeleteAtTail(l, n);
	}
	for (node* k = l.head; k->next != l.tail; k = k->next) {
		if (k->data == x) {
			node* g = k->next; g->prev = k;
			k->next = g->next; g->next->prev = k;
			delete g;
		}
	}
}
// Hàm xóa 1 node trước 1 node:
void  DeleteNodeBeforeNode(list& l, int x, int n) {
	search(l, x);
	if (l.head->next->data == x) {
		DeleteAtHead(l, n);
	}
	for (node* k = l.head->next->next; k != NULL; k = k->next) {
		if (k->data == x) {
			node* h = k->prev; h->next = k;
			k->prev = h->prev; h->prev->next = k;
			delete h;
		}
	}
}
// Hàm xóa 1 cái node có vị trí bất kỳ
void DeleteNode_place(list& l, int place, int n) {
	// Nếu list rỗng thì không làm gì hết
	if (!l.head) {
		cout << "\nList is Empty !";
		return;
	}

	// Nếu node cần xóa nằm ở đầu danh sách
	if (place == 1)
	{
		DeleteAtHead(l, n);
		return;
	}
	// Nếu node cần xóa nằm ở cuối danh sách
	if (place == n)
	{
		DeleteAtTail(l, n);
		return;
	}
	else {
		int dem = 0;
		if (l.head != NULL) {
			node* p = l.head;
			node* q = new node;
			while (p != NULL) { // tim node thu k.
				dem++;
				q = p;
				if (dem == place) break; // tim thay thi break
				else p = p->next; // k thi tim tiep
			}
			node* r = l.head;
			while (r->next != q) r = r->next; // tim node k-1
			r->next = q->next; // cho node next cua node k-1 tro toi node k+1;
			q->next->prev = r;
			delete q;
		}
	}
}
// Hàm xóa node có giá trị bất kỳ (Nếu có nhiều node cùng giá trị thì phải xóa lần lượt)
void DeleteNode_value(list& l, int x, int n) {
	search(l, x);
	// Nếu list rỗng thì không làm gì hết
	if (!l.head) {
		return;
	}
	// Nếu node cần xóa nằm ở đầu danh sách
	if (l.head->data == x)
	{
		DeleteAtHead(l, n);
	}
	// Nếu node cần xóa nằm ở cuối danh sách
	if (l.tail->data == x)
	{
		DeleteAtTail(l, n);
	}
	// Duyệt danh sách để tìm
	node* p = l.head;
	node* q = new node;
	while (p != NULL) { // tim node thu k.
		q = p;
		if (p->data == x) break; // tim thay thi break
		else p = p->next; // k thi tim tiep
	}
	node* r = l.head;
	while (r->next != q) r = r->next; // tim node k-1
	r->next = q->next; // cho node next cua node k-1 tro toi node k+1;
	q->next->prev = r;
	delete q;

}
// Hàm xóa node có giá trị bất kỳ (Nếu có nhiều node cùng giá trị thì chỉ cần xóa 1 lần liên tiếp)
void DeleteNodes_values(list& l, int x, int n, int count) {
	for (int i = 0; i < count; i++) {
		DeleteNode_value(l, x, n);
	}
}

void Print(list& l, int n)
{
	node* temp = l.head;
	cout << "\nForward list: ";
	n = 0;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
		n++;
	}
	cout << "\nList co " << n << " phan tu " << endl;
}
void ReversePrint(list& l, int n)
{
	node* temp = l.tail;
	cout << "\nReverse List: ";
	n = 0;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
		n++;
	}
	cout << "\nList co " << n << " phan tu " << endl;
}
// Hàm đếm số phần tử trong list
void Counts(list& l) {
	int n = 0;
	node* temp = l.head;
	while (temp != NULL) {
		n++;
		temp = temp->next;
	}
	cout << "\nList co " << n << " phan tu " << endl;
}
// Hàm giải phóng bộ nhớ:
void CleanMemory(list& l)
{
	node* k = NULL;
	while (l.head != NULL)
	{
		k = l.head;
		l.head = l.head->next;
		delete k;
	}
}
// Menu
void Menu(list& l, int n) {
	int choose;
	while (true) {
		system("cls");
		cout << "\n\t\t\t==================== MENU ====================\n";
		cout << "\t\t\t1. Them node vao dau danh sach\n";
		cout << "\t\t\t2. Them node vao cuoi danh sach\n";
		cout << "\t\t\t3. Xuat danh sach lien ket kep\n";
		cout << "\t\t\t4. Them node p after node q trong danh sach\n";
		cout << "\t\t\t5. Them node p before node q trong danh sach\n";
		cout << "\t\t\t6. Them node p vao place bat ky trong danh sach\n";
		cout << "\t\t\t7. Xoa node dau\n";
		cout << "\t\t\t8. Xoa node cuoi\n";
		cout << "\t\t\t9. Xoa node sau node q\n";
		cout << "\t\t\t10.Xoa node truoc node q\n";
		cout << "\t\t\t11.Xoa node co place bat ky trong list\n";
		cout << "\t\t\t12.Xoa node bat ky trong list\n";
		cout << "\t\t\t0. Thoat ";
		cout << "\n\t\t\t==================== END =====================\n";

		cout << "Nhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 12) {
			cout << "\nLua chon cua ban khong hop le >> Vui long nhap lai !";
			system("pause");
		}
		else if (choose == 1) {
			int x;
			cout << "\nInput: ";
			cin >> x;
			InsertAtHead(l, x);
			Counts(l);
		}
		else if (choose == 2) {
			int x;
			cout << "\nInput: ";
			cin >> x;
			InsertAtTail(l, x);
			Counts(l);
		}
		else if (choose == 3) {
			Print(l, n);
			system("pause");
		}
		else if (choose == 4)
		{
			int k;
			cout << "\nNhap gia tri node trong list k =  ";
			cin >> k;
			int x;
			cout << "\nNhap gia tri node muon chen: ";
			cin >> x;
			addsAfter(l, x, k);
			system("pause");
		}
		else if (choose == 5)
		{
			int k;
			cout << "\nNhap gia tri node trong list k =  ";
			cin >> k;
			int x;
			cout << "\nNhap gia tri node muon chen: ";
			cin >> x;
			addsBefore(l, x, k);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else if (choose == 6)
		{
			int n = 0;
			node* temp = l.head;
			while (temp != NULL) {
				n++;
				temp = temp->next;
			}
			int x;
			cout << "\nNhap phan tu ban muon chen: ";
			cin >> x;
			int place;
			cout << "\nNhap vi tri ban muon chen: ";
			cin >> place;
			addNode_k(l, x, place, n);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else if (choose == 7) {
			DeleteAtHead(l, n);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else if (choose == 8) {
			DeleteAtTail(l, n);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else if (choose == 9) {
			int x;
			cout << "\nXoa node sau node p !";
			cout << "\nNhap node p: ";
			cin >> x;
			DeleteNodeAfterNode(l, x, n);
			system("pause");
		}
		else if (choose == 10) {
			int x;
			cout << "\nXoa node truoc node p !";
			cout << "\nNhap node p: ";
			cin >> x;
			DeleteNodeBeforeNode(l, x, n);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else if (choose == 11)
		{

			int n = 0;
			node* temp = l.head;
			while (temp != NULL) {
				n++;
				temp = temp->next;
			}
			int place;
			cout << "\nNhap vi tri ban muon xoa: ";
			cin >> place;
			DeleteNode_place(l, place, n);
			system("pause");
		}
		else if (choose == 12) {
			int x;
			cout << "\nNhap gia tri node ban muon xoa: ";
			cin >> x;
			int count = 0;
			for (node* k = l.head; k != NULL; k = k->next) {
				if (k->data == x) {
					count++;
				}
			}
			cout << "\nCo " << count << " gia tri " << x << " trong list !" << endl;
			DeleteNodes_values(l, x, n, count);
			Counts(l);
			cout << "\nList co " << n << " phan tu " << endl;
			system("pause");
		}
		else
		{
			CleanMemory(l); // Xóa bộ nhớ
			break; // Thoát khỏi vòng lặp hiện tại
		}
	}
}
int main()
{
	int n;

	list l;

	CreateList(l);

	Menu(l, n);

	system("pause");
	return 0;
}
