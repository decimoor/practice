#include <iostream>
#include <string>
#include <clocale>

using namespace std;
void make_arr(long long key, int arr[]);
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