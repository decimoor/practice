#include <iostream>
#include <string>
#include <clocale>
#include <cmath>
#define Rus setlocale(LC_ALL, "Rus")

using namespace std;
void make_arr(long long key, int arr[]);
int	number_size(long long key)
{

}
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