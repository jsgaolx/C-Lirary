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
	assert(str.data_ != nullptr && data_ != nullptr);
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
	assert(str != nullptr && data_ != nullptr);
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

const MySTLString & MySTLString::operator+(const MySTLString& str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	MySTLString str1;
	delete[]str1.data_;
	str1.data_ = (new char[strlen(data_) + strlen(str.data_) + 1]);
	while ((*str1.data_++ = *data_++) != '\0');
	str1.data_--;
	char* str2 = str.data_;
	while ((*str1.data_++ = *str2 ++) != '\0');
	return str1;
}

const MySTLString & MySTLString::operator+=(const MySTLString & str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = new char[strlen(data_) + strlen(str.data_) + 1];
	while ((*str1 ++ = *data_++) != '\0');
	str1--;
	char* str2 = str.data_;
	while ((*str2++ = *str2++) != '\0');
	data_ = str2;
	return *this;
}

bool MySTLString::operator==(const MySTLString& str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = str.data_;
	if(strlen(data_) != strlen(str1))
		return false;
	while (*data_ != '\0')
		if(*data_++ != *str1++)
			return false;
	return true;
}

bool MySTLString::operator>(const MySTLString & str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ > *str1++)
			return true;
		else
			return false;
	}
	if (*data_++ == '\0')
		return false;
	else
		return true;
}

bool MySTLString::operator>=(const MySTLString & str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ == *str1++)
			continue;
		if (*data_ > *str1)
			return true;
		else
			return false;
	}
	if (*data_ == *str1)
		return true;
	if (*data_ == '\0')
		return false;
	else
		return true;
}

bool MySTLString::operator<(const MySTLString & str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ < *str1++)
			return true;
		else
			return false;
	}
	if (*data_++ == '\0')
		return true;
	else
		return false;
}

bool MySTLString::operator<=(const MySTLString & str)
{
	assert(str.data_ != nullptr && data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ == *str1++)
			continue;
		if (*data_ < *str1)
			return true;
		else
			return false;
	}
	if (*data_ == *str1)
		return true;
	if (*data_ == '\0')
		return true;
	else
		return false;
}

char& MySTLString::operator[](unsigned n)
{
	assert(data_ != nullptr);
	return data_[n];
}

bool MySTLString::empty()
{
	assert(data_ != nullptr);
	if (data_ = '\0')
		return true;
	return false;
}

unsigned MySTLString::size()
{
	assert(data_ != nullptr);
	return strlen(data_);
}

unsigned MySTLString::strlen(const char* s)
{
	unsigned len = 0;
	assert(s != nullptr);
	if (*s == '\0')
		return len;
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
	assert(data_ != nullptr);
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
	assert(str.data_ != nullptr);
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



