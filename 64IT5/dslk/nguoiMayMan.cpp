#include<iostream>
// Trieu Than @Pro
// Let's Grow Together!
#include<iomanip>
using namespace std;

struct Node{
	Node *next;
	int data;	
};

typedef Node *List;

void Init(List &head){
	head = NULL;
}

Node *createNode(int x){
	Node *p = new Node;
	p->next = NULL;
	p->data = x;
	return p;	
}

void addHead(List &head, Node *p ){
	p->next = head;
	head = p;
}

void del(List &head, Node *p){
	Node *q = head;
	head = head->next;
	p->next = head;
	delete q;
}

void nhap(List &head, int n){
	Node *q = new Node;
	for(int i = n; i>= 1; i-- ){
		Node *p = createNode(i);
		if( i == n ) q = p;
		addHead(head,p);
	}
	q->next = head;
}

void xuat(List head){
	cout<<"\nPhan tu cuoi cung: " << head->data;
}

void lap(List &head, int k ){
	int count = 1;
	while(head->next != head ){
		count++;
		Node *p = head;
		head = head->next;
		if(count == k  ){
			count  = 1;
			del(head, p);
		}
	}
}


int main(){
	List head;
	Init(head);
	int n, k;
	cout<<"\nHay nhap n, k: "; cin>> n >> k;
	nhap(head, n);
	lap(head, k);
	xuat(head);
	return 0;
}
