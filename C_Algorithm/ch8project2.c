#include <stdio.h>
#define LENGTH 7
#define TRUE -1

// 배열 내용을 표시하는 함수
void printArray(int a[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}

// 배열 a[head]~a[tail]을 그룹으로 나누는 함수
int divideArray(int a[], int head, int tail) {
	int left, right, temp;
	left = head + 1; // 배열 첫 요소 + 1부터 뒷 요소로 훑어가는 위치
	right = tail; // 배열 끝 요소부터 앞 요소로 훑어가는 위치

	// 기준값 a[head]보다 작은 요소를 앞쪽으로, 큰 요소를 뒤쪽으로 이동
	while (TRUE) {
		// 배열 첫 요소 +1부터 뒤로 훑어가, 기준값보다 큰 요소를 찾음
		while (left < tail && a[head] > a[left]) {
			left++;
		}

		// 배열 끝 요소에서 앞으로 훑어 기준값보다 작은 요소를 찾음
		while (a[head] < a[right]) {
			right--;
		}

		// 확인할 요소가 없어지면 종료
		if (left >= right) {
			break;
		}

		// 기준값보다 큰 a[left]와 기준값보다 작은 a[right]를 교환
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;

		// 다음 요소를 확인함
		left++;
		right--;
	}

	// 기준값 a[head]와 a[right]를 교환
	temp = a[head];
	a[head] = a[right];
	a[right] = temp;

	// 기준값 a[right]의 위치를 반환
	return right;
}

// 배열 a[start]~a[end]를 오름차순으로 정렬하는 함수
void sortArray(int a[], int start, int end) {
	int pivot; // 배열을 그룹으로 나누는 기준값의 인덱스 위치

	// 배열 요소가 2개 이상인 경우 정렬 처리 실행
	if (start < end) {
		// 기준값과의 대소 관계에 따라 그룹 나누기
		pivot = divideArray(a, start, end);

		// 기준값보다 작은 앞쪽 그룹에 동일한 처리를 적용(재귀 호출)
		sortArray(a, start, pivot - 1);

		// 기준값보다 큰 뒤쪽 그룹에 동일한 처리를 적용(재귀 호출)
		sortArray(a, pivot + 1, end);
	}
}

int main(void) {
	int a[] = { 4,7,1,6,2,5,3 };

	// 정렬전 배열을 표시
	printArray(a, LENGTH);

	// 퀵 정렬 실행
	sortArray(a, 0, LENGTH - 1);

	// 정렬된 배열을 표시
	printArray(a, LENGTH);

	return 0;
}