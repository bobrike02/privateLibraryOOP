#include <stack>
#include <stdexcept>
#include <algorithm>
#include "library.h"

Library::BookOperation::BookOperation(OperationType type, Book *book, Library *library, int value) : type(type),
                                                                                                     book(book),
                                                                                                     library(library) {
    if (type == GRADE_BOOK) {
        holder.oldValue = book->getRating();
        holder.newValue = value;
    } else if (type == DEGRADE_CONDITION) {
        if (PBook *pbook = dynamic_cast<PBook *>(book)) {
            holder.oldValue = pbook->getCondition();
            holder.newValue = value;
        } else {
            throw std::invalid_argument("incorrect type of book");
        }
    } else if (type == ADD_READING_DATE) {
        holder.newValue = value;
    } else {
        throw std::invalid_argument("incorrect type of operation");
    }
}

Library::BookOperation::BookOperation(OperationType type, Book *book, Library *library) : type(type), book(book),
                                                                                          library(library) {
    if (type == GRADE_BOOK || type == DEGRADE_CONDITION || type == ADD_READING_DATE) {
        throw std::invalid_argument("incorrect type of operation");
    }
}

void Library::BookOperation::perform() {
    switch (type) {
        case ADD_BOOK:
            library->insert(library->root, book);
            break;
        case REMOVE_BOOK:
            library->remove(library->root, book->getName());
            break;
        case GRADE_BOOK:
            book->setRating(holder.newValue);
            break;
        case DEGRADE_CONDITION:
            if (PBook *pbook = dynamic_cast<PBook *>(book)) {
                pbook->setCondition(holder.newValue);
            }
            break;
        case ADD_READING_DATE:
            book->addReadingDate(holder.newValue);
            break;
    }
}

void Library::BookOperation::undo() {
    if (!book)
        return;
    switch (type) {
        case ADD_BOOK:
            library->remove(library->root, book->getName());
            break;
        case REMOVE_BOOK:
            library->insert(library->root, book);
            break;
        case GRADE_BOOK:
            book->setRating(holder.oldValue);
            break;
        case DEGRADE_CONDITION:
            if (PBook *pbook = dynamic_cast<PBook *>(book)) {
                pbook->setCondition(holder.oldValue);
            }
            break;
        case ADD_READING_DATE:
            book->getReadingDates().pop_back();
            break;
    }
}

void Library::insert(Library::TreeNode *&node, Book *book) {
    if (!node) {
        node = new TreeNode(book);
    } else if (book->getName() < node->book->getName()) {
        insert(node->left, book);
    } else {
        insert(node->right, book);
    }
}

void Library::clear(Library::TreeNode *&node) {
    if (!node) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

void Library::addBook(Book &book) {
    BookOperation addOperation(OperationType::ADD_BOOK, &book, this);
    performOperation(addOperation);
}

void Library::removeBook(const std::string &name) {
    TreeNode *node = findBook(root, name);
    if (node) {
        BookOperation removeOperation(OperationType::REMOVE_BOOK, node->book, this);
        performOperation(removeOperation);
    }
}

void Library::setRating(const std::string &name, short rating) {
    TreeNode *node = findBook(root, name);
    if (node) {
        BookOperation gradeOperation(OperationType::GRADE_BOOK, node->book, this, rating);
        performOperation(gradeOperation);
    }
}

void Library::setCondition(const std::string &name, short condition) {
    TreeNode *node = findBook(root, name);
    if (node) {
        PBook *pbook = dynamic_cast<PBook *>(node->book);
        if (pbook) {
            BookOperation degradeOperation(OperationType::DEGRADE_CONDITION, pbook, this, condition);
            performOperation(degradeOperation);
        } else {
            throw std::invalid_argument("incorrect type of book");
        }
    }
}

Library::TreeNode *&Library::findBook(Library::TreeNode *&node, const std::string &name) {
    if (!node) {
        return node;
    }
    if (name == node->book->getName()) {
        return node;
    } else if (name < node->book->getName()) {
        return findBook(node->left, name);
    } else {
        return findBook(node->right, name);
    }
}


void Library::remove(Library::TreeNode *&node, const std::string &name) {
    if (!node) {
        return;
    }
    if (name < node->book->getName()) {
        remove(node->left, name);
    } else if (name > node->book->getName()) {
        remove(node->right, name);
    } else {
        if (node->left && node->right) {
            TreeNode *temp = node->right;
            while (temp->left) {
                temp = temp->left;
            }
            node->book = temp->book;
            remove(node->right, temp->book->getName());
        } else {
            TreeNode *temp = node;
            if (node->left) {
                node = node->left;
            } else {
                node = node->right;
            }
            delete temp;
        }
    }
}

void Library::undo() {
    if (operations.empty())
        return;
    operations.back().undo();
    operations.pop_back();
}

Library::Library() : root(nullptr) {}

Library::~Library() {
    clear(root);
}

void Library::performOperation(Library::BookOperation operation) {
    operations.push_back(operation);
    operation.perform();
}

void Library::addReadingDate(const std::string &name, int date) {
    TreeNode *node = findBook(root, name);
    if (node) {
        BookOperation addReadingDateOperation(OperationType::ADD_READING_DATE, node->book, this, date);
        performOperation(addReadingDateOperation);
    }
}

std::string Library::getBooksListSortedByNameAscending() {
    std::string result = "";
    std::vector<Book *> books;
    getBooksList(root, books);
    while (!books.empty()) {
        result += books.back()->getName() + "\n";
        books.pop_back();
    }
    return result;
}

std::string Library::getBooksListSortedByRatingDescending() {
    std::string result;
    std::vector<Book *> books;
    getBooksList(root, books);
    std::sort(books.begin(), books.end(), [](Book *a, Book *b) {
        return a->getRating() < b->getRating();
    });
    while (!books.empty()) {
        result += books.back()->getName() + +" " + std::to_string(books.back()->getRating()) + "\n";
        books.pop_back();
    }
    return result;
}

void Library::getBooksList(TreeNode *node, std::vector<Book *> &result) {
    if (node != nullptr) {
        getBooksList(node->right, result);
        result.push_back(node->book);
        getBooksList(node->left, result);
    }
}