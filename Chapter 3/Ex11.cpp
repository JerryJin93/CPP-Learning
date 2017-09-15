#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

/*
	现有1元、2元和5元的货币（数量不限），请计算购买价值为n元的物品，有多少种支付方式（要求输出每一种支付方式）。
*/

int main()
{
	int n;
	LinkedList<int> list;
	cout << "请输入计划花费的金额（元）：";
	cin >> n;
	cout << endl << "假设花费1元货币的数量为x，花费2元货币的数量为y，花费5元货币的数量为z，则输出结果如下：" << endl << endl;
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