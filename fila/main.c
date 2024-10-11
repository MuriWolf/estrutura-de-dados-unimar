#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int capacity, size, front, back;
	int* items;
} Queue;

Queue* createQueue(int capacity) {
	Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));

	newQueue->capacity = capacity;
	newQueue->size = 0;
	newQueue->front = 0;
	newQueue->back = capacity - 1;
	newQueue->items = (int*)calloc(capacity, sizeof(int));

	return newQueue;
}

void enqueue(Queue* q, int newItem) {
	if (q->size == q->capacity) {
		printf("Queue is full. Action now allowed.");
	}
	else {
		q->back = (q->back + 1) % q->capacity; // modulo because is circular 
		*(q->items + q->back) = newItem;
		q->size++;
	}
}

int dequeue(Queue* q) {
	if (q->size == 0) {
		printf("Queue is empty. Action now allowed.");
		return -1;
	}
	else {
		int removedItem = *(q->items + q->back);
		q->front = (q->back + 1) % q->capacity;
		q->size--;

		return removedItem;
	}
}

void showQueueItems(Queue* q) {
	int back = q->back;
	for (int i = 0; i < q->size; i++) {
		printf("%d", *(q->items + q->back));
		back = (back + 1) % q->capacity;
	}
}

int isFull(Queue* q) {
	if (q->size == q->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty(Queue* q) {
	if (q->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	Queue* queue;
	queue = createQueue(5);

	enqueue(queue, 10);
	dequeue(queue);


	return 0;
}