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
		printf("\n������ ������ = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// �ؽð� ���ϱ�
		hashValue = hashFunc(data);
		printf("�ؽð� = %d %% 10 = %d\n", data, hashValue); // %%�� ȭ�鿡 %���ڸ� ǥ���Ѵ�.

		// �ؽ� ���̺� ����
		hashTable[hashValue] = data;
		printf("hashTable[%d]�� %d�� �����մϴ�.\n", hashValue, data);
	} while (TRUE);

	do {
		printf("\nŽ���� ������ = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// �ؽð� ���ϱ�
		hashValue = hashFunc(data);
		printf("�ؽð� = %d %% 10 = %d\n", data, hashValue);

		// Ž���� ��� ǥ��
		if (hashTable[hashValue] == data) {
			printf("hashTable[%d]���� %d�̹Ƿ�, �߰ߵ� ��ġ�� ǥ���մϴ�.\n", hashValue, data);
			printf("%d��°���� �߰ߵǾ����ϴ�.\n", hashValue);
		}
		else {
			printf("hashTable[%d]���� %d�� �ƴϹǷ�, 'ã�� �� �����ϴ�'�� ǥ���մϴ�.\n", hashValue, data);
			printf("ã�� �� �����ϴ�.\n");
		}

	} while (TRUE);

	return 0;
}