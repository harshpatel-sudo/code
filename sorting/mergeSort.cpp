#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int larr[n1];
    int rarr[n2];
    for (int i = 0; i < n1; ++i)
    {
        larr[i] = arr[l + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        rarr[i] = arr[m + i + 1];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (larr[i] <= rarr[j])
        {
            arr[k++] = larr[i++];
        }
        else
        {
            arr[k++] = rarr[j++];
        }
    }
    while (i < n1)
        arr[k++] = larr[i++];
    while (j < n2)
        arr[k++] = rarr[j++];
}
void merge_sort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main()
{
    int arr[] = {2, 4, 3, 5, 9, 8, 1, 7, 6, 0};
    merge_sort(arr, 0, 10);
    for (int i = 0; i < 10; ++i)
        cout << arr[i] << endl;
    return 0;
}