#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>


using namespace std;

void First();
void Second();
int Palindrom(char* String);
int Fourth();



int main()
{
	setlocale(LC_ALL, "");
	First();
	Second();

	
	cout << endl << endl << "Exersize #3" << endl;

	char String[256];
	cout << "Enter your sentence: ";
	cin.getline(String, 256);

	int f = Palindrom(String);

	if (f == 0)
		cout << endl << "It is not palindrom!";
	else
		cout << endl << "It is palindrom!";
	//---------------------------------------------


	Fourth();

	return 0;
}


void First()
{
	cout << "Exersize #1" << endl;

	char str[255];
	cout << endl << "Enter your string: " << endl;
	cin.getline(str, 255);

	char ch = str[0];
	int n = 0;
	int k = 0;

	while (ch != '\0')
	{
		n++;
		k++;
		ch = str[k];
	}

	cout << endl << "Length of string: " << n << endl;
}


void Second()
{
	cout << endl << endl << "Exersize #2" << endl;
	srand(time(0));

	char article[2][16]{ "the", "a" };
	char noun[5][20]{ "front", "heat", "hate", "turn", "account" };
	char verb[5][20]{ "say", "go", "get", "do", "be" };
	char predlog[5][10]{ "after", "above", "in", "from", "beside" };

	char str[255] = "";

	strcat(str, article[rand() % 2]);

	if (strlen(str) == 0)
		strcat(str, noun[rand() % 5]);
	else
	{
		strcat(str, " ");
		strcat(str, noun[rand() % 5]);
	}

	strcat(str, " ");
	strcat(str, verb[rand() % 5]);
	strcat(str, " ");
	strcat(str, predlog[rand() % 5]);
	strcat(str, " ");
	strcat(str, article[rand() % 2]);
	strcat(str, " ");
	strcat(str, noun[rand() % 5]);
	strcat(str, ".");

	str[0] ^= 0x20;


	cout << "Generated sentence:  " << str << endl;
}


int Palindrom(char String[])
{
	char str[256] = "";
	int k = 0;

	for (int i = 0; i < strlen(String); i++)
	{
		if (isalpha(String[i]))
		{
			str[k] = String[i];
			k++;
		}
	}


	for (int i = 0; i < strlen(str); i++)
		if (tolower(str[i]) != tolower(str[strlen(str) - 1 - i]))
			return 0;

	return 1;
}



int Fourth()
{
	cout << endl << endl << "Exersize #4";

	ifstream f;
	char buk[87] = "qwetryuiopasdfghjklzxcbvnm";
	char pre[4] = "!?.";
	char str[255] = "";
	char temp[100];

	int pred, slov;
	pred = slov = 0;
	char ch;

	f.open("input.txt");


	if (!f)
	{
		printf("Cannot open input file.\n");
		return 0;
	}

	while (!f.eof())
	{
		f >> (temp);
		strcat(str, temp);
		strcat(str, " ");
	}

	cout << endl << "Text:  " << str;


	f.close();




	//----------------
	f.open("input.txt");

	while (!f.eof())
	{
		ch = f.get();
		if (ch == ' ' || ch == '\n' || ch == '\t')
			slov++; //Считает пробелы, табуляцию и переход на следущую строку.
	}

	cout << endl << "Words in text: " << slov + 1; //на 1 слово больше так как пробела после него нет.
	f.close();
	
	f.open("input.txt");
	while (!f.eof())
	{
		ch = f.get();

		for (int i = 0; i < 3; i++)
			if (ch == pre[i])
			{
				pred++;
				break;
			}
	}

	f.close();
	cout << endl << "Sentences in text: " << pred;

	return 1;
}
