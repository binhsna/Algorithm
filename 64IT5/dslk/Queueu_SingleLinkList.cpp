// tao queue tu danh sach lien ket don
#include<iostream>
using namespace std;

struct Node{
	Node *next;
	int data;
};

struct Queue{
	Node *head, *tail;
};

void Init( Queue &q ){
	q.head = q.tail = NULL;
}

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}

void Push(Queue &q, Node *p ){
	if(!q.head) q.head = q.tail = p;
	else{
		q.tail->next = p;
		q.tail = p;
	}
}

int Top(Queue q ){
	if(q.head){
		return q.head->data;
	}
	else return 0;
}

int Pop(Queue &q ){
	if(q.head){
		Node *p = q.head;
		q.head = q.head->next;
		return p->data;
		delete p;
	}
	return 0;// tuong duong queue rong
}

void nhap(Queue &q ){
	int n, x;
	cin>> n;
	while(n--){
		cout<<"\nphan tu tiep theo: "; cin>> x;
		Node *p = createNode(x);
		Push(q,p);
	}
}

void xuat(Queue q ){
	Node *p = q.head;
	while(p){
		cout<< p->data << " ";
		p = p->next;
	}
	cout<< endl;
}

int main(){
	Queue q;
	Init(q);
	nhap(q);
	xuat(q);
	Node *p = createNode(10);
	Push(q,p);
	xuat(q);
	cout<<"\nPhan tu top: "<< Top(q)<<endl;
	Pop(q);
	cout<< "\nQueue sau khi pop phan tu top: \n";
	xuat(q);
	cout<<"\nPhan tu top: "<< Top(q)<<endl;
	return 0;
}
