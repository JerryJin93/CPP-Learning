#include <iostream>
#include <cstdlib>

using namespace std;

/*
	��дһ�����򣬽������¶�ת��Ϊ�����¶ȡ�ת����ʽΪ��
		c=5/9(f-32)
	���У�cΪ�����¶ȣ�fΪ�����¶�
*/

int main()
{
	float c;
	float f;
	cout << "�����뼴����ת���Ļ����¶ȣ��H����ֵ��";
	cin >> f;
	c = 5.0/9*(f-32);
	cout << endl << "ת������õ��������¶ȣ��棩��ֵ�ǣ�" << c << endl << endl;
	system("pause");
	return 0;
}