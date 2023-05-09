""" Консольный интерфейс для проекта личная библиотека"""
import ctypes

"""
1. Вывести список всех книг, отсортированный по названию
2. Вывести список всех книг, отсортированный по оценке
3. Добавить книгу в библиотеку
4. Удалить книгу из библиотеки
5. Поставить книге оценку
6. Отметить ухудшение состояния книги
7. Отменить последнюю операцию
8. Добавить дату прочтения
"""


def print_sorted_by_name():
    """  Функция вывода списка всех книг, отсортированного по названию """
    out = ctypes.create_string_buffer(100)
    print("Список всех книг, отсортированный по названию:")
    lib.Library_getBooksListSortedByNameAscending(library, out, ctypes.sizeof(out))
    print(out.value.decode('utf-8'))


def print_sorted_by_raiting():
    """  Функция вывода списка всех книг, отсортированного по оценке """
    out = ctypes.create_string_buffer(100)
    print("Список всех книг, отсортированный по оценке:")
    lib.Library_getBooksListSortedByRatingDescending(library, out, ctypes.sizeof(out))
    print(out.value.decode('utf-8'))


def add_book():
    """  Функция добавления книги в библиотеку """
    name = input("Введите название книги: ")
    author = input("Введите имя автора книги: ")
    is_ok = False
    while not is_ok:
        try:
            type_of_book = int(input("Выберите тип книги -- бумажная (1) или электронная (2): "))
            if not (type_of_book in {1, 2}):
                raise ValueError
            if type_of_book == 1:
                while True:
                    pages = input("Введите количество страниц в книге: ")
                    try:
                        pages = int(pages)
                        if pages > 0:
                            break
                        else:
                            print("Количество страниц в книге не может быть отрицательным!")
                    except ValueError:
                        print("Количество страниц в книге - положительное число!")
                while True:
                    condition = input("Введите оценку состояния книги как число от 1 до 10: ")
                    try:
                        condition = int(condition)
                        if 1 <= condition <= 10:
                            break
                        else:
                            print("Состояние книги это число от 1 до 10!")
                    except ValueError:
                        print("Состояние книги - число от 1 до 10!")
            elif type_of_book == 2:
                while True:
                    filetype = input("Введите формат файла книги (PDF, EPUB, FB2, TXT): ")
                    if filetype in {"PDF", "EPUB", "FB2", "TXT"}:
                        break
                    else:
                        print("Допустимые форматы - PDF, EPUB, FB2, TXT!")
                while True:
                    filesize = input("Введите размер файла книги: ")
                    try:
                        filesize = int(filesize)
                        if filesize > 0:
                            break
                        else:
                            print("Размер файла книги не может быть отрицательным!")
                    except ValueError:
                        print("Размер файла книги - положительное число!")
            is_ok = True
        except ValueError:
            print("Пожалуйста, введите 1 или 2!")
    print(f"добавляю книгу в библиотеку c названием - {name}, автором - {author}")
    author = ctypes.c_char_p(author.encode('utf-8'))
    name = ctypes.c_char_p(name.encode('utf-8'))
    if is_ok:
        if type_of_book == 2:
            lib.Library_addEBook(library, name, author, ctypes.c_char_p(filetype.encode('utf-8')), filesize)
        else:
            lib.Library_addPBook(library, name, author, pages, condition)


def delete_book():
    """  Функция удаления книги """
    name = input("Введите название книги для удаления: ")
    print(f"выполняю удаление книги c названием - {name} из библиотеки")
    name = ctypes.c_char_p(name.encode('utf-8'))
    lib.Library_removeBook(library, name)


def set_raiting():
    """  Функция проставления оценки книге из библиотеки """
    name = input("Введите название книги для выставления оценки: ")
    while True:
        rating = input("Введите оценку книги как число от 1 до 10: ")
        try:
            rating = int(rating)
            if 1 <= rating <= 10:
                break
            else:
                print("Оценка книги это число от 1 до 10!")
        except ValueError:
            print("Оценка книги - число от 1 до 10!")
    print(f"выставляю оценку книге c названием - {name}")
    name = ctypes.c_char_p(name.encode('utf-8'))
    lib.Library_setRating(library, name, rating)


