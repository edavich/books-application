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
/*
int count = 0;
int rCount = 0;

int search(const char c, Library * all){
    int r = 0;
    if (all->booklist[count].title == NULL) return -1;
    if (c == 'T'){
    	char name[100];
    	printf("Enter title:   ");
        scanf("%s", name);
	printf("name is: %s\n", name);
	for(int i = 0; i < 10; i++){
	    printf("%s", all->booklist[i].title);
	    printf("%d\n", i);
	    if (all->booklist[i].title == name){
	        r= count + 1;
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
	        r = count + 1;
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
	        r = count +1;
		rCount++;
	    }
	    count++;
	}
    }
    else if (c=='L'){
        r = -1;
    }
    else{
    	return -1;
    }
    return r;	
}
*/
//Appearance of books application
int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");
     
    int noResult = 1;
    while (noResult){
        printf("How would you like to search the library?");
    	printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
    	char choice = getchar();

    	FILE *dir;
    	char buf[250];
    	dir = fopen("booksdirectory.txt", "r");
	if (dir == NULL){
	    printf("Bad file");
	    continue;
	}
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

	Library * cur = &book1;
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
	//cur.next = NULL;
	fclose(dir);
	
	cur = &book1;
	while (cur != NULL){
	    printf("%s\n", cur->booklist.title);
	    cur = cur->next;
	}
/*	int  r = search(choice, book1);
	printf("%d\n", r);
	return 0;
    	//if (result->booklist == NULL) printf("Sorry, we could not find a book. Please try again!");
*    	if(place == 0) {
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
