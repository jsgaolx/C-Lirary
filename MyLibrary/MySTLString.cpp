#include "MySTLString.h"
#include <assert.h>
#include <iostream>
#include <algorithm>

MySTLString::~MySTLString()
{
}

MySTLString::MySTLString():size_(0),data_(new char[1])
{
	*data_ = '\0';
}

MySTLString::MySTLString(const MySTLString& str):size_(str.size_), data_(new char[str.size_ + 1])
{
	data_ = strcpy(data_, str.data_);
}

MySTLString::MySTLString(const char * s):size_(strlen(s)),data_(new char[strlen(s) + 1])
{
	data_ = strcpy(data_, s); 
}

MySTLString::MySTLString(unsigned len, const char& a):size_(len),data_(new char[len + 1])
{
	data_[size_] = '\0';
	while (len--)
		data_[len] = a;
}

MySTLString& MySTLString::operator=(const MySTLString& str)
{
	char* data = new char(*str.data_);
	delete[]data_;
	size_ = str.size_;
	data_ = data;
	return *this;
}

MySTLString& MySTLString::operator=(const char * str)
{
	assert(str != nullptr && data_ != nullptr);
	if (data_ == str)
		return *this;
	else
	{
		size_ = strlen(str);
		delete[]data_;
		data_ = new char[size_ + 1];
		data_ = strcpy(data_, str);
		return *this;
	}
}

MySTLString operator+(const MySTLString& str1, const MySTLString& str2)
{
	MySTLString str3 = str1;
	str3 += str2;
	return str3;
}

const MySTLString & MySTLString::operator+=(const MySTLString & str)
{
	MySTLString str1;
	str1.size_ = size_ + str.size_;
	delete[]str1.data_;
	str1.data_ = (new char[str1.size_ + 1]);
	for (unsigned i = 0; i < size_; i++)
	{
		str1.data_[i] = data_[i];
	}
	for (unsigned i = size_; i <= str1.size_; i++)
	{
		str1.data_[i] = str.data_[i - size_];
	}
	*this = str1;
	return *this;
}

bool const MySTLString::operator==(const MySTLString& str)
{
	assert(data_ != nullptr);
	char* str1 = str.data_;
	if(size_ != str.size_)
		return false;
	while (*data_ != '\0')
		if(*data_++ != *str1++)
			return false;
	return true;
}

bool const MySTLString::operator>(const MySTLString & str)
{
	assert(data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ > *str1++)
			return true;
		else
			return false;
	}
	if (*data_ == '\0')
		return false;
	else
		return true;
}

bool const MySTLString::operator>=(const MySTLString & str)
{
	assert(data_ != nullptr);
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

bool const MySTLString::operator<(const MySTLString & str)
{
	assert(data_ != nullptr);
	char* str1 = str.data_;
	while (*data_ != '\0' && *str1 != '\0')
	{
		if (*data_++ < *str1++)
			return true;
		else
			return false;
	}
	if (*data_ == '\0')
		return true;
	else
		return false;
}

bool const MySTLString::operator<=(const MySTLString & str)
{
	assert(data_ != nullptr);
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
	if (n > size_)
		exit(-1);
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
	return size_;
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



