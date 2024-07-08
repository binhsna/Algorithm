#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
struct node* head, *tail;
node* CreateNode(int data){
	node* p = new node();
	p->data = data;
	p->next = NULL;
	return p;
}
bool isEmpty(){
	if(!head) return true;
	else return false;
}
void EnQueue(int data){
	node* p = CreateNode(data);
	if(!head){
		head=tail=p;
	}
	else{
		tail->next=p;
		tail=p;
	}
}
int Front(){
	return head->data;
}
int DeQueue(){
	int data = head->data;
	node* p = head;
	head = head->next;
	delete p;
	return data;
}
void PrintQueue(){
	node* k = head;
	while(k){
		cout<<k->data<<" ";
		k=k->next;
	}cout<<"\n";
}
void CleanMemory(){
	node* k = NULL;
	while(head){
		k=head;
		head=head->next;
		delete k;
	}
}
int main(){
	head = NULL;
	tail = NULL;	
	int lc; 
	do{
		system("cls");
		cout<<"1) Nhap phan tu cho Queue.\n";
		cout<<"2) In ra phan tu dau Queue.\n";
		cout<<"3) Xoa phan tu dau Queue.\n";
		cout<<"4) Hien thi Queue.\n";
		cout<<"5) Clean Queue.\n";
		cout<<"0) Thoat.\n";
		cout<<"Nhap lua chon cua ban: "; cin>>lc;
		switch(lc){
			case 0: break;
			case 1:
				int data;
				cout<<"Nhap phan tu: "; cin>>data;
				EnQueue(data); break;
			case 2:
				if(head){
					cout<<"phan tu dau tien cua Queue la: "<<Front()<<endl;
				}else cout<<"Queue is Empty !\n"; system("pause"); break;
			case 3:
				if(head){
					cout<<"Xoa phan tu "<<DeQueue()<<" thanh cong !"<<endl;
				}else cout<<"Queue is Empty !\n"; system("pause"); break;
			case 4:
				if(head){
					cout<<"Queue: "; PrintQueue();
				}else cout<<"Queue is Empty !\n"; system("pause"); break;
			case 5:
				if(head){
					CleanMemory(); cout<<"Xoa du lieu thanh cong !"<<endl;
				}else cout<<"Queue is Empty !\n"; system("pause"); break;
					break;
			default: cout<<"Ban da nhap sai lua chon, Vui long nhap lai !"<<endl;
						system("pause"); break;
		}
	}while(lc!=0);
	return 0;
}
