#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        int key = arr[i];
        while (key < arr[j])
        {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {2, 4, 3, 5, 9, 8, 1, 7, 6, 0};
    insertion_sort(arr, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << endl;
    return 0;
}