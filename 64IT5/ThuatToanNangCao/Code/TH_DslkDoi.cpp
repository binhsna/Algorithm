#include <iostream>
using namespace std;
 
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct Node *head, *tail; // Khoi tao Node head global cua dslk dôi.
 
// Ham tao moi node de nhan du lieu
struct Node* GetNewNode(int x) {
    struct Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 
// Ham them node vao dau danh sach
void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
 
// Ham them node vao cuoi danh sach
void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
 
// Ham xoa node dau danh sach
void DeleteAtHead() {
    if(head == NULL) {
        return;
    }
    head = head->next;
    head->prev = NULL;
}
 
// Ham xoa node cuoi danh sach
void DeleteAtTail() {
    if(head == NULL) {
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}
 
// Ham hien danh sach lien ket tu dau den cuoi
void Print() {
    struct Node* temp = head;
    cout<<"\nDanh sach lien ket doi: ";
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
 

int main() {
 
    head = NULL; tail = NULL; // Khoi tao danh sach lien ket doi rong ban dau
    int lc,x;
	do{
		system("cls");
		cout<<"\n______MENU______"
			<<"\n1_Them nut vao dau danh sach."
			<<"\n2_Them nut vao cuoi danh sach."
			<<"\n3_Hien thi danh sach lien ket doi."
			<<"\n4_Xoa nut dau danh sach."
			<<"\n5_Xoa nut cuoi danh sach."
			<<"\n0_Thoat.\n->Ban chon ? ";
			cin>> lc;
		switch(lc){
			case 0: break;
			case 1: cout<<"\nNhap gia tri nut ban muon them: "; cin>>x;InsertAtHead(x); break;
			case 2: cout<<"\nNhap gia tri nut ban muon them: "; cin>>x;InsertAtTail(x); break;
			case 3: Print(); system("pause"); break;
			case 4: DeleteAtHead();break;
			case 5: DeleteAtTail();break;
		}
	}while(lc != 0 );
	cout<<endl;
	
	return 0;

}
    
