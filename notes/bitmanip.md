```C++
#include<iostream>

using namespace std;

int main(){
    int a=10;
    unsig =10;
    int na = -10;
    int shift = 555;
    a=a<<shift;
    ua=ua<<shift;
    na=na<<shift;
    cout<<"Left Shift  "<<shift<<" a: "<<a<<" ua: "<<ua<<" na: "<<na<<endl;
    a=a>>shift;
    ua=ua>>shift;
    na=na>>shift;
    cout<<"Right Shift "<<shift<<" a: "<<a<<" ua: "<<ua<<" na: "<<na<<endl;

    unsigned int d = 2147483648;
    //for(int i = 0; i<34 ; i++)
    //{
        d = d >> 31;
        cout << d << endl;
    //}
}
```