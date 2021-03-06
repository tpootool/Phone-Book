/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "ListFunctions.h"

struct HashNode{
   node* hashValue;
   struct HashNode* next;

};

typedef struct HashNode hashNode;

int hashing(char* PNumber);
/*
   The hash function.
   Takes an array of 10 characters. The first two characters of the phone number array are taken andthe modulus function is used to return
   a hash key.
*/

hashNode** createHTable();
/*
   Creates a hash table by using malloc.
*/

void destroy(hashNode** doomedTable);
/*
   Frees all of the memory stored in a hash table and then frees the hash table itself.
   Takes a hashNode** as the hash table to be freed.
*/

void insert(hashNode** table, node* toBeHash);
/*
   Inserts an item into the hash table from a linked list.
   A pointer to the location of the item in the linked list is stored into the hash table.
   Takes a pointer to a hash table to which the item will be added.
   Takes a node* as the head of a list to which the item belongs to.
*/

hashNode* lookup(hashNode** table, char* number);
/*
   Searches for an item in the hash table passed into the function.
   Takes a hashNode** as the hash table to be searched.
   Takes a char* as the phone number to be searched.
*/
void removeNode(hashNode** table, char* number);
/*
   Removes an item from the hash table passed into the function.
   Takes a hashNode** as the hash table to have an item taken out of.
   Takes a char* as the phone number to search for the corresponding item to be removed.
*/
