#include <stdio.h>
#define LENGTH 10

int main(void) {
	int a[] = { 72, 68, 92, 88, 41, 53, 97, 84, 39, 55 };
	int max, min;

	max = a[0];
	min = a[0];

	for (int i = 0; i < LENGTH; ++i) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	printf("�ִ� : %d\n", max);
	printf("�ּڰ� : %d\n", min);
	return 0;
}