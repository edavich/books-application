//
// book.h
// 308 Final Project
// 
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#ifndef book_h
#define book_h

typedef struct Book {
    char title[100];
    Author author;
    int date;
    Content content;
    char filename[50];
} Book;

typedef struct Content{
    const char *pages[1000];
} Content;

typedef struct Author{
    char author[50];
} 

#endif /* book.h */
