#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

#define min(a, b) ((a < b) ? a : b)

/*
	��дһ��������a��b�����Լ����
*/

int main()
{
	int a,b;
	LinkedList<int> list;
	cout << "�������������֣�a��b������SPACE��������";
	cin >> a >>  b;
	for(int i = 1; i <= min(a,b); i++)
	{
		if(a % i == 0 && b % i == 0)
		{
			list.insertAtTail(i);
		}
	}
	cout << endl << a << "��" << b << "�����Լ���ǣ�";
	list.printNode(list.getLength());
	cout << endl;
	system("pause");
	return 0;
}