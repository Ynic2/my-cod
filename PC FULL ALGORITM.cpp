#include <iostream>
#include <string>
#include <vector>

using namespace std;

void mas(int a, vector<int>& number, size_t size) {
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

vector<int> num(int& a) {
	int flag = 0;
	while (flag == 0) {
		size_t size = to_string(a).length();
		vector<int> vec(size);
		mas(a, vec, size);
		if (exam(vec, size) == 0) {
			return vec;
			break;
		}
		else {
			cout << "Введите УНИКАЛЬНОЕ число:";
			cin >> a;
		}
	}
}

void bulls_cows(int& bulls, int& cows, vector<int> number, vector<int> answer, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int q = 0; q < size; q++) {
			if (number[i] == answer[q]) {
				if (i == q) bulls++;
				else cows++;
			}
		}
	}
}

void win(int bulls, int& stop, int play,size_t size) {
	if (bulls == size) {
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
	vector<int> number(0);
	number = num(a);
	size_t size = number.size();
	vector<int> answer(size);
	int play = 0;
	int stop = 0;
	int prov = 0;
	int bulls_ex, cows_ex;
	int lenght = 0;
	vector<vector<int>> number_ex(0);
	vector<vector<int>> bc_ex(0);
	while (stop == 0) {
		play++;
		if (to_string(play).length() == size) {
			int bulls = 0, cows = 0, bulls_ex1 = 0, cows_ex1 = 0;
			mas(play, answer, size);
			int k = exam(answer, size);
			if (k == 0) {
				if (prov == 0) {
					bulls_cows(bulls, cows, number, answer, size);
					cout << "Компьютер говорит: " << play << endl;
					cout << "Количество быков: "<<bulls<<endl;
					cout << "Количество коров: "<<cows<<endl;
					number_ex.push_back(answer);
					lenght++;
					vector<int> bc;
					bc = { bulls,cows };
					bc_ex.push_back(bc);
					prov = 1;
				}
				else {
					int c = 0;
					for (int i = 0; i < lenght; i++) {
						bulls_cows(bulls_ex1, cows_ex1, number_ex[i], answer, size);
						vector<int> bc_ex1(0);
						bc_ex1 = { bulls_ex1, cows_ex1 };
						if (bc_ex1 == bc_ex[i]) {
							c++;

						}
						bulls_ex1 = 0;
						cows_ex1 = 0;
					}
					if (c == lenght) {
						bulls_cows(bulls, cows, number, answer, size);
						cout << "Копмьютер говорит: " << play << endl;	
						cout << "Количество быков: "<<bulls<<endl ;
						cout << "Количество коров: " << cows << endl;
						number_ex.push_back(answer);
						lenght++;
						vector<int> bc;
						bc = { bulls,cows };
						bc_ex.push_back(bc);
					}
				}
				win(bulls, stop, play,size);
			}
		}
	}
}