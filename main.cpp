#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

/* Written by Zubchenko Konstantin (25.03.2020)
* As homework for "Algorithmes and data structures" classes
* Professor: Syromyatnikov Vladislav Petrovich
*
*
* Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
* Ошибки возможны при некорректном вводе данных.
*/


class Binary{
public:
    static void search(unsigned long long n, int arr[n], int key){
//В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        t = clock();
// создали массив на n элементов
        srand(time(NULL));
        for (unsigned long long i = 0; i < n; i++) {
            arr[i] = rand()%100000; // считываем элементы массива
        }

//insertionSort(n, arr); // сортируем с помощью функции
        sort(arr, arr + n);

        bool flag = false;
        unsigned long long l = 0; // левая граница
        unsigned long long r = n-1; // правая граница
        unsigned long long mid;

        while (l <= r && !flag) {
            D++;
            mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

            if (arr[mid] == key) {flag = true; C++;} //проверяем ключ со серединным элементом
            if (arr[mid] > key) {r = mid - 1;C++;} // проверяем, какую часть нужно отбросить
            else {l = mid + 1;C++;}
        }
        t = clock() - t;
        if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid;
        else cout << "\nИзвините, но такого элемента в массиве нет";
        cout << "\nВремя t = " << t << "\t\tt(э) = " << C;
        cout << "\nt(a) = " << log2(n) << "\t\tt(э)/t(a) = " << C/log2(n);
        t=0;
        C=0;
        cout << "\nГлубина рекурсии составила: " << D;
    }

    static void result_search(){

        N = 300000;
        cout << "\n====================================\n";
        int key;
        cout << "Количество элементов массива:" << N;
        cout << "\n\nСредний случай:\n";
        key = rand()%100000;
        int arr[N];
        Binary::search(N, arr, key); //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        D=0;
        cout << "\n\nНаихудший случай:";
        key = 100000;
        Binary::search(N, arr, key);

        cout << "\n====================================";
        N += 100000;
        cout << "\n\nКоличество элементов массива:" << N;
        cout << "\n\nСредний случай:\n";
        key = rand()%100000;
        int *arr1= nullptr;  // объявление нового указателя
        arr1 = new int [N];
        Binary::search(N, arr1, key); //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        D=0;
        cout << "\n\nНаихудший случай:";
        key = 100000;
        Binary::search(N, arr1, key);
        delete[] arr1;
        arr1 = nullptr;

        cout << "\n====================================";
        N += 100000;
        cout << "\n\nКоличество элементов массива:" << N;
        cout << "\n\nСредний случай:\n";
        key = rand()%100000;
        int *arr2= nullptr;
        arr2 = new int [N];
        Binary::search(N, arr2, key); //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        D=0;
        cout << "\n\nНаихудший случай:";
        key = 100000;
        Binary::search(N, arr2, key);//В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        delete[] arr2;
        arr2 = nullptr;

        cout << "\n====================================";
        N += 100000;
        cout << "\n\nКоличество элементов массива:" << N;
        cout << "\n\nСредний случай:\n";
        key = rand()%100000;
        int *arr3= nullptr;
        arr3 = new int [N];
        Binary::search(N, arr3, key); //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        D=0;
        cout << "\n\nНаихудший случай:";
        key = 100000;
        Binary::search(N, arr3, key);//В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        delete[] arr3;
        arr3 = nullptr;

        cout << "\n====================================";
        N += 100000;
        cout << "\n\nКоличество элементов массива:" << N;
        cout << "\n\nСредний случай:\n";
        key = rand()%10000;
        int *arr4= nullptr;
        arr4 = new int [N];
        Binary::search(N, arr4, key); //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        D=0;
        cout << "\n\nНаихудший случай:";
        key = 100000;
        Binary::search(N, arr4, key);//В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
//целочисленное значение ключа поиска
        delete[] arr4;
        arr4 = nullptr;
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Здравствуйте, введите, пожалуйста тестовый массив для бинарного поиска:\n" << endl;
    int ar[10];
    int key0;
    int m;
    for (int i = 0;i < 10;i++)
    {
        cin >> m;
        ar[i] = m;
    }
    cout << "Введите ключ\n";
    cin >> key0;
    insertionSort(10, ar);
    cout << "Отсортированный массив: ";
    for (int i : ar)
    {
        cout << i << " ";
    }

    bool flag = false;
    unsigned long long l = 0; // левая граница
    unsigned long long r = 9; // правая граница
    unsigned long long mid;

    while (l <= r && !flag) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (ar[mid] == key0) flag = true; //проверяем ключ со серединным элементом
        if (ar[mid] > key0) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
    }
    if (flag) cout << "\nИндекс элемента " << key0 << " в массиве равен: " << mid;
    else cout <<

    "\nИзвините, но такого элемента в массиве нет";

    Binary::result_search();
}