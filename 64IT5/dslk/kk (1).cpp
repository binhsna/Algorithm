#include<iostream>
using namespace std;
// chuong trinh cong hai da thuc update.
// ung dung danh sach lien ket sap xep, thao tac tron hai danh sach va loai tru cac node co so mu trung n
struct DonThuc{
	int heso;
	int somu;
	DonThuc *next;
};

struct DaThuc{
	DonThuc *head;
	DonThuc *tail;
};

DonThuc *createNode( int h, int s ){
	DonThuc  *p = new DonThuc;
	if(!p) return NULL;
	p->next = NULL;
	p->heso = h;
	p->somu = s;
	return p;
}

void Init(  DaThuc &d ){
	d.head = NULL;
	d.tail = NULL;
}

void addTail( DaThuc &d,  DonThuc *p ){
	if(d.head == NULL ) d.head = d.tail = p;
	else{
		d.tail->next = p;
		d.tail = p;
	}
}
void addHead( DaThuc &d, DonThuc *p ){
	if(!d.head) d.head = d.tail = p;
	else{
		p->next = d.head;
		d.head = p;
	}
}

void addAt( DaThuc &d, DonThuc *p ){
	if(!d.head || d.head->somu < p->somu ) addHead( d, p );
	else{
		DonThuc *q = d.head;
		while(q->next){
			if( q->next->somu < p->somu ) break;
			q = q->next;
		}
		if( !q->next ) addTail(d, p );
		else{
			p->next = q->next;
			q->next = p;
		}
	}
}

void nhap( DaThuc &d ){
	int n;
	while(1){
		int lc;
		cout<<"\nNhap he so, so mu: ";
		int h, s;
		cin>> h >> s;
		DonThuc *p = createNode( h, s );
		addAt( d, p );
		cout<<"\nNhap gia tri #0 de tiep tuc. Nhap 0 de thoat! ";
		cin>> lc;
		if(!lc) break;
	}
}

void xuat( DaThuc d ){
	while(d.head){
		cout<< d.head->heso << "x^" << d.head->somu ;
		if(d.head->next) cout<< " + ";
		d.head = d.head->next;
	}
	cout<< endl;
}

DonThuc *meger( DonThuc *d1, DonThuc *d2 ){
	if( !d1 && !d2 ) return NULL;
	else if( !d2 && d1 ) return d1;
	else if( !d1 && d2 ) return d2;
	
	DonThuc *d = NULL;
	if( d1->somu > d2->somu ){
		d = d1;
		d->next = meger( d1->next, d2 );
	}
	else{
		d = d2;
		d->next = meger( d1, d2->next );
	}
	return d;
}

void cong( DaThuc &d2 ){
	DonThuc *d = d2.head;
	if( !d2.head ) return;
	while( d->next ){
		if( d->next && d->somu == d->next->somu ){
			d->heso+= d->next->heso;
			d->next= d->next->next;
		}
		d = d->next;
	}
}

int main(){
	DaThuc d, d1, d2;
	Init(d); Init(d1); Init(d2);
	nhap(d);
	nhap(d1);
	xuat(d);
	xuat(d1);
	d2.head = meger( d.head, d1.head );
	cong(d2);
	xuat(d2);
	xuat(d);
	xuat(d1);
	return 0;
}
