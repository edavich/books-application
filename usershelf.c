//
// usershelf.c
// 308 Final Project
//
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#include <stdlib.h>
#include <string.h>

#include "usershelf.h"


int add_to_shelf (Shelf * shelf, int tot, Book bookToAdd){
    shelf->favorites[tot] = bookToAdd;
    shelf->total = shelf->total + 1;
    if (shelf->total == tot+1){
        return 1;
    }
    else {
        return 0;
    }
}

int print_shelf (Shelf * shelf){
    printf("\tYour Shelf:\n");
    for (int i = 0; i < shelf->total; i++){
        printf("\t\t%s\n", shelf->favorites[i].title);
    }
    printf("\n");
    return 1;
}



