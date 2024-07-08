#include <iostream>
using namespace std;
/* kh?i t?o m?ng và các bi?n c?n thi?t trong Queue */
int queue[100], n = 100, front = - 1, rear = - 1;
/* hàm thêm ph?n t? vào trong Queue */
void push() {
// kh?i t?o bi?n val và dua nó vào trong hàng d?i
   int val;
//xét di?u ki?n hàng d?i d?y, n?u d?y thì không th? thêm ph?n t? vào du?c
   if (rear == n - 1)
   cout<<"Tràn hàng d?i"<<endl;
//Ngu?c l?i n?u trong hàng d?i v?n còn ch? tr?ng thì ta th?c hi?n thêm ph?n t?
   else {
      if (front == - 1)
      front = 0;
      cout<<"Chèn ph?n t? vào hàng d?i : "<<endl;
      //yêu c?u nh?p d? li?u t? bàn phím
      cin>>val;
      //tang v? trí hi?n t?i lên m?t
      rear++;
      //thêm ph?n t? dó vào v? trí hi?n t?i rear
      queue[rear] = val;
   }
}
/* hàm xóa ph?n t? kh?i Queue */
void pop() {
//n?u trong hàng d?i r?ng thì không th? xóa ph?n t?, ta th?c hi?n return và k?t thúc hàm
   if (front == - 1 || front > rear) {
      cout<<"Không th? xóa ph?n t? trong hàng d?i ";
      return ;
   } 
//Ngu?c l?i ta s? th?c hi?n l?y ph?n t? dó ra và xóa luôn kh?i hàng d?i
   else {
      cout<<"Ph?n t? dã xóa kh?i hàng d?i là: "<< queue[front] <<endl;
      front++;;
   }
}
/* hàm in các ph?n t? trong Queue ra màn hình */
void print() {
//n?u hàng d?i r?ng ta s? thông báo 
   if (front == - 1)
   cout<<"Hàng d?i r?ng!!"<<endl;
//Ngu?c l?i n?u hàng d?i có ph?n t? thì ta s? xu?t l?n lu?t các ph?n t? dó ra màn hình
   else {
      cout<<"Các ph?n t? trong hàng d?i là: ";
      //s? d?ng vòng l?p for d? xu?t l?n lu?t các ph?n t?
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
/* hàm main d? t?o menu và g?i các hàm dã t?o ? trên */
int main() {
   int ch;
   cout<<"1) Thêm ph?n t? vào Queue"<<endl;
   cout<<"2) Xóa ph?n t? kh?i Queue"<<endl;
   cout<<"3) Hi?n th? t?t c? các ph?n t? trong Queue"<<endl;
   cout<<"4) Thoát"<<endl;
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
         case 4: cout<<"K?t thúc"<<endl;
         break;
         default: cout<<"L?a ch?n c?a b?n không dúng"<<endl;
      }
   } while(ch!=4);
    
   cout<<"\n--------------------------\n";

}
