#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
  
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++){
        cout << arr[i];
        cout<<"\t";
      }
}
 
int main()
{
    int n;
    int a[n];
    do{
        cout << "\nNhap n = ";
        cin >> n;
    }while(n <= 0);  
     
    for(int i = 0;i < n;i++){
        cout<<"a["<<i<<"]=";
       cin >> a[i];
    };
 
    insertionSort(a, n);
    cout<<"Mang sau khi duoc sap xep: \n";
    printArray(a, n);
  
    cout<<"\n-------------------------------------\n";
}
