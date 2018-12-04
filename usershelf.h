//
// usershelf.h
// 308 Final Project
//
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#ifndef usershelf_h
#define usershelf_h

#include "book.h"

typedef struct Shelf {
    struct Book favorites[25];
    int total;
} Shelf;

int add_to_shelf(Shelf * shelf, int tot, Book book);

int print_shelf(Shelf * shelf);

#endif /* usershelf.h */


