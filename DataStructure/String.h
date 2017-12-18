
#ifndef _STRING_H_
#define _STRING_H_
#include "LinkList.h"
#include <cstring>
#include <iostream>
using namespace std;

//字符串类
class String
{
public:
	String();
	virtual~String();
	String(const String &copy);
	String(const char *copy);
	String(const LinkList<char> &copy);
	int Length() const;
	bool isEmpty() const;
	String &operator=(const String &copy);
	const char *CStr() const;
	const char &operator[](int i) const;

protected:
	char *strVal;
	int length;
};

//串相关内容
String Read(istream &input);
String Read(istream &input, char &terminalChar);	//从输入流读入串，并用terminalChar返回串结束字符
void Write(const String &s);
void Concat(String &addTo, const String &addOn);
//void Copy(String &copy, const String &original);
//void Copy(String &copy, const String &original, int n);
int Index(const String &target, const String &pattern, int pos = 0);	//查找模式串pattern第一次在目标串targe中从第pos个字符开始的位置
//String SubString(const String &s, int pos, int len);
bool operator==(const String &first, const String &second);
bool operator<(const String &first, const String &second);
bool operator>(const String &first, const String &second);
bool operator<=(const String &first, const String &second);
bool operator>=(const String &first, const String &second);
bool operator!=(const String &first, const String &second);

#endif // !_STRING_H_
