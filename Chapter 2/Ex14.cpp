#include <iostream>
#include <cstdlib>
using namespace std;

/*
	����ļ����ƽ̨����C++���������ʽ(x+1)*(++x)+(x++)
*/
int main()
{
	int expression;
	int x;
	cout << "��Ҫ����ı��ʽ�ǣ�(x+1)*(++x)+(x++)\n\n";
	cout << "������x��ֵ��";
	cin >> x;
	expression = (x+1)*(++x)+(x++);
	cout << "\n���ʽ�Ľ���ǣ�" << expression << "\n\n";
	system("pause");
	return 0;
}