#include <iostream>
using namespace std;
/* kh?i t?o m?ng v� c�c bi?n c?n thi?t trong Queue */
int queue[100], n = 100, front = - 1, rear = - 1;
/* h�m th�m ph?n t? v�o trong Queue */
void push() {
// kh?i t?o bi?n val v� dua n� v�o trong h�ng d?i
   int val;
//x�t di?u ki?n h�ng d?i d?y, n?u d?y th� kh�ng th? th�m ph?n t? v�o du?c
   if (rear == n - 1)
   cout<<"Tr�n h�ng d?i"<<endl;
//Ngu?c l?i n?u trong h�ng d?i v?n c�n ch? tr?ng th� ta th?c hi?n th�m ph?n t?
   else {
      if (front == - 1)
      front = 0;
      cout<<"Ch�n ph?n t? v�o h�ng d?i : "<<endl;
      //y�u c?u nh?p d? li?u t? b�n ph�m
      cin>>val;
      //tang v? tr� hi?n t?i l�n m?t
      rear++;
      //th�m ph?n t? d� v�o v? tr� hi?n t?i rear
      queue[rear] = val;
   }
}
/* h�m x�a ph?n t? kh?i Queue */
void pop() {
//n?u trong h�ng d?i r?ng th� kh�ng th? x�a ph?n t?, ta th?c hi?n return v� k?t th�c h�m
   if (front == - 1 || front > rear) {
      cout<<"Kh�ng th? x�a ph?n t? trong h�ng d?i ";
      return ;
   } 
//Ngu?c l?i ta s? th?c hi?n l?y ph?n t? d� ra v� x�a lu�n kh?i h�ng d?i
   else {
      cout<<"Ph?n t? d� x�a kh?i h�ng d?i l�: "<< queue[front] <<endl;
      front++;;
   }
}
/* h�m in c�c ph?n t? trong Queue ra m�n h�nh */
void print() {
//n?u h�ng d?i r?ng ta s? th�ng b�o 
   if (front == - 1)
   cout<<"H�ng d?i r?ng!!"<<endl;
//Ngu?c l?i n?u h�ng d?i c� ph?n t? th� ta s? xu?t l?n lu?t c�c ph?n t? d� ra m�n h�nh
   else {
      cout<<"C�c ph?n t? trong h�ng d?i l�: ";
      //s? d?ng v�ng l?p for d? xu?t l?n lu?t c�c ph?n t?
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
/* h�m main d? t?o menu v� g?i c�c h�m d� t?o ? tr�n */
int main() {
   int ch;
   cout<<"1) Th�m ph?n t? v�o Queue"<<endl;
   cout<<"2) X�a ph?n t? kh?i Queue"<<endl;
   cout<<"3) Hi?n th? t?t c? c�c ph?n t? trong Queue"<<endl;
   cout<<"4) Tho�t"<<endl;
   do {
      cout<<"Nh?p l?a ch?n c?a b?n: "<<endl;
      cin>>ch;
      switch (ch) {
         case 1: push();
         break;
         case 2: pop();
         break;
         case 3: print();
         break;
         case 4: cout<<"K?t th�c"<<endl;
         break;
         default: cout<<"L?a ch?n c?a b?n kh�ng d�ng"<<endl;
      }
   } while(ch!=4);
    
   cout<<"\n--------------------------\n";

}
