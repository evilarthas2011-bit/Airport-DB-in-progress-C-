#include "Dataio.h"
#include <string>
#include <iostream>
#include <iomanip> 
using namespace std;


// из enum в строку
string EnumString(int index) {
    switch (static_cast<Type>(index - 1)) {
    case Chart: return "Чартарный";
    case Reg: return "Регулярный";
    case Priam: return "Прямой";
    case Tranz: return "Транзитный";
    case Styic: return "Стыковачный";
    }
}

// Функция ввода даты и времени вылета
void TmO(Airport*& temp, int count) {
    cout << "Введите дату вылет\n" << "Год: ";
    while (1) {
        if (cin >> temp[count].timeo.year && temp[count].timeo.year >= 2000 && temp[count].timeo.year <= 2100) {
            break;
        }
        else {
            cout << "Ошибка ! Введите год от 2000 до 2100 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "\nМесяц: ";
    while (1) {
        if (cin >> temp[count].timeo.month && temp[count].timeo.month >= 1 && temp[count].timeo.month <= 12) {
            break;
        }
        else {
            cout << "Ошибка ! Введите месяц от 1 до 12 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "\nДень: ";

    switch (temp[count].timeo.month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        while (1) {
            if (cin >> temp[count].timeo.day && temp[count].timeo.day >= 1 && temp[count].timeo.day <= 31) {
                break;
            }
            else {
                cout << "Ошибка ! Введите число от 1 до 31 !\n";
                cin.clear();
                cin.ignore();
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        while (1) {
            if (cin >> temp[count].timeo.day && temp[count].timeo.day >= 1 && temp[count].timeo.day <= 30) {
                break;
            }
            else {
                cout << "Ошибка ! Введите число от 1 до 30 !\n";
                cin.clear();
                cin.ignore();
            }
        }
        break;
    case 2:
        while (1) {
            if (cin >> temp[count].timeo.day && temp[count].timeo.day >= 1 && temp[count].timeo.day <= 29) {
                break;
            }
            else {
                cout << "Ошибка ! Введите число от 1 до 29 !\n";
                cin.clear();
                cin.ignore();
            }
        }
        break;
    default:
        cout << "ОШИБКА!" << endl;
        break;
    }


    cout << "\nВведите время вылета.\nЧасы: ";
    while (1) {
        if (cin >> temp[count].timeo.hour && temp[count].timeo.hour >= 0 && temp[count].timeo.hour <= 23) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время часы от 0 до 23 !";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Минуты :";
    //Проверка ввода минуты
    while (1) {
        if (cin >> temp[count].timeo.min && temp[count].timeo.min >= 0 && temp[count].timeo.min <= 59) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время минуты от 0 до 59 !";
            cin.clear();
            cin.ignore();
        }
    }
}

// Функция ввода даты и времени прибытия
void TmI(Airport*& temp, int count) {
    cout << "Введите дату прибытия\n" << "Год: ";
    while (2) {
        if (cin >> temp[count].timei.year && temp[count].timei.year >= 2000 && temp[count].timei.year <= 2100 && temp[count].timei.year >= temp[count].timeo.year) {
            break;
        }
        else {
            cout << "Ошибка ! Введите год от 2000 до 2100 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Месяц: ";
    if (temp[count].timei.year == temp[count].timeo.year) {
        while (2) {
            if (cin >> temp[count].timei.month && temp[count].timei.month <= 12 && temp[count].timeo.month <= temp[count].timei.month) {
                break;
            }
            else {
                cout << "Ошибка ! Введите корректный месяц до 12 !\n";
                cin.clear();
                cin.ignore();
            }
        }
    }
    else {
        while (2) {
            if (cin >> temp[count].timei.month && temp[count].timei.month >= 1 && temp[count].timei.month <= 12) {
                break;
            }
            else {
                cout << "Ошибка ! Введите месяц от 1 до 12 !\n";
                cin.clear();
                cin.ignore();
            }
        }

    }

    cout << "\nДень: ";
    if (temp[count].timei.month == temp[count].timeo.month) {
        switch (temp[count].timei.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= temp[count].timeo.day && temp[count].timei.day <= 31) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 31 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= temp[count].timeo.day && temp[count].timei.day <= 30) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 30 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }
            break;
        case 2:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= temp[count].timeo.day && temp[count].timei.day <= 29) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 29 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }
            break;
        default:
            cout << "ОШИБКА!" << endl;
            break;
        }
    }
    else {
        switch (temp[count].timei.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= 1 && temp[count].timei.day <= 31) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 31 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }
        case 4:
        case 6:
        case 9:
        case 11:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= 1 && temp[count].timei.day <= 30) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 30 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }

        case 2:
            while (2) {
                if (cin >> temp[count].timei.day && temp[count].timei.day >= 1 && temp[count].timei.day <= 29) {
                    break;
                }
                else {
                    cout << "Ошибка ! Введите число от 1 до 29 !\n";
                    cin.clear();
                    cin.ignore();
                }
            }
        default:
            cout << "ОШИБКА!" << endl;
            break;
        }
    }

    cout << "Введите время прибытия :\nЧасы :";
    //Проверка ввода времени
    if (temp[count].timeo.day == temp[count].timei.day) {
        while (1) {
            if (cin >> temp[count].timei.hour && temp[count].timei.hour >= temp[count].timeo.hour && temp[count].timei.hour <= 23) {
                break;
            }
            else {
                cout << " Ошибка ! Введите время часы от 0 до 23 !";
                cin.clear();
                cin.ignore();
            }
        }
        cout << "Минуты :";

        if (temp[count].timei.hour == temp[count].timeo.hour) {
            while (2) {
                if (cin >> temp[count].timei.min && temp[count].timei.min >= temp[count].timeo.min && temp[count].timei.min <= 59) {
                    break;
                }
                else {
                    cout << " Ошибка ! Введите время минуты от 0 до 59 !";
                    cin.clear();
                    cin.ignore();
                }
            }
        }
        else {
            while (2) {
                if (cin >> temp[count].timei.min && temp[count].timei.min >= 0 && temp[count].timei.min <= 59) {
                    break;
                }
                else {
                    cout << " Ошибка ! Введите время минуты от 0 до 59 !";
                    cin.clear();
                    cin.ignore();
                }
            }
        }
    }
    else {
        while (2) {
            if (cin >> temp[count].timei.hour && temp[count].timei.hour >= 0 && temp[count].timei.hour <= 23) {
                break;
            }
            else {
                cout << " Ошибка ! Введите время часы от 0 до 23 !";
                cin.clear();
                cin.ignore();
            }
        }
        cout << "Минуты :";

        while (2) {
            if (cin >> temp[count].timei.min && temp[count].timei.min >= 0 && temp[count].timei.min <= 59) {
                break;
            }
            else {
                cout << " Ошибка ! Введите время минуты от 0 до 59 !";
                cin.clear();
                cin.ignore();
            }
        }
    }
}

