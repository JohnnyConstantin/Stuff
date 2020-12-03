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

void sort_g(Edge* g[], int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (*g[j] > * g[j + 1]) {
                Edge* s;
                s = g[j];
                g[j] = g[j + 1];
                g[j + 1] = s;
            }
        }
    }
}

void kruskal(Edge* g[], int len, int vrs) {
    int n = 0, edg = 0;
    vector<Edge*> f;
    map<char, int> vertices;
    for (int i = 0; i < len; ++i) {
        vertices[g[i]->ver1] = vertices[g[i]->ver2] = 0;
    }
    for (int i = 0; i < len; ++i) {
        if (edg == vrs - 1) {
            break;
        }
        if (vertices[g[i]->ver2] != vertices[g[i]->ver1]) {
            edg++;
            if (vertices[g[i]->ver2] != 0 && vertices[g[i]->ver1] != 0) {
                int k = vertices[g[i]->ver1];
                for (auto o : vertices) {
                    if (o.second == k)
                        vertices[o.first] = vertices[g[i]->ver2];
                }
            }
            else
                vertices[g[i]->ver2] = vertices[g[i]->ver1] = vertices[g[i]->ver2] + vertices[g[i]->ver1];
            f.push_back(g[i]);
        }
        if (vertices[g[i]->ver1] == 0 && vertices[g[i]->ver2] == 0) {
            edg++;
            n++;
            vertices[g[i]->ver1] = vertices[g[i]->ver2] = n;
            f.push_back(g[i]);
        }
    }
    cout << "Минимальное остовное дерево графа\n";
    cout << "Вывод представлен в виде ребер графа\n\n";
    for (auto o : f) {
        cout << "(" << o->ver1 << ")-" << o->len << "-(" << o->ver2 << ")\n";
    }
    cout << endl;
}

void test() {
    Edge* graph[] = { new Edge('1','2',2),
                      new Edge('1','3',6),
                      new Edge('1','4',4),
                      new Edge('2','4',7),
                      new Edge('2','5',8),
                      new Edge('3','4',8),
                      new Edge('3','6',5),
                      new Edge('4','5',2),
                      new Edge('4','6',8),
                      new Edge('5','6',4) };
    sort_g(graph, 10);
    kruskal(graph, 10, 6);

    for (auto & i : graph) {
        delete i;
    }
}

void input_graph() {
    int n, l, v;
    char n1, n2;
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
    sort_g(graph, n);
    kruskal(graph, n, v);

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