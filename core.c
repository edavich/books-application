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

Library search(const char c){
    Library result;
    
    if (c
}

int core_main(int argc, const char * argv[]) {
    printf("%s", "\n\n\t\tWELCOME TO BOOKS\n\n");
    printf("How would you like to search the library?");
    printf("\nTitle(T), Author(A), Date(D), List All (L):   ");
    char choice = getchar();
    printf("\nYour choice is %c", choice);

    FILE *dir;
    char buf[1000];
    dir = fopen("bookdirectory.txt", "r");
    if (dir){
    	while(fgets(buf,1000,dir) != NULL){
	    
	}
    }




    printf("%s", "\n\n\n");
    return 0;
}
