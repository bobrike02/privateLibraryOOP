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


def print_sorted_by_name(lib):
    """ Заготовка для функции вывода списка всех книг, отсортированного по названию """
    print("stub: выполняю вывод с сортировкой по названию")
    return None


def print_sorted_by_raiting(lib):
    """ Заготовка для функции вывода списка всех книг, отсортированного по оценке """
    print("stub: выполняю вывод с сортировкой по оценке")
    return None


def add_book():
    """ Заготовка для функции добавления книги в библиотеку """
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
                    if filetype in {"PDF", "TXT", "FB2", "TXT"}:
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
    print(f"stub: добавляю книгу в библиотеку c названием - {name}, автором - {author}")


def delete_book(lib):
    """ Заготовка для функции удаления книги """
    name = input("Введите название книги для удаления: ")
    author = input("Введите имя автора книги: ")
    print(f"stub: выполняю удаление книги c названием - {name}, автором - {author} из библиотеки")


def set_raiting(lib):
    """ Заготовка для функции проставления оценки книге из библиотеки """
    name = input("Введите название книги для выставления оценки: ")
    author = input("Введите имя автора книги: ")
    while True:
        raiting = input("Введите оценку книги как число от 1 до 10: ")
        try:
            raiting = int(raiting)
            if 1 <= raiting <= 10:
                break
            else:
                print("Оценка книги это число от 1 до 10!")
        except ValueError:
            print("Оценка книги - число от 1 до 10!")
    print(f"stub: выставляю оценку книге c названием - {name}, автором - {author}")


def set_condition(lib):
    """ Заготовка для функции проставления состояния книги """
    name = input("Введите имя бумажной книги для оценки состояния: ")
    author = input("Введите имя автора книги: ")
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
    print(f"stub: выставляю состояние книге c названием - {name}, автором - {author}")


def add_reading_date(lib):
    """ Заготовка для функции добавления даты прочтения """
    name = input("Введите название книги для добавления даты прочтения: ")
    author = input("Введите имя автора книги: ")
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
    print(f"stub: добавляю дату прочтения для книги c названием - {name}, автором - {author}")


def undo(lib):
    """ Заготовка для функции отмены операции """
    print("stub: выполняю отмену последней операции")


def quit_lib():
    """ Выйти из программы """
    print('stub: завершаю программу')
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
    # Загружаем библиотеку
    lib = ctypes.cdll.LoadLibrary("./interface.dll")

    # Определяем аргументы и возвращаемое значение для функций
    lib.Library_new.argtypes = []
    lib.Library_new.restype = ctypes.c_void_p

    lib.Library_addEBook.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_short]
    lib.Library_addEBook.restype = None

    lib.Library_addPBook.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_short, ctypes.c_short]
    lib.Library_addPBook.restype = None

    lib.Library_removeBook.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
    lib.Library_removeBook.restype = None

    lib.Library_setRating.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_short]
    lib.Library_setRating.restype = None

    lib.Library_setCondition.argtypes = [ctypes.c_void_p,
                                         ctypes.c_char_p,
                                         ctypes.c_size_t]
    lib.Library_setCondition.restype = None

    lib.Library_addReadingDate.argtypes = [ctypes.c_void_p,
                                           ctypes.c_char_p,
                                           ctypes.c_size_t]
    lib.Library_addReadingDate.restype = None

    lib.Library_getBooksListSortedByNameAscending.argtypes = [ctypes.c_void_p]
    lib.Library_getBooksListSortedByNameAscending.restype = ctypes.c_char_p

    lib.Library_getBooksListSortedByRatingDescending.argtypes = [ctypes.c_void_p]
    lib.Library_getBooksListSortedByRatingDescending.restype = ctypes.c_char_p

    lib.Library_undo.argtypes = [ctypes.c_void_p]
    lib.Library_undo.restype = None
    return lib


def test(lib):
    library = lib.Library_new()
    name = ctypes.c_char_p('War and Peace'.encode('utf-8'))
    author = ctypes.c_char_p('Lew Tolstoy'.encode('utf-8'))
    lib.Library_addEBook(library, name, author, ctypes.c_char_p('PDF'.encode('utf-8')), 1024)
    name = ctypes.c_char_p('War and Peace1'.encode('utf-8'))
    author = ctypes.c_char_p('Lew Tolstoy1'.encode('utf-8'))
    lib.Library_addPBook(library, name, author, 100, 3)
    lib.Library_setRating(library, name, 4)
    lib.Library_setCondition(library, name, 2)
    lib.Library_addReadingDate(library, name, 20220429)
    out = ctypes.create_string_buffer(100)
    lib.Library_getBooksListSortedByNameAscending(library, out, ctypes.sizeof(out))
    print(out.value.decode('utf-8'))
    out = ctypes.create_string_buffer(100)
    lib.Library_getBooksListSortedByRatingDescending(library, out, ctypes.sizeof(out))
    print(out.value.decode('utf-8'))
    lib.Library_undo(library)


def main(lib):
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
    test(lib)
