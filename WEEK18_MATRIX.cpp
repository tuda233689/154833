#include <iostream>
#include <string>
using namespace std;

const int MAX = 15;
struct Node
{
    int data;
    Node *next;
};

// Stack
struct Stack
{
    Node *top;
};

void initStack(Stack &S)
{
    S.top = NULL;
}

bool isEmptyStack(Stack &S)
{
    return S.top == NULL;
}

void pushStack(Stack &S, int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = S.top;
    S.top = node;
}

int popStack(Stack &S)
{
    if (isEmptyStack(S))
    {
        return 0;
    }
    else
    {
        Node *node = S.top;
        int data = node->data;
        S.top = S.top->next;
        delete node;
        return data;
    }
}

int top(Stack &S)
{
    if (isEmptyStack(S))
    {
        return 0;
    }
    else
    {
        return S.top->data;
    }
}

// Queue
struct Queue
{
    Node *front;
    Node *rear;
};

void initQueue(Queue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}

bool isEmptyQueue(Queue &Q)
{
    return Q.front == NULL;
}

void pushQueue(Queue &Q, int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;

    if (isEmptyQueue(Q))
    {
        Q.front = node;
        Q.rear = node;
    }
    else
    {
        Q.rear->next = node;
        Q.rear = node;
    }
}

int popQueue(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        return 0;
    }
    else
    {
        Node *node = new Node();
        int data = node->data;
        Q.front = Q.front->next;
        if (Q.front == NULL)
        {
            Q.rear = NULL;
        }
        delete node;
        return data;
    }
}

int front(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        return 0;
    }
    else
    {
        return Q.front->data;
    }
}

int rear(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        return 0;
    }
    else
    {
        return Q.rear->data;
    }
}

// Graph
struct Graph
{
    int V;
    int E[MAX][MAX];
};

void initGraph(Graph &G, int V)
{
    G.V = V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            G.E[i][j] = 0;
        }
    }
}

void addEdge(Graph &G, int u, int v)
{
    G.E[u][v] = 1;
}

void displayAdjMatrix(Graph &G)
{
    cout << "Matrix:\n";
    for (int i = 0; i < G.V; i++)
    {
        for (int j = 0; j < G.V; j++)
        {
            cout << G.E[i][j] << " ";
        }
        cout << "\n";
    } 
}

// BFS
void BFS(Graph &G, int start)
{
    Queue Q;
    initQueue(Q);
    pushQueue(Q, start);
    bool visited[MAX] = {0};
    visited[start] = 1;

    cout << "BFS: \n";
    while (!isEmptyQueue(Q))
    {
        int u = front(Q);
        popQueue(Q);

        cout << u << " ";

        for (int v = 0; v < G.V; v++)
        {
            if (G.E[u][v] == 1 && !visited[v])
            {
                visited[v] = 1;
                pushQueue(Q, v);
            }
        }
    }
    cout << "\n";
}

// DFS
void DFS(Graph &G, int start)
{
    Stack S;
    initStack(S);
    pushStack(S, start);
    bool visited[MAX] = {0};

    cout << "DFS: \n";
    while (!isEmptyStack(S))
    {
        int u = top(S);
        popStack(S);

        if (!visited[u])
        {
            visited[u] = 1;
            cout << u << " ";
        }

        for (int v = G.V - 1; v >= 0; v--)
        {
            if (G.E[u][v] == 1 && !visited[v])
            {
                pushStack(S, v);
            }
        }
    }
    cout << "\n";
}

void inputGraph(Graph &G, int E)
{
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(G, u , v);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    Graph G;
    initGraph(G, V);
    inputGraph(G, E);

    int start = 0;
    displayAdjMatrix(G);
    BFS(G, start);
    DFS(G, start);

    return 0;
}

// G(V, E) = G(7, 10)
// a  b  c  d  e  f  g
// 0  1  2  3  4  5  6  7
// a->b: 0 1
// a->c: 0 2
// a->d: 0 3
// b->e: 1 4
// d->e: 3 4
// d->f: 3 5
// e->f: 4 5
// e->g: 4 6
// g->b: 6 1
// g->f: 6 5

// Input:
// 7 10
// 0 1
// 0 2
// 0 3
// 1 4
// 3 4
// 3 5
// 4 5
// 4 6
// 6 1
// 6 5

// Output:
// Matrix:
// 0 1 1 1 0 0 0
// 0 0 0 0 1 0 0
// 0 0 0 0 0 0 0
// 0 0 0 0 1 1 0
// 0 0 0 0 0 1 1
// 0 0 0 0 0 0 0
// 0 1 0 0 0 1 0
// BFS:
// 0 1 2 3 4 5 6
// DFS:
// 0 1 4 5 6 2 3