#include <iostream>
using namespace std;

struct Node
{
    string word;
    int count;
    Node *next;
};

Node *CreateNode(string word)
{
    Node *node = new Node;
    node->word = word;
    node->count = 1;
    node->next = NULL;
    return node;
}

struct LinkedList
{
    Node *head;
    Node *tail;
};

void InitList(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void AddNode(LinkedList *list, Node *node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

void AssignNode(LinkedList *list, string word)
{
    Node *i = list->head;
    while (i != NULL)
    {
        if (i->word == word)
        {
            i->count++;
        }
        i = i->next;
    }
    Node *node = CreateNode(word);
    if (node != NULL)
    {
        AddNode(list, node);
    }
}

void CreateList(LinkedList *list)
{
    string word;
    do
    {
        cin >> word;
        if (word == ".")
        {
            break;
        }
        AssignNode(list, word);
    } while (word != ".");
    
}

string theMostFrequentWord(LinkedList *list)
{
    Node *i = list->head;
    string w = "";
    int c = 0;
    while (i != NULL)
    {
        if (i->count > c)
        {
            w = i->word;
            c = i->count;
        }
        i = i->next;
    }
    return w;
}

void DeleteReduplicatedWord(LinkedList *list)
{
    Node *i = list->head;
    while (i != NULL && i->next != NULL)
    {
        if (i->word == i->next->word)
        {
            Node *t = i->next;
            i->next = t->next;
            delete t;
            if (i->next == NULL)
            {
                list->tail = i;
            }
        }
        else
        {
            i = i->next;
        }
    }
}

int CountWord(LinkedList *list)
{
    int count = 0;
    Node *i = list->head;
    while (i != NULL)
    {
        count++;
        i = i->next;
    }
    return count;
}

void PrintList(LinkedList *list)
{
    Node *i = list->head;
    DeleteReduplicatedWord(list);
    while (i != NULL)
    {
        cout << i->word << " ";
        i = i->next;
    }
    cout << "\n";
}

int main()
{
    LinkedList list;
    InitList(&list);
    CreateList(&list);
    PrintList(&list);
    cout << "Từ xuất hiện nhiều nhất: " << theMostFrequentWord(&list) << "\n";
    cout << "Số từ trong câu là: " << CountWord(&list);
    return 0;
}