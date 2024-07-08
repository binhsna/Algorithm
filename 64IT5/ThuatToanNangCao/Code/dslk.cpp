#include <iostream>
using namespace std;
// Danh sach lien ket don

struct node{
	int data;
	node* next;
	node* prev;
};
struct node *head, *tail;
// Ham khoi tao node
node* createNode(int data){
	node* p = new node();
	p->data = data;
	p->next = NULL;
	return p;
}
// Ham them vao dau danh sach lien ket
void AddHead(int data){
	node* p = createNode(data);
	if (! head)
		head=tail=p;
	else{
		p->next = head;
		head->prev = p;
		head = p;
	}	
}
// Ham chen vao cuoi danh sach lien ket
void AddTail(int data){
	node* p = createNode(data);
	if (! head)
		head=tail=p;
	else{
		tail->next = p;
		p->prev = tail;
		tail = p;
	}
}
// Ham tim kiem node
bool Search(int data){
	if(!head)
		return false;
	else {
		for(node* k = head; k!=NULL; k=k->next){
			if(k->data == data)
				return true;
		}
		return false;
	}
}
// Ham chen node vao sau node k
void AddAfter(int data, int dt){
	if(Search(dt) == false)
		cout<<"Khong co node k !";
	else{
		for(node* k = head; k!=NULL; k=k->next){
			if(k->data == dt){
				node* p =createNode(data);
				node* r = k->next;
				k->next=p; p->prev = k;
				p->next = r; r->prev = p;
				exit(1);
			}
		}
	}
}
// Ham chen vao giua (truoc) node k
void AddBefore(int data, int dt){
	if(Search(dt) == false)
		cout<<"Khong co node k !";
	else{
		for(node* k = head; k!=NULL; k=k->next){
			if(k->data == dt){
				node* p =createNode(data);
				node* r = k->prev;
				k->prev = p; p->next = k;
				r->next = p; p->prev = r;
				exit(1);				
			}
		}
	}
}
// Ham chen them node vao vi tri bat ky
void AddNode_k(int data, int place, int n){
	if (place < 1 or place > n+1)
		cout<<"Vi tri khong hop le!";
	else if(!head or place == 1)
		AddHead(data);
	else if(place ==  n+1)
		AddTail(data);
	else{
		node* k = head;
		int dem = 0;
		while(k!=NULL){
			dem++;
			if(dem == place){
				node* p = createNode(data);
				node* r = k->prev;
				k->prev = p; p->next = k;
				r->next = p; p->prev =r;
			}
			k=k->next;
		}
	}
}
void DeleteHead(){
	if(!head){
		cout<<"Danh sach rong !";
	}
	else{
		node* p = head;
		head = head->next;
		delete p;
	}
}
void DeleteTail(){
	if(!head){
		cout<<"Danh sach rong !";
	}
	else{
		//for(node* k=head; k!=NULL; k=k->next){
			//if(k->next=tail){
				//delete tail;
				//k->next = NULL;
				//tail = k;
				//return;
			//}
		//}
		tail = tail->prev;
		tail->next = NULL;
	}
}
// Ham hien thi List
void Print(){
	for(node* k=head; k!=NULL; k=k->next)
		cout<<k->data<<" ";
		cout<<endl;
}
int main(){
	head=tail=NULL;
	int data,lc,dt;
	do{
		system("cls");
		cout<<"1) Them phan tu vao dau List.\n";
		cout<<"2) Them phan tu vao cuoi List.\n";
		cout<<"3) Xoa phan tu dau List.\n";
		cout<<"4) Xoa phan tu cuoi List.\n";
		cout<<"5) Chen 1 node sau 1 node k.\n";
		cout<<"6) Chen 1 node vao truoc node k.\n";
		cout<<"7) Chen 1 node vao 1 vi tri bat ky.\n";
		cout<<"8) Hien thi List.\n";
		cout<<"0) Thoat.\n";
		cout<<"Lua chon cua ban la: ";
		cin>>lc;
		
		switch(lc){
			case 0:
				break;
			case 1:
				cout<<"Nhap so nguyen: ";
				cin>>data;
				AddHead(data); break;
			case 2:
				cout<<"Nhap so nguyen: ";
				cin>>data;
				AddTail(data); break;
			case 3:
				if(head){
					DeleteHead();
					cout<<"Xoa thanh cong !"<<endl;
				}
				system("pause"); break;
			case 4:
				if(head){
					DeleteTail();
					cout<<"Xoa thanh cong !"<<endl;
				}
				system("pause"); break;
			case 5:
				cout<<"Nhap gia tri cua node k: "; cin>>dt;
				cout<<"Nhap gia tri node ban muon chen: "; cin>>data;
				AddAfter(data,dt);
				cout<<"Chen thanh cong!"<<endl;
				system("pause"); break;
			case 6:
				cout<<"Nhap gia tri cua node k: "; cin>>dt;
				cout<<"Nhap gia tri node ban muon chen: "; cin>>data;
				AddBefore(data,dt);
				cout<<"Chen thanh cong!"<<endl;
				system("pause"); break;
			case 7:
				int place;
				cout<<"Nhap vi tri ban muon chen: "; cin>>place;
				cout<<"Nhap so nguyen: "; cin>>data;
				int n;
				for(node* k=head; k!=NULL; k=k->next){
					n++;
				}
				AddNode_k(data,place,n);
				cout<<"Chen thanh cong!"<<endl;
				system("pause"); break;
			case 8:
				Print();
				system("pause"); break;
			default:
				cout<<"Ban da nhap sai lua chon, Vui long nhap lai !"<<endl;
				system("pause"); break;
		}
	}while(lc!=0);
	return 0;
}
