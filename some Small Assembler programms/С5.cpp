#include <iostream>
using namespace std;


/*
�������� ���� , 7 ������ , 1 ����, ����

�5.0	���� ����������� ����� n � k, n > 1.  ����������  k ���������� ������ ����� 1/n.
(��� ������� ���� ���������� ����������  ���������� �� �� ���, ������� �� �������� �������
� �������.) ��������� ������ ������������ ������ ����� ����������.

������� ������ :
������� ������� ������� �� 10^k
�������� ��� 10^k �� ����� n
���� �� ����� ����� ������� ������ �� � ������� �� ����, � ����� ������� ����� ����� � ��������, �� ���������� ��������, �������� �� �������

������� :
input         output
3 4           0.3333
8 6           0.125000
7 5			  0.14285
*/

int qwerty(int n , int k) { // �������� ������� 10^k / n
	int result;
	int ten = 1;
	_asm {
		mov ecx , k
		loop1: mov eax , ten //����� ��������� 10^k
			   mov edx , 0
			   mov ebx , 10
			   mul ebx
			   mov ten , eax
		loop loop1
		mov eax , ten // ����� ����� �� n
		mov edx , 0
		div n
		mov result , eax // �������� �� 9 � �������
		mov edx , 0
		mov ebx , 10
		div ebx
		cmp edx , 9
		jne endloop
		mov edx , 0
		div ebx
		jne endloop
		mov edx, 0
		div ebx
		jne endloop
		mov ebx , 1 //���� ������������ ��� ��������� ������, �� ��������� �������� �� �����, ����� �� ������
		add result , ebx
		endloop:
	}
	return result;
}

void main() {
	setlocale(LC_ALL, ".1251");
	cout << "������� ��� ����� n � k     (n > 1)" << endl;
	int n, k;
	cin >> n >> k;
	cout << "1/n = 0." << qwerty(n , k);// ������� 0.<��������� ����, ��� ���������� � qwerty>
	cout << endl;
	system("pause");
}