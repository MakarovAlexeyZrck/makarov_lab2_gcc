// apl_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;


// Струтура данных для трубы
struct trumpet
{
    int id;
    string user_id;
    string length;
    string diametr;
    string is_repair;
};


// Структрура данных для КС
struct ks
{
    int id;
    string user_id;
    string ks_name;
    string number_of_workshops;
    string working_workshops;
    string efficiency;
};

// Глобальный вектор для информации о трубах
vector <trumpet> trumpets_data;

// Глобальный вектор для информации о КС
vector <ks> kss_data;


vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


// Вывод функций программы
void show_functions() {

    cout << " --- Select the user action --- " << endl
        << "1. Add the trumpet ... " << endl
        << "2. Add the ks ... " << endl
        << "3. Show all items ... " << endl
        << "4. Edit the trumpet ..." << endl
        << "5. Edit the ks ... " << endl
        << "6. Save items to file ... " << endl
        << "7. Upload data from file ... " << endl
        << "8. Research ... " << endl
        << "0. Exit ..." << endl;

}

// Функция по добалению записи о трубе в программу
void add_trumpet(int n_id) {

    trumpet current_trumpet;

    // Ввод данных о трубе
    if (n_id == 0) {
        current_trumpet.id = rand();
    }
    else {
        current_trumpet.id = n_id;
    }

    // Ввод идентификатора пользователя для трубы
    cout << "\nInput trumpet`s id: ";
    cin >> current_trumpet.user_id;

    // Ввод длины трубы
    cout << "Input trumpet`s lenght: ";
    cin >> current_trumpet.length;

    // Ввод диаметра трубы
    cout << "Input trumpet`s diametr: ";
    cin >> current_trumpet.diametr;

    // Ввод признака в работе или нет
    cout << "Input repair or not: ";
    cin >> current_trumpet.is_repair;

    // Добавление информации о трубе в глобальный ветор
    trumpets_data.push_back(current_trumpet);

    cout << "Trumpet was added. Success ... \n\n";

}


// Создание нового элемента КС
void add_ks(int n_id) {

    ks current_ks;

    // Идентификатор КС
    if (n_id == 0) {
        current_ks.id = rand();
    }
    else {
        current_ks.id = n_id;
    }

    // Ввод идентификатора пользователя для КС
    cout << "\nInput ks`s id: ";
    cin >> current_ks.user_id;

    // Наименование КС
    cout << "Input ks`s name: ";
    cin >> current_ks.ks_name;

    // Количество цехов в КС
    cout << "Input ks`s workshops: ";
    cin >> current_ks.number_of_workshops;

    // Количество цехов КС в работе 
    cout << "Input in work workshops: ";
    cin >> current_ks.working_workshops;

    // Эффективность КС
    cout << "Input ks`s efficiency: ";
    cin >> current_ks.efficiency;

    // Отправка данных в глобальный вектор данных
    kss_data.push_back(current_ks);

    cout << "KS was added. Success ... \n\n";

}


// Отображение всех элементов, что в глобальных векторах 
void show_all() {

    // Отображение всех труб 
    int trumpets_count;
    trumpets_count = trumpets_data.size();
    if (trumpets_count == 0) {
        cout << "\nNo trumpets yet. Choose 1 for adding trumpet ... \n\n";
    }
    else
    {
        cout << "\nTRUMPETS DATA \n";
        for (auto& im : trumpets_data) {
            cout << "Unique trumpet id: " << im.id << ", user trumpet id: " << im.user_id << ", trumpet lenght: " << im.length << ", trumpet diametr: " << im.diametr << ", is trumpet repair: " << im.is_repair << endl;

        }
    }

    // Отоюражение всех КС и их характеристик 
    int kss_count;
    kss_count = kss_data.size();
    if (kss_count == 0) {
        cout << "\nNo kss yet. Choose 2 for adding trumpet ... \n\n";
    }
    else
    {
        cout << "\nKS DATA \n";
        for (auto& im : kss_data) {
            cout << "Unique ks id: " << im.id << ", user ks id: " << im.user_id << ", ks name: " << im.ks_name << ", ks workshops number: " << im.number_of_workshops << ", ks working workshops: " << im.working_workshops << ", ks efficiency: " << im.efficiency << endl;
        }
    }

    cout << endl;

}


