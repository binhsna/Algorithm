#include <iostream>
using namespace std;

// Ham nhap phan tu
void input(float a[], int n){
	for(int i=0; i<n; i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}	
}
// Ham xuat phan tu
void output(float a[], int n){
	cout<<"Mang a: ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
// Ham hoan doi
void swap(float& x, float& y){
	float temp = x;
	x=y;
	y=temp;
}
// Ham tra ve gia tri int cua float
int round(float f){
	return (int)f;
}
// Ham sap noi bot (tang dan)
void sort_bt(float a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){ 
			if(round(a[j]) < round(a[j+1])){
				swap(a[j],a[j+1]);
			}
		}
	}
}

int main(){
	float a[100];
	int n;
	
	do{
		cout<<"Nhap n = ";
		cin>>n;
	}while(n<0);
	
	input(a,n);
	
	sort_bt(a,n);

	output(a,n);
	
	return 0;
}
