#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

/*
					Lập 1 (danh sách liên kết kép) các số nguyên (double linked list):
*/
// Cấu trúc của 1 cái node:
class node
{
public:
	int data; // dữ liệu truyền vào trong trường hợp này là số nguyên:
	node* next; // Con trỏ xuôi
	node* prev; // Con trỏ ngược 
};
// Cấu trúc của 1 danh sách liên kết:
class list
{
public:
	node* head; // Con trỏ đầu
	node* tail; // Con trỏ cuối
};
// Bắt buộc phải có hàm khởi tạo node:
node* CreateNode(int x)
{
	node* p = new node;
	if (p == NULL) exit(1);
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
// Bắt buộc phải có hàm khởi tạo 1 danh sách (list):
void CreateList(list& l)
{
	l.head = NULL;
	l.tail = NULL;
}
// Hàm chèn phần tử mới vào vị trí đầu tiên của list:
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
// Hàm chèn phần tử mới vào vị trí cuối của list:
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
// Hàm tìm kiếm giá trị node (kiểm tra 1 phần tử có trong list ?)
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
// Hàm xóa phần tử đầu tiên:
void DeleteAtHead(list& l) {
	if (l.head == NULL) {
		return;
	}
	else if (l.head->next == NULL) {
		l.head = NULL;
	}
	else {
		l.head = l.head->next;
		l.head->prev = NULL;
	}
}
// Hàm xóa phần tử cuối:
void DeleteAtTail(list& l) {
	if (l.head == NULL) {
		return;
	}
	else if (l.head->next == NULL) {
		l.head = NULL;
	}
	else {
		l.tail = l.tail->prev;
		l.tail->next = NULL;
	}
}
// Hàm xóa 1 node sau 1 node:
void DeleteNodeAfterNode(list& l, int x) {
	search(l, x);
	// list rỗng
	if (!l.head) {
		exit(1);
	}
	// Xét danh sách từ node đầu đến node cuối
	for (node* k = l.head; k != NULL; k = k->next) {
		if (k->data == x && k->next->next != NULL) {
			// x nằm ở vị trí cách phần tử cuối 1 phần tử trở lên
			node* g = k->next; g->prev = k;
			k->next = g->next; g->next->prev = k;
			delete g;
			return; // xóa nhiều node thì bỏ return;
		}
		if (k->data == x && k->next->next == NULL) {
			// x nằm ở vị trí kế cuối
			DeleteAtTail(l);
			return; 
		}
	}
}
// Hàm xóa giá trị của node trước node mang giá trị x (phải chia TH và phải thực hiện)
void  DeleteNodeBeforeNode(list& l, int x) {
	search(l, x);
	// list rỗng
	if (!l.head) {
		exit(1);
	}
	for (node* k = l.tail; k != NULL; k = k->prev) {
		if (k->data == x && k->prev->prev != NULL) {
			// x nằm từ vị trí thứ 3 trở đi
			node* h = k->prev; h->next = k;
			k->prev = h->prev; h->prev->next = k;
			delete h;
			return; // xóa nhiều node thì bỏ return;
		}
		if (k->data == x && k->prev->prev == NULL) {
			// x nằm ở vị trí thứ 2
			DeleteAtHead(l);
			return;
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
		DeleteAtHead(l);
		return;
	}
	// Nếu node cần xóa nằm ở cuối danh sách
	if (place == n)
	{
		DeleteAtTail(l);
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
void DeleteNode_value(list& l, int x) {
	search(l, x);
	// Nếu list rỗng thì không làm gì hết
	if (!l.head) {
		return;
	}
	// Nếu node cần xóa nằm ở đầu danh sách
	else if (l.head->data == x)
	{
		DeleteAtHead(l);
	}
	// Nếu node cần xóa nằm ở cuối danh sách
	else if (l.tail->data == x)
	{
		DeleteAtTail(l);
	}
	else {
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
}
// Hàm xóa node có giá trị bất kỳ (Nếu có nhiều node cùng giá trị thì chỉ cần xóa 1 lần liên tiếp)
void DeleteNodes_values(list& l, int x, int n) {
	for (int i = 0; i < n; i++) {
		DeleteNode_value(l, x);
	}
}
// Hàm in ra màn hình theo chiều xuôi (danh sách xuôi):
void Print(list& l)
{
	node* temp = l.head;
	cout << "\nForward list: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
// Hàm In ra màn hình theo chiều ngược (danh sách ngược):
void ReversePrint(list& l)
{
	node* temp = l.tail;
	cout << "\nReverse List: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
		cout << endl;
	}
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
void Menu(list& l) {
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
		cout << "\t\t\t12.Xoa node co gia tri bat ky trong list\n";
		cout << "\t\t\t13.Clean Memory \n";
		cout << "\t\t\t0. Thoat ";
		cout << "\n\t\t\t==================== END =====================\n";

		cout << "Nhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 13) {
			cout << "\nLua chon cua ban khong hop le >> Vui long nhap lai !";
			system("pause");
		}
		else if (choose == 1) {
			int x;
			cout << "\nInput: ";
			cin >> x;
			InsertAtHead(l, x);
		}
		else if (choose == 2) {
			int x;
			cout << "\nInput: ";
			cin >> x;
			InsertAtTail(l, x);
		}
		else if (choose == 3) {
			int n = 0;
			node* temp = l.head;
			while (temp != NULL) {
				n++;
				temp = temp->next;
			}
			cout << "\nSo phan tu cua list la: " << n << endl;
			Print(l);
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
			system("pause");
		}
		else if (choose == 7) {
			DeleteAtHead(l);
			system("pause");
		}
		else if (choose == 8) {
			DeleteAtTail(l);
			system("pause");
		}
		else if (choose == 9) {
			int x;
			cout << "\nXoa node sau node p !";
			cout << "\nNhap node p: ";
			cin >> x;
			int n = 0;
			for (node* k = l.head; k != NULL; k = k->next) {
				if (k->data == x) {
					n++;
				}
			}
			cout << "\nCo " << n << " gia tri " << x << " trong list !" << endl;
			DeleteNodeAfterNode(l, x);
			system("pause");
		}
		else if (choose == 10) {
			int x;
			cout << "\nXoa node truoc node p !";
			cout << "\nNhap node p: ";
			cin >> x;
			int n = 0;
			for (node* k = l.head; k != NULL; k = k->next) {
				if (k->data == x) {
					n++;
				}
			}
			cout << "\nCo " << n << " gia tri " << x << " trong list !" << endl;
			DeleteNodeBeforeNode(l, x);
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
			int n = 0;
			for (node* k = l.head; k != NULL; k = k->next) {
				if (k->data == x) {
					n++;
				}
			}
			cout << "\nCo " << n << " gia tri " << x << " trong list !" << endl;
			DeleteNodes_values(l, x, n);
			system("pause");
		}
		else if (choose == 13) {

		CleanMemory(l); // Xóa bộ nhớ để ta thực hiện luôn thao tác mới trong Menu
}
		else
		{
			CleanMemory(l); // Xóa bộ nhớ xong thục hiện break; để thoát chương trình
			break; // Thoát khỏi vòng lặp while
		}
	}
}
int main()
{
	list l;

	CreateList(l);

	Menu(l);

	system("pause");
	return 0;
}
