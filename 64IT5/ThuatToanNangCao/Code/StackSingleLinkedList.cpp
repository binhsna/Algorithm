#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
typedef struct node* stack;
// Ham kiem tra stack rong ?
bool isEmpty(stack s){
	return (s == NULL);
}
node* CreateNode(int data){
	node* p = new node();
	p->data = data;
	p->next = NULL;
	return p;
}
void push(stack& s, int data){
	node* p = CreateNode(data);
	if(isEmpty(s)){
		s = p;
	}
	else{
		p->next = s;
		s = p;
	}
}
int top(stack s){
	if(!isEmpty(s)){
		return s->data;
	}
	else {
		cout<<"Stack is Empty !"<<endl;
		return 0;
	}
}
int pop(stack& s){
	if(!isEmpty(s)){
		int data = s->data;
		node* x = s;
		s=s->next;
		delete x;
		return data;
	}
	else {
		cout<<"Stack is Empty !"<<endl;
		return 0;
	}
}
void OutPut(stack& s){
	if(s){
		node* k = s;
		while(k!=NULL){
			cout<<k->data<<" ";
			k=k->next;
		}cout<<endl;
	}
}
int main(){
	stack s = NULL;
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
				push(s,data); break;
			case 2:
				if(s){
					cout<<"Phan tu dau stack la: "<<top(s)<<endl;
				}
				else cout<<"Stack is Empty !\n";
				system("pause"); break;
			case 3:
				if(s){
					cout<<"Phan tu dau stack bi xoa la: "<<pop(s)<<endl;
				}
				else cout<<"Stack is Empty !\n";
				system("pause"); break;
			case 4:
				if(s){
				cout<<"Stack: "; OutPut(s);
				}
				else cout<<"Stack is Empty !\n";
				system("pause"); break;
				
			default:
				cout<<"Ban da nhap sai lua chon, Vui long nhap lai !\n";
				system("pause"); break;
		}	
	}while(lc!=0);
	return 0;
}
