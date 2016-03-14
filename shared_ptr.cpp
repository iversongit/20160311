 ///
 /// @file    shared_ptr.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 23:39:25
 ///
 
#include <iostream>
#include <memory>
using std::endl;
using std::cout;

class Child;
class Parent{
	public:
		Parent(){
			cout<<"Parent()"<<endl;
		}
		
		~Parent(){
			cout<<"~Parent()"<<endl;
		}

		std::shared_ptr<Child> _pChild;
};

class Child{
	public:
		Child(){
			cout<<"Child()"<<endl;
		}

		~Child(){
			cout<<"~Child()"<<endl;
		}

		std::shared_ptr<Parent> _pParent;
};

int main(void){
	std::shared_ptr<Parent> parent(new Parent);
	std::shared_ptr<Child> child(new Child);
	cout<<"Child's use_count ="<<child.use_count()<<endl;
	cout<<"Parent's use_count ="<<parent.use_count()<<endl;
	parent->_pChild = child;
	child->_pParent = parent;	
	cout<<"Child's use_count ="<<child.use_count()<<endl;
	cout<<"Parent's use_count ="<<parent.use_count()<<endl;
	return 0;
}
