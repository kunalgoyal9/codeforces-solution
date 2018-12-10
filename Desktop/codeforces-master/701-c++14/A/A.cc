#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fors(w,s,x) for(int w=s; w<x; w++)
int main(){
	int n;
	cin>>n;
	vector<int> arr;
	fors(i,0,n){
		int t;
		cin>>t;
		arr.push_back(t);
	}
	vector<int> cntivs;
	int cnt = 0;
	fors(i,0,n){
		fors(j,i+1,n){
			if(arr[i]>arr[j]) cnt++;
		}
	}
	//cout<<cnt;
	int q;
	cin>>q;
	fors(i,0,q){
		int l,r;
		cin>>l>>r;
		int len = r-l;
		len = len*(len+1);
		len>>=1;
		if(((cnt%2==1) && (len%2==1)) or ((cnt%2==0) and (len%2)==0)){
			cout<<"even"<<endl;
			cnt = 2;
		}
		else{
			cout<<"odd"<<endl;
			cnt=3;
		}
	}
	return 0;
}
