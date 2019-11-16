#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
//为CMyString添加赋值运算函数

class CMyString
{
public:
	CMyString(const char* pData);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator=(const CMyString& str);

	void print();

private:
	char* m_pData;
};

CMyString::CMyString(const char* pData)
{
	if (!pData)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[]m_pData;
}

inline
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;
	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}
inline
void CMyString::print()
{
	printf("%s\n", m_pData);
}
int main()
{
	CMyString s1("123");
	CMyString s2(s1);
	CMyString s3("456");
	cout << "s1: ";
	s1.print();
	cout << "s2: ";
	s2.print();
	cout << "s3: ";
	s3.print();
	s1 = s2 = s3;
	cout << "s1: ";
	s1.print();
	cout << "s2: ";
	s2.print();
	return 0;
}
