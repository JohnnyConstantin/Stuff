#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Edge {
    char ver1, ver2;
    int len;

    bool operator<(const Edge& rhs) const {
        return len < rhs.len;
    }

    bool operator>(const Edge& rhs) const {
        return rhs < *this;
    }

    Edge(char node1, char node2, int len) : ver1(node1), ver2(node2), len(len) {}
};

const int INF = 1000000000;

void bf(Edge* g[], int v, int e, int first) {
    vector<int> d (e, INF);
    d[first-1] =0;
    for (int i = 0; i < v-1; ++i) {
        for (int j = 0; j < e; ++j) {
            d[g[j]->ver2-1] = min(d[g[j]->ver2-1], d[g[j]->ver1-1] + g[j]->len);
            }
        }
    for(int i=0; i <e; ++i){
        if(d[g[i]->ver1-1] != INF && d[g[i]->ver1-1] + g[i]->len < d[g[i]->ver2-1]){
            cout << "Граф содержит цикл отрицательного веса\nКратчайших путей не найдено\n";
            return;
        }
    }
    for(int i=0; i<v; ++i){
        cout << "Вершина: " << i+1 << "     " << "Путь: " << d[i] << "\n";
    }
}

void test() {
    Edge* graph[] = {   new Edge(1, 3, 12),
                        new Edge(1,2,23),
                      new Edge(2,3,25),
                      new Edge(2,5,22),
                      new Edge(2,8,35),
                      new Edge(3,4,18),
                      new Edge(4,6,20),
                      new Edge(5,6,23),
                      new Edge(5,7,14),
                      new Edge(6,7,24),
                      new Edge(7,8,16) };
    bf(graph, 8, 11, 1);

    for (auto & i : graph) {
        delete i;
    }
}

void input_graph() {
    int n, l, v, n1, n2;
    cout << "Введите кол-во вершин графа:\n";
    cin >> v;
    cout << "Введите кол-во ребер графа:\n";
    cin >> n;
    cout << "Введите " << n << " ребер.\n"
                            "В формате вершина, вес ребра, вершина.\n";
    Edge* graph[n];
    for (int i = 0; i < n; ++i) {
        cin >> n1 >> l >> n2;
        graph[i] = new Edge(n1, n2, l);
    }
    bf(graph, v,n,1);

    for (auto & i : graph) {
        delete i;
    }
}

void mainMenu() {
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Выберите команду:" << endl;
    cout << "[1] - Вывести граф" << endl;
    cout << "[2] - Тестовый прогон программы" << endl;
    cout << "[0] - Завершить работу программы" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
}

void menu() {
    cout << "Выбранная команда:";
    int choise;
    cin >> choise;
    cout << "----------------------------------------------------------------------------------------" << endl;
    switch (choise) {
        case 1: {
            input_graph();
            menu();
            break;
        }
        case 2: {
            test();
            menu();
            break;
        }
        case 0:
            cout << "Вы точно хотите выйти?\n"
                   "[0] Да\n"
                   "[1] Нет\n";
            int a;
            cin >> a;
            if (a == 1)
                menu();
            break;
        default:
            cout << "Вы ввели неправильное значение." << endl;
            menu();
            break;
    }
}

int main()
{
    mainMenu();
    menu();
    return 0;
}