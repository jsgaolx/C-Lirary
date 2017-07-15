#include "MySTLString.h"
#include <assert.h>

MySTLString::MySTLString():data_(new char[1])
{
	*data_ = '\0';
}

MySTLString::MySTLString(const char * s):data_(new char[strlen(s) + 1])
{
	strcpy(data_, s);
}

int MySTLString::strlen(const char* s)
{
	int len = 0;
	while ((*s++) != '\0')
		len++;
	return len;
}

char * MySTLString::strcpy(char * des,const char * source)
{
	char* r = des;
	assert((des != nullptr) && (source != nullptr));
	while((*r++ = *source++) != '\0')
		return r;
}

const char & MySTLString::front() const
{
	// TODO: 在此处插入 return 语句
	return data_[0];
}
