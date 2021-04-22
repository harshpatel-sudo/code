#include<iostream>

using namespace std;

bool isValid(char &c){
	if(c>96 && c < 123)
		return true;
	return false;
}

bool isPalindrome(char* str){
	size_t n = 0;
	while(str[n]!='\0'){
		if (str[n]>64 && str[n] < 91) //Convert to lower case
			str[n]+=32;
		++n;
	}
	int front=-1,end=n;
	while(front<end){
		while(!isValid(str[++front])){}
		while(!isValid(str[--end])){}
		if(str[front] != str[end]) return false;
		return true;
	}
}

int main(){
	cout<<isPalindrome("Nayan\0")<<endl;
	cout<<isPalindrome("nayan\0")<<endl;
	cout<<isPalindrome("n;a;y;a;n\0")<<endl;
	cout<<isPalindrome("N! @a_y(a)n\0")<<endl;
	cout<<isPalindrome("Nayn\0")<<endl;
	cout<<isPalindrome("Nayan\0")<<endl;
	cout<<isPalindrome("Nayan\0")<<endl;
	cout<<isPalindrome("Nayan\0")<<endl;
	return 0;
}
