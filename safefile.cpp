 ///
 /// @file    safefile.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-11 06:31:17
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class SafeFile{
	public:
		SafeFile(const char *file)
		:_filehandler(fopen(file,"w+"))
		{
			cout<<"SafeFile(const char*)"<<endl;
			if(_filehandler == NULL){
				cout<<"fopen fail"<<endl;
				return;
			}
		}

		void write(const char* str){
			cout<<"write(const char*)"<<endl;
			if(fputs(str,_filehandler) == EOF){
				cout<<"fputs fail"<<endl;
				return;
			}
		}

		void write(const char* buf,int num){
			cout<<"write(const char*,int)"<<endl;
			if(num != 0 && fwrite(buf,num,1,_filehandler) == 0){
				cout<<"fwrite fail"<<endl;
				return;
			}
		}

		~SafeFile(){
			cout<<"~SafeFile()"<<endl;
			if(_filehandler)
				fclose(_filehandler);
		}

	private:
		SafeFile(const SafeFile & rhs);
		SafeFile & operator =(const SafeFile & rhs);
	private:
		FILE * _filehandler;
};


int main(void){
	SafeFile sf("test.dat");
	sf.write("\nit is just a test!\n");
	return 0;
}
