// Trieu Than @Pro - Let's Grow Together!
// Comment neu ban thay chuong trinh co the update.

#include<iostream>
using namespace std;

struct Node{
	Node *next;
	int data;
};

typedef Node *List;

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}

void addList( List &l, Node *p ){
	if(!l) l = p;
	else{
		if( l->data > p->data ){
			p->next = l;
			l = p;
		}
		else{
			Node *r = l;
			while( r->next && r->next->data < p->data )
				r = r->next;
			/// 1 2 6 9 10 11
			p->next = r->next;
			r->next = p;
		}
	}
}

void add( List &l ){
	int n, x;
	cout<<"\nNhap so luong phan tu cua list: ";
	cin>> n;
	while(n--){
		cout<<"\nPhan tu tiep theo: ";
		cin>> x;
		Node *p = createNode(x);
		addList( l , p );
	}
}

void disPlay( List l ){
	if(l){
		while(l){
			cout<< l->data << " ";
			l = l->next;
		}
	}
	else
		cout<< "\nDanh sach rong!";
}

int main(){
	List l = NULL;
	add(l);
	disPlay(l);
	add(l);
	disPlay(l);
	return 0;
}
