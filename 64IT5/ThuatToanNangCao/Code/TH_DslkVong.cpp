#include <iostream>
using namespace std;

// 											DANH SACH LIEN KET VONG

struct Node {
    int data;
    struct Node * next;
};
 
typedef struct Node node;
 
node* CreateNode(int data) {
    node* p = new node;
    p -> data = data;
    return p;
}
// Ham dem so luong node
int Length(node* tail) {
    node* current = tail;
    int i = 1;
    if (tail == NULL) {return 0;}
	else {
        current = current -> next;
        while (current != tail) {
            i++;
            current = current -> next;
        }
    }
    return i; // Tra ve so luong node
}
// Ham them vao dau danh sach 1 gia tri
node* InsertAtHead(node* tail, int data) {
    node* p = CreateNode(data); // Khoi tao 1 node moi
    if (tail == NULL) {
        tail = p;
        p -> next = p;
    } else {
        p -> next = tail -> next;
        tail -> next = p;
    }
    return tail;
}
// Ham them vao cuoi danh sach 1 gia tri
node* InsertAtEnd(node* tail, int data) {
    return InsertAtHead(tail, data) -> next;
}
// Ham chen gia tri vao vi tri bat ky
node* InsertAtArbitrary(node* tail, int data, int location) {
    int len = Length(tail), i;
    if (location < 1 || location > len + 1) {
        cout<<"\nVi tri ban nhap khong hop le !\n";
    } else {
        if (tail == NULL) return InsertAtHead(tail, data);
        node* p = CreateNode(data), * current = tail;
        for (i = 1; i != location; i++) current = current -> next;
        p -> next = current -> next;
        current -> next = p;
        if (location == len + 1) tail = p;
    }
    return tail;
}
// Ham xoa theo gia tri duoc chi dinh
node* DeleteByValue(node* tail, int data) {
    node* current = tail, * previous;
    if (tail == NULL) return tail;
    else if (tail == tail -> next) {
        if (tail -> data == data) {
            tail = NULL;
            delete current; // Xoa luon node hien thoi
        }
        return tail;
    }
    do {
        previous = current; // Tao con tro truoc do
        current = current -> next;
        if (current -> data == data) {
            previous -> next = current -> next;
            if (current == tail) tail = previous;
            delete current;
            current = previous -> next;
        }
    } while (current != tail);
    return tail;
}
// Ham xoa theo vi tri chi dinh
node* DeleteByLocation(node* tail, int location) {
    node* current, * previous = tail;
    int len = Length(tail), i;
    if (location < 1 || location > len) {
        cout<<"Vi tri khong hop le";
    } else if (len == 1) {
        tail = NULL;
        delete current; // Neu chi co 1 nut thi xoa luon node hien thoi
    } else {
        current = tail -> next;
        for (i = 1; i < location; i++) {
            previous = current;
            current = current -> next;
        }
        previous -> next = current -> next;
        if (current == tail) tail = previous;
        delete current;
    }
 
    return tail;
}
 

// Ham hien thi danh sach lien ket vong tu dau den cuoi
void Display(node* tail) {
    node* current = tail;
    if (tail != NULL) {
        do {
            current = current -> next;
            cout<<" "<<current -> data;
        } while (current != tail);
    }
}
int main() {
    node* cll = NULL;
    int lc, data, location;
	do{
		system("cls");
		cout<<"\n______MENU______"
			<<"\n1_Them nut vao dau danh sach."
			<<"\n2_Them nut vao cuoi danh sach."
			<<"\n3_Them nut vao vi tri bat ky."
			<<"\n4_Xoa nut theo du lieu da cho."
			<<"\n5_Xoa nut theo vi tri bat ky."
			<<"\n6_Hien danh sach lien ket vong."
			<<"\n0_Thoat.\n->Ban chon ? ";
			cin>> lc;
		switch(lc){
			case 0: break;
			case 1: cout<<"\nNhap gia tri nut ban muon them: "; cin>>data;
            cll = InsertAtHead(cll, data);
			break;
			case 2: cout<<"\nNhap gia tri nut ban muon them: "; cin>>data;
            cll = InsertAtEnd(cll, data);
			break;
			case 3: cout<<"\nNhap gia tri nut ban muon them: "; cin>>data;
            cout<<"Nhap vi tri can them: "; cin>>location;
            cll = InsertAtArbitrary(cll, data, location);
			break;
			case 4: cout<<"\nNhap gia tri nut ban muon xoa: "; cin>>data;
            cll = DeleteByValue(cll, data);system("pause");
			break;
			case 5: cout<<"\nNhap vi tri nut ban muon xoa: "; cin>>location;
            cll = DeleteByLocation(cll, location);
			break;
			case 6: cout<<"\n-> Danh sach lien ket vong:\n"; Display(cll); cout<<endl;
			system("pause");
			break;
		}
	}while(lc != 0 );
	cout<<endl;
    return 0;
}
