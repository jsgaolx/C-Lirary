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

MySTLString::MySTLString(const char * s):data_(new char[strlen(s) + 1])
{
	data_ = strcpy(data_, s);
}

int MySTLString::strlen(const char* s)
{
	
	int len = 0;
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



