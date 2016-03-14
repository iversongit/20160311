 ///
 /// @file    unique_ptr.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 22:51:08
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/*返回的是一个匿名对象，即右值，此时就会调用
 *移动构造函数-->unique_ptr具有移动语义
 */ 
std::unique_ptr<int> getValue(){
	std::unique_ptr<int> np(new int(88));
	return np;
}

int main(void){
	int *i = new int(66);
	std::unique_ptr<int> up(i);
	/*无法调用赋值运算符函数和复制构造函数*/
//	std::unique_ptr<int> up1(up);
//	std::unique_ptr<int> up2;
//	up2 = up;
	cout<<"*i ="<<*i<<endl;
	cout<<"*up ="<<*up<<endl;
	cout<<"i ="<<std::hex<<i<<endl;
	cout<<"up.get() ="<<std::hex<<up.get()<<endl;
//	cout<<"up ="<<std::hex<<up<<endl;

	std::unique_ptr<int> up3 = getValue();
	cout<<"-------------------------"<<endl;
/*使用move函数，显式的告诉我们要发生所有权的转移*/	
	std::unique_ptr<int> up4(std::move(up));
	cout<<"*up4 ="<<*up4<<endl; //16进制方式显示
//	cout<<"*up ="<<*up<<endl;

	cout<<"-------------------------"<<endl;
	vector<std::unique_ptr<int> > vecInt;  //可以作为容器的元素
	vecInt.push_back(std::move(up3));
//	vecInt.push_back(up3);
	cout<<"*vecInt[0] ="<<*vecInt[0]<<endl; //16进制方式显示
	return 0;
}
