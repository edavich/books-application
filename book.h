//
// book.h
// 308 Final Project
// 
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#ifndef book_h
#define book_h

typedef struct Content{
    const char *pages[1000];
} Content;

typedef struct Author{
    char author[250];
} Author;

typedef struct Book {
    char title[250];
    Author author;
    int date;
    Content content;
    char filename[250];
} Book;

typedef struct Library{
    Book booklist[100];
} Library;

#endif /* book.h */
