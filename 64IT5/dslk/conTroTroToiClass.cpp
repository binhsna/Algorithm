// Trieu Than @Pro - Let's grow together!

#include<iostream>
#include<cstring>
using namespace std;

class Nguoi{
	private:
		char *name;
		char *addr;
		char *phone;
	public:
		Nguoi( char *name, char *ad, char *ph ){
			this->name = name;
			this->addr = ad;
			this->phone = ph;
			cout<< "\nDoi tuong da duoc tao!";
		}
		char *getName(){
			return this->name;
		}
		
		char *getAddr(){
			return this->addr;
		}
		
		char *getPhone(){
			return this->phone;
		}
};

class D{
	friend class Nguoi;
};

class SuperMan{
	friend class Nguoi;
	friend class D;
	public:
		char *getName(Nguoi n){
			return n.getName();
		}
		
		char *getAddr(Nguoi n){
			return n.getAddr();
		}
		
		char *getPhone(Nguoi n){
			return n.getPhone();
		}
};

int main(){
	char na[40], ad[40], ph[20];
	strcpy(na, "Tran Van Nam");
	strcpy(ad, "Ha Noi");
	strcpy(ph, "0948 1234 12");
	Nguoi n1(na, ad, ph);
	Nguoi *n2 = &n1;
	cout<< endl;
	SuperMan s1;
	cout<< n2->getName() << endl;
	cout<< n2->getAddr() << endl;
	cout<< n2->getPhone() << endl;
	return 0;
}
