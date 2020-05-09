#include <iostream>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

/* Written by Zubchenko Konstantin (24.04.2020)
* As homework for "Algorithmes and data structures" lab №7
* Professor: Syromyatnikov Vladislav Petrovich
*
*
*/

class Node {
public:
    string name;
    string firstname;
    int num;

    Node * next;

    Node(){};

    Node(string name, string firstname) {
        this->firstname = firstname;
        this->name = name;
        this->next = nullptr;
    }
};


void add_First(list<Node> &a, Node n){
    n.num = a.size() + 1;
    if(!a.empty()) {
        for (Node node : a) {
            node.num++;
        }
        n.next = &a.front();
        a.push_front(n);
    } else {
        a.push_front(n);
    }
}

int getSize(list<Node> &a){
    return a.back().num;
}

void add_Last(list<Node> &a, Node n){
    n.num = getSize(a) + 1;
    a.push_back(n);
    a.back().next = nullptr;
}

void del_First(list<Node> &a){
    if(getSize(a) == 0)
        cout << "Нечего удалять";
    else {
        if (getSize(a) > 1) {
            a.pop_front();
            for (Node &node : a)
                node.num--;
        } else {
            a.pop_front();
        }
    }
}

void del_Last(list<Node> &a){
    if(getSize(a) == 0)
        cout << "Нечего удалять";
    else{
        a.pop_back();
        a.back().next = nullptr;
    }
}

int find_First(list<Node> &a, Node n){
    for(Node d : a) {
        if (d.firstname == n.firstname && d.name == n.name) {
            return d.num;
        }
    }
    return 0;
}

int find_All(list<Node> &a, Node n){
    int count = 0;
    for(Node d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            ++count;
        }
    }
    return count;
}

void change_First(list<Node> &a, Node &n, string name, string firstname){
    for(Node &d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
            return;
        }
    }
}

void change_All(list<Node> &a, Node n, string name, string firstname){
    for(Node &d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
        }
    }
}

int change_Number(list<Node> &a, string name, string firstname, int b){
    for(Node &d : a){
        if(b == d.num){
            d.name = name;
            d.firstname = firstname;
            return 1;
        }
    }
    return 0;
}

void print(list<Node> &a){
    for(Node &d : a){
        cout << d.name << " " << d.firstname << endl;
    }
}

Node get_Num(list<Node> &a, int b){
    for(Node &d : a){
        if(b == d.num){
            return d;
        }
    }
    return Node();
}

void swap(list<Node> &a, int first, int second){

    Node node1 = get_Num(a, first);
    Node node2 = get_Num(a, second);

    for(Node &d : a){
        if(d.num == first) {
            d.firstname = node2.firstname;
            d.name = node2.name;
        }
        if (d.num == second){
            d.firstname = node1.firstname;
            d.name = node1.name;
        }
    }
}



void testing(list<Node> &a){
    string name, firstname;

    for (int i = 0; i < 10; ++i) {
        cout << "Введите имя и фамилию человека \n";
        string tempname = "name" + to_string(i);
        string tempsur = "firstname" + to_string(i);
        cin >> tempname >> tempsur;
        Node n(tempname, tempsur);
        cout <<
             "Добавляем его в список на 1 позицию...\n";
        add_Last(a, n);
    }

    cout << "Выводим список для проверки..." << endl;
    print(a);



    /*//////////////////////////////////////////////////////////////*/
    //                  Эта херня не работает, хз почему
    //                        возможно указатели

    cout << "Меняем местами второй и предпоследний элемент..." << endl;
    swap(a, 4, 6);



    cout << "Удаляем первый элемент списка..." << endl;
    del_First(a);

    cout << "Удаляем последний элемент списка..." << endl;
    del_Last(a);

    cout << "Выводим список для проверки..." << endl;
    print(a);

    Node test("Константин", "Зубченко");
    cout << "Найдем элемент " << test.name << " " << test.firstname << endl;
    if(find_First(a, test) == 0){cout << "Такого элемента не существует\n";}else{
        cout << "Запрашиваемый элемент находится на позиции " << find_First(a, test) << endl;
    }

        cout << endl << endl;

    Node test2("Константин", "Зубченко");
    cout << "Найдем элемент " << test2.name << " " <<  test2.firstname << endl;
    if(find_First(a, test2) == 0){cout << "Такого элемента не существует\n";}else{
        cout << "Запрашиваемый элемент встречается " << find_All(a, test2) << " раз" << endl;
    }

    Node test3("Константин", "Зубченко");
    cout << "Найдем элемент " << test3.name << " " <<  test3.firstname << " и изменим его первое вхождение на Мамин Умничка" << endl;
    change_First(a, test3 ,"Мамин", "Умничка");

    cout << "Выводим список для проверки..." << endl;
    print(a);

    cout << endl;


    cout << "Введите номер элемента, который нужно изменить: \n";
    int num = 0;
    cin >> num;
    cout << "Найдем элемент под номером " << num << " и изменим вхождение по заданному номеру на Мамин Умничка" << endl;

    change_Number(a, "Мамин", "Умничка", num);

    cout << "Выводим список для проверки...\n" << endl;
    print(a);

    cout << endl;

    Node test4("Константин", "Зубченко");
    cout << "Найдем все элементы " << test4.name << " " << test4.firstname << "и изменим все вхождения этого элемента на Мамин "
                                                                       "Умничка" << endl;
    change_All(a, test4, "Мамин", "Умничка");
    cout << "Выводим список для проверки...\n" << endl;
    print(a);

    cout << endl;


}

int main() {
    setlocale(LC_ALL, "Ru");

    list<Node> a;

    testing(a);

}