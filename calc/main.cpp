//Программа написана Зубченко К.В./ Студент 2 курса РТУ МИРЭА/24.09.20
#include <iostream>
#include <queue>
using namespace std;

bool isOperand(char c)
{
    return isdigit(c);
}

double evaluatePrefix(string exprsn)
{
    queue<double> Queue;

    for (int j = exprsn.size() - 1; j >= 0; j--) {
        if (isOperand(exprsn[j]))
            Queue.push(exprsn[j] - '0');//Переводим char в число

        else {//При обнаружении оператора - достаем последние два числа из стэка
            double o1 = Queue.back();
            Queue.pop();
            double o2 = Queue.back();
            Queue.pop();
            //Выбор действия на основе оператора
            switch (exprsn[j]) {
                case ' ':
                    break;
                case '+':
                    Queue.push(o1 + o2);
                    break;
                case '-':
                    Queue.push(o1 - o2);
                    break;
                case '*':
                    Queue.push(o1 * o2);
                    break;
                case '/':
                    Queue.push(o1 / o2);
                    break;
            }
        }
    }

    return Queue.front();
}
int main()
{
    string exprsn;
    cout << "Введите выражение: ";
    cin >> exprsn;
    cout << "Результат: "<< evaluatePrefix(exprsn) << endl;
    return 0;
}