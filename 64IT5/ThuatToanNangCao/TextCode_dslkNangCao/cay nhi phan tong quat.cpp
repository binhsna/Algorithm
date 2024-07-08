#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *left, *right;
};

typedef TNode *Tree;

void Init(Tree &root){
	root = NULL;
}

TNode *createNode(int x){
	TNode *p = new TNode;
	if(!p) exit(1);
	p->data = x;
	p->left = p->right =  NULL;
	return p;
}

TNode *searchNode(Tree t, int x ){
	if(t){
		if(t->data == x ) return t;
		else{
			TNode *p = searchNode(t->left, x);
			if(!p) p = searchNode(t->right, x);
			return p;
		}
	}
	return NULL;
}

void insertNode(Tree &root, TNode *p ){
	if(!root) root = p;
	else{
		int x;
		cout<< "\nEnter parent node: "; cin>> x;
		TNode *q = searchNode(root, x); // la node cha
		if(p){
			int vt; cout<< "\n1_insert Left, 2_insert Right";
			cin>> vt;
			if(vt == 1 ) q->left = p;
			else q->right = p;// default
		}
		else cout<< "\nFailed";
	}
}

void createTree(Tree &root){
	int n, x;
	cout<< "\nEnter the number of Tree elements: ";
	cin>> n;
	while(n--){
		cout<< "\nEnter next element: "; cin>> x;
		TNode *p = createNode(x);
		insertNode(root, p);
	}
}

void LNR(Tree root){
	if(root){
		LNR(root->left);
		cout<< root->data << " ";
		LNR(root->right);
	}
}

int main(){
	/* tree: 50
		    /  \
		  30    70
		  /\	 /\
		20  40  60 90
	
	*/
	Tree root;
	Init(root);
	createTree(root);
	LNR(root);
	return 0;	
}
