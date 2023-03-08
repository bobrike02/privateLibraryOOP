#include <iostream>
#include <cassert>
#include "book.h"

using namespace std;

int main() {
    // Создаем автора и добавляем его в список авторов
    Author author1("William", "Shakespeare");
    vector<Author> authors = {author1};

    // Создаем бумажную книгу
    PBook pBook("Hamlet", authors, 350, 8);

    // Проверяем корректность создания книги
    assert(pBook.getName() == "Hamlet");
    assert(pBook.getPages() == 350);
    assert(pBook.getCondition() == 8);

    // Выводим название книги
    cout << "Book name: " << pBook.getName() << endl;

    // Выводим число страниц и состояние книги
    cout << "Book pages: " << pBook.getPages() << endl;
    cout << "Book condition: " << pBook.getCondition() << endl;

    // Выводим и проверяем авторов книги
    cout << "Book authors: ";
    for (auto &author: pBook.getAuthors()) {
        cout << author.getName() << " " << author.getSurname() << endl;
        assert(author.getName() == authors.front().getName());
        assert(author.getSurname() == authors.front().getSurname());
    }

    // Добавляем даты прочтения книги и проверяем, что они корректно добавились
    pBook.addReadingDate(30);
    assert(pBook.getReadingDates()[0] == 30);
    pBook.addReadingDate(35);
    assert(pBook.getReadingDates()[1] == 35);
    pBook.addReadingDate(40);
    assert(pBook.getReadingDates()[2] == 40);

    // Выводим даты прочтения книги
    bool first = true;
    cout << "Reading dates: ";
    for (auto &date: pBook.getReadingDates()) {
        if (first){
            first = false;
        } else {
            cout << ", ";
        }
        cout << date;
    }
    cout << endl;

    // Меняем, проверяем и выводим состояние книги
    pBook.setCondition(7);
    assert(pBook.getCondition() == 7);
    cout << "New book condition: " << pBook.getCondition() << endl;

    // Выставляем оценку (сначала невалидную, потом валидную) и выводим ее
    assert(!pBook.setRating(11));
    pBook.setRating(9);
    assert(pBook.getRating() == 9);
    cout << "Book rating: " << pBook.getRating() << endl;

    // Пробуем поменять состояние книги на невалидное
    assert(!pBook.setCondition(11));

    // Создаем автора и добавляем его в список авторов
    Author author2("Lew", "Tolstoy");
    vector<Author> authors2 = {author2};

    // Создаем электронную книгу
    EBook eBook("War and Peace", authors2, "PDF", 2048);

    // Проверяем корректность создания книги
    assert(eBook.getName() == "War and Peace");
    assert(eBook.getFileType() == "PDF");
    assert(eBook.getFileSize() == 2048);

    // Выводим название, формат и размер книги
    cout << "EBook name: " << eBook.getName() << endl;
    cout << "EBook format: " << eBook.getFileType() << endl;
    cout << "EBook size: " << eBook.getFileSize() << endl;

    // Выводим и проверяем авторов книги
    cout << "EBook authors: ";
    for (auto &author: eBook.getAuthors()) {
        cout << author.getName() << " " << author.getSurname() << endl;
        assert(author.getName() == authors2.front().getName());
        assert(author.getSurname() == authors2.front().getSurname());
    }

    // Добавляем даты прочтения книги и проверяем, что они корректно добавились
    eBook.addReadingDate(30);
    assert(eBook.getReadingDates()[0] == 30);
    eBook.addReadingDate(35);
    assert(eBook.getReadingDates()[1] == 35);
    eBook.addReadingDate(40);
    assert(eBook.getReadingDates()[2] == 40);

    // Выводим даты прочтения книги
    first = true;
    cout << "Reading dates: ";
    for (auto &date: eBook.getReadingDates()) {
        if (first){
            first = false;
        } else {
            cout << ", ";
        }
            cout << date;
    }
    cout << endl;

    // Сравниваем книги по названию
    if (pBook < eBook) {
        cout << pBook.getName() << " is less than " << eBook.getName() << endl;
    } else if (pBook == eBook) {
        cout << pBook.getName() << " is equal to " << eBook.getName() << endl;
        assert(false);
    } else {
        cout << pBook.getName() << " is greater than " << eBook.getName() << endl;
        assert(false);
    }
    return 0;
}