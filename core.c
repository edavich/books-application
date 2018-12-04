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
#include "usershelf.h"


//Search through library of books  by title
//c = user's choice


Library* search(const char c, Library * cur){
    Library * result = (Library *)malloc(sizeof(Library));
    if (cur == NULL) return NULL;
    if (c == 'T'){
        char name[100];
        printf("Enter title:   ");
        scanf("%s", name); 
    	while(cur != NULL){
            if (strstr(cur->booklist.title, name)!=NULL){
                strcpy(result->booklist.title, cur->booklist.title);
		result->next = NULL;
		return result;
            }
            cur = cur->next;
    	}
    }
        //Search through library of books by author 
    else if (c=='A'){
        char name[100];
        printf("Enter author:   ");
        scanf("%s", name);
        while(cur !=  NULL){
            if (strstr(cur->booklist.author.author,name)!= NULL){
	        strcpy(result->booklist.title, cur->booklist.title);
		result->next = NULL;
		return result;
            }
	    cur = cur->next;
        }
    }
     else if (c=='D'){
        char name[100];
        printf("Enter publication date:   ");
        scanf("%s", name);
        int date = atoi(name);
	printf("%d\n", date);
        while(cur != NULL){
            if (cur->booklist.date == date){
                strcpy(result->booklist.title, cur->booklist.title);
		result->next = NULL;
		return result;
            }
	    cur = cur->next;
        }
    }
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
    Shelf * shelf = malloc(sizeof(Shelf));
    shelf->total = 0;

    char choice;
    int resultNotFound = 1;
    //Allows user to search through the library until they make a selection.
    while(resultNotFound){
      printf("How would you like to search the library?");
      printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
      scanf(" %c", &choice);
 

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
	    token = strtok(NULL, ", ");
	    char filename[35];
	    strcat(filename, token);
	    strcat(filename, "\0");
            strcpy(curLib->booklist.filename, filename);
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
	    printf("Sorry, no books were found.\n\n");
	}
	//close the file
	fclose(dir);
	/*
        while(curLib != NULL){
	    printf("%s %s %d %s\n", curLib->booklist.title, curLib->booklist.author.author, curLib->booklist.date, curLib->booklist.filename);
	    curLib = curLib->next;
	
	}*/

    }
    
 
    char selectedTitle[50];
    printf("\nSelect a title to read:   ");
    scanf("%s", selectedTitle);
     
    Book selectedBook;
    curLib = lib;
    while(curLib != NULL){
        if (strstr(curLib->booklist.title, selectedTitle) != NULL){
	    selectedBook = curLib->booklist;
	}
	curLib = curLib->next;
    }

    char favorite[50];
    printf("Would you like to add this book to your favorites shelf (Y/N)?   ");
    scanf("%s", favorite);
    if(* favorite == 'Y'){
        add_to_shelf(shelf, shelf->total, selectedBook);
	printf("Book added\n\n");
    }
    printf("Would you like to view your favorites shelf (Y/N)?   ");
    scanf("%s", favorite);
    if(* favorite == 'Y'){
        print_shelf(shelf);
	printf("Continue(C):   ");
	char wait;
	scanf(" %c", &wait);
    }


    char path[70] = "\0";
    char* first = "Books/\0";
    strcat(path, first);
    //printf("%lu", strlen(selectedBook.filename));
    strcat(path, selectedBook.filename);
    //strcat(path, "\0"); 
    printf("\n\n\nBook Title: <%s>\n", path);
    FILE *fp;
    fp = fopen("Books/Dracula.txt", "r");
    char nav = 'N';
    char ch;
    while(nav == 'N'){
	read_book(&fp, &selectedBook);
	printf("\nTo navigate select Next(N) or Exit(E):   ");
        scanf(" %c", &ch);
	nav = ch;
	if (nav == 'E'){
	    printf("\n\n\t\tThank you for choosing Books! \n");
	}
    }
    fclose(fp);
    //printf("%s\n", loadedBook->content.pages[0]);


    return 0;
}


