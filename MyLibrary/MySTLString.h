
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
	friend MySTLString operator + (const MySTLString& str1,const MySTLString& str2);
	
public:
	~MySTLString();
	//默认构造函数
	MySTLString();
	//拷贝构造函数
	//初始化方式 string s2 (s1)
	MySTLString(const MySTLString& str);
	//初始化方式 string s3 ("a") 
	MySTLString(const char* s);
	//初始化方式 string s4 (10,'a')
	MySTLString(unsigned len, const char& a);

	//重载赋值运算符
	MySTLString& operator = (const MySTLString& str);

	MySTLString& operator = (const char* str);
	//MySTLString& operator + (MySTLString& str);
	const MySTLString& operator += (const MySTLString& str);
	char& operator [] (unsigned n);
	bool const operator == (const MySTLString& str);
	bool const operator > (const MySTLString& str);
	bool const operator >= (const MySTLString& str);
	bool const operator < (const MySTLString& str);
	bool const operator <= (const MySTLString& str);

	bool empty();
	unsigned size();

	
	//计算长度
	unsigned strlen(const char* s);
	//拷贝
	char* strcpy(char* des,const char* source);
	//返回第一个char
	const char& front()const;
	//返回数据
	const char* c_str() const { return data_; }
	//合并
	char* strcat(char* str1, char* str2);
	
private:
	char* data_;
	unsigned size_;
};

#endif