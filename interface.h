/**
 * Заголовочный файл, содержащий интерфейс для работы с библиотекой
 */

#ifndef PRIVATELIBRARY_INTERFACE_H
#define PRIVATELIBRARY_INTERFACE_H

#include "library.h"

extern "C" {
    /**
     * Создает новый объект класса Library
     * 
     * @return Указатель на созданный объект класса Library
     */
    Library *Library_new();
    
    /**
     * Добавляет электронную книгу в библиотеку
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     * @param author Автор книги
     * @param filetype Тип файла
     * @param filesize Размер файла
     */
    void Library_addEBook(Library *library,  char *name,  char *author,  char *filetype, long filesize);
    
    /**
     * Добавляет печатную книгу в библиотеку
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     * @param author Автор книги
     * @param pages Количество страниц
     * @param condition Состояние книги
     */
    void Library_addPBook(Library *library,  char *name,  char *author, int pages, short condition);
    
    /**
     * Удаляет книгу из библиотеки
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     */
    void Library_removeBook(Library *library,  char *name);
    
    /**
     * Устанавливает рейтинг книги
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     * @param rating Рейтинг книги
     */
    void Library_setRating(Library *library,  char *name, short int rating);
    
    /**
     * Устанавливает состояние книги
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     * @param condition Состояние книги
     */
    void Library_setCondition(Library *library,  char *name, short int condition);
    
    /**
     * Добавляет дату чтения книги
     * 
     * @param library Указатель на объект класса Library
     * @param name Название книги
     * @param date Дата чтения книги
     */
    void Library_addReadingDate(Library *library,  char *name, short int date);
    
    /**
     * Получает список книг, отсортированных по названию в алфавитном порядке
     * 
     * @param library Указатель на объект класса Library
     * @param list Список книг
     * @param max_list_len Максимальная длина списка
     */
    void Library_getBooksListSortedByNameAscending(Library *library, char* list, int max_list_len);
    
    /**
     * Получает список книг, отсортированных по рейтингу в порядке убывания
     * 
     * @param library Указатель на объект класса Library
     * @param list Список книг
     * @param max_list_len Максимальная длина списка
     */
    void Library_getBooksListSortedByRatingDescending(Library *library, char* list, int max_list_len);
    
    /**
     * Отменяет последнее действие в библиотеке
     * 
     * @param library Указатель на объект класса Library
     */
    void Library_undo(Library *library);
}
#endif //PRIVATELIBRARY_INTERFACE_H