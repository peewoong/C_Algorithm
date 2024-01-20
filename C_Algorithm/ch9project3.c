#include <stdio.h>

// �賶�� �ִ� ����
#define KNAP_MAX 6

// ������ ����
#define ITEM_NUM 5

// ������ ��Ī
char name[] = { 'A', 'B', 'C', 'D', 'E' };

// ������ ����
int weight[] = { 1, 2, 3, 4, 5 };

// ������ ��ġ
int value[] = { 100, 300, 350, 500, 650 };

// ������ ������ �Ǵ��� ������ �ִ� ��ġ
int maxValue[ITEM_NUM][KNAP_MAX + 1];

// �������� ���� ����
int lastItem[KNAP_MAX + 1];

// item��° ������ ������ �Ǵ��� ���� �賶�� ������ ǥ���ϴ� �Լ�
void showKnap(int item) {
    int knap;    // 0~6kg�� �賶�� ����Ŵ

    // ������ ���� �Ǵ��� ������ ������ ǥ��
    printf("<%c, %dkg, %d���� ����� ���>\n", name[item], weight[item], value[item]);

    // �� �賶�� ���Ը� ǥ��
    for (knap = 0; knap <= KNAP_MAX; knap++) {
        printf("%dkg\t", knap);
    }
    printf("\n");

    // �賶�� ��� ��ǰ ��ġ�� �հ踦 ǥ��
    for (knap = 0; knap <= KNAP_MAX; knap++) {
        printf("%d��\t", maxValue[item][knap]);
    }
    printf("\n");

    // �賶�� ���������� ���� ������ ǥ��
    for (knap = 0; knap <= KNAP_MAX; knap++) {
        if (lastItem[knap] != -1) {
            printf("%c\t", name[lastItem[knap]]);
        }
        else {
            printf("����\t");
        }
    }
    printf("\n\n");
}

// ���α׷� ������ �������� main �Լ�
int main() {
    int item;           // ���� ��ȣ
    int knap;           // 0~6kg�� �賶�� ����Ŵ
    int selVal;         // �ӽ÷� ������ ������ ����� ��ġ �հ�
    int totalWeight;    // �߷��� �հ�

    // 0��° ������ ������ �Ǵ�
    item = 0;
    // 0~KNAP_MAX kg�� �賶�� ���
    for (knap = 0; knap <= KNAP_MAX; knap++) {
        // �ִ� ���� ���ϸ� ����
        if (weight[item] <= knap) {
            maxValue[item][knap] = value[item];
            lastItem[knap] = item;
        }
        // �ִ� ���� ���ϰ� �ƴϸ� �������� ����
        else {
            maxValue[0][knap] = 0;
            lastItem[knap] = -1;
        }
    }
    showKnap(item);

    // 1��°~ITEM_NUM - 1��° ������ ���
    for (item = 1; item < ITEM_NUM; item++) {
        // 0~KNAP_MAX kg�� �賶�� ���
        for (knap = 0; knap <= KNAP_MAX; knap++) {
            // �ִ� ���� ������ ���
            if (weight[item] <= knap) {
                // ������ ����� ��ġ�� ����
                selVal = maxValue[item - 1][knap - weight[item]] + value[item];
                // ��ġ�� ũ�� ����
                if (selVal > maxValue[item - 1][knap]) {
                    maxValue[item][knap] = selVal;
                    lastItem[knap] = item;
                }
                // ��ġ�� ũ�� ������ �������� ����
                else {
                    maxValue[item][knap] = maxValue[item - 1][knap];
                }
            }
            // �ִ� ���� ���ϰ� �ƴϸ� �������� ����
            else {
                maxValue[item][knap] = maxValue[item - 1][knap];
            }
        }
        showKnap(item);
    }

    // �賶�� ��� �ִ� ������ �����Ͽ� ������ ǥ��
    printf("<�賶�� ��� �ִ� ������ ����>\n");
    totalWeight = 0;
    for (knap = KNAP_MAX; knap > 0; knap -= weight[item]) {
        item = lastItem[knap];
        printf("%dkg�� �賶�� ���������� ���� ������ %c�Դϴ�.\n", knap, name[item]);
        totalWeight += weight[item];
        printf(" %c, %dkg, %d��\n", name[item], weight[item], value[item]);
        printf(" %dkg - %dkg = %dkg�Դϴ�.\n", knap, weight[item], knap - weight[item]);
    }
    printf("\n<������ ǥ��>\n");
    printf("������ �հ� = %dkg\n", totalWeight);
    printf("��ġ�� �ִ� = %d��\n", maxValue[ITEM_NUM - 1][KNAP_MAX]);

    return 0;
}