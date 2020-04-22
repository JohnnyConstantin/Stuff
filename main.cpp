#include <iostream>
#include <vector>
using namespace std;

/* Written by Zubchenko Konstantin (22.04.2020)
* As homework for "Algorithmes and data structures" lab №6
* Professor: Syromyatnikov Vladislav Petrovich
*
*
* Опущена проверка пред- и постусловий в функциях в связи с узкой направленностью программы.
* Ошибки возможны при некорректном вводе данных.
*/

long long int C = 0;
long long int M = 0;
# define NO_OF_CHARS 256

// A utility function to get maximum of two integers
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

// The preprocessing function for Boyer Moore's bad character heuristic
    void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
    {
        int i;

// Initialize all occurrences as -1
        for (i = 0; i < NO_OF_CHARS; i++)
            badchar[i] = -1;

// Fill the actual value of last occurrence of a character
        for (i = 0; i < size; i++)
            badchar[(int) str[i]] = i;
    }

    void search(char *txt, char *pat)
    {
        int m = strlen(pat);
        int n = strlen(txt);

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
            if (j < 0)
            {
                printf("\n pattern occurs at shift = %d", s);
                cout << "\n" << M;
                cout << "\n" << C;

                s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

            }

            else {
                s += max(1, j - badchar[txt[s + j]]);
                C++;
                M++;
            }
        }
    }

/* Driver program to test above funtion */
    int main()
    {
        char txt[] = "ABAAABCD";
        char pat[] = "ABC";
        search(txt, pat);
        return 0;
    }