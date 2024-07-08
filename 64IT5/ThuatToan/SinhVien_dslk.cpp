#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class date{
public:
	int ngay;
	int thang;
	int nam;
};
void InputDate(date& d){
	cout<<"Nhap ngay sinh: ";
	cin>>d.ngay;
	cout<<"Nhap thang sinh: ";
	cin>>d.thang;
	cout<<"Nhap nam sinh: ";
	cin>>d.nam;
}
class student{
public:
	string name;
	string mssv;
	date d;
	float dtb;	
};
void inputInfo(student& sv){
	while (getchar() != '\n');
	cout<<"Name: ";
	getline(cin,sv.name,'\n');
	//fflush(stdin);
	InputDate(sv.d);
	while (getchar() != '\n');
	cout<<"Mssv: ";
	getline(cin,sv.mssv,'\n');
	cout<<"Diem trung binh: ";
	cin>>sv.dtb;
}
void showInfo(student& sv){
	cout<<"\nName: "<<sv.name;
	cout<<"\nMssv: "<<sv.mssv;
	cout<<"\nDate: "<<sv.d.ngay<<"/"<<sv.d.thang<<"/"<<sv.d.nam;
	cout<<"\nDiem trung binh: "<<sv.dtb;
	cout<<endl;
}
struct node{
	student data;
	node* next;
};
struct node *head,*tail;
// Ham khoi tao 1 student
node* CreateNode(student sv){
	node* p = new node();
	p->data=sv;
	p->next=NULL;
	return p;
}
bool isEmpty(){
	if(!head) return true;
	return false;
}
void AddHead(student sv){
	node* p = CreateNode(sv);
	if(isEmpty()) head=tail=p;
	else{
		p->next=head;
		head=p;
	}
}
void AddTail(student sv){
	node* p = CreateNode(sv);
	if(isEmpty()) head=tail=p;
	else{
		tail->next=p;
		tail=p;
	}
}
void DeHead(){
	if(isEmpty())
		cout<<"Hien tai khong co sinh vien !";
	else {
		node* p = head;
		head = head->next;
		delete p;
		cout<<"Xoa thanh cong !";
	}
}
void DeTail(){
	if(isEmpty())
		cout<<"Hien tai khong co sinh vien !";
	else {
		for(node* k=head; k!=NULL; k=k->next){
			if(k->next==tail){
				delete tail;
				k->next = NULL;
				tail=k;
				cout<<"Xoa thanh cong !";
				return;	
			}
		}
	}
}
void showStudentList(student& sv){
	int count=1;
	for(node* k=head;k!=NULL;k=k->next){
		cout<<"\t\t\t\tSINH VIEN THU "<<count++;
		showInfo(sv);
	}
	cout<<"\n\n";
}
void cleanList(){
	node* k=NULL;
	while(head != NULL){
		k=head;
		head=head->next;
		delete k;
	}
}
void Menu(student sv){
	int lc;
	do{
		system("cls");
		cout<<"1) Them Sinh Vien.\n";
		cout<<"2) Xoa Sinh Vien cuoi danh sach.\n";
		cout<<"3) Xoa Sinh Vien dau danh sach.\n";
		cout<<"4) Hien thi danh sach Sinh Vien.\n";
		cout<<"5) Xoa danh sach Sinh Vien.\n";
		cout<<"0) Thoat.\n";
		cout<<"Lua chon cua ban: ";
		cin>>lc;
		switch(lc){
			case 0: break;
			case 1:
				inputInfo(sv);
				AddHead(sv);
				break;
			case 2: DeTail(); system("pause"); break;
			case 3: DeHead(); system("pause"); break;
			case 4: showStudentList(sv); system("pause"); break;
			case 5: cleanList(); break;
		}
	}while(lc!=0);
}
int main(){
	head=tail=NULL;
	student sv;
	Menu(sv);
	
	return 0;
}
