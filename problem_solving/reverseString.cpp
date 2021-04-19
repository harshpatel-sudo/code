#include <iostream>
#include <cstring>
using namespace std;

char *reverse(char *str, int size)
{
    char *rev = new char[size + 1];
    for (int i = 0; i < size; ++i)
    {
        rev[i] = str[size - 1 - i];
    }
    rev[size] = '\0';
    return rev;
}

int main()
{
    char *str = "Reverse this string";
    char *revstr = reverse(str, strlen(str));
    cout << revstr << endl;
    delete revstr;
}