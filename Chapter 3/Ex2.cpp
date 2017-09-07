#include <iostream>
#include <cstdlib>
#include <iomanip>

#define HOUR_SMALLER_THAN_ZERO "Сʱ�����Ǹ�ֵ�����������룺"
#define HOUR_OUT_OF_BOUND "������24Сʱ�ƣ�Сʱ����24�����壬���������룺"
#define MINUTE_SMALLER_THAN_ZERO "���Ӳ����Ǹ�ֵ�����������룺"
#define MINUTE_OUT_OF_BOUND "����Խ�磬����������"

using namespace std;

/*
	��дһ�����򣬽���24Сʱ�Ʊ�ʾ��ʱ��ת��Ϊ12Сʱ�Ʊ�ʾ��ʱ�䡣���磬����20��16��20��16�֣������8:16pm������8��16��8��16�֣������8:16am��
*/

bool checkHour(int hour);
bool checkMinute(int minute);
int getTransformedHour(int hour);
char *getLabel(int hour);
char *formatting(int hour_transformed, int minute, char *label);
int countWidth(int number);

const int offset = 48; //ASCII '0' -> 48

int main()
{
	int hour;
	int minute;
	int hour_transformed;
	char *label;
	bool flag = true;
	cout << "������Сʱ��ֵ��";
	cin >> hour;
	cout << endl << "��������ӵ�ֵ��";
	cin >> minute;
	while(flag)
	{
		if(checkHour(hour))
		{
			if(checkMinute(minute))
			{
				flag = false;
			}
			else if(minute < 0)
			{
				cout << endl << MINUTE_SMALLER_THAN_ZERO;
				cin >> minute;
			}
			else if(minute > 59)
			{
				cout << endl << MINUTE_OUT_OF_BOUND;
				cin >> minute;
			}
		}
		else if(hour < 0)
		{
			cout << endl << HOUR_SMALLER_THAN_ZERO;
			cin >> hour;
			if(checkMinute(minute))
			{
				continue;
			}
			else if(minute < 0)
			{
				cout << endl << MINUTE_SMALLER_THAN_ZERO;
				cin >> minute;
			}
			else if(minute > 59)
			{
				cout << endl << MINUTE_OUT_OF_BOUND;
				cin >> minute;
			}
		}
		else if(hour > 23)
		{
			cout << endl << HOUR_OUT_OF_BOUND;
			cin >> hour;
			if(checkMinute(minute))
			{
				continue;
			}
			else if(minute < 0)
			{
				cout << endl << MINUTE_SMALLER_THAN_ZERO;
				cin >> minute;
			}
			else if(minute > 59)
			{
				cout << endl << MINUTE_OUT_OF_BOUND;
				cin >> minute;
			}
		}
	};
	
	hour_transformed = getTransformedHour(hour);
	label = getLabel(hour);
	formatting(hour_transformed, minute, label);
	cout << endl << "ת�����Ϊ��" << formatting(hour_transformed, minute, label) << endl << endl;
	system("pause");
	return 0;
}


bool checkHour(int hour)
{
	if(hour >= 0 && hour <= 23)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkMinute(int minute)
{
	if(minute >= 0 && minute <= 59)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getTransformedHour(int hour)
{
	hour %= 12;
	return hour;
}

char *getLabel(int hour)
{
	char *label;
	if(hour >= 0 && hour <= 24)
	{
		if(hour >= 0 && hour < 12)
		{
			label = "am";
		}
		else
		{
			label = "pm";
		}
	}
	else
	{
		cout << "Сʱֵ����" << endl;
	}
	return label;
}

char *formatting(int hour_transformed, int minute, char *label)
{
	static char done[7] = {0};
	done[2] = ':';
	//done[7] = '\0';
	if(countWidth(hour_transformed) == 1)
	{
		done[0] = (char)(0 + offset);
		done[1] = (char)(hour_transformed + offset);
	}
	else
	{
		done[0] = (char)(hour_transformed / 10 + offset);
		done[1] = (char)(hour_transformed % 10 + offset);
	}

	if(countWidth(minute) == 1)
	{
		done[3] = (char)(0 + offset);
		done[4] = (char)(minute + offset);
	}
	else
	{
		done[3] = (char)(minute / 10 + offset);
		done[4] = (char)(minute % 10 + offset);
	}
	
	done[5] = label[0];
	done[6] = label[1];

	return done; //���ؾֲ���������ִ��룬�ֲ�������ջ���ڴ��ַ��գ�
}

int countWidth(int number)
{
	int count = 1;
	while(number /= 10)
	{
		count++;
	}
	return count;
}