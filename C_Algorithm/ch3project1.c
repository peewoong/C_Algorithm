#include <stdio.h>

int main(void) {
	int a[10] = {39,41,53,55,68,72,84,88,92,97};
	int x;
	int pos = -1;

	// 인덱스 저장 변수
	int left, right, middle;
	left = 0;
	right = 9;

	printf("x : ");
	scanf_s("%d", &x);

	printf("반복 실행 전 : x = %d\n", x);
	printf("반복 실행 전 : pos = %d, left = %d, middle = ?, right = %d\n", pos, left, right);

	while (pos == -1 && left <= right) {
		middle = (left + right) / 2; // 정수형의 결과이므로 나눈 결과의 소수점 이하는 버린다. middle = 4

		if (a[middle] == x) {
			pos = middle;
		}
		else if (a[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;		
		}

		printf("반복 실행 중 : pos = %d, left = %d, middle = %d, right = %d\n", pos, left, middle, right);
	}

	printf("pos : %d\n", pos);
	return 0;
}