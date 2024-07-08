#include <iostream>

#include <string>

#include <conio.h>

using namespace std;

class HoSoSinhVien {



public:

	string mssv;	// Ma so sinh vien

	string hoten;	// Ho va ten cua sinh vien

	string email;	// Dia chi Email cua sinh vien

	string sdt;		// So dien thoai cua sinh vien



};

#define MAX_N_SINH_VIEN 100





HoSoSinhVien lop64TH1[MAX_N_SINH_VIEN];

int soSinhVien = 5;





void Nhap_Danh_Sach_Sinh_Vien()

{

	for (int i = 0; i < soSinhVien; i++)

	{

		cout << "\n\n\t\t NHAP THONG TIN SINH VIEN THU " << i + 1<<endl;

	

	//while (getchar() != '\n');

	cout << "\nNhap ma so sinh vien: ";

	getline(cin, lop64TH1[i].mssv);

	cout << "\nNhap ho ten sinh vien: ";

	getline(cin, lop64TH1[i].hoten);

	cout << "\nEmail: ";

	getline(cin,lop64TH1[i].email);

	cout << "\nSDT: ";

	getline(cin,lop64TH1[i].sdt);			

	}

}

int main( )



{

	 Nhap_Danh_Sach_Sinh_Vien();

	



cout << lop64TH1[4].sdt << endl;



return 0;



}
