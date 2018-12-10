#include<bits/stdc++.h>

using namespace std;

class parent{
	public: 
		int a=9; 
		parent(){
			cout<<"parent\n";
		}
};

class child1{
	public:
		child1(){
			cout<<"child1\n";
		}
};

class child2: child1,parent{
	public:
		int b=9;
		int aa = a; 
		child2(){
			cout<<"child2\n";
		}
};

int main(){
	child2 ch;
	
	return 0;
}