def set_condition():
    """  Функция проставления состояния книги """
    name = input("Введите имя бумажной книги для оценки состояния: ")
    while True:
        condition = input("Введите оценку состояния книги как число от 1 до 10: ")
        try:
            condition = int(condition)
            if 1 <= condition <= 10:
                break
            else:
                print("Состояние книги это число от 1 до 10!")
        except ValueError:
            print("Состояние книги - число от 1 до 10!")
    print(f"выставляю состояние книге c названием - {name}")
    name = ctypes.c_char_p(name.encode('utf-8'))
    try:
        lib.Library_setCondition(library, name, condition)
    except OSError:
        # в случае если пользователь попытался выставить состояние
        # для электронной книги, будет созданно исключение
        print(f"Книга является электронной!")


def add_reading_date():
    """  Функция добавления даты прочтения """
    name = input("Введите название книги для добавления даты прочтения: ")
    while True:
        date = input("Введите дату прочтения книги как положительное число: ")
        try:
            date = int(date)
            if date > 0:
                break
            else:
                print("Дата прочтения это положительное число!")
        except ValueError:
            print("Дата прочтения это положительное число!")
    print(f"добавляю дату прочтения для книги c названием - {name}")
    name = ctypes.c_char_p(name.encode('utf-8'))
    lib.Library_addReadingDate(library, name, date)


def undo():
    """  Функция отмены операции """
    print("выполняю отмену последней операции")
    lib.Library_undo(library)


def quit_lib():
    """ Выйти из программы """
    print('завершаю программу')
    exit(0)


def print_menu(menu):
    """ Функция вывода меню, возвращающая функцию для исполнения """
    for i, (menu_str, _) in enumerate(menu):
        print(f'{i + 1}. {menu_str}')
    while True:
        try:
            num = int(input())
            return menu[num - 1][1]
        except (ValueError, IndexError):
            print(f'Пожалуйста, введите число от 1 до {len(menu)}')


def init_binding():
    """ Функция для загрузки C++ библиотеки """
    # Определение класса Library для ctypes
    class Library(ctypes.Structure):
        pass

    # Загрузка dll
    libdll = ctypes.cdll.LoadLibrary("./cmake-build-debug/libshared.dll")

    # Определение argtypes and restypes для каждой функции
    libdll.Library_new.restype = ctypes.POINTER(Library)

    libdll.Library_addEBook.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p,
                                        ctypes.c_long]
    libdll.Library_addEBook.restype = None

    libdll.Library_addPBook.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int,
                                        ctypes.c_short]
    libdll.Library_addPBook.restype = None

    libdll.Library_removeBook.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p]
    libdll.Library_removeBook.restype = None

    libdll.Library_setRating.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_short]
    libdll.Library_setRating.restype = None

    libdll.Library_setCondition.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_short]
    libdll.Library_setCondition.restype = None

    libdll.Library_addReadingDate.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_short]
    libdll.Library_addReadingDate.restype = None

    libdll.Library_getBooksListSortedByNameAscending.argtypes = [ctypes.POINTER(Library), ctypes.c_char_p, ctypes.c_int]
    libdll.Library_getBooksListSortedByNameAscending.restype = None

    libdll.Library_getBooksListSortedByRatingDescending.argtypes = [ctypes.POINTER(Library),
                                                                    ctypes.c_char_p, ctypes.c_int]
    libdll.Library_getBooksListSortedByRatingDescending.restype = None

    libdll.Library_undo.argtypes = [ctypes.POINTER(Library)]
    libdll.Library_undo.restype = None

    return libdll


def main():
    """ Функция главного меню """
    menu = [("Вывести список всех книг, отсортированный по названию", print_sorted_by_name),
            ("Вывести список всех книг, отсортированный по оценке", print_sorted_by_raiting),
            ("Добавить книгу в библиотеку", add_book),
            ("Удалить книгу из библиотеки", delete_book),
            ("Поставить книге оценку", set_raiting),
            ("Отметить ухудшение состояния книги", set_condition),
            ("Добавить дату прочтения", add_reading_date),
            ("Отменить последнюю операцию", undo),
            ("Выйти из программы", quit_lib)]
    while True:
        func = print_menu(menu)
        func()


if __name__ == '__main__':
    lib = init_binding()
    library = lib.Library_new()
    main()
