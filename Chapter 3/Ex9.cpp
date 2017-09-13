#include <iostream>
#include <cstdlib>
#include <cmath>
#include "LinkedList.h"

using namespace std;

/*
	��дһ��������������������λ�������ǵ������ǵĸ�λ���ֵ������͡����磺
		153 = pow(1, 3) + pow(3, 3) + pow(5, 3)
*/

int getWidth(int number);
LinkedList<int> parseNumber(int number);

int main()
{
	LinkedList<int> parseResult, list;
	for(int i = 100; i <= 999; i++)
	{
		parseResult = parseNumber(i);
		if(i == (int)pow((double)parseResult.getData(1), (double)3) + (int)pow((double)parseResult.getData(2), (double)3) + (int)pow((double)parseResult.getData(3), (double)3))
		{
			list.insertAtTail(i);
		}
	}
	cout << "������Ľ��Ϊ��";
	list.printLinkedList();
	system("pause");
	return 0;
}

int getWidth(int number)
{
	int width = 1;
	while(number /= 10)
	{
		width++;
	}
	return width;
}

LinkedList<int> parseNumber(int number)
{
	LinkedList<int> list;
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