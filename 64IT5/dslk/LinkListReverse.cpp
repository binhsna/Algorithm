#include<iostream>
using namespace std;

struct Node{
	Node *next;
	int data;
};

struct List{
	Node *head;
	Node *tail;
};

void Init(List &l){
	l.head = NULL;
	l.tail = NULL;
}

Node *createNode(int x){
	Node *p = new Node;
	if(!p) exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}
void addTail(List &l, Node *p){
	if(!l.head) l.head = l.tail = p;
	else{
		l.tail->next = p;
		l.tail = p;// cap nhat l.tail
	}
}

void reverse(List &l){
	Node *parent = l.head ;
	Node *current = l.head->next;
	l.head = current->next;
	parent->next = NULL;
	current->next = parent;
	while(l.head->next){
		parent = current;
		current = l.head;
		l.head = l.head->next;
		current->next = parent;
	}
	l.head->next = current;
	
}

void display(List l){
	while(l.head){
		cout<< l.head->data << " ";
		l.head = l.head->next;
	}
	cout << endl;
}

void nhap(List &l){
	int n;
	cin>> n;
	for(int i = 1; i<= n; i++){
		Node *p = createNode(i);
		addTail(l,p);
	}
}

int main(){
	List l;
	Init(l);
	nhap(l);
	display(l);
	reverse(l);
	display(l);
	return 0;
}
