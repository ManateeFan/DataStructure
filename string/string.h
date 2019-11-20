#pragma once

#include <iostream>

namespace vlyf
{
	class string
	{
	private:
		char* data;
		unsigned length;
	public:
		// constructor
		string();
		string(const char& ch);
		string(const char* str);
		string(const string& str);

		// destructor
		~string();

		// information methods
		unsigned Length() const;
		int Index(char c) const;

		// case methods
		void UpCase(unsigned first, unsigned last);
		void LowCase(unsigned first, unsigned last);

		// stream operators
		friend std::ostream& operator<<(std::ostream&, const string&);
		friend std::istream& operator>>(std::istream&, const string&);

		// access operators
		const char& operator[](unsigned i) const;
		char& operator[](unsigned i);
		char& at(unsigned i);

		// asignment operators
		string& operator=(const char* s);
		string& operator=(const string& str);
		string& operator+=(const string& str);

		// string concatenation
		friend string operator+(const string& str1, const string& str2);
		friend string operator+(const string& str, const char* s);
		friend string operator+(const char* s, const string& str);

		// logical opreators
		friend bool operator==(const string& str1, const string& str2);
		friend bool operator!=(const string& str1, const string& str2);
		friend bool operator<(const string& str1, const string& str2);
		friend bool operator>(const string& str1, const string& str2);
		friend bool operator<=(const string& str1, const string& str2);
		friend bool operator>=(const string& str1, const string& str2);
	};
}
