#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template < typename T >
auto lambda = [](T num) {
    if (sizeof(num) == 1) {
        return num >= 0 && num <= 127;
    }
    else {
        return num > 0;
    }
    };
auto lambda_3 = [](string text_1, string text_2) {return text_1 + text_2; };

int main() {
    setlocale(LC_ALL, "ru");
    vector<int>v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // ���������� ���������� ����� ����� � std::vector ������ ���������. 
    int target1 = 3;
    int num_items1 = count(v.begin(), v.end(), target1);
    cout << "�����: " << target1 << " ����������: " << num_items1 << '\n';
    // ������-��������� ��� �������� ���������, ������� 3.
    int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
    cout << "���������� ���������, ������� 3: " << num_items3 << '\n';
    cout << " ������, ������ ����������" << endl;
    // ������-���������, ������ ����������
    for (auto i : v) [i]() {if (i % 3 == 0) cout << i << " "; }();

    cout << endl << " ������ � �����������" << endl;
    // ����� �������� ������� 3. �������� ����� ���������� ��� �������� � ������� �������
    for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << " "; }(i);

    cout << endl << " ������ ��� ����������" << endl;
    // ����� �������� ������� 3.
    // �������� ���������� ����� ������ ���������� ��� ���� ��������� ������ ��� ���������� ����������
    for (auto i : v)[i] {if (i % 3 == 0) cout << i << " "; }();

    
    //��� 1
    auto lambda_1 = [](auto num) {return num > 0; };
    auto result_1 = lambda_1(12);

    //��� 2
    int iNum = 44;
    float fNum = 456.78;
    char cNum = 'f';
    auto iresult_lambda = lambda<int>(iNum);
    auto fresult_lambda = lambda<float>(fNum);
    auto cresult_lambda = lambda<char>(cNum);

    //��� 3
    string text_1 = "Good";
    string text_2 = "day";
    auto result_3 = lambda_3(text_1, text_2);
}