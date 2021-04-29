#include<iostream>

using namespace std;

void printArr(int *arr[3]){
    cout<<arr[1][2];

}

int main(){
    int arr[2][3]={0,1,2,3,4,5};
    printArr((*arr)[3]);
}