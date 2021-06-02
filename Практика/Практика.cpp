#include <iostream>
#include <fstream>
#include <string> //для string'а
#include <clocale> //для великого и могучего
#include <cmath> //для возведения в степень
#include <Windows.h> //тоже для великого и могучего
#include <ctime>


using namespace std;

ifstream file("pswrds.txt");

void make_arr(long long key, int arr[]); //тут мы создаем массив из цифр ключа то есть если ключ 123456, то массив: [1,2,3,4,5,6]
int	number_size(long long key); //тут у нас размер ключа (количество цифр)
char letter(char l, int k); //функция, которая меняет букву по ключу, то есть A и ключ 2 получится В
char letter_backward(char l, int k);
string crypt(string sentence, long long key); //функция которая все это объединяет
string uncrypt(string sentence, long long key); //расшифровывает сообщение
void load(string title);
bool checking(string password);



int main()
{
	setlocale(LC_ALL, "Rus");
	setlocale(0, "Rus");
	SetConsoleCP(1251); //дичь, чтобы буквы адекватно выводились
	SetConsoleOutputCP(1251);
	cout << "Введите пароль: ";
	string sentence;
	getline(cin, sentence); //считываем строку целиком (cin так не может)
	long long key;
	srand(time(0));
	key = rand();
	string new_one = crypt(sentence, key);
	load("Шифруем пароль: ");
	cout << "\nПароль успешно зашифрован";
	load("Передача пароля на сервер: ");
	cout << "\nПередача завершена!";
	string old_one = uncrypt(new_one, key);
	load("Сервер: расшифровка сообщения: ");
	if (checking(old_one))
	{
		cout << "\nВы успешно авторизованы!";
	}
	else
	{
		cout << "\nПароль неверный!";
	}
}

void make_arr(long long key, int arr[])
{
	int size = number_size(key);
	int exp = pow(10, size - 1);
	for (int i = 0; i < size; i++)
	{
		arr[i] = key / exp;
		key = key % exp;
		exp /= 10;
	}

}

int number_size(long long key)
{
	int size = 0;
	while (key >= 10)
	{
		key /= 10;
		size++;
	}
	return ++size;
}

char letter(char l, int k)
{
	int place = 0;
	if (l >= -64 && l <= -33)
	{
		place = (l +64 + k) % 32;
		l = -64 + place;
	}
	if (l >= -32 && l <= -1)
	{
		place = (l + 32 + k) % 32;
		l = -32 + place;
	}
	return l;
}

char letter_backward(char l, int k)
{
	int place = 0;
	if (l >= -64 && l <= -33)
	{
		place = (l + 64 - k);
		if (place < 0)

		{
			place = 32 + place;
		}
		
		l = -64 + place;
	}
	if (l >= -32 && l <= -1)
	{
		place = (l + 32 - k);
		if (place < 0)
		{
			place = 32 + place;
		}
		l = -32 + place;
	}
	return l;
}
string crypt(string sentence, long long key) //функция которая все это объединяет
{
	int arr[100]; //массив с цифрами ключа
	make_arr(key, arr);
	string new_sentence = sentence; //инициализация зашифрованного сообщения
	int size = number_size(key);
	for (int i = 0; i < sentence.size(); i++)
	{
		new_sentence[i] = letter(sentence[i], arr[i % size]); //шифруем каждую букву по отдельности
	}
	return new_sentence;
}

string uncrypt(string sentence, long long key)
{
	int size = number_size(key);
	int arr[100];
	make_arr(key, arr);
	string old_one = sentence;
	for (int i = 0; i < sentence.size(); i++)
	{
		old_one[i] = letter_backward(sentence[i], arr[i % size]);
	}
	return old_one;

}
void load(string title)
{
	string line = title + " [ ";
	for (int i = 0; i < 30; i++)
	{
		line += "#";
		Sleep(rand()%300);
		cout << "\r" << line;
	}
	cout << "\r" << line + " ]";
}

bool checking(string password)
{
	string ps;
	while (!file.eof())
	{
		getline(file, ps, '\n');
		if (ps == password)
		{
			return true;
		}
	}
	return false;
}