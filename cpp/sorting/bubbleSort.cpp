#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size-1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            } 
        }
        if (!swapped)
            break;
    }
}

int main()
{
  int arr[] = {2, 4, 3, 5, 9, 8, 1, 7, 6, 0};
    bubble_sort(arr, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << endl;
    return 0;
}