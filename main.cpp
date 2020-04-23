#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/* Written by Zubchenko Konstantin (22.04.2020)
* As homework for "Algorithmes and data structures" lab №6
* Professor: Syromyatnikov Vladislav Petrovich
*
*
* Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
* Ошибки возможны при некорректном вводе данных.
*/

long long int C = -1;
long long int M = -1;
# define NO_OF_CHARS 256

char par[] = "ABC";
long long int N = 100000;
bool found;
int T, T2;

// A utility function to get maximum of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

// The preprocessing function for Boyer Moore's bad character heuristic
    void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
    {
        int i;

// Initialize all occurrences as -1
        for (i = 0; i < NO_OF_CHARS; i++)
            badchar[i] = -1;

// Fill the actual value of last occurrence of a character
        for (i = 0; i < size; i++)
            badchar[(int) str[i]] = i;
    }

    void search(string txt, string pat)
    {
        C=0;
        M=0;
        int m = pat.length();
        int n = txt.length();
        found = false;

        int badchar[NO_OF_CHARS];

        badCharHeuristic(pat, m, badchar);

        int s = 0; // s is shift of the pattern with respect to text
        while (s <= (n - m))
        {
            int j = m - 1;

            while (j >= 0 && pat[j] == txt[s + j]) {
                j--;
                C++;
            }
            if (j <= 0)
            {
                printf("Искомое слово находится на %d позиции", s);
                found = true;
                s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

            }

            else {
                s += max(1, j - badchar[txt[s + j]]);
                C++;
                M++;
            }
        }
    }
void create_file(string name, char *what,long long int n){
    ofstream file(name);
    for (auto i = 0; i < n; i += 10){
        if (i == n / 2)
        {
            file << what;
            continue;
        }
        file << "JSDFGHJKLZ";
    }
    file.close();
}
string create_arr(string name){
    ifstream file(name);
    string mas;
    getline(file, mas);
    file.close();
    return mas;
}

string test_arr(){
        string test = "asdfghjklo";
        cout << "Введите тестовый массив для поиска строки " << par << endl;
        for(int i = 0; i < 10; i++){
            cin >> test[i];
        }
        return test;
    }
/* Driver program to test above function */
    int main()
    {
        cout << "\nАлгоритм Бойера-Мура-Хорспула\n"
                "\nТестовый прогон. \n";
        string path = "d.txt";

        cout << "Средний случай: \n";
        string test = test_arr();
        T = clock();
        search(test, par);
        T2 = clock();
        cout << "\nM(э): " << M <<"\t f(э): " << M + C <<  "\nC(э): " << C << "\t T = " << T2 - T;
        T=0;
        T2=0;


        cout << "\n\nНаихудший случай: \n";
        string test2 = test_arr();
        T=clock();
        search(test2, par);
        T2=clock();
        if(!found){
            cout << "Слово отсутствует в тексте \n" << "M(э): " << M <<"\t f(э): " << M + C <<  "\nC(э): " << C << "\t T = " << T2-T;
        }
        T=0;
        T2=0;


        cout << "\n\n=============================================\nКонтрольный прогон программы:";

        cout << "\n\nСредний случай:\n";
        create_file(path, par, N);
        T=clock();
        string txt = create_arr(path);
        search(txt, par);
        T2=clock();
        cout << "\nM(э): " << M <<"\t f(э): " << M + C <<  "\nC(э): " << C << "\t T = " << T2 - T;
        T=0;
        T2=0;

         cout << "\n\nНаихудший случай \n";
        string pat2 = "??J";
        T=clock();
        string txt2 = create_arr(path);
        search(txt2, pat2);
        T2=clock();
        if(!found){
            cout << "Слово отсутствует в тексте \n" << "M(э): " << M <<"\t f(э): " << M + C <<  "\nC(э): " << C << "\t T = " << T2-T;
        }
        return 0;
    }