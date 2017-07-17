#include "MySTLString.h"
#include <assert.h>
#include <iostream>
#include <algorithm>

MySTLString::~MySTLString()
{
}

MySTLString::MySTLString():data_(new char[1])
{
	*data_ = '\0';
}

MySTLString::MySTLString(const MySTLString& str):data_(new char[strlen(str.data_)])
{
	data_ = strcpy(data_, str.data_);
}

MySTLString::MySTLString(const char * s):data_(new char[strlen(s) + 1])
{
	data_ = strcpy(data_, s);
}

MySTLString::MySTLString(unsigned len, const char& a):data_(new char(len + 1))
{
	data_[len] = '\0';
	while (len--)
		data_[len] = a;
}

MySTLString& MySTLString::operator=(const MySTLString& str)
{
	if (&str == this)
		return *this;
	else
	{
		delete[]data_;
		data_ = new char[strlen(str.data_) + 1];
		data_ = strcpy(data_, str.data_);
	}
	return *this;
}

MySTLString& MySTLString::operator=(const char * str)
{
	if (data_ == str)
		return *this;
	else
	{
		delete[]data_;
		data_ = new char[strlen(str) + 1];
		data_ = strcpy(data_, str);
	}
	return *this;
}

unsigned MySTLString::strlen(const char* s)
{
	
	unsigned len = 0;
	assert(s != nullptr);
	while ((*s++) != '\0')
		len++;
	return len;
}

char * MySTLString::strcpy(char * des,const char * source)
{
	char* r = des;
	assert((des != nullptr) && (source != nullptr));
	while ((*des++ = *source++) != '\0');
	return r;
}

const char & MySTLString::front() const
{
	return data_[0];
}

char* MySTLString::strcat(char * str1, char * str2)
{
	assert(str1 != nullptr&&str2 != nullptr);
	char* p = str1;
	while (*p != '\0')
		p++;
	while ((*p++ = *str2++) != '\0');
	return p;
}

std::ostream & operator<<(std::ostream& os, const MySTLString& str)
{
	auto c = str.c_str();
	while(*c)
		os << *c++;
	return os;
}

std::istream& operator>>(std::istream& is, MySTLString& str)
{
	is >> str.data_;
	return is;
}



