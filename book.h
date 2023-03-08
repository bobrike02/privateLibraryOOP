#include <string>
#include <vector>

/**
 * Класс автора книги.
 *
 * Хранит информацию об имени и фамилии автора.
 */
class Author {
private:
    std::string name;
    std::string surname;
public:
    /**
     * Конструктор класса Author.
     *
     * @param name Имя автора.
     * @param surname Фамилия автора.
     */
    Author(std::string name, std::string surname) : name(name), surname(surname) {}

    /**
     * Получить имя автора.
     *
     * @return Имя автора.
     */
    std::string getName() const {
        return name;
    }

    /**
     * Получить фамилию автора.
     *
     * @return Фамилия автора.
     */
    std::string getSurname() const {
        return surname;
    }
};

/**
 * Базовый класс книги.
 *
 * Хранит информацию о названии книги, ее авторах, оценке, датах чтения,
 * а также предоставляет методы для работы с этой информацией.
 */
class Book {
private:
    std::string name;  // название книги
    std::vector <Author> authors;  // авторы книги
    std::vector<long> readingDates;  // даты чтения книги (в виде чисел дней)
    short int rating;  // оценка книги по десятибалльной шкале
public:
    /**
     * Конструктор класса Book.
     *
     * @param name Название книги.
     * @param authors Список авторов книги.
     */
    Book(std::string name, std::vector <Author> authors) : name(name), authors(authors), rating(0) {}

    /**
     * Получить оценку книги.
     *
     * @return Оценка книги.
     */
    short getRating() {
        return rating;
    }

    /**
     * Установить оценку книге.
     *
     * @param newRating Новая оценка книги.
     * @return true, если оценка установлена успешно, false - в противном случае.
     */
    bool setRating(short int newRating);

    /**
     * Добавить дату чтения книги.
     *
     * @param readingDate Дата чтения книги в виде числа дней.
     */
    void addReadingDate(long readingDate) {
        readingDates.push_back(readingDate);
    }

    /**
     * Получить список дат чтения книги.
     *
     * @return Список дат чтения книги в виде чисел дней.
     */
    std::vector<long> getReadingDates() {
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
    bool operator<(const Book other);

    /**
    * Оператор сравнения равенства для книг.
    * Определяется как сравнение названий книг.
    *
    * @param other Другая книга, с которой сравниваем.
    * @return true, если название данной книги равно названию другой книги.
    */
    bool operator==(const Book other);

    /**
     * Получить название книги.
     *
     * @return Название книги.
     */
    std::string getName() {
        return name;
    }

    /**
     * Получить вектор авторов книги.
     *
     * @return Вектор авторов книги.
     */
    std::vector <Author> getAuthors() {
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
    EBook(std::string name, std::vector <Author> authors, std::string fileType, long fileSize) : Book(name, authors),
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
    PBook(std::string name, std::vector <Author> authors, int pages, short int condition) : Book(name, authors), pages(pages),
                                                                              condition(condition) {}
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
    bool setCondition(short int newCondition);
};