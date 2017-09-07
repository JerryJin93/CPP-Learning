#include <iostream>
#include <cstdlib>
#include <iomanip>

#define HOUR_SMALLER_THAN_ZERO "小时不能是负值，请重新输入："
#define HOUR_OUT_OF_BOUND "由于是24小时制，小时大于24无意义，请重新输入："
#define MINUTE_SMALLER_THAN_ZERO "分钟不能是负值，请重新输入："
#define MINUTE_OUT_OF_BOUND "分钟越界，请重新输入"

using namespace std;

/*
	编写一个程序，将用24小时制表示的时间转换为12小时制表示的时间。例如，输入20和16（20点16分），输出8:16pm；输入8和16（8点16分），输出8:16am。
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
	cout << "请输入小时的值：";
	cin >> hour;
	cout << endl << "请输入分钟的值：";
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
	cout << endl << "转换结果为：" << formatting(hour_transformed, minute, label) << endl << endl;
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
		cout << "小时值错误！" << endl;
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

	return done; //返回局部变量会出现代码，局部变量出栈，内存地址清空！
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