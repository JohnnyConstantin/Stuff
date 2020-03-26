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

unsigned long long int C = 0, M = 0, n;
long double fa, f, r;

static uint64_t GetTickCountMs()
//Функция подсчета времени(взято с интернет-ресурса https://stackoverflow)
{
    struct timespec ts{};

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (uint64_t)(ts.tv_nsec / 1000000) + ((uint64_t)ts.tv_sec * 1000ull);
    //В постусловии ожидается целочисленное значение
}

bool compare(int a, int b)
//В предусловии ожидаются два целочисленных аргумента
{
    C++;
    return a > b;
}

void reverse(int* ar_1)
{
    for (int i = 0;i < n / 2;i++)
        swap(ar_1[i], ar_1[n - i - 1]);
}

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

class Shell {

public:
    static void test_Shell(vector<int> ar){
        //В предусловии ожидается вектор целочисленных значений
        cout << "Отсортированный тестовый массив: ";
            int d = 10;
            d = d / 2;
            while (d > 0)
            {
                for (int i = 0; i < 10 - d; i++) {
                    int j = i;
                    while (j >= 0 && compare(ar[j], ar[j + d])) {
                        swap(ar[j], ar[j + d]);
                        j--;
                    }
                }
                d = d / 2;
            }
            for (int i = 0; i < 10; i++)
            cout << ar[i] << " ";
            cout << endl;
            ar.clear();
    };

    static void sort_Shell(int ar[]) {
        //В предусловии ожидается вектор целочисленных значений
        long int start = GetTickCountMs();
        C = 0, M = 0;
        int d = n;
        d = d / 2;
        while (d > 0) {
            for (int i = 0; i < n - d; i++) {
                int j = i;
                while (j >= 0 && compare( ar[j], ar[j + d])) {
                    swap(ar[j], ar[j + d]);
                    j--;
                    M++;
                }
            }
            d = d / 2;
        }
        long int end = GetTickCountMs();
        long int T = end - start;
        f = C + M;
        cout << "T(n)=" << T << "\t\t\t fэ(n)=" << f << endl;
    };

    static void result_Shell(){
            for(int i = 0;i < 5;i++)
            {
                n += 10000;
                int* ar_1 = new int[n];
                for (int j = 0; j < n; j++)
                    ar_1[j] = rand();
                cout << n << " элементов:" << endl;
                cout << "Средний случай:" << endl;
                sort_Shell(ar_1);
                fa = n * n;
                r = f / fa;
                cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << r << endl;

                cout << "Наилучший случай:" << endl;
                sort_Shell(ar_1);
                fa = n * log10(n) * log10(n);
                r = f / fa;
                cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << r << endl;

                cout << "Наихудший случай:" << endl;
                reverse(ar_1);
                sort_Shell(ar_1);
                fa = pow(n, 1.5);
                r = f / fa;
                cout << "fa(n)=" << fa << "\t\t fэ(n)/fa(n)=" << r << endl;

                cout << endl;
                delete[] ar_1;
            }
    };
};

class Shaker {
public:
    static void test_Shake(vector<int> ar2){
        //В предусловии ожидается вектор целочисленных значений
        cout << "Отсортированный тестовый массив:";
        int left = 1, right = 9;
        bool k = false;
        while (left <= right) {
            for (int i = right; i >= left; i--) {
                if (ar2[i - 1] > ar2[i]) {
                    swap(ar2[i], ar2[i - 1]);
                    k = true;
                }
            }
            left++;
            if (!k) break;
            for (int i = left; i <= right; i++) {
                if (ar2[i - 1] > ar2[i]) {
                    swap(ar2[i], ar2[i - 1]);
                }
            }
            right--;
        }
        for(int i=0;i<10;i++)
            cout << ar2[i] << " " ;
            cout << endl;
    };
    static void sort_Shake(int *ar2) {
        //В предусловии ожидается целочисленный массив
        long int start = GetTickCountMs();
        M = 0, C = 0;
        int left = 1, right = n - 1;
        bool k = false;
        while (left <= right) {
            for (int i = right; i >= left; i--) {
                C++;
                if (ar2[i - 1] > ar2[i]) {
                    swap(ar2[i], ar2[i - 1]);
                    k = true;
                    M++;
                }
            }
            left++;
            if (!k) break;
            for (int i = left; i <= right; i++) {
                C++;
                if (ar2[i - 1] > ar2[i]) {
                    swap(ar2[i], ar2[i - 1]);
                    M++;
                }
            }
            right--;
        }
        long int end = GetTickCountMs();
        long int T = end - start;
        f = C + M;
        cout << "T(n)=" << T << "\t\t\t fэ(n)=" << f << endl;
    }
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

        for (int i = (10 / 2) - 1; i >= 0; i--)
            shiftDown(ar3, i, 10 - 1);
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
            if (root * 2 == bottom) {
                maxChild = root * 2;
            ;
        }   else if (numbers[root * 2] > numbers[root * 2 + 1]) {
            maxChild = root * 2;
            ;
        } else{
                maxChild = root * 2 + 1;
                ;}
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
            C=0, M=0;
            for (int i = (array_size / 2) - 1; i >= 0; i--){
                shiftDown(numbers, i, array_size - 1);
            ;}
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
            cout << "T(n)=" << T << "\t\t\t fэ(n)=" << f << endl;
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
            fa = n * log2(n) * log2(n);
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << "Наилучший случай:" << endl;
            reverse(ar_3);
            heapSort(ar_3, n);
            fa = n * log2(n) * log2(n);
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << "Наихудший случай:" << endl;
            heapSort(ar_3, n);

            fa = n * log2(n) * log2(n);
            cout << "fa(n)=" << fa << "\t fэ(n)/fa(n)=" << f / fa << endl;

            cout << endl;
            delete[] ar_3;
        }
    };
};
int main()
{
    setlocale(LC_ALL, "Rus");
    n = 10000;
    int select;
    cout << "Выберите сортировку:\n1 - Сортировка Шелла\n2 - Шейкерная сортировка\n3 - Пирамидальная сортировка" << endl;
    cin >> select;
    cout << endl;
    if (select == 1)
    {
        cout << "Вы выбрали сортировку Шелла.\n";
        vector<int> ar;
        ar = Test::tests(ar);//В постусловии и предусловии ожидается вектор целочисленных значений
        Shell::test_Shell(ar);//В предусловии ожидается вектор целочисленных значений
        Shell::result_Shell();
        }
    else if(select == 2){
        cout << "Вы выбрали Шейкерную сортировку.\n";
        vector<int> ar2;
        ar2 = Test::tests(ar2);//В предусловии ожидается целочисленный вектор
        Shaker::test_Shake(ar2);//В предусловии ожидается целочисленный вектор
        Shaker::result_Shake();
    } else if(select == 3){
        cout << "Вы выбрали пирамидальную сортировку.\n";
        Heap::test_Heap();
        Heap::resultHeap();
    }
    }