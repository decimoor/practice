#include <iostream>
#include <string>
#include <clocale>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#define Rus setlocale(LC_ALL, "Rus")

using namespace std;
void make_arr(long long key, int arr[]);
int	number_size(long long key);
char letter(char l, int k);
string cypher(string sentence, long long key)
{
	int arr[100];
	make_arr(key, arr);
	string new_sentence;
	return new_sentence;
}

int main()
{
	cout << "Введите предложение: ";
	string sentence;
	cin >> sentence;
	cout << "Введите ключ: ";
	long long key;
	cin >> key;
	string new_one = cypher(sentence, key);
	cout << "Зашифрованное предложение: " << new_one;
	Rus;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	


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