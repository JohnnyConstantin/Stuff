#include <iostream>
#include <list>

using namespace std;

/* Written by Zubchenko Konstantin (24.04.2020)
* As homework for "Algorithmes and data structures" lab №7
* Professor: Syromyatnikov Vladislav Petrovich
*
*       Антон 12 Сергей 24 Константин 18 Артем 80 Петр 1 Анна 28 Диана 69 Мария 65 Елена 20 Ангелина 10
*/

struct Los
{
    string name;
    int inf;
    Los* next = NULL;
};

struct ActionLos
{
    int SizeList;
    string name;
    int inf;
    Los* first = NULL;
    Los* last = NULL;

    void start()
    {
        SizeList = 10;
        cout << "Введите 10 элементов списка (имя и возраст):" << endl;
        Los* el = new Los;
        cin >> el->name;
        cin >> el->inf;
        first = el;
        last = el;
        for (int i = 0; i < 9; i++)
        {
            cin >> name;
            cin >> inf;
            last = creat(last, name, inf);
        }
        menu();
        menu1();
    }

    Los* creat(Los* last, string name, int inf)
    {
        Los* el = new Los;
        el->name = name;
        el->inf = inf;
        last->next = el;
        return el;
    }

    void AddToBeginning()
    {
        cout << "Введите элемент (имя и число), который нужно добавить в начало списка" << endl;
        Los* el = new Los;
        cin >> el->name;
        cin >> el->inf;
        el->next = first;
        first = el;
        SizeList++;
        menu1();
    }

    void AddToEnd()
    {
        cout << "Введите элемент (имя и число), который нужно добавить в конец списка" << endl;
        Los* el = new Los;
        cin >> el->name;
        cin >> el->inf;
        last->next = el;
        last = el;
        SizeList++;
        menu1();
    }

    void AddElementAfter()
    {
        cout << "Введите элемент, после которого должна произойти вставка (имя и число): " << endl;
        cin >> name;
        cin >> inf;
        cout << "Введите элемент, который необходимо вставить (имя и число): " << endl;
        Los* who = first;
        int flag = false;
        int copy = SizeList;
        while (copy > 0) {
            if (who->inf == inf && who->name == name)
            {
                flag = true;
                copy = 0;
                Los* el = new Los;
                cin >> name;
                cin >> inf;
                el->inf = inf;
                el->name = name;
                el->next = who->next;
                who->next = el;
                cout << "Элемент успешно добавлен" << endl;
                SizeList++;
            }
            copy--;
            who = who->next;
        }
        if (!flag) { cout << "Элемент найти не удалось." << endl; }
        menu1();
    }

