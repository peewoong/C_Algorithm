#include <stdio.h>
#define LENGTH 5

void printArray(int a[], int len);

// ���� ���� ����
int main(void) {
	int a[] = { 90, 34, 78, 12, 56 };
	int ins, cmp, temp;

	printf("���� �� �迭\n");
	printArray(a, LENGTH);
	printf("\n");

	for (ins = 0; ins < LENGTH - 1; ++ins) {
		printf("�ܺ� �ݺ��� : %dȸ\n", ins + 1);
		for (cmp = 0; cmp < LENGTH - ins - 1; ++cmp) {
			if (a[cmp] > a[cmp + 1]) {
				temp = a[cmp];
				a[cmp] = a[cmp + 1];
				a[cmp + 1] = temp;
			}

			printf("���� �ݺ��� : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, cmp, a[cmp]);
			printArray(a, LENGTH);
		}

		printf("�ܺ� �ݺ��� : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, cmp, a[cmp]);
		printf("�ܺ� �ݺ��� : Ȯ���� ���� ��ġ = a[%d] <- %d\n\n", cmp, a[cmp]);

		printArray(a, LENGTH);
		printf("\n");
	}

	printf("�ܺ� �ݺ��� : Ȯ���� ���� ��ġ = a[%d] <- %d\n\n", 0, a[0]);

	printf("���� �� �迭\n");
	printArray(a, LENGTH);

	return 0;
}

void printArray(int a[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}