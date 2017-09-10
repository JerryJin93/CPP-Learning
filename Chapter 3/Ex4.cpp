#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

/*
	��дһ�����򣬴Ӽ�������һ�����������жϸ�������Ϊ��λ�����������λ����
*/

int getWidth(unsigned int number);
LinkedList<unsigned int> parseNumber(unsigned int number);
int power(int a, int b);

int main()
{
	unsigned int number;
	LinkedList<unsigned int> list;
	cout << "������һ����������";
	cin >> number;
	while(number < 0)
	{
		cout << endl << "�������������������������룺";
		cin >> number;
	}
	list = parseNumber(number);
	cout << endl << "�����������λ���ǣ�"<< getWidth(number) << "λ" << endl << endl << "ÿһλ���Ӹ�λ����λ�����ǣ�";	
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