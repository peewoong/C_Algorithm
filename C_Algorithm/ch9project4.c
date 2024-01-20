#include <stdio.h>
#define KNAP_MAX 6    // �賶�� �ִ� ����
#define ITEM_NUM 5    // ������ ����

int main() {
    int totalWeight = 0;    // ������ �հ�
    int totalValue = 0;     // ��ġ�� �հ�

    // ������ ����(��ġ�� ū ������ ����)
    char name[] = { 'E', 'D', 'C', 'B', 'A' };
    int weight[] = { 5, 4, 3, 2, 1 };
    int value[] = { 650, 500, 350, 300, 100 };

    // ��ġ�� ū ������ ����
    for (int i = 0; i < ITEM_NUM; i++) {
        if (totalWeight + weight[i] <= KNAP_MAX) {
            printf("���� %c�� ����\n", name[i]);
            totalWeight += weight[i];
            totalValue += value[i];
        }
        else {
            break;
        }
    }

    // ����� ǥ��
    printf("������ �հ� = %dkg\n", totalWeight);
    printf("��ġ�� �հ� = %d��\n", totalValue);

    return 0;
}