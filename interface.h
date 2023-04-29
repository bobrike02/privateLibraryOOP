
#ifndef PRIVATELIBRARY_INTERFACE_H
#define PRIVATELIBRARY_INTERFACE_H

#include "library.h"

extern "C" {
    Library *Library_new();

    void Library_addEBook(Library *library,  char *name,  char *author,  char *filetype, short int filesize);

    void Library_addPBook(Library *library,  char *name,  char *author, short int pages, short int condition);

    void Library_removeBook(Library *library,  char *name);

    void Library_setRating(Library *library,  char *name, short int rating);

    void Library_setCondition(Library *library,  char *name, short int condition);

    void Library_addReadingDate(Library *library,  char *name, short int date);

    void Library_getBooksListSortedByNameAscending(Library *library, char* list, int max_list_len);

    void Library_getBooksListSortedByRatingDescending(Library *library, char* list, int max_list_len);

    void Library_undo(Library *library);
}
#endif //PRIVATELIBRARY_INTERFACE_H
