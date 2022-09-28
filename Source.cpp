#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	//Ввод числа пользователем
	setlocale(LC_ALL, "ru");
	size_t size;
	int a,stop=0;
	while (stop == 0) {
		size = 0;
		cout << "Введите четырехзначное число:" << endl;
		cin >> a;
		int b = a;
		while (b > 0) {
			b = b / 10;
			size++;
		}
		if (size == 4) {
			stop = 1;
		}
	}
	vector<int> input(size);
	for (int i = size - 1; i >= 0; i--) {
		input[i] = a % 10;
		a /= 10;
	}
	//Конец ввода
	//Пк отгадывает
	vector<int> number(size);
	int bulls = 0, cows = 0;
	for (int q = 1; q <= 9; q++) {
		number[0] = q;
		if (bulls == 4) {
			break;
		}
		for (int w = 0; w <= 9; w++) {
			number[1] = w;
			if (bulls == 4) {
				break;
			}
			for (int e = 0; e <= 9; e++) {
				number[2] = e;
				if (bulls == 4) {
					break;
				}
				for (int r = 0; r <= 9; r++) {
					number[3] = r;
					vector<int> number_ex(size);
					number_ex = number;
					int k=0;
					for (int i = 0; i < size; i++) {
						for (int x = 0; x < size; x++) {
							if (number[i] == number_ex[x] && i != x) {
								k++;
							}
							
						}
					}
					if (k == 0) {
						cout << number[0] << number[1] << number[2] << number[3];
						for (int i = 0; i < size; i++) {
							for (int x = 0; x < size; x++) {
								if (number[i] == input[x] && i == x) {
									bulls++;
								}
								if (number[i] == input[x] && i != x) {
									cows++;
								}
							}

						}
						if (bulls == 4) {
							cout << "Компьютер победил!" << endl;
							break;
						}
						else {
							cout << "Количество коров: " << cows << endl;
							cout << "Количество быков: " << bulls << endl;
							cows = 0;
							bulls = 0;
						}
					}
				}
			}
		}
	}
}