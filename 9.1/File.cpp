#include "File.h"
#include "Dataio.h"

string prefix(string filename, bool binary) {
    string ext = binary ? ".bin" : ".txt";
    if (filename.length() < ext.length() ||
        filename.substr(filename.length() - ext.length()) != ext) {
        filename += ext;
    }
    return filename;
}

// 1. Создание файла
ofstream new_DB(string& filename, bool binary) {
    filename = prefix(filename, binary);
    ios_base::openmode mode = ios::out;
    if (binary) mode |= ios::binary;

    ofstream file(filename, mode);
    if (file.fail()) {
        cerr << "Ошибка: Не удалось создать файл '" << filename << "'" << endl;
    }
    else {
        cout << "Файл '" << filename << "' успешно создан." << endl;
    }
    return file;
}

//  Удаление файла
bool remove_DB(string filename, bool binary) {
    filename = prefix(filename, binary);
    if (remove(filename.c_str()) == 0) {
        cout << " Файл " << filename << " удалён." << endl;
        return true;
    }
    else {
        cerr << "Ошибка: Файл " << filename << " не найден." << endl;
        return false;
    }
}

//  Сохранение и дозапись
void save_DB(string filename, Airport* data, int count, bool binary, bool append) {
    filename = prefix(filename, binary);
    ios_base::openmode mode = ios::out;
    if (binary) mode |= ios::binary;
    if (append) mode |= ios::app;

    ofstream file(filename, mode);
    if (file.fail()) {
        cerr << "Ошибка открытия файла " << filename << " для записи!" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        if (binary) {
            file.write((char*)&data[i].number, sizeof(int));
            size_t t_len = data[i].type.length();
            file.write((char*)&t_len, sizeof(size_t));
            file.write(data[i].type.c_str(), t_len);
            size_t d_len = data[i].destination.length();
            file.write((char*)&d_len, sizeof(size_t));
            file.write(data[i].destination.c_str(), d_len);
            file.write((char*)&data[i].timeo, sizeof(Time));
            file.write((char*)&data[i].timei, sizeof(Time));
        }
        else {
            file << data[i].number << " " << data[i].type << " " << data[i].destination << " "
                << data[i].timeo.year << " " << data[i].timeo.month << " " << data[i].timeo.day << " "
                << data[i].timeo.hour << " " << data[i].timeo.min << " "
                << data[i].timei.year << " " << data[i].timei.month << " " << data[i].timei.day << " "
                << data[i].timei.hour << " " << data[i].timei.min << endl;
        }
    }
    file.close();
}

// Загрузка файла
void load_DB(string filename, Airport*& data, int& count, bool binary) {
    filename = prefix(filename, binary);
    ios_base::openmode mode = ios::in;
    if (binary) mode |= ios::binary;

    ifstream file(filename, mode);
    if (!file.is_open()) {
        cerr << "Ошибка: Файл " << filename << " не найден!" << endl;
        return;
    }

    int file_records = 0;
    if (binary) { // Проход по файлу для определения его размера
        while (file.peek() != EOF) {
            int n; size_t len;
            if (!file.read((char*)&n, sizeof(int))) break;
            file.read((char*)&len, sizeof(size_t)); file.seekg(len, ios::cur);
            file.read((char*)&len, sizeof(size_t)); file.seekg(len, ios::cur);
            file.seekg(sizeof(Time) * 2, ios::cur);
            file_records++;
            file.peek();
        }
    }
    else {
        int n; string s1, s2; Time t1, t2;
        while (file >> n >> s1 >> s2 >> t1.year >> t1.month >> t1.day >> t1.hour >> t1.min
            >> t2.year >> t2.month >> t2.day >> t2.hour >> t2.min) {
            file_records++;
        }
    }

    file.clear(); file.seekg(0, ios::beg);
    clear(data, count);

    if (file_records > 0) {
        count = file_records;
        data = new Airport[count];
        for (int i = 0; i < count; i++) {
            if (binary) {
                file.read((char*)&data[i].number, sizeof(int));
                size_t len;
                file.read((char*)&len, sizeof(size_t));
                data[i].type.resize(len);
                if (len > 0) file.read(&data[i].type[0], len);
                file.read((char*)&len, sizeof(size_t));
                data[i].destination.resize(len);
                if (len > 0) file.read(&data[i].destination[0], len);
                file.read((char*)&data[i].timeo, sizeof(Time));
                file.read((char*)&data[i].timei, sizeof(Time));
            }
            else {
                file >> data[i].number >> data[i].type >> data[i].destination
                    >> data[i].timeo.year >> data[i].timeo.month >> data[i].timeo.day >> data[i].timeo.hour >> data[i].timeo.min
                    >> data[i].timei.year >> data[i].timei.month >> data[i].timei.day >> data[i].timei.hour >> data[i].timei.min;
            }
        }
    }
    file.close();
}


void add_to_history(string*& history, int& count, string filename) {
    for (int i = 0; i < count; i++)
        if (history[i] == filename) return;
    string* temp = new string[count + 1];
    for (int i = 0; i < count; i++) temp[i] = history[i];
    temp[count] = filename;
    delete[] history;
    history = temp;
    count++;
}

void remove_from_history(string*& history, int& count, string filename) {
    int index = -1;
    for (int i = 0; i < count; i++)
        if (history[i] == filename)
        {
            index = i; break;
        }
    if (index == -1) return;

    if (count == 1) { delete[] history; history = nullptr; count = 0; }
    else {
        string* temp = new string[count - 1];
        for (int i = 0, j = 0; i < count; i++) if (i != index) temp[j++] = history[i];
        delete[] history;
        history = temp;
        count--;
    }
}

void print_history(string* history, int count) {
    cout << "\n=== Список файлов сессии ===" << endl;
    if (count == 0)
    {
        cout << "Список пуст." << endl;
    }
    else {
        for (int i = 0; i < count; i++) cout << i + 1 << ". " << history[i] << endl;
    }

}