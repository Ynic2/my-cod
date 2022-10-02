#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
	//Создание рандомного числа
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	size_t size;
	int stop = 0;
	while (stop == 0) {
		cout << "Введите количество разрядов:" << endl;
		cin >> size;
		if (size <= 9 && size > 0) {
			stop = 1;
		}
	}
	vector<int> number(size);
	number[0] = 1 + rand() % (8+1);
	for (int i = 1; i < size; i++) {
		int pos;
		pos = rand() % (9 + 1);
		number[i] = pos;
	}
	vector<int> number_ex(size);
	number_ex = number;
	int ok = 0;
	while (ok == 0) {
		int k = 0;
		for (int i = 1; i < size; i++) {
			for (int q = 0; q < size; q++) {
				if (number[i] == number_ex[q] && i != q) {
					number[i] = rand() % (9 + 1);
					number_ex = number;
					k++;
				}
			}
		}
		if (k == 0) {
			ok = 1;
		}
	}
	for (int i = 0; i < size; i++) {
		cout << number[i];
	}
	//Конец рандомного числа
	//Ввод числа пользователем
	int res = 0;
	while (res == 0) {
		int a;
		int stop1 = 0;
		vector<int> input(size);
		while (stop1 == 0) {
			int c = 0;
			cout << "Введите уникальное число с разрядом " << size << ":" << endl;
			cin >> a;
			for (int i = (size - 1); i >= 0; i--) {
				input[i] = a % 10;
				a = a / 10;
				c++;
			}
			if (c == size) {
				stop1 = 1;
			}
		}

		//Конец ввода
		//Проверка и результаты
		int bulls = 0;
		int cows = 0;
		int prov = 0;
		vector<int> input_ex(size);
		input_ex = input;
		for (int i = 0; i < size; i++) {
			for (int q = 0; q < size; q++) {
				if (input[i] == input_ex[q] && i != q) {
					prov++;
				}
			}
		}
		if (prov == 0) {
			for (int i = 0; i < size; i++) {
				for (int q = 0; q < size; q++) {
					if (number[i] == input[q] && i == q) {
						bulls++;
					}
					else if (number[i] == input[q] && i != q) {
						cows++;
					}
				}
			}
			if (bulls == size) {
				cout << "Вы победили!!" << endl;
				res = 1;
			}
			else {
				cout << "Количество коров: " << cows << endl;
				cout << "Количество быков: " << bulls << endl;
			}
		}
	}
}