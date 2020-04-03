#include <iostream>
#include <fstream>
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
unsigned long long n;

// Функция заполнения файла единицами
void create_file(ofstream& file, int count) {
    for (auto i = 0; i < count; i++) {
        file << 1;
    }
}
// Определение номера элемента последовательности nc , которому будет присвоено значение равное двум
    int position = rand() % (n - 4) + 4;

// Функция линейного поиска
    bool search_number(ifstream& f, long digit, bool showtime)
    {
        double time = clock(); //Время в начале поиска
        long c = 0, pos = -1;
        while (!f.eof())
        {
            string str;
            getline(f, str);
            for (auto ch : str)
            {
                if (isdigit(ch))
                {
                    c++;
                    pos++;
                    if (digit == atoi(&ch))
                    {
                        cout << "\nПоиск в файле. Позиция цифры \""
                        << digit << "\": " << pos << " Количество сравнений: " << c;
                        if (showtime)
                            cout << " Время поиска: " << setw(5) << (clock() - time) / CLOCKS_PER_SEC «" секунд.";
                        return true;
                    }
                }
            }
        }

        cout << "\nПоиск в файле. Число \"" << digit << "\" не найдено! Время поиска: " << (clock() - time) / CLOCKS_PER_SEC;
        return false;
    }


// Обращение к функции линейного поиска для среднего и наихудшего случаев
    void search_numbers(ifstream& f, const string& path, bool showtime)
    {
        search_number(f, 2, showtime);
        f.close();

        f.open(path);
        search_number(f, 3, showtime);
        f.close();
    }


int main()
{
    setlocale(LC_ALL, "Rus");
    ifstream f;
    string path = ""
    search_numbers(f, )
}