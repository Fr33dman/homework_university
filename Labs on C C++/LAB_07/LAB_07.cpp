
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <clocale>
#include <stdio.h>
#include <cstring>
#include <iomanip>
#include <fstream>

using namespace std;

const char fn[] = "post office database.txt";

struct Fio
{
	char* surname;
	char* name;
};

struct Date
{
	int day;
	char* month;
	int year;
};

struct Parcel
{
	Fio senderFio;
	char* senderAdress;
	Fio receiverFio;
	char* receiverAdress;
	double weight;
	Date departureDate;
};

int loadParcels(Parcel(*(&postOffice)))
{
	ifstream file(fn);
	if (!file)
		return 0;
	char buf[64];
	int n;
	file >> n;
	file.getline(buf, sizeof(buf));
	postOffice = (Parcel*)malloc(n * sizeof(Parcel));
	for (int i = 0; i < n; i++) {
		file.getline(buf, sizeof(buf));
		postOffice[i].senderFio.surname = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].senderFio.surname, buf);
		file.getline(buf, sizeof(buf));
		postOffice[i].senderFio.name = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].senderFio.name, buf);
		file.getline(buf, sizeof(buf));
		postOffice[i].senderAdress = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].senderAdress, buf);
		file >> postOffice[i].departureDate.day;
		file.getline(buf, sizeof(buf));
		file.getline(buf, sizeof(buf));
		postOffice[i].departureDate.month = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].departureDate.month, buf);
		file >> postOffice[i].departureDate.year;
		file.getline(buf, sizeof(buf));
		file.getline(buf, sizeof(buf));
		postOffice[i].receiverFio.surname = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].receiverFio.surname, buf);
		file.getline(buf, sizeof(buf));
		postOffice[i].receiverFio.name = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].receiverFio.name, buf);
		file.getline(buf, sizeof(buf));
		postOffice[i].receiverAdress = (char*)malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(postOffice[i].receiverAdress, buf);
		file >> postOffice[i].weight;
		file.getline(buf, sizeof(buf));
	}
	file.close();
	return n;
}

void saveParcels(Parcel* postOffice, int n)
{
	ofstream file(fn);
	if (!file)
	{
		cout << "Ошибка создания файла!" << endl;
		return;
	}
	file << n << endl;
	for (int i = 0; i < n; i++) {
		file << postOffice[i].senderFio.surname << endl;
		file << postOffice[i].senderFio.name << endl;
		file << postOffice[i].senderAdress << endl;
		file << postOffice[i].departureDate.day << endl;
		file << postOffice[i].departureDate.month << endl;
		file << postOffice[i].departureDate.year << endl;
		file << postOffice[i].receiverFio.surname << endl;
		file << postOffice[i].receiverFio.name << endl;
		file << postOffice[i].receiverAdress << endl;
		file << postOffice[i].weight << endl;
	}
	file.close();
}
void addParcel(Parcel(*(&postOffice)), int& nParcels)
{
	postOffice = (Parcel*)realloc(postOffice, (nParcels + 1) * sizeof(Parcel));
	char buf[256];
	cin.ignore(256, '\n');
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Фамилия отправителя: ";
	fgets(buf, 256, stdin);
	int length = strlen(buf);
	postOffice[nParcels].senderFio.surname = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderFio.surname, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Имя отправителя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].senderFio.name = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderFio.name, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Адрес отправителя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].senderAdress = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].senderAdress, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "День отправки: ";
	int tmp;
	cin >> tmp;
	postOffice[nParcels].departureDate.day = tmp;
	cout << endl;
	cout << "=====================================================" << endl;
	cin.ignore(256, '\n');
	cout << "Месяц отправки: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].departureDate.month = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].departureDate.month, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Год отправки: ";
	cin >> tmp;
	postOffice[nParcels].departureDate.year = tmp;
	cout << endl;
	cout << "=====================================================" << endl;
	cin.ignore(256, '\n');
	cout << "Фамилия получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverFio.surname = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverFio.surname, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Имя получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverFio.name = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverFio.name, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Адрес получателя: ";
	fgets(buf, 256, stdin);
	length = strlen(buf);
	postOffice[nParcels].receiverAdress = (char*)malloc(sizeof(char) * length);
	buf[length - 1] = '\0';
	strcpy(postOffice[nParcels].receiverAdress, buf);
	cout << endl;
	cout << "=====================================================" << endl;
	cout << "Введите вес посылки: ";
	cin >> tmp;
	postOffice[nParcels].weight = tmp;
	cout << "=====================================================" << endl;
	nParcels++;
}

