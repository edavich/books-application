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

//Search through library of books  by title


//c = user's choice

int count = 0;
int rCount = 0;

Library * search(const char c, Library * all){
    Library *result;
    if (all->booklist[count].title == NULL) return NULL;
    if (c == 'T'){
    	char name[100];
    	printf("Enter title:   ");
        scanf("%s", name);
	while(all->booklist[count].title != NULL){
	    if (all->booklist[count].title == name){
	        result->booklist[rCount] = all->booklist[count];
		rCount++;
	    }
	    count++;
	}
    }
    
    //Search through library of books by author 
    else if (c=='A'){
        char name[100];
    	printf("Enter author:   ");
        scanf("%s", name);
	while(all->booklist[count].author.author != NULL){
	    if (all->booklist[count].author.author == name){
	        result->booklist[rCount] = all->booklist[count];
		rCount++;
	    }
	    count++;
	}
    }
 
    //Search through library of books by date
    else if (c=='D'){
        char name[100];
    	printf("Enter publication date:   ");
        scanf("%s", name);
	int date = atoi(name);
	while(!all->booklist[count].date){
	    if (all->booklist[count].date == date){
	        result->booklist[rCount] = all->booklist[count];
		rCount++;
	    }
	    count++;
	}
    }
    else if (c=='L'){
        result->booklist == all->booklist;
    }
    else{
    	return NULL;
    }
    return result;	
}

//Appearance of books application
int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");
     
    int noResult = 1;
    while (noResult){
        printf("How would you like to search the library?");
    	printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
    	char choice = getchar();
    	
    	Library * booklist;
    	FILE *dir;
    	char buf[1000];
    	dir = fopen("bookdirectory.txt", "r");
    	if (dir){
    	    while(fgets(buf,1000,dir) != NULL){
	   	char* token = strtok(buf, ", ");
	   	int i = atoi(token);
	   	token = strtok(NULL, ", ");
           	strcpy(booklist->booklist[i].title, token + '\0');
	   	token = strtok(NULL, ", ");
           	strcpy(booklist->booklist[i].author.author, token + '\0');
	   	token = strtok(NULL, ", ");
	   	booklist->booklist[i].date = atoi(token);
	   	token = strtok(NULL, ", ");
           	strcpy(booklist->booklist[i].filename, token + '\0');
	    }
	}
    	Library *result = search(choice, booklist);
    	if (result->booklist == NULL) printf("Sorry, we could not find a book. Please try again!");
    	else {
	    noResult = 0;
            count = 0;
	    printf("We found the following books:  \n\n ");
	    while (result->booklist[count].title != NULL){
	        printf("\t%s", result->booklist[count].title);
	    }
        }
    }

    printf("%s", "\n\n\n");
    return 0;
}
