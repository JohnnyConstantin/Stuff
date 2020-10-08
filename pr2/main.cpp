
//Программа написана Зубченко К.В., студент 2 курса РТУ МИРЭА

#include <iostream>
using namespace std;

struct Node
{
    int key;
    int height;
    Node *right;
    Node *left;
    Node(int k) { key=k; height=1; left=right=0; }
};

int height(Node *p)
{
    if (p) return p->height;
    else return 0;
}

int bfactor(Node* p)
{
    return height(p->right)-height(p->left);
}

void fixheight(Node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

Node* rotateright(Node* p) // правый поворот вокруг p
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* rotateleft(Node* q) // левый поворот вокруг q
{
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node* balance(Node* p) // балансировка узла p
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

void printHeight(Node *p){
    cout << p->height;
}

void countLeafs(Node* t_node, int &sum)
{
    if (t_node == NULL)
        return;

    countLeafs(t_node->left, sum);

    if (!t_node->left && !t_node->right)
        sum+=t_node->key;

    countLeafs(t_node->right, sum);
};


Node *Insert(Node *x, int k)
{
    if (!x) return new Node(k);
    if (k<x->key) x->left=Insert(x->left, k);
    else x->right=Insert(x->right, k);
    return balance(x);
}

void iterSymmetry(Node *root) {
    if(NULL==root)
        return;
    iterSymmetry(root->left);
    cout << "Обошли "<< root->key << endl;
    iterSymmetry(root->right);
}

void iterFromBack(Node *root) {
   if(NULL==root)
       return;
   iterFromBack(root->left);
   iterFromBack(root->right);
   cout << "Обошли "<< root->key << endl;
}

int main(){
    Node *node;
    bool flag = false;
    while(true) {
        if (!flag) {
            cout << "Здравствуйте, добро пожаловать в программу реализацию АВЛ-дерева.\n"
                    "Создание дерева... Введите корень:\n";
                    int root;
                    cin >> root;
                    node = new Node(root);;
                    flag = true;
        } else {
            cout <<
            "\nВыберите действие.\n"
            "1. Провести тестирование\n"
            "2. Добавить элемент\n"
            "3. Найти сумму значений\n"
            "4. Провести обход дерева\n"
            "5. Найти высоту дерева\n"
            "6. Выход\n\n"
            "Выбранный вариант > ";
            char choice;
            cin >> choice;
            cout << endl;
            int sum = 0;
            int lsum =0;
            int key;
            Node *test = new Node(8);
            switch (choice) {
                case '1':
                    cout << "\nПроисходит тестирование...\n\n"
                            "Создано новое дерево. Начинается добавление элементов...\n\n";
                    for (int i = 0; i < 9; ++i) {
                        int fortest;
                        cout << "Добавьте элемент: ";
                        cin >> fortest;
                        Insert(test,fortest);
                        cout << "Добавлен элемент " << fortest << "\n";
                    }
                    cout << "\nСовершим обратный обход дерева:\n";
                    iterFromBack(test);
                    cout << "\nСовершим симметричный обход дерева:\n";
                    iterSymmetry(test);
                    cout << "\nСумма листьев дерева равна:\n";
                    countLeafs(test, sum);
                    printf("%d", sum);
                    cout << "\nВысота дерева равна:\n";
                    printHeight(test);
                    cout << endl << endl;
                    break;
                case '2':
                    cout << "Введите ключ, который необходимо вставить\n"
                            "Ключ > ";
                    cin >> key;
                    Insert(node, key);
                    break;
                case '3':
                    cout << "Сумма значений листьев равна:\n";
                    countLeafs(node, lsum);
                    cout << lsum;
                    break;
                case '4':
                    char choice2;
                    cout << "Выберите какой обход вы хотите совершить.\n"
                            "1. Симметричный обход дерева\n"
                            "2. Обратный обход дерева\n"
                            "3. Вернуться назад\n\n"
                            "Выбранный вариант > ";
                    cin >> choice2;
                    switch (choice2) {
                        case '1':
                            iterSymmetry(node);
                            break;
                        case '2':
                            iterFromBack(node);
                            break;
                        case '3':
                            break;
                    }
                    break;
                case '5':
                    printHeight(node);
                    cout << endl << endl;
                    break;
                case '6':
                    return 0;
                default:
                    cout << "Что-то пошло не так, попробуйте еще раз\n";
                    break;
            }
        }
    }
}