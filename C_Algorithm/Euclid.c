#include <stdio.h>

int main(void) {
	int a, b;

	scanf_s("%d %d", &a, &b);

	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}

	printf("%d\n", a);

	return 0;
}