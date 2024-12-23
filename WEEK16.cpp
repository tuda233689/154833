#include <iostream>
using namespace std;

struct Node
{
    int key;
    int height;
    Node *left;
    Node *right;
};

Node *createNode(int key)
{
    Node *newNode = new Node();
    newNode->key  = key;
    newNode->height = 1;
    newNode->left   = NULL;
    newNode->right  = NULL;
    return newNode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *node)
{
    if (node == NULL) return 0;
    return node->height;
}

int balance(Node *node)
{
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T = x->right;

    x->right = y;
    y->left  = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T = y->left;

    y->left  = x;
    x->right = T;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int key)
{
    if (root == NULL) return createNode(key);

    if      (key < root->key)   root->left = insert(root->left, key);
    else if (key > root->key)   root->right = insert(root->right, key);
    else                        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int b = balance(root);

    // LL
    if (b > 1 && key < root->left->key) return rightRotate(root);

    // RR
    if (b < -1 && key > root->right->key) return leftRotate(root);

    // LR
    if (b > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (b < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->key << " ";
    }
}

int main()
{
    Node *root = NULL;
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        root = insert(root, key);
    }

    cout << "\nPreorder Traversal:  ";
    preOrderTraversal(root);

    cout << "\nInorder Traversal:   ";
    inOrderTraversal(root);
    
    cout << "\nPostorder Traversal: ";
    postOrderTraversal(root);

    return 0;
}
// INPUT:
// 12
// 17 23 201 98 67 83 13 23 10 191 84 58

// OUTPUT:
// Preorder Traversal:  67 17 13 10 23 58 98 83 84 201 191 
// Inorder Traversal:   10 13 17 23 58 67 83 84 98 191 201 
// Postorder Traversal: 10 13 58 23 17 84 83 191 201 98 67