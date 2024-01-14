#include <stdio.h>
#define LENGTH 10
#define TRUE -1
#define FALSE 0

struct BST {
	int data;
	int left;
	int right;
};

// ���� Ž�� Ʈ���� ��ü�� �Ǵ� �迭(��� ���� �ִ� 10)
struct BST tree[LENGTH];

// ��Ʈ ����� ������ ��ġ �ε���(���� ����Ʈ�� head)
int rootIdx = 0;

// �������� �߰��� ����� ������ ��ġ �ε���
int newIdx = 0;

void addBST(int data) {
	int currentIdx; // ���� ����� ������ ��ġ �ε���
	int addFlag; // ��� �߰��� �Ϸ�Ǿ����� Ȯ���ϴ� �÷���

	// ������ ��ġ�� ��ڰ��� ���� ���� �߰�
	tree[newIdx].data = data;
	tree[newIdx].left = -1;
	tree[newIdx].right = -1;

	// ��Ʈ ��Ұ� �ƴ϶�� ���� ������ ���� ��� ��ġ Ž�� �� ����
	if (newIdx != rootIdx) {
		currentIdx = rootIdx; // ��Ʈ���� ���� Ž�� Ʈ���� ������
		addFlag = FALSE; // ��� �߰��� �Ϸ���� ����

		do {
			// ��Ʈ ��ڰ����� �� ������ �������� ������
			if (data < tree[currentIdx].data) {
				// �������� �������� �� ���̸� left�� ����� ������ ��ġ �ε����� �߰�(���� ���� ����)
				if (tree[currentIdx].left == -1) {
					tree[currentIdx].left = newIdx;
					addFlag = TRUE;
				}
				// �������� �������� �� ���� �ƴ϶�� ������ ��Һ��� �� ������
				else {
					currentIdx = tree[currentIdx].left;
				}
			}
			// ��Ʈ ��ڰ����� �� ũ�� ���������� ������ (������ ���� ����)
			else {
				// ���������� �������� �� ���̸� right�� ����� ������ ��ġ �ε����� �߰�(���� ���� ����)
				if (tree[currentIdx].right == -1) {
					tree[currentIdx].right = newIdx;
					addFlag = TRUE;
				}
				// ���������� �������� �� ���� �ƴ϶�� �������� ��Һ��� �� ������
				else {
					currentIdx = tree[currentIdx].right;
				}
			}
		} while (addFlag == FALSE);
	}

	// ������ �߰��� ��Ҹ� ���� ������ ��ġ�� �ε����� 1 �ø�
	newIdx++;
}

// ���� �˻� Ʈ���� ��ü�� �迭�� ������ ��ġ ������ ǥ���ϴ� �Լ�
void printfPhysicalBST() {
	int i;

	for (int i = 0; i < newIdx; ++i) {
		printf("tree[%d] : data = %d, left = %d, right = %d\n",
			i, tree[i].data, tree[i].left, tree[i].right);
	}
}

void printLogicalBST(int currentIdx) {
	if (currentIdx != -1) {
		printf("tree[%d] : data = %d, left = %d, right = %d\n",
			currentIdx, tree[currentIdx].data, tree[currentIdx].left, tree[currentIdx].right);

		// ��� ȣ�� �κ�
		printLogicalBST(tree[currentIdx].left);
		printLogicalBST(tree[currentIdx].right);
	}
}

// ���� Ʈ���� Ž���ϴ� �Լ�
int searchBST(int x, int currentIdx) {
	if (currentIdx == -1) {
		return -1;
	}
	else {
		if (tree[currentIdx].data == x) {
			return currentIdx;
		}
		else if (tree[currentIdx].data > x) {
			return searchBST(x, tree[currentIdx].left);
		}
		else {
			return searchBST(x, tree[currentIdx].right);
		}
	}
}

int main(void) {
	// ��Ҹ� �߰��ϸ鼭 ���� Ž�� Ʈ���� ����
	addBST(4);
	addBST(6);
	addBST(5);
	addBST(2);
	addBST(3);
	addBST(7);
	addBST(1);

	//// ������ ��ġ ������ ǥ��
	//printfPhysicalBST();

	//// ���� Ž�� Ʈ���� ���� ����(���� �켱 Ž��)�� ǥ��
	//printf("----\n");
	//printLogicalBST(rootIdx);

	// ���� Ž�� Ʈ���� Ž��
	printf("data���� '5'�� ���� ������ ��ġ Ž�� ��� = tree[%d]\n", searchBST(5, rootIdx));
	printf("data���� '8'�� ���� ������ ��ġ Ž�� ��� = tree[%d]\n", searchBST(8, rootIdx));

	return 0;
}