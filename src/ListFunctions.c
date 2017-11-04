/*
Student Name: Travis Pootoolal
Student ID: 0753871

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListFunctions.h"

node* createList(){ /* Creates a list with a dummy head. */

  node* toBeMade;

  toBeMade = malloc(sizeof(node)*1);
  toBeMade->next = NULL;
  toBeMade->length = 0;

  return (toBeMade);
}

node* initNode(char* FName, char* LName, char* PNumber){ /* Initializes a node to be added to a list. */

  node* newElement;

  newElement = malloc(sizeof(node)*1);

  newElement->firstName = malloc(sizeof(char)*(strlen(FName)+1) );
  strcpy(newElement->firstName,FName);

  newElement->lastName = malloc(sizeof(char)*(strlen(LName)+1) );
  strcpy(newElement->lastName,LName);

  newElement->phoneNumber = malloc(sizeof(char)*(strlen(PNumber)+1) );
  strcpy(newElement->phoneNumber,PNumber);

  newElement->next = NULL;

 return newElement;
}

node* addFront(node* head, char* FName, char* LName, char* PNumber){ /* Creates and adds a node to the front of a list. */

  node* temp;

  temp = initNode(FName,LName,PNumber);

  if (head->next != NULL){
   temp->next = head->next;
   }

  head->next = temp;
  head->length ++ ;

  return (head);
}

void printList(node* head){ /* Prints the contents of a list */

  node* currentPosition;

  currentPosition = head->next;
  printf("\n");
  while(currentPosition->next != NULL){
   printf("\nLast Name:%s\nFirst Name: %s\nPhone Number: %s\n",currentPosition->lastName, currentPosition->firstName, currentPosition->phoneNumber);
   currentPosition = currentPosition->next;
  }
  printf("\nLast Name:%s\nFirstName: %s\nPhone Number: %s\n",currentPosition->lastName, currentPosition->firstName, currentPosition->phoneNumber);
}
/*
int getFrontVal(node* head){  Retrieves the value stored by the first data containing node in the list. 

  return (head->next->nodeValue);
} */

node* removeFront(node* head){ /* Removes the first data containing node in the list. */

  node* temp;

  temp = head->next;
  if (head->next->next != NULL){
   head->next = head->next->next;
  }
  else{
   head->next = NULL;
  }

  head->length -- ;

  return (temp);
}

int listLength(node* head){ /* Returns the number of items in a list. */

  return (head->length);
}

void destroyNode(node* doomed){ /* Frees a node */

  free(doomed->firstName);
  free(doomed->lastName);
  free(doomed->phoneNumber);
  free(doomed);
}

void destroyList(node* doomedList){ /* Frees the contents of a list */

  node* nextPosition;

  nextPosition = doomedList->next;

  while(nextPosition->next != NULL){
   destroyNode(doomedList);
   
   doomedList = nextPosition;
   nextPosition = nextPosition->next;
  }
  free(doomedList); 
}
