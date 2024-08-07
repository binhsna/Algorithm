#include <iostream>
#include <iomanip>
using namespace std;
//											CAY TIM KIEM NHI PHAN BST
struct BSTNode{
	int data;
	BSTNode* Lchild;
	BSTNode* Rchild;
};
// Ham tao node:
BSTNode* CreateNode(int data){
	BSTNode* p = new BSTNode();
	p->data = data;
	p->Lchild = p->Rchild = NULL;
	return p;
}
// Tim vi tri node can chen:
BSTNode* SearchNodeAdd(BSTNode* root, int data){
	if(root == NULL){return NULL;}
	BSTNode* p = root;
	BSTNode* f = p;
	while(p!=NULL){
		f=p;
		if(p->data > data){p = p->Lchild;}
		else{p = p->Rchild;}
	}
	return f;
}
// Ham chen Node:
void AddNode(BSTNode* &root, int data){
	BSTNode* n = CreateNode(data);
	if(root == NULL){root=n; return;}
	else{
		BSTNode* f = SearchNodeAdd(root,data);
		if(f!=NULL){
			if(f->data > data){f->Lchild=n;}
			else{f->Rchild=n;}
		}
	}
}
// Ham tao cay:
void CreateTree(BSTNode* &root, int a[], int n){
	for(int i=0; i<n; i++){
		AddNode(root,a[i]);
	}
}
// Ham tim node:
BSTNode* SearchNode(BSTNode* root, int data){
	if(root == NULL){return NULL;}
	if(root->data == data){
		cout<<"Da thay node "<<root->data<<endl;
		return root;
	}
	if(root->data > data){SearchNode(root->Lchild,data);}
	else SearchNode(root->Rchild,data);
}
// Duyet Trung To
void InOrder(BSTNode* root){
	if(root != NULL){
		InOrder(root->Lchild);
		cout<<" "<<root->data; // Duyet goc
		InOrder(root->Rchild);
	}
}
// Duyet Tien To
void PreOrder(BSTNode* root){
	if(root != NULL){
		cout<<" "<<root->data; // Duyet goc
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
// Duyet Hau To
void PostOrder(BSTNode* root){
	if(root != NULL){
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		cout<<" "<<root->data; // Duyet goc 
	}
}
// Ham xac dinh node ben trai:
BSTNode* Lchild(BSTNode* root){
	if(root!=NULL) return root->Lchild;
	else return NULL;
}
// Ham xac dinh node ben phai:
BSTNode* Rchild(BSTNode* root){
	if(root!=NULL) return root->Rchild;
	else return NULL;
}
// Ham dem so node trong cay:
int CountNode(BSTNode* root){
	if(root==NULL) return 0;
	else return (1 + CountNode(Lchild(root)) + CountNode(Rchild(root)));
}
// Ham xoa Node:
BSTNode* DeleteNode(BSTNode* root, int data){
	static int dltt = -1 ;
    if (root == NULL)
        return NULL;
    if (root->data == data)
      {
       if (root->Lchild == NULL && root->Rchild == NULL)
           { delete root;
             return NULL ;
             }
       if ( (root->Lchild == NULL )&&(root->Rchild != NULL))
          {BSTNode* NewRoot = root->Rchild;
            delete root;
           return NewRoot;
          }
        if ( (root->Rchild != NULL )&&(root->Lchild == NULL))
          {  BSTNode* NewRoot = root->Lchild;
             delete root ;
            return NewRoot;
          }
        if (root->Lchild != NULL && root->Rchild != NULL)
            {//2
            // T�m n�t thay th�
            BSTNode* replace = root->Rchild;
            while (replace->Lchild != NULL) replace = replace->Lchild;
            root->data = replace->data;
            dltt = replace->data;
            cout<<"  \ Nut Thay The co du lieu = "<<replace->data<<" \n ";
            DeleteNode(root->Rchild, replace->data);
            return root;
           }//2
        if (root->Lchild != NULL)
            return root->Lchild;
        else
            return root->Rchild;
       }//1
    if (data > root->data)
        root->Rchild = DeleteNode(root->Rchild, data);
      else
        root->Lchild = DeleteNode(root->Lchild, data);
     return root;
}//0

int main(){
	BSTNode* root = NULL;
	int a[]={45,30,5,35,32,60,55,58,67};
	int data; int n=9;
	CreateTree(root,a,n);
	cout<<"\n  So nut cua cay hien co : "<<CountNode(root)<<endl;
	
	cout<<"\n  Duyet cay theo thu tu giua InOrder : \n\n"<<setw(10);
	InOrder(root); cout<<endl;
	
	cout<<"\n  Duyet cay theo thu tu truoc PreOrder : \n\n"<<setw(10);
	PreOrder(root); cout<<endl;
	cout<<"\n  Duyet cay theo thu tu sau PostOrder : \n\n"<<setw(10);
	PostOrder(root); cout<<endl;
	
	cout<<"\n Nhap nut can tim : "; cin>>data;
	SearchNode(root,data);
	
	cout<<"\n Nhap nut can xoa : "; cin>>data;
	DeleteNode(root,data);
	cout<<"\n  Duyet cay theo thu tu giua InOrder sau khi xoa nut:\n\n"<<setw(10);
	InOrder(root); cout<<endl;
	
	return 0;
}
