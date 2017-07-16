#include <iostream>
#include "MySTLString.h"
using namespace std;
int main()
{
	MySTLString str("adasdasd");
	std::cout << str;
	MySTLString str_1;
	std::cin >> str_1;
	std::cout << str_1;
	return 0;
}