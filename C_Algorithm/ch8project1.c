#include <stdio.h>

int factorial(int n) {
	printf("factorial(%d)�� ȣ��Ǿ����ϴ�.\n", n);
	if (n == 0) {
		// 0�� ����� 1�̹Ƿ� 1�� ��ȯ�Ͽ� ��� ȣ���� ����
		printf("factorial(0)�� 1�� ��ȯ�߽��ϴ�.\n");
		return 1;
	}
	else {
		int retVal = n * factorial(n - 1);
		printf("factorial(%d)�� %d�� ��ȯ�߽��ϴ�.\n", n, retVal);
		return retVal;
	}
}

int main(void) {
	int ans;

	ans = factorial(5);
	printf("%d\n", ans);

	return 0;
}