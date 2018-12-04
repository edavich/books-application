//  library.h  
//
//

#ifndef library_h
#define library_h

typedef struct Library{
    Book booklist;
    struct Library * next;
} Library;


#endif /* library_h */
