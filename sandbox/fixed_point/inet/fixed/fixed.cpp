#include <iostream>
#include "fixed.h"

using namespace std;

void main()
{
	fixed a, b, c;
	int d;

	a = int_to_fixed(100);
	b = int_to_fixed(10);
	d = a / b; //d ����� ��������� 10 � ������� int
	cout << d << endl;
	c = a / 10; // � ����� ��������� 10 � ������� fixed
	cout << fixed_to_int(c) << endl;

	c = a + b; //c ����� ��������� 110.0 � ������� fixed
	cout << fixed_to_int(c) << endl;

	cin >> a;
}
