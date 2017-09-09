#include <iostream>
#include <cstdlib>

using namespace std;

/*
	编写一个程序，将华氏温度转换为摄氏温度。转换公式为：
		c=5/9(f-32)
	其中，c为摄氏温度，f为华氏温度。
*/

int main()
{
	float c;
	float f;
	cout << "请输入即将被转换的华氏温度（℉）的值：";
	cin >> f;
	c = 5.0/9*(f-32);
	cout << endl << "转换结果得到的摄氏温度（℃）的值是：" << c << endl << endl;
	system("pause");
	return 0;
}