#include <iostream>
#include "Varparm.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int result_iparm = Varparm::ivarparm(1, 2);
	cout << result_iparm << endl;
	result_iparm = Varparm::ivarparm(2, 1, 4);
	cout << result_iparm << endl;
	result_iparm = Varparm::ivarparm(3, 1, 4, 5);
	cout << result_iparm << endl;
	result_iparm = Varparm::ivarparm(7, 1, 4, 2, 6, 7, 7, 8);
	cout << result_iparm << endl;

	int result_sparm = Varparm::svarparm(1, 2);
	cout << result_sparm << endl;
	result_iparm = Varparm::svarparm(2, 1, 4);
	cout << result_sparm << endl;
	result_iparm = Varparm::svarparm(3, 1, 4, 5);
	cout << result_sparm << endl;
	result_iparm = Varparm::svarparm(7, 1, 4, 2, 6, 7, 7, 8);
	cout << result_sparm << endl;

	double result_fparm = Varparm::fvarparm(1, FLT_MAX);
	result_fparm = Varparm::fvarparm(1, 4, FLT_MAX);
	result_fparm = Varparm::fvarparm(1, 4, 5, FLT_MAX);
	result_fparm = Varparm::fvarparm(1, 4, 2, 6, 7, 7, 8, FLT_MAX);
	cout << result_fparm << endl;

	double result_dparm = Varparm::dvarparm(2, DBL_MAX);
	result_dparm = Varparm::dvarparm(1, 4, DBL_MAX);
	result_dparm = Varparm::dvarparm(1, 4, 5, DBL_MAX);
	result_dparm = Varparm::dvarparm(1, 4, 2, 6, 7, 7, 8, DBL_MAX);
	cout << result_dparm << endl;

	return 0;
}