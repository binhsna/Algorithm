#include <iostream>
using namespace std;

// Ham nhap phan tu
void input(int a[], int n){
	for(int i=0; i<n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}	
}
// Ham xuat phan tu
void output(int a[], int n){
	cout<<"Mang a: ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
// Ham hoan doi
void swap(int& x, int& y){
	int temp = x;
	x=y;
	y=temp;
}
// Ham sap xep tuan tu (tang dan)
void sort_tt(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] > a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}
// Ham sap xep chon (tang dan)
void sort_chon(int a[], int n){
	int index = 0;
	for(int i=0; i<n-1; i++){
		index = i;
		for(int j=i+1; j<n; j++){
			if(a[index] > a[j]){
				index = j;
			}
		}swap(a[i],a[index]);
	}
}
// Ham sap noi bot (tang dan)
void sort_bt(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){ 
			if(a[j] < a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
// Ham sap xep noi bot (giam dan)
void sort_bg(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){ // 2 1 0 3 8 4 7
			if(a[j] > a[j-1] ){
				swap(a[j],a[j-1]);
			}	
		}
	}
}
// Ham sap xep chen
void sort_chen(int a[], int n){
	int i, j, key;
	for(i=1; i<n; i++){
		key = a[i];
		j=i-1;
		while(j>=0 and a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
int main(){
	int a[100];
	int n;
	
	do{
		cout<<"Nhap n = ";
		cin>>n;
	}while(n<0);
	
	input(a,n);
	sort_tt(a,n);
	//sort_chon(a,n);
	sort_bt(a,n);
	//sort_bg(a,n);
	//sort_chen(a,n);
	output(a,n);
	
	return 0;
}
