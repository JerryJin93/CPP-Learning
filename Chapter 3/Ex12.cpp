#include <iostream>
#include <cstdlib>
#include <cmath>
#include "LinkedList.h"

using namespace std;

/*
	��дһ�����򣬴Ӽ�������һ�����������жϸ��������Ƿ�Ϊ����������������ָ������ͷ���������������ֶ�һ�������磬9783879����һ����������
*/

int getWidth(unsigned int number);
LinkedList<unsigned int> parseNumber(unsigned int number);
bool isTrue(unsigned number);

int main()
{
	unsigned int number;
	cout << "������һ����������";
	cin >> number;
	if(isTrue(number))
	{
		cout << endl << "����һ��������" << endl << endl;
	}
	else
	{
		cout << endl << "�ⲻ��һ��������" << endl << endl;
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