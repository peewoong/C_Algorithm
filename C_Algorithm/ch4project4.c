#include <stdio.h>
#define LENGTH 5

void printArray(int a[], int len);

// 선택 정렬 예시
int main(void) {
	int a[] = { 90,34,78,12,56 };
	int ins, cmp, min, temp;

	printf("정렬 전 배열\n");
	printArray(a, LENGTH);
	printf("\n");

	for (ins = 0; ins < LENGTH; ++ins) {
		printf("외부 반복문 : %d회\n", ins + 1);
		min = ins;

		for (cmp = ins + 1; cmp < LENGTH; ++cmp) {
			if (a[ins] > a[cmp]) {
				min = cmp;
				temp = a[ins];
				a[ins] = a[min];
				a[cmp] = temp;

				// 배열 요소의 현재 최솟값 확인
				printf("배열 요소의 현재 최솟값 : a[%d] = %d\n", ins, a[ins]);
				printArray(a, LENGTH);
			}

			// 내부 반복문 1회 실행 후 중간 정렬 결과 내용 표시
			printf("내부 반복문 : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, cmp, a[cmp]);
			printArray(a, LENGTH);
		}

		printf("외부 반복문 : ins = %d, cmp = %d, a[%d] = %d\n", ins, cmp, ins, a[ins]);
		printf("외부 반복문 : 확정된 정렬 위치 = a[%d] <= %d\n", ins, a[ins]);

		// 정렬 중간 결과 내용을 표시
		printArray(a, LENGTH);
		printf("\n");
	}

	printf("외부 반복문 : 확정 된 정렬 위치 = a[%d] <= %d\n\n", LENGTH - 1, a[LENGTH - 1]);

	// 정렬 후 배열 내용을 표시
	printf("정렬 후 배열\n");
	printArray(a, LENGTH);

	return 0;
}

void printArray(int a[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}