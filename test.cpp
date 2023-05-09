#include <iostream>
#include <cassert>
#include "library.h"

int main() {
    // Тесты книг
    
    // Создаем бумажную книгу
    PBook pBook("Hamlet", "William Shakespeare", 350, 8);

    // Проверяем корректность создания книги
    assert(pBook.getName() == "Hamlet");
    assert(pBook.getAuthors() == "William Shakespeare");
    assert(pBook.getPages() == 350);
    assert(pBook.getCondition() == 8);

    // Добавляем даты прочтения книги и Проверяем, что они корректно добавились
    pBook.addReadingDate(30);
    assert(pBook.getReadingDates()[0] == 30);
    pBook.addReadingDate(35);
    assert(pBook.getReadingDates()[1] == 35);
    pBook.addReadingDate(40);
    assert(pBook.getReadingDates()[2] == 40);

    // Меняем, Проверяем и выводим состояние книги
    pBook.setCondition(7);
    assert(pBook.getCondition() == 7);

    // Выставляем оценку (сначала невалидную, потом валидную) и выводим ее
    assert(!pBook.setRating(11));
    pBook.setRating(9);
    assert(pBook.getRating() == 9);

    // Пробуем поменять состояние книги на невалидное
    assert(!pBook.setCondition(11));

    // Создаем электронную книгу
    EBook eBook("War and Peace", "Lew Tolstoy", "PDF", 2048);

    // Проверяем корректность создания книги
    assert(eBook.getName() == "War and Peace");
    assert(eBook.getFileType() == "PDF");
    assert(eBook.getFileSize() == 2048);

    // Добавляем даты прочтения книги и Проверяем, что они корректно добавились
    eBook.addReadingDate(30);
    assert(eBook.getReadingDates()[0] == 30);
    eBook.addReadingDate(35);
    assert(eBook.getReadingDates()[1] == 35);
    eBook.addReadingDate(40);
    assert(eBook.getReadingDates()[2] == 40);


    // Сравниваем книги по названию
    if (pBook < eBook) {
    } else if (pBook == eBook) {
        assert(false);
    } else {
        assert(false);
    }

    std::cout<< "All book tests passed!" << std::endl;

    // Тесты библиотеки
    
    // Создаем библиотеку
    Library library;

    // Создаем несколько новых книг
    PBook book1("War and Peace", "Lew Tolstoy", 1225, 10);
    EBook book2("The Great Gatsby", "F. Scott Fitzgerald", "PDF", 231);
    PBook book3("The Catcher in the Rye", "J.D. Salinger", 224, 8);

    // Добавляем книги в библиотеку
    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);

    // Проверяем, что книги действительно добавлены в библиотеку и что сортированный вывод работает корректно
    assert((library.getBooksListSortedByNameAscending() == "The Catcher in the Rye\nThe Great Gatsby\nWar and Peace\n"));

    // Проставляем оценки книгам
    library.setRating("War and Peace", 9);
    library.setRating("The Great Gatsby", 7);

    // Проверяем, что оценки действительно проставлены
    assert(book1.getRating() == 9);
    assert(book2.getRating() == 7);
    // Проверяем, что вывод с сортировкой по оценками корректно работает
    assert(library.getBooksListSortedByRatingDescending() == "War and Peace 9\nThe Great Gatsby 7\nThe Catcher in the Rye 0\n");

    // Ухудшаем состояние бумажной книги
    library.setCondition("War and Peace", 8);

    // Проверяем, что состояние действительно ухудшилось
    assert(book1.getCondition() == 8);

    // добавляем даты чтения книг
    library.addReadingDate("War and Peace", 123);
    library.addReadingDate("War and Peace", 124);
    library.addReadingDate("The Catcher in the Rye", 125);

    // Проверяем, что даты чтения действительно добавлены
    std::vector<int> readingDates1 = book1.getReadingDates();
    std::vector<int> readingDates3 = book3.getReadingDates();
    assert(readingDates1.size() == 2);
    assert(readingDates1[0] == 123);
    assert(readingDates1[1] == 124);
    assert(readingDates3.size() == 1);
    assert(readingDates3[0] == 125);

    // Отменяем последнюю операцию - library.addReadingDate("The Catcher in the Rye", 125);
    library.undo();

    // Проверяем, что последняя операция отменена
    readingDates3 = book3.getReadingDates();
    assert(readingDates3.size() == 0);

    // Отменяем последнюю операцию - library.addReadingDate("War and Peace", 124);
    library.undo();

    // Проверяем, что последняя операция отменена
    readingDates1 = book1.getReadingDates();
    assert(readingDates1.size() == 1);

    // Отменяем последнюю операцию - library.addReadingDate("War and Peace", 123);
    library.undo();

    // Проверяем, что последняя операция отменена
    readingDates1 = book1.getReadingDates();
    assert(readingDates1.size() == 0);

    // Отменяем последнюю операцию - library.setCondition("War and Peace", 8);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert(book1.getCondition() == 10);

    // Отменяем последнюю операцию - library.setRating("The Great Gatsby", 7);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert(book2.getRating() == 0);

    // Отменяем последнюю операцию - library.setRating("War and Peace", 9);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert(book1.getRating() == 0);

    // Отменяем последнюю операцию - library.addBook(book3);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert((library.getBooksListSortedByNameAscending() == "The Great Gatsby\nWar and Peace\n"));

    // Отменяем последнюю операцию - library.addBook(book2);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert((library.getBooksListSortedByNameAscending() == "War and Peace\n"));

    // Отменяем последнюю операцию - library.addBook(book1);
    library.undo();

    // Проверяем, что последняя операция отменена
    assert((library.getBooksListSortedByNameAscending() == ""));

    // Добавляем книги снова в библиотеку
    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);

    // Удаляем книги из библиотеки и проверяем, что они удалились
    library.removeBook("The Great Gatsby");
    assert((library.getBooksListSortedByNameAscending() == "The Catcher in the Rye\nWar and Peace\n"));
    library.removeBook("The Catcher in the Rye");
    assert((library.getBooksListSortedByNameAscending() == "War and Peace\n"));
    library.removeBook("War and Peace");
    assert((library.getBooksListSortedByNameAscending() == ""));

    std::cout<< "All library tests passed!" << std::endl;
    return 0;
}
