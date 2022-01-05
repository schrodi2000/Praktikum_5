//
// Created by schro on 05.01.2022.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H

typedef struct queue_struct *Queue;

Queue createQueue();

void deleteQueue(Queue head);

int queueLength(Queue head);

Bool isQueueEmpty(Queue head);

void printQueue(Queue head);

Queue addChar(Queue head, char c);

Queue addInt(Queue head, int i);

char getChar(Queue head);

int getInt(Queue head);

const char* getString(Queue head);

#endif //UNTITLED_QUEUE_H
