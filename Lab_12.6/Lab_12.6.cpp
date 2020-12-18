#include <iostream>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

struct Cherha
{
	Cherha* link;
	string s;
};

int Start(ifstream& file_load, Cherha*& first, Cherha*& last);
void Print(Cherha*& first, Cherha*& T, const int N);
void inversia(Cherha* G, Cherha* T, Cherha*& first, int kilkist);

int main(void)
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Cherha* first = NULL;
	Cherha* last = NULL;

	char fname[51];
	cout << "Введіть назву файлу для зчитування слів: "; cin >> fname; cout << endl;

	ifstream file_load;
	file_load.open(fname);
	int kilkist = Start(file_load, first, last);
	file_load.close();

	cout << "Сформована черга за допомогою зчитування з текстового файлу: " << endl << endl;
	Cherha* T = first;
	Print(first, T, kilkist);

	T = first;
	Cherha* G = first;
	inversia(G, T, first, kilkist - 1);

	int kilkist_z, zmina = 0;
	cout << "Виведення заданої кількості елементів черги(скільки?)(можливо " << kilkist << " елементів): "; cin >> kilkist_z;
	cout << endl;

	T = first;
	Print(first, T, kilkist_z + 1);

	cout << "Модифікована черга(відбулася інверсія слів): " << endl << endl;
	T = first;
	Print(first, T, kilkist);

	return 0;
}

int Start(ifstream& file_load, Cherha*& first, Cherha*& last)
{
	string str;
	int kilkist = 0;

	while (!file_load.eof())
	{
		file_load >> str;
		Cherha* tmp = new Cherha;
		tmp->s = str;
		tmp->link = NULL;
		if (first == NULL)
			first = tmp;
		else
			last->link = tmp;
		last = tmp;
		kilkist++;
	}
	return kilkist;
}

void Print(Cherha*& first, Cherha*& T, const int N)
{
	string str;
	int index = 0;

	while (index < N - 1)
	{
		str = T->s;
		cout << str << "   ";
		T = T->link;
		index++;
	}
	cout << endl << endl;
}

void inversia(Cherha* G, Cherha* T, Cherha*& first, int kilkist)
{
	string str;
	int zmina = 0;                   // 1(ініціалізіція змінної 'zmina' значенням 0)
	string str_x, str_y;
	int kil, l = -1;
	if (kilkist % 2)
		kil = (kilkist / 2) + 1;
	else
		kil = kilkist / 2;

	do
	{
		l++;                         // 2(змінна 'l' збільшилася на одиницю)
		while (zmina < kilkist - 1)
		{
			G = G->link;             // 3(вказівник 'G' переходить на наступну позицію)
			zmina++;                 // 4(змінна 'zmina' збільшилася на одиницю)
		}
		str_y = G->s;                // 5(зміна 'str_y' отримує значення елемента черги)
		str_x = T->s;                // 6(зміна 'str_ч' отримує значення елемента черги)

		G->s = str_x;                // 7(інформаційне поле елемента черги отримує значеннч змінної 'str_y')
		T->s = str_y;                // 8(інформаційне поле елемента черги отримує значеннч змінної 'str_x')

		G = first;                   // 9(вказівник отримує значення(адресу) від вказівника 'first')
		kilkist--;                   // 10(змінна 'l' зменшилася на одиницю)
		zmina = 0;                   // 11(змінна 'zmina' отримує значення 0)

		T = T->link;                 // 12(вказівник 'T' переходить на наступну позицію)
	} while (l < kil - 1);
}