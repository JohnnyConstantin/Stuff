

//Программа написана Зубченко К.В., студент 2 курса РТУ МИРЭА



#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
using namespace std;

struct Node //описание узла списка
{
    string data; //информационное поле
    Node *next; //указатель на следующий элемент
};

struct QueueLos //описание очереди
{
    int size; //счетчик размера очереди
    Node *first; //указатель на начало очереди
    Node *last; //указатель на конец очереди
};

void Creation(QueueLos *Q) //создание очереди
{
    Q->first=new Node;
    Q->first->next=NULL;
    Q->last=Q->first;
    Q->size=0;
}

bool Full(QueueLos *Q) //проверка очереди на пустоту
{
    return Q->first == Q->last;
}

string Top(QueueLos *Q) //вывод начального элемента
{
    return Q->first->next->data;
}

void Add(QueueLos *Q) //добавление элемента
{
    if(Q->size>=5){cout<<"Очередь переполнена, добавление элемента невозможно\n";} else {
        string city;
        cout << "\nВведите название города\n";
        cin >> city;
        Q->last->next = new Node;
        Q->last = Q->last->next;
        Q->last->data = city; //добавление элемента в конец
        Q->last->next = NULL; //обнуление указателя на следующий элемент
        Q->size++;
        cout << "\nГород успешно добавлен в очередь\n\n";
    }
}
void Delete(QueueLos *Q) //удаление элемента
{
    if (Q->size!=0){
    Q->first=Q->first->next; //смещение указателя
    Q->size--;
    cout<<"\nГород удален успешно\n\n";} else {
        cout<< "Очередь пуста! Нечего удалять\n";
    }
}

int Size(QueueLos *Q) //размер очереди
{ return Q->size; }


void Print(QueueLos Q){//вывод очереди
    for(int i =0; i < Q.size; i++) {
        cout << Q.first->next->data << endl;
        Q.first=Q.first->next;
    }
    cout << endl;
    cout << "---------------------" << endl;
}





template <typename T>
class Queue
{
private:
    T* p; // динамический массив
    int count; // количество элементов в очереди

public:
// конструктор
    Queue()
    {
        count = 0; // очередь пустая
    }

// добавить элемент в очередь
    void push(T item)
    {
        T* p2;
        p2 = p;
        try {
// попытка выделить новый фрагмент памяти для p, но на 1 больше
            p = new T[count + 1];
            for (int i = 0; i < count; i++)
                p[i] = p2[i];
            p[count] = item;
            count++;
// освободить предварительно выделенную память
            if (count > 1)
                delete[] p2;
        }
        catch (bad_alloc e)
        {
// если память не выделена
            cout << e.what() << endl; // вывести сообщение об ошибке

// вернуть старый указатель на p
            p = p2;
        }
    }

// вытянуть первый элемент из очереди
    T pop()
    {
        if (count == 0)
            return 0;
        T item;
        item = p[0];
// сформировать новый участок памяти, который на 1 меньше
        try {
            T* p2;
// попытка выделить память
            p2 = new T[count - 1];
            count--; // уменьшить количество элементов в очереди
            for (int i = 0; i < count; i++)
                p2[i] = p[i + 1]; // копируются все кроме первого элемента

// освободить участок, на который указывает p
            if (count > 0)
                delete[] p;

// перенаправить p на p2
            p = p2;

// вернуть item
            return item;
        }
        catch (bad_alloc e)
        {
// если память не выделилась, то вернуть 0
            cout << e.what() << endl;
            return 0;
        }
    }

// деструктор
    ~Queue()
    {
        if (count > 0)
            delete[] p;
    }

// взять первый элемент из очереди не вытягивая его
    T GetItem()
    {
        if (count > 0)
            return p[0];
        else
            return 0;
    }

// проверка существования элементов в очереди
    bool IsEmpty()
    {
        return count == 0;
    }

// количество элементов в очереди
    int GetN()
    {
        return count;
    }

// метод, выводящий очередь
    void print(const char* objName)
    {
        for (int i = 0; i < count; i++)
            cout << p[i] << "\t";
        cout << endl;
        cout << "---------------------" << endl;
    }


    T popfromback()
    {
        if (count == 0)
            return 0;
        T item;
        item = p[count-1];
// сформировать новый участок памяти, который на 1 меньше
        try {
            T* p2;
// попытка выделить память
            p2 = new T[count - 1];
            count--; // уменьшить количество элементов в очереди
            for (int i = 0; i < count-1; i++)
                p2[i] = p[i]; // копируются все кроме первого элемента

// освободить участок, на который указывает p
            if (count > 0)
                delete[] p;

// перенаправить p на p2
            p = p2;

// вернуть item
            return item;
        }
        catch (bad_alloc e)
        {
// если память не выделилась, то вернуть 0
            cout << e.what() << endl;
            return 0;
        }
    }

double back(){
    return p[count-1];
}

// возвращает  элемент очереди
    double front(){
        return p[0];
}


};



bool isOperand(char c)
{
    return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
    Queue<double> Queue;

    for (int j = exprsn.length() - 1; j >= 0; j--) {
        if (isOperand(exprsn[j]))
            Queue.push(exprsn[j] - '0');//Переводим char в число

        else {//При обнаружении оператора - достаем последние два числа из стэка
            double o1 = Queue.back();
            Queue.popfromback();
            double o2 = Queue.back();
            Queue.popfromback();
            //Выбор действия на основе оператора
            switch (exprsn[j]) {
                case ' ':
                    break;
                case '+':
                    Queue.push(o1 + o2);
                    break;
                case '-':
                    Queue.push(o1 - o2);
                    break;
                case '*':
                    Queue.push(o1 * o2);
                    break;
                case '/':
                    Queue.push(o1 / o2);
                    break;
            }
        }
    }

    return Queue.front();
}

