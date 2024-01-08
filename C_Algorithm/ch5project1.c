#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LENGTH 10

// StationList 구조체 정의
struct StationList {
	char name[20]; // 역 이름
	int next; // 연결 정보
};

// 연결 리스트의 실체가 되는 배열(요소 수는 최대 10)
struct StationList list[10];

int head;
int insIdx; // 새로 삽입할 요소의 인덱스 지정
char insName; // 새로 삽입할 역 이름 지정
int prevIdx; // 삽입할 요소의 하나 앞 요소의 인덱스 지정, 삭제할 요소의 하나 앞 요소의 인덱스 지정
int delInx; // 삭제할 요소의 인덱스 지정

void initStationList() {
	strcpy(list[0].name, "부산");
	list[0].next = -1;
	strcpy(list[1].name, "대전");
	list[1].next = 3;
	strcpy(list[2].name, "서울");
	list[2].next = 4;
	strcpy(list[3].name, "동대구");
	list[3].next = 0;
	strcpy(list[4].name, "천안아산");
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

	InsertStationList(5, "광명", 2);
	printStationList();

	DeleteStationList(5, 2);
	printStationList();

	return 0;
}