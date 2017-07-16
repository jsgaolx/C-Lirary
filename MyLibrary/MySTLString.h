
#ifndef GAO_STRING
#define GAO_STRIHG

#include <memory>
#include <iostream>

class MySTLString
{
	//重载输出运算符
	friend std::ostream &operator<<(std::ostream& os, const MySTLString& str);
	//重载输入运算符
	friend std::istream &operator>>(std::istream& is, MySTLString& str);
public:
	~MySTLString();
	//默认构造函数
	MySTLString();
	//拷贝构造函数
	MySTLString(const char* s);

	//计算长度
	int strlen(const char* s);
	//拷贝
	char* strcpy(char* des,const char* source);
	//返回第一个char
	const char& front()const;
	//返回数据
	const char* c_str() const { return data_; }
	
	
	
private:
	char* data_;
};

#endif