#include <iostream>
using namespace std;


// Tạo node
struct Node
{
    int a;      // hệ số
    int n;      // bậc mũ
    Node* next; // con trỏ tới phần tử tiếp theo
};

Node* CreateNode(int a, int n)
{
    if (a == 0) return NULL;
    Node* node = new Node;
    node->a = a;
    node->n = n;
    node->next = NULL;
    return node;
}


// Tạo danh sách liên kết đơn
struct LinkedList
{
    Node* head;
    Node* tail;
};

void InitList(LinkedList* list)
{
    list->head = NULL;
    list->tail = NULL;
}


// Thêm node vào danh sách
void AddNode(LinkedList* list, Node* node)
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


// Gán giá trị hệ số và bậc mũ vào node
void AssignNode(LinkedList* list, int a, int n)
{
    Node* node = CreateNode(a, n);
    AddNode(list, node);
}


// Duyệt danh sách
void CreateList(LinkedList* list)
{
    int a;
    int n;
    do
    {
        cin >> a;
        if (a == 0)
        {
            break;
        }
        cin >> n;
        AssignNode(list, a, n);
    } while (a != 0);
}

void PrintList(LinkedList list)
{
    Node* node = list.head;
    bool k = true;
    cout << "\nf(x) = ";
    while (node != NULL)
    {
        if (node->a > 0 && !k)      cout << " + ";
        if (node->a < 0)            cout << " - ";

        if (abs(node->a) == 1)
        {
            if (node->n == 0)       cout << abs(node->a);
            else if (node->n == 1)  cout << "x";
            else                    cout << "x^" << node->n;
        }
        else
        {
            if (node->n == 0)       cout << abs(node->a);
            else if (node->n == 1)  cout << abs(node->a) << "x";
            else                    cout << abs(node->a) << "x^" << node->n;
        }
        node = node->next;
        k = false;
    }
}


int main()
{
    LinkedList list;
    InitList(&list);
    CreateList(&list);
    PrintList(list);
    return 0;
}