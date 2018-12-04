//
// core.c
// 308 Final Project
//
// Created by Vivian Weaver and Emily Davich
// Copyright 2018
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "library.h"

#include "core.h"
#include "book.h"

//Appearance of books application
int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");
    
    //start of linkedlist
    Library * lib; 
    //current point in linkedlist
    Library * curLib;
    
    char choice;
    int resultNotFound = 1;
    //Allows user to search through the library until they make a selection.
    while(resultNotFound){
     
      printf("How would you like to search the library?");
      printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
      choice = getchar(); 

        //open book directory
    	FILE *dir;
    	char buf[250];
    	dir = fopen("booksdirectory.txt", "r");
	if (dir == NULL){
	    printf("Bad file");
	    continue;	
        }

        //read in the book directory file
	while(fgets(buf, 250, dir)!= NULL){
            Library * newLib = malloc(sizeof(Library));
       
	    if(curLib == NULL){
               curLib = newLib;
               lib = newLib;
            }
            else {
               curLib->next = newLib;
	       curLib = curLib->next;
            }
            
	    /*
            //tokenize string
	    char* token = strtok(buf, ",");
	    int i = atoi(token);
	    i = i-1;
	    printf("%d\n", i);
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.title, token);
	    printf("%s\n", curLib->booklist.title);
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.author.author, token);
	    printf("%s\n", curLib->booklist.author.author);
	    token = strtok(NULL, ",");
	    int num = atoi(token);
	    curLib ->booklist.date = num;
	    printf("%d\n", curLib->booklist.date);
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.filename, token);
	    printf("%s\n", curLib->booklist.filename);
	    curLib = curLib->next;
	    */
	}
	

	//close the file
	fclose(dir);
	
	return 0;
    	

    }
}
