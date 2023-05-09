#ifndef PRIVATELIBRARY_LIBRARY_H
#define PRIVATELIBRARY_LIBRARY_H
#pragma once
#include <cstring>
#include "book.h"

/**
 * Перечисление типов операций с книгой
 */
enum OperationType {
    ADD_BOOK, // Добавление книги
    REMOVE_BOOK, // Удаление книги
    GRADE_BOOK, // Проставление оценки
    DEGRADE_CONDITION, // Ухудшение состояния бумажной книги
    ADD_READING_DATE // Добавление даты чтения
};

/**
 * Класс для выполнения операций с книгами
 */
class Library {
private:
    /**
     * Структура для хранения узла бинарного дерева
     */
    struct TreeNode {
        Book *book; // Указатель на книгу
        TreeNode *left; // Левый потомок
        TreeNode *right; // Правый потомок

        /**
         * Конструктор узла бинарного дерева
         * @param book Указатель на книгу
         */
        TreeNode(Book *book) : book(book), left(nullptr), right(nullptr) {}

        /**
         * Деструктор узла бинарного дерева
         */
        ~TreeNode() {}
    };

    /**
     * Класс для хранения операции над книгой
     */
    class BookOperation {
    private:
        struct ValueHolder {
            short int oldValue; // Старое значение
            short int newValue; // Новое значение
        };
        OperationType type; // Тип операции
        Book *book; // Указатель на книгу
        Library *library; // Указатель на библиотеку
        ValueHolder holder; // Хранилище значений
    public:
        /**
         * Выполнение операции над книгой
         */
        void perform();

        /**
         * Отмена операции над книгой
         */
        void undo();

        /**
         * Конструктор операции добавления/удаления книги
         * @param type Тип операции
         * @param book Указатель на книгу
         * @param library Указатель на библиотеку
         */
        BookOperation(OperationType type, Book *book, Library *library);

        /**
         * Конструктор операции проставления оценки/ухудшения состояния/добавления даты чтения книги
         * @param type Тип операции
         * @param book Указатель на книгу
         * @param library Указатель на библиотеку
         * @param value Новое значение
         */
        BookOperation(OperationType type, Book *book, Library *library, int value);
    };

    std::vector<BookOperation> operations; // Вектор операций над книгой

    /**
     * Поиск книги в бинарном дереве по названию
     * @param node Указатель на узел дерева
     * @param name Название книги
     * @return Указатель на узел дерева, содержащий книгу с заданным названием
     */
    TreeNode *&findBook(TreeNode *&node, const std::string &name);

    /**
     * Очистка бинарного дерева
     * @param node Указатель на узел дерева
     */
    void clear(TreeNode *&node);

    /**
     * Удаление книги из бинарного дерева
     * @param node Указатель на узел дерева
     * @param name Название книги
     */
    void remove(TreeNode *&node, const std::string &name);

    /**
     * Добавление книги в бинарное дерево
     * @param node Указатель на узел дерева
     * @param book Указатель на книгу
     */
    void insert(TreeNode *&node, Book *book);

    /**
     * Выполнение операции над книгой
     * @param operation Операция над книгой
     */
    void performOperation(BookOperation operation);

    /**
     * Получение списка книг
     * @param node Указатель на узел дерева
     * @param result Вектор для хранения списка книг
     */
    void getBooksList(TreeNode *node, std::vector<Book *> &result);

    TreeNode *root; // Указатель на корень дерева
public:
    /**
     * Конструктор класса Library
     */
    Library();

    /**
     * Деструктор класса Library
     */
    ~Library();

    /**
     * Добавление книги в библиотеку
     * @param book Ссылка на книгу
     */
    void addBook(Book *book);

    /**
     * Удаление книги из библиотеки
     * @param name Название книги
     */
    void removeBook(const std::string &name);

    /**
     * Проставление оценки книге
     * @param name Название книги
     * @param rating Оценка книги
     */
    void setRating(const std::string &name, const short int &rating);

    /**
     * Ухудшение состояния бумажной книги
     * @param name Название книги
     * @param condition Состояние книги
     */
    void setCondition(const std::string &name, const short int &condition);

    /**
     * Добавление даты чтения книги
     * @param name Название книги
     * @param date Дата чтения книги
     */
    void addReadingDate(const std::string &name, int date);

    /**
     * Получение списка книг с сортировкой по названию в порядке возрастания
     * @return Список книг в порядке возрастания
     */
    std::string getBooksListSortedByNameAscending();

    /**
     * Получение списка книг с сортировкой по оценке в порядке убывания
     * @return Список книг в порядке убывания
     */
    std::string getBooksListSortedByRatingDescending();

    /**
     * Отмена последней операции
     */
    void undo();

};
#endif //PRIVATELIBRARY_LIBRARY_H

