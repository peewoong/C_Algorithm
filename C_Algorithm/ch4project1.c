#include <stdio.h>

// ���߹ݺ��� ���� : ������
int main(void) {
	for (int i = 1; i < 10; ++i) {
		printf("%d�� : ", i);

		for (int j = 1; j < 10; ++j) {
			printf("\t%2d", i * j);
		}

		printf("\n");
	}

	return 0;
}