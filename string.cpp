 ///
 /// @file    string.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 02:46:22
 ///

#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String{
	public:
		String()
		:_pstr(new char[1])
		{
			cout<<"String()"<<endl;
		}

		String(const char *pstr)
		{
			cout<<"String(const char *)"<<endl;
			_pstr = new char(strlen(pstr) + 1);
			strcpy(_pstr,pstr);
		}

		String(const String &rhs){
			cout<<"String(const String &rhs)"<<endl;
			_pstr = new char(strlen(rhs._pstr) + 1);
			strcpy(_pstr,rhs._pstr);
		}
//右值引用优先绑定到右值，移动构造函数会优先于
//复制构造函数进行调用
		String(String && rhs)//移动构造函数
		:_pstr(rhs._pstr)
		{
			cout<<"String(String && rhs)"<<endl;
			rhs._pstr = NULL;
		}

		String & operator =(const String & rhs){
			cout<<"operator =(const String &)"<<endl;
			if(this != &rhs){
				delete [] _pstr;
				_pstr = new char(strlen(rhs._pstr) + 1);
				strcpy(_pstr,rhs._pstr);
			}
			return *this;
		}

		//移动赋值运算符函数
		String & operator =(String && rhs){
			cout<<"operator =(String && rhs)"<<endl;
			if(this != &rhs){
				delete [] _pstr;
				_pstr = rhs._pstr;
				rhs._pstr = NULL;
			}
			return *this;
		}

		String & operator +=(const String & rhs){
			cout<<"operator +=(const String & rhs)"<<endl;
			char *tmp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1];
			strcpy(tmp,_pstr);
			strcat(tmp,rhs._pstr);
			delete[] _pstr;
			_pstr = tmp;
			return *this;
		}

		~String(){
			cout<<"~String()"<<endl;
			delete[] _pstr;
		}

	friend std::ostream & operator<<(std::ostream &,const String &);

	private:
		char *_pstr;

};

std::ostream & operator<<(std::ostream & os,const String &rhs){
	cout<<"operator<<(std::ostream &os,const String &rhs)"<<endl;
	os<<rhs._pstr;
	return os;
}

String operator + (const String &lhs,const String &rhs){
	cout<<"operator + (const String &lhs,const String &rhs)"<<endl;
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

int main(void){
	String s1 = "hello";
	String s2 = "world";
	String s3 = s1 + s2;
	s3 = s1 + s2;
	cout<<"s1= "<<s1<<endl;
	cout<<"s2= "<<s2<<endl;
	cout<<"s3= "<<s3<<endl;
	cout<<"----------------------"<<endl;
	s3 = s1;
	cout<<"s1= "<<s1<<endl;
	cout<<"s3= "<<s3<<endl;
	cout<<"----------------------"<<endl;
//使用std::move库函数时，表示以后不再使用
//s1,s1中的内容已经转移了
	s3 = std::move(s1);
	cout<<"s3= "<<s3<<endl;
	cout<<"s1= "<<s1<<endl;
	return 0;
}
