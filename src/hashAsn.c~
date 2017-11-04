/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "menuFunctions.h"

int hashing(char* PNumber){/* The hash function */
  int hashKey;
  char cast[2];

  strncpy(cast,PNumber,2);

  hashKey = (strtol(cast,NULL,10)) % 100;

  return hashKey;
  }

hashNode** createHTable(){/* Creates a hash table of size 100 */
  hashNode** newTable;
  
  newTable = malloc(sizeof(hashNode*)*100);

  return newTable;
  }

void destroy(hashNode** doomedTable){/* Frees hash table from memory */
  int i;
  hashNode* temp;

  for(i=0;i<10;i++){

   if(doomedTable[i] != NULL){   

   temp = doomedTable[i];

    do{

     free(temp->hashValue->firstName);
     free(temp->hashValue->lastName);
     free(temp->hashValue->phoneNumber);

     temp = temp->next;

     } while(temp != NULL);

    free(doomedTable[i]);
    }
   }

  free(doomedTable);
  }

void insert(hashNode** table, node* toBeHash){/* Inserts an element into the hash table */
  hashNode* temp;
  hashNode* prevLocation;
  int key, i;

  key = hashing(toBeHash->phoneNumber);
  temp = malloc(sizeof(hashNode)*1);
  temp->hashValue = toBeHash;

  prevLocation = table[key];


  if (table[key] == NULL){/* If there's no entry in the table the current entry is made the first */
   table[key] = temp;
   }

  else if (table[key] != NULL){/* If there's an entry in the hash table a series of checks determines where the new entry should be added */

    for (i=1;i<10;i++){/* Checks each individual number of the entry to be added with other entries in the table */

     if (table[key]->hashValue->phoneNumber[i] > temp->hashValue->phoneNumber[i]){/* If the number in the first slot of the hash table is 
                                                                                     larger than the one to be entered, the new entry is 
                                                                                     added to the front of the list */

      temp->next = table[key];
      table[key] = temp;
      break;
      }

     else if (prevLocation->hashValue->phoneNumber[i] < temp->hashValue->phoneNumber[i]){/* If the current item in the hash table has a 
                                                                                            number lower than the entry to be added three
                                                                                            checks are performed: */

       if (prevLocation->next == NULL){/* If there's no 'next' entry in the item being checked, the entry to be added is added after the
                                          current item */
        prevLocation->next = temp;
        break;
        }

       if (prevLocation->next != NULL){/* If there is an entry after the item being checked, two checks are performed: */

         if (prevLocation->next->hashValue->phoneNumber[i] > temp->hashValue->phoneNumber[i]){/* If the number of the 'next' item of the 
                                                                                                 current entry is larger than the entry to
                                                                                                 be added, it is inserted after the current
                                                                                                 item and before its 'next' item */
          temp->next = prevLocation->next;
          prevLocation->next = temp;
          break;
          }

         if (prevLocation->next->hashValue->phoneNumber[i] <= temp->hashValue->phoneNumber[i]){/* If the number of the 'next' item of the 
                                                                                                  current entry is equal to or less than
                                                                                                  the entry to be added, the pointer of the
                                                                                                  current item goes to the next value, resets
                                                                                                  the loop counter to its starting value and
                                                                                                  performs the same checks for the next 
                                                                                                  location in the list*/
          prevLocation = prevLocation->next;
          i = 0;
          }

         }/* if != NULL bracket */
    }/* else if bracket */
   }/* for loop bracket */
  }/* else if bracket */
 }/* function bracket*/

hashNode* lookfor(int i, char* number,hashNode* temp){

   i = 0;
   while (i < 9){
    if (number[i] != temp->hashValue->phoneNumber[i]){
     temp = temp ->next;
     i = 0;
     continue;
     }

    else{
     temp = (lookfor(i+1, number, temp));
     return temp;
     }
    }
   return temp;
   }

hashNode* lookup(hashNode** table, char* number){
  hashNode* temp;
  int i;

  temp = table[hashing(number)];

  if (temp == NULL){
   return temp;
   }

  for (i=0;i<10;i++){/* Searches for an identical match */
   if (number[i] != temp->hashValue->phoneNumber[i]){
    temp = temp->next;
    i = 0;

    if (temp == NULL){
     return temp;
     }
    }
   } 

  return temp;
  }

void removeNode(hashNode** table, char* number){/* Removes an item from the hash table */
  hashNode* temp;
  hashNode* prev;
  int i;

  temp = lookup(table,number);

  if (temp->next != NULL){

  prev = table[hashing(number)];

   for (i=0;i<10;i++){/* If there's an entry after the item being removed, it is placed after the previous item */
    if (number[i] != prev->next->hashValue->phoneNumber[i]){
     prev = prev->next;
     i = 0;
      }
     }

    prev->next = temp->next;
    }

  free(temp->hashValue->firstName);
  free(temp->hashValue->lastName);
  free(temp->hashValue->phoneNumber);
  free(temp);
  }
