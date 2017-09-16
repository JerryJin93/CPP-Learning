#include <iostream>
#include <cstdlib>

using namespace std;

/*
	假定邮寄包裹的计费标准如下（重量在档次之间时往上一档靠）：
	
	重量（克）       收费（元）
	  15               5
	  30               9
	  45               12
	  60               14（每满1000公里加收1元）
	  60以上           15（每满1000公里加收2元）
	  
	编写一个程序，输入包裹重量和邮寄距离，计算并输出收费数额。
*/

float cashier(float weight, float distance);

int main()
{
	float weight, distance;
	cout << "请输入包裹重量和邮寄距离，中间用SPACE隔开：";
	cin >> weight >> distance;
	while(weight < 15 || distance <= 0) // 01 10 11
	{
		if(weight < 15 && distance > 0)
		{
			cout << endl << "不好意思，最低包裹重量的限制是15克，现在已经低于15克，请重新输入包裹重量：";
			cin >> weight;
		}
		else if(weight >= 15 && distance <= 0)
		{
			cout << endl << "不好意思，邮寄距离必须是正数，请重新输入邮寄距离：";
			cin >> distance;
		}
		else if(weight < 15 && distance <= 0)
		{
			cout << endl << "不好意思，最低包裹重量不能低于15克，且邮寄距离必须是正数，您的两个参数都不达标，请重新输入，中间用SPACE隔开：";
			cin >> weight >> distance;
		}
	}
	cout << endl << "经过靠谱、合理的计算，现共需要收费：" << cashier(weight, distance) << "元" << endl << endl;
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