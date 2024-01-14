#include <stdio.h>
#define LENGTH 10
#define TRUE -1

int hashTable[LENGTH] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int hashFunc(int key) {
	return key % 10;
}

int main(void) {
	int data, hashValue;

	do {
		printf("\n저장할 데이터 = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// 해시값 구하기
		hashValue = hashFunc(data);
		printf("해시값 = %d %% 10 = %d\n", data, hashValue); // %%는 화면에 %문자를 표시한다.

		// 해시 테이블에 저장
		hashTable[hashValue] = data;
		printf("hashTable[%d]에 %d를 저장합니다.\n", hashValue, data);
	} while (TRUE);

	do {
		printf("\n탐색할 데이터 = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// 해시값 구하기
		hashValue = hashFunc(data);
		printf("해시값 = %d %% 10 = %d\n", data, hashValue);

		// 탐색한 결과 표시
		if (hashTable[hashValue] == data) {
			printf("hashTable[%d]값은 %d이므로, 발견된 위치를 표시합니다.\n", hashValue, data);
			printf("%d번째에서 발견되었습니다.\n", hashValue);
		}
		else {
			printf("hashTable[%d]값은 %d가 아니므로, '찾을 수 없습니다'를 표시합니다.\n", hashValue, data);
			printf("찾을 수 없습니다.\n");
		}

	} while (TRUE);

	return 0;
}