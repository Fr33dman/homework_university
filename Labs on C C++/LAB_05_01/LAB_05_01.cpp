
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <clocale>
#include <iomanip>
#include <cstring>

using namespace std;

char** initialize(int& count)
{

	char** tmp = 0;
	char** text = (char**)malloc(0 * sizeof(char*));
	char buf[256];

	while (true) {
		fgets(buf, 256, stdin);
		if (strcmp(buf, "ok\n") == 0)

			break;

		tmp = (char**)realloc(tmp, (count + 1) * sizeof(char*));

		if (tmp == NULL) {

			cout << "memory error" << endl;
			break;

		}

		else

			text = tmp;

		*(text + count) = (char*)malloc(strlen(buf) + 1);
		strcpy(text[count], buf);
		count++;

	}

	return text;

}

void setFormat(int* length, int* nLine)
{

	cout << "Введите длину строки: ";
	cin >> *length;

	cout << "Введите количество строк: ";
	cin >> *nLine;

	cout << endl;

}

bool isOdd(char symbol)
{

	if (symbol == '1' or symbol == '3' or symbol == '5' or symbol == '7' or symbol == '9')

		return true;

	else

		return false;
}

bool isEven(char symbol)
{

	if (symbol == '0' or symbol == '2' or symbol == '4' or symbol == '6' or symbol == '8')

		return true;

	else

		return false;

}

char* matrixEdit(char* str)
{

	//char* new_string = NULL;
	int orig_len = strlen(str);

	int* help = (int*)malloc((orig_len - 1) * sizeof(int));
	char* new_string = (char*)malloc((orig_len + 1) * sizeof(char));

	for (int i = 0; i < orig_len - 1; i++) {

		if (isOdd(str[i])) {

			help[i] = 0;

		}
		else {

			help[i] = 1;

		}

	}

	int j = 0;

	/*for (int i = 0; i < orig_len - 1; i++) {
		cout << help[i] << ' ';
	}*/

	for (int i = 0; i < orig_len - 1; i++) {

		if (help[i] == 1) {

			new_string[j] = str[i];
			j++;

			new_string[j] = str[i];
			j++;

		}

	}

	new_string[j] = '\n';
	new_string[j + 1] = '\0';
	cout << endl;

	//cout << new_string << "          ";

	return new_string;

}

char** matrixChange(char** text, int count)  // should try "\b"
{

	char** newText = (char**)malloc(2 * sizeof(text));

	//char** newText = (char**)malloc(0 * sizeof(char));

	//char** newText = text;

	for (int i = 0; i < count; i++)

		//newText[i] = (char*)realloc(newText[i], 2 * sizeof(text));
		//strcpy(newText[i], matrixEdit(text[i]));
		newText[i] = matrixEdit(text[i]);

	return newText;

}

void format(char** text, int length, int nLine, int count)
{

	int tmpLine = 0;
	int tmpLength = 0;

	for (int i = 0; i < count; i++) {

		for (int j = 0; j < strlen(text[i]); j++) {

			if (tmpLength == length) {

				cout << endl;
				++tmpLine;
				tmpLength = 0;

			}

			if (tmpLine == nLine) {

				cout << endl << "-----------" << endl;
				tmpLine = 0;

			}

			cout << text[i][j];
			++tmpLength;
			
		}

	}

}

void textDraw(char** text, int count)
{
	for (int i = 0; i < count; i++)

		cout << text[i];

}

int main()
{
	setlocale(LC_ALL, "Russian");


	int count = 0;
	char** text = initialize(count);

	//textDraw(text, count);

	int length, nLine;
	setFormat(&length, &nLine);

	char** newText = matrixChange(text, count);

	//textDraw(newText, count);

	format(newText, length, nLine, count);

	for (int i = 0; i < count; i++)

		free(text[i]);

	free(text);

	text = 0;

	return 0;

}
