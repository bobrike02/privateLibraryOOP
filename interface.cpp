#include "interface.h"

Library *Library_new() {
    return new Library();
}

void Library_addEBook(Library *library, char *name, char *author, char *filetype, long filesize) {
    EBook *eBook = new EBook(name, author, filetype, filesize);
    library->addBook(eBook);
}

void Library_addPBook(Library *library, char *name, char *author, int pages, short condition) {
    PBook *pBook = new PBook(name, author, pages, condition);
    library->addBook(pBook);
}


void Library_removeBook(Library *library, char *name) {
    library->removeBook(name);
}

void Library_setRating(Library *library, char *name, short rating) {
    library->setRating(name, rating);
}

void Library_setCondition(Library *library, char *name, short condition) {
    library->setCondition(name, condition);
}

void Library_addReadingDate(Library *library, char *name, short date) {
    library->addReadingDate(name, date);
}

void Library_getBooksListSortedByNameAscending(Library *library, char *list, int max_list_len) {
    strncpy(list, library->getBooksListSortedByNameAscending().c_str(), max_list_len);
}

void Library_getBooksListSortedByRatingDescending(Library *library, char *list, int max_list_len) {
    strncpy(list, library->getBooksListSortedByRatingDescending().c_str(), max_list_len);
}

void Library_undo(Library *library) {
    library->undo();
}
