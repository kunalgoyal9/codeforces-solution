#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fors(w,s,x) for(int w=s; w<x; w++)


int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int maxm = -999999999;
	
	fors(i,0,n+1){
		int na = i;
		int nb = n-i;
		maxm = max(maxm,min((int)floor((float)a/(float)na),(int)floor((float)b/(float)nb)));
	}
	cout<<maxm;
	
	return 0;
}
