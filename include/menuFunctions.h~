/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "hashAsn.h"

void menuOperation(char* arg);
/*
   This function loads all neccessary data for the interface and acts as the central hub for the program.
   Takes in a char* which loads the first input file to be added to the directory.
*/

void errorMessage(char* msg);
/*
   This function displays an error message and returns to the main menu of the program if prompted in a sub function.
   Takes in a char* which is the error message displayed upon calling.
*/
void loadList(node* head, hashNode** table, char* filePath);
/*
   This function loads an input '.txt' file into the directory.
   Takes in the head of a linked list as a node*. The hash table redirects to this list.
   Takes in a hash table as a hashNode**.
   Takes in the file path of an input file as a char*.
*/

void addEntry(hashNode** table, node* head);
/*
   This function prompts the user to enter the first and last name as well as the phone number of an entry to be added to the directory.
   Takes in a hash table as a hashNode**.  The entry is added to the hash table after it is added to the linked list.
   Takes in the head of a linked list.  The entry is added to the linked list before it is added to the hash table.
*/

void search(hashNode** table);
/*
   This function allows the user to search for an entry by entering a 10 digit phone number.
   Takes in the hash table that is being searched as a hashNode**.
   The 10 digit phone number is taken within the function.
*/

void rPrint(int i, hashNode** table);
/*
   This function prints the entire directory in a recursive manner.
   Takes an int as a counter.
   Takes in the hash table as a hashNode** and prints the contents of it.
*/
