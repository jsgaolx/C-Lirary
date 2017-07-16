
#ifndef GAO_STRING
#define GAO_STRIHG

#include <memory>
#include <iostream>

class MySTLString
{
	//������������
	friend std::ostream &operator<<(std::ostream& os, const MySTLString& str);
	//�������������
	friend std::istream &operator>>(std::istream& is, MySTLString& str);
public:
	~MySTLString();
	//Ĭ�Ϲ��캯��
	MySTLString();
	//�������캯��
	MySTLString(const char* s);

	//���㳤��
	int strlen(const char* s);
	//����
	char* strcpy(char* des,const char* source);
	//���ص�һ��char
	const char& front()const;
	//��������
	const char* c_str() const { return data_; }
	
	
	
private:
	char* data_;
};

#endif