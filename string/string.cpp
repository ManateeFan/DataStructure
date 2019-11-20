#include "string.h"

inline
vlyf::string::string() : data(new char('\0')), length(0) {}

inline
vlyf::string::string(const char& ch):length(1)
{
	data = new char[2];
	data[0] = ch;
	data[1] = '\0';
}

inline
vlyf::string::string(const string& str)
{
	unsigned len = str.Length();
	data = new char[len + 1];
	for (unsigned i = 0; i < len; i++)
	{
		data[i] = str[i];
	}
	data[len] = '\0';
}

inline
vlyf::string::~string()
{
	delete[]data;
}

inline
unsigned vlyf::string::Length() const
{
	return Length();
}

int vlyf::string::Index(char c) const
{
	for (unsigned i = 0; i < Length(); i++)
	{
		if (c == data[i]) return i;
	}
	return -1;
}

inline
void vlyf::string::UpCase(unsigned first, unsigned last)
{
	while (first++ < last)
	{
		if ('a' <= data[first] && data[first] <= 'z')
			data[first] -= ('a' - 'A');
	}
}

inline
void vlyf::string::LowCase(unsigned first, unsigned last)
{
	while (first++ < last)
	{
		if ('A' <= data[first] && data[first] <= 'Z')
			data[first] += ('a' - 'A');
	}
}

inline
const char& vlyf::string::operator[](unsigned i) const
{
	if (i < Length()) return data[i];
	else return data[0];
}

inline
char& vlyf::string::operator[](unsigned i)
{
	if (i < Length()) return data[i];
	else return data[0];
}

inline
char& vlyf::string::at(unsigned i)
{
	if (i < Length()) return data[i];
	else return data[0];
}

inline
string& vlyf::string::operator=(const char* s)
{
	if (s == *this) return *this;
	delete[]data;
	unsigned len, i;
	for (i = 0; s[i] != '\0'; i++)
	{
	}
	len = i;
	data = new char[len];
	for (unsigned j = 0; j < Length(); j++)
		data[i] = s[i];
	return *this;
}

inline
string& vlyf::string::operator=(const string& str)
{
	if (&str == this) return *this;
	delete[]data;
	for (unsigned i = 0; i < str.Length(); i++)
		data[i] = str[i];
	return *this;
}

string& vlyf::string::operator+=(const string& str)
{
	unsigned len = Length() + str.Length();
	char* ss = new char[len];
	for (unsigned i = 0; i < Length(); i++)
		ss[i] = data[i];
	for (unsigned i = 0; i < str.Length(); i++)
		ss[i + length] = str[i];
	delete[]data;
	data = ss;
	return *this;
}


std::ostream& vlyf::operator<<(std::ostream& os, string str) 
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


std::istream& vlyf::operator>>(std::istream& is, const string& str)
{
	char* ss = new char[1000];
	is >> ss;
	str = string(ss);
	return is;
}
