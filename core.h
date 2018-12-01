//
// core.h
// 308 Final Project
// 
// Created by Emily Davich and Vivian Weaver
// Copyright 2018
//

#ifndef core_h
#define core_h
#include "book.h"

typedef struct Library{
    Book listBook[100];
} Library;

Library search(const char c);

int core_main(int argc, const char * argv[]);

#endif /* core_h */
