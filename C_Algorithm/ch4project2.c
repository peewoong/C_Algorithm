#include <stdio.h>
#define LENGTH 5

void printArray(int a[], int len);

// ���� ���� �˰���
int main(void) {
	int a[] = { 90,34,78,12,56 };
	int temp, ins, cmp;

	printf("���� �� �迭\n");
	printArray(a, LENGTH);
	printf("\n");

	for (ins = 1; ins < 5; ins++) {
		printf("�ܺ� �ݺ��� : temp <- a[%d] = %d\n", ins, a[ins]);
		temp = a[ins];
		for (cmp = ins - 1; cmp >= 0; cmp--) {
			printf("���� �ݺ��� : ins = %d, cmp = %d, temp = %d\n", ins, cmp, temp);

			if (a[cmp] < temp) {
				a[cmp+1] = a[cmp];
			}
			else {
				printf("break�� �ߴ� \n");
				break;
			}
		}

		printf("�ܺ� �ݺ��� : ins = %d, cmp = %d, temp = %d\n", ins, cmp, temp);
		printf("�ܺ� �ݺ��� : Ȯ���� ���� ��ġ = a[%d] <- temp \n\n", cmp + 1);
		a[cmp+1] = temp;

		// ���� ��ġ Ȯ�� �� ���� �߰� ��� ������ ǥ��
		printf("���� ��ġ Ȯ�� �� �߰� ��� \n");
		printArray(a, LENGTH);
		printf("\n");
	}

	printf("���� �� �迭\n");
	printArray(a, LENGTH);
	printf("\n");

	return 0;
}

void printArray(int a[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}