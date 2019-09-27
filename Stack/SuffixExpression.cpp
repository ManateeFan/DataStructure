

#include <iostream>
#include "ArrayStack.h"
using namespace std;

/*数组栈的实现*/
template<typename T>
ArrayStack<T>::ArrayStack(int s)
{
	array = new T[s];
	capacity = s;
};
template<typename T>
ArrayStack<T>::~ArrayStack()
{
	delete array;
};
//判空
template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0;
};
//获取栈的大小
template<typename T>
int ArrayStack<T>::size()
{
	return count;
};
//入栈
template<typename T>
void ArrayStack<T>::push(T t)
{
	if (count != capacity)
	{
		array[count++] = t;
	}
};
//出栈
template<typename T>
T ArrayStack<T>::pop()
{
	if (count != 0)
	{
		return array[--count];
	}
};
//获取栈顶元素
template<typename T>
T ArrayStack<T>::top()
{
	if (count != 0)
	{
		return array[count - 1];
	}
};
class Calculator
{
public:
	void Run()
	{
		char ch;
		double newOperand;
		while (cin >> ch && ch != '#')
		{
			switch (ch)
			{
			case '+':
				DoOperator(ch);
				break;
			case '-':
				DoOperator(ch);
				break;
			case '*':
				DoOperator(ch);
				break;
			case '/':
				DoOperator(ch);
				break;
			default:cin.putback(ch);
				cin >> newOperand;
				AddOperand(newOperand);
			}
		}
		cout << s.top();
	}
private:
	ArrayStack<double> s;
	bool Get2operands(double& left, double& right)
	{
		if (s.isEmpty())
			return false;
		right = s.pop();
		left = s.pop();
		return true;
	}
	void DoOperator(char op)
	{
		double left, right, value;
		int result;
		result = Get2operands(left, right);
		if (result == true)
		{
			switch (op)
			{
			case '+':
				value = left + right;
				s.push(value);
				break;
			case '-':
				value = left - right;
				s.push(value);
				break;
			case '*':
				value = left * right;
				s.push(value);
				break;
			case '/':
				if (right == 0)
					exit(0);
				value = left / right;
				s.push(value);
				break;
			}
		}
	}
	void AddOperand(double value)
	{
		s.push(value);
	}
};
int main()
{
	Calculator calc;
	calc.Run();
}




