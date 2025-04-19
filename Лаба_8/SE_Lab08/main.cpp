#include <iostream>
using namespace std;

int defaultparm(int num_1, int num_2, int num_3, int num_4, int num_5, int num_6 = 3, int num_7 = 4) {
	return (num_1 + num_2 + num_3 + num_4 + num_5) / 7;
}

int main() {
	setlocale(LC_ALL, "ru");
	int num_1 = 1, num_2 = 2, num_3 = 3, num_4 = 4, num_5 = 5, num_6 = 6, num_7 = 7;

	

	int result = defaultparm(num_1, num_2, num_3, num_4, num_5);
	cout << "Функция dfaultparm вернула " << result << endl;
	
	result = defaultparm(num_1, num_2, num_3, num_4, num_5, num_6, num_7);
	cout << "Функция dfaultparm вернула " << result << endl;
	return 0;
}