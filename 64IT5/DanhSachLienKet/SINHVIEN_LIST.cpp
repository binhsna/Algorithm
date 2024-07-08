
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class date
{
public:
	int day;
	int month;
	int year;
};
// Hàm đọc ngày tháng năm từ file
void ReadDate(ifstream& filein, date& d) {
	filein >> d.day;
	filein.seekg(1, 1); // Dịch sang phải 1 bye để bỏ qua ký tự '/'
	filein >> d.month;
	filein.seekg(1, 1); // Dịch sang phải 1 bye để bỏ qua ký tự '/'
	filein >> d.year;
	filein.seekg(1, 1); // Dịch sang phải 1 bye để bỏ qua ký tự '/'
}
class student
{
public:
	string name;
	string mssv;
	date daybirth;
	float mathTB;
};
// Khai báo cấu trúc 1 cái node sinh viên
class node {
public:
	student data;
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
node* KhoiTaoNode(student x) {
	node* p = new node;
	if (!p) {
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
// Hàm thêm node sinh viên vào đầu danh sách:
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
// Hàm đọc dữ liệu sinh viên từ file
void read_Info_SV(ifstream& filein, student& sv) {
	// Đọc họ tên sinh viên
	getline(filein, sv.name, ',');
	filein.seekg(1, 1); // Dịch 1 bye để bỏ qua khoảng trắng
	// Đọc mssv
	getline(filein, sv.mssv, ',');
	filein.seekg(1, 1); // Dịch 1 bye để bỏ qua khoảng trắng
	// Đọc thông tin date
	ReadDate(filein, sv.daybirth);
	filein.seekg(1, 1); // Dịch 2 bye để bỏ qua ',' và khoảng trắng
	// Đọc điểm trung bình
	filein >> sv.mathTB;

	// Tạo biến tạm để đọc ký tự xuống  dòng
	string temp;
	getline(filein, temp);
}
// Hàm đọc danh sách sinh viên từ file
void Read_Info_List_SV(ifstream& filein, list& l)
{
	// Đọc đến cuối  file thì dừng
	while (!filein.eof())
	{
		// Bước 1. Đọc thông tin sinh viên
		student sv;
		read_Info_SV(filein, sv);
		// Bước 2. Khởi tạo 1 cái node sinh viên
		node* p = KhoiTaoNode(sv);
		// Bước 3. Thêm sinh viên (thêm node p) vào danh sách sinh viên
		InsertLast(l, p);
	}
}
// Hàm giải phóng vùng nhớ cho single linked list
void DeleteMemory(list& l)
{
	node* p = NULL;
	while (l.head != NULL)
	{
		p = l.head;
		l.head = l.head->next;
		delete p;
	}
}
// Hàm ghi thông tin sinh viên vào file
void Write_Info_SV(ofstream& fileout, student sv) {
	// GHi họ tên sinh viên
	fileout << sv.name << ", ";
	fileout << sv.mssv << ", ";
	fileout << sv.daybirth.day << "/" << sv.daybirth.month << "/" << sv.daybirth.year << ", ";
	fileout << sv.mathTB;
}

// Hàm hoán vị 2 sinh viên:
void HoanVi(student& x, student& y) {
	student temp;
	temp = x;
	x = y;
	y = temp;
}
// Hàm sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
void SortIncreat_math(list& l)
{
	for (node* k = l.head; k != NULL; k = k->next) {
		for (node* h = k->next; h != NULL; h = h->next) {
			if (k->data.mathTB > h->data.mathTB) 
			{
				HoanVi(k->data, h->data);
			}
		}
	}
}
// Ghi dữ liệu vào file
void Save_MathTB_Info_To_File(list l) {
	ofstream fileout;
	fileout.open("SAPXEPDIEMMAX.TXT", ios_base::out);
	SortIncreat_math(l);
	// Dùng vòng lặp để lưu tất cả thông tin sinh viên 
	for (node* k = l.head; k != NULL; k = k->next)
	{
		Write_Info_SV(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}
// Hàm in danh sách sinh viên có điểm trung bình max vào file
void Save_MathTB_Max_To_File(list l) 
{
	float max = l.head->data.mathTB;
	// Bước 1. Tìm ra điểm trung bình max
	for (node* k = l.head->next; k != NULL; k = k->next)
	{
		if (max < k->data.mathTB)
		{
			max = k->data.mathTB;
		}
	}
	ofstream fileout;
	fileout.open("DIEMTRUNGBINHMAX.TXT", ios_base::out);
	// Bước 2. Tìm các sinh viên có điểm trung bình cao nhất và ghi vào file
	for (node* k = l.head; k != NULL; k = k->next)
	{
		if (max == k->data.mathTB)
		{
			Write_Info_SV(fileout, k->data);
			fileout << endl;
		}
	}
	fileout.close();
}// hàm tách tên trong chuỗi họ tên
string Ten_Sinh_Vien(string tensv)
{
	// BƯỚC 1: Duyệt họ tên sinh viên từ cuối chuỗi về đầu chuỗi - nếu gặp kí tự khoảng trắng thì dừng và lấy cái vị trí tiếp theo để cắt chuỗi
	int length = tensv.length();
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		if (tensv[i] == ' ')
		{
			break;
		}
	}
	// BƯỚC 2: cắt chuỗi tại vị trí i + 1 về đến cuối chuỗi
	return tensv.substr(i + 1);

}


// hàm xuất để test dữ liệu
void Show(student sv) {
	cout << "\nHo ten: " << sv.name;
	cout << "\nMa sinh vien: " << sv.mssv;
	cout << "\nNgay sinh: " << sv.daybirth.day << "/" << sv.daybirth.month << "/" << sv.daybirth.year;
	cout << "\nDiem trung binh: " << sv.mathTB << endl;
}
// Hàm xuất danh sách sinh viên
void Show_list_sv(list l) {
	int count = 1;
	for (node* k = l.head; k != NULL; k = k->next) 
	{
		cout << "\n\t\t\t SINH VIEN THU " << count++;
		Show(k->data);
	}
}
// hàm tìm kiếm sinh viên dựa vào tên sinh viên
void Tim_Kiem_Sinh_Vien_Dua_Vao_Ten(list l, string tensv)
{
	for (node* k = l.head; k != NULL; k = k->next)
	{
		// BƯỚC 1: Cắt cái tên trong chuỗi họ tên của sinh viên
		string ten = Ten_Sinh_Vien(k->data.name);
		if (_stricmp((char*)ten.c_str(), (char*)tensv.c_str()) == 0)
		{
			Show(k->data);
			cout << endl << endl;
		}
	}
}
int main()
{

	list l;
	KhoiTaoDSLK(l);

	ifstream filein;
	filein.open("SINHVIEN1.TXT", ios_base::in);

	
	Read_Info_List_SV(filein, l);
	Show_list_sv(l);

	//Save_MathTB_Info_To_File(l);
	Save_MathTB_Max_To_File(l);


	string tensv;
	cout << "\nNhap ho ten sinh vien can tim kiem: ";
	getline(cin, tensv);

	Tim_Kiem_Sinh_Vien_Dua_Vao_Ten(l, tensv);

	DeleteMemory(l);

	filein.close();
	system("pause");
	return 0;
}