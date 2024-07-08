#include<iostream>
using namespace std;
int n;

struct Node{
	int data;
	Node *next;
};

struct List{
	Node *head;
	Node *tail;
};

void Init( List &l ){
	l.head = l.tail = NULL;
}

Node *createNode( int x ){
	Node *p = new Node;
	if(!p) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}

void addTail( List &l, Node *p ){
	if(!l.head){
		l.head = l.tail = p;
	}
	else{
		l.tail->next = p;
		l.tail = p;
	}
	l.tail->next = l.head;
}
void nhap( List &l ){
	cout<< "\nnhap n = "; cin>> n;
	for( int i = 1; i<= n; i++ ){
		Node *p= createNode( i );
		addTail( l, p );
	}
}

// cac buoc thuc hien dao danh sach lien ket vong:
/* 	B1: Neu danh sach rong hoac co 1 node thi bo qua.
	B2: Neu danh sach co hai node thi doi cho hai phan tu cho nhau
	B3: Neu danh sach co tu ba Node tro len:
		* danh dau node *temp = *head, *parent = *head, *current = *head->next; cap nhat l.head = current->next;
		* Lap: khi l.head->next != temp;
			parent = current;
			current = l.head;
			l.head = l.head->next;
			current->next = parent;
	B4: cap nhat lai l.head, l.tail, khep lai vong.
*/

void dao( List &l ){
	if(l.head){ // ds k rong
		if(l.head == l.tail ) return; // bo qua
		else if( l.tail == l.head->next ){ // doi cho
			l.head = l.head->next;
			l.tail = l.tail->next;
		}
		else{ // truong hop ds co tu ba node tro len
			Node *temp, *parent, *current;
			temp = parent = l.head; // danh dau node head
			current = l.head->next;
			l.head = current->next; // cap nhat l.head
			current->next = parent;// dao nguoc con tro next
			while(l.head->next != temp ){
				parent = current; // cap nhat parent
				current = l.head; // cap nhat current
				l.head = l.head->next; // tim l.tail cu
				current->next = parent; // cap nhat lai con tro next
			}
			l.head->next = current; // cap nhat con tro next cua l.head
			l.tail = temp; // cap nhat lai l.tail
			l.tail->next = l.head; // khep vong
		}
	} else cout<<"\nDanh sach rong!";
}

void xuat( List l ){
	if(l.head){
		Node *p = l.head;
		do{
			cout<< p->data << "->";
			p = p->next;
		} while( p != l.head );
	}
	cout<< endl;
}

int main(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	dao(l);
	xuat(l);
	return 0;
}
