#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *arr, int l, int r)
{
    int pi = r;
    int i = l - 1;
    for (int j = l; j < r ; ++j)
    {
        if (arr[j] < arr[pi])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pi]);
    return i + 1;
}

void quick_sort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quick_sort(arr, l, pi - 1);
        quick_sort(arr, pi + 1, r);
    }
}
int main()
{
    int arr[] = {2, 4, 3, 5, 9, 8, 1, 7, 6, 0};
    quick_sort(arr, 0, 9);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << endl;
    return 0;
}