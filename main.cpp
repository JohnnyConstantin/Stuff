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



unsigned long long int C = 0, M = 0, n, f;
double fa;

class Test{

    public:
    static vector<int> tests(vector<int> test){
        //В предусловии ожидается вектор целочисленных значений
        cout << "Введите через пробел 10 целочисленных элементов массива" << endl;
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

static uint64_t GetTickCountMs()
//Функция подсчета времени(взято с интернет-ресурса https://stackoverflow)
{
    struct timespec ts{};

    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (uint64_t)(ts.tv_nsec / 1000000) + ((uint64_t)ts.tv_sec * 1000ull);
}

bool compare(int a, int b)
//В предусловии ожидаются два целочисленных аргумента
{
    C++;
    if (a > b)
        return true;
    else
        return false;
};

void reverse(int* ar_1)
{
    for (int i = 0;i < n / 2;i++)
        swap(ar_1[i], ar_1[n - i - 1]);
}

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
                    while (j >= 0 && ar[j] > ar[j + d]) {
                        swap(ar[j], ar[j + d]);
                        j--;
                    }
                }
                d = d / 2;
            }
            for (int i = 0; i < 10; i++)
            cout << ar[i] << " ";
            cout << endl;
    };

    static void sort_Shell(vector<int> ar_1) {
        //В предусловии ожидается вектор целочисленных значений
        long int start = GetTickCountMs();
        C = 0, M = 0;
        int d = n;
        d = d / 2;
        while (d > 0) {
            for (int i = 0; i < n - d; i++) {
                int j = i;
                while (j >= 0 && compare(ar_1[j], ar_1[j + d])) {
                    swap(ar_1[j], ar_1[j + d]);
                    j--;
                    M++;
                }
            }
            d = d / 2;
        }
        long int end = GetTickCountMs();
        long int T = end - start;
        f = C + M;
        cout << ""
        cout << "T(n)=" << T << "\t fэ(n)=" << f << endl;
    };
};

void Shake(int* mas)
{
    long int start = GetTickCountMs();
    M = 0, C = 0;
    int left = 1, right = n - 1;
    bool k = false;
    while (left <= right)
    {
        for (int i = right; i >= left; i--)
        {
            C++;
            if (mas[i - 1] > mas[i])
            {
                swap(mas[i], mas[i - 1]);
                k = true;
                M++;
            }
        }
        left++;
        if (!k) break;
        for (int i = left; i <= right; i++)
        {
            C++;
            if (mas[i - 1] > mas[i])
            {
                swap(mas[i], mas[i - 1]);
                M++;
            }
        }
        right--;
    }
    long int end = GetTickCountMs();
    long int T = end - start;
    f = C + M;
    cout << "T(n)=" << T << " fэ(n)=" << f << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    n = 50000;
    int select;
    cout << "Выберите сортировку:\n1 - Сортировка Шелла\n2 - Шейкерная сортировка\n3 - Пирамидальная сортировка" << endl;
    cin >> select;
    cout << endl;
    if (select == 1)
    {
        cout << "Вы выбрали сортировку Шелла." << endl;
        vector<int> ar;
        ar = Test::tests(ar);//В постусловии и предусловии ожидается вектор целочисленных значений
       Shell::test_Shell(ar);//В предусловии ожидается вектор целочисленных значений
       Shell::sort_Shell(ar);//В предусловии ожидается вектор целочисленных значений
        }
    else if(select == 2){

    }
    }