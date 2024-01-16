#include <stdio.h>
#define LENGTH 10
#define TRUE -1

int hashTable[LENGTH] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

int hashFunc(int key) {
	return key % 10;
}

int main(void) {
	int data, hashValue;
	int pos; // ���� ��ġ, �˻� ��ġ

	do {
		printf("\n������ ������ = ");
		scanf_s("%d", &data);

		if (data < 0) {
			break;
		}

		// �ؽð� ���ϱ�
		hashValue = hashFunc(data);
		printf("�ؽð� = %d %% 10 = %d\n", data, hashValue); // %%�� ȭ�鿡 %���ڸ� ǥ���Ѵ�.

		// �������� ���� ��ġ�� ����
		pos = hashValue;
		printf("���� ��ġ pos = %d\n", pos);
		while (hashTable[pos] != -1) {
			// ���� �迭 ��ҿ��� �����͸� ������ �� �ִ��� Ȯ��
			pos++;

			// �迭 ������ ��ұ��� ������ ���� ���� ���θ� Ȯ���ϸ� �迭 ù ��° ��Ҹ� ����
			if (pos >= LENGTH) {
				pos = 0;
			}
			printf("���� ��ġ pos = %d\n", pos);

			// �ؽð��� �迭 ��� ��ġ���� ���ƿ���
			// �ؽ� ���̺� �����Ͱ� ���� �� ���̹Ƿ� �ݺ��� ����
			if (pos == hashValue) {
				break;
			}
		}

		if (hashTable[pos] == -1) {
			// �ؽ� ���̺� �����Ͱ� ���� ���� �ʾҴٸ� �����͸� ����
			hashTable[pos] = data;
			printf("hashTable[%d]�� %d�� �����մϴ�\n", pos, data);
		}
		else {
			printf("�ؽ� ���̺��� ���� á���ϴ�.\n");
		}
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

		// �����͸� �˻�
		pos = hashValue;
		printf("Ž�� ��ġ pos = %d\n", pos);
		while (hashTable[pos] != -1 && hashTable[pos] != data) {
			// ���� �迭 ��ҷ� Ž�� ��ġ�� �̵�
			pos++;

			// �迭 ������ ��ұ��� Ž���ϸ� �迭 ù ��° ��Ҹ� ����
			if (pos >= LENGTH) {
				pos = 0;
			}
			printf("Ž�� ��ġ pos = %d\n", pos);

			// -1�� ã�Ұų�, �ؽð��� �ε��� ��ġ�� ���ƿ���, �����͸� ã�� �� ���� ���̹Ƿ� �ݺ��� ����
			if (hashTable[pos] == -1 || pos == hashValue) {
				break;
			}
		}

		// Ž���� ����� ǥ��
		if (hashTable[pos] == data) {
			printf("hashTable[%d]���� %d�̹Ƿ�, �߰��� ��ġ�� ǥ���մϴ�.\n", pos, data);
			printf("%d��°���� �߰ߵǾ����ϴ�.\n", pos);
		}
		else {
			printf("hashTable[%d]���� %d�̹Ƿ�, 'ã�� �� �����ϴ�.'�� ǥ���մϴ�.\n", pos, hashTable[pos]);
			printf("ã�� �� �����ϴ�.\n");
		}

	} while (TRUE);

	return 0;
}