#include <iostream>
using namespace std;


/*
�������� ���� 7 ������

�1.0	������ �����, ���������� �� ���� �� ������ ����.
����� ������ ����� �������� ����, �������� 9.


������� �������� :
� ����� �������������� �����, �� ��� ���������� � ����� ������ �������� � ����� �� ����� � � ������������ ����
����� �������������� �����
������� ������ ������� � ����

*/

int insert(int a) { // ������� ��������� �������, �� ��� ��� �������������� �����
	int result = 0;
	int index = 1;
	int devyanosto = 90;
	int sto = 100;
	_asm {
	while1: mov eax , a
			mov edx , 0
			mov ebx , 10
			div ebx
			mov a , eax
			mov ebx , devyanosto
			add ebx , edx
			mov eax , result
			mov edx , 0
			mul sto
			mov result , eax
			add result , ebx
			
			cmp a , 0
	jne while1
	}
	return result;
}

int rotate(int a) { //������� �������������� ����� 
	int result = 0;
	_asm {
	while1: mov eax , a
			mov edx , 0
			mov ebx , 10
			div ebx
			add result , edx
			mov a , eax
			mov eax , result
			mov edx , 0
			mul ebx
			mov result , eax
			cmp a , 0
	jne while1
	}
	return result;
}

void main() {
	setlocale(LC_ALL, ".1251");
	cout << "������� �����" << endl;
	int a;
	cin >> a;
	cout << (rotate(insert(a))/100) <<  endl; // ������� � ����� ����������� �������, ����� ��� ���������������� � ������� �� 100 (����� ������ 90 �� �����)
	system("pause");
}