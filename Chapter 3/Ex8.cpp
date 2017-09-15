#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define PRECISION 1e-8

/*
	编写一个程序计算圆周率。可利用公式：
		π / 4 = 1 - 1 / 3 + 1 / 5 - 1 / 7 + ...
	直到最后一项的绝对值小于pow(10, -8)
*/

int main()
{
	long double pi = 0;
	int count = 1;
	long double factor;
	long double add = 1;
	cout << endl << "正在计算圆周率，精确到小数点后8位，由于没有经过数学方面的优化，收敛速度很慢，请稍后..." << endl << endl;
	do
	{
		if(count % 2 == 0)
		{
			factor = -1;
		}
		else{
			factor = 1;
		}
		pi += factor / add;
		add += 2;
		count++;
	}
	while(fabs(factor / add) >= PRECISION);
	cout << setprecision(8) << "精确到小数点后8位的圆周率是：" << 4 * pi << endl << endl;
	system("pause");
	return 0;
}