void drawInformation(Parcel* postOffice, int a)
{
	cout << "=============================================================================================================================" << endl;
	cout << setw(15) << "Фамилия|" << setw(15) << "Имя|" << setw(15) << "Адрес|" << setw(20) << "Дата|" << setw(15) << "Фамилия|" << setw(15) << "Имя|" << setw(15) << "Адрес|" << setw(15) << "Вес|" << endl;
	cout << setw(15) << "Отправителя|" << setw(15) << "Отправителя|" << setw(15) << "Отправителя|" << setw(20) << "Отправки|" << setw(15) << "Получателя|" << setw(15) << "Получателя|" << setw(15) << "Получателя|" << setw(15) << "|" << endl;
	cout << "=============================================================================================================================" << endl;
	cout << setw(14) << postOffice[a].senderFio.surname << "|";
	cout << setw(14) << postOffice[a].senderFio.name << "|";
	cout << setw(14) << postOffice[a].senderAdress << "|";
	cout << setw(3) << postOffice[a].departureDate.day;
	cout << setw(11) << postOffice[a].departureDate.month;
	cout << setw(5) << postOffice[a].departureDate.year << "|";
	cout << setw(14) << postOffice[a].receiverFio.surname << "|";
	cout << setw(14) << postOffice[a].receiverFio.name << "|";
	cout << setw(14) << postOffice[a].receiverAdress << "|";
	cout << setw(14) << postOffice[a].weight << "|";
	cout << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl;

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
	int count = 0;
	for (int nParcels = 0; nParcels < n; nParcels++)
		if (strcmp(postOffice[nParcels].receiverAdress, str) == 0) {
			drawInformation(postOffice, nParcels);
			++count;
		}
	if (count == 0)
		cout << endl << "Посылки отсутствуют" << endl;
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
	int count = 0;
	for (int nParcels = 0; nParcels < n; nParcels++)
		if (strcmp(postOffice[nParcels].senderFio.surname, surname) == 0)
			if (strcmp(postOffice[nParcels].senderFio.name, name) == 0) {

				drawInformation(postOffice, nParcels);
				++count;

			}
	if (count == 0)
		cout << endl << "Посылки отсутствуют" << endl;
}

void sort(Parcel* postOffice, int n)
{
	Parcel tmp;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int cmp = strcmp(postOffice[i].receiverFio.surname, postOffice[j].receiverFio.surname);
			if (cmp > 0) {
				tmp = postOffice[i];
				postOffice[i] = postOffice[j];
				postOffice[j] = tmp;
			}
			if (cmp == 0)
				cmp = strcmp(postOffice[i].receiverFio.name, postOffice[j].receiverFio.name);
			if (cmp > 0) {
				tmp = postOffice[i];
				postOffice[i] = postOffice[j];
				postOffice[j] = tmp;
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

int monthCheck(Date date)
{
	int days;
	int nMonth;
	if (strcmp(date.month, "january") == 0)
		nMonth = 1;
	else if (strcmp(date.month, "february") == 0)
		nMonth = 2;
	else if (strcmp(date.month, "march") == 0)
		nMonth = 3;
	else if (strcmp(date.month, "april") == 0)
		nMonth = 4;
	else if (strcmp(date.month, "may") == 0)
		nMonth = 5;
	else if (strcmp(date.month, "june") == 0)
		nMonth = 6;
	else if (strcmp(date.month, "july") == 0)
		nMonth = 7;
	else if (strcmp(date.month, "august") == 0)
		nMonth = 8;
	else if (strcmp(date.month, "september") == 0)
		nMonth = 9;
	else if (strcmp(date.month, "october") == 0)
		nMonth = 10;
	else if (strcmp(date.month, "november") == 0)
		nMonth = 11;
	else if (strcmp(date.month, "december") == 0)
		nMonth = 12;
	else {
		cout << "Некорректный ввод месяца" << endl;
		return 0;
	}
	return nMonth;
}

int isOlderHY(Date date)
{
	time_t now = time(0);
	tm* tmParcel = new tm;
	tmParcel = localtime(&now);
	tmParcel->tm_year = date.year - 1900;
	tmParcel->tm_mon = monthCheck(date) - 1;
	tmParcel->tm_mday = date.day;
	time_t ttParcel = mktime(tmParcel);
	time_t HYAgo = (time(0) - 365.25 / 2 * 24 * 60 * 60);
	if (ttParcel < HYAgo)
		return 1;
	else
		return 0;
}

void findDate(Parcel* postOffice, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (isOlderHY(postOffice[i].departureDate)) {
			drawInformation(postOffice, i);
			++count;
		}
	if (count == 0)
		cout << endl << "Посылки отсутствуют" << endl;
}

void drawMenu()
{

	cout << "=======================================================" << endl;
	cout << "Добавить новую посылку                                1" << endl;
	cout << "Распечатать информацию о посылке                      2" << endl;
	cout << "Найти все посылки отправителя                         3" << endl;
	cout << "Найти все посылки с весом, больше заданного           4" << endl;
	cout << "Найти посылки, отправленные больше полугода назад     5" << endl;
	cout << "Выход из программы                                    6" << endl;
	cout << "=======================================================" << endl;
	cout << "Введите номер функции: ";

}

int main()
{

	setlocale(LC_ALL, "Russian");

	bool is_working = true;
	Parcel* post_office = (Parcel*)malloc(0 * sizeof(Parcel));

	int  n = 0;
	int option;

	n = loadParcels(post_office);

	while (is_working) {
		drawMenu();
		option = 0;
		scanf("%d", &option);
		switch (option) {
		case 1:
			addParcel(post_office, n);
			break;
		case 2:
			findInformation(post_office, n);
			break;
		case 3:
			findName(post_office, n);
			break;
		case 4:
			findWeight(post_office, n);
			break;
		case 5:
			findDate(post_office, n);
			break;
		case 6:
			saveParcels(post_office, n);
			isWorking = false;
			break;
		default:
			cout << "Ошибка ввода" << endl;
			cin.ignore(256, '\n');
			break;
		}
	}
	return 0;
}
