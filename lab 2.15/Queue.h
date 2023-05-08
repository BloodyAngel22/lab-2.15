#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Element {
	int data;
	Element* next;
};

struct Queue {
	Element* head = NULL, * tail = NULL;
};

void push(Queue& q, int d); int pull(Queue& q); void printQueue(const Queue& q);