#include <iostream>

using namespace std;

void hello() {
	cout << "Hello, World!";
}

int main() {
	setlocale(LC_ALL, "ru");
	//Task 4
	bool a = false;
	bool b = true;
	int size_bool = sizeof(bool);

	//Task 5
	char letter = 'e';
	int size_letter = sizeof(char);

	//Task 6 
	char letter_0 = 'е';
	int size_letter_0 = sizeof(char);

	//Task 7
	wchar_t letter_1 = 'r';
	int size_letter_1 = sizeof(wchar_t);

	//Task 8
	wchar_t letter_2 = 'р';
	int size_letter_2 = sizeof(wchar_t);

	//Task 9
	/*
	21(dec) = 21/16 = 15(hex) = f
	-21(dec) = -25(oct) = -10101(bin) = 1000 0000 0001 0101(пк) = 1111 1111 1110 1010(ок) = 1111 1111 1110 1011(дк) = ffeb(hex)
	*/
	short X = 21;
	short X2 = -21;
	int size_x = sizeof(short);

	//Task 10
	short var_1 = 0x7fff;
	short var_2 = 0x8000;
	int size_var = sizeof(short);

	//Task 11
	/*
	Это 16-битное беззнаковое число 
	Самое большое:
	1111 1111 1111 1111 (bin) = 0xffff(hex)
	Самле маленькое:
	0000 0000 0000 0000 = 0x0000
	*/
	unsigned short var_3 = 0xffff;
	unsigned short var_4 = 0x0000;
	int size_var_3 = sizeof(unsigned short);

	//Task 12
	/*
	22(dec) = 0001 0110(bin) = 16(hex)
	-22 = 1000 0000 0001 0110(пк) = 1111 1111 1110 1010(дк) = ffea(hex)
	*/
	int Y = 22;
	int Y2 = -22;
	int size_y = sizeof(int);

	//Task 13
	int var_5 = 0x7fffffff;
	int var_6 = 0x80000000;

	//Task 14
	unsigned int var_7 = 0xffffffff;
	unsigned int var_8 = 0x00000000;

	//Task 15
	/*
	Z = 23 = 17(hex)
	-Z = -23 = -0001 0111(bin) = 1000 0000 0001 0111(пк) = 1111 1111 1110 1001(дк) = ffe9(hex)
	*/
	long Z = 23;
	long Z2 = -23;

	//Task 16
	long var_9 = 0x7fffffff;
	long var_10 = 0x80000000;

	//Task 17
	unsigned long var_11 = 0xffffffff;
	unsigned long var_12 = 0x00000000;

	//Task 18
	/*
	13.0 = 0x00005041
	-13.0 = 0x000050c1
	*/
	float S = 13.0f;
	float S2 = -13.0f;

	//Task 19
	float var_13 = S / 0;
	float var_14 = S2 / 0;
	float var_15 = sqrt(S2);

	//Task 20
	/*
	pc = 0x000000f8b971f4d4
	pwc = 0x0000008fb971f554
	psh = 0x0000008f9b71f5d4
	pint = 0x000000f8b971f6f4
	pf = 0x0000008fb971f894
	pd = 0x0000008fb971f958
	*/
	double var_16 = 1.02501;

	char* pc = &letter;
	wchar_t* pwc = &letter_1;
	short* psh = &X;
	int* pint = &Y;
	float* pf = &S;
	double* pd = &var_16;

	pc += 3;
	pwc += 3;
	psh += 3;
	pint += 3;
	pf += 3;
	pd += 3;

	//Task 21
	

	void (*pfunc)() = nullptr;
	pfunc = hello;
	cout << endl << "Вызов функции:" << endl;
	pfunc();
}