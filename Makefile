CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : testing program


testing :
	gcc $(CFLAGS) src/ListFunctions.c src/hashAsn.c src/hashTester.c -Iinclude -obin/test


program: 
	gcc $(CFLAGS) src/ListFunctions.c src/phoneBookAsn.c src/hashAsn.c src/menuFunctions.c -lncurses -Iinclude -obin/phoneBook

clean:
	@ rm *.o



