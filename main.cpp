#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

/*    Written by Zubchenko Konstantin (2.04.2020)
 *    As homework for "Algorithmes and data structures" classes
 *    Professor: Syromyatnikov Vladislav Petrovich
 *
 *
 *    Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
 *    Ошибки возможны при некорректном вводе данных.
 */
using namespace std;

unsigned long long int time1, time2, position1, position2 = -1, C = 0, n, digit, pos;

void create(int* ar, unsigned long long int n, unsigned long long int pos){
    for (int i = 0;i < n;i++)
        ar[i] = 1;

    ar[pos] = 2;
    ofstream file("/Applications/GitHub/GitHub/Stuff/d.txt");
    for (int i = 0;i < n;i++)
        file << ar[i];
    file.close();
}

bool search(int* ar, int digit, bool flag)
{
    time1 = clock();
    for (int i = 0;i < n;i++)
    {
        C++;
        if (ar[i] == digit)
        {
            cout << "\nПозиция цифры \""
                 << digit << "\": " << i;
            if (flag)
            {
                time2 = clock();
                cout << " C = " << C;
                cout << " Время поиска: " << time2 - time1 << " мс";
            }
            return true;
        }
    }

    cout << "\nЧисло \"" << digit << "\" не найдено!";
    if (flag)
    {
        time2 = clock();
        cout << " Время поиска : " << time2 - time1 << " мс";
    }
    return false;
}

bool search_file(int digit, bool flag)
{
    time1 = clock();
    ifstream file2("/Applications/GitHub/GitHub/Stuff/d.txt");
    while (!file2.eof())
    {
        string str;
        getline(file2, str);
        for (char ch : str)
        {
            if (isdigit(ch))
            {
                C++;
                position2++;
                if (digit == atoi(&ch))
                {
                    time2 = clock();
                    cout << "\nПозиция цифры \""
                         << digit << "\": " << position2;
                    if (flag)
                    {
                        cout << " C = " << C;
                        cout << " Время поиска: "<<time2-time1<<" мс";
                    }
                    return true;
                }
            }
        }
    }
    file2.close();
    cout << "\nЧисло \"" << digit << "\" не найдено!";
    if (flag)
    {
        time2 = clock();
        cout << " Время поиска : " << time2 - time1 << " мс";
    }
    return false;
}

void test()

{
    cout << "Тестовый прогон массива из 10 элементов:" << endl;
    n = 10;
    int* ar = new int[n];
    cout << "Введите 10 чисел" << endl;
    for (int i = 0;i < n;i++)
        cin >> ar[i];

    ofstream file("/Applications/GitHub/GitHub/Stuff/d.txt");
    for (int i = 0;i < n;i++)
        file << ar[i];
    file.close();

    cout << "\nПоиск в массиве." <<
    "\nСредний случай:";
    search(ar, 2, false);
    cout << "\nХудший случай:";
    search(ar, 3, false);
    C = 0;position1 = 0;position2 = -1;
    cout << endl << endl;
    cout << "\nПоиск в файле." <<
    "\nСредний случай:";
    search_file(2, false);
    cout << "\nХудший случай:";
    search_file(3, false);
    C = 0;position1 = 0;position2 = -1;
    cout << endl << endl;
    delete[] ar;
}

void control()

{
    cout << "Контрольный прогон:";
    cout << endl << "----------------------------------------------------------------------------" << endl;
    n = 5000000;
    for (int i = 0;i < 3;i++)
    {
        n += 1000000;
        cout << "Количество элементов: " << n << endl;
        pos = rand() % (n - 4) + 4;
        int* ar = new int[n];
        cout << "\nПоиск в массиве." << "\nСредний случай:";
        create(ar, n, pos);
        search(ar, 2, true);
        cout << "\nНаихудший случай:";
        C = 0;
        search(ar, 3, true);
        C = 0;position1 = 0;position2 = -1;
        cout<< "\n\n**************************************************************************************" << endl;
        cout << "\nПоиск в файле." << "\nСредний случай:";
        search_file(2, true);
        cout << "\nНаихудший случай:";
        C = 0;
        search_file(3, true);
        C = 0;position1 = 0;position2 = -1;
        cout << endl << "----------------------------------------------------------------------------" << endl;
        delete[] ar;
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    test();
    control();
}