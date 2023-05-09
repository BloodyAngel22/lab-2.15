#include "Queue.h"
#include <time.h>

int random() {
	return rand() % (50 - -50 + 1) + -50;
}

void loopQueue() {
	FILE* file;
	Queue negative;
	Queue positive;
	int choice;
	while (true) {
		printf("�����: 1 - ���������� ���������; 2 - ������� �������; 3 - �������; 4 - �����\n");
		int tmp;
		int size;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			do {
				printf("��� �������� �������?\n1 - ����������; 2 - ����\n"); scanf_s("%d", &choice);
			} while (choice < 1 and choice > 2);
			if (choice == 1) {
				printf("������� �������: "); scanf_s("%d", &tmp);
				if (tmp < 0) push(negative, tmp);
				if (tmp >= 0) push(positive, tmp);
			}
			if (choice == 2) {
				fopen_s(&file, "file.txt", "rt");
				do {
					printf("������� ��������� �������?\n"); scanf_s("%d", &size);
				} while (size > 100 and size < 0);
				for (int i = 0; i < size; i++) {
					fscanf_s(file, "%d", &tmp);
					if (tmp < 0)
						push(negative, tmp);
					if (tmp >= 0)
						push(positive, tmp);
				}
				fclose(file);
			}
			break;
		case 2:
			do {
				printf("�� ����� ������� ������� �������?\n1 - negative; 2 - positive\n"); scanf_s("%d", &choice);
			} while (choice < 1 and choice > 2);
			if (choice == 1) {
				tmp = pull(negative);
				printf("�������� �������� %d\n", tmp);
			}
			if (choice == 2) {
				tmp = pull(positive);
				printf("�������� �������� %d\n", tmp);
			}
			break;
		case 3:
			do {
				printf("����� ������� �������?\n0 - ���; 1 - negative; 2 - positive\n"); scanf_s("%d", &choice);
			} while (choice < 0 and choice > 2);
			if (choice == 0) {
				clearQueue(negative);
				clearQueue(positive);
			}
			if (choice == 1)
				clearQueue(negative);
			if (choice == 2)
				clearQueue(positive);
			printf("������ ���������\n");
			break;
		case 4:
			clearQueue(negative);
			clearQueue(positive);
			return;
		}

		printf("�������������:\n");	printQueue(negative);
		printf("�������������:\n");	printQueue(positive);
	}
}

int main() {
	srand(time(NULL));
	system("chcp 1251");
	/*for (int i = 0; i < 25; i++) {
		int a = random();
		printf("%d ", a);
	}
	printf("\n");*/
	loopQueue();
}