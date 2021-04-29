#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minidx = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minidx])
            {
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
}

int main()
{
    int arr[] = {2, 4, 3, 5, 9, 8, 1, 7, 6, 0};
    selection_sort(arr, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << endl;
    return 0;
}