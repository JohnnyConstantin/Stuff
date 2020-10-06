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

typedef struct Stack {
    size_t size;
    size_t limit;
    Node **data;
} Stack;

Stack* createStack() {
    Stack *tmp = (Stack*) malloc(sizeof(Stack));
    tmp->limit = 100;
    tmp->size = 0;
    tmp->data = (Node**) malloc(tmp->limit * sizeof(Node*));
    return tmp;
}

void freeStack(Stack **s) {
    free((*s)->data);
    free(*s);
    *s = NULL;
}

void push(Stack *s, Node *item) {
    if (s->size >= s->limit) {
        s->limit *= 2;
        s->data = (Node**) realloc(s->data, s->limit * sizeof(Node*));
    }
    s->data[s->size++] = item;
}

Node* pop(Stack *s) {
    if (s->size == 0) {
        exit(7);
    }
    s->size--;
    return s->data[s->size];
}

Node* peek(Stack *s) {
    return s->data[s->size-1];
}

void iterSymmetry(Node *root) {
    Stack *ps = createStack();
    while (ps->size != 0 || root != NULL) {
        if (root != NULL) {
            push(ps, root);
            root = root->left;
        } else {
            root = pop(ps);
            printf("Посещено %d\n", root->key);
            root = root->right;
        }
    }
    freeStack(&ps);
}

void iterFromBack(Node *root) {
    Stack *ps = createStack();
    Node *lnp = NULL;
    Node *peekn = NULL;

    while (!ps->size == 0 || root != NULL) {
        if (root) {
            push(ps, root);
            root = root->left;
        } else {
            peekn = peek(ps);
            if (peekn->right && lnp != peekn->right) {
                root = peekn->right;
            } else {
                pop(ps);
                printf("Посещено %d\n", peekn->key);
                lnp = peekn;
            }
        }
    }

    freeStack(&ps);
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
                            "Создано новое дерево. Начинается добавление элементов...\n\n"
                            "Добавлен элемент 8\n"
                            "Добавлен элемент 4\n"
                            "Добавлен элемент 9\n"
                            "Добавлен элемент 1\n"
                            "Добавлен элемент 10\n"
                            "Добавлен элемент 12\n"
                            "Добавлен элемент 0\n"
                            "Добавлен элемент 11\n"
                            "Добавлен элемент 3\n"
                            "Добавлен элемент 2\n"
                            "\nСовершим обратный обход дерева:\n";
                    Insert(test, 4);
                    Insert(test, 9);
                    Insert(test, 1);
                    Insert(test, 6);
                    Insert(test, 10);
                    Insert(test, 5);
                    Insert(test, 11);
                    Insert(test, 7);
                    Insert(test, 12);
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