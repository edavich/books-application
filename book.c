//
// book.c
// 308 Final Project
// 
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "book.h"

<<<<<<< HEAD
/*
=======

>>>>>>> fe514760f1482ff863179ff87b3ad4be6f79cf2e
Book* read_book(Book* book){
    char key[54] = "To navigate type Previous(P), Next(N), or Exit(E):   ";
    FILE *fp;
    	char buf[500];
    	fp = fopen("booksdirectory.txt", "r");
	if (fp == NULL){
	    printf("Bad file");
	    return book;
	}
        int count = 0;
        Content content;

	while(fgets(buf, 500, fp)!= NULL){
	    char page[20000];
	    strcpy(page, buf);
            for (int i = 0; i < 40; i++){
	    	if (fgets(buf,500,fp)!= NULL){
		    strcat(page, buf);
		}
		else {
		    break;
		}
	    }
            strcpy(content.pages[count], page);
	    count++;
        }   
	book->content = content;
	fclose(fp);
   return book;
   //for a given book title - loop through the content struct
   //File I/O read in text file
   //return 40 lines of content at a time to be printed in main 

}
<<<<<<< HEAD
*/
=======



>>>>>>> fe514760f1482ff863179ff87b3ad4be6f79cf2e
