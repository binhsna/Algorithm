#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
using namespace std;
// Ham tao struct Sinh 
struct Date{
	int day;
	int month;
	int year;
};
void inputDate(Date& d){
	cout<<"Nhap ngay sinh: ";
	cin>>d.day;
	while(d.day < 1 or d.day > 31){
		cout<<"Ngay ban nhap khong hop le!";
		cout<<"Vui long nhap lai ngay [1,31]: ";
		cin>>d.day;
	}
	cout<<"Nhap thang sinh: ";
	cin>>d.month;
	while(d.month < 1 or d.month > 12){
        cout << "Thang khong hop le" << endl;
        cout<<"Vui long nhap lai thang [1,12]: ";
		cin>>d.month;
	}	
	cout<<"Nhap nam sinh: ";
	cin>>d.year;
	int so_ngay;
        switch(d.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            so_ngay=31;
            break;
        case 2:
            if(d.year%400==0 ||(d.year%4==0 && d.year%100!=0)){
            so_ngay=29;
            }
            else{
            so_ngay=28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            so_ngay=30;
            break;
        }
        if(d.day > so_ngay){
			cout<<"Ngay khong hop le voi thang!"<<endl;
			cout<<"Vui long nhap lai ngay [1,"<<so_ngay<<"]"<<endl;
        	inputDate(d);
        }
}
struct student{
	string MaSV;
	string TenSV;
	Date NgaySinh;
	string GioiTinh;
	
	float DiemToan;
	float DiemLy;
	float DiemHoa;
	float DiemTB;
};
// Ham nhap thong tin cho Sinh Vien
void inputStudent(student& sv){
	while(getchar() != '\n');
	cout<<"Ma Sinh Vien: ";
	getline(cin,sv.MaSV);
	
	cout<<"Ten Sinh Vien: ";
	getline(cin,sv.TenSV);
	
	inputDate(sv.NgaySinh);
	
	cin.ignore(); // bat buoc phai co
	cout<<"Nhap gioi tinh:\n";
	cout<<"0: girl; 1: boy\n";
	cout<<"Gioi tinh: ";
	cin>>sv.GioiTinh;		
	while(sv.GioiTinh != "0" && sv.GioiTinh != "1"){
		cout<<"Gioi tinh khong hop le!";
		cout<<"Vui long nhap lai, Gioi tinh: ";
		cin>>sv.GioiTinh;
	}	
	
	// Nhap Diem of sinh vien
	cout<<"Diem Toan: "; cin>>sv.DiemToan;
	while(sv.DiemToan < 0 or sv.DiemToan > 10){
		cout<<"Diem khong hop le!";
		cout<<"Vui long nhap lai DiemToan [0,10]: ";
		cin>>sv.DiemToan;
	}
	cout<<"Diem Ly: "; cin>>sv.DiemLy;
	while(sv.DiemLy < 0 or sv.DiemLy > 10){
		cout<<"Diem khong hop le!";
		cout<<"Vui long nhap lai DiemLy [0,10]: ";
		cin>>sv.DiemLy;
	}
	cout<<"Diem Hoa: "; cin>>sv.DiemHoa;
	while(sv.DiemHoa < 0 or sv.DiemHoa > 10){
		cout<<"Diem khong hop le!";
		cout<<"Vui long nhap lai DiemHoa [0,10]: ";
		cin>>sv.DiemHoa;
	}
	
	sv.DiemTB = (sv.DiemToan + sv.DiemLy + sv.DiemHoa)/3;	
}
// Ham hien thi 1 sinh vien
void showInf(student sv){
	cout<<"\nMa Sinh vien: "<<sv.MaSV;
	cout<<"\nTen Sinh Vien: "<<sv.TenSV;
	cout<<"\nNgaySinh: "<<sv.NgaySinh.day<<"/"<<sv.NgaySinh.month<<"/"<<sv.NgaySinh.year;
	cout<<"\nGioi Tinh: "<<sv.GioiTinh;
	cout<<"\nDiem Toan: "<<sv.DiemToan;
	cout<<"\nDiem Ly: "<<sv.DiemLy;
	cout<<"\nDiem Hoa: "<<sv.DiemHoa;
	cout<<"\nDiem TB: "<<sv.DiemTB;
}
// Cau truc 1 cai Node
struct node{
	student data;
	node* next;
	node* prev;
};
struct node *head, *tail;
// Ham tao 1 node
node* CreateNode(student sv ){
	node* p = new node();
	p->data = sv;
	p->next = NULL;
	p->prev = NULL;
	
	return p;
}
// Ham chen 1 node vao dau List
void AddHead(student sv){
	node* p = CreateNode(sv);
	if(!head)	head=tail=p;
	else{
		p->next = head;
		head->prev = p;
		head = p;
	}
}
// Ham chen 1 node vao cuoi List
void AddTail(student sv){
	node* p = CreateNode(sv);
	if(!head) head=tail=p;
	else{
		tail->next = p;
		p->prev = tail;
		tail = p;
	}
}
// Ham hien thi danh sach sinh vien
void show_sv(){
	int dem=1;
	for(node* k=head; k!=NULL; k=k->next){
		cout<<"\n\t\t\t\t\tTHONG TIN SINH VIEN THU "<<dem++<<endl;
		showInf(k->data);
	}
	cout<<endl;
}
/* Ham kiem tra xem trong List Sinh Vien ? Sinh vien co Diem
TB <= [19964 % 6 +1] */
void kiemTraDiemTB(){
	int dem=0;
	int kt = (19964 % 6) + 1;
	for(node* k=head; k!=NULL; k=k->next){
		if(k->data.DiemTB <= kt){
			dem++;
		}
	}
	cout<<"Co "<<dem<<" sinh vien thoa man yeu cau !"<<endl;
}
// Ham sap xep danh sach sinh vien theo chieu tang dan cua DiemHoa
void sort_DiemHoaT(){
	for(node* k=head; k!=tail; k=k->next){
		for(node* g=k->next; g!=NULL; g=g->next){
			if(k->data.DiemHoa > g->data.DiemHoa){
				swap(k->data,g->data);
			}
		}
	}
}
// Ham giai phong bo nho
void CleanList(){
	node* k = NULL;
	while(head!=NULL){
		k=head;
		head = head->next;
		delete k;
	}
}
// Ham menu
void menu(student sv){
	int lc;
	
	do{
		system("cls");
		cout<<"1) Them Sinh Vien vao dau List.\n";
		cout<<"2) Them Sinh Vien vao cuoi List.\n";
		cout<<"3) Hien thi List Sinh Vien.\n";
		cout<<"4) Dem So Sinh Vien co DiemTB <= [19964 % 6+1].\n";
		cout<<"5) Sap xep List Sinh Vien theo DiemHoa Tang dan.\n";
		cout<<"6) Giai phong bo nho.\n";
		cout<<"0) Thoat";
		cout<<"\nLua chon cua ban: "; cin>>lc;
		
		switch(lc){
			case 0: break;
			case 1: inputStudent(sv);
					AddHead(sv); break;
			case 2: inputStudent(sv);
					AddTail(sv); break;
			case 3: show_sv();
				system("pause"); break;
			case 4: 
				kiemTraDiemTB();
				system("pause"); break;
			case 5: sort_DiemHoaT();
				system("pause");
				break;
			case 6: CleanList();
				
			default:
				cout<<"Lua chon cua ban khong hop le!";
				cout<<"\nVui long nhap lai!";
				break;
		}
	}while(lc!=0);
}
int main(){
	head=tail=NULL;
	student sv;
	menu(sv);
	return 0;
}
