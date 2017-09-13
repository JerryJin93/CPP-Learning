#include <iostream>
#include <cstdlib>
#include <cmath>
#include "LinkedList.h"

using namespace std;

/*
	编写一个程序，从键盘输入一个正整数，判断该正整数是否为回文数。回文数是指从正向和反向两个方向读数字都一样，例如，9783879就是一个回文数。
*/

int getWidth(unsigned int number);
LinkedList<unsigned int> parseNumber(unsigned int number);
bool isTrue(unsigned number);

int main()
{
	unsigned int number;
	cout << "请输入一个正整数：";
	cin >> number;
	if(isTrue(number))
	{
		cout << endl << "这是一个回文数" << endl << endl;
	}
	else
	{
		cout << endl << "这不是一个回文数" << endl << endl;
	}
	system("pause");
	return 0;
}

int getWidth(unsigned int number)
{
	int width = 1;
	while(number /= 10)
	{
		width++;
	}
	return width;
}

LinkedList<unsigned int> parseNumber(unsigned int number)
{
	LinkedList<unsigned int> list;
	int bit, tmp;
	int width = getWidth(number);
	if(width > 2)
	{
		tmp = number;
		while(width-- > 1)
		{
			bit = tmp / (int)pow((double)10, (double)width);
			list.insertAtTail(bit);
			tmp = number - (number / (int)pow((double)10, (double)width) * (int)pow((double)10, (double)width));
		}
		list.insertAtTail(number % 10);
	}
	else
	{
		list.insertAtTail(number / 10);
		list.insertAtTail(number % 10);
	}
	return list;
}

bool isTrue(unsigned int number)
{
	bool judge;
	LinkedList<unsigned int> list1, list2;
	list1 = parseNumber(number);
	list2 = list1.inverse();
	if(list1.equals(list2))
	{
		judge = true;
	}
	else
	{
		judge = false;
	}
	return judge;
}