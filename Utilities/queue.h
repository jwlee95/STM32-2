/*
 * queue
 *
 *  Created on: Apr 30, 2025
 *      Author: JeonghWhanPro
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

#include <stdbool.h>

#define QUEUE_SIZE 256

typedef struct {
    uint8_t buffer[QUEUE_SIZE];
    uint16_t head;
    uint16_t tail;
} Queue;



void initQueue(Queue *q) {
    q->head = 0;
    q->tail = 0;
}

bool isQueueFull(Queue *q) {
    return ((q->head + 1) % QUEUE_SIZE) == q->tail;
}

bool isQueueEmpty(Queue *q) {
    return (q->head == q->tail);
}

void enqueue(Queue *q, char data) {
    if (!isQueueFull(q)) {
        q->buffer[q->head] = data;
        q->head = (q->head + 1) % QUEUE_SIZE;
    }
}

uint8_t dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        char data = q->buffer[q->tail];
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        return data;
    }
    return '\0'; // 큐가 비어있을 경우
}


#endif /* INC_QUEUE_H_ */
