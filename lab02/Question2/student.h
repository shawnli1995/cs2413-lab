#ifndef STUDENT_H
#define STUDENT_H

#include <stdbool.h>

typedef struct {
    int *data;      // buffer of length capacity
    int capacity;   // k
    int head;       // index of front element
    int tail;       // index of next insertion position
    int size;       // number of elements currently in queue
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
int  myCircularQueueFront(MyCircularQueue* obj);
int  myCircularQueueRear(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj);

#endif
