#include <iostream>
using namespace std;

// colocar find
// pequeno ajuste no inserthelp

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
Node* find(BST* bst, int k);
Node* findhelp(Node* rt, int k);
Node* findDad(BST* bst, int k);
Node* findDadHelp(Node* rt, int k, Node* dad);
int getindex(BST* bst, int k);
void inorder(Node* rt);


int main(){

    int n, k;
    cin >> n;
    
    BST* tree = createBST();

    for(int i=0; i<n; i++){
        cin >> k;
        insert(tree, k);
    }

    cin >> k;

    Node* pai = findDad(tree, k);

    cout << pai->key << "\n";

    return 0;
}

Node* createNode(int k){
    Node* n = new Node;
    n->key = k;
    n->height=0;
    n->left=n->right=NULL;
    return n;
}

BST* createBST(){
    BST* bst = new BST;
    bst->nodecount=0;
    bst->root=NULL;
    return bst;
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

Node* find(BST* bst, int k){
    return findhelp(bst->root, k);
}

Node* findhelp(Node* rt, int k){
    if(rt==NULL){
        return NULL;
    }
    if(rt->key>k){
        return findhelp(rt->left, k);
    }
    else if(rt->key==k){
        return rt;
    } 
    else {
        return findhelp(rt->right, k);
    }
}

Node* findDad(BST* bst, int k){
    return findDadHelp(bst->root, k, NULL);
}

Node* findDadHelp(Node* rt, int k, Node* dad){
    if(rt==NULL){
        return NULL;
    }
    if(rt->key>k){
        // pai = rt
        return findDadHelp(rt->left, k, rt);
    }
    else if(rt->key==k){
        return dad;
    } 
    else {
        // pai = rt
        return findDadHelp(rt->right, k, rt);
    }
}

int getindex(BST* bst, int k){
    // tem filho da esquerda? indexFilhoEsquerda+1 : indexPai+1
    // ou
    // qtd filhos Pai + qtd filhos FilhoEsquerda
    // falta: referencia Pai - ok

    

    return 0;
}

void inorder(Node* rt, int k, int* index){
    if(rt!=NULL){
        inorder(rt->left);
        (*index)++;
    }
}
