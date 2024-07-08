#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class date
{
public:
	int day;
	int month;
	int year;
};
void InputDate(date& d)
{
	cout << "Nhap ngay sinh: ";
	cin >> d.day;
	cout << "Nhap thang sinh: ";
	cin >> d.month;
	cout << "Nhap nam sinh: ";
	cin >> d.year;
}
class student
{
public:
	string name;
	string mssv;
	date dat;
	float math_tb;
};
void InputInfo(student& sv)
{
	while (getchar() != '\n');
	cout << "Name: ";
	getline(cin, sv.name);
	InputDate(sv.dat);
	cin.ignore();
	cout << "Mssv: ";
	getline(cin, sv.mssv);
	cout << "Diem trung binh: ";
	cin >> sv.math_tb;
}
void ShowInfo(student& sv)
{
	cout << "\nName: " << sv.name;
	cout << "\nMssv: " << sv.mssv;
	cout << "\nDate: " << sv.dat.day << "/" << sv.dat.month << "/" << sv.dat.year;
	cout << "\nDiem trung binh: " << sv.math_tb;
	cout << endl;
}
class node
{
public:
	student data;
	node* next;
};
class queue
{
public:
	node* head;
	node* tail;
};
node* createNode(student x)
{
	node* p = new node;
	if (p == NULL)
	{
		cout << "\nEnroll";
		return NULL;
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}
void createQueue(queue& qe)
{
	qe.head = NULL;
	qe.tail = NULL;
}
// Hàm kiểm tra Queue rỗng ?
bool IsEmpty(queue& qe)
{
	if (qe.head == NULL)
	{
		cout << "\nQueue is Empty !";
		return true;
	}
	else {
		return false;
	}
}
// Hàm enQueue : Là hàm thêm vào cuối
void enQueue(queue& qe, node* p)
{
	if (IsEmpty(qe) == true)
	{
		qe.head = qe.tail = p;
	}
	else {
		// Thêm vào cuối
		qe.tail->next = p;
		qe.tail = p;
	}
}
// Hàm deQueue: Là hàm xóa giá trị đầu
void deQueue(queue& qe) {
	if (IsEmpty(qe) == true) {
		cout << "\nQueue is Empty !";
	}
	else {
		node* p = qe.head;
		qe.head = qe.head->next;
		delete p;
	}
}
// Hàm Front lấy và in ra giá trị đầu
void Front(queue& qe)
{
	if (IsEmpty(qe) == true) {
		cout << "\nQueue is Empty !";
	}
	else {
		ShowInfo(qe.head->data);
	}
}
// Hàm xuất Queue:
void ShowQueue_sv(queue& qe)
{
	int count = 1;
	for (node* k = qe.head; k != NULL; k = k->next)
	{
		cout << "\n\t\t\t SINH VIEN THU " << count++;
		ShowInfo(k->data);
	}
	cout << endl;
}
// Hàm giải phóng bộ nhớ
void CleanQueue(queue& qe)
{
	node* k = NULL;
	while (qe.head != NULL)
	{
		k = qe.head;
		qe.head = qe.head->next;
		delete k;
	}
}
// Hiển thị menu
void Menu(queue& qe)
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t================ MENU ================\n";
		cout << "\n\t\t\t1. Them student vao Queue";
		cout << "\n\t\t\t2. Xuat ra Queue";
		cout << "\n\t\t\t3. student dau tien Queue: ";
		cout << "\n\t\t\t4. Delete student dau Queue";
		cout << "\n\t\t\t0. Exit Menu !";
		cout << "\n\n\t\t\t================ END =================\n";

		cout << "\nVui long nhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 4) {
			cout << "\nEnroll -> Nhap lai lua chon cua ban !";
		}
		else if (choose == 1)
		{
			student sv;
			InputInfo(sv);
			node* p = createNode(sv);
			enQueue(qe, p);
		}
		else if (choose == 2)
		{
			ShowQueue_sv(qe);
			system("pause");
		}
		else if (choose == 3)
		{
			cout << "\nStudent dau tien trong Queue: ";
			Front(qe);
			system("pause");
		}
		else if (choose == 4)
		{
			deQueue(qe);
		}
		else
		{
			CleanQueue(qe);
			ShowQueue_sv(qe);
			system("pause");
			break;
		}
	}
}
int main()
{
	queue qe;

	createQueue(qe);

	Menu(qe);

	system("pause");
	return 0;
}