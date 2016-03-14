 ///
 /// @file    weak_ptr2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-12 00:10:05
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

class X{
	public:
		X(){
			cout<<"X()"<<endl;
		}

		~X(){
			cout<<"~X()"<<endl;
		}

		void func(){
			cout<<"X::func"<<endl;
		}
};

int main(void){
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p1(new X);
		//把一个shared_ptr对象赋值给一个
		//weak_ptr对象，引用计数不会加1
		p = p1;
		cout<<"after p = p1"<<endl;
		cout<<"p1.use_count() ="<<p1.use_count()<<endl;
		cout<<"---------------------"<<endl;
		std::shared_ptr<X> p2 = p.lock();//将p提升为shared_ptr
		if(!p2){
			cout<<"object has been destroyed"<<endl;
		}else{
			p2->func();
			cout<<"p2.use_count() ="<<p2.use_count()<<endl;
		}
		
	}
	
	std::shared_ptr<X> p3 = p.lock();
	if(!p3){ //提升失败
		cout<<"object has been destroyed"<<endl;
	}else{
		p3->func();
		cout<<"p2.use_count() ="<<p3.use_count()<<endl;
	}

	return 0;
}
