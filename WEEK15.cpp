#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string title;
    Node *children[10];
    int childrenCount;

    Node(string t) : title(t), childrenCount(0) {}
};

Node *createNode(string title)
{
    Node *newNode = new Node(title);
    return newNode;
}

void addChild(Node *parent, string title)
{
    parent->children[parent->childrenCount++] = createNode(title);
}

void deleteNode(Node *parent, Node *node, int k)
{
    for (int i = k; i < parent->childrenCount - 1; i++)
    {
        parent->children[i] = parent->children[i + 1];
    }
    parent->childrenCount--;
    delete node;
}

void deleteChild(Node *root, string title)
{
    for (int i = 0; i < root->childrenCount; i++)
    {
        if (root->children[i]->title == title)
        {
            deleteNode(root, root->children[i], i);
            return;
        }
    }
    for (int i = 0; i < root->childrenCount; i++)
    {
        deleteChild(root->children[i], title);
    }
}

Node *longestChapter(Node *root)
{
    Node *chapter = root->children[0];
    for (int i = 1; i < root->childrenCount; i++)
    {
        if (root->children[i]->childrenCount > chapter->childrenCount)
        {
            chapter = root->children[i];
        }
    }
    return chapter;
}

void input(Node *parent)
{
    int i = 0;
    string title;
    while (1)
    {
        getline(cin, title);
        addChild(parent, title);
        if (title.back() == '.') break;
        if (title.back() == ':') input(parent->children[i++]);
    }
}

void output(Node *parent, int level = 0)
{
    for (int i = 0; i < level; i++)
    {
        cout << "  ";
    }
    cout << parent->title << endl;
    for (int i = 0; i < parent->childrenCount; i++)
    {
        output(parent->children[i], level + 1);
    }
}

int main()
{
    Node *book = createNode("Book");
    input(book);
    cout << "--------------------" << endl;
    output(book);

    cout << "Số chương: " << book->childrenCount << endl;
    cout << "Chương dài nhất: " << longestChapter(book)->title;
    return 0;
}

// INPUT:
// Chapter 1:
//   Section 1
//   Section 2
//   Section 3.
// Chapter 2:
//   Section 1
//   Section 2.
// Chapter 3.