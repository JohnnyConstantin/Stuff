#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

/*    Written by Zubchenko Konstantin (25.03.2020)
 *    As homework for "Algorithmes and data structures" classes
 *    Professor: Syromyatnikov Vladislav Petrovich
 *
 *
 *    Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
 *    Ошибки возможны при некорректном вводе данных.
 */

unsigned long long  C = 0, //Количество сравнений
                    D = 0, //Глубина рекурсии
                    N;     //Количество элементов
unsigned long t;           //Переменная времени



void insertionSort(unsigned long long n, int mas[n]){
//В предусловии ожидается целочисленное значение типа unsigned long long и массив целочисленных значений
    for (int j = 1; j < n; j++){
        int key1 = mas[j];
        int i = j - 1;

        while (i >= 0 && mas[i] > key1){
            mas[i + 1] = mas[i];
            i--;
        }
        mas[i + 1] = key1;
    }
}

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
         cout << "\nВремя T(n) = " << t << "\t\tf(э) = " << C;
         cout << "\nf(a) = " << log2(n) << "\t\tf(э)/f(a) = " << C/log2(n);
         t=0;
         C=0;
         cout << "\nГлубина рекурсии составила: " << D;
     }

     static void result_search(){

         N = 400000;
         cout<<"\n====================================\n";
         int key;
         cout << "Количество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         int arr[N];
         Binary::search(N, arr, key);   //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
                                        //целочисленное значение ключа поиска
         D=0;

        cout<<"\n====================================";
         N += 100000;
         cout << "\n\nКоличество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         int arr1[N];
         Binary::search(N,arr1, key);   //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
                                        //целочисленное значение ключа поиска
         D=0;

         cout<<"\n====================================";
         N += 100000;
         cout << "\n\nКоличество элементов массива:" << N;
         cout << "\nВведите ключ\n";
         cin >> key;
         int arr2[N];
         Binary::search(N, arr2, key);  //В предусловии ожидается целочисленное значение типа unsigned long long, массив целочисленных значений и
                                        //целочисленное значение ключа поиска
         D=0;
     }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Здравствуйте, введите, пожалуйста тестовый массив для бинарного поиска:\n" << endl;
    int ar[8];
    int key0;
    int m;
    for (int i = 0;i < 8;i++)
    {
        cin >> m;
        ar[i] = m;
    }
    cout << "Введите ключ\n";
    cin >> key0;
    insertionSort(8, ar);
    cout << "Отсортированный массив: ";
    for (int i : ar)
    {
        cout << i << " ";
    }

    bool flag = false;
    unsigned long long l = 0; // левая граница
    unsigned long long r = 7; // правая граница
    unsigned long long mid;

    while (l <= r && !flag) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (ar[mid] == key0) flag = true; //проверяем ключ со серединным элементом
        if (ar[mid] > key0) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
    }
    if (flag) cout << "\nИндекс элемента " << key0 << " в массиве равен: " << mid;
    else cout << "\nИзвините, но такого элемента в массиве нет";

    Binary::result_search();
}