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
	delete[] data;
	unsigned n = 0;
	while (s[n] != '\0')
		n++;
	length = n;
	return *this;
}

inline
string& vlyf::string::operator=(const string& str)
{
	if (this == &str) return *this;
	delete[]data;
	unsigned len = str.Length();
	data = new char[len];
	for (unsigned i = 0; i < len; i++)
		data[i] = str[i];
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
