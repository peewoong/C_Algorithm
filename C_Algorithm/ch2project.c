#include <stdio.h>
#define LENGTH 10

int main(void) {
	int x = 0;
	int pos = -1;
	int a[] = { 72, 68, 92, 88, 41, 53, 97, 84, 39, 55 };

	printf("�Է��� ���� : ");
	scanf_s("%d", &x);
	printf("�ݺ� ���� �� : x = %d, pos = %d\n", x, pos);

	// �迭�� ������ Ȯ������ �ʾҰ�, ���ϴ� ���� �߰ߵ��� �ʾҴٸ� �ݺ��϶�� �ǹ�
	for (int i = 0; i < LENGTH && pos == -1; ++i) {
		if (a[i] == x) {
			pos = i;
		}

		printf("�ݺ� ���� �� : i = %d, pos = %d\n", i, pos);
	}

	printf("%d\n", pos);
	printf("�ݺ� ���� �� :  pos = %d\n", pos);
	return 0;
}