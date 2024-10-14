#include <iostream>

using namespace std;

void SWAP(int *a, int *b)
{
    int TEMP = *a;
    *a = *b;
    *b = TEMP;
    
}

void SELECTION_SORT(int n, int arr[])
{
    int MIN_INDEX;

    for (int i = 0; i < n - 1; i++)
    {
        MIN_INDEX = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[MIN_INDEX])
            {
                MIN_INDEX = j;
            }
        }
        SWAP(&arr[MIN_INDEX], &arr[i]);
    }
}

void INSERTION_SORT(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i;
        while (arr[j - 1] > x && j > 0)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    string s = "";
    string str[3] = {"red", "white", "blue"};
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == str[0]) arr[i] = 0;
        if (s == str[1]) arr[i] = 1;
        if (s == str[2]) arr[i] = 2;
    }
    INSERTION_SORT(n, arr);
    for (int i = 0; i < n; i++)
    {
        cout << str[arr[i]] << " ";
    }
    return 0;
}

// Input {xanh, đỏ, xanh, đỏ, đỏ, trắng, đỏ, xanh, trắng}
// Output {đỏ, đỏ, đỏ, đỏ, trắng, trắng, xanh, xanh, xanh}