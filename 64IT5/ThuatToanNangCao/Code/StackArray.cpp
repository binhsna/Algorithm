#include <iostream>
using namespace std;
int current_size = -1;
#define max_size 100 // const int max_size = 100
int s[max_size];
// Ham kiem tra stack rong ?
bool isEmpty(){
	return (current_size == -1);
}
// Ham kiem tra stack full phan tu
bool isFull(){
	return (current_size == max_size);
}
// Ham chen phan tu vao dinh ngan xep
void push(int data){
	if(!isFull()){
		current_size++;
		s[current_size] = data;
	}
	else cout<<"Stack is full !\n";
}
// Ham lay phan tu top cua stack
int top(){
	return s[current_size];
}
// Ham lay phan tu top cua stack va xoa no di
int pop(){
		int data = s[current_size];
		current_size--;
		return data;
}
// Ham hien thi stack
void Output(){
	for (int i = 0; i<= current_size; i++)
		cout<<s[i]<<" ";
		cout<<endl;
}
int main(){
	int lc;
	do{
		system("cls");
		cout<<"1) Nhap phan tu cho stack.\n";
		cout<<"2) In ra phan tu dau stack.\n";
		cout<<"3) Xoa phan tu dau stack.\n";
		cout<<"4) Hien thi stack.\n";
		cout<<"0) Thoat.\n";
		cout<<"Nhap lua chon cua ban: "; cin>>lc;
		switch(lc){
			case 0: break;
			case 1:
				int data;
				cout<<"Nhap phan tu: "; cin>>data;
				push(data); break;
			case 2:
				if(!isEmpty()){
					cout<<"Phan tu dau stack la: "<<top()<<endl;
				}
				else cout<<"Stack is empty !\n";
				system("pause"); break;
			case 3:
				if(!isEmpty()){
					cout<<"Phan tu dau stack bi xoa la: "<<pop()<<endl;
				}
				else cout<<"Stack is empty !\n";
				system("pause"); break;
			case 4:
				if(!isEmpty()){
				cout<<"Stack: "; Output();
				}
				else cout<<"Stack is empty !\n";
				system("pause"); break;
			default:
				cout<<"Ban da nhap sai lua chon, Vui long nhap lai !\n";
				system("pause"); break;
		}
	}while(lc!=0);
	return 0;
}
