#include "list.h"
#include "queue.h"
#include "stdlib.h"

struct queue_struct {
    List liste;
};

Queue createQueue(){
    Queue queue = malloc(sizeof(struct queue_struct));
    queue->liste = createList();
    return queue;
}

void deleteQueue(Queue head){
    deleteList(head->liste);
    free(head);
}

int queueLength(Queue head){
    return listLength(head->liste);
}

Bool isQueueEmpty(Queue head){
    return isListEmpty(head->liste);
}

void printQueue(Queue head){
    printList(head->liste);
}

Queue addChar(Queue head, char c){
    appendChar(head->liste, c);
    return head;
}

Queue addInt(Queue head, int i){
    appendInt(head->liste, i);
    return head;
}

char getChar(Queue head){
    char c = getCharAt(head->liste, 0);
    removeAt(head->liste, 0);
    return c;
}

int getInt(Queue head){
    int i = getIntAt(head->liste, 0);
    removeAt(head->liste, 0);
    return i;
}

const char* getString(Queue head){
    const char* s = getStringAt(head->liste, 0);
    removeAt(head->liste, 0);
    return s;
}
