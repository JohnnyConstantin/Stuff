#include <iostream>
#include <list>

using namespace std;

/* Written by Zubchenko Konstantin (24.04.2020)
* As homework for "Algorithmes and data structures" lab №7
* Professor: Syromyatnikov Vladislav Petrovich
*
*           й ц ц у у к к е Константин Зубченко Константин Зубченко н г Константин Зубченко г ш о л
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

//Добавить в начало
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

//Вычислить длину списка
int getSize(list<Node> &a){
    return a.back().num;
}

//Добавить в конец
void add_Last(list<Node> &a, Node n){
    n.num = getSize(a) + 1;
    a.push_back(n);
    a.back().next = nullptr;
}

//Удалить первый элемент
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

//Удалить последний элемент
void del_Last(list<Node> &a){
    if(getSize(a) == 0)
        cout << "Нечего удалять";
    else{
        a.pop_back();
        a.back().next = nullptr;
    }
}

//Найти первое вхождение
int find_First(list<Node> &a, Node n){
    for(Node d : a) {
        if (d.firstname == n.firstname && d.name == n.name) {
            return d.num;
        }
    }
    return 0;
}

//Найти все вхождения
int find_All(list<Node> &a, Node n){
    int count = 0;
    for(Node d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            ++count;
        }
    }
    return count;
}

//Изменить первое вхождение
void change_First(list<Node> &a, Node &n, string name, string firstname){
    for(Node &d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
            return;
        }
    }
}

//Изменить все вхождения
void change_All(list<Node> &a, Node n, string name, string firstname){
    for(Node &d : a){
        if(d.firstname == n.firstname && d.name == n.name){
            d.name = name;
            d.firstname = firstname;
        }
    }
}

//Изменить по порядковому номеру
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

//Вывести список
void print(list<Node> &a){
    for(Node &d : a){
        cout << d.name << " " << d.firstname << endl;
    }
}

//Получить элемент по порядковому номеру
Node get_Num(list<Node> &a, int b){
    for(Node &d : a){
        if(b == d.num){
            return d;
        }
    }
    return Node();
}


//Поменять два элемента местами
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
//Добавить в середину после
void addPrev(list<Node> &a, int b, Node n){
    list<Node> g;
    for(int i = a.size(); i > b; --i){
        add_Last(g, get_Num(a, i));
        del_Last(a);
    }

    add_Last(a, n);
    for(int h = g.size(); h > 0; h--){
        add_Last(a, get_Num(g,h));
    }

}

//Добавить в середину перед
void addForw(list<Node> &a, int j, Node n){
    list<Node> y;
    int m = 0;
    for(int i = a.size(); i > j; --i){
        add_Last(y, get_Num(a, i));
        del_Last(a);
        m++;
    }

    add_Last(a, n);
    for(int t = m; t > 0; t--){
        add_Last(a, get_Num(y,t));
    }
}


void testing(list<Node> &a){

    for (int i = 0; i < 10; ++i) {
        cout << "Введите имя и фамилию человека \n";
        string tempname = "name" + to_string(i);
        string tempsur = "firstname" + to_string(i);
        cin >> tempname >> tempsur;
        Node n(tempname, tempsur);
        cout <<
             "Добавляем его в список на последнюю позицию...\n";
        add_Last(a, n);
    }

    cout << "Выводим список для проверки..." << endl;
    print(a);

    Node test5("Артем", "Артемко");
    int k = 5;
    cout << "Добавим Артем Артемко в середину списка " << "после " << k << " позиции" << endl;
    addPrev(a, k, test5);
    cout << "Выводим список для проверки..." << endl;
    print(a);

    cout << endl;


    Node test7("Артемис", "Артемкис");
    int k1 = 8;
    cout << "Добавим Артем Артемко в середину списка " << "после " << k1 << " позиции" << endl;
    addForw(a, k1, test7);
    cout << "Выводим список для проверки..." << endl;
    print(a);

    cout << endl;


    int first = 4;
    int second = 6;
    cout << "Меняем местами " << first <<  " и " << second << " элемент..." << endl;
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