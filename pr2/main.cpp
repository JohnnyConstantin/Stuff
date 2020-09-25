#include <iostream>

using namespace std;

struct Node
{
    int key;
    char height;
    Node *right;
    Node *left;
    Node(int k) { key=k; height=1; left=right=0; }
};

char height(Node *p)
{
    if (p) return p->height;
    else return 0;
}

int BF(Node *p)
{ return height(p->right)-height(p->left); }

void OverHeight(Node *p)
{
    char hleft=height(p->left);
    char hright=height(p->right);
    p->height=(hleft>hright ? hleft : hright)+1;
}

Node* RightRotation(Node *x)
{
    Node *y=x->left;
    x->left=y->right;
    y->right=x;
    OverHeight(x);
    OverHeight(y);
    return y;
}
Node *LeftRotation(Node *y)
{
    Node *x=y->right;
    y->right=x->left;
    x->left=y;
    OverHeight(y);
    OverHeight(x);
    return x;
}

Node *Balance(Node *x)
{
    OverHeight(x);
    if (BF(x)==2)
    {
        if (BF(x->right)<0) x->right=RightRotation(x->right);
        return LeftRotation(x);
    }
    if (BF(x)==-2)
    {
        if (BF(x->left)>0) x->left=LeftRotation(x->left);
        return RightRotation(x);
    }
    return x;
}

Node *Insert(Node *x, int k)
{
    if (!x) return new Node(k);
    if (k<x->key) x->left=Insert(x->left, k);
    else x->right=Insert(x->right, k);
    return Balance(x);
}

int main(){
    Node *node = new Node(1);
    Insert(node, 2);
    Insert(node, 0);
    Insert(node, 5);
    return height(node);
}