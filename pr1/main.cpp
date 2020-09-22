//Программа написано Зубченко К.В., студент 2 курса РТУ МИРЭА
#include <iostream>
#include <new>
using namespace std;

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

// операторная функция operator=(),
// реализует присваивание объектов типа Queue
    Queue& operator=(const Queue& obj)
    {
        T* p2; // указатель на дополнительную память

        try {
// попытка выделить новый участок памяти для p2
            p2 = new T[obj.count];

// если память выделена успешно,
// можно освобождать предварительно выделенную память для p
            if (count > 0)
                delete[] p;

// скопировать obj в текущий объект
            p = p2; // перенаправить p на p2
            count = obj.count;

// заполнить значениями
            for (int i = 0; i < count; i++)
                p[i] = obj.p[i];
        }
        catch (bad_alloc e)
        {
// если память не выделилась, то вывести соответствующее сообщение
            cout << e.what() << endl;
        }
        return *this; // вернуть текущий объект
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
        cout << "Object: " << objName << endl;
        for (int i = 0; i < count; i++)
            cout << p[i] << "\t";
        cout << endl;
        cout << "---------------------" << endl;
    }
};

int main()
{
    Queue<string> Q1;
    cout << "Добро пожаловать в программу-реализацию очереди.\n";
    while (true) {
        cout << "Пожалуйста, выберите желаемое действие с очередью ( максимальный размер очереди - 5 объектов )\n"
                "1. Добавить элемент в очередь\n"
                "2. Вывод первого элемента очереди\n"
                "3. Проверка очереди\n"
                "4. Вывести очередь на экран\n"
                "5. Выйти из программы\n";
        char choice;
        string city,poppedItem,firstItem;
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "Введите город, который хотите добавить в очередь\n";
                cin >> city;
                if(Q1.GetN() >= 5){
                    cout << "Очередь переполнена\nЭлемент не может быть добавлен\n";
                } else {
                    Q1.push(city);
                    cout << "Элемент добавлен успешно\n";
                }
                break;
            case '2':
                cout << "\t1. Вывод первого элемента с его удалением\n"
                        "\t2. Вывод первого элемента без его удаления\n";
                char choice2;
                cin >> choice2;
                switch (choice2) {
                    case '1':
                        if(Q1.GetN() != 0) {
                            poppedItem = Q1.GetItem();
                            cout << "Первый элемент очереди = " << poppedItem << endl;
                            Q1.pop();
                        } else {
                            cout << "Очередь пустая! Нечего выводить\n";
                        }
                        break;
                    case '2':
                        if(Q1.GetN() != 0) {
                            firstItem = Q1.GetItem();
                            cout << "Первый элемент очереди = " << firstItem << endl;
                        } else {
                            cout << "Очередь пустая! Нечего выводить\n";
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
                            cout << "Очередь пустая\n";
                        else
                            cout << "Очередь не пустая\n";
                        break;
                    case '2':
                        if(Q1.GetN() >= 5)
                            cout << "Очередь переполнена\n";
                        else
                            cout << "Очередь не переполнена\n";
                        break;
                }
                break;
            case '4':
                Q1.print("Q1");
                break;
            case '5':
                cout << "Вы действительно хотите выйти?\n\t1. Да\n\t2. Нет\n";
                char choice4;
                cin >> choice4;
                switch (choice4){
                    case '1':
                        return 0;
                    case '2':
                        break;
                }
                break;
            default:
                cout << "Что-то пошло не так, сделайте выбор еще раз\n";
                break;
        }
    }
}
