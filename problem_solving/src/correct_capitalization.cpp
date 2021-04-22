#include<iostream>

using namespace std;

bool isCapitalCorrect(char* str){
	enum capType {lower, upper, capfirst} captype;
	if (str[1]=='\0') return true;
	if (str[0] > 96 && str[0] < 123) captype = lower;
	else if (str[0] >64 && str[0]<91 && str[1] >64 && str[1]<91) captype = upper;
	else captype = capfirst;
	++str;
	while(*str != '\0') {
		switch(captype) {
			case lower:
				if (*str > 96 && *str <123) break;
				else return false;
			case capfirst:
				if (*str > 96 && *str < 123) break;
				else return false;
			case upper:
				if (*str >64 && *str <91) break;
				else return false;
		}
		++str;
	}
	return true;
}
int main(){

cout<<isCapitalCorrect("A")<<" A"<<endl;
cout<<isCapitalCorrect("ABC")<<" ABC"<<endl;
cout<<isCapitalCorrect("abcde")<<" abcde"<<endl;
cout<<isCapitalCorrect("aBcdE")<<" aBcdE"<<endl;
cout<<isCapitalCorrect("Abcdef")<<" Abcdef"<<endl;
cout<<isCapitalCorrect("Ab")<<" Ab"<<endl;
cout<<isCapitalCorrect("aB")<<" aB"<<endl;
cout<<isCapitalCorrect("aCb")<<" aCb"<<endl;

return 0;
}
