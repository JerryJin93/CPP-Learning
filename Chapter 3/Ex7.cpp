#include <iostream>
#include <cstdlib>

using namespace std;

/*
	�ٶ��ʼİ����ļƷѱ�׼���£������ڵ���֮��ʱ����һ��������
	
	�������ˣ�       �շѣ�Ԫ��
	  15               5
	  30               9
	  45               12
	  60               14��ÿ��1000�������1Ԫ��
	  60����           15��ÿ��1000�������2Ԫ��
	  
	��дһ��������������������ʼľ��룬���㲢����շ����
*/

float cashier(float weight, float distance);

int main()
{
	float weight, distance;
	cout << "����������������ʼľ��룬�м���SPACE������";
	cin >> weight >> distance;
	while(weight < 15 || distance <= 0) // 01 10 11
	{
		if(weight < 15 && distance > 0)
		{
			cout << endl << "������˼����Ͱ���������������15�ˣ������Ѿ�����15�ˣ��������������������";
			cin >> weight;
		}
		else if(weight >= 15 && distance <= 0)
		{
			cout << endl << "������˼���ʼľ�������������������������ʼľ��룺";
			cin >> distance;
		}
		else if(weight < 15 && distance <= 0)
		{
			cout << endl << "������˼����Ͱ����������ܵ���15�ˣ����ʼľ��������������������������������꣬���������룬�м���SPACE������";
			cin >> weight >> distance;
		}
	}
	cout << endl << "�������ס�����ļ��㣬�ֹ���Ҫ�շѣ�" << cashier(weight, distance) << "Ԫ" << endl << endl;
	system("pause");
	return 0;
}

float cashier(float weight, float distance)
{
	float payment;
	if(weight >= 15 && weight < 30)
	{
		payment = 5;
	}
	else if(weight >= 30 && weight < 45)
	{
		payment = 9;
	}
	else if(weight >= 45 && weight < 60)
	{
		payment = 12;
	}
	else if(weight == 60)
	{
		payment = 14 + distance / 1000;
	}
	else
	{
		payment = 15 + distance / 1000 * 2;
	}
	return payment;
}