#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KNAP_MAX 6    // �賶�� �ִ� ����
#define ITEM_NUM 5    // ������ ����

#define IND_NUM 8	         // ��ü ��
#define MUTATE_RATE 0.1    // �������� Ȯ��(10%)

char itemName[] = { 'A', 'B', 'C', 'D', 'E' };    // ������ �̸�
int itemWeight[] = { 1, 2, 3, 4, 5 };             // ������ ����
int itemValue[] = { 100, 300, 350, 500, 650 };    // ������ ��ġ

int indGeneration;                 // ��ü�� ����
int indGene[IND_NUM][ITEM_NUM];    // ��ü�� ������
int indWeight[IND_NUM];            // ��ü�� ����
int indValue[IND_NUM];             // ��ü�� ��ġ
int indFitness[IND_NUM];           // ��ü�� ������

// ��ü�� �������� �����ϴ� �Լ�
void createIndividual() {
    int ind, item;    // ���� ī����

    // 0 �Ǵ� 1�� �������� ����
    for (ind = 0; ind < IND_NUM; ind++) {
        for (item = 0; item < ITEM_NUM; item++) {
            indGene[ind][item] = rand() % 2;
        }
    }
}

// ��ü�� ����, ��ġ, �������� ����ϴ� �Լ�
void calcIndividual() {
    int ind, item;    // ���� ī����

    for (ind = 0; ind < IND_NUM; ind++) {
        // ���Կ� ��ġ�� ���
        indWeight[ind] = 0;
        indValue[ind] = 0;
        for (item = 0; item < ITEM_NUM; item++) {
            if (indGene[ind][item] == 1) {
                indWeight[ind] += itemWeight[item];
                indValue[ind] += itemValue[item];
            }
        }

        // �������� ���
        if (indWeight[ind] <= KNAP_MAX) {
            // �ִ� ���� ���ϸ� ��ġ�� �״�� �������� ����
            indFitness[ind] = indValue[ind];
        }
        else {
            // �ִ� ���Ը� �ʰ��ϸ� �������� 0���� ��
            indFitness[ind] = 0;
        }
    }
}

// ��ü�� ������ ǥ���ϴ� �Լ�
void showIndividual() {
    int ind, item;    // ���� ī����

    // ���븦 ǥ��
    printf("\n<%d����>\n", indGeneration);

    // ������, ����, ��ġ, �������� ǥ��
    printf("������\t\t����\t��ġ\t������\n");
    for (ind = 0; ind < IND_NUM; ind++) {
        for (item = 0; item < ITEM_NUM; item++) {
            printf("[%d]", indGene[ind][item]);
        }
        printf("\t%2dkg\t%4d��\t%4d\n", indWeight[ind], indValue[ind], indFitness[ind]);
    }
    printf("\n");
}

// �������� ū ������� ��ü�� �����ϴ� �Լ�
void sortIndividual() {
    int pos;     // ������ ���
    int ins;     // ������ ��ġ
    int item;    // ���� ī����
    int tmp;     // �ӽ� ����

    // ���� ���ķ� ����
    for (pos = 1; pos < IND_NUM; pos++) {
        ins = pos;
        while (ins >= 1 && indFitness[ins - 1] < indFitness[ins]) {
            for (item = 0; item < ITEM_NUM; item++) {
                tmp = indGene[ins - 1][item];
                indGene[ins - 1][item] = indGene[ins][item];
                indGene[ins][item] = tmp;
            }

            tmp = indWeight[ins - 1];
            indWeight[ins - 1] = indWeight[ins];
            indWeight[ins] = tmp;

            tmp = indValue[ins - 1];
            indValue[ins - 1] = indValue[ins];
            indValue[ins] = tmp;

            tmp = indFitness[ins - 1];
            indFitness[ins - 1] = indFitness[ins];
            indFitness[ins] = tmp;

            ins--;
        }
    }
}

