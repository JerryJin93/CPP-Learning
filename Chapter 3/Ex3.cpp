#include <iostream>
#include <cstdio>
#include <cstdlib>
//#include <cstring>

using namespace std;

/*
	��дһ�����򣬷ֱ�������������Сд��ĸa~z��
*/

char* getAlphabet(char *option);
void printAlphabet(char *alphabet, char *option);

int main()
{
	printAlphabet(getAlphabet("LowerCase"), "Forward");
	printAlphabet(getAlphabet("LowerCase"), "Backward");
	printAlphabet(getAlphabet("UpperCase"), "Forward");
	printAlphabet(getAlphabet("UpperCase"), "Backward");
	cout << endl;
	system("pause");
	return 0;
}

char* getAlphabet(char *option)
{
	static char alphabet[26] = {0};
	int offset;
	if(!strcmp(option, "LowerCase"))
	{
		offset = 97;
	}
	else if(!strcmp(option, "UpperCase"))
	{
		offset = 65;
	}
	for(int i = 0; i < 26; i++)
	{
		alphabet[i] = i + offset;
	}
	return alphabet;
}

void printAlphabet(char *alphabet, char *option)
{
	if(!strcmp(option, "Forward"))
	{
		for(int i = 0; i < 26; i++)
		{
			cout << alphabet[i] << " ";
		}
		cout << endl;
	}
	else if(!strcmp(option, "Backward"))
	{
		for(int i = 25; i>= 0; i--)
		{
			cout << alphabet[i] << " ";
		}
		cout << endl;
	}
	
}