#include <stdio.h>
#define LENGTH 10
#define TRUE -1

int hashTable[LENGTH] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int hashFunc(int key) {
	return key % 10;
}

int main(void) {
	int data, hashValue;
	int pos; // 저장 위치, 검색 위치

	do {
		printf("\n저장할 데이터 = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// 해시값 구하기
		hashValue = hashFunc(data);
		printf("해시값 = %d %% 10 = %d\n", data, hashValue); // %%는 화면에 %문자를 표시한다.

		// 데이터의 저장 위치를 정함
		pos = hashValue;
		printf("저장 위치 pos = %d\n", pos);
		while (hashTable[pos] != -1) {
			// 다음 배열 요소에서 데이터를 저장할 수 있는지 확인
			pos++;

			// 배열 마지막 요소까지 데이터 저장 가능 여부를 확인하면 배열 첫 번째 요소를 지정
			if (pos >= LENGTH) {
				pos = 0;
			}
			printf("저장 위치 pos = %d\n", pos);

			// 해시값의 배열 요소 위치까지 돌아오면
			// 해시 테이블에 데이터가 가득 찬 것이므로 반복을 종료
			if (pos == hashValue) {
				break;
			}
		}

		if (hashTable[pos] == -1) {
			// 해시 테이블에 데이터가 가득 차지 않았다면 데이터를 저장
			hashTable[pos] = data;
			printf("hashTable[%d]에 %d를 저장합니다\n", pos, data);
		}
		else {
			printf("해시 테이블이 가득 찼습니다.\n");
		}
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

		// 데이터를 검색
		pos = hashValue;
		printf("탐색 위치 pos = %d\n", pos);
		while (hashTable[pos] != -1 && hashTable[pos] != data) {
			// 다음 배열 요소로 탐색 위치를 이동
			pos++;

			// 배열 마지막 요소까지 탐색하면 배열 첫 번째 요소를 지정
			if (pos >= LENGTH) {
				pos = 0;
			}
			printf("탐색 위치 pos = %d\n", pos);

			// -1을 찾았거나, 해시값의 인덱스 위치로 돌아오면, 데이터를 찾을 수 없는 것이므로 반복을 종료
			if (hashTable[pos] == -1 || pos == hashValue) {
				break;
			}
		}

		// 탐색한 결과를 표시
		if (hashTable[pos] == data) {
			printf("hashTable[%d]값은 %d이므로, 발견한 위치를 표시합니다.\n", pos, data);
			printf("%d번째에서 발견되었습니다.\n", pos);
		}
		else {
			printf("hashTable[%d]값은 %d이므로, '찾을 수 없습니다.'를 표시합니다.\n", pos, hashTable[pos]);
			printf("찾을 수 없습니다.\n");
		}

	} while (TRUE);

	return 0;
}