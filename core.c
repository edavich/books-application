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
    Library *result = all;
    if (all->booklist[count].title == NULL) return NULL;
    if (c == 'T'){
    	char name[100];
    	printf("Enter title:   ");
        scanf("%s", name);
	return NULL;
	while(all->booklist[count].title != NULL){
	    if (all->booklist[count].title == name){
	        result->booklist[rCount] = all->booklist[count];
		rCount++;
	    }
	    count++;
	    printf("%s", all->booklist[count].title);
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
    	
    	Library * booklist = malloc(sizeof(Library));
    	FILE *dir;
    	char buf[250];
    	dir = fopen("booksdirectory.txt", "r");
	if (dir == NULL){
	    printf("Bad file");
	    continue;
	}
	int place;
	int date;
	char title[50];
	char author[50];
	char filename[50];
	while(fgets(buf, 250, dir)!= NULL){
	    char* token = strtok(buf, ",");
	    int i = atoi(token);
	    token = strtok(NULL, ",");
            strcpy(booklist->booklist[place].title, token);
	    // printf("%s\n", booklist->booklist[place].title);
	    token = strtok(NULL, ",");
            strcpy(booklist->booklist[place].author.author, token);
	    //printf("%s\n", booklist->booklist[place].author.author);
	    token = strtok(NULL, ",");
	    int num = atoi(token);
	    booklist->booklist[place].date = num;
	    //printf("%d\n", booklist->booklist[place].date);
	    token = strtok(NULL, ",");
            strcpy(booklist->booklist[place].filename, token);
	    //printf("%s\n", booklist->booklist[place].filename);
	}
	fclose(dir);	
        Library* result = search(choice, booklist);

	printf("yay!");
	return 0;
    	//if (result->booklist == NULL) printf("Sorry, we could not find a book. Please try again!");
/*    	if(place == 0) {
	    noResult = 0;
            count = 0;
	    printf("We found the following books:  \n\n ");
	    //while (result->booklist[count].title != NULL){
	        printf("\t%s", result->booklist[count].title);
	    }
        }
	free(booklist);
	free(result);
    }

    printf("%s", "\n\n\n");
    return 0;
    */
    }
}
