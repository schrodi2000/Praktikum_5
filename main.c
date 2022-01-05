 #include <stdio.h>
#include "list.h"
#include "queue.h"

void listTest(List liste){
    appendInt(liste, isListEmpty(liste));
    insertDoubleAt(liste, listLength(liste), 3.33);
    appendString(liste,"zwei");
    insertStringAt(liste, 1, getStringAt(liste, 2));
    removeAt(liste, 3);
    printList(liste);
    removeAt(liste, 0);
    insertIntAt(liste, 0, (int)isListEmpty(liste)+4);
    printDataAt(liste, 0);
}
void queueTest(Queue queue){
    addChar(queue, 'I');
    addInt(queue, queueLength(queue)+1);
    printQueue(queue);
    addChar(queue, getChar(queue));
    printf("\n");
    printQueue(queue);

}

int main() {
    List liste = createList();
    Queue queue = createQueue();
    listTest(liste);
    printf("\n---\n");
    queueTest(queue);
    return 0;
}
