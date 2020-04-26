//Общие задания :
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

void First();
void Second();
void Third();


int main()
{
	First();
	Second();
	Third();

	return 0;
}


void First()
{
	cout << "Exersize #1" << endl;

	char str[] = "PrOgRaMmInG, TeStInG, EnDing.";
	cout << "String before transforming: " << str << endl;

	char ch = str[0];
	int i = 0;

	while (ch != '\0')
	{
		if (('A' <= str[i]) && (str[i] <= 'Z'))
			str[i] ^= 0x20;
		i++;
		ch = str[i];
	}

	cout << "String after transforming: " << str << endl;
}


void Second()
{
	cout << endl << endl << "Exersize #2" << endl;
	char sent[] = "Do you like programming? \nI love programming \nBut sometimes I lose my head from love.";
	char word[] = "programming";

	size_t n = 0;
	size_t len = strlen(word);

	for (const char* src = sent; (src = strstr(src, word)) != NULL; src += len)
	{
		n++;
	}

	cout << "Text: " << endl << sent << endl;
	cout << endl << "Word for searching:  " << word << endl;
	cout << endl << "The number of same words: " << n << endl;
}



void Third()
{
	cout << endl << endl << "Exersize #3" << endl;

	/* Массив для хранения введенной строки */
	char String[30000] = "I love programming!";

	cout << endl << "String before sorting:  " << String << endl;

	/* Массив номеров позиций, с которых начинаются слова */
	int Words[15000];

	/* Количество введенных слов */
	int Number;


	int i, j, Temp;
	int Flag; /* Признак окончания слова */

	/* Предварительная обработка */
	for (Number = 0, Flag = 1, i = 0; String[i]; i++)
	{
		/* Все пробелы заменяем на символ конца строки */
		if (String[i] == ' ')
		{
			String[i] = 0;
			Flag = 1;
		}
		/* Позиции первых после пробелов символов записываем в массив */
		else if (Flag)
		{
			Words[Number++] = i;
			Flag = 0;
		}
	}

	/* Сортировка */
	for (j = Number - 1; j > 0; j--)
		for (i = 0; i < j; i++)
			if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
			{
				Temp = Words[i];
				Words[i] = Words[i + 1];
				Words[i + 1] = Temp;
			}



	/* Вывод результата */
	cout << endl << "Sorted words:" << endl;
	for (i = 0; i < Number; i++)
		cout << &String[Words[i]] << endl;
}
