#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

/*    Written by Zubchenko Konstantin (7.03.2020)
 *    As homework for "Algorithmes and data structures" classes
 *    Professor: Syromyatnikov Vladislav Petrovich
 *
 *
 *    Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
 *    Ошибки возможны при некорректном вводе данных.
 */

unsigned long long C = 0, D = 0, N;
unsigned long t;

class Test{

public:
    static vector<int> tests(vector<int> test){
        //В предусловии ожидается вектор целочисленных значений
        cout << "Введите через пробел 10 целочисленных элементов тестового массива" << endl;
        int m;
        for (int i = 0;i < 10;i++)
        {
            cin >> m;
            test.push_back(m);
        }
        return test;
        //В постусловии ожидается вектор целочисленных значений
    };
};

class Binary{
public:
     static void search(unsigned long long n, int key){
         t = clock();
         int arr[n]; // создали массив на n элементов
         srand(time(NULL));
         for (unsigned long long i = 0; i < n; i++) {
             arr[i] = rand()%100000; // считываем элементы массива
         }

         sort (arr, arr + n); // сортируем с помощью функции sort (быстрая сортировка)

         bool flag = false;
         unsigned long long l = 0; // левая граница
         unsigned long long r = n-1; // правая граница
         unsigned long long mid;

         while (l <= r && !flag) {
             mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

             if (arr[mid] == key) flag = true; //проверяем ключ со серединным элементом
             if (arr[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
             else l = mid + 1;
         }
        t = clock() - t;
         if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid;
         else cout << "\nИзвините, но такого элемента в массиве нет";
     }
     static void result_search(){

         N = 400000;
         cout<<"====================================\n";
         int key; // создали переменную в которой будет находиться ключ
         cout << "Количество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         Binary::search(N, key);

        cout<<"\n====================================";
         N += 100000;
         cout << "\n\nКоличество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         Binary::search(N, key);
         cout<<"\n====================================";
         N += 100000;
         cout << "\n\nКоличество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         Binary::search(N, key);
     }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    int select;
    cout << "Выберите рекурсивный алгоритм:\n1 - Бинарный поиск" << endl;
    cin >> select;
    if (select == 1) {
       Binary::result_search();
    }
}