//Функция ввода данных
void Enter(Airport*& temp, int count) {
    // Ввод новых данных
    cout << "Введите номер рейса: ";
    //Проверка ввода номера рейса
    while (1) {
        if (cin >> temp[count].number && temp[count].number >= 1) {
            break;
        }
        else {
            cout << "Ошибка ! Введите число больше 1!\n";
            cin.clear(); // Для сброса ошибок
            cin.ignore();
        }
    }

    cout << "Введите номер типа рейса (1-Чартарный, 2-Регулярный, 3-Прямой, 4-Транзитный,5-Стыковачный) :";
    int x;
    while (7) {
        if (cin >> x && x >= 1 && x <= 5) {
            temp[count].type = EnumString(x);
            break;
        }
        else {
            cout << "Ошибка! Повторите ввод типа !\n";
            cin.clear();
            cin.ignore();
        }
    }

    /* cout << "Введите тип рейса (1-Чартарный, 2-Регулярный, 3-Прямой, 4-Транзитный,5-Стыковачный) : ";
     string Check = "Чартарный  Регулярный  Прямой  Транзитный  Стыковачный";
     cin.ignore(); // Полное очистка буфера ввода для коректной работы getline ()
     //Проверка на ввод строк
     //getline(cin, temp[count].type);
     while (7) {
         if (getline(cin, temp[count].type) && Check.find(temp[count].type) != string::npos) {
             break;
         }
         else {
             cout << "Ошибка! Повторите ввод типа ! Обратите внимание на правильность введённого слова и регистр первой буквы!\n";
             cin.clear();
             cin.ignore();
         }
     }
     */

    cout << "Введите пунк назначения рейса: ";
    cin.ignore();
    //Проверка на ввод строк 
   // getline(cin, temp[count].destination);
    while (7) {
        if (getline(cin, temp[count].destination) && !temp[count].destination.empty() /* && isupper(temp[count].destination[0])*/) {
            break;
        }
        else {
            cout << "Ошибка! Ввод пустой!\n";
            cin.clear();

        }
    }

    TmO(temp, count);
    TmI(temp, count);
    //Предъыдущий варик
  /*  cout << "Введите дату вылета : \nДень :";
    //Проверка ввода дня
    while (2) {
        if (cin >> temp[count].timeo.day && temp[count].timeo.day >= 1 && temp[count].timeo.day <= 31) {
            break;
        }
        else {
            cout << "Ошибка ! Введите число от 1 до 31 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Месяц :";
    // Проверка ввода месяца
    while (3) {
        if (cin >> temp[count].timeo.month && temp[count].timeo.month >= 1 && temp[count].timeo.month <= 12) {
            break;
        }
        else {
            cout << "Ошибка ! Введите месяц от 1 до 12 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Год :";
    //Проверка ввода года
    while (4) {
        if (cin >> temp[count].timeo.year && temp[count].timeo.year >= 2000 && temp[count].timeo.year <= 2100) {
            break;
        }
        else {
            cout << "Ошибка ! Введите год от 2000 до 2100 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Введите время вылета : \n Часы :";
    //Проверка ввода часа
    while (5) {
        if (cin >> temp[count].timeo.hour && temp[count].timeo.hour >= 0 && temp[count].timeo.hour <= 23) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время часы от 0 до 23 !";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Минуты :";
    //Проверка ввода минуты
    while (6) {
        if (cin >> temp[count].timeo.min && temp[count].timeo.min >= 0 && temp[count].timeo.min <= 59) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время минуты от 0 до 59 !";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Введите дату прибытия : \nДень :";
    while (2) {
        if (cin >> temp[count].timei.day && temp[count].timei.day >= 1 && temp[count].timei.day <= 31) {
            break;
        }
        else {
            cout << "Ошибка ! Введите число от 1 до 31 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Месяц :";
    while (3) {
        if (cin >> temp[count].timei.month && temp[count].timei.month >= 1 && temp[count].timei.month <= 12) {
            break;
        }
        else {
            cout << "Ошибка ! Введите месяц от 1 до 12 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Год :";
    while (4) {
        if (cin >> temp[count].timei.year && temp[count].timei.year >= 2000 && temp[count].timei.year <= 2100) {
            break;
        }
        else {
            cout << "Ошибка ! Введите год от 2000 до 2100 !\n";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Введите время прибытия : \n Часы :";
    while (5) {
        if (cin >> temp[count].timei.hour && temp[count].timei.hour >= 0 && temp[count].timei.hour <= 23) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время часы от 0 до 23 !";
            cin.clear();
            cin.ignore();
        }
    }

    cout << "Минуты :";
    while (6) {
        if (cin >> temp[count].timei.min && temp[count].timei.min >= 0 && temp[count].timei.min <= 59) {
            break;
        }
        else {
            cout << " Ошибка ! Введите время минуты от 0 до 59 !";
            cin.clear();
            cin.ignore();
        }
    }
    */
}