// Изменение трубы 
void trumpet_edit() {

    // Флажок на перезапись информации о трубе 
    int was_rewrite = 0;

    // Индекс элемента в массиве
    int index = 0;

    int trumpets_count;
    trumpets_count = trumpets_data.size();
    if (trumpets_count == 0) {
        cout << "\nNothing to change. Choose 1 for adding trumpet ... \n\n";
    }
    else {

        // Получение идентификатора изменяемой трубы
        cout << "Trumpets ids are: \n";
        for (auto& im : trumpets_data) {
            cout << im.id << endl;
        }
        cout << "Input trumpet id, which you want to change: ";

        int changing_id;
        cin >> changing_id;

        // Идаление существующей трубы с данным идентификатором и перезапись новой c прежним id
        for (auto& im : trumpets_data) {
            if (im.id == changing_id) {
                trumpets_data.erase(trumpets_data.begin() + index);
                was_rewrite = 1;
            }
            index = index + 1;
        }

        // В случае,если такая труба есть - перезаписываем ее
        if (was_rewrite == 1) {
            // Изменение трубы
            add_trumpet(changing_id);
        }
        else {
            cout << "There is no pipe with this ID \n" << endl;
        }
    }
}


// Измениеть КС
void ks_edit() {

    // Флажок на перезапись информации о трубе 
    int was_rewrite = 0;

    // Индекс элемента в массиве
    int index = 0;

    int kss_count;
    kss_count = kss_data.size();
    if (kss_count == 0) {
        cout << "\nNothing to change. Choose 2 for adding ks ... \n\n";
    }
    else {

        // Получение идентификатора изменяемой трубы
        cout << "KS ids are: \n";
        for (auto& im : kss_data) {
            cout << im.id << endl;
        }

        cout << "Input trumpet id, which you want to change: ";
        int changing_id;
        cin >> changing_id;

        // Идаление существующей трубы с данным идентификатором и перезапись новой c прежним id
        for (auto& im : kss_data) {
            if (im.id == changing_id) {
                kss_data.erase(kss_data.begin() + index);
                was_rewrite = 1;
            }
            index = index + 1;
        }

        // В случае,если такая труба есть - перезаписываем ее
        if (was_rewrite == 1) {
            // Изменение трубы
            add_ks(changing_id);
        }
        else {
            cout << "There is no pipe with this ID \n" << endl;
        }
    }
}


// Сохранение данных в текстовый файл
void save_to_txt() {

    ofstream output("output.txt");
    if (!output) {
        cout << "open error";
    }

    // Запись данных из вектора с трубами
    if (trumpets_data.size() == 0) {
        output << "No trumpets data in vector" << endl;
    }
    else {
        for (auto& im : trumpets_data) {
            output << "t " << im.id << " " << im.user_id << " " << im.length << " " << im.diametr << " " << im.is_repair << endl;
        }
    }

    // Запись данных из вектора с КС
    if (kss_data.size() == 0) {
        output << "No ks data in vector" << endl;
    }
    else {
        for (auto& im : kss_data) {
            output << "k " << im.id << " " << im.user_id << " " << im.ks_name << " " << im.number_of_workshops << " " << im.working_workshops << " " << im.efficiency << endl;
        }
    }

    cout << "\nData extraction to txt. Success ... \n" << endl;
}


// Чтение данных об установках 
void upload_data() {

    // Строка, которой присваиваем при чтение и разделитель в строке 
    string line;
    string delimetr = " ";

    ifstream file("input.txt");

    // Если файл открыт успешно - начинаем чтение
    if (file.is_open()) {
        while (getline(file, line)) {
            vector<string> v = split(line, delimetr);

            // Если из файла запись принадлежит трубам
            if (v[0] == "t") {
                trumpet current_trumpet;
                current_trumpet.id = stoi(v[1]);
                current_trumpet.user_id = v[2];
                current_trumpet.length = v[3];
                current_trumpet.diametr = v[4];
                current_trumpet.is_repair = v[5];
                trumpets_data.push_back(current_trumpet);
            };

            if (v[0] == "k") {
                ks current_ks;
                current_ks.id = stoi(v[1]);
                current_ks.user_id = v[2];
                current_ks.ks_name = v[3];
                current_ks.number_of_workshops = v[4];
                current_ks.working_workshops = v[5];
                current_ks.efficiency = v[6];
                kss_data.push_back(current_ks);
            }
        }
    }

    cout << "\nData was read. Success ... \n\n";
}


