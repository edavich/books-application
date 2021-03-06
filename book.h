//
// book.h
// 308 Final Project
//
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#ifndef book_h
#define book_h

typedef struct Content{
    char *pages[1000];
} Content;

typedef struct Author{
    char author[50];
} Author;

typedef struct Book {
    char title[50];
    Author author;
    int date;
    Content content;
    char filename[50];
} Book;

Book* read_book(FILE** fp, Book *book);


#endif /* book.h */

