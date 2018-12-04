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



Book* read_book(FILE **fp, Book* book){
//    char key[54] = "To navigate type Next(N), or Exit(E):   ";
        if (*fp == NULL) return NULL;
    	char buf[1024];
        int count = 0;
        Content * content = malloc(sizeof(Content));

	if(fgets(buf, 1024,*fp)!= NULL){
	    char page[20000] = "\0";
	    strcpy(page, buf);
            for (int i = 0; i < 40; i++){
	    	if (fgets(buf,1024,*fp)!= NULL){
		    strcat(page, buf);
		}
		else {
		    break;
		}
	    }
            printf("%s\n\n", page);
            //strcpy(content->pages[count], page);
	    count++;
	    
        }   
	//book->content = *content;
  return book;
   //for a given book title - loop through the content struct
   //File I/O read in text file
   //return 40 lines of content at a time to be printed in main 

}


