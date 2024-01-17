#include <stdio.h>
#define LENGTH 7
#define TRUE -1

// �迭 ������ ǥ���ϴ� �Լ�
void printArray(int a[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("[%d]", a[i]);
	}
	printf("\n");
}

// �迭 a[head]~a[tail]�� �׷����� ������ �Լ�
int divideArray(int a[], int head, int tail) {
	int left, right, temp;
	left = head + 1; // �迭 ù ��� + 1���� �� ��ҷ� �Ⱦ�� ��ġ
	right = tail; // �迭 �� ��Һ��� �� ��ҷ� �Ⱦ�� ��ġ

	// ���ذ� a[head]���� ���� ��Ҹ� ��������, ū ��Ҹ� �������� �̵�
	while (TRUE) {
		// �迭 ù ��� +1���� �ڷ� �Ⱦ, ���ذ����� ū ��Ҹ� ã��
		while (left < tail && a[head] > a[left]) {
			left++;
		}

		// �迭 �� ��ҿ��� ������ �Ⱦ� ���ذ����� ���� ��Ҹ� ã��
		while (a[head] < a[right]) {
			right--;
		}

		// Ȯ���� ��Ұ� �������� ����
		if (left >= right) {
			break;
		}

		// ���ذ����� ū a[left]�� ���ذ����� ���� a[right]�� ��ȯ
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;

		// ���� ��Ҹ� Ȯ����
		left++;
		right--;
	}

	// ���ذ� a[head]�� a[right]�� ��ȯ
	temp = a[head];
	a[head] = a[right];
	a[right] = temp;

	// ���ذ� a[right]�� ��ġ�� ��ȯ
	return right;
}

// �迭 a[start]~a[end]�� ������������ �����ϴ� �Լ�
void sortArray(int a[], int start, int end) {
	int pivot; // �迭�� �׷����� ������ ���ذ��� �ε��� ��ġ

	// �迭 ��Ұ� 2�� �̻��� ��� ���� ó�� ����
	if (start < end) {
		// ���ذ����� ��� ���迡 ���� �׷� ������
		pivot = divideArray(a, start, end);

		// ���ذ����� ���� ���� �׷쿡 ������ ó���� ����(��� ȣ��)
		sortArray(a, start, pivot - 1);

		// ���ذ����� ū ���� �׷쿡 ������ ó���� ����(��� ȣ��)
		sortArray(a, pivot + 1, end);
	}
}

int main(void) {
	int a[] = { 4,7,1,6,2,5,3 };

	// ������ �迭�� ǥ��
	printArray(a, LENGTH);

	// �� ���� ����
	sortArray(a, 0, LENGTH - 1);

	// ���ĵ� �迭�� ǥ��
	printArray(a, LENGTH);

	return 0;
}