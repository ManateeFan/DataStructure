#include <iostream>


using namespace std;

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
void ReplaceBlank(char* const& str, int n)
{
	int length;
	int nBlank = 0;
	for (length = 0; str[length] != '\0'; length++)
	{
		if (str[length] == ' ')
			nBlank++;
	}
	int reLength = length + 2 * nBlank;
	char* begin = &str[length] - 1;
	char* end = &str[reLength] - 1;
	while (begin != str-1)
	{
		if (*begin == ' ')
		{
			*end = '0';
			*(end - 1) = '2';
			*(end - 2) = '%';
			end -= 3;
			begin--;
		}
		else
		{
			*end = *begin;
			end--;
			begin--;
		}
	}
	str[reLength] = '\0';
}
int main()
{
	char str[20] = " a b ";
	ReplaceBlank(str, 20);
	cout << str;
	return 0;
}