#include <iostream>

using namespace std;

void sort_asm(int a[], int n) {
	int i = n;
	int j = n;
	_asm {
		mov ecx , i
		loop1: mov eax , 0
			   loop2: mov eax , 0
					  mov ecx , j
					  dec j
					  mov esi, a
					  mov ebx , j
					  shl ebx , 2
					  mov eax , [esi+ebx]
					  cmp eax , [esi+ebx-4]
					  jnl exit_1
					  mov eax , [esi+ebx]
					  mov ecx , [esi+ebx-4]
					  mov [esi+ebx] , ecx
					  mov [esi+ebx-4] , eax
					  exit_1:
			   loop loop2
			   mov ecx , i
			   dec i
		loop loop1
	}
}

void main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	sort_asm(a, n);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	system("pause");
}