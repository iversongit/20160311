 ///
 /// @file    point.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 04:00:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int x=0, int y=0)
		:_x(x)
		,_y(y)
		{
			cout<<"Point(int,int)"<<endl;
		}

		Point(const Point &rhs)
		:_x(rhs._x)
		,_y(rhs._y)
		{
			cout<<"Point(const Point &)"<<endl;
		}

		~Point(){
			cout<<"~Point()"<<endl;
		}
	private:
		int _x;
		int _y;

};

Point func(){
	Point tmp(6,8);
	return tmp;
}

int main(void){
	func();
	Point p = 1;
	return 0;
}
