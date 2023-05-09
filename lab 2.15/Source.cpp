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
		printf("Выбор: 1 - Добавление элементов; 2 - Удалить элемент; 3 - Очистка; 4 - Выход\n");
		int tmp;
		int size;
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			do {
				printf("Как добавить элемент?\n1 - клавиатура; 2 - файл\n"); scanf_s("%d", &choice);
			} while (choice < 1 and choice > 2);
			if (choice == 1) {
				printf("Введите элемент: "); scanf_s("%d", &tmp);
				if (tmp < 0) push(negative, tmp);
				if (tmp >= 0) push(positive, tmp);
			}
			if (choice == 2) {
				fopen_s(&file, "file.txt", "rt");
				do {
					printf("Сколько элементов считать?\n"); scanf_s("%d", &size);
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
				printf("Из какой очереди удаляем элемент?\n1 - negative; 2 - positive\n"); scanf_s("%d", &choice);
			} while (choice < 1 and choice > 2);
			if (choice == 1) {
				tmp = pull(negative);
				printf("Удаление элемента %d\n", tmp);
			}
			if (choice == 2) {
				tmp = pull(positive);
				printf("Удаление элемента %d\n", tmp);
			}
			break;
		case 3:
			do {
				printf("Какую очередь чистить?\n0 - обе; 1 - negative; 2 - positive\n"); scanf_s("%d", &choice);
			} while (choice < 0 and choice > 2);
			if (choice == 0) {
				clearQueue(negative);
				clearQueue(positive);
			}
			if (choice == 1)
				clearQueue(negative);
			if (choice == 2)
				clearQueue(positive);
			printf("Чистка завершена\n");
			break;
		case 4:
			clearQueue(negative);
			clearQueue(positive);
			return;
		}

		printf("Отрицательные:\n");	printQueue(negative);
		printf("Положительные:\n");	printQueue(positive);
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