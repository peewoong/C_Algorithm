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
		addFlag = false; // ��� �߰��� �Ϸ���� ����
		
		do {
			// ��Ʈ ��ڰ����� �� ������ �������� ������
			if (daat < tree[currentIdx].data) {
				// �������� �������� �� ���̸� left�� ����� ������ ��ġ �ε����� �߰�(���� ���� ����)
				if (tree[currentIdx].left == -1) {
					tree[currentIdx].left = newIdx;
					addFlag = true;
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
					addFlag = true;
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

int main(void) {
	// ��Ҹ� �߰��ϸ鼭 ���� Ž�� Ʈ���� ����
	addBST(4);
	addBST(6);
	addBST(5);
	addBST(2);
	addBST(3);
	addBST(7);
	addBST(1);


	printfPhysicalBST();

	return 0;
}