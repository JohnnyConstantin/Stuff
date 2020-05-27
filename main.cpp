#include <iostream>
#include <list>

using namespace std;

/* Written by Zubchenko Konstantin (24.04.2020)
* As homework for "Algorithmes and data structures" lab №7
* Professor: Syromyatnikov Vladislav Petrovich
*
*       Антон 12 Сергей 24 Константин 18 Артем 80 Петр 1 Анна 28 Диана 69 Мария 65 Елена 20 Ангелина 10
*/
#include <iostream>
#include <string>
#include <locale>

using namespace std;

struct los
{
    string town;
    int inf;
    los* next=NULL;
    los* past=NULL;
};

struct ActionLos
{
    int SizeList;
    string town;
    int inf;
    los* first = NULL;
    los* last = NULL;
//создание ЛОС из 10-ти элементов
    void start() {
        SizeList = 10;
        cout << "Введите 10 элементов списка (Имя и число):" << endl;
        los* el = new los;
        cin >> el->town;
        cin >> el->inf;
        first = el;
        last = el;
        for (int i = 0; i < 9; i++) {
            cin >> town;
            cin >> inf;
            last = creat(last, town, inf);
        }
        menu();
    }

    los* creat(los* last, string town, int inf) {
        los* el = new los;
        el->town = town;
        el->inf = inf;
        el->past = last;
        last->next = el;
        return el;
    }

    void AddFirstElement() {
        cout << "Введите элемент (Имя и число), который нужно добавить в начало дека" << endl;
        los* el = new los;
        cin >> el->town;
        cin >> el->inf;
        el->next = first;
        first->past = el;
        first = el;
        SizeList++;
        cout << "Элемент успешно добавлен" << endl;
        menu1();
    }

    void AddLastElement() {
        cout << "Введите элемент (Имя и число), который нужно добавить в конец дека" << endl;
        los* el = new los;
        cin >> el->town;
        cin >> el->inf;
        el->past = last;
        last->next = el;
        last = el;
        SizeList++;
        cout << "Элемент успешно добавлен" << endl;
        menu1();
    }

    void AddElAfter() {
        cout << "Введите элемент, после которого должна произойти вставка (Имя и число): " << endl;
        cin >> town;
        cin >> inf;
        los* who = first;
        int flag = false;
        int copy = SizeList;
        while (copy > 0) {
            if (who->inf == inf && who->town == town) {
                cout << "Введите элемент, который необходимо вставить (Имя и число): " << endl;
                flag = true;
                copy = 0;
                los* el = new los;
                cin >> town;
                cin >> inf;
                el->inf = inf;
                el->town = town;
                el->next = who->next;
                if (who != last)who->next->past = el;
                else last = el;
                who->next = el;
                el->past = who;
                cout << "Элемент успешно добавлен" << endl;
                SizeList++;
            }
            copy--;
            who = who->next;
        }
        if (!flag) { cout << "Элемент найти не удалось." << endl; }
        menu1();
    }

    void AddElBefore() {
        cout << "Введите элемент, перед которым должна произойти вставка (Имя и число): " << endl;
        cin >> town;
        cin >> inf;
        los* who = first;
        los* past = NULL;
        int flag = false;
        int copy = SizeList;
        while (copy > 0) {
            if (who->inf == inf && who->town == town) {
                cout << "Введите элемент, который необходимо вставить (Имя и число): " << endl;
                flag = true;
                copy = 0;
                los* el = new los;
                cin >> town;
                cin >> inf;
                el->inf = inf;
                el->town = town;
                el->next = who;
                if (past != NULL) {
                    past->next = el;
                }
                else { first = el; }
                el->past = past;
                who->past = el;
                cout << "Элемент успешно добавлен" << endl;
                SizeList++;
            }
            copy--;
            past = who;
            who = who->next;
        }
        if (!flag) { cout << "Элемент найти не удалось." << endl; }
        menu1();
    }


