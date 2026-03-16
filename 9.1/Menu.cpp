#include "Menu.h"
#include "Dataio.h"
#include "File.h"
#include <iostream>

void menu() {
    std::cout << "\n**** МЕНЮ УПРАВЛЕНИЯ ****" << std::endl;
    std::cout << "1. Добавить запись" << std::endl;
    std::cout << "2. Вывести списком (поле: значение)" << std::endl;
    std::cout << "3. Вывести таблицей" << std::endl;
    std::cout << "4. Создать новый файл" << std::endl;
    std::cout << "5. Удалить файл по названию" << std::endl;
    std::cout << "6. Очистка динамичсекой памяти" << std::endl;
    std::cout << "7. Запись в файл" << std::endl;
    std::cout << "8. Загрузка из файл" << std::endl;
    std::cout << "9. Выбор работы с бинарным или текстовым файлом" << std::endl;
    std::cout << "10. Список файлов" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";

}
// Функция меню
void Menu() {
   
    int count = 0;
    Airport* Plane = nullptr;
    string* history = nullptr;
    int history_count = 0;
    bool binary = false;
    string filename;
    int choice;

    while (true) {
        menu();
        cout << "Режим: " << (binary ? "[Двоичный]" : "[Текстовый]") << " | Записей в памяти: " << count << endl;
        cout << ">> ";
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        case 1:  addAirport(Plane, count);
            break;
        case 2:  printList(Plane, count);
            break;
        case 3:  printTable(Plane, count);
            break;
        case 4:
            cout << "Имя нового файла: "; cin >> filename;
            {
                ofstream file = new_DB(filename, binary);
                if (file.is_open()) {
                    add_to_history(history, history_count, filename);
                    file.close();
                }
            }
            break;

        case 5:
            cout << "Имя файла для удаления: "; cin >> filename;
            {
                string full_name = prefix(filename, binary);
                if (remove_DB(full_name, binary)) {
                    remove_from_history(history, history_count, full_name);
                    cout << "Удалено.\n";
                }
            }
            break;

        case 6:
            clear(Plane, count);
            cout << "Память очищена.\n";
            break;

        case 7:
            if (count == 0) { cout << "Массив пуст.\n"; break; }
            cout << "Имя файла: "; cin >> filename;
            int Mode;
            while (true) {
                cout << "0 - Перезаписать, 1 - Дописать: ";
                if (cin >> Mode && (Mode == 0 || Mode == 1)) break;
                cin.clear(); cin.ignore(10000, '\n');
            }
            save_DB(filename, Plane, count, binary, (Mode == 1));
            add_to_history(history, history_count, prefix(filename, binary));
            cout << "Сохранено.\n";
            break;

        case 8:
            cout << "Имя файла: "; cin >> filename;
            load_DB(filename, Plane, count, binary);
            if (count > 0) add_to_history(history, history_count, prefix(filename, binary));
            break;

        case 9:
            binary = !binary;
            cout << "Режим изменен.\n";
            break;

        case 10:
            print_history(history, history_count);
            break;

        default: cout << "Неверный пункт.\n"; break;
        }
    }

    clear(Plane, count);
    delete[] history;
}

