#include <iostream>

using namespace std;

bool fuck(int(&array)[3][3], int row, int column, int number)
{
	bool flag = false;

	if (array && (row >= 0 && column >= 0))
	{
		int i = 0;
		int j = column - 1;
		while (i < row && j >= 0)
		{
			if (number > array[i][j])
				i++;
			else if (number < array[i][j])
				j--;
			else
			{
				flag = true;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int a[3][3] = { 1, 2, 8, 2, 4, 9, 4, 7, 10 };

	cout << fuck(a, 3, 3, 8) << endl;
	return 0;
}