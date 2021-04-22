#include<iostream>

using namespace std;

bool isCircular(const char* path) {
	int horizontal=0,vertical=0;
	while(*path != '\0'){
		switch(*(path++)) {
			case 'L': ++horizontal; break;
			case 'R': --horizontal; break;
			case 'U': ++vertical;   break;
			case 'D': --vertical;   break;
		}
	}
	if (horizontal || vertical)
		return false;
	return true;
}

int main(){
cout<<isCircular("LR")<<endl;
cout<<isCircular("LRUD")<<endl;
cout<<isCircular("UDLR")<<endl;
cout<<isCircular("LLLUUURRDDDR")<<endl;
cout<<isCircular("LUUUUDDDDDR")<<endl;
cout<<isCircular("RUULLDRD")<<endl;
cout<<isCircular("URURD")<<endl;
}