    void AddElementBefore()
    {
        cout << "Введите элемент, перед которым должна произойти вставка (имя и число): " << endl;
        cin >> name;
        cin >> inf;
        cout << "Введите элемент, который необходимо вставить (имя и число): " << endl;
        Los* who = first;
        Los* past = NULL;
        int flag = false;
        int copy = SizeList;
        while (copy > 0) {
            if (who->inf == inf && who->name == name) {
                flag = true;
                copy = 0;
                Los* el = new Los;
                cin >> name;
                cin >> inf;
                el->inf = inf;
                el->name = name;
                el->next = who;
                if (past != NULL) {
                    past->next = el;
                }
                else { first = el; }
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

    void DeleteFromBeginning()
    {
        cout << "Первый элемент удалён" << endl;
        Los* temporary = first;
        first = first->next;
        delete temporary;
        SizeList--;
        menu1();
    }

    void DeleteFromEnd()
    {
        cout << "Последний элемент удалён" << endl;
        int copy = SizeList;
        Los* who = first;
        while (copy > 0)
        {
            if (who->next == last) {
                last = who;
                who = who->next;
                delete who;
            }
            copy--;
        }
        SizeList--;
        menu1();
    }

    bool DeleteElement1(string name, int inf, int n)
    {
        Los* who = first;
        Los* past = NULL;
        int copy = SizeList;
        while (copy > 0)
        {
            if (who->inf == inf && who->name == name) {
                if (past != NULL) {
                    past->next = who->next;
                }
                else { first = who->next; }
                SizeList--;
                delete who;
                if (n == 0)DeleteElement1(name, inf, n);
                return true;
            }
            past = who;
            who = who->next;
            copy--;
        }
        return false;
    }

    void DeleteElement(int n)
    {
        cout << "Введите элемент, который необходимо удалить:" << endl;
        cin >> name;
        cin >> inf;
        bool flag = DeleteElement1(name, inf, n);
        if (!flag) {
            cout << "Искомый элемент не найден" << endl;
        }    else if (n == 1) cout << "Искомый элемент удалён" << endl;
        else cout << "Все искомые элементы удалены" << endl;
        menu1();
    }

    void FindElement(int n)
    {
        cout << "Введите элемент, который необходимо найти:" << endl;
        cin >> name;
        cin >> inf;
        Los* who = first;
        int pos = 0;
        int flag = false;
        int copy = SizeList;
        while (copy > 0) {
            pos++;
            if (who->inf == inf && who->name == name && n == 1) {
                copy = 0;
                flag = true;
                cout << "Позиция данного элемента в ЛОС равна " << pos << endl;
            }
            if (who->inf == inf && who->name == name && n == 0) {
                if (!flag) {
                    cout << "Данный элемент в ЛОС стоит на позициях: " << endl << pos << endl;
                }
                else cout << pos << endl;
                flag = true;
            }
            who = who->next;
            copy--;
        }
        if (!flag) { cout << "Элемента с такими данными в ЛОС не существует" << endl; }
        menu1();
    }

    void ChangeElement(int n)
    {
        cout << "Введите значение, которое желаете изменить (имя и число)" << endl;
        cin >> name;
        cin >> inf;
        string name1;
        int inf1;
        bool flag = false;
        cout << "Введите значение, на которое желаете изменить (имя и число)" << endl;
        cin >> name1;
        cin >> inf1;
        Los* who = first;
        int copy = SizeList;
        while (copy > 0) {
            if (who->name == name && who->inf == inf) {
                who->name = name1;
                who->inf = inf1;
                if (n == 1) {
                    copy = 0;
                }
                flag = true;
            }
            who = who->next;
            copy--;
        }
        if (flag)cout << "Операция прошла успешно" << endl;
        else cout << "Введённый вами элемент не был найден" << endl;
        menu1();
    }

    void ChangePositionedElement()
    {
        cout << "Введите номер элемента, значение которого желаете изменить" << endl;
        int n, i = 1;
        cin >> n;
        if (n > SizeList) { cout << "Размер ЛОС меньше указанного вами значения!" << endl; }
        else {
            cout << "Введите значение, на которое желаете изменить (имя и число)" << endl;
            Los* who = first;
            while (i != n) {
                who = who->next;
                i++;
            }
            cin >> who->name;
            cin >> who->inf;
            cout << "Значение успешно изменено" << endl;
        }
        menu1();
    }

    void SwapElements(int n1, int n2) {
        bool flag = false;
        if (n2 - n1 == 1) flag = true;
        Los *past1 = new Los;
        Los *past2 = new Los;
        Los *next1 = new Los;
        Los *next2 = new Los;
        Los *el1 = new Los;
        Los *el2 = new Los;
        Los *who = first;
        int copy = SizeList;
        while (copy > 0) {
            n1--;
            n2--;
            if (n1 == 0) {
                el1 = who;
                next1 = who->next;
            } else if (n1 > 0)past1 = who;
            if (n2 == 0) {
                el2 = who;
                next2 = who->next;
            } else if (n2 > 0)past2 = who;
            who = who->next;
            copy--;
        }
        if (el1 == first && el2 == last) {
            first = el2;
            last = el1;
        } else if (el1 == first)first = el2;
        else if (el2 == last)last = el1;
        past1->next = el2;
        el1->next = next2;
        if (flag)el2->next = el1;
        else {
            past2->next = el1;
            el2->next = next1;
        }
    }

    void Replace() {
        cout << "Введите номера элементов, которые хотите поменять местами" << endl;
        int n1, n2;
        cin >> n1;
        cin >> n2;
        if (n1 > SizeList || n2 > SizeList) { cout << "Величина ЛОС короче, нежели одно из ваших значений" << endl; }
        else {
            if (n1 > n2) {
                int n = n2;
                n2 = n1;
                n1 = n;
            }
            SwapElements(n1, n2);
            cout << "Замена выполнена успешно" << endl;
        }
        menu1();
    }

    void LosLength() {
        cout << "Длина ЛОС равна " << SizeList << endl;
        menu1();
    }

    void DeleteLos() {
        while (SizeList > 0) {
            Los* who = first;
            first = first->next;
            delete who;
            SizeList--;
        }
        cout << "Весь ЛОС удалён" << endl;
        menu1();
    }

    void OutLos() {
        setlocale(LC_ALL, "Russian");
        Los* first = this->first;
        int copy = SizeList;
        while (SizeList > 0) {
            cout << first->name << " " << first->inf << endl;
            first = first->next;
            SizeList--;
        }
        SizeList = copy;
        menu1();
    }

    void menu() {
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Список команд:" << endl;
        cout << "[1] - Добавить элемент в список" << endl;
        cout << "[2] - Удалить элемент из списка" << endl;
        cout << "[3] - Найти элемент" << endl;
        cout << "[4] - Изменить элемент" << endl;
        cout << "[5] - Поменять два элемента местами" << endl;
        cout << "[6] - Вычислить длину ЛОС" << endl;
        cout << "[7] - Вывести (распечатать) ЛОС на экран" << endl;
        cout << "[8] - Удалить ЛОС" << endl;
        cout << "[0] - Завершение программы" << endl << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        menu1();
    }

    void menu1() {
        cout << "Введите команду: ";
        int choice;
        cin >> choice;
        cout
                << "-------------------------------------------------------------------------------------------------------------------"
                << endl;
        switch (choice) {
            case 1:
                cout << "[1] - Добавить элемент в начало списка" << endl;
                cout << "[2] - Добавить элемент в конец списка" << endl;
                cout << "[3] - Добавить элемент в середину списка" << endl;
                int choice1;
                cin >> choice1;
                cout
                        << "-------------------------------------------------------------------------------------------------------------------"
                        << endl;
                switch (choice1) {
                    case 1:
                        AddToBeginning();
                        break;
                    case 2:
                        AddToEnd();
                        break;
                    case 3:
                        cout << "[1] - Добавить элемент в середину списка после заданного элемента" << endl;
                        cout << "[2] - Добавить элемент в середину списка перед заданным элементом" << endl;
                        int choice2;
                        cin >> choice2;
                        cout
                                << "-------------------------------------------------------------------------------------------------------------------"
                                << endl;
                        switch (choice2) {
                            case 1:
                                AddElementAfter();
                                break;
                            case 2:
                                AddElementBefore();
                                break;
                        }
                }
                break;
            case 2:
                cout << "[1] - Удалить первый элемент" << endl;
                cout << "[2] - Удалить последний элемент" << endl;
                cout << "[3] - Удалить искомый элемет" << endl;
                int choice5;
                cin >> choice5;
                cout
                        << "-------------------------------------------------------------------------------------------------------------------"
                        << endl;
                switch (choice5) {
                    case 1:
                        DeleteFromBeginning();;
                        break;
                    case 2:
                        DeleteFromEnd();
                        break;
                    case 3:
                        cout << "[1] - Удалить искомый элемет (первое вхождение)" << endl;
                        cout << "[2] - Удалить искомый элемет (все вхождения)" << endl;
                        int choice1;
                        cin >> choice1;
                        cout
                                << "-------------------------------------------------------------------------------------------------------------------"
                                << endl;
                        switch (choice1) {
                            case 1:
                                DeleteElement(1);
                                break;
                            case 2:
                                DeleteElement(0);
                                break;
                        }
                }
                        break;
                    case 3:
                        cout << "[1] - Найти элемент (первое вхождение)" << endl;
                        cout << "[2] - Найти элемент (все вхождения)" << endl;
                        cout << "Введите команду:";
                        int choice4;
                        cin >> choice4;
                        cout
                                << "-------------------------------------------------------------------------------------------------------------------"
                                << endl;
                        switch (choice4) {
                            case 1:
                                FindElement(1);
                                break;
                            case 2:
                                FindElement(0);
                                break;
                        }
                        break;
                    case 4:
                        cout << "[1] - Изменить элемент (первое вхождение)" << endl;
                        cout << "[2] - Изменить элемент (все вхождения)" << endl;
                        cout << "[3] - Изменить элемент (по порядковому номеру)" << endl;
                        cout << "Введите команду:";
                        int choice3;
                        cin >> choice3;
                        cout << "-------------------------------------------------------------------------------------------------------------------"
                                << endl;
                        switch (choice3) {
                            case 1:
                                ChangeElement(1);
                                break;
                            case 2:
                                ChangeElement(0);
                                break;
                            case 3:
                                ChangePositionedElement();
                                break;
                        }
                        break;
                    case 5:
                        Replace();
                        break;
                    case 6:
                        LosLength();
                        break;
                    case 7:
                        OutLos();
                        break;
                    case 8:
                        DeleteLos();
                        break;
                    case 0:
                        cout << "Вы уверены, что хотите выйти из программы?"<< endl;
                        cout << "[1] Да"<<endl;
                        cout << "[2] Нет"<<endl;
                        int choice6;
                        cin >> choice6;
                cout << "-------------------------------------------------------------------------------------------------------------------"
                     << endl;
                switch (choice6) {
                    case 1:
                        return;
                    case 2:
                        break;
                    default:
                        cout << "Несуществующая команда!";
                        break;
                }
            }
        }
};

int main()
{
    ActionLos* work = new ActionLos;
    work->start();
    return 0;
}