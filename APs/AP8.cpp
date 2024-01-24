#include <iostream>

using namespace std;

typedef struct BSTNode{
    int key;
    int height;
    struct BSTNode* left;
    struct BSTNode* right;
}Node;

typedef struct{
    Node* root;
    int nodecount;
}BST;

Node* createNode(int k);
BST* createBST();
void insert(BST* bst, int k);
Node* inserthelp(Node* rt, int k);
int getBalance(Node* rt);
int h(Node* rt);
Node* rightRotate(Node* rt);
Node* leftRotate(Node* rt);

int main(){

    return 0;
}

Node* createNode(int k){
    Node* n = new Node;
    n->key = k;
    n->height=-1;
    n->left=n->right=NULL;
    return n;
}

BST* createBST(){
    BST* bst = new BST;
    bst->nodecount=0;
    bst->root=NULL;
}

void insert(BST* bst, int k){
    bst->root = inserthelp(bst->root, k);
    bst->nodecount++;
}

Node* inserthelp(Node* rt, int k){
    if(rt==NULL){
        return createNode(k);
    }
    else if(rt->key>k){
        rt->left = inserthelp(rt->left, k);
    }
    else{
        rt->right = inserthelp(rt->right, k);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if(balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if(balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }
    if(balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if(balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

int getBalance(Node* rt){
    if(rt==NULL)
        return 0;
    return h(rt->left)-h(rt->right);
}

int h(Node* rt){
    if(rt==NULL)
        return -1;
    return rt->height;
}

Node* rightRotate(Node* rt){
    Node* l = rt->left;
    Node* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    l->height = 1 + max(h(l->left), h(l->right));
    return l;
}

Node* leftRotate(Node* rt){
    Node* r = rt->right;
    Node* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(h(rt->left), h(rt->right));
    r->height = 1 + max(h(r->left), h(r->right));
    return r;
}
