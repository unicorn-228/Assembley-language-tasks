#include <iostream>

using namespace std;

/*
�������� ����, 1 ���� , 7 ������
�8.0	���� ����������� n. ����������  ����������  ������� �����������  x*x + y*y < n � �����������
(��������������� �����) ������, �� ��������� �������� � ������������� �������.

������� :

������� n 1212121
���-�� ����� ���������� = 950858

������� n 15111
���-�� ����� ���������� = 11736

������� n 12345
���-�� ����� ���������� = 9588

������� ������ :
������� �����, ������� �������� �������� ������ �� ��������� �����
���������� ��� ���� � ������ �� ������ �����, ������� �������������� ������ �� ��������� �����
��������� �������� �� ����� ���� � ������ ��� ������ ���������
���� ��������, �� ����������� ����������, ����� ������ ��������
*/
int koren(int a) {
	int i = 1;
	for (; i < a; i++) {
		if (i*i >= a)
			break;
	}
	i--;
	return i;
}

int qwerty(int w , int n) {
	//��� ������� ������� ����� ������
	/*
	������������ ������� ��� ������ ��� ������ ����� �� c++ :
	for (long long int i = n / w; i >= 1; i--) {	//���������� ��� i �� ������ �����, ������� �������������� ������ �� ��������� �����
		for (long long int q = n / w; q >= 1; q--) {	//���������� ��� q �� ������ �����, ������� �������������� ������ �� ��������� �����
			if (q*q + i * i < n) {	//���� ����������� ���� ������� , �� ����������� ���-�� ����� ���
				result++;
			}
		}
	} 
	*/
	int temp1 = n / w;
	int i = temp1;
	int q = temp1;
	int result = 0;
	int temp = 0;
	_asm {
		mov ecx , i
		loop1: mov ecx , q //������ ���� (�� i)
			   loop2: mov eax , ecx //������ ���� (�� q)
					  //����� ���� ������� ��������� i*i + q*q
					  mov edx , 0
					  mul ecx
					  mov temp , eax
					  mov eax , i
					  mov edx , 0
					  mul i
					  add temp , eax
					  mov eax , n
					  cmp temp , eax
					  jnl skipNext //���� ���� ������� �� �����������, �� ���������� �������� ��������
					  add result , 1 //���� �����������, �� ����������� ���������
					  skipNext: 
		              sub q , 1 //��������� q
					  mov ecx , q
						  add ecx , 1
					  loop loop2
			   sub i , 1 //��������� i
						  mov eax , temp1 //���������� q � ��������� ��������� ������ n / w
						mov q , eax
			   mov ecx , i
						  add ecx , 1
						  loop loop1
	}
	return result;
}

void main() {
	setlocale(LC_ALL, ".1251");
	long long int n, result = 0;
	cout << "������� n ";
	cin >> n;
	int w = koren(n); //������� �������������� ������ �� ����� n
	result = qwerty(w, n); //��������� �������� �� ����������
	cout << endl << "���-�� ����� ���������� = " << result << endl;
	system("pause");
}