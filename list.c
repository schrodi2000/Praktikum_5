#include "list.h"
#include "stdlib.h"

typedef union value {
    char CHAR;
    long LONG;
    int INT;
    float FLOAT;
    double DOUBLE;
    const char *STRING;
} Data;         /* Datum eines belibigen Datentyps. */
typedef enum datentyp_enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING,
    LONG,
    NONE
} DataType;     /* liste der Datentypen in einem Enum zusammengefasst */
struct list_struct {
    DataType type;
    Data value;
    List next;
};

List createList() {
    List liste = malloc(sizeof(struct list_struct));
    liste->type = NONE;
    liste->next = NULL;
    return liste;
}

void deleteList(List head){
    /*TODO jedes listen element free machen mit free()*/
    head->type = NONE;
    head->next = NULL;
}

List removeAt(List head, int index){
    /*TODO wenn das 0. element gelöscht werden soll, dann soll das nächste einfach dem 0. überschrieben werden*/
    List vorheriger = createList();
    if (index < 0) exit(-4);
    while(index){
        vorheriger = head;
        head = head->next;
        index--;
    }
    vorheriger->next = head->next;
    free(head);
    return vorheriger;
}

/*
 * Insert und Append Funktionen
 * */
List insert(List head, int index) {
    List new = createList();
    List vorheriger = NULL;
    List jetziger = head;
    if (jetziger->type != NONE) {
        while (index != 0 && jetziger != NULL) {
            vorheriger = jetziger;
            jetziger = jetziger->next;
            index--;
        }
        if (1 < index) {
            exit(-1);
        }
        new->next = jetziger;
        if (vorheriger != NULL) {
            vorheriger->next = new;
        }
        return new;
    }
    return head;
}       /* gleichbleibender teil der insert Funktionen */

List insertIntAt(List head, int index, int value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = INT;
    new->value.INT = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List insertCharAt(List head, int index, char value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = CHAR;
    new->value.CHAR = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List insertLongAt(List head, int index, long value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = LONG;
    new->value.LONG = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List insertFloatAt(List head, int index, float value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = FLOAT;
    new->value.FLOAT = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List insertDoubleAt(List head, int index, double value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = DOUBLE;
    new->value.DOUBLE = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List insertStringAt(List head, int index, const char *value) {
    List new, test;
    test = createList();
    if (index < 0) exit(-2);
    new = insert(head, index);
    new->type = STRING;
    new->value.STRING = value;
    if(index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    return head;
}

List appendInt(List head, int value) {
    List new = insert(head, -1);
    new->type = INT;
    new->value.INT = value;
    /*TODO wenn es der 0. eintrag ist, soll das statt in new in head geschrieben werden.*/
    return head;
}

List appendChar(List head, char value) {
    List new = insert(head, -1);
    new->type = CHAR;
    new->value.CHAR = value;
    return head;
}

List appendLong(List head, long value) {
    List new = insert(head, -1);
    new->type = LONG;
    new->value.LONG = value;
    return head;
}

List appendFloat(List head, float value) {
    List new = insert(head, -1);
    new->type = FLOAT;
    new->value.FLOAT = value;
    return head;
}

List appendDouble(List head, double value) {
    List new = insert(head, -1);
    new->type = DOUBLE;
    new->value.DOUBLE = value;
    return head;
}

List appendString(List head, const char *value) {
    List new = insert(head, -1);
    new->type = STRING;
    new->value.STRING = value;
    return head;
}

/*
 * Get Funktionen
 * */
List get(List head, int index){
    while(index){
        head = head->next;
        index--;
    }
    return head;
}       /* gleichbleibender teil der get Funktionen */

char getCharAt(List head,int index){
    head = get(head, index);
    if (head->type != CHAR) exit(-3);
    return head->value.CHAR;
}

int getIntAt(List head,int index){
    head = get(head, index);
    if (head->type != INT) exit(-3);
    return head->value.INT;
}

long getLongtAt(List head,int index){
    head = get(head, index);
    if (head->type != LONG) exit(-3);
    return head->value.LONG;
}

float getFloatAt(List head,int index){
    head = get(head, index);
    if (head->type != FLOAT) exit(-3);
    return head->value.FLOAT;
}

double getDoubleAt(List head,int index){
    head = get(head, index);
    if (head->type != DOUBLE) exit(-3);
    return head->value.DOUBLE;
}

const char* getStringAt(List head,int index){
    head = get(head, index);
    if (head->type != STRING) exit(-3);
    return head->value.STRING;
}

