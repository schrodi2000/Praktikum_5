#include "list.h"
#include "stdlib.h"
#include "stdio.h"

typedef union value {
    char CHAR;
    long LONG;
    int INT;
    float FLOAT;
    double DOUBLE;
    const char* STRING;
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

void isIndexCorrect(List head, int index) {
    if (index < 0 || index > listLength(head)) {
        printf("Index is incorrect");
        exit(-2);
    }
}

int listLength(List head) {
    int i = 1;
    if (head->type == NONE) return 0;
    while (head->next != NULL) {
        head = head->next;
        i++;
    }
    return i;
}

Bool isListEmpty(List head) {
    return head->type == NONE ? true : false;
}

void printList(List head) {
    while (head != NULL) {
        switch (head->type) {
            case CHAR:
                printf("Type: Char    Value: %c\n", head->value.CHAR);
                break;
            case DOUBLE:
                printf("Type: Double  Value: %f\n", head->value.DOUBLE);
                break;
            case FLOAT:
                printf("Type: Float   Value: %f\n", head->value.FLOAT);
                break;
            case INT:
                printf("Type: Int     Value: %i\n", head->value.INT);
                break;
            case LONG:
                printf("Type: Long    Value: %lo\n", head->value.LONG);
                break;
            case STRING:
                printf("Type: String  Value: %s\n", head->value.STRING);
                break;
            case NONE:
                break;
        }
        head = head->next;
    }
}

void printDataAt(List head, int index) {
    isIndexCorrect(head, index);
    while (index) {
        head = head->next;
        index--;
    }
    switch (head->type) {
        case CHAR:
            printf("Type: Char    Value: %c\n", head->value.CHAR);
            break;
        case DOUBLE:
            printf("Type: Double  Value: %f\n", head->value.DOUBLE);
            break;
        case FLOAT:
            printf("Type: Float   Value: %f\n", head->value.FLOAT);
            break;
        case INT:
            printf("Type: Int     Value: %i\n", head->value.INT);
            break;
        case LONG:
            printf("Type: Long    Value: %lo\n", head->value.LONG);
            break;
        case STRING:
            printf("Type: String  Value: %s\n", head->value.STRING);
            break;
        case NONE:
            break;
    }
}

List createList() {
    List liste = malloc(sizeof(struct list_struct));
    liste->type = NONE;
    liste->next = NULL;
    return liste;
}

void deleteList(List head) {
    List next;
    while (head != NULL) {
        next = head->next;
        free(head);
        head = next;
    }
}

List removeAt(List head, int index) {
    List next;
    isIndexCorrect(head, index);
    if (index > 0) {
        List jetziger = head;
        List vorheriger = index ? NULL : createList();
        while (index) {
            vorheriger = jetziger;
            jetziger = jetziger->next;
            index--;
        }
        vorheriger->next = jetziger->next;
        free(jetziger);
    } else {
        if (head->next != NULL) {
            next = head->next;
            head->type = next->type;
            head->value = next->value;
            head->next = next->next;
            free(next);
        } else {
            head->type = NONE;
        }
    }
    return head;
}

/*
 * Insert und Append Funktionen
 * */
List insert(List head, int index) {
    List new = createList();
    List vorheriger = NULL;
    List jetziger = head;
    isIndexCorrect(head, index);
    if (jetziger->type != NONE) {
        while (index != 0 && jetziger != NULL) {
            vorheriger = jetziger;
            jetziger = jetziger->next;
            index--;
        }
        new->next = jetziger;
        if (vorheriger != NULL) {
            vorheriger->next = new;
        }
        return new;
    }
    free(new);
    return head;
}       /* gleichbleibender teil der insert Funktionen */

List insertIntAt(List head, int index, int value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = INT;
    new->value.INT = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List insertCharAt(List head, int index, char value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = CHAR;
    new->value.CHAR = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List insertLongAt(List head, int index, long value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = LONG;
    new->value.LONG = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List insertFloatAt(List head, int index, float value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = FLOAT;
    new->value.FLOAT = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List insertDoubleAt(List head, int index, double value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = DOUBLE;
    new->value.DOUBLE = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List insertStringAt(List head, int index, const char* value) {
    List new, test;
    test = createList();
    new = insert(head, index);
    new->type = STRING;
    new->value.STRING = value;
    if (index == 0) {
        *test = *head;
        *head = *new;
        head->next = new;
        *new = *test;
    }
    free(test);
    return head;
}

List appendInt(List head, int value) {
    List new = insert(head, listLength(head));
    new->type = INT;
    new->value.INT = value;
    return head;
}

List appendChar(List head, char value) {
    List new = insert(head, listLength(head));
    new->type = CHAR;
    new->value.CHAR = value;
    return head;
}

List appendLong(List head, long value) {
    List new = insert(head, listLength(head));
    new->type = LONG;
    new->value.LONG = value;
    return head;
}

List appendFloat(List head, float value) {
    List new = insert(head, listLength(head));
    new->type = FLOAT;
    new->value.FLOAT = value;
    return head;
}

List appendDouble(List head, double value) {
    List new = insert(head, listLength(head));
    new->type = DOUBLE;
    new->value.DOUBLE = value;
    return head;
}

List appendString(List head, const char* value) {
    List new = insert(head, listLength(head));
    new->type = STRING;
    new->value.STRING = value;
    return head;
}

/*
 * Get Funktionen
 * */
List get(List head, int index) {
    isIndexCorrect(head, index);
    while (index) {
        head = head->next;
        index--;
    }
    return head;
}       /* gleichbleibender teil der get Funktionen */

char getCharAt(List head, int index) {
    head = get(head, index);
    if (head->type != CHAR) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.CHAR;
}

int getIntAt(List head, int index) {
    head = get(head, index);
    if (head->type != INT) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.INT;
}

long getLongtAt(List head, int index) {
    head = get(head, index);
    if (head->type != LONG) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.LONG;
}

float getFloatAt(List head, int index) {
    head = get(head, index);
    if (head->type != FLOAT) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.FLOAT;
}

double getDoubleAt(List head, int index) {
    head = get(head, index);
    if (head->type != DOUBLE) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.DOUBLE;
}

const char* getStringAt(List head, int index) {
    head = get(head, index);
    if (head->type != STRING) {
        printf("wrong Datatype.");
        exit(-3);
    }
    return head->value.STRING;
}

