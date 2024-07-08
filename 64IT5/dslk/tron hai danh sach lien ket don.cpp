/* tron hai danh sach lien ket l1, l2 da sap xep tang thanh mot danh sach lien ket sap xep giam.
	*cach 1: dao nguoc l1, l2, sau do tron lai.
	*cach 2: tron hai danh sach lai sau do dao nguoc lai. 
	*cach 3: trong khi tron hai danh sach lai thi dao nguoc no luon.
	- neu ca hai ds l1, l2 rong, return null;
	- khoi tao danh sach l rong;
	@.3 truong hop:
	- neu ca l1, l2 deu # null, tim phan tu head nho nhat trong l1, l2 chen vao dau l;
	- neu l1 = null, l2 # null, chen cac phan tu con lai cua l2 vao dau danh sach l;
	- neu l1 # null, l2 = null, chen cac phan tu con lai cua l1 vao dau danh sach l.
	4 3 2 1
*/

// Trieu Than @Pro - let's grow together!

#include<iostream>
using namespace std;

struct Node{
	Node *next;
	int data;
};

typedef Node *List;

void Init(List &l){
	l= NULL;
}

Node *createNode(int x){
	Node *p = new Node;
	if(!p) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}

void addTail(List &l, Node *p ){
	if(!l) l = p;
	else{
		Node *pp = l;
		while(pp->next) pp = pp->next;
		pp->next = p;
	}
}

void addHead(List &l, Node *p ){
	p->next = l;
	l = p;
}

Node *merger(List l1, List l2){
	if(!l1 && !l2) return NULL;
	Node *p = new Node;
	List l; Init(l);
	while(l1 || l2){
		if(l1 && l2){
			if(l1->data < l2->data){
				p = l1;
				l1 = p->next;
				addHead(l,p);
			}
			else{
				p = l2;
				l2 = p->next;
				addHead(l,p);
			}
		}
		if(!l1 && l2){
			p = l2;
			l2 = p->next;
			addHead(l,p);
		}
		
		if(!l2 && l1){
			p = l1;
			l1 = p->next;
			addHead(l,p);
		}
	}
	return l;
}

void xuat(List l){
	while(l){
		cout<< l->data << " ";
		l = l->next;
	}
	cout<< endl;
}

void nhap(List &l){
	int n, x;
	cout<<"Nhap so ptu: "; cin>> n;
	while(n--){
		cout<<"Phan tu tiep theo: ";
		cin>> x;
		Node *p = createNode(x);
		addTail(l, p);
	}
}

int main(){
	List l1, l2, l;
	Init(l1); Init(l2); Init(l);
	nhap(l1); nhap(l2);
	xuat(l1);
	xuat(l2);
	l = merger(l1, l2);
	xuat(l);
	return 0;
}
