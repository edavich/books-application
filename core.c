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
        char name[50];
        printf("Enter title:   ");
        fgets(name,50,stdin); 
        name[strlen(name)-1] = '\0'; 
	while(cur != NULL){
	    //printf("%s,%s", cur->booklist.title, name);
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
        char name[50];
        printf("Enter author:   ");
        fgets(name,50,stdin);
	name[strlen(name)-1] = '\0';
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
        char name[10];
        printf("Enter publication date:   ");
        fgets(name, 10, stdin);
	name[strlen(name)-1] = '\0';
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

    char choice[5];
    int resultNotFound = 1;

    //Allows user to search through the library until they make a selection.
    while(resultNotFound){
      printf("How would you like to search the library?");
      printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
      fgets(choice,5,stdin);
 
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
	    token[strlen(token)-2] = '\0';
            strcpy(curLib->booklist.filename, token);
            printf("%s", curLib->booklist.filename);
	}
	curLib->next = NULL;
	curLib = lib;

        Library* result = search(*choice, curLib);
	if (result != NULL) {
	    printf("\n\tBooks found: \n");
	    while(result != NULL){
	        printf("\t\t%s\n", result->booklist.title);
		result = result->next;
	    }
            resultNotFound = 0;
	}
	else{
	    printf("\nSorry, no books were found.\n\n");
	}
	//close the file
	fclose(dir);
	/*
	curLib = lib;
        strcpy(curLib->booklist.filename, "Books/AliceInWonderland.txt");
	curLib = curLib->next;   
	strcpy(curLib->booklist.filename, "Books/Dracula.txt");
	curLib = curLib->next;    
	strcpy(curLib->booklist.filename, "Books/Grimm'sFairyTales.txt");
	curLib = curLib->next;    
	strcpy(curLib->booklist.filename, "Books/MobyDick.txt");
	curLib = curLib->next;     
	strcpy(curLib->booklist.filename, "Books/PrideAndPrejudice.txt");
*/
    }
    
    //printf("%s", curLib->booklist.filename);
 
    char selectedTitle[50];
    printf("\nSelect a title to read:   ");
    fgets(selectedTitle,50,stdin);
    selectedTitle[strlen(selectedTitle)-1] = '\0';
    
    Book selectedBook;
    curLib = lib;
    while(curLib != NULL){
        if (strstr(curLib->booklist.title, selectedTitle) != NULL){
	    //selectedBook = curLib->booklist;
            memcpy(&selectedBook, &(curLib->booklist), sizeof(Book));
            strcpy(selectedBook.filename, curLib->booklist.filename);
            //printf("%s", selectedBook.filename);
	}
	curLib = curLib->next;
    }
    
    //favorites/users shelf
    char favorite[50];
    printf("Would you like to add this book to your favorites shelf (Y/N)?   ");
    fgets(favorite,50,stdin);
    if(* favorite == 'Y'){
        add_to_shelf(shelf, shelf->total, selectedBook);
	printf("Book added\n\n");
    }
    printf("Would you like to view your favorites shelf (Y/N)?   ");
    strcpy(favorite, "\0");
    fgets(favorite,50,stdin);
    if(* favorite == 'Y'){
        print_shelf(shelf);
	printf("Continue(C):   ");
	char wait;
	scanf(" %c", &wait);
    }

    //print out the book
    
    char path[100];
    strcpy(path, "Books/");
    strcat(path, selectedBook.filename);
    //printf("%s", selectedBook.filename);
    //strcat(path, "\0"); 

    printf("\n\n\nBook Title: <%s>\n", path);
    FILE *fp;
    fp = fopen(path, "r");

    //navigate through book
    char nav = 'N';
    char ch;
    
    printf("\nTo navigate select Next(N) or Exit(E):   ");
    scanf(" %c", &ch);
    nav = ch;

	if (nav == 'E'){
	    printf("\n\n\t\tThank you for choosing Books! \n");
	    printf("\n");
	    return 0;
    }
    while(nav == 'N'){ 
	if (nav == 'E'){
	    printf("\n\n\t\tThank you for choosing Books! \n");
	    printf("\n");
	    break;
	}
	read_book(&fp, &selectedBook);

	printf("\nTo navigate select Next(N) or Exit(E):   ");
        scanf(" %c", &ch);
	nav = ch;
    }
    //fclose(fp);
    //printf("%s\n", loadedBook->content.pages[0]);

    return 0;
}


