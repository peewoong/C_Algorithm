#include <stdio.h>
#define LENGTH 100

int fibonacciNumbers[LENGTH];

void initFibonacciNumbers() {
	for (int i = 0; i < LENGTH; ++i) {
		fibonacciNumbers[i] = -1;
	}
}

int fibonacci(int n) {
	printf("fibonacci(%d)가 호출되었습니다.\n", n);

	if (fibonacciNumbers[n] == -1) {
		if (n == 0) {
			fibonacciNumbers[n] = 0;
		}
		else if (n == 1) {
			fibonacciNumbers[n] = 1;
		}
		else {
			fibonacciNumbers[n] = fibonacci(n - 1) + fibonacci(n - 2);
		}
	}

	return fibonacciNumbers[n];
}

int main(void) {
	initFibonacciNumbers();

	printf("5번째 피보나치 수 = %d\n", fibonacci(5));
	printf("\n");

	return 0;
}