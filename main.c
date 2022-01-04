 #include <stdio.h>
#include "list.h"
int main() {
    int test;
    List liste = createList();
    insertIntAt(liste, 0, 3);
    insertIntAt(liste, 0, 1);
    insertIntAt(liste, 1, 2);
    removeAt(liste, 0);
    printf("0 : %i \n", getIntAt(liste,0));
    printf("1 : %i \n", getIntAt(liste,1));
    printf("2 : %i \n", getIntAt(liste,2));
    return 0;
}
