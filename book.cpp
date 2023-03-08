#include "book.h"


bool PBook::setCondition(short newCondition) {
    if (newCondition >= 0 && newCondition <= 10) {
        condition = newCondition;
        return true;
    }
    return false;
}

bool Book::operator==(const Book other) {
    return name.compare(other.name) == 0;
}

bool Book::operator<(const Book other) {
    return name.compare(other.name) < 0;
}

bool Book::setRating(short newRating) {
    if (newRating >= 0 && newRating <= 10) {
        Book::rating = newRating;
        return true;
    }
    return false;
}
