
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <stdio.h>
#include <cstring>
#include <iomanip>

using namespace std;

struct Parcel
{

	char* senderSurname;
	char* senderName;
	char* senderAdress;
	char* receiverSurname;
	char* receiverName;
	char* receiverAdress;
	double weight;

};

Parcel addParcel(Parcel(*(&postOffice)), int& nParcels)
{

	postOffice = (Parcel*)realloc(postOffice, (nParcels + 1) * sizeof(Parcel));
	char buf[256];
	cin.ignore(256, '\n');

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Фамилия отправителя: ";
	fgets(buf, 256, stdin);
	int length = strlen(buf);
	postOffice[nParcels].senderSurname = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderSurname, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Имя отправителя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].senderName = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderName, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Адрес отправителя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].senderAdress = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderAdress, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Фамилия получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverSurname = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverSurname, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Имя получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverName = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverName, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	cout << "Адрес получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverAdress = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverAdress, buf);

	cout << endl;
	cout << "-----------------------------------------------------" << endl;

	int tmp;
	cout << "Введите вес посылки: ";
	cin >> tmp;
	postOffice[nParcels].weight = tmp;

	cout << "-----------------------------------------------------" << endl;

	nParcels++;

}

void drawInformation(Parcel* postOffice, int a)
{

	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << "Фамилия|" << setw(15) << "Имя|" << setw(15) << "Адрес|" << setw(15) << "Фамилия|" << setw(15) << "Имя|" << setw(15) << "Адрес|" << setw(15) << "Вес|" << endl;
	cout << setw(15) << "Отправителя|" << setw(15) << "Отправителя|" << setw(15) << "Отправителя|" << setw(15) << "Получателя|" << setw(15) << "Получателя|" << setw(15) << "Получателя|" << setw(15) << "|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;

	cout << setw(14) << postOffice[a].senderSurname << "|";
	cout << setw(14) << postOffice[a].senderName << "|";
	cout << setw(14) << postOffice[a].senderAdress << "|";
	cout << setw(14) << postOffice[a].receiverSurname << "|";
	cout << setw(14) << postOffice[a].receiverName << "|";
	cout << setw(14) << postOffice[a].receiverAdress << "|";
	cout << setw(14) << postOffice[a].weight << "|";
	cout << endl;

	cout << "---------------------------------------------------------------------------------------------------------" << endl;

}

void findInformation(Parcel* postOffice, int n) 
{

	char buf[256];
	cin.ignore(256, '\n');

	cout << "-----------------------------------------------------" << endl;
	cout << "Введите адрес доставки: ";
	fgets(buf, 256, stdin);
	int length = strlen(buf);
	char* str = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(str, buf);

	for (int nParcels = 0; nParcels < n; nParcels++)

		if (strcmp(postOffice[nParcels].receiverAdress, str) == 0)

			drawInformation(postOffice, nParcels);

}

void findName(Parcel* postOffice, int n)
{

	char buf[256];
	cin.ignore(256, '\n');

	cout << "-----------------------------------------------------" << endl;
	cout << "Введите фамилию отправителя: ";
	fgets(buf, 256, stdin);
	int length = strlen(buf);
	char* surname = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(surname, buf);

	cout << "-----------------------------------------------------" << endl;
	cout << "Введите имя отправителя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	char* name = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(name, buf);

	cout << "-----------------------------------------------------" << endl;

	for (int nParcels = 0; nParcels < n; nParcels++)

		if (strcmp(postOffice[nParcels].senderSurname, surname) == 0)

			if (strcmp(postOffice[nParcels].senderName, name) == 0)

				drawInformation(postOffice, nParcels);

			else

				cout << "Посылки нет в базе данных";

}

void sort(Parcel* postOffice, int n)
{
	Parcel tmp;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			int cmp = strcmp(postOffice[i].receiverSurname, postOffice[j].receiverSurname);
			if (cmp > 0) {

				tmp = postOffice[i];
				postOffice[i] = postOffice[j];
				postOffice[j] = tmp;

			}
			if (cmp == 0) {

				cmp = strcmp(postOffice[i].receiverName, postOffice[j].receiverName);

				if (cmp > 0) {

					tmp = postOffice[i];
					postOffice[i] = postOffice[j];
					postOffice[j] = tmp;

				}
			}
		}
}

void findWeight(Parcel* postOffice, int n)
{

	int weight;
	cout << "Введите требуемый вес: ";
	cin >> weight;

	cout << endl;

	Parcel* answer = (Parcel*)malloc(n * sizeof(Parcel));

	int tmp = 0;


	for (int nParcels = 0; nParcels < n; nParcels++)
		if (postOffice[nParcels].weight > weight) {

			answer[tmp] = postOffice[nParcels];
			++tmp;

		}

	if (tmp == 0) {

		cout << "Нет посылок с весом, больше данного." << endl;
		return;

	}

	sort(answer, tmp);

	for (int i = 0; i < tmp; i++)

		drawInformation(answer, i);

}

void drawMenu()
{

	cout << "-----------------------------------------------------" << endl;
	cout << "Добавить новую посылку      ........................1" << endl;
	cout << "Распечатать информацию о посылке  ..................2" << endl;
	cout << "Найти все посылки отправителя    ...................3" << endl;
	cout << "Найти все посылки с весом, больше заданного     ....4" << endl;
	cout << "Выход из программы    ..............................5" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Введите номер функции: ";

}

int main()
{

	setlocale(LC_ALL, "Russian");

	bool isWorking = true;

	Parcel* postOffice = (Parcel*)malloc(0 * sizeof(Parcel));
	int nParcels = 0;
	int option;

	while (isWorking) {

		drawMenu();

		option = 0;
		scanf("%d", &option);

		switch (option) {

		case 1:

			addParcel(postOffice, nParcels);
			break;

		case 2:

			findInformation(postOffice, nParcels);
			break;

		case 3:

			findName(postOffice, nParcels);
			break;

		case 4:

			findWeight(postOffice, nParcels);
			break;

		case 5:

			isWorking = false;
			break;

		default:

			cout << "Ошибка пользовательского ввода" << endl;
			break;
		}

	}

	return 0;

}
