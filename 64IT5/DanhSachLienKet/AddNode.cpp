#include <iostream>
using namespace std;
int n = 0; // Khai báo biến toàn cục - chứa số lượng phần tử trong danh sách
// Thêm node p vào trước node q
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
	if (!l.head) {
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
void AddNodeAfterOtherNode(list& l, node* p) 
{
	int x;
	cout << "\nMhap gia tri node q: ";
	cin >> x;
	node* q = KhoiTaoNode(x);

	// Duyệt từ đầu danh sách đến cuối danh sách
	for (node* k = l.head; k != NULL; k = k->next) 
	{
			// Nếu node q tồn tại thì thêm node p vào sau node q
		if (q->data == k->data) 
		{
			node* h = KhoiTaoNode(p->data); // Khởi tạo node h để thêm vào sau node q
			node* g = k->next; // Cho node g trỏ đến node nằm sau node q
			h->next = g; // Bước 1. Tạo mối liên kết từ node h đến node g -> cũng chính là tạo mối liên kết node h đến node nằm sau node q
			k->next = h; // Bước 2. Tạo mối liên kết từ node q đến node h -> cũng chính là node k đến node h

		}
	}

}

// Thêm node p vào trước node q(nằm trong single linked list)
void AddNodeBeforeOtherNode(list& l, node* p) {
	int x;
	cout << "\nMhap gia tri node q: ";
	cin >> x;
	node* q = KhoiTaoNode(x);

	// TH Tổng quát: trong danh sách có thể có nhiều phần tử mang giá trị q
	node* g = new node; // node g là node giữ liên kết với cái node nằm trước node q trong danh sách
	// Duyệt từ đầu danh sách đến cuối danh sách
	for (node* k = l.head; k != NULL; k = k->next)
	{
		// Nếu node q tồn tại ở bất kỳ vị trí nào thì thêm node p vào trước node q
		if (q->data == l.head->data)
		{ // Khi node q ở vị trí đầu tiên
			InsertFirst(l, p);
		}

		if (q->data == k->data)
		{ // Khi node q ở vị trí >= 2 thì mới thực hiện được ->
			node* h = KhoiTaoNode(p->data); // Mỗi lần phát hiện 1 node p thì ta khởi tạo 1 node p mới <-> khởi tạo node h
			// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <-> thêm node p vào sau node q
			h->next = k;
			g->next = h;
		}
		g = k; // Giữ liên kết với node nằm trước node q trong danh sách
	}
}
// Hàm thêm phần tử vào vị trí bất kỳ trong danh sách liên kết
// Cách 1:
//void AddNodeToAnyPosition(list& l, node* p, int place, int n)
//{
//	// Nếu danh sách rỗng:
//	if (!l.head || place == 1) {
//		// Thêm node p vào đầu danh sách l
//		InsertFirst(l, p);
//	}
//	else if (place == n + 1) {
//		// Thêm node vào cuối danh sách
//		InsertLast(l, p);
//	}
//	else // place nằm trong đoạn [2,n]
//	{
//		int count = 0; // Xác định vị trí cần thêm
//
//		// TH Tổng quát: trong danh sách có thể có nhiều phần tử mang giá trị q
//		node* g = new node; // node g là node giữ liên kết với cái node nằm trước node q trong danh sách
//		// Duyệt từ đầu danh sách đến cuối danh sách
//		for (node* k = l.head; k != NULL; k = k->next)
//		{
//			count++;
//			// Tìm vị trí cần thêm
//
//			if (count == place)
//			{ // Khi node q ở vị trí >= 2 thì mới thực hiện được ->
//				node* h = KhoiTaoNode(p->data); // Mỗi lần phát hiện 1 node p thì ta khởi tạo 1 node p mới <-> khởi tạo node h
//				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <-> thêm node p vào sau node q
//				h->next = k;
//				g->next = h;
//				break;
//			}
//			g = k; // Giữ liên kết với node nằm trước node q trong danh sách
//		}
//	}
//}

// Cách 2: Dùng biến toàn cục cho biến n
void AddNodeToAnyPosition(list& l, node* p, int place)
{
	// Nếu danh sách rỗng:
	if (!l.head || place == 1) {
		// Thêm node p vào đầu danh sách l
		InsertFirst(l, p);
	}
	else if (place == n + 1) {
		// Thêm node vào cuối danh sách
		InsertLast(l, p);
	}
	else // place nằm trong đoạn [2,n]
	{
		int count = 0; // Xác định vị trí cần thêm

		// TH Tổng quát: trong danh sách có thể có nhiều phần tử mang giá trị q
		node* g = new node; // node g là node giữ liên kết với cái node nằm trước node q trong danh sách
		// Duyệt từ đầu danh sách đến cuối danh sách
		for (node* k = l.head; k != NULL; k = k->next)
		{
			count++;
			// Tìm vị trí cần thêm

			if (count == place)
			{ // Khi node q ở vị trí >= 2 thì mới thực hiện được ->
				node* h = KhoiTaoNode(p->data); // Mỗi lần phát hiện 1 node p thì ta khởi tạo 1 node p mới <-> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <-> thêm node p vào sau node q
				h->next = k;
				g->next = h;
				break;
			}
			g = k; // Giữ liên kết với node nằm trước node q trong danh sách
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
		cout << "\t\t\t4. Them node p before node q trong danh sach\n";
		cout << "\t\t\t5. Them node p vao place bat ky trong danh sach\n";
		cout << "\t\t\t0. Thoat ";
		cout << "\n\t\t\t==================== END =====================\n";

		cout << "Nhap lua chon: ";
		cin >> choose;
		if (choose < 0 || choose > 5) {
			cout << "\nLua chon cua ban khong hop le >> Vui long nhap lai !";
			system("pause");
		}
		else if (choose == 1) {
			n++; // Cách 2
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
		else if (choose == 4)
		{
			int x;
			cout << "\nNhap gia tri node p can them vao truoc node q: ";
			cin >> x;
			node* p = KhoiTaoNode(x);
			AddNodeBeforeOtherNode(l, p);
		}
		else if(choose == 5)
		{
			// Cách 1
			//int n = 0;
			//// Vòng lặp lấy số lượng node trong 
			//for (node* k = l.head; k != NULL; k = k->next)
			//{
			//	n++;
			//}

			// Khởi tạo giá trị cho node p
			int x;
			cout << "\nhap gia tri node p: ";
			cin >> x;
			node* p = KhoiTaoNode(x);

			// Nhập vị trí cần thêm cho node p ====> xem lại điều kiện
			int place;
			do {
				cout << "\nNhap place can them node p: ";
				cin >> place;
				if (place<1 || place > n + 1) {
					cout << "\nVi tri can them phai nam trong doan [1;" << n + 1 << "]";
				}
			} while (place <1 || place > n + 1);
			/*AddNodeToAnyPosition(l, p, place, n);*/ // Cách 1
			AddNodeToAnyPosition(l, p, place); // Cách 2
			n++;
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