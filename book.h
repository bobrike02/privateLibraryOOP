#include <string>
#include <vector>
#ifndef PRIVATELIBRARY_BOOK_H
#define PRIVATELIBRARY_BOOK_H



/**
 * Базовый класс книги.
 *
 * Хранит информацию о названии книги, ее авторах, оценке, датах чтения,
 * а также предоставляет методы для работы с этой информацией.
 */
class Book {
private:
    std::string name;  // название книги
    std::string authors;  // автор книги
    std::vector<int> readingDates;  // даты чтения книги (в виде чисел дней)
    short int rating;  // оценка книги по десятибалльной шкале
public:
    /**
     * Конструктор класса Book.
     *
     * @param name Название книги.
     * @param authors Список авторов книги.
     */
    Book(const std::string &name, const std::string&authors) : name(name), authors(authors), rating(0) {}

    /**
     * Получить оценку книги.
     *
     * @return Оценка книги.
     */
    short int getRating() const {
        return rating;
    }


    /**
     * Установить оценку книге.
     *
     * @param newRating Новая оценка книги.
     * @return true, если оценка установлена успешно, false - в противном случае.
     */
    bool setRating(const short int &newRating);

    /**
     * Добавить дату чтения книги.
     *
     * @param readingDate Дата чтения книги в виде числа дней.
     */
    void addReadingDate(const int &readingDate) {
        readingDates.push_back(readingDate);
    }

    /**
     * Получить список дат чтения книги.
     *
     * @return Список дат чтения книги в виде чисел дней.
     */
    std::vector<int>& getReadingDates()  {
        return readingDates;
    }

    /**
     * Деструктор класса Book
     */
    virtual ~Book() {}

    /**
     * Оператор сравнения меньше (less than) для книг.
     * Определяется как сравнение названий книг.
     *
     * @param other Другая книга, с которой сравниваем.
     * @return true, если название данной книги лексикографически меньше, чем название другой книги.
     */
    bool operator<(const Book &other);

    /**
    * Оператор сравнения равенства для книг.
    * Определяется как сравнение названий книг.
    *
    * @param other Другая книга, с которой сравниваем.
    * @return true, если название данной книги равно названию другой книги.
    */
    bool operator==(const Book &other);

    /**
     * Получить название книги.
     *
     * @return Название книги.
     */
    const std::string getName() const {
        return name;
    }

    /**
     * Получить вектор авторов книги.
     *
     * @return Вектор авторов книги.
     */
    const std::string& getAuthors() const {
        return authors;
    }
};

class EBook : public Book {
private:
    std::string fileType;  // Название формата книги
    long fileSize;  // Объём файла книги
public:
    /**
     * Конструктор класса EBook.
     *
     * @param name Название книги.
     * @param authors Список авторов книги.
     * @param fileType Название формата книги.
     * @param fileSize Объём файла книги.
     */
    EBook(const std::string &name, const std::string&authors, const std::string &fileType,
          const long &fileSize) : Book(name, authors),
                                  fileType(fileType),
                                  fileSize(fileSize) {}

    /**
     * Получить название формата книги.
     *
     * @return Название формата книги.
     */
    std::string getFileType() const {
        return fileType;
    }

    /**
     * Получить объём файла книги.
     *
     * @return Объём файла книги.
     */
    long getFileSize() const {
        return fileSize;
    }
};

class PBook : public Book {
private:
    int pages;  // Количество страниц книги
    short int condition;  // Состояние книги по десятибалльной шкале
public:
    /**
     * Конструктор класса PBook.
     *
     * @param name Название книги.
     * @param authors Список авторов книги.
     * @param pages Количество страниц книги.
     * @param condition Состояние книги по десятибалльной шкале.
     */
    PBook(const std::string &name, const std::string &author, const int &pages, const short int &condition) :
            Book(name, author), pages(pages), condition(condition) {}

    /**
     * Получить количество страниц книги.
     *
     * @return Количество страниц книги.
     */
    int getPages() const {
        return pages;
    }

    /**
     * Получить состояние книги.
     *
     * @return Состояние книги по десятибалльной шкале.
     */
    short int getCondition() const {
        return condition;
    }

    /**
     * Установить состояние книги.
     *
     * @param newCondition Новое состояние книги по десятибалльной шкале.
     * @return true, если состояние установлено успешно, false - в противном случае.
     */
    bool setCondition(const short int &newCondition);
};
#endif //PRIVATELIBRARY_BOOK_H