#include <iostream>
#include <string>
#include <stack>
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

void iterInorder(Node *root) {
    Stack *ps = createStack();
    while (ps->size != 0 || root != NULL) {
        if (root != NULL) {
            push(ps, root);
            root = root->left;
        } else {
            root = pop(ps);
            printf("visited %d\n", root->key);
            root = root->right;
        }
    }
    freeStack(&ps);
}

void iterPostorder(Node *root) {
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
                printf("visited %d\n", peekn->key);
                lnp = peekn;
            }
        }
    }

    freeStack(&ps);
}

int main(){
    Node *node = new Node(8);
    Insert(node, 4);
    Insert(node, 9);
    Insert(node, 1);
    Insert(node, 10);
    int sum = 0;
    iterPostorder(node);
    iterInorder(node);
    countLeafs(node, sum);
    cout << sum;
    printHeight(node);
    return 0;
}