#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

Node *createNode(string data)
{
    Node *node = new Node();
    node->data = data;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

void initialize(Node *&root)
{
    root = NULL;
}

bool isEmpty(Node *root)
{
    return root == NULL;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char o)
{
    if (o == '+' || o == '-') return 1;
    if (o == '*' || o == '/') return 2;
    if (o == '^')             return 3;
    return 0;
}

Node *buildTree(string str, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int parentheses = 0;
    int min_p =  3;
    int split = -1;

    for (int i = start; i <= end; i++)
    {
        char c = str[i];
        if      (c == '(') parentheses++;
        else if (c == ')') parentheses--;
        else if (isOperator(c) && parentheses == 0)
        {
            int p = precedence(c);
            if (min_p >= p)
            {
                min_p = p;
                split = i;
            }
        }
    }

    if (split == -1)
    {
        if (str[start] == '(' && str[end] == ')')
        {
            return buildTree(str, start + 1, end - 1);
        }
        return createNode(str.substr(start, end - start + 1));
    }

    Node *root = createNode(string(1, str[split]));
    root->left  = buildTree(str, start    , split - 1);
    root->right = buildTree(str, split + 1, end      );
    return root;
}

void inorderTraversal(Node *root)
{
    if (!isEmpty(root))
    {
        inorderTraversal(root->left);
        cout << root->data;
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root)
{
    if (!isEmpty(root))
    {
        cout << root->data;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (!isEmpty(root))
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data;
    }
}

void input(Node *&root)
{
    string str;
    cout << "Biểu thức: ";
    getline(cin, str);
    root = buildTree(str, 0, str.length() - 1);
}

void output(Node *root)
{
    if (isEmpty(root))
    {
        cout << "Cây rỗng\n";
        return;
    }
    cout << "Trung tố : ";
    inorderTraversal(root);
    cout << "\n";

    cout << "Tiền tố  : ";
    preorderTraversal(root);
    cout << "\n";

    cout << "Hậu tố   : ";
    postorderTraversal(root);
    cout << "\n";
}

int main()
{
    Node *root;
    initialize(root);
    input(root);
    output(root);
    return 0;
}