#include <iostream>
using namespace std;

struct Product
{
    string name;
    int nProduct;
    int price;
};

struct Cart
{
    Product *product;
    int nType;
    int price;
};

struct Node
{
    Cart cart;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

void initialize(Queue &queue)
{
    queue.front = NULL;
    queue.rear = NULL;
}

bool isEmpty(Queue &queue)
{
    return queue.front == NULL;
}

void enqueue(Queue &queue, Cart cart)
{
    Node *node = new Node();
    node->cart = cart;
    node->next = NULL;

    if (isEmpty(queue))
    {
        queue.front = node;
        queue.rear = node;
    }
    else
    {
        queue.rear->next = node;
        queue.rear = node;
    }
}

void dequeue(Queue &queue)
{
    if (!isEmpty(queue))
    {
        Node *node = queue.front;
        queue.front = queue.front->next;
        
        delete[] node->cart.product;
        delete node;
        
        if (queue.front == NULL)
        {
            queue.rear = NULL;
        }
    }
    else
    {
        cout << "Hàng đợi trống\n";
    }
}

int pay(Queue &queue)
{
    if (!isEmpty(queue))
    {
        int price = queue.front->cart.price;
        dequeue(queue);
        return price;
    }
    return 0;
}

int revenue(Queue &queue)
{
    int revenue = 0;
    while (!isEmpty(queue))
    {
        revenue += pay(queue);
    }
    return revenue;
}

int countProduct(Queue &queue, string name)
{
    int count = 0;
    Node *node = queue.front;

    while (node != NULL)
    {
        for (int i = 0; i < node->cart.nType; i++)
        {
            if (node->cart.product[i].name == name)
            {
                count += node->cart.product[i].nProduct;
            }
        }
        node = node->next;
    }
    return count;
}

void input(Queue &queue)
{
    int nCart;

    cout << "Số lượng khách hàng: ";
    cin >> nCart;

    for (int i = 0; i < nCart; i++)
    {
        Cart cart;
        cart.price = 0;

        cout << "Số loại sản phẩm trong giỏ của khách hàng thứ " << i + 1 << ": ";
        cin >> cart.nType;

        cart.product = new Product[cart.nType];

        for (int j = 0; j < cart.nType; j++)
        {
            cout << "Thông tin sản phẩm thứ " << j + 1 << "\n";
            cout << "|Tên|Số lượng|Giá tiền|\n  ";
            cin >> cart.product[j].name >> cart.product[j].nProduct >> cart.product[j].price;
            cart.price += cart.product[j].nProduct * cart.product[j].price;
        }
        enqueue(queue, cart);
    }
}

void output(Queue &queue)
{
    int cnt = countProduct(queue, "A");
    int rev = revenue(queue);

    cout << "-----------------------------------\n";
    cout << "Doanh thu           : " << rev << "\n";
    cout << "Số sản phẩm A đã bán: " << cnt;
}

int main()
{
    Queue queue;
    initialize(queue);
    input(queue);
    output(queue);

    return 0;
}

// Số lượng khách hàng: 4
// Số loại sản phẩm trong giỏ của khách hàng thứ 1: 2
// Thông tin sản phẩm thứ 1
// |Tên|Số lượng|Giá tiền| 
//   B     10      2000
// Thông tin sản phẩm thứ 2
// |Tên|Số lượng|Giá tiền| 
//   C     1       3000
// Số loại sản phẩm trong giỏ của khách hàng thứ 2: 1
// Thông tin sản phẩm thứ 1
// |Tên|Số lượng|Giá tiền| 
//   A     5       1000
// Số loại sản phẩm trong giỏ của khách hàng thứ 3: 2
// Thông tin sản phẩm thứ 1
// |Tên|Số lượng|Giá tiền| 
//   C     2       3000
// Thông tin sản phẩm thứ 2
// |Tên|Số lượng|Giá tiền| 
//   A     1       1000
// Số loại sản phẩm trong giỏ của khách hàng thứ 4: 3
// Thông tin sản phẩm thứ 1
// |Tên|Số lượng|Giá tiền| 
//   A     5       1000
// Thông tin sản phẩm thứ 2
// |Tên|Số lượng|Giá tiền|
//   B     5       2000
// Thông tin sản phẩm thứ 3
// |Tên|Số lượng|Giá tiền|
//   A     1       1000
// -----------------------------------
// Doanh thu           : 51000
// Số sản phẩm A đã bán: 12