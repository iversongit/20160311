 ///
 /// @file    ArrayWrapper.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 04:30:03
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class MetaData{
	public:
		MetaData(int size,const string &name)
		:_name(name)
		,_size(size)
		{
			cout<<"MetaData(const string &,int)"<<endl;
		}

		MetaData(const MetaData &rhs)
		:_name(rhs._name)
		,_size(rhs._size)
		{
			cout<<"MetaData(const MetaData &)"<<endl;
		}

		~MetaData(){
			cout<<"~MetaData()"<<endl;
		}

		MetaData(MetaData && rhs)
		:_name(std::move(rhs._name))
		,_size(rhs._size)
		{
			cout<<"MetaData(MetaData &&)"<<endl;
		}

		int getSize() const{
			return _size;
		}

		string getName() const{
			return _name;
		}

	private:
		string _name;
		int _size;
};

class ArrayWrapper{
	public:
		ArrayWrapper()
		:_pval(new int[64])
		,_metadata(64,"ArrayWrapper")
		{
			cout<<"ArrayWrapper()"<<endl;
		}

		ArrayWrapper(int n)
		:_pval(new int[n])
		,_metadata(n,"ArrayWrapper")
		{
			cout<<"ArrayWrapper(int)"<<endl;
		}

		ArrayWrapper(const ArrayWrapper &rhs)
		:_pval(new int[rhs._metadata.getSize()])
		,_metadata(rhs._metadata)
		{
			cout<<"ArrayWrapper(const ArrayWrapper &)"<<endl;
			for(int i=0; i<rhs._metadata.getSize(); ++i){
				_pval[i] = rhs._pval[i];
			}
		}

		ArrayWrapper(ArrayWrapper && rhs)
		:_pval(rhs._pval)
		,_metadata(std::move(rhs._metadata))
		{
			cout<<"ArrayWrapper(ArrayWrapper &&)"<<endl;
			rhs._pval = NULL;
		}

		~ArrayWrapper(){
			cout<<"~ArrayWrapper()"<<endl;
			delete[] _pval;
		}
	private:
		int *_pval;
		MetaData _metadata;

};

int main(void){
	ArrayWrapper arw1;
	ArrayWrapper arw2(5);
	ArrayWrapper arw3(std::move(arw1));
	return 0;
}
