#include <iostream>
#define max_size 100
using namespace std;
class Queue{
	private:
		int front;
		int rear;
		int arr[max_size];
	public:
		Queue(){
			front = -1;
			rear = -1;
			for(int i=0; i<max_size; i++)
				arr[i]=0;
		}
		bool isEmpty(){
			return (front == -1 and rear == -1);
		}
		bool isFull(){
			return (rear == max_size - 1);
		}
		void EnQueue(int val){
			if(isFull()){
				cout<<"Queue is Full\n";
				return;
			}
			else if(isEmpty()){
				rear = front = 0;
				arr[rear]=val;
			}
			else{
				rear++;
				arr[rear]=val;
			}
		}
		int DeQueue(){
			int x;
			if(isEmpty()){
				cout<<"Queue is Empty\n";
				return 0;
			}
			else if(front == rear){
				x=arr[front];
				arr[front]=0;
				front = rear = -1;
			}
			else{
				x=arr[front];
				arr[front]=0;
				front++;
			}
			return x;
		}
		int Front(){
			return arr[front];
		}
		void PrintQueue(){
			for(int i=front; i<=rear; i++)
				cout<<arr[i]<<" ";
				cout<<"\n";
		}
};
int main(){
	Queue q1;
	int lc, val;
	do{
		system("cls");
		cout<<"1) Nhap phan tu vao Queue.\n";
		cout<<"2) In ra phan tu dau tien cua Queue.\n";
		cout<<"3) Xoa phan tu dau tien cua Queue.\n";
		cout<<"4) In ra Queue.\n";
		cout<<"0) Thoat\n";
		cout<<"Nhap lua chon cua ban: "; cin>>lc;
		switch(lc){
			case 1:
				cout<<"Nhap phan tu: "; cin>>val;
				q1.EnQueue(val);
				break;
			case 2:
				if(q1.isEmpty())
					cout<<"Queue is Empty\n";
				else cout<<"Phan tu dau tien cua Queue la: "<<q1.Front()<<endl;
				system("pause"); break;
			case 3:
				if(q1.isEmpty())
					cout<<"Queue is Empty\n";
				else cout<<"Xoa phan tu "<<q1.DeQueue()<<" thanh cong !\n";
				system("pause"); break;
			case 4:
				if(q1.isEmpty())
					cout<<"Queue is Empty\n";
				else{
					cout<<"Queue: "; q1.PrintQueue();
				}
				system("pause"); break;
			default: 
				cout<<"Ban da nhap sai lua chon, Vui long nhap lai !\n";
				system("pause");
				break;
		}	
	}while(lc!=0);
	return 0;
}
