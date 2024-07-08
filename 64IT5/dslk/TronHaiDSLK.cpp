#include<iostream>
using namespace std;

struct Node{
	Node *next;
	int data;
};

typedef Node *List;

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}

void addTail( List &l, int x ){
	Node *p = createNode(x);
	if(!l) l = p;
	else{
		Node *r = l;
		while(r->next) r = r->next;
		r->next = p;
		r = p;
	}
}

void xuat( List l ){
	while(l){
		if(l->next) cout<< l->data << "->";
		else cout<< l->data;
		l = l->next;
	}
	cout<< endl;
}

void nhap(List &l ){
	int n, x;
	cin>> n;
	for( int i = 0; i< n; i++ ){
		cout<<"\nNhap phan tu thu "<< i+1 << " : ";
		cin>> x;
		addTail( l, x );
	}
}

// tron hai danh sach da sap xep thanh danh sach sap xep.
// lan luot k tra hai phan tu dau l1,l2, chon lay phan tu co gia tri nho hon
// chen vao cuoi l. thuc hien cho toi khi 1 trong hai danh sach rong.

Node *merge( List l1, List l2 ){
	if(!l2) return l1;
	else if( !l1 ) return l2;
	
	List l = NULL;
	if( l1->data < l2->data ){
		l = l1;
		l->next = merge(l1->next, l2);
		
	}
	else{
		l = l2;
		l->next = merge(l1, l2->next);
	}
	return l;
}

// tim phan tu middle cua danh sach lien ket.
// dung hai bien chay Node *p, *q. trong do p tang 1:1, q tang 2:1
// khi q->phan tu cuoi cung cua danh sach thi p chinh la phan tu mid can tim.

Node *getMid( List l ){
	if(!l) return l;
	Node *p, *q;
	p = q = l;
	while(q->next && q->next->next){
		p = p->next;
		q = q->next->next;
	}
	return p;
}

void tach( List l, List &l1, List &l2 ){
	Node *mid = getMid(l);
	l1 = l;
	l2 = mid->next;
	mid->next = NULL;
}

// tien hanh mergeSort();
// cac buoc thuc hien:
// B0: dieu kien dung: danh sach rong hoac danh sach chi co mot node.
// B1: Tach doi danh sach can sap xep thanh l1, l2.
// B2: goi de quy mergeSort(l1), mergeSort(l2).
// B3: Tron l1, l2 lai => danh sach da sap xep.
// B4: tra ve k.qua.

void mergeSort( List &l ){
	List l1 = NULL, l2 = NULL;
	if( !l || !l->next ) return;
	tach(l, l1, l2 );
	mergeSort(l1);
	mergeSort(l2);
	l = merge( l1, l2);
}

int main(){
	List l1;
	l1 = NULL;
	nhap(l1);
	xuat(l1);
	mergeSort(l1);
	xuat(l1);
	return 0;
}
