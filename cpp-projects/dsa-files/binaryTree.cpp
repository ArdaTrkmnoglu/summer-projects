#include <iostream>
using namespace std;

typedef struct treeNode treeNode;

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    treeNode* parent;
};

treeNode* createNodeWithParent(int data, treeNode* parent) {
    treeNode* newNode = new treeNode;       // treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

void preorder(treeNode* ptr) {              // root->left->right
    if (ptr) {
        cout << ptr->data << " \n";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(treeNode* ptr) {               // left->root->right
    if (ptr) {
        inorder(ptr->left);
        cout << ptr->data << " \n";
        inorder(ptr->right);
    }
}

void postorder(treeNode* ptr) {             // left->right->root
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " \n";
    }
}

int main() {

    treeNode* root = createNodeWithParent(1, NULL);             // level 0

    root->left = createNodeWithParent(2, root);                 // level 1
    root->right = createNodeWithParent(3, root);

    root->left->left = createNodeWithParent(4, root->left);     // level 2
    root->left->right = createNodeWithParent(5, root->left);

    

    delete(root->left->right);
    delete(root->left->left);
    delete(root->right);
    delete(root->left);
    delete(root);
    return 0;
}