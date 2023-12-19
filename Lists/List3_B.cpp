#include <iostream>
using namespace std;

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
void insert(BST* bst, int k, int e);
Node* inserthelp(Node* rt, int k, int e);
void preorder(Node* rt);
void inorder(Node* rt);
void posorder(Node* rt);


int main(){

    int n=0, k=0;
    BST* tree;
    cin >> n;

    tree = createBST();

    for(int i=0; i<n; i++){
        cin >> k;
        insert(tree, k, k);
    }

    cout << "Pre order :";
    preorder(tree->root);
    cout << "\n";
    cout << "In order  :";
    inorder(tree->root);
    cout << "\n";
    cout << "Post order:";
    posorder(tree->root);

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

void preorder(Node* rt){
    if(rt!=NULL){
        cout << " " << rt->element;
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(Node* rt){
    if(rt!=NULL){
        inorder(rt->left);
        cout << " " << rt->element;
        inorder(rt->right);
    }
}

void posorder(Node* rt){
    if(rt!=NULL){
        posorder(rt->left);
        posorder(rt->right);
        cout << " " << rt->element;
    }
}