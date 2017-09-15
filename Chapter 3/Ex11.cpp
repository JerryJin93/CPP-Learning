#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

/*
	����1Ԫ��2Ԫ��5Ԫ�Ļ��ң��������ޣ�������㹺���ֵΪnԪ����Ʒ���ж�����֧����ʽ��Ҫ�����ÿһ��֧����ʽ����
*/

int main()
{
	int n;
	LinkedList<int> list;
	cout << "������ƻ����ѵĽ�Ԫ����";
	cin >> n;
	cout << endl << "���軨��1Ԫ���ҵ�����Ϊx������2Ԫ���ҵ�����Ϊy������5Ԫ���ҵ�����Ϊz�������������£�" << endl << endl;
	for(int x = 0; x < n; x++)
	{
		for(int y = 0; y < (n / 2); y++)
		{
			for(int z = 0; z < (n / 5); z++)
			{
				if(x + 2 * y + 5 * z == n)
				{
					list.insertAtTail(x);
					list.insertAtTail(y);
					list.insertAtTail(z);
				}
			}
		}
	}
	for(int i = 1; i <= list.getLength(); i += 3)
	{
		cout << setw(2) << "x = " << list.getData(i) << "   " << "y = " << list.getData(i + 1) << "   " << "z = " << list.getData(i + 2) << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}