#include <iostream>
using namespace std;
// 											Danh sach lien ket vong don 

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
    // simply insert at head and return the next node pointed by tail
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
 
node* sort(node* tail) {
    if (Length(tail) < 2) return tail;
    node* ptr1 = tail -> next, * ptr2, * min;
    int temp;
    // selection sort implementation
    while (ptr1 -> next != tail -> next) {
        min = ptr1;
        ptr2 = ptr1 -> next;
        while (ptr2 != tail -> next) {
            if (min -> data > ptr2 -> data) min = ptr2;
            ptr2 = ptr2 -> next;
        }
        if (min != ptr1) {
            temp = min -> data;
            min -> data = ptr1 -> data;
            ptr1 -> data = temp;
        }
        ptr1 = ptr1 -> next;
    }
    return tail;
}
// Ham hien thi
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
    int option, data, location;
    while (1) {
    	system("cls");
        //Display(cll);
        cout<<"\nlength = "<<Length(cll);
        cout<<"\n\nMENU OF CHOICE\n1. Insert at head\n2. Insert at end\n3. Insert at arbitrary location\n4. Display List\n5. Delete by value\n6. Delete by location\n7. Sort\n8. Exit\n";
        cout<<"Your choice: ";
        cin>>option;
 		if(option < 1 || option > 8){
 			cout<<"\nLua chon cua ban khong hop le !\n-> Vui long nhap lai !\n";
 			system("pause");
		}
        else if (option == 1) {
            cout<<"Enter data to be inserted: "; cin>>data;
            cll = InsertAtHead(cll, data);// Kiem tra lai tail = ? : cout<<endl<<cll->data<<endl;system("pause");
        } else if (option == 2) {
            cout<<"Enter data to be inserted at end: "; cin>>data;
            cll = InsertAtEnd(cll, data); // Kiem tra lai tail = ? : cout<<endl<<cll->data<<endl;system("pause");
        } else if (option == 3) {
            cout<<"Enter data to be inserted: "; cin>>data;
            cout<<"Enter location to be inserted into: "; cin>>location;
            cll = InsertAtArbitrary(cll, data, location); // Kiem tra lai tail = ? : cout<<endl<<cll->data<<endl;
			system("pause");
        } else if (option == 4) {
            cout<<"-> Circular linked list:\n"; Display(cll); cout<<endl; system("pause");
        } else if (option == 5) {
            cout<<"Enter value to be deleted: "; cin>>data;
            cll = DeleteByValue(cll, data);
            system("pause");
        } else if (option == 6) {
            cout<<"Enter location to be deleted: "; cin>>location;
            cll = DeleteByLocation(cll, location);
            system("pause");
        } else if(option == 7) {
            sort(cll);system("pause");
        } else if (option == 8) {
            break;
        }
    }
    return 0;
}
