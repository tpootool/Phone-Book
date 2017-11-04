/*
Student Name: Travis Pootoolal
Student ID: 0753981
*/


#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "hashAsn.h"

void errorMessage(char* msg){/* Displays an error message */
   printw("\n%s\nReturning to menu.\nPress any key to continue.",msg);
   getch();
}

void loadList(node* head, hashNode** table, char* filePath){/* Loads a '.txt' file into the linked list and hash table */
  FILE* loadFile;
  char buffer[100];
  char bufCheck[100];
  char* f;
  char* s;
  char* n;

  loadFile = fopen(filePath,"r");

  if (loadFile == NULL){
   errorMessage("\nInvalid file path.\n");
   return;
   }

  fgets(buffer,100,loadFile);
  
  do{
   strcpy(bufCheck,buffer);

   f = strtok(buffer,",");
   s = strtok(NULL,",");
   n = strtok(NULL,"\n");

   addFront(head,f,s,n);
   insert(table,head->next);

   strcpy(bufCheck,buffer);
   fgets(buffer,100,loadFile);

   } while(strcmp(buffer,bufCheck) != 0);

  fclose(loadFile);
  }

void addEntry(hashNode** table, node* head){/* Adds a single entry to the directory */
  char first[50];
  char last[50];
  char number[20];

  printw("Enter a first name: ");
  getstr(first);
  printw("\n%s\n",first);

  printw("\nEnter a last name: ");
  getstr(last);
  printw("\n%s\n",last);

  printw("\nEnter a phone number: ");
  getstr(number);

  if (strlen(number) != 10){/* If the number entered is of an incorrect length it is not stored and the user is sent to the main menu */
   errorMessage("\nPhone number must be 10 numbers long.\n");
   return;
   }

  printw("\n%s\n",number);

  addFront(head,first,last,number);
  insert(table,head->next);
}

void search(hashNode** table){/* Searches for a pre-existing entry */
  hashNode* temp;
  char* buffer;

  printw("Enter a phone number to be searched: ");

  buffer = malloc(sizeof(char)*10);
  getstr(buffer);

  if (strlen(buffer) != 10){
   errorMessage("\nPhone number must be 10 numbers long.\n");
   free(buffer);
   return;
   }

  temp = table[hashing(buffer)];

  if (temp == NULL){
   errorMessage("\nPhone number entered does not match any record.\n");
   free(buffer);
   return;
   }

  temp = lookup(table,buffer);

  if (temp != NULL){
    printw("\nFirst Name: %s\nLast Name: %s\nPhone Number: %s\n\nPress any key to go back\n",temp->hashValue->firstName,temp->hashValue->lastName,temp->hashValue->phoneNumber);
   }
  else {
    errorMessage("\nPhone number entered does not match any record.\n");
    free(buffer);
    return;
   }

  free(buffer);
  getch();
  }

void rPrint(int i, hashNode** table){/* Recursive print function */
  hashNode* temp;

 temp = table[i];
 while( i < 99 ) {

  if (temp != NULL){

   do{
      printw("First Name: %s | Last Name: %s | Phone Number: %s\n",temp->hashValue->firstName,temp->hashValue->lastName,temp->hashValue->phoneNumber);
      temp = temp->next;
      } while(temp != NULL);
   }

   rPrint(i+1, table);
   return; 
 }
}

void menuOperation(char* arg){/* The interface of the program */

 int y,x;
 int check;
 char* buffer;
 char path[100];
 node* sample;
 hashNode** hashTable;

 if (arg == NULL){/* Checks the argv entry */
   printf("\nNo file path entered.\nProgram not initiated.\n");
   return;
   }

 if (fopen(arg,"r") == NULL){
   printf("\nInvalid file path entered.\nProgram not initiated.\n");
   return;
   }

 sample = createList();

 hashTable = createHTable();

 loadList(sample,hashTable,arg);

 initscr();

 keypad(stdscr,TRUE);

 curs_set(0);

 while (y != 7){

  printw("\nPHONE BOOK DIRECTORY:\nThis program stores the first name, last name, and phone number of a person\n");

  mvprintw(5,1,"Print List");
  mvprintw(6,1,"Search Number");
  mvprintw(7,1,"Load List");
  mvprintw(8,1,"Add Single Entry");
  mvprintw(9,1,"Quit");

  mvprintw(5,0,">");

  do {/* This navigates the menu */
    check = getch(); 

    if (check == KEY_UP){
     getyx(stdscr,y,x);
     if (y > 5){
      mvprintw(y,x-x," ");
      mvprintw(y-1,x-x,">");
      }
     }

    if (check == KEY_DOWN){
     getyx(stdscr,y,x);
     if (y < 9){
      mvprintw(y,x-x," ");
      mvprintw(y+1,x-x,">");
      }
     }

     getyx(stdscr,y,x);
    } while (check == KEY_UP || check == KEY_DOWN);

  if (y == 5){
    clear();
    rPrint(0,hashTable);
    getch();
    clear();
    check = 1;
    }

  if (y == 6){
    clear();
    search(hashTable);
    clear();
    check = 1;
    }

  if (y == 7){
    clear();
    printw("Enter file path of text file: ");
    buffer = malloc(sizeof(char)*100);
    getstr(buffer);
    strncpy(path,buffer,100);
    loadList(sample,hashTable, buffer);
    check = 1;
    y = 5;
    clear();
    free(buffer);
    }

  if (y == 8){
    clear();
    addEntry(hashTable, sample);
    check = 1;
    clear();
    }

  if (y == 9){
    destroy(hashTable);
    endwin();
    return;
    }
  } 
}
