#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LENGTH 10

// StationList ����ü ����
struct StationList {
	char name[20]; // �� �̸�
	int next; // ���� ����
};

// ���� ����Ʈ�� ��ü�� �Ǵ� �迭(��� ���� �ִ� 10)
struct StationList list[10];

int head;
int insIdx; // ���� ������ ����� �ε��� ����
char insName; // ���� ������ �� �̸� ����
int prevIdx; // ������ ����� �ϳ� �� ����� �ε��� ����, ������ ����� �ϳ� �� ����� �ε��� ����
int delInx; // ������ ����� �ε��� ����

void initStationList() {
	strcpy(list[0].name, "�λ�");
	list[0].next = -1;
	strcpy(list[1].name, "����");
	list[1].next = 3;
	strcpy(list[2].name, "����");
	list[2].next = 4;
	strcpy(list[3].name, "���뱸");
	list[3].next = 0;
	strcpy(list[4].name, "õ�Ⱦƻ�");
	list[4].next = 1;

	head = 2;
}

void printStationList() {
	int idx = head;
	while (idx != -1) {
		printf("[%s] -> ", list[idx].name);
		idx = list[idx].next;
	}

	printf("\n");
}

void InsertStationList(int insIdx, char insName[], int prevIdx) {
	strcpy(list[insIdx].name, insName);
	list[insIdx].next = list[prevIdx].next;
	list[prevIdx].next = insIdx;
}

void DeleteStationList(int delIdx, int prevIdx) {
	list[prevIdx].next = list[delIdx].next;
}

int main(void) {
	initStationList();
	printStationList();

	InsertStationList(5, "����", 2);
	printStationList();

	DeleteStationList(5, 2);
	printStationList();

	return 0;
}