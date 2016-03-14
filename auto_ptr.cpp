 ///
 /// @file    auto_ptr.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 22:12:17
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

int main(void){
	double *db = new double(66.66);
	std::auto_ptr<double> ptr1(db);
	cout<< "*db =" << *db <<endl;
	cout<< "*ptr1 =" << *ptr1 <<endl;
//	cout<< "ptr1 =" << ptr1 <<endl; 无此用法
	cout<< "db =" << std::hex << db<<endl;
	cout<< "ptr1.get() = " << ptr1.get() <<endl;
	cout<<"-----------------------------"<<endl;
	float *f = new float(88.88);
	cout<<"*f ="<< *f <<endl;
	cout<<"f ="<<std::hex<<f<<endl;
	std::auto_ptr<float> f1(f);
	/*进行复制构造，发生了所有权的转移*/
	std::auto_ptr<float> f2(f1);
//	cout<<"*f1 ="<< *f1 <<endl;
	cout<<"*f2 ="<< *f2 <<endl;
	cout<<"f ="<<std::hex<<f<<endl;
	/*显示segmant default 为auto_ptr的缺陷*/
//	cout<<"f1 ="<<std::hex<<f1<<endl;
	cout<<"f2.get() ="<<f2.get()<<endl;
	cout<<"-----------------------------"<<endl;
	int *i = new int(8);
	std::auto_ptr<int> i1;
	i1.reset(i);
	cout<<"*i1 ="<< *i1 <<endl;
	return 0;
}
