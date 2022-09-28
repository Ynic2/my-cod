#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
	//�������� ���������� �����
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	size_t size;
	int stop = 0;
	while (stop == 0) {
		cout << "������� ���������� ��������:" << endl;
		cin >> size;
		if (size <= 9 && size > 0) {
			stop = 1;
		}
	}
	vector<int> number(size);
	number[0] = 1 + rand() % 8;
	for (int i = 1; i < size; i++) {
		int pos;
		pos = rand() % 9 + 1;
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
					number[i] = rand() % 9 + 1;
					number_ex = number;
				}
				else {
					k++;
				}
			}
		}
		if (k == (size-1)*size) {
			ok = 1;
		}
	}
	for (int i = 0; i < size; i++) {
		cout << number[i];
	}
	cout << endl;
	//����� ���������� �����
	//���� ����� �������������
	int res = 0;
	while (res==0){
		int a;
		int stop1 = 0;
		while (stop1 == 0) {
			cout << "������� ����� � �������� " << size << ":"<< endl;
			cin >> a;
			if (a >= pow(10,size-1) && a < pow(10,size) ){
				stop1 = 1;
			}
		}
		vector<int> input(size);
		for (int i = (size-1); i >= 0; i--) {
			input[i] = a % 10;
			a = a / 10;
		}
		//����� �����
		//�������� � ����������
		int bulls = 0;
		int cows = 0;
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
			cout << "�� ��������!!"<<endl;
			res = 1;
		}
		else {
			cout << "���������� �����: " << cows<<endl;
			cout << "���������� �����: " << bulls<<endl;
		}
	}
}