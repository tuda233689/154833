#include <iostream>
using namespace std;

struct Node
{
    string fileName;    // test.cpp
    string filePath;    // D>Document
    int fileTime;       // 20241120
    int fileSize;       // 200 (MB)
    Node *next;
};

Node *CreateNode(string fileName, string filePath, int fileTime, int fileSize)
{
    Node *node = new Node;
    node->fileName = fileName;
    node->filePath = filePath;
    node->fileTime = fileTime;
    node->fileSize = fileSize;
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

void AddFile(LinkedList *list, Node *node)
{
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else if (node->fileTime < list->head->fileTime)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        Node *i = list->head;
        while (i->next != NULL && i->next->fileTime <= node->fileTime)
        {
            i = i->next;
        }
        node->next = i->next;
        i->next = node;
    }
    if (node->next == NULL)
    {
        list->tail = node;
    }
}

void CopyPaste(LinkedList *list, string fileName, string filePath, int fileTime, int fileSize)
{
    Node *node = CreateNode(fileName, "D>Document", fileTime, fileSize);
    AddFile(list, node);
}

void CreateList(LinkedList *list)
{
    string fileName;
    string filePath;
    int fileTime;
    int fileSize;
    do
    {
        cin >> fileName;
        if (fileName == ".")
        {
            break;
        }
        cin >> filePath >> fileTime >> fileSize;
        CopyPaste(list, fileName, filePath, fileTime, fileSize);
    } while (fileName != ".");
}

int CalculateFilesSize(LinkedList *list)
{
    int filesSize = 0;
    Node *i = list->head;
    while (i != NULL)
    {
        filesSize += i->fileSize;
        i = i->next;
    }
    return filesSize;
}

void PrintList(LinkedList *list)
{
    Node *i = list->head;
    cout << "Danh sách các tệp trong thư mục D>Document\n";
    cout << "---------------------------------------------\n";
    while (i != NULL)
    {
        cout << "Tên tệp: " << i->fileName << "\n";
        cout << "Địa chỉ: " << i->filePath << "\n";
        cout << "Thời gian tạo: " << i->fileTime << "\n";
        cout << "Kích thước: " << i->fileSize << "\n";
        cout << "---------------------------------------------\n";
        i = i->next;
    }
}

int main()
{
    LinkedList list;
    InitList(&list);
    CreateList(&list);
    PrintList(&list);
    cout << "Kích thước của tệp D>Document: " << CalculateFilesSize(&list);
    return 0;
}