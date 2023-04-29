#include <iostream>
#include <fstream>
#include "interface.h"

Library* Library_new() {
    return new Library();
}

void Library_addEBook(Library *library, char *name, char *author, char *filetype, short filesize) {
    EBook eBook(name, author, filetype, filesize);
    library->addBook(eBook);
}

void Library_addPBook(Library *library, char *name, char *author, short pages, short condition) {
    PBook pBook(name, author, pages, condition);
    library->addBook(pBook);
}

void Library_removeBook(Library *library, char *name) {
    library->removeBook(name);
}

void Library_setRating(Library *library, char *name, short int rating) {
    library->setRating(name, rating);
}

void Library_setCondition(Library *library, char *name, short int condition) {
    library->setCondition(name, condition);
}

void Library_addReadingDate(Library *library, char *name, short int date) {
    library->addReadingDate(name, date);
}

void Library_getBooksListSortedByNameAscending(Library *library, char* list, int max_list_len) {
    strncpy(list, library->getBooksListSortedByNameAscending().c_str(), max_list_len);
}

void Library_getBooksListSortedByRatingDescending(Library *library, char* list, int max_list_len) {
    strncpy(list, library->getBooksListSortedByNameAscending().c_str(), max_list_len);
}

void Library_undo(Library *library) {
    library->undo();
}
