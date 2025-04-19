#include <iostream>
#include "Call.h"
using namespace std;

int _cdecl Call::func_1(int x, int y, int z) {
	return x + y + z;
}

int _stdcall Call::func_2(int& x, int y, int z) {
	return x * y * z;
}

int _fastcall Call::func_3(int x, int y, int z, int t) {
	return x + y + z + t;
}

int main() {
	setlocale(LC_ALL, "ru");

	int x, y, z, k, result_1, result_2, result_3;
	cout << "¬ведите значение чисел: " << endl;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;
	cout << "z = "; cin >> z;
	cout << "k = "; cin >> k;
	cout << endl;

	result_1 = Call::func_1(x, y, z);
	result_2 = Call::func_2(x, y, z);
	result_3 = Call::func_3(x, y, z, k);

	cout << "–езультат: " << endl;
	cout << "func_1(сумма): " << result_1 << endl;
	cout << "func_2(произведение): " << result_2 << endl;
	cout << "func_3(сумма): " << result_3 << endl;

	return 0;
}