// Функция внесения данных и выделения доп. памяти
void addAirport(Airport*& data, int& count) {
    // Создаем новый временный массив размером на 1 больше
    Airport* temp = new Airport[count + 1];

    // Копируем старые данные в новый массив
    for (int i = 0; i < count; i++) {
        temp[i] = data[i];
    }

    Enter(temp, count);

    // Удаляем старый массив и перенаправляем указатель
    delete[] data;
    data = temp;
    count++;

    cout << "Запись успешно добавлена!" << endl;
}

//  Функция вывод в формате "поле: значение"
void printList(Airport* data, int count) {
    if (count == 0) {  // Проверка на пустоту структуры
        cout << "Список пуст." << endl;
        return;
    }
    cout << "\n*** Список Рейсов ***" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Запись №" << i + 1 << ":" << endl;
        cout << "Номер рейса: " << data[i].number << endl;
        cout << "Тип рейса: " << data[i].type << endl;
        cout << "Пунк назначения: " << data[i].destination << endl;
        cout << "Дата вылета: " << data[i].timeo.day << "." << data[i].timeo.month << "." << data[i].timeo.year << endl;
        cout << "Вермя вылета: " << data[i].timeo.hour << ":" << data[i].timeo.hour << endl;
        cout << "Дата прибытия: " << data[i].timei.day << "." << data[i].timei.month << "." << data[i].timei.year << endl;
        cout << "Вермя прибытия: " << data[i].timei.hour << ":" << data[i].timei.hour << endl;
        cout << "*************************" << endl;
    }
}

