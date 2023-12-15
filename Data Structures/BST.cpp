#include <iostream>

typedef struct BSTNode{
    int key;
    int element;
    struct BSTNode* left;
    struct BSTNode* right;
}Node;

typedef struct{
    int nodecount;
    Node* root;
}BST;

Node* createNode(int k, int e);
BST* createBST();
int find(BST* bst, int k);
int findhelp(Node* rt, int k);
void insert(BST* bst, int k, int e);
Node* inserthelp(Node* rt, int k, int e);
int remove(BST* bst, int k);
Node* removehelp(Node* rt, int k);
Node* getmin(Node* rt);
Node* deletemin(Node* rt);

int main(){



    return 0;
}

Node* createNode(int k, int e){
    Node *n = new Node;
    n->key=k;
    n->element=e;
    n->left=n->right=NULL;
    return n;
}

BST* createBST(){
    BST* bst = new BST;
    bst->root=NULL;
    bst->nodecount=0;
    return bst;
}

int find(BST bst, int k){
    return findhelp(bst.root, k);
}

int findhelp(Node* rt, int k){
    if(rt==NULL) 
        return -1;
    if(rt->key>k)
        return findhelp(rt->left, k);
    else if(rt->key==k)
        return rt->element;
    else 
        return findhelp(rt->right, k);
}

void insert(BST* bst, int k, int e){
    bst->root=inserthelp(bst->root, k, e);
    bst->nodecount++;
}

Node* inserthelp(Node* rt, int k, int e){
    if(rt==NULL)
        return createNode(k, e);
    else if(rt->key>k)
        rt->left=inserthelp(rt->left, k, e);
    else
        rt->right=inserthelp(rt->right, k, e);
    return rt;
}

int remove(BST* bst, int k){
    int temp = findhelp(bst->root, k);
    if(temp!=NULL){
        bst->root=removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

Node* removehelp(Node* rt, int k){
    if(rt==NULL) return NULL;
    if(rt->key>k)
        rt->left=removehelp(rt->left, k);
    else if(rt->key<k)
        rt->right=removehelp(rt->right, k);
    else{
        if(rt->left==NULL)
            return rt->right;
        else if(rt->right==NULL)
            return rt->left;
        else{
            Node* tmp = getmin(rt->right);
            rt->element = tmp->element;
            rt->key = tmp->key;
            rt->right = deletemin(rt->right);
        }
    }
}

Node* getmin(Node* rt){
    if(rt->left==NULL)
        return rt;
    return getmin(rt->left);
}

Node* deletemin(Node* rt){
    if(rt->left==NULL)
        return rt->right;
    rt->left=deletemin(rt->left);
    return rt;
}
