#include <iostream>
#include <string> //для string'а
#include <clocale> //для великого и могучего
#include <cmath> //для возведения в степень
#include <Windows.h> //тоже для великого и могучего
#define Rus setlocale(LC_ALL, "Rus")

using namespace std;

void make_arr(long long key, int arr[]); //тут мы создаем массив из цифр ключа то есть если ключ 123456, то массив: [1,2,3,4,5,6]
int	number_size(long long key); //тут у нас размер ключа (количество цифр)
char letter(char l, int k); //функция, которая меняет букву по ключу, то есть A и ключ 2 получится В
string cypher(string sentence, long long key); //функция которая все это объединяет


int main()
{
	Rus;
	SetConsoleCP(1251); //дичь, чтобы буквы адекватно выводились
	SetConsoleOutputCP(1251);
	cout << "Введите предложение: ";
	string sentence;
	getline(cin, sentence); //считываем строку целиком (cin так не может)
	cout << "Введите ключ: ";
	long long key;
	cin >> key;
	string new_one = cypher(sentence, key);
	cout << "Зашифрованное предложение: " << new_one;
	//ну типо все
	//внизу реализцаия некоторых функций, но там ничего интересного
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
	return size+1;
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

string cypher(string sentence, long long key) //функция которая все это объединяет
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