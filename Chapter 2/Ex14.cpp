#include <iostream>
#include <cstdlib>

using namespace std;

/*
	在你的计算机平台上用C++程序计算表达式(x+1)*(++x)+(x++)。（假设x的初值为1。）
*/

int main()
{
	int expression;
	int x;
	cout << "需要计算的表达式是：(x+1)*(++x)+(x++)\n\n";
	cout << "请输入x的值：";
	cin >> x;
	expression = (x+1)*(++x)+(x++);
	cout << "\n表达式的结果是：" << expression << "\n\n";
	system("pause");
	return 0;
}