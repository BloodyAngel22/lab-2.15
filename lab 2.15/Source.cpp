#include "Queue.h"

void loopQueue() {
	Queue q;
	int choice;
	while (true) {
		printf("�����: 1 - �������� ����� �������; 2 - ������� �������; 3 - �����\n");
		int tmp;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("������� ������� ");
			scanf_s("%d", &tmp);
			push(q, tmp);
			break;
		case 2:
			tmp = pull(q);
			printf("�������� �������� %d\n", tmp);
			break;
		case 3:
			return;
		}

		printQueue(q);
	}
}

int main() {
	system("chcp 1251");
	loopQueue();
}