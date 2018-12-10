#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fors(xx,yy,zz) for(int xx=yy; xx<zz; xx++)
#define all(xx) xx.begin(),xx.end()
#define mod 1000000009
#define pii pair<int,int>;

vector<int> arr;

struct node{
	bool lazy;
	vector<int> change;
	node(){
		lazy=0;
		change.resize(101,0);
	}
};

vector<node> t;

void update(int pos, vector<int> &vec){
	fors(i,1,101){
		if(t[pos].change[i]!=0){
			if(vec[t[pos].change[i]]!=0)
			t[pos].change[i]=vec[t[pos].change[i]];
		}
		else{
			t[pos].change[i]=vec[i];
		}
	}
	t[pos].lazy=true;
}

void push(int pos,int l,int r){
	if(!t[pos].lazy) return;
	else if(l!=r){
		update(2*pos+1,t[pos].change);
		update(2*pos+2,t[pos].change);
	}
	else{
		if(t[pos].change[arr[l]]!=0)
		arr[l]=t[pos].change[arr[l]];
	}
	t[pos].lazy=false;
	t[pos].change.clear();
	t[pos].change.resize(101,0);
}

void setr(int pos,int l,int r, int ql, int qr,int x,int y){
	if(r<ql||l>qr) return;
	push(pos,l,r);
	if(l>=ql and r<=qr){
		t[pos].lazy = true;
		t[pos].change[x] = y;
		return;
	}
	int mid = (l+r)>>1;
	setr(2*pos+1,l,mid,ql,qr,x,y);
	setr(2*pos+2,mid+1,r,ql,qr,x,y);
}

void finalchk(int pos,int l,int r){
	push(pos,l,r);
	if(l==r) return;
	int mid = (l+r)>>1;
	finalchk(2*pos+1,l,mid);
	finalchk(2*pos+2,mid+1,r);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	t.resize(4*n);
	fors(i,0,n){
		int tr;cin>>tr;
		arr.emplace_back(tr);
		//cout<<arr[i];
	}
	int q;
	cin>>q;
	fors(i,0,q){
		int l,r,x,y;cin>>l>>r>>x>>y;
		l--;r--;
		setr(0,0,n-1,l,r,x,y);
	}
	finalchk(0,0,n-1);
	fors(i,0,n){
		cout<<arr[i]<<' ';
	}
	return 0;
}
