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
		friend std::ostream& operator<<(std::ostream& os, const string& str);
		friend std::istream& operator>>(std::istream& is, string& str);

		// access operators
		const char& operator[](unsigned i) const;	//const string 
		char& operator[](unsigned i);

		// asignment operators
		string& operator=(const char* s);
		string& operator=(const string& str);
		string& operator+=(const string& str);

		// string concatenation
		friend string operator+(const string& lhs, const string& rhs);
		friend string operator+(const string& lhs, const char* rhs);
		friend string operator+(const char* lhs, const string& rhs);

		// logical opreators
		friend bool operator==(const string& lhs, const string& rhs);
		friend bool operator!=(const string& lhs, const string& rhs);
		friend bool operator<(const string& lhs, const string& rhs);
		friend bool operator>(const string& lhs, const string& rhs);
	};
}