// Функция вывода  в табличном формате
void printTable(Airport* data, int count) {
    if (count == 0) {  // Проверка на пустоту структуры
        cout << "Таблица пуста." << endl;
        return;
    }

    cout << "\n" << setfill('*') << setw(125) << "" << setfill(' ') << endl;  // setfill() для заполнения пустокго места символами используется вместе с setw ()
    cout << "| " << setw(2) << left << "№"  // Left для выравнивания по левой стороне
        << "| " << setw(6) << "Номер "
        << "| " << setw(20) << "Тип рейса"
        << "| " << setw(20) << "Пунк назначения"
        << "| " << setw(15) << "Дата вылета"
        << "| " << setw(15) << "Время вылета"
        << "| " << setw(15) << "Дата прибытия"
        << "| " << setw(15) << "Время прибытия" << " |" << endl;
    cout << setfill('-') << setw(125) << "" << setfill(' ') << endl;
    // Для красоты таблицы просто трээээш
    string datain;
    string timein;
    string dataout;
    string timeout;

    for (int i = 0; i < count; i++) {   // Вывод полей структуры по порядку
        dataout = to_string(data[i].timeo.day) + "." + to_string(data[i].timeo.month) + "." + to_string(data[i].timeo.year);
        datain = to_string(data[i].timei.day) + "." + to_string(data[i].timei.month) + "." + to_string(data[i].timei.year);
        timeout = to_string(data[i].timeo.hour) + ":" + to_string(data[i].timeo.min);
        timein = to_string(data[i].timei.hour) + ":" + to_string(data[i].timei.min);
        cout << "| " << setw(2) << left << i + 1
            << "| " << setw(6) << data[i].number
            << "| " << setw(20) << data[i].type
            << "| " << setw(20) << data[i].destination
            << "| " << setw(15) << dataout /* data[i].timeo.day << "." << data[i].timeo.month << "." << data[i].timei.year */
            << "| " << setw(15) << timeout /* data[i].timeo.hour << ":" << data[i].timeo.hour */
            << "| " << setw(15) << timein /* data[i].timei.day << "." << data[i].timei.month << "." <<  data[i].timei.year */
            << "| " << setw(15) << datain /*data[i].timei.hour << ":" << data[i].timei.hour*/
            << " |" << endl;
    }
    cout << setfill('*') << setw(125) << "" << setfill(' ') << endl;
}

void clear(Airport*& data, int& count) {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    count = 0;
}
