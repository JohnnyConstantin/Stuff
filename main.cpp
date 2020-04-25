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
* Падает в main() на функции add_First(); В самой функции объект записывается в связный список, но после выхода
* из функции связный список очищается и все изменения пропадают. Предположительно проблема в памяти/указателях
* либо в конструкторе
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
    n.num = 1;
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
            for (Node node : a)
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

int  find_First(list<Node> &a, Node n){
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

void change_First(list<Node> &a, Node n, string name, string firstname){
    for(Node d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
            break;
        }
    }
}

void change_All(list<Node> &a, Node n, string name, string firstname){
    for(Node d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
        }
    }
}

void change_Number(list<Node> &a, string name, string firstname, int b){
    for(Node d : a){
        if(b == d.num){
            d.name = name;
            d.firstname = firstname;
        }
    }
}

void print(list<Node> &a){
    for(Node d : a){
        cout << d.name << " " << d.firstname << endl;
    }
}

Node get_Num(list<Node> &a, int b){
    for(Node d : a){
        if(b == d.num){
            return d;
        }
    }
    return Node();
}

void swap(list<Node> &a, int first, int second){

    Node node1 = get_Num(a, first);
    Node node2 = get_Num(a, second);

    if(first == 0){
        del_First(a);
        del_Last(a);
        add_First(a, node2);
        add_Last(a, node1);
        return;
    } else if(second == 0){
        del_First(a);
        del_Last(a);
        add_First(a, node1);
        add_Last(a, node2);
        return;
    }

    for(Node d : *&a){
        if(d.num == node1.num - 1)
            d.next = get_Num(a, second - 1).next;
        if(d.num == node2.num - 1)
            d.next = get_Num(a, first - 1).next;
        if(d.num == node1.num)
            d.next = node2.next;
        if(d.num == node2.num)
            d.next = node1.next;
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
        add_First(a, n);
    }

    cout << "Выводим список для проверки..." << endl;
    print(a);

    cout << "Меняем местами второй и предпоследний элемент..." << endl;
    swap(a, 4, 6);

    cout << "Выводим список для проверки..." << endl;
    print(a);

}

int main() {
    setlocale(LC_ALL, "Ru");

    list<Node> a;

    testing(a);

}