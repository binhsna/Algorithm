// Trieu Than @Pro - Let's grow together!

#include<iostream>
#include<ctime>
using namespace std;

int main(){
	time_t now = time('\0');
	cout<< "\nnow = " << now;
	char *ch = ctime(&now);
	tm *t = localtime(&now);
	char *ch1 = asctime(t);
	cout<< "\nthoi gian da dinh dang: " << ch;
	cout<< "\nthoi gian da dinh dang thong qua cau truc tm: " << ch1;
	cout<< "\nNgay/thang/nam gio: phut: giay\n" << t->tm_mday << "/" << 1+ t->tm_mon << "/" << 1900+ t->tm_year;
	cout<< " " << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec;
	return 0;
}
