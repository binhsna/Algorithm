#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
// Khai báo student'class
class student
{
public:
	string name;
	string maso;
	float diem_KTLT;
	float diem_TRR;
	float diem_CTDL_GT;
};
// Hàm nhập thông tin 1 sinh viên
void InputInfo(student& sv) 
{
	while (getchar() != '\n'); // Xóa bộ nhớ đệm
	// Điều kiện nhập mã số
	do 
	{
		cout << "\nNhap ma so sinh vien: ";
		getline(cin, sv.maso);
		if (sv.maso.length() > 20) {
			cout << "\nDo dai khong hop le !";
			system("pause");
		}
	} while (sv.name.length() > 20);
	// Điều kiện nhập điểm
	do
	{
		cout << "\nNhap ho ten sinh vien: ";
		getline(cin, sv.name);
		if (sv.name.length() > 30) {
			cout << "\nDo dai khong hop le !";
			system("pause");
		}
	} while (sv.name.length() > 30);
	// Điều kiện nhập điểm
	do {
		cout << "\nNhap diem KTLT: ";
		cin >> sv.diem_KTLT;
		if (sv.diem_KTLT < 0 || sv.diem_KTLT > 10) {
			cout << "\nDiem khong hop le -> Vui long nhap lai !";
			system("pause");
		}
	} while (sv.diem_KTLT < 0 || sv.diem_KTLT > 10);
	do {
		cout << "\nNhap diem CTDL_GT: ";
		cin >> sv.diem_CTDL_GT;
		if (sv.diem_CTDL_GT < 0 || sv.diem_CTDL_GT > 10) {
			cout << "\nDiem khong hop le -> Vui long nhap lai !";
			system("pause");
		}
	} while (sv.diem_CTDL_GT < 0 || sv.diem_CTDL_GT > 10);
	do {
		cout << "\nNhap diem TRR: ";
		cin >> sv.diem_TRR;
		if (sv.diem_TRR < 0 || sv.diem_TRR > 10) {
			cout << "\nDiem khong hop le -> Vui long nhap lai !";
			system("pause");
		}
	} while (sv.diem_TRR < 0 || sv.diem_TRR > 10);

}
// Hàm xuất danh sách sinh viên
void ShowInfo(student& sv) {
	cout << "\nName: " << sv.name;
	cout << "\nMSSV: " << sv.maso;
	cout << "\nDiem ky thuat lap trinh: " << sv.diem_KTLT;
	cout << "\nDiem CSDL_GT: " << sv.diem_CTDL_GT;
	cout << "\nDiem toan roi rac: " << sv.diem_TRR;
	cout << endl;
}
// Khai báo class student list
class list
{
public:
	// theo con trỏ
	student* ds[100]; // Khai báo mảng 1 chiều các con trỏ sinh viên
	int n;
};
// function show  student list
void ShowList_sv(list& l) {
	for (size_t i = 0; i < l.n; i++)
	{
		cout << "\n\t\t\t INFORMATION STUDENT IS NUMBER " << i + 1;
		ShowInfo(*l.ds[i]);
	}
}
// function manager student list
void Menu(list& l) 
{
	int choose;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\ ============ QUAN LY SINH VIEN ============\n";
		cout << "\n\t\t\t1. Nhap thong tin sinh vien";
		cout << "\n\t\t\t2. Xuat danh sach sinh vien";
		cout << "\n\t\t\t0. thoat !";
		cout << "\n\t\t\ =================== END ===================\n";

		cout << "\nNhap lua chon: ";
		cin >> choose;

		if (choose < 0 || choose > 2)
		{
			cout << "\nLua chon cua ban khong hop le -> Vui long nhap lai !" << endl;
			system("pause");
		}
		else if(choose == 1)
		{
			student* sv = new student;
			InputInfo(*sv);
			l.ds[l.n] = sv; // Thêm sinh viên sv vào list
			l.n++;
		}
		else if (choose == 2) 
		{
			cout << "\n\t\t\t\t\t LIST OF STUDENTS\n";
			ShowList_sv(l);
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
	list l;

	l.n = 0;
	
	Menu(l);

	// Giải phóng bộ nhớ
	for (int i = 0; i < l.n; i++)
	{
		delete l.ds[i];
	}
	ShowList_sv(l);

	system("pause");
	return 0;
}