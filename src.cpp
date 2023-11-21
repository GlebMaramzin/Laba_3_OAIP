#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void add_bludo() {

    struct Bludo {
        string title;
        string type;
        double price;
    };



    ofstream bluda_file("bluda.txt");
    Bludo new_bludo;
    int bludo_num = 1;

    while (true) {
        system("cls");

        cout << "Блюдо №" << bludo_num << endl;
        cout << "Введите название блюда: " << endl;
        cin >> new_bludo.title;
        if (new_bludo.title == "stop") break;
        bluda_file << new_bludo.title << ";";
        cout << "Введите тип блюда: " << endl;
        cout << "Возможные варианты: Закуски, Основные блюда, Десерты, Напитки, Для детей" << endl;
        cin >> new_bludo.type;
        bluda_file << new_bludo.type << ";";
        cout << "Введите стоимость блюда: " << endl;
        cin >> new_bludo.price;
        bluda_file << new_bludo.price << "\n";

        bludo_num++;
    }

    bluda_file.close();
}

void find_bludo(string& title) {
    ifstream bluda_file("bluda.txt");
    string line;
    bool is_found = false;

    while (getline(bluda_file, line)) {
        size_t pos = line.find(';');
        string full_title = line.substr(0, pos);
        if (full_title == title) {
            cout << "Найдено блюдо: " << line << endl;
            is_found = true;
            break;
        }
        bluda_file.close();
        if (!is_found) cout << "Не удалось найти указанное блюдо" << endl;
    }
}


void sort_by_type() {
    system("cls");

    ifstream bluda_file("bluda.txt");
    string line;
    vector<string> lines;

    while (getline(bluda_file, line)) {
        lines.push_back(line);
    }
    bluda_file.close();

    for (int i = 0; i < lines.size() - 1; i++) {
        for (int j = 0; j < lines.size() - i - 1; j++) {
            size_t pos1 = lines[j].find(';');
            size_t pos2 = lines[j + 1].find(';');
            string type1 = lines[j].substr(pos1 + 1, lines[j].find_last_of(';'));
            string type2 = lines[j + 1].substr(pos2 + 1, lines[j+1].find_last_of(';'));
            pos1 = type1.find(';');
            pos2 = type2.find(';');
            type1 = type1.substr(0, pos1);
            type2 = type2.substr(0, pos2);
            cout << type1 << endl;
            cout << type2 << endl;
            if (type1 < type2) {
                std::swap(lines[j], lines[j + 1]);
            }
        }
    }

    ofstream bluda_file_in("bluda.txt");
    for (int i = 0; i < lines.size(); i++) {
        bluda_file_in << lines[i] << endl;
    }
    bluda_file_in.close();
    cout << "Блюда отсортированы по типу" << endl;
    cout << endl;
}


void sort_by_price() {
    system("cls");

    ifstream bluda_file("bluda.txt");
    string line;
    vector<string> lines;

    while (getline(bluda_file, line)) {
        lines.push_back(line);
    }
    bluda_file.close();

    for (int i = 0; i < lines.size() - 1; i++) {
        for (int j = 0; j < lines.size() - i - 1; j++) {
            size_t pos1 = lines[j].find_last_of(';');
            size_t pos2 = lines[j + 1].find_last_of(';');
            double price1 = stod(lines[j].substr(pos1 + 1));
            double price2 = stod(lines[j + 1].substr(pos2 + 1));
            if (price1 > price2) {
                std::swap(lines[j], lines[j + 1]);
            }
        }
    }

    ofstream bluda_file_in("bluda.txt");
    for (int i = 0; i < lines.size(); i++) {
        bluda_file_in << lines[i] << endl;
    }
    bluda_file.close();
    cout << "Блюда отсортированы по цене" << endl;
    cout << endl;
}


void print_bluda_by_type(string& type) {
    ifstream bluda_file("bluda.txt");
    string line;

    while (getline(bluda_file, line)) {
        size_t pos_first = line.find(';');
        string full_type = line.substr(pos_first+1, type.size());

        if (full_type == type) {

            cout << "Найдено блюдо по типу '" << type << "': " << line << endl;
        }
    }
}


void print_bluda_by_price(string& price) {
    ifstream bluda_file("bluda.txt");
    string line;

    while (getline(bluda_file, line)) {
        size_t pos = line.find_last_of(';');
        string full_price = line.substr(pos+1);
        if (full_price == price) {
            cout << "Найдено блюдо по цене '" << price << "': " << line << endl;
        }
    }
}


void print_bluda_by_query() {
    system("cls");
    string type, price;
    int choice;

    cout << "Вывести блюда по: " << endl;
    cout << "1) Типу блюда" << endl;
    cout << "2) Стоимости" << endl;
    cout << "3) Отмена" << endl;
    cout << "Выберите действие: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cin.ignore();
        cout << "Введите тип блюда: " << endl;
        getline(cin, type);
        print_bluda_by_type(type);
        break;
    case 2:
        cin.ignore();
        cout << "Введите стоимость: " << endl;
        getline(cin, price);
        print_bluda_by_price(price);
        break;
    default:
        break;
    }
}


int main()
{
    system("chcp 1251 > nul");

    string title;
    int choice;


    do {
        cout << "Меню:" << endl;
        cout << "1) Добавить блюдо" << endl;
        cout << "2) Поиск блюда по названию" << endl;
        cout << "3) Сортировать блюда по типу" << endl;
        cout << "4) Сортировать блюда по цене" << endl;
        cout << "5) Вывести блюда по запросу" << endl;
        cout << "6) Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            add_bludo();
            break;
        }
        case 2: {
            cin.ignore();
            cout << "Введите название блюда: " << endl;
            getline(cin, title);
            find_bludo(title);
            break;
        }
        case 3: {
            sort_by_type();
            break;
        }
        case 4: {
            sort_by_price();
            break;
        }
        case 5: {
            print_bluda_by_query();
            break;
        }
        case 6: {
            cout << "Завершение программы";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }
        }
    } while (choice != 6);

    system("pause > nul");
    return 0;
}