int main() {
    char kindOfQueue;
    while (true) {
        Queue<string> Q1;
        int exit=0;
        cout << "Выберите способ реализации очереди\n"
                "1. Очередь на базе однонаправленного динамического списка\n"
                "2. Очередь на базе динамического массива\n"
                "3. Калькулятор\n";
        cin >> kindOfQueue;
        switch (kindOfQueue) {
            case '1':
                QueueLos Q;
                Creation(&Q);
                char number;
                cout
                        << "Добро пожаловать в программу-реализацию очереди на базе однонаправленного динамического списка.\n";
                while (exit==0) {
                    cout
                            << "Пожалуйста, выберите желаемое действие с очередью ( максимальный размер очереди - 5 объектов )\n"
                            "1. Добавить элемент\n"
                            "2. Удалить элемент\n"
                            "3. Вывести верхний элемент\n"
                            "4. Узнать размер очереди\n"
                            "5. Вывести очередь\n"
                            "0. Выйти\n\n";
                    cout << "Номер команды > ";
                    cin >> number;
                    switch (number) {
                        case '1':
                            Add(&Q);
                            break;
                        case '2':
                            if (Full(&Q)) cout << endl <<"Очередь пуста\n\n";
                            else Delete(&Q);
                            break;
                        case '3':
                            if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
                            else { cout << "\nНачальный элемент: " << Top(&Q) << "\n\n"; }
                            break;
                        case '4':
                            if (Full(&Q)) cout << endl << "Очередь пуста\n\n";
                            else cout << "\nРазмер очереди: " << Size(&Q) << "\n\n";
                            break;
                        case '5':
                            Print(Q);
                            break;
                        case '0':
                            cout << "\nВы действительно хотите выйти?\n\t1. Да\n\t2. Нет\n";
                            char choice4;
                            cin >> choice4;
                            switch (choice4) {
                                case '1':
                                    exit = 1;
                                case '2':
                                    break;
                            }
                            break;
                    }
                }
                break;
            case '2':
                char choice;
                cout << "Добро пожаловать в программу-реализацию очереди на базе динамического массива.\n";
                while (exit==0) {
                    cout
                            << "Пожалуйста, выберите желаемое действие с очередью ( максимальный размер очереди - 5 объектов )\n"
                               "1. Добавить элемент в очередь\n"
                               "2. Вывод первого элемента очереди\n"
                               "3. Проверка очереди\n"
                               "4. Вывести очередь на экран\n"
                               "5. Выйти из программы\n\n";
                            cout << "Номер команды > ";
                    string city, poppedItem, firstItem;
                    cin >> choice;
                    switch (choice) {
                        case '1':
                            cout << "\nВведите город, который хотите добавить в очередь\n";
                            cin >> city;
                            if (Q1.GetN() >= 5) {
                                cout << "\nОчередь переполнена\nЭлемент не может быть добавлен\n";
                            } else {
                                Q1.push(city);
                                cout << "\nЭлемент добавлен успешно\n\n";
                            }
                            break;
                        case '2':
                            cout << "\t1. Вывод первого элемента с его удалением\n"
                                    "\t2. Вывод первого элемента без его удаления\n";
                            char choice2;
                            cin >> choice2;
                            switch (choice2) {
                                case '1':
                                    if (Q1.GetN() != 0) {
                                        poppedItem = Q1.GetItem();
                                        cout << "\nПервый элемент очереди = " << poppedItem << endl << endl;
                                        Q1.pop();
                                    } else {
                                        cout << "\nОчередь пустая! Нечего выводить\n";
                                    }
                                    break;
                                case '2':
                                    if (Q1.GetN() != 0) {
                                        firstItem = Q1.GetItem();
                                        cout << "\nПервый элемент очереди = " << firstItem << endl << endl;
                                    } else {
                                        cout << "\nОчередь пустая! Нечего выводить\n";
                                    }
                                    break;
                            }
                            break;
                        case '3':
                            cout << "\t1. Проверить очередь на пустоту\n"
                                    "\t2. Проверить очередь на переполнение\n";
                            char choice3;
                            cin >> choice3;
                            switch (choice3) {
                                case '1':
                                    if (Q1.IsEmpty())
                                        cout << "\nОчередь пустая\n\n";
                                    else
                                        cout << "\nОчередь не пустая\n\n";
                                    break;
                                case '2':
                                    if (Q1.GetN() >= 5)
                                        cout << "\nОчередь переполнена\n\n";
                                    else
                                        cout << "\nОчередь не переполнена\n\n";
                                    break;
                            }
                            break;
                        case '4':
                            Q1.print("Q1");
                            break;
                        case '5':
                            cout << "\nВы действительно хотите выйти?\n\t1. Да\n\t2. Нет\n";
                            char choice4;
                            cin >> choice4;
                            switch (choice4) {
                                case '1':
                                    exit = 1;
                                case '2':
                                    break;
                            }
                            break;
                        default:
                            cout << "Что-то пошло не так, сделайте выбор еще раз\n";
                            break;
                    }
                } break;
            case '3':
                    string exprsn;
                    cout << "Введите выражение: ";
                    cin >> exprsn;
                    cout << "Результат: "<< evaluatePrefix(exprsn) << endl;
                return 0;
        }
    }
}
