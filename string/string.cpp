#include "string.h"

using namespace vlyf;

inline
vlyf::string::string()
{
	length = 0;
	data = new char[0];
}

inline
string::string(const char* str)
{
	if (str)
	{
		unsigned n = 0;
		while (str[n] != '\0') n++;
		data = new char[n];
		length = n;
		for (unsigned i = 0; i < n; i++)
		{
			data[i] = str[i];
		}
	}
	else
	{
		length = 0;
		data = new char[0];
	}
}

inline
string::string(const string& str)
{
	unsigned len = str.Length();
	length = len;
	data = new char[len];
	for (unsigned i = 0; i < len; i++)
	{
		data[i] = str[i];
	}
}

inline
string::~string()
{
	delete[]data;
}

inline
unsigned string::Length() const
{
	return length;
}

int string::Index(char c) const
{
	for (unsigned i = 0; i < Length(); i++)
	{
		if (c == data[i]) return i;
	}
	return -1;
}

inline
void string::UpCase(unsigned first, unsigned last)
{
	while (first++ < last)
	{
		if ('a' <= data[first] && data[first] <= 'z')
			data[first] -= ('a' - 'A');
	}
}

inline
void string::LowCase(unsigned first, unsigned last)
{
	while (first++ < last)
	{
		if ('A' <= data[first] && data[first] <= 'Z')
			data[first] += ('a' - 'A');
	}
}


const char& vlyf::string::operator[](unsigned i) const
{
	return data[i];
}

char& vlyf::string::operator[](unsigned i)
{
	return data[i];
}

string& vlyf::string::operator=(const char* s)
{
	char* temp = data;					//保存原本数据，确保异常安全性
	unsigned n = 0;
	while (s[n] != '\0')
		n++;
	length = n;
	data = new char[n];
	for (unsigned i = 0; i < n; i++)
		data[i] = s[i];
	delete[] temp;
	return *this;
}

inline
string& vlyf::string::operator=(const string& str)
{
	if (this == &str) return *this;
	char* temp = str.data;				//保存原本数据，确保异常安全性

	unsigned len = str.Length();
	data = new char[len];
	for (unsigned i = 0; i < len; i++)
		data[i] = str[i];
	length = len;
	delete[] temp;
	return *this;
}

inline
string& string::operator+=(const string& str)
{
	unsigned len = length + str.Length();
	char* ss = new char[len];
	for (unsigned i = 0; i < Length(); i++)
		ss[i] = data[i];
	for (unsigned i = 0; i < str.Length(); i++)
		ss[i + length] = str[i];
	delete[]data;
	data = ss;
	length = len;
	return *this;
}




std::ostream& vlyf::operator<<(std::ostream& os, const string& str)
{
	if (str.Length() > 0)
	{
		for (unsigned i = 0; i < str.Length(); i++)
			os << str[i];
	}
	else
	{
		os << "";
	}
	return os;
}

std::istream& vlyf::operator>>(std::istream& is,string& str)
{
	char* ss = new char[1000];
	is >> ss;
	str = string(ss);
	return is;
}

string vlyf::operator+(const string& lhs, const string& rhs)
{
	return string(lhs) += rhs;
}

string vlyf::operator+(const string& lhs, const char* rhs)
{
	return string(lhs) += string(rhs);
}

string vlyf::operator+(const char* lhs, const string& rhs)
{
	return string(lhs) += string(rhs);
}


bool vlyf::operator==(const string& lhs, const string& rhs)
{
	if (lhs.Length() != rhs.Length())
		return false;
	unsigned n = 0;
	unsigned len = lhs.Length();
	while (lhs[n] == rhs[n] && len != n)
		n++;
	return n == len;
}

bool vlyf::operator!=(const string& lhs, const string& rhs)
{
	if (lhs.Length() != rhs.Length())
		return true;
	unsigned n = 0;
	unsigned len = lhs.Length();
	while (lhs[n] == rhs[n] && len != n)
		n++;
	return n != len;
}

bool vlyf::operator<(const string& lhs, const string& rhs)
{
	unsigned min = (lhs.Length() < rhs.Length()) ? lhs.Length() : rhs.Length();
	unsigned n = 0;
	while (lhs[n] == rhs[n] && n != min)
		n++;
	if (n == min) return lhs.Length() < rhs.Length();
	else
	{
		if (lhs[n] < rhs[n])
			return lhs.Length() < rhs.Length();
		else
			return lhs.Length() > rhs.Length();
	}
}

bool vlyf::operator>(const string& lhs, const string& rhs)
{
	return lhs < rhs;
}

int main()
{
	string s1 = "123";
	std::cout << "s1:" << s1 << "		length: " << s1.Length() << std::endl;

	string s2("456");
	std::cout << "s2:" << s2 << "		length: " << s2.Length() << std::endl;

	string s3(s1);
	std::cout << "s3:" << s3 << "		length: " << s3.Length() << std::endl;

	string s4 = s3;
	std::cout << "s4:" << s4 << "		length: " << s4.Length() << std::endl;

	string s5(s1);
	s5 += s2;
	std::cout << "s5:" << s5 << "		length: " << s5.Length() << std::endl;

	string s6(s5);
	std::cout << "s6:" << s6 << "		length: " << s6.Length() << std::endl;

	if (s5 == s6) std::cout << "s5 == s6:		true" << std::endl;

	string s7 = s1 + "456";
	std::cout << "s7:" << s7 << "		length: " << s7.Length() << std::endl;

	string s8 = "456" + s1;
	std::cout << "s8:" << s8 << "		length: " << s8.Length() << std::endl;

	string s9 = s7 + s8;
	std::cout << "s9:" << s9 << "		length: " << s9.Length() << std::endl;

	return 0;
}