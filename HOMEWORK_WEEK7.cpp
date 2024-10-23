#include <iostream>
#include <string>

using namespace std;

struct POPULATION {
    int year;
    int count; 
};


void MAX_MIN(POPULATION a[], int n)
{
    int max_count = a[0].count;
    int min_count = a[0].count;
    string max_output = "";
    string min_output = "";

    for (int i = 0; i < n; i++)
    {
        if (max_count < a[i].count)
        {
            max_count = a[i].count;
        }
        if (min_count > a[i].count)
        {
            min_count = a[i].count;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i].count == max_count)
        {
            max_output += to_string(a[i].year) + ", ";
        }
        if (a[i].count == min_count)
        {
            min_output += to_string(a[i].year) + ", ";
        }
    }

    cout << "Các năm có số lượng người sinh ra là lớn nhất là " << max_output << "với " << max_count << " người.\n";
    cout << "Các năm có số lượng người sinh ra là nhỏ nhất là " << min_output << "với " << min_count << " người.\n";
}

int main()
{
    int n;
    cin >> n;
    POPULATION a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].year;
        cin >> a[i].count;
    }

    MAX_MIN(a, n);

    return 0;
}