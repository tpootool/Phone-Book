/*
Student Name: Travis Pootoolal
Student ID: 0753871
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode{
   char* firstName;
   char* lastName;
   char* phoneNumber;
   int length;
   int hashKey;
   struct listNode * next;
};

typedef struct listNode node;

node* createList();
/*
   Precondition(s): None.

   Postcondition(s): A list has been initialized with a list size of 0 and a dummy node as the head of the list with the tail of the head
                     set to NULL.The list is head of the list is returned.
*/

node* initNode(char* FName, char* LName, char* PNumber);
/*
   Precondition(s): A valid int value has been passed in as a function parameter.

   Postcondition(s): A Node has been created and initialized, the int parameter has been stored, the next pointer set to NULL.
                     The node is returned.
*/

node* addFront(node* head, char* FName, char* LName, char* PNumber);
/*
   Precondition(s): A list of the correct type and an int have been passed in as function parameters.

   Postcondition(s): A node has been added to the front of the list, its location is in the next pointer for the dummy head, the
                     location of the previous front of the list is stored in its next pointer, the list count has increased by 1.
                     The head of the list is returned.
*/

void printList(node* head);
/*
   Precondition(s): A list of the correct type has been passed as a function parameter.

   Postcontition(s): The list has been printed to screen with no return value.
*/

/*int getFrontVal(node* head);

   Precondition(s): A list of the correct type has been passed as a function parameter.

   Postcondition(s): The int value stored in the first Node is returned.
*/


node* removeFront(node* head);
/*
   Precondition(s): A list of the correct type has been passed into the function as a parameter.

   Postcondition(s): The node at the front of the list is removed, the list count has decreased by 1.
                     The removed node is returned.
*/


int listLength(node* head);
/*
   Precondition(s): A list of valid type has been passed into the function as a parameter.

   Postoncondition(s): The size of the list is returned as an int.
*/


void destroyNode(node* doomed);
/*
   Precondition(s): A struct with the correct type has been passed into the function as a parameter.

   Postcondition(s): All values within the struct are freed and the struct itself is freed.
*/

void destroyList(node* doomedList);
/*
   Precondition(s): A list of valid type has been passed into the function as a parameter.

   Postcondition(s): The list and all elements within consisting of dynamic memory has been freed.
*/