// ���¸� �����ϴ� �Լ�
void selectIndividual() {
    int ind, item;    // ���� ī����

    // ������ ���� 50%�� ���� 50%�� ����(���� 50%�� ���½�Ŵ)
    for (ind = 0; ind < IND_NUM / 2; ind++) {
        for (item = 0; item < ITEM_NUM; item++) {
            indGene[ind + IND_NUM / 2][item] = indGene[ind][item];
        }
    }
    printf("���� 50���� ���½��׽��ϴ�.\n");
}

// ������ �����ϴ� �Լ�
void crossoverIndividual() {
    int ind, item;         // ���� ī����
    int crossoverPoint;    // ���� ���� ��ġ
    int tmp;               // �ӽ� ����

    // ���� 50%�� ������ ��ü�� ������� ��
    for (ind = IND_NUM / 2; ind < (IND_NUM - 1); ind += 2) {
        // ������ ��ġ�� ���Ƿ� ����
        crossoverPoint = rand() % (ITEM_NUM - 1) + 1;
        for (item = crossoverPoint; item < ITEM_NUM; item++) {
            // �̿� ��ü�� ���� ����
            tmp = indGene[ind][item];
            indGene[ind][item] = indGene[ind + 1][item];
            indGene[ind + 1][item] = tmp;
        }
        printf("��ü %d�� %d�� %d�� ��ġ���� �����߽��ϴ�.\n", ind, ind + 1, crossoverPoint);
    }
}

// �������̸� ����� �Լ�
void mutateIndividual() {
    int ind, item;    // ���� ī����

    // ���� 50%�� ������ ��ü�� ������� ��
    for (ind = IND_NUM / 2; ind < IND_NUM; ind++) {
        for (item = 0; item < ITEM_NUM; item++) {
            // �̸� ������ Ȯ���� �������� �����
            if (rand() / (double)RAND_MAX <= MUTATE_RATE) {
                // ������ ������ ������
                indGene[ind][item] ^= 1;
                printf("��ü %d�� %d ��ġ���� �������̸� ��������ϴ�.\n", ind, item);
            }
        }
    }
}

// ���α׷��� ������ �������� main �Լ�
int main() {
    int genMax;    // �ִ� ����
    int item;      // ���� ī����

    // ������ �����ϴ� �õ尪�� ����(1970/1/1�� ����)
    srand((unsigned int)time(NULL));

    // Ű����� �ִ� ���븦 �Է�
    printf("�ִ� ���� = ");
    scanf_s("%d", &genMax);

    // 1���� ��ü�� ����
    indGeneration = 1;
    createIndividual();

    // �������� ���
    calcIndividual();

    // �������� ū ������ ��ü�� ����
    sortIndividual();

    // ��ü�� ǥ��
    showIndividual();

    // 1���뾿 ��ȭ��Ű��
    indGeneration++;
    while (indGeneration <= genMax) {
        // �������� ū ������ ��ü�� ����
        sortIndividual();

        // ���½�Ŵ
        selectIndividual();

        // ������Ŵ
        crossoverIndividual();

        // �������̽�Ŵ
        mutateIndividual();

        // �������� ���
        calcIndividual();

        // �������� ū ������ ��ü�� ����
        sortIndividual();

        // ��ü�� ǥ��
        showIndividual();

        // ���� ����� ���ư�
        indGeneration++;
    }

    // �������� ���� ���� ��ü�� �������� ǥ��
    printf("<�賶�� ��� �ִ� ������ ǥ���մϴ�.>\n");
    for (item = 0; item < ITEM_NUM; item++) {
        if (indGene[0][item] == 1) {
            printf("%c, %dkg, %d��\n", itemName[item], itemWeight[item], itemValue[item]);
        }
    }
    printf("\n<������ ǥ��>\n");
    printf("������ �հ� = %dkg\n", indWeight[0]);
    printf("��ġ�� �ִ� = %d��\n", indValue[0]);

    return 0;
}