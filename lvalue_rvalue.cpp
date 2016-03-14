 ///
 /// @file    lvalue_rvalue.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 02:24:45
 ///
 
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void){
	int a = 1;
	int b = 2;
	int *p = &a;
	vector<int> vecInt;
	vecInt.push_back(1);
	string s1 = "hello";
	string s2 = "world";
	const int &m = 1;

//能取地址的即是左值，否则为右值
	&a;  //lvalue;
	&b;  //lvalue;
//	&(a + b);  rvalue;
//	&(a++);  rvalue;
	&(++b);  //lvalue;
	&p;   //lvalue;
	&(*p); //lvalue;
	&vecInt[0]; //lvalue;
//	&100;   rvalue;
	&s1;	//lvalue;
//	&string("test");  rvalue;
//	&(s1 + s2);  rvalue;
	&m;  //lvalue;

	cout<<"-------------------"<<endl;

	int n = 10;
	int &ref1 = n;
	const int ref = 5;
//const左值引用可以绑定在所有的数据上，
//不管是左值还是右值
	const int &ref2 = 3;
	const int &ref3 = n;
	const int &ref4 = ref1;
	const int &ref5 = ref;
	const int &ref6 = 100;

	cout<<"-------------------"<<endl;
	int && refa = 100; //右值引用就是为了区分出右值
//	int && refb = n;  右值引用不能绑定左值
	return 0;
}
