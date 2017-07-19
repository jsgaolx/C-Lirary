#include <iostream>
#include "MySTLString.h"
using namespace std;
int main()
{
	MySTLString s1;
	MySTLString s1_1("aa") ;
	MySTLString s2(s1_1);
	MySTLString s2_1 = s1_1;
	MySTLString s3("bb");
	MySTLString s3_1 = "bb";
	MySTLString s4(2,'c');
	//std::cout << s1 << "#" << std::endl;
	s4 += s3;
	std::cout << s4 << std::endl;
	s3 = s1 + s2;
	std::cout << s3 << std::endl;
	
	
	return 0;
}