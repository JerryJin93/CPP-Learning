#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define PRECISION 1e-8

/*
	��дһ���������Բ���ʡ������ù�ʽ��
		�� / 4 = 1 - 1 / 3 + 1 / 5 - 1 / 7 + ...
	ֱ�����һ��ľ���ֵС��pow(10, -8)
*/

int main()
{
	long double pi = 0;
	int count = 1;
	long double factor;
	long double add = 1;
	cout << endl << "���ڼ���Բ���ʣ���ȷ��С�����8λ������û�о�����ѧ������Ż��������ٶȺ��������Ժ�..." << endl << endl;
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
	cout << setprecision(8) << "��ȷ��С�����8λ��Բ�����ǣ�" << 4 * pi << endl << endl;
	system("pause");
	return 0;
}