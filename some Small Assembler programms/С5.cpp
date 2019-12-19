#include <iostream>
using namespace std;


/*
¬еретило »ль€ , 7 группа , 1 курс, ‘ѕћ»

—5.0	ƒаны натуральные числа n и k, n > 1.  Ќапечатать  k дес€тичных знаков числа 1/n.
(ѕри наличии двух дес€тичных разложений  выбираетс€ то из них, которое не содержит дев€тки
в периоде.) ѕрограмма должна использовать только целые переменные.

принцип работы :
вначале умножим единицу на 10^k
разделим это 10^k на число n
если на конце будут дев€тки уберем их и заменим на нули, а число сто€щще ближе всего к дев€ткам, не €вл€ющеес€ дев€ткой, увеличим на единицу

примеры :
input         output
3 4           0.3333
8 6           0.125000
7 5			  0.14285
*/

int qwerty(int n , int k) { // функции€ считает 10^k / n
	int result;
	int ten = 1;
	_asm {
		mov ecx , k
		loop1: mov eax , ten //здесь считаетс€ 10^k
			   mov edx , 0
			   mov ebx , 10
			   mul ebx
			   mov ten , eax
		loop loop1
		mov eax , ten // далее делим на n
		mov edx , 0
		div n
		mov result , eax // проверка на 9 в периоде
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
		mov ebx , 1 //если заканчиваетс €на несколько де€ток, то добавл€ем единичку на конце, чтобы из убрать
		add result , ebx
		endloop:
	}
	return result;
}

void main() {
	setlocale(LC_ALL, ".1251");
	cout << "введите два числа n и k     (n > 1)" << endl;
	int n, k;
	cin >> n >> k;
	cout << "1/n = 0." << qwerty(n , k);// выводим 0.<результат того, что получилось в qwerty>
	cout << endl;
	system("pause");
}