#include <stdio.h>
#define LENGTH 5

void printArray(int a[], int len);

// ���� ���� ����
int main(void) {
	int a[] = { 90,34,78,12,56 };
	int ins, cmp, min, temp;

	printf("���� �� �迭\n");
	printArray(a, LENGTH);
	printf("\n");

	for (ins = 0; ins < LENGTH; ++ins) {
		printf("�ܺ� �ݺ��� : %dȸ\n", ins + 1);
		min = ins;

		for (cmp = ins + 1; cmp < LENGTH; ++cmp) {
			if (a[ins] > a[cmp]) {
				min = cmp;
				temp = a[ins];
				a[ins] = a[min];
				a[cmp] = temp;

				// �迭 ����� ���� �ּڰ� Ȯ��
				printf("�迭 ����� ���� �ּڰ� : a[%d] = %d\n", ins, a[ins]);
				printArray(a, LENGTH);
			}

			// ���� �ݺ��� 1ȸ ���� �� �߰� ���� ��� ���� ǥ��
			printf("���� �ݺ��� : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, cmp, a[cmp]);
			printArray(a, LENGTH);
		}

		printf("�ܺ� �ݺ��� : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, ins, a[ins]);
		printf("�ܺ� �ݺ��� : Ȯ���� ���� ��ġ = a[%d] <= %d\n", ins, a[ins]);

		// ���� �߰� ��� ������ ǥ��
		printArray(a, LENGTH);
		printf("\n");
	}

	printf("�ܺ� �ݺ��� : Ȯ�� �� ���� ��ġ = a[%d] <= %d\n\n", LENGTH - 1, a[LENGTH - 1]);

	// ���� �� �迭 ������ ǥ��
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