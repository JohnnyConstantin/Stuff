#include <iostream>
#include <string>
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

void print(Node *p){
    cout << p->height;
}

void summ(Node *root, int &sum) {
    if (root != NULL) {
        sum += root->key;
        summ(root->left, sum);
        summ(root->right, sum);
    }
}

Node *Insert(Node *x, int k)
{
    if (!x) return new Node(k);
    if (k<x->key) x->left=Insert(x->left, k);
    else x->right=Insert(x->right, k);
    return balance(x);
}

int main(){
    Node *node = new Node(8);
    Insert(node, 4);
    Insert(node, 9);
    int sum = 0;
    summ(node,sum);
    cout << sum << endl;
    print(node);
    return 0;
}