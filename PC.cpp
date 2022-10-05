#include <iostream>
#include <string>
#include <vector>

using namespace std;


void mas(int a, vector<int> &number, size_t size) {
	for (int i = (size - 1); i >= 0; i--) {
		number[i] = a % 10;
		a /= 10;
	}
}

int exam(vector<int> number, size_t size) {
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int q = 0; q < size; q++) {
			if (number[i] == number[q] && i != q) k++;
		}
	}
	return k;
}

void num(int &a, vector<int> &number, size_t size) {
	int flag = 0;
	while (flag == 0) {
		mas(a, number, size);
		int k;
		k = exam(number, size);
		if (k != 0) {
			cout << "Введите УНИКАЛЬНОЕ число: ";
			cin >> a;
			cout << endl;
		}
		else flag = 1;
	}
}

void bulls_cows(int &bulls, int &cows, vector<int> number, vector<int> answer, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int q = 0; q < size; q++) {
			if (number[i] == answer[q]) {
				if (i == q) bulls++;
				else cows++;
			}
		}
	}
}

void win(int bulls, int &stop, int play) {
	if (bulls == 4) {
		stop = 1;
		cout << "Компьютер победил! Загаданное число: " << play << endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int a;
	cout << "Введите число: ";
	cin >> a;
	cout << endl;
	size_t size = to_string(a).length();
	vector<int> number(size);
	num(a, number, size);
	vector<int> answer(size);
	int play = 0;
	int stop = 0;
	int prov = 0;
	int bulls_ex, cows_ex;
	vector<int> number_ex(size);
	while (stop == 0) {
		play++;
		if (to_string(play).length() == size) {
			int bulls = 0, cows = 0, bulls_ex1 = 0, cows_ex1 = 0;
			mas(play, answer, size);
			int k = exam(answer, size);
			if (k == 0) {
				if (prov == 0) {
					cout << "Робот говорит: " << play << endl;
					bulls_cows(bulls, cows, number, answer, size);
					cout << "Количество быков: " << bulls << endl;
					cout << "Количество коров: " << cows << endl;
					prov = 1;
					number_ex = answer;
					bulls_ex = bulls;
					cows_ex = cows;

				}

				else {
					bulls_cows(bulls_ex1, cows_ex1, number_ex, answer, size);
					if (bulls_ex == 0 && cows_ex == 0 && bulls_ex1 == 0 && cows_ex1 == 0) {
						cout << "Компьютер говорит: " << play << endl;
						bulls_cows(bulls, cows, number, answer, size);
						cout << "Количество быков: " << bulls << endl;
						cout << "Количество коров: " << cows << endl;
						if (bulls > bulls_ex && cows < cows_ex) {
							number_ex = answer;
							cows_ex = cows;
							bulls_ex = bulls;
						}
					}
					else if (bulls_ex1 >= bulls_ex && cows_ex1 <= cows_ex) {
						cout << "Компьютер говорит число: " << play << endl;
						bulls_cows(bulls, cows, number, answer, size);
						cout << "Количество быков: " << bulls << endl;
						cout << "Количество коров: " << cows << endl;
						if (bulls > bulls_ex && cows <= cows_ex) {
							number_ex = answer;
							cows_ex = cows;
							bulls_ex = bulls;
						}
					}
				}
				win(bulls, stop, play);
			}
		}
	}
}