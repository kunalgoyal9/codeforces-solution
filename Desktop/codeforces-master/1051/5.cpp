#include<iostream> 
using namespace std; 
  
class Base { 
public: 
    virtual int fun(int i) {
		cout<<"base"; } 
}; 
  
class Derived: public Base { 
private: 
    int fun(int x)   {
		cout<<"derived";  } 
}; 

int main() 
{ 
    Derived d; 
    Base * p = &d;
    p->fun(1); 
    return 0; 
} 
