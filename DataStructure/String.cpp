/*
#include "String.h"

String::String()
{
	strVal = NULL;
	length = 0;
}
String::~String()
{
	if (strVal != NULL)
		delete[]strVal;
}
String::String(const String &copy)
{
	length = copy.length;
	strVal = new char[length + 1];
	strcpy(strVal, copy.CStr());
}
String::String(const char *copy)
{
	length = strlen(copy);
	strVal = new char[length + 1];
	strcpy(strVal, copy);
}
String::String(const LinkList<char> &copy)
{
	length = copy.Length();
	strVal = new char[length + 1];
	for (int i = 0; i < length; i++)
		copy.GetElem(i + 1, strVal[i]);
	strVal[length] = '\0';
}
int String::Length() const
{
	return length;
}
bool String::isEmpty() const
{
	return length == 0;
}
String &String::operator=(const String &copy)
{
	if (&copy != this)
	{
		if (strVal != NULL)
			delete[]strVal;
		length = copy.length;
		strVal = new char[length + 1];
		strcpy(strVal, copy.CStr());
	}
	return *this;
}
const char *String::CStr() const
{
	return (const char *)strVal;
}
const char &String::operator[](int i) const
{
	return (const char)strVal[i];
}

String Read(istream &input)
{
	LinkList<char> tmp;
	int size = 0;
	char ch;
	while ((ch = input.peek()) != EOF && (ch = input.get()) != '\n')
	{	//peek()从输入流中取一个字符，输入流指针不变；get()从输入流中取一个字符，输入流指针指向下一字符
		tmp.Insert(++size, ch);
	}
	String answer(tmp);
	return answer;
}
String Read(istream &input, char &terminalChar)
{
	LinkList<char> tmp;
	int size = 0;
	char ch;
	while ((ch = input.peek()) != EOF && (ch = input.get()) != '\n')
		tmp.Insert(++size, ch);
	terminalChar = ch;
	String answer(tmp);
	return answer;
}
void Write(const String &s)
{
	cout << s.CStr() << endl;
}
void Concat(String &addTo, const String &addOn)
{
	const char *cFirst = addTo.CStr();
	const char *cSecond = addOn.CStr();
	char *copy = new char[strlen(cFirst) + strlen(cSecond) + 1];
	strcpy(copy, cFirst);
	strcat(copy, cSecond);
	addTo = copy;	//????????
	delete[]copy;
}
//void Copy(String &copy, const String &original); }
//void Copy(String &copy, const String &original, int n);
int Index(const String &target, const String &pattern, int pos = 0)
{
	const char *cTarget = target.CStr();
	const char *cPattern = pattern.CStr();
	const char *ptr = strstr(cTarget + pos, cPattern);
	if (ptr == NULL)
		return -1;
	else
		return ptr - cTarget;
}
//String SubString(const String &s, int pos, int len)
//{
//
//}
bool operator==(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) == 0;
}
bool operator<(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) < 0;
}
bool operator>(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) > 0;
}
bool operator<=(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) <= 0;
}
bool operator>=(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) >= 0;
}
bool operator!=(const String &first, const String &second)
{
	return strcmp(first.CStr(), second.CStr()) != 0;
}
*/