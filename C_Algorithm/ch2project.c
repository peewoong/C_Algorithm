#include <stdio.h>
#define LENGTH 10

int main(void) {
	int x = 0;
	int pos = -1;
	int a[] = { 72, 68, 92, 88, 41, 53, 97, 84, 39, 55 };

	printf("입력할 숫자 : ");
	scanf_s("%d", &x);
	printf("반복 실행 전 : x = %d, pos = %d\n", x, pos);

	// 배열을 끝까지 확인하지 않았고, 원하는 값이 발견되지 않았다면 반복하라는 의미
	for (int i = 0; i < LENGTH && pos == -1; ++i) {
		if (a[i] == x) {
			pos = i;
		}

		printf("반복 실행 중 : i = %d, pos = %d\n", i, pos);
	}

	printf("%d\n", pos);
	printf("반복 실행 후 :  pos = %d\n", pos);
	return 0;
}