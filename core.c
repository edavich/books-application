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

#include "core.h"
#include "book.h"


//Appearance of books application
int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");

    printf("How would you like to search the library?");
    printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
    char choice = getchar();
 
    int noResult = 1;
    while (noResult){
 
        //open book directory
    	FILE *dir;
    	char buf[250];
    	dir = fopen("booksdirectory.txt", "r");
	if (dir == NULL){
	    printf("Bad file");
	    continue;
	}

        //?
	int i;
	Library book1;
	Library book2;
	Library book3;
	Library book4;
	Library book5;

	book1.next = &book2;
	book2.next = &book3;
	book3.next = &book4;
	book4.next = &book5;
	book5.next = NULL;	
        
        //?
	Library * cur = &book1;

        //read in the book directory
	while(fgets(buf, 250, dir)!= NULL){
	    char* token = strtok(buf, ",");
	    i = atoi(token);
	    i = i-1;
	    printf("%d\n", i);
	    token = strtok(NULL, ",");
            strcpy(cur->booklist.title, token);
	    printf("%s\n", cur->booklist.title);
	    token = strtok(NULL, ",");
            strcpy(cur->booklist.author.author, token);
	    printf("%s\n", cur->booklist.author.author);
	    token = strtok(NULL, ",");
	    int num = atoi(token);
	    cur->booklist.date = num;
	    printf("%d\n", cur->booklist.date);
	    token = strtok(NULL, ",");
            strcpy(cur->booklist.filename, token);
	    printf("%s\n", cur->booklist.filename);
	    cur = cur->next;
	}

	//close the file
	fclose(dir);
	
        //
	cur = &book1;
	while (cur != NULL){
	    printf("%s\n", cur->booklist.title);
	    cur = cur->next;
	}
	int  r = search(choice, book1);
	printf("%d\n", r);
	return 0;
    	
    }
}
