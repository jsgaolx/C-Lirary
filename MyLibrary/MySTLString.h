
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
	friend MySTLString operator + (const MySTLString& str1,const MySTLString& str2);
	
public:
	~MySTLString();
	//Ĭ�Ϲ��캯��
	MySTLString();
	//�������캯��
	//��ʼ����ʽ string s2 (s1)
	MySTLString(const MySTLString& str);
	//��ʼ����ʽ string s3 ("a") 
	MySTLString(const char* s);
	//��ʼ����ʽ string s4 (10,'a')
	MySTLString(unsigned len, const char& a);

	//���ظ�ֵ�����
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

	
	//���㳤��
	unsigned strlen(const char* s);
	//����
	char* strcpy(char* des,const char* source);
	//���ص�һ��char
	const char& front()const;
	//��������
	const char* c_str() const { return data_; }
	//�ϲ�
	char* strcat(char* str1, char* str2);
	
private:
	char* data_;
	unsigned size_;
};

#endif