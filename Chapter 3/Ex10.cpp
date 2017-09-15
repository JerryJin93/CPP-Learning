#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;

#define min(a, b) ((a < b) ? a : b)

/*
	编写一个程序，求a和b的最大公约数。
*/

int main()
{
	int a,b;
	LinkedList<int> list;
	cout << "请输入两个数字（a和b），以SPACE键隔开：";
	cin >> a >>  b;
	for(int i = 1; i <= min(a,b); i++)
	{
		if(a % i == 0 && b % i == 0)
		{
			list.insertAtTail(i);
		}
	}
	cout << endl << a << "和" << b << "的最大公约数是：";
	list.printNode(list.getLength());
	cout << endl;
	system("pause");
	return 0;
}