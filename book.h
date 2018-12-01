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
   char *author;
}

typedef struct Book {
    char *title;
    Author author;
    int date;
    Content content;
} Book;



#endif /* book.h */
