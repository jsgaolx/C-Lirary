
#ifndef GAO_STRING
#define GAO_STRIHG

class MySTLString
{
public:
	MySTLString();
	MySTLString(const char* s);
	int strlen(const char* s);
	char* strcpy(char* des,const char* source);
	const char& front()const;

private:
	char* data_;
};

#endif