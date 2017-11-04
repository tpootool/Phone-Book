/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include "hashAsn.h"

int main(){
  int i;
  char num[2];
  hashNode** testTable;
  node* tempNode;
  hashNode* tempHash;

/* Tests all hash keys possible */

  for (i=0;i<=100;i++){
  sprintf(num,"%d",i);
  printf("\nhash key of value %d: %d",i,hashing(num)); 
   }

/* Creates a hash table */

  testTable = createHTable();

  if (testTable == NULL){
   printf("\nTable created is not NULL\n");
   }

  else{
   printf("\nTable created is NULL\n");
   }

/* Creates a node to be added to the hash table */

  tempNode = initNode("Bob","Rickson","2876543219");

/* Inserts the node into the hash table */

  insert(testTable,tempNode);

/* Looks up the value of the node entered */

  tempHash = lookup(testTable,"2876543219");

  if (tempHash == NULL){
   printf("\nNo item was inserted\n");
   }

  else{
   printf("\nFirst Name: %s, Last Name: %s, Phone Number: %s\n",tempHash->hashValue->firstName,tempHash->hashValue->lastName,tempHash->hashValue->phoneNumber);
   }

/* Creates a new node that will collide with the current entry in the hash table */

  tempNode = initNode("Rick","Bobson","2812345678");

  insert(testTable,tempNode);

  tempHash = lookup(testTable,"2812345678");

  if (tempHash == NULL){
   printf("\nNo item was inserted\n");
   }

  else{
   printf("\nFirst Name: %s, Last Name: %s, Phone Number: %s\n",tempHash->hashValue->firstName,tempHash->hashValue->lastName,tempHash->hashValue->phoneNumber);
   }

/* Creates a new node that will collide with the current entry in the hash table */

  tempNode = initNode("Mick","Robson","2823456789");

  insert(testTable,tempNode);

  tempHash = lookup(testTable,"2823456789");

  if (tempHash == NULL){
   printf("\nNo item was inserted\n");
   }

  else{
   printf("\nFirst Name: %s, Last Name: %s, Phone Number: %s\n",tempHash->hashValue->firstName,tempHash->hashValue->lastName,tempHash->hashValue->phoneNumber);
   }

/* Tests the remove function */

  removeNode(testTable,"2823456789");

  tempHash = lookup(testTable,"2823456789");

  if (tempHash == NULL){
   printf("\nNo item was inserted\n");
   }

  else{
   printf("\nFirst Name: %s, Last Name: %s, Phone Number: %s\n",tempHash->hashValue->firstName,tempHash->hashValue->lastName,tempHash->hashValue->phoneNumber);
   }

/* Frees the table from memory */

  destroy(testTable);


return 0;
}
