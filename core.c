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


//Search through library of books  by title
//c = user's choice

int count = 0;
int rCount = 0;
Library* search(const char c, Library * cur){
    int r = 0;
    Library * result = (Library *)malloc(sizeof(Library));
    if (cur == NULL) return NULL;
    if (c == 'T'){
        char name[100];
        printf("Enter title:   ");
        scanf("%s", name);
    	printf("name is: %s\n", name);
    	while(cur != NULL){
            if (strcmp(cur->booklist.title, name)){
                strcpy(result->booklist.title, name);
		result->next = NULL;
		return result;
            }
            cur = cur->next;
    	}
    }
/*    else if (c=='D'){
        char name[100];
        printf("Enter publication date:   ");
        scanf("%s", name);
        int date = atoi(name);
        while(cur != NULL){
            if (cur->booklist.date == date){
                result->booklist.date = date;
		result->next = NULL;
		return result;
            }
	    cur = cur->next;
        }
    }
    */
    else if (c=='L'){
        return cur;
    }
    else{
        return NULL;
    }  
}



int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");
    
    //start of linkedlist
    Library * lib = NULL; 
    //current point in linkedlist
    Library * curLib = NULL;

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
            
	    Library * newLib = (Library *)malloc(sizeof(Library));
	    if (newLib == NULL){
	        printf("Failure");
		return 0;
	    }
	    if(curLib == NULL){
	       curLib = newLib;
               lib = newLib;
            }
            else {
               curLib->next = newLib;
	       curLib = curLib->next;
            }
            
           // printf("%s", buf);
	    
            //tokenize string
	    char* token = strtok(buf, ",");
	    int i = atoi(token);
	    i = i-1;
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.title, token);
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.author.author, token);
	    token = strtok(NULL, ",");
	    int num = atoi(token);
	    curLib ->booklist.date = num;
	    token = strtok(NULL, ",");
            strcpy(curLib->booklist.filename, token);
	}
	curLib->next = NULL;
	curLib = lib;
        Library* result = search(choice, curLib);
	if (result != NULL) {
	    printf("\n\tBooks found: \n");
	    while(result != NULL){
	        printf("\t\t%s\n", result->booklist.title);
		result = result->next;
	    }
            resultNotFound = 0;
	}
	else{
	    printf("Sorry, no books were found.");
	}
	//close the file
	fclose(dir);
	/*
        while(curLib != NULL){
	    printf("%s %s %d %s\n", curLib->booklist.title, curLib->booklist.author.author, curLib->booklist.date, curLib->booklist.filename);
	    curLib = curLib->next;
	
	}*/

    }
    
    char favorite[50];
    printf("Would you like to add a book to your favorites shelf (Y/N)? ");
    scanf("%s", favorite);
    if(* favorite == 'Y'){
      printf("call add to shelf");
    }
 
    char selectedTitle[50];
    printf("\nSelect a title to read:   ");
    scanf("%s", selectedTitle);
     
    Book selectedBook;
    curLib = lib;
    while(curLib != NULL){
        if (strcmp(curLib->booklist.title, selectedTitle) == 0){
	    selectedBook = curLib->booklist;
	}
	curLib = curLib->next;
    }
<<<<<<< HEAD
     
    
=======
    printf("\n\n\nBook Title: %s", selectedBook.title);

    read_book(&selectedBook, selectedBook.filename);
    //printf("%s\n", loadedBook->content.pages[0]);
>>>>>>> cf8550f8e1f139cd8ccb848f774822831b162d04



    return 0;
}
