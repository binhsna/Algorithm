#include <iostream>
using namespace std;
/*
	In danh sách các số nguyên số nguyên bằng double linked list
*/
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
// Hàm khởi tạo 1 cái node
node* CreateNode(int x) {
	node* p = new node;
	if (p == NULL) {
		exit(1);
	}
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return p;
}
// Hàm khởi tạo 1 list
void CreateList(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
// Hàm chèn phần tử lên đầu list
void InsertAtHead(list& l, int x) {
	node* p = CreateNode(x);
	if (l.head == NULL) {
		l.head = p; l.tail = p;
		return;
	}
	l.head->prev = p;
	p->next = l.head;
	l.head = p;
}
// Hàm chèn phần tử vào cuối
void InsertAtTail(list& l, int x) {
	node* p = CreateNode(x);
	if (l.head == NULL) {
		l.head = p; l.tail = p;
		return;
	}
	l.tail->next = p;
	p->prev = l.tail;
	l.tail = p;
}
// Hàm xóa giá trị node đầu:
void DeleteAtHeal(list& l, int n) {
	Counts(l);
	if (l.head == NULL) {
		cout << "\nList is Empty !\n";
		return;
	}
	if (n == 1) { // list có 1 phần tử
		node* g = l.head;
		delete g;
	}
	else {
		node* p = l.head;
		l.head = l.head->next;
		l.head->prev = NULL;

		delete p;
	}

}
// Hàm đếm số phần tử
void Counts(list& l) {
	int n = 0;
	for (node* k = l.head; k != NULL; k = k->next) {
		n++;
	}
}
// Hàm xuất danh sách
void Print(list& l) {
	int n = 0;
	node* temp = l.head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
		n++;
	}
	cout << "\nNow list has " << n << " numbers";
	cout << endl;
	// Cách 2: 
	// for(node* k=l.head; k!=NULL; k=k->next){
	//		cout<<k->data<<" ";
	// }
}
// Hàm giải phóng con trỏ
void Clean(list& l) {
	node* p = NULL;
	while (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
// Hàm Menu
void Menu(list& l) {
	int choose;
	while (true) {
		system("cls");
		cout << "\n\t\t\t ============== Menu ==============\n";
		cout << "\n\t\t\t1. Chen phan tu vao dau \n";
		cout << "\t\t\t2. Chen phan tu vao cuoi \n";
		cout << "\t\t\t3. Xuat ra cac phan tu \n";
		cout << "\t\t\t4. Xoa phan tu dau cua list \n";
		cout << "\t\t\t0. Thoat khoi Menu !\n";
		cout << "\n\t\t\t ============== End ===============\n";

		cout << "\nNhap lua chon cua ban: ";
		cin >> choose;
		if (choose < 0 || choose > 4) {
			cout << "\nLua chon cua ban sai -> vui long nhap lai !";
			return;
		}
		else if (choose == 1) {
			int x;
			cout << "\nNhap so nguyen x = ";
			cin >> x;
			InsertAtHead(l, x);
		}
		else if (choose == 2) {
			int x;
			cout << "\nNhap so nguyen x = ";
			cin >> x;
			InsertAtTail(l, x);
		}
		else if (choose == 3) {
			cout << "\nDanh sach cac so nguyen: \n";
			Print(l);
			system("pause");
		}
		else if (choose == 4) {
			int n;
			DeleteAtHeal(l,n);
		}
		else {
			Clean(l);
			break;
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