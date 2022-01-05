 #include <stdio.h>
#include "list.h"
int main() {
    List liste = createList();
    appendChar(liste, 'A');
    printList(liste);
    /*
    List liste = createList();
    insertIntAt(liste, 0, 3);
    insertDoubleAt(liste, 0, 1.1);
    insertFloatAt(liste, 1, 2.1f);
    printf("length: %i\n", listLength(liste));
    printf("0 : %f \n", getDoubleAt(liste,0));
    printf("1 : %f \n", getFloatAt(liste,1));
    printf("2 : %d \n", getIntAt(liste,2));
    printList(liste);
    deleteList(liste);*/
    return 0;
}
