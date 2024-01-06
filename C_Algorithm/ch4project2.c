#include <stdio.h>

// 삽입 정렬 알고리즘
int main(void) {
	int a[] = { 90,34,78,12,56 };
	int temp, ins, cmp;

	for (ins = 1; ins < 5; ins++) {
		temp = a[ins];
		for (cmp = ins - 1; cmp >= 0; cmp--) {
			if (a[cmp] > temp) {
				a[cmp+1] = a[cmp];
			}
			else {
				break;
			}
		}
		a[cmp+1] = temp;
	}

	for (int i = 0; i < 5; ++i) {
		printf("%3d", a[i]);
	}

	return 0;
}