#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct TNode
{   string du_lieu; //truong key cua du lieu
    TNode *Lchild, *Rchild; //con trai va con nodehai
};

typedef TNode *Tree;  //cay

TNode* TaoNode(TNode *node, string du_lieu) // chen 1 Node vao cay
{  node = new TNode;// (TNode *) malloc(sizeof(TNode));
    node->du_lieu = du_lieu;
    node->Lchild = node->Rchild = NULL;
    return node;   // ok
}

TNode*  TaoTree(TNode *node, string du_lieu)        // Nhap node tao cay
{     cout<<"\n     Nhap du lieu cho nut : "; getline(cin,du_lieu,'\n');
        if (du_lieu == "0") return NULL;
        node =  TaoNode(node,du_lieu);
        cout<<"    Nhap Du lieu node con TRAI cua nut "<<du_lieu<<" : ";
        node->Lchild = TaoTree(node->Lchild,du_lieu);
        cout<<"    Nhap Du lieu node con PHAI cua nut "<<du_lieu<<" : ";
        node->Rchild = TaoTree(node->Rchild,du_lieu);
    return node;
}

// Duyet theo InOrder - thu tu giua
void InOrder(Tree GOC)
{ if(GOC!=NULL)
     {InOrder(GOC->Lchild);
      cout<<" "<<GOC->du_lieu;//duyet goc
      InOrder(GOC->Rchild);
     }
}

void PreOrder(Tree GOC)//duyet theo thu tu truoc
{  if(GOC!=NULL)
     {cout<<" "<<GOC->du_lieu;
      PreOrder(GOC->Lchild);
      PreOrder(GOC->Rchild);
     }
}



void PostOrder(Tree GOC)//duyet theo thu tu sau
{ if(GOC!=NULL)
     {PostOrder(GOC->Lchild);
      PostOrder(GOC->Rchild);
      cout<<" "<<GOC->du_lieu;
     }
}

TNode* TimNode(Tree  GOC, string du_lieu)     // tim nut theo du_lieu, theo ki?u duy?t InOrder
 { if(GOC!=NULL)
     { if (GOC->du_lieu == du_lieu)  return GOC;
       TimNode(GOC->Lchild,du_lieu);
       TimNode(GOC->Rchild,du_lieu);
    }
 }

TNode * Lchild(Tree GOC)
{  if(GOC!=NULL) return GOC->Lchild;
    else return NULL;
  }

TNode * Rchild(Tree GOC)
{  if(GOC!=NULL) return GOC->Rchild;
    else  return  NULL;
}

int LA(Tree GOC) //- kiem tra nút lá
{   if(GOC!= NULL)
      return (GOC->Lchild==NULL && GOC->Rchild==NULL ) ;
    else
     return 0;
}

int DemNode(Tree GOC)  //- Dem so nút trong cây
{  if(GOC==NULL) return 0;
    else return (1+DemNode(Lchild(GOC))+ DemNode(Rchild(GOC)));
}

int main()
{ Tree GOC;
    GOC = NULL; //Tao cay rong
    TNode *node=NULL;
    string du_lieu;
    cout<<"\n   Nhap so 0 de chuyen sang nhap node khac hoac thoat";
    GOC = TaoTree(node,du_lieu); //- Nhap node tao cay
    cout<<"\n   So nut cua cay hien co  : "<<DemNode(GOC)<<"\n";
	cout<<"\n   Duyet cay theo thu tu giua InOrder : \n\n";
    cout<<setw(10);
    InOrder(GOC);cout<<"\n" ;
    cout<<"\n   Duyet cay theo thu tu truoc  PreOrder : \n\n";
    cout<<setw(10);
    PreOrder(GOC); cout<<"\n";
    cout<<"  \n  Duyet cay theo thu tu sau  PostOrder :  \n \n";
    cout<<setw(10);
    PostOrder(GOC); cout<<"\n";
     TNode *P;
    cout<<" \n Tim kiem nut theo du lieu \n ";
    cout<<"Nhap du lieu nut can tim: "; cin>>du_lieu;
    P = TimNode(GOC, du_lieu);// searchKey(T, x);
if (P != NULL) cout<<"\n Da Tim thay nut co du lieu la "<<du_lieu;
else cout<<" Khong co nut nao co du lieu la "<<du_lieu<<" trong cay \n";
   system("pause");
return 0;
}

