#include <iostream>
using namespace std;


/*
Веретило Илья 7 группа

В1.0	Задано число, содержащее от двух до девяти цифр.
Между каждой парой соседних цифр, вставить 9.


принцип действия :
в цикле переворачиваем число, но оно получается с одной лишней девяткой и нулем на конце и в перевернутом виде
затем переворачиваем число
убираем лишнюю девятку и нуль

*/

int insert(int a) { // функция вставляет девятки, но при это переворачивает число
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

int rotate(int a) { //функция переворачивает число 
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
	cout << "введите число" << endl;
	int a;
	cin >> a;
	cout << (rotate(insert(a))/100) <<  endl; // вначале в число вставляются девятки, потом оно переворачивается и делится на 100 (чтобы убрать 90 на конце)
	system("pause");
}