// Поиск по характеристикам труб
void trumpets_research() {

    string research_id;
    cout << "1 - For research by names, 2 - by repair parametr: ";
    cin >> research_id;

    if (research_id == "1") {
        string name;
        cout << "It wil be research by name. Input name for research: ";
        cin >> name;

        for (auto& im : trumpets_data) {
            if (im.user_id == name) {
                cout << "I found trumpet with id " << im.id;
                cout << "Unique trumpet id: " << im.id << ", user trumpet id: " << im.user_id << ", trumpet lenght: " << im.length << ", trumpet diametr: " << im.diametr << ", is trumpet repair: " << im.is_repair << "\n\n" << endl;
            }
        }
    }
    else if (research_id == "2") {
        string is_repair;
        cout << "It wil be research by repair parametr. Input repair parametr for research: ";
        cin >> is_repair;

        for (auto& im : trumpets_data) {
            if (im.is_repair == is_repair) {
                cout << "I found trumpet with id " << im.id;
                cout << "\nUnique trumpet id: " << im.id << ", user trumpet id: " << im.user_id << ", trumpet lenght: " << im.length << ", trumpet diametr: " << im.diametr << ", is trumpet repair: " << im.is_repair << "\n\n" << endl;
            }
        }
    }
    else {
        cout << "Unknown research parametr ... \n\n";
    }
}


// Поиск по характеристикам КС
void ks_research() {

    string research_id;
    cout << "1 - For research by names, 2 - by ks working workshops: ";
    cin >> research_id;

    if (research_id == "1") {
        string name;
        cout << "It wil be research by name. Input name for research: ";
        cin >> name;

        for (auto& im : kss_data) {
            if (im.user_id == name) {
                cout << "I found ks with id " << im.id;
                cout << "\nUnique ks id: " << im.id << ", user ks id: " << im.user_id << ", ks name: " << im.ks_name << ", ks workshops number: " << im.number_of_workshops << ", ks working workshops: " << im.working_workshops << ", ks efficiency: " << im.efficiency << "\n\n" << endl;
            }
        }
    }
    else if (research_id == "2") {
        string working;
        cout << "It wil be research by ks working workshops. Input working workshops parametr for research: ";
        cin >> working;

        for (auto& im : kss_data) {
            if (im.working_workshops == working) {
                cout << "I found ks with id " << im.id;
                cout << "Unique ks id: " << im.id << ", user ks id: " << im.user_id << ", ks name: " << im.ks_name << ", ks workshops number: " << im.number_of_workshops << ", ks working workshops: " << im.working_workshops << ", ks efficiency: " << im.efficiency << "\n\n" << endl;
            }
        }
    }
    else {
        cout << "Unknown research parametr ... \n\n";
    }

}


// Распределение фильтрации 
void search_filters() {

    string id;

    cout << "For research into trumpets input 1, for research into ks input 2: ";
    cin >> id;

    if (id == "1") {
        trumpets_research();
    }
    else if (id == "2") {
        ks_research();
    }
    else {
        cout << "Paramets are incorrect. Exit to main menu ... \n\n";
    }
}

int main()
{
    string action_id;

    do {

        show_functions();
        cout << "Insert your action: ";
        cin >> action_id;

        // Запуск действия согласно выбору пользователя

        if (action_id == "1") {
            add_trumpet(0);
        }

        else if (action_id == "2") {
            add_ks(0);
        }

        else if (action_id == "3") {
            show_all();
        }

        else if (action_id == "4") {
            trumpet_edit();
        }

        else if (action_id == "5") {
            ks_edit();
        }

        else if (action_id == "6") {
            save_to_txt();
        }

        else if (action_id == "7") {
            upload_data();
        }

        else if (action_id == "8") {
            search_filters();
        }

        else if (action_id == "0") {
            cout << "Program closed ... ";
        }

        else {
            cout << "\nUnknown input. Try it again ... \n\n";
        }

    } while (action_id != "0");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
