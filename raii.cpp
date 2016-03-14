 ///
 /// @file    raii.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 07:43:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class RAII{
	public:
		RAII(T * p)
		:_p(p)
		{
			cout<<"RAII()"<<endl;
		}

		T * get() const{
			return _p;
		}

		T & operator *() const{
			return *_p;
		}

		void reset(T * p){
			delete _p;
			_p = p;
		}

		~RAII(){
			cout<<"~RAII()"<<endl;
			delete _p;
		}
	private:
		RAII(const RAII & rhs);
		RAII & operator =(const RAII & rhs);

	private:
		T * _p;
};

class SomeSource{
	
};

class Example{
	public:
		Example()
		:_p1(new SomeSource)
		,_p2(new SomeSource)
		{
			cout<<"Example()"<<endl;
		}

		Example(const Example &rhs)
		:_p1(new SomeSource(*rhs._p1))
		,_p2(new SomeSource(*rhs._p2))
		{
			cout<<"Example(const Example &)"<<endl;
		}

		Example & operator =(const Example &rhs){
			cout<<"operator =(const Example &)"<<endl;
			if(this != &rhs){
				*_p1 = *rhs._p1;
				*_p2 = *rhs._p2;
			}
			return *this;
		}

		~Example()
		{
			cout<<"~Example()"<<endl;
		}
	private:
		RAII<SomeSource> _p1;
		RAII<SomeSource> _p2;
};

int main(void){
	int *a = new int(8);
	delete a;
	cout<<"---------------"<<endl;
	RAII<int> raiiInt(new int(3));
	return 0;
}
