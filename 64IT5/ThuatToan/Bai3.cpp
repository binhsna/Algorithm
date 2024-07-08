
#include <iostream>

using namespace std;

class QueueNode{



public:



char val;



QueueNode* next;



};



class AwesomeQueue {



private:



QueueNode* _first;



QueueNode* _last;



public:



void enqueue( char c );



char dequeue( );

void PrintQueue();



};



void AwesomeQueue::enqueue( char c )



{

	QueueNode* p = new QueueNode();

	p->val = c;

	p->next = NULL;

	

	if(!_first){

		_first=_last=p;

	}

	else{

		_last->next=p;

		_last=p;

	}

}
char AwesomeQueue::dequeue(){
	char data = _first->val;
	QueueNode* p = _first;
	_first = _first->next;
	delete p;
	return data;
}
void AwesomeQueue::PrintQueue(){
	QueueNode* k = _first;
	while(k!=NULL){
		cout<<k->val<<" ";
		k=k->next;
	}
}


int main(){
	
	AwesomeQueue q;

q.enqueue('H'); q.enqueue('V'); q.enqueue('D'); q.enqueue('S');

cout << q.dequeue()<< q.dequeue() << q.dequeue() << endl;

q.enqueue('M'); q.enqueue('R'); q.enqueue('T');

cout << q.dequeue() << q.dequeue() << q.dequeue() << endl;

//q.PrintQueue();
return 0;

}
	


