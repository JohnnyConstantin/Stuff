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

unsigned long long C = 0, //Количество сравнений
        D = 0, //Глубина рекурсии
        N; //Количество элементов
unsigned long t; //Переменная времени

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
<<<<<<< HEAD
    static void result_Shake(){
        for (int i = 0;i < 5;i++)
        {
            n += 10000;
            int* ar_2 = new int[n];
            for (int i = 0;i < n;i++)
                ar_2[i] = rand();
            cout << n << " элементов:" << endl;
            cout << "Средний случай:" << endl;
            sort_Shake(ar_2);
            fa = n * n;
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << "Наилучший случай:" << endl;
            sort_Shake(ar_2);
            fa = n;
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << "Наихудший случай:" << endl;
            reverse(ar_2);
            sort_Shake(ar_2);

            fa = n * n;
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << endl;
            delete[] ar_2;
        }};
};

class Heap{
public:
    static void test_Heap(){
        int* ar3 = new int[10];
        cout << "Введите через пробел 10 целочисленных элементов тестового массива" << endl;
        for (int i = 0;i < 10;i++) {
            cin >> ar3[i];
        }

<<<<<<< HEAD
        // Формируем нижний ряд пирамиды
        for (int i = (10 / 2) - 1; i >= 0; i--)
            shiftDown(ar3, i,10 - 1);
        // Просеиваем через пирамиду остальные элементы
=======
        for (int i = (10 / 2) - 1; i >= 0; i--)
            shiftDown(ar3, i, 10 - 1);
>>>>>>> dev
        for (int i = 10 - 1; i >= 1; i--)
        {
            int temp = ar3[0];
            ar3[0] = ar3[i];
            ar3[i] = temp;
            shiftDown(ar3, 0, i - 1);
        }

        for (int i = 0;i < 10;i++) {
            cout << ar3[i] << " ";
        }
        cout << '\n';
        delete[] ar3;
    };

    static void shiftDown(int *numbers, int root, int bottom)
    //В предусловии ожидается целочисленный массив, и 2 целочисленных значения любого знака
    {
        int maxChild;
        int done = 0;
        while ((root * 2 <= bottom) && (!done)) {
<<<<<<< HEAD
            if (root * 2 == bottom){    // если мы в последнем ряду,
                maxChild = root * 2;
                ;}
              // запоминаем левый потомок
            // иначе запоминаем больший потомок из двух
            else if (numbers[root * 2] > numbers[root * 2 + 1]){
            maxChild = root * 2;
            ;}
            else{
                maxChild = root * 2 + 1;
                ;}
            // если элемент вершины меньше максимального потомка
=======
            if (root * 2 == bottom) {
                maxChild = root * 2;
            ;
        }   else if (numbers[root * 2] > numbers[root * 2 + 1]) {
            maxChild = root * 2;
            ;
        } else{
                maxChild = root * 2 + 1;
                ;}
>>>>>>> dev
            if (numbers[root] < numbers[maxChild])
            {
                int temp = numbers[root];
                numbers[root] = numbers[maxChild];
                numbers[maxChild] = temp;
                root = maxChild;
                C++;
            }
            else
                done = 1; // пирамида сформирована
        }
    }

    static void heapSort(int *numbers, int array_size)
    //В предусловии ожидается целочисленный массив и целочисленное значение больше нуля
        {
            long int start = GetTickCountMs();
<<<<<<< HEAD
            M =0, C=0;
            // Формируем нижний ряд пирамиды
            for (int i = (array_size / 2) - 1; i >= 0; i--){
                shiftDown(numbers, i, array_size - 1);}
            // Просеиваем через пирамиду остальные элементы
=======
            C=0, M=0;
            for (int i = (array_size / 2) - 1; i >= 0; i--){
                shiftDown(numbers, i, array_size - 1);
            ;}
>>>>>>> dev
            for (int i = array_size - 1; i >= 1; i--)
            {
                int temp = numbers[0];
                numbers[0] = numbers[i];
                numbers[i] = temp;
                shiftDown(numbers, 0, i - 1);
               C++;
            }
            long int end = GetTickCountMs();
            long int T = end - start;
            f = C + M;
<<<<<<< HEAD
            cout << "T(n)=" << T << " fэ(n)=" << f << endl;
=======
            cout << "T(n)=" << T << "\t\t\t fэ(n)=" << f << endl;
>>>>>>> dev
        };

    static void resultHeap() {
        for (int i = 0;i < 5;i++)
        {
            n += 10000;
            int* ar_3 = new int[n];
            for (int i = 0;i < n;i++)
                ar_3[i] = rand();
            cout << n << " элементов:" << endl;
            cout << "Средний случай:" << endl;
            heapSort(ar_3, n);
<<<<<<< HEAD
<<<<<<< HEAD
            fa = n * log10(n);
<<<<<<< HEAD
            cout << "fa(n)=" << fa << " fэ(n)/fa(n)=" << f / fa << endl;
=======
=======
            fa = n * log10(n) * log10(n);
>>>>>>> dev
=======
            fa = n * log2(n) * log2(n);
>>>>>>> dev
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;
>>>>>>> dev

            cout << "Наилучший случай:" << endl;
            reverse(ar_3);
            heapSort(ar_3, n);
<<<<<<< HEAD
<<<<<<< HEAD
            fa = n * log10(n);
<<<<<<< HEAD
            cout << "fa(n)=" << fa << " fэ(n)/fa(n)=" << f / fa << endl;
=======
=======
            fa = n * log10(n) * log10(n);
>>>>>>> dev
=======
            fa = n * log2(n) * log2(n);
>>>>>>> dev
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;
>>>>>>> dev
=======
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
>>>>>>> dev

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