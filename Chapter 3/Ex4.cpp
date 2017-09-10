#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

/*
	编写一个程序，从键盘输入一个正整数，判断该正整数为几位数，并输出其位数。
*/

int getWidth(unsigned int number);
LinkedList<unsigned int> parseNumber(unsigned int number);
int power(int a, int b);

int main()
{
	unsigned int number;
	LinkedList<unsigned int> list;
	cout << "请输入一个正整数：";
	cin >> number;
	while(number < 0)
	{
		cout << endl << "必须输入正整数！请重新输入：";
		cin >> number;
	}
	list = parseNumber(number);
	cout << endl << "您输入的数的位数是："<< getWidth(number) << "位" << endl << endl << "每一位数从高位往低位依次是：";	
	list.printLinkedList();
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
	unsigned int bit, tmp;
	int width = getWidth(number);

	if(width > 2)
	{
		tmp = number;
		while(width-- > 1)
		{
			bit = tmp / power(10, width);
			list.insertAtTail(bit);
			tmp = number - (number / power(10,width) * power(10, width));
		}
		list.insertAtTail(number % 10);
		return list;
	}
	else
	{
		list.insertAtTail(number / 10);
		list.insertAtTail(number % 10);
		return list;
	}
}

int power(int a, int b)
{
	int res = a;
	for(int i = 0; i < b - 1; i++)
	{
		res = res * a;
	}
	return res;
}