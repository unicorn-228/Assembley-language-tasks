#include <iostream>
using namespace std;


/*
�������� ����, 7 ������, 1 ����, ����

�5.0	��� ����� ���������� ��������������, ���� ������ �� ��� ����� �����
���� ��������� �������, �� ������ ������ ����� �����.
��������� �������� �� �������� ����� � � � ��������������.

������� ��� �������� :

����           ���������

220 284        ����� �������������
1184 1210      ����� �������������
2620 2924      ����� �������������
210 250        ����� �� �������������
515 235        ����� �� �������������

������� ������ :
��������� ����� ��������� ����� �����, � ����� ��� ����� ������������ � �������
*/

int factor(int a) { // �������, ������� ���� ����� ��������� �����
	int num = a - 1;
	int sum = 0;
	_asm {
		mov ecx , num
		loop1: mov num , ecx				// � ����� ����� ������� �� ������� ����� � �����
			   mov eax , a					// � ������� ������������ � �����. ���� �� ����� ����, �� ��������� ������������� �� 
			   mov edx , 0					// ������� �����
			   div num
			   cmp edx , 0
			   jne _end
			   mov eax , num
			   add sum , eax
		
			   _end:
		loop loop1
	}
	return sum;
}

void main() {
	setlocale(LC_ALL, ".1251");
	cout << "������� ��� ����� � ��������� ��������, �������� �� ��� ��������������" <<endl;
	int a, b;
	cin >> a;
	cin >> b;
	if (factor(a) == b && factor(b) == a) {
		cout << "����� �������������";
	}
	else {
		cout << "����� �� �������������";
	}
	cout << endl;
	system("pause");
}