    void FindElRtL() {
        cout << "Введите элемент, который необходимо найти:" << endl;
        cin >> town;
        cin >> inf;
        los* who = first;
        int pos = 0;
        int flag = false;
        int copy = 0;
        while (copy<10) {
            pos++;
            if (who->inf == inf && who->town == town) {
                flag = true;
                cout << "Позиция данного элемента в деке равна: " << pos << endl;
            }
            who = who->next;
            copy++;
        }
        if (!flag) { cout << "Элемента с такими данными в деке не существует" << endl; }
        menu1();
    }

    void SwapRtL(){
        cout << "Введите 1 элемент" << endl;
        cin >> town;
        string temp = town;
        cin >> inf;
        int temp1 = inf;
        los* who = first;

        cout << "Введите 2 элемент" << endl;
        cin >> town;
        cin >> inf;
        los* who1 = last;

        int pos = 0;
        int flag = false;
        int copy = 0;
        int copy1 = 10;

        while (copy<10 && copy1 > 0) {
            while (who->inf == temp1 && who->town == temp) {
                if(who1->inf == inf && who1->town == town){
                    who->inf = inf;
                    who->town = town;
                    who1->inf = temp1;
                    who1->town = temp;
                    cout << "Обмен прошел успешно" << endl;
                    menu1();
                    break;
                }
                who1 = who1->past;
                copy1--;
            }
            who = who->next;
            copy++;
        }
        menu1();
    }

    void menu() {
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout <<"Список команд:" << endl;
        cout <<"[1] - Добавить элемент" << endl;
        cout <<"[2] - Найти элемент (все вхождения)" << endl;
        cout << "[3] - Вывести дек на экран (проход справа-налево)" << endl;
        cout << "[4] - Поменять два элемента местами" << endl;
        cout << "[0] - Завершение программы" << endl << endl;
        menu1();
    }

    void menu1(){
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Новая команда: ";
        int choise;
        cin >> choise;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        switch (choise)
        {
            case 1:
                cout << "[1] - Добавление элемента в начало дека" << endl;
                cout << "[2] - Добавление элемента в конец дека" << endl;
                cout << "[3] - Добавление элемента в середину дека" << endl;
                cin >> choise;
                switch(choise) {
                    case 1:
                        AddFirstElement();
                        break;
                    case 2:
                        AddLastElement();
                        break;
                    case 3:
                        cout << "[1] - Добавление элемента в середину дека после заданного элемента" << endl;
                        cout << "[2] - Добавление элемента в середину дека перед заданным элементом" << endl;
                        cin >> choise;
                        switch (choise) {
                            case 1:
                                AddElAfter();
                                break;
                            case 2:
                                AddElBefore();
                                break;
                        }
                }
            case 2:
                FindElRtL();
                break;
            case 3:
                ConclusionRtL();
                break;
            case 4:
                cout << "[1] - Поменять два элемента местами(проход слева-направо)" << endl;
                cin >> choise;
                switch (choise){
                    case 1:
                        SwapRtL();
                        break;
                }
            case 0:
                cout << "Вы уверены, что хотите выйти из программы?"<<endl;
                cout << "[1] - Да" << endl;
                cout << "[2] - Нет" << endl;
                cin >> choise;
                switch(choise){
                    case 1:
                        cout << "Программа завершена"<<endl<<endl<<endl;
                        return;
                    case 2:
                        cout << "Не выходим из программы";
                        break;
                }
                break;
            default:
                cout << "Вы ввели неправильную команду!";
                menu1();
                break;
        }
    }

    void ConclusionRtL() {
        los* last= this->last;
        int copy = SizeList;
        while (copy > 0) {
            cout << last->town << " " << last->inf << endl;
            last = last->past;
            copy--;
        }
        menu1();
    }
};

int main()
{
    ActionLos* work = new ActionLos;
    work->start();
    return 0;
}