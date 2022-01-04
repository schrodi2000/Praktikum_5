/*
 * list.h
 *
 *  Created on: 07.12.2021
 *      Author: nwulff
 */

#ifndef LIST_H_
#define LIST_H_

#ifndef BOOLEAN
#define BOOLEAN
typedef enum {false, true} Bool;
#endif
/**
 * Forward pointer declaration to an internal implementation specific hidden list structure.
 */
typedef struct list_struct* List;
/**
 * List life-cycle functions create and delete list or remove a single node with index
 */
List createList();
void deleteList(List head);
List removeAt(List head, int index);
/**
 * List length functions.
 */
int  listLength(List head);
Bool isListEmpty(List head);
/**
 * print functions to stdout.
 */
void printList(List head);
void printDataAt(List head,int index);
/**
 * type-safe data insertion with an index
 */
List insertCharAt(List head, int index, char c);
List insertIntAt(List head, int index, int i);
List insertLongAt(List head, int index, long l);
List insertFloatAt(List head, int index, float f);
List insertDoubleAt(List head, int index, double d);
List insertStringAt(List head, int index, const char *s);
/**
 * type-safe data insertion at end of list
 */
List appendChar(List head, char c);
List appendInt(List head, int i);
List appendLong(List head, long l);
List appendFloat(List head, float f);
List appendDouble(List head, double d);
List appendString(List head, const char *s);
/**
 * type-safe read access to the data with an index
 */
char   getCharAt(List head,int index);
int    getIntAt(List head,int index);
long   getLongAt(List head,int index);
float  getFloatAt(List head,int index);
double getDoubleAt(List head,int index);
const char* getStringAt(List head,int index);


#endif /* LIST_H_ */