#include <stdio.h>

int factorial(int n) {
	printf("factorial(%d)가 호출되었습니다.\n", n);
	if (n == 0) {
		// 0의 계승은 1이므로 1을 반환하여 재귀 호출을 종료
		printf("factorial(0)이 1을 반환했습니다.\n");
		return 1;
	}
	else {
		int retVal = n * factorial(n - 1);
		printf("factorial(%d)가 %d를 반환했습니다.\n", n, retVal);
		return retVal;
	}
}

int main(void) {
	int ans;

	ans = factorial(5);
	printf("%d\n", ans);

	return 0;
}