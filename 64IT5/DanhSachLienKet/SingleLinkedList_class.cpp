#include <iostream>
using namespace std;

// Bài toán: Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị max trong danh sách

// ========================= KHAI BÁO DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN =======================
// Khai báo cấu trúc 1 cái Node
class NODE{
public:
	int data; // dữ liệu chứa trong 1 cái node
	NODE* pNext; // Con trỏ liên kết giữa các node vs nhau
};

// Khai báo danh sách 
class LIST {
public:
	NODE* pHead; // node quản lý đầu danh sách
	NODE* pTail; // node quản lý cuối danh sách
};

// ============ KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ============
void KhoiTao(LIST& l) {
	// Cho 2 node trỏ đến NULL - Vì danh sách liên kết đơn chưa có phần tử
	l.pHead = NULL;
	l.pTail = NULL;
}

// Hàm khởi tạo 1 cái node
NODE* KhoiTaoNODE(int x) {
	NODE* p = new NODE; // cấp phát vùng nhớ cho NODE p
	if (! p)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyền giá trị x vào cho data
	p->pNext = NULL; // Đầu tiên khai báo node thì node đó chưa có liên kết đến node nào hết ===> con trỏ của nó sẽ trỏ đến NULL

	return p; // Trả về NODE p vừa khởi tạo
}

// Hàm thêm node p vào đầu danh sách liên kết
void ThemVaoDau(LIST& l, NODE* p) {
	// Danh sách đang rỗng
	if (! l.pHead)
	{
		l.pHead = l.pTail = p; // node đầu cx là node cuối và là p
	}
	else {
		p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kết đến node đầu - pHead
		l.pHead = p; // Cập nhật lại pHead chính là node p
	}
}

// Hàm thêm node p vào cuối danh sách liên kết
void ThemVaoCuoi(LIST& l, NODE* p) {
	// Danh sách đang rỗng
	if (! l.pHead)
	{
		l.pHead = l.pTail = p; // node đầu cx là node cuối và là p
	}
	else {
		l.pTail->pNext = p; // Cho con trỏ của pTail liên kết vs node p
		l.pTail = p; // Cập nhật lại p là node pTail
	}
}
// Hàm xuất danh sách liên kết
// Phải duyệt từ đầu danh sách đến cuối danh sách
void Xuat_Danh_Sach(LIST l) {
	//{ for(int i=0; i<n; i++) - Đối với mảng }
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
	cout << endl;
}
// Hàm tìm giá trị max trong danh sách liên kết đơn
int TimMax(LIST l) {
	int max = l.pHead->data; // giả sử node đầu là node max
	for (NODE* k = l.pHead->pNext; k != NULL; k = k->pNext) {
		if (max < k->data) {
			max = k->data; // Cập nhật lại giá trị
		}
	}
	return max;

}
int main() {
	LIST l;
	KhoiTao(l); // Khởi tạo danh sách liên kết đơn

	int n;
	cout << "\nNhap so luong node can them : ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nNhap gia tri so nguyen thu " << i << ": ";
		cin >> x;
		NODE* p = KhoiTaoNODE(x); // Khởi tạo 1 cái node số nguyên
		ThemVaoCuoi(l, p); // Thêm vào cuối danh sách liên kết đơn
	}

	cout << "\n\n\t\t\t DANH SACH LIEN KET DON\n";
	Xuat_Danh_Sach(l);

	cout << "\n\n\t\t\t GIA TRI LON NHAT : " << TimMax(l) << endl;

	system("pause");

	return